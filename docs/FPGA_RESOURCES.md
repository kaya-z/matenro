# FPGA 資源の使用状況 (記録)

Tang Nano 9K (`GW1NR-LV9QN88PC6/I5`、Gowin IDE の `gw_sh`、`run all` = 合成 + 配置配線)。測った日: **2026-11-07**。

**値は、共有 RAM (BSRAM 8KB、`rtl/shr_ap.v`) を入れた起動 ROM 版 (`fpga/tn9k/scripts/build.sh boot`、`TAG=_bram`) のものです。**
このビットストリームは実機のフラッシュに入っていて、OS-9 Level 2 が起動し、`duo` と、Z80 を BSRAM から動かす試験 (`xlshr`) が通っています。
漢字ローダは 2026-11-01 に削除済み、ACIA の割り込み (2026-11-06) と共有 RAM (2026-11-07) は入っています。

## 1. 配置配線後の合計 (`impl/pnr/matenro_boot.rpt.txt`)

| 資源 | 使用 / 総数 | 使用率 | 内訳 |
|---|---|---|---|
| Logic (LUT + ALU + SSRAM) | 7,729 / 8,640 | **90%** | LUT 7,129、ALU 492、SSRAM (RAM16) 18、ROM16 0 |
| CLS (スライス) | 4,070 / 4,320 | **95%** (残り 250) | 配置配線が通るかどうかを決めるのは、Logic よりこちら |
| レジスタ | 2,210 / 6,771 | 33% | FF 2,204 (論理) + 6 (I/O) |
| BSRAM | 8 / 26 (残り 18) | 31% | SP 1、SDPB 2、DPB 4 (共有 RAM)、pROM 1 (ROM) |
| I/O ポート | 27 / 71 | 39% | 入力 5、出力 21 |
| IOLOGIC | 20 / 97 | 21% | IDDR 9、ODDR 11 (PSRAM) |
| PLL (rPLL) | 1 / 2 | 50% | 27MHz → 67.5MHz と 90 度ずれた 67.5MHz |
| グローバルクロック | PRIMARY 4/8、LW 3/8、GCLK_PIN 3/3 | | |

DSP は使っていません (このデバイスには無い)。

## 2. タイミング (`impl/pnr/matenro_boot_tr_content.html`)

| クロック | 制約 | 実際の Fmax | 負のスラック (setup / hold) |
|---|---|---|---|
| `clk81` (システム 67.5MHz) | 67.5MHz | **68.013MHz** | なし / なし |
| `E` (6809 のバスクロック) | 1.875MHz | 24.652MHz | なし / なし |

余裕は 0.5MHz (約 0.1ns) しかありません。**配置配線の結果は RTL の変更のたびに変わります** (同じ RTL でも `PLACE` は効きません)。共有 RAM を入れた最初の配置配線は 63.8MHz (負のスラック -1.78ns、4 経路) で通りませんでした。遅かったのは追加した回路ではなく、SMMU の読み出し (BSRAM の出力の clock-to-out が 3.5ns) だったので、`xlink.v` の `smmu_rd` の後ろに FF を 1 段足して通しました。必ずビルドのたびに `Total Negative Slack Summary` を見てください。

## 3. 合成後のモジュール別の使用量 (`impl/gwsynthesis/matenro_boot_syn_resource.html`)

読み方: 各行は**そのモジュール自身**の資源で、子モジュールは別の行です (足し合わせると合計になります)。小計の列は A〜D の各グループ。LUT と ALU は別に数えます (Logic = LUT + ALU)。

