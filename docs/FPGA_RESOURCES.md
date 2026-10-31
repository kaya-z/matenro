# FPGA 資源の使用状況 (記録)

Tang Nano 9K (`GW1NR-LV9QN88PC6/I5`、Gowin IDE の `gw_sh`、`run all` = 合成 + 配置配線)。測った日: 2026-10-31。**この 1 章と 2 章は、フラッシュに入っている今のビットストリーム (起動時のメモリ検査入り、漢字ローダなし、SMMU の読み出しをレジスタ経由にしたもの) の値です。3 章以降 (モジュール別) はコミット `1e0d1f4` の時点の値で、漢字ローダ (177 LUT) はもうありません。**
ビットストリームは、実機で OS-9 Level 2 が起動し、`cpm /d0/hello.com` が動いたもの (`fpga/tn9k/scripts/build.sh boot`、起動 ROM 版)。

## 1. 配置配線後の合計 (`impl/pnr/matenro_boot.rpt.txt`)

| 資源 | 使用 / 総数 | 使用率 | 内訳 |
|---|---|---|---|
| Logic (LUT + ALU + SSRAM) | 7,539 / 8,640 | **88%** | LUT 7,016、ALU 427、ROM16 0、SSRAM (RAM16) 16 |
| CLS (スライス) | 3,976 / 4,320 | **93%** | |
| レジスタ | 2,008 / 6,771 | 30% | FF 2,003 (論理) + 5 (I/O) |
| BSRAM | 4 / 26 | 16% | SDPB 3、pROM 1 |
| I/O ポート | 18 / 71 | 26% | 入力 5、出力 13 |
| IOLOGIC | 20 / 97 | 21% | IDDR 9、ODDR 11 (PSRAM) |
| PLL (rPLL) | 1 / 2 | 50% | 27MHz → 67.5MHz と 90 度ずれた 67.5MHz |
| グローバルクロック | PRIMARY 4/8、LW 3/8、GCLK_PIN 3/3 | | |

DSP は使っていません (このデバイスには無い)。

## 2. タイミング (`impl/pnr/matenro_boot_tr_content.html`)

| クロック | 制約 | 実際の Fmax | 負のスラック (setup / hold) |
|---|---|---|---|
| `clk81` (システム 67.5MHz) | 67.5MHz | **67.549MHz** | なし / なし |
| `E` (6809 のバスクロック) | 1.875MHz | 23.162MHz | なし / なし |

余裕は 0.1〜0.5ns しかありません。**配置配線の結果は RTL の変更のたびに変わり**、64〜68MHz の間で動きました (同じ RTL の `xltest` で Fmax 64.7MHz、スラック -3.4ns になったことがあります)。ビットストリームを作ったら、毎回 `Total Negative Slack Summary` を見てください。Z80 のためのマルチサイクル制約は `fpga/tn9k/constraints/matenro.sdc` にあります (docs/FPGA.md の 9 章)。

## 3. 合成後のモジュール別の使用量 (`impl/gwsynthesis/matenro_boot_syn_resource.html`)

| モジュール | LUT | ALU | レジスタ | BSRAM | SSRAM | 備考 |
|---|---|---|---|---|---|---|
| 6809 コア (`soc/cpu`、Greg Miller) | 3,307 | 119 | 207 | - | - | 全体の約 43% |
| SoC のつなぎ (`soc`) | 854 | 44 | 443 | 1 | - | アドレスのデコード、MMU の表、PSRAM の窓、XLINK のつなぎ、ROM (BSRAM 1) |
| SD ディスク (`soc/disk`) | 454 | 62 | 311 | 1 | - | |
| タイマ + 時計 (`soc/timer`) | 221 | 17 | 151 | - | - | OS-9 の時刻 (電池なし) |
| ACIA (UART) | 100 | 15 | 103 | 1 | - | |
| 漢字ローダ (`soc/loader`) | 177 | - | 126 | - | - | **`KANJI = 0` でも合成に残っている** (HDMI なしでは不要): 削れる |
| PSRAM コントローラ (`psram`) | 77 | 14 | 104 | - | - | |
| PSRAM 調停 (`soc/arb`、4 マスタ) | 46 | - | 70 | - | - | |
| トップ (`tn9k_top`) | 9 | 15 | 20 | - | - | |
| **Z80 側の合計** | **1,887** | 85 | 541 | 1 | 16 | 下の 4 行の合計 |
| ・Z80 のつなぎ (`soc/sub`: 窓、バスの選択、メモリポート) | 159 | 7 | 119 | - | - | |
| ・Z80 のバスのラッパ (`soc/sub/cpu`) | 31 | - | 12 | - | - | |
| ・Z80 のコア (`i_tv80_core` + `i_mcode` 228 + `i_alu` 8 + `i_reg` 6) | 1,338 | 54 | 218 | - | 12 | TV80 |
| ・XLINK + SMMU (`soc/sub/xl`) | 359 | 31 | 192 | 1 | 4 | レジスタ、メールボックス、SMMU 128 × 8 ビット、窓、32 ビットのカウンタ |

(モジュール別の LUT を足すと 7,132 で、配置配線後の 7,122 とほぼ同じです。モジュール別は合成後の値です。)

## 4. 前の見積もり・他の構成との比較

| 構成 | LUT / Logic | 備考 |
|---|---|---|
| sim09 の SoC (HDMI なし、Z80 なし) | 約 5,458 (`new-sbc09/docs/FPGA.md`) | |
| **今の SoC (Z80 + XLINK 入り、HDMI なし、MEMTEST なし)** | **7,635 (89%)** | 実機で動作 |
| `xltest` 版 (同じ SoC、別の ROM) | 7,771 (90%) | 6809 の ROM が違うだけ |
| docs/FPGA.md の見積もり (Z80 構成) | 約 7,200〜7,400 (84〜86%) | 実測は少し上 (Z80 側の追加が約 1,890 + 調停 46 + ウィンドウ/メモリポートの回路) |

Z80 側の追加 (約 1,890 LUT) は、見積もり (1,950〜2,150) の範囲内でした。

## 5. 空きと今後の余地

* 9K の残りは Logic で約 1,000 (11%)、CLS で約 320 (7%) です。**HDMI (約 2,000 LUT) は載りません**。20K のボードなら載ります。
* 削れるもの: 漢字ローダ (177 LUT、`KANJI = 0` でも残っている)。削るとタイミングの余裕も増える見込みですが、まだやっていません。
* 8088 (3,000〜6,000 LUT の見積もり) は 9K には載りません。20K が要ります。

## 6. 再現の手順

```sh
TV80=<tv80s.v のあるディレクトリ> fpga/tn9k/scripts/build.sh boot      # 結果: fpga/tn9k/build/boot/impl/pnr/matenro_boot.fs
# 合計: impl/pnr/matenro_boot.rpt.txt の "Resource Usage Summary"、タイミング: matenro_boot_tr_content.html
```