| モジュール | LUT | ALU | レジスタ | BSRAM | SSRAM | 備考 |
|---|---|---|---|---|---|---|
| **A. 6809 側 (sim09 の SoC)** | | | | | | |
| &nbsp;&nbsp;6809 コア (`soc/cpu`、Greg Miller) | 3,283 | 119 | 207 | - | - | 6809 だけで LUT の約 46% |
| &nbsp;&nbsp;SoC のつなぎ (`soc`) | 1,114 | 52 | 568 | 1 | - | アドレスのデコード、MMU の表、PSRAM の窓、XLINK のつなぎ、ROM (BSRAM 1) |
| &nbsp;&nbsp;SD ディスク (`soc/disk`) | 455 | 62 | 311 | 1 | - | SPI の SD カードと DMA (BSRAM 1) |
| &nbsp;&nbsp;タイマ + 時計 (`soc/timer`) | 227 | 17 | 151 | - | - | OS-9 の時刻 (電池なし) |
| &nbsp;&nbsp;ACIA (UART) | 121 | 18 | 118 | 1 | 2 | BSRAM 1、SSRAM 2 |
| &nbsp;&nbsp;PSRAM コントローラ (`psram`) | 77 | 14 | 104 | - | - |  |
| &nbsp;&nbsp;PSRAM 調停 (`soc/arb`、4 マスタ) | 50 | - | 70 | - | - |  |
| **小計** | **5,327** | **282** | **1,529** | **3** | **2** | LUT 全体の 75% |
| **B. Z80 側** | | | | | | |
| &nbsp;&nbsp;Z80 のつなぎ (`soc/sub`) | 147 | 7 | 130 | - | - | メモリポート、バスの選択、窓のつなぎ |
| &nbsp;&nbsp;Z80 のバスのラッパ (`soc/sub/cpu`) | 30 | - | 12 | - | - |  |
| &nbsp;&nbsp;Z80 のコア (TV80: `i_tv80_core` + `i_mcode` + `i_alu` + `i_reg`) | 1,327 | 54 | 218 | - | 12 | `i_mcode` 233、`i_tv80_core` 1,079、`i_alu` 8、`i_reg` 7 (SSRAM 12) |
| **小計** | **1,504** | **61** | **360** | **-** | **12** | LUT 全体の 21% |
| **C. 6809 と Z80 の間** | | | | | | |
| &nbsp;&nbsp;XLINK + SMMU (`soc/sub/xl`) | 280 | 69 | 262 | 1 | 4 | レジスタ、メールボックス、SMMU 128 × 8 ビット (BSRAM 1、SSRAM 4)、窓、32 ビットのカウンタ |
| &nbsp;&nbsp;共有 RAM (`soc/shr`、`shr_ap.v`) | 8 | - | 6 | 4 | - | 8KB のデュアルポート (BSRAM 4)。2026-11-07 に追加 |
| **小計** | **288** | **69** | **268** | **5** | **4** | LUT 全体の 4% |
| **D. その他** | | | | | | |
| &nbsp;&nbsp;トップ (`tn9k_top`) | 9 | 15 | 20 | - | - |  |
| &nbsp;&nbsp;S2 ボタン (`s2`、`btn_toggle`) | 11 | 19 | 25 | - | - |  |
| **小計** | **20** | **34** | **45** | **-** | **-** | LUT 全体の 1% 未満 |
| **合成後の合計 (A+B+C+D)** | **7,139** | **446** | **2,202** | **8** | **18** | |
| 配置配線後の合計 (1 章) | 7,129 | 492 | 2,210 | 8 | 18 | 配置配線で ALU が 46 増える |
| デバイスの総数 | 8,640 (LUT + ALU) | | 6,771 | 26 | | |

* 合成後の合計 (LUT 7,139) は、配置配線後 (7,129) より 10 多いだけです。ALU の差 (446 → 492) は、配置配線で加算器が増えたためです。
* 一番大きいのは 6809 のコア (LUT の 46%) です。Z80 のコア (TV80) は約 1,330 LUT (19%)、Z80 側の追加分 (B + C、共有 RAM を含む) は約 1,790 LUT (25%) です。
* BSRAM 8 の内訳: ROM (`soc`) 1、SD ディスクのバッファ 1、ACIA 1、SMMU (`xl`) 1、共有 RAM 4。

## 4. 推移 (同じ SoC の各版)

| 時点 | Logic | CLS | BSRAM | Fmax (制約 67.5MHz) | 変更 |
|---|---|---|---|---|---|
| sim09 の SoC (HDMI なし、Z80 なし) | LUT 約 5,458 (64%) | 76% | 3 | | `new-sbc09/docs/FPGA.md` |
| 2026-10-31 | 7,539 (88%) | 93% | 4 | 67.549 | Z80 + XLINK 入り、起動時のメモリ検査入り |
| 2026-11-01 (`_opt`) | 7,669 (89%) | 94% | 4 | | 長い経路を短くした (docs/FPGA.md の 9.6)。一番悪いスラック +0.326ns |
| 2026-11-06 (`_acirq`) | 7,666 (89%) | 95% | 4 | 69.132 | ACIA の割り込み (RTL) |
| **2026-11-07 (`_bram`)** | **7,729 (90%)** | **95%** | **8** | **68.013** | 共有 RAM 8KB (+63 LUT、+4 BSRAM)、SMMU の読み出しに FF 1 段 |

見積もり (docs/FPGA.md の 1 章) は Z80 構成で約 7,200〜7,400 (84〜86%) でしたが、実測は少し上でした。

## 5. 空きと今後の余地

* 9K の残りは Logic で約 910 (11%)、CLS で約 250 (6%)、BSRAM で 18 ブロック (36KB) です。**HDMI (約 2,000 LUT) は載りません**。20K のボードなら載ります。
* 共有 RAM を 16KB に広げると、BSRAM はあと 4 ブロック、LUT は数十増えます。ブロック数は足りますが、CLS が 95% で、Fmax の余裕が 0.5MHz しかありません。配置配線の結果次第です。
* 8088 (3,000〜6,000 LUT の見積もり) は 9K には載りません。20K が要ります。

## 6. 再現の手順

```sh
TV80=<tv80s.v のあるディレクトリ> fpga/tn9k/scripts/build.sh boot      # 結果: fpga/tn9k/build/boot/impl/pnr/matenro_boot.fs
# 合計: impl/pnr/matenro_boot.rpt.txt の "Resource Usage Summary"、タイミング: matenro_boot_tr_content.html
# モジュール別: impl/gwsynthesis/matenro_boot_syn_resource.html
```
