# Tang Nano 20K 版 (6809 + 8088) の設計

**状態 (2026-11-12): 実機がまだ無いので、ビットストリームを作るところまで** (合成・配置配線を通して `.fs` ができ、Verilator で OS-9 の起動と 8088 のプログラムが動く)。ボードには書いていません。ピンの数字やクロックの余裕など、実機で確かめるべきことは 8 章にまとめました。

Tang Nano 9K 版 ([FPGA.md](FPGA.md)) は 6809 + Z80 です。20K 版は同じ SoC (`matenro_soc.v`) の**サブ CPU を 8088 (MCL86) に替え**、9K の PSRAM のかわりにパッケージ内の **SDRAM** を使います。HDMI はまだありません。

## 1. ボードとチップ

| 項目 | 内容 | 出典 |
|---|---|---|
| FPGA | Gowin GW2AR-LV18QN88C8/I7 (GW2AR-18C): LUT4 20,736、FF 15,552、BSRAM 46 ブロック (828 Kbit)、PLL 2、18x18 乗算器 48 | Sipeed のボードの頁 |
| SDRAM | パッケージ内の SDR SDRAM、64 Mbit (8MB)、32 ビット、4 バンク × 2K 行 × 256 列 | 同上、Sipeed の `nestang` 例 |
| 水晶 | 27 MHz、FPGA のピン 4 | `led` `uart` 例の `.cst` |
| ボタン | S1 = ピン 88、S2 = ピン 87。**押すと H** (`nestang` は `sys_resetn <= ~s1`) | `picorv32` `hdmi` `audio` `nestang` 例 |
| LED | 6 個、ピン 15-20、**L で点灯** | `led/blink_leds` 例 |
| UART | BL616 の USB シリアル: FPGA の TX = ピン 69、RX = ピン 70 | `uart` 例 |
| microSD | CLK = 83、CMD (MOSI) = 82、DAT0 (MISO) = 84、DAT3 (CS) = 81 (DAT1 = 85、DAT2 = 80 は使わない) | `nestang` 例の `.cst` |

SDRAM のピンは、パッケージの中でつながっているので `.cst` には書きません (Gowin のツールが `O_sdram_*` `IO_sdram_dq` の名前で見つけます。合成の報告にピンが自動で割り当てられていました)。Sipeed の回路図の PDF は取れなかったので、ピンの数字は**サンプルの `.cst` から**読んだものです。

## 2. 構成

```
 27 MHz ─ PLL ─┬─ clk (システムクロック、既定 54 MHz)
               └─ clk_p (同じクロックを 180 度ずらしたもの = SDRAM のクロック)

 tn20k_top
   ├─ matenro_soc (`define SUB8088: 9K と同じ SoC。Z80 のかわりに i8088_sub)
   │    6809 ── MMU (Level 2) ── ROM / I/O / UART / タイマ / SD ディスク
   │      │                                  PSRAM 調停 (psram_arb4: マスタ 0..4)
   │      └─ XLINK ── i8088_sub (MCL86: eu.v + biu_min.v + マイクロコード ROM)
   │                     └─ 共有 RAM 8KB (BSRAM、shr_ap.v)
   └─ sdram_ctl ── 調停の下の層 (PsramController と同じ要求の形)  ── SDRAM
```

* **調停から下は 9K と同じ要求の形**にしたので、`psram_arb4.v` `matenro_soc.v` のメモリまわり (ディスクの DMA、Z80 / 8088 のメモリポート、XLINK の窓) は変えていません。
* 6809 側は 9K の Level 2 の OS-9 がそのまま動きます。`SUB8088` を定義した SoC は、XLINK の `XID` が 2 になります。
* 時計は 9K と同じ「システムクロックのパルスで進める」方式です (docs/FPGA.md の 9.13)。

## 3. メモリ: SDRAM とコントローラ (`fpga/rtl/sdram_ctl.v`)

* 8MB のうち、**4MB** を使います (調停のアドレスは 22 ビットのバイトアドレス。OS-9 Level 2 の物理メモリは 2MB)。アドレスの写像: ワード (32 ビット) = `addr[21:2]`、列 = `w[7:0]`、バンク = `w[9:8]`、行 = `w[19:10]`。
* `PsramController` と同じ入出力: `read` / `write` のパルス、`addr[21:0]` (バイト)、`din[15:0]`、`byte_write`、`dout[15:0]` (`addr[21:1]` のワード)、`busy`。
* **書き方**: SDR SDRAM のコマンド (JEDEC) から自分で書きました。**Sipeed の `nestang` の `sdram.v` (GPL v3) は使っていません** (MIT のこのプロジェクトに入れられないため。CREDITS.md)。アクセスは ACTIVE → READ / WRITE (オートプリチャージ付き) → 待ち、1 回 9 クロック、重ねません。CAS レイテンシ 2、バースト長 1。tRCD = 3 クロック、書きのあとは tWR + tRP を含めて 10 クロックあけます。読んだデータは READ から 3 クロックあとに取ります (SDRAM のクロックはシステムクロックの反転)。
* **リフレッシュ**: 7.4µs ごとに AUTO REFRESH (4096 回 / 64ms に十分)。リフレッシュ中に来た要求は覚えておいて、あとで行います。電源投入後 200µs 待ち、PRECHARGE ALL、AUTO REFRESH 2 回、MODE REGISTER SET の順。
* **検証**: `fpga/tn20k/sim/sdram_model.v` (SDRAM の動作モデル。tRCD / tRP / tRC / リフレッシュ間隔などの規則を数えて、破ると `errors` が増える) に対して `make -C fpga/tn20k/sim sdram`: バイト / ワードの乱数の読み書き 14,100 件 (1 クロックおきの連続アクセスと、リフレッシュ中の要求を含む)、4MB の端、結果は**不一致 0、規則違反 0**。

## 4. 8088: MCL86 とその包み (`fpga/rtl/i8088_sub.v`)

* **コア**: MicroCore Labs の MCL86 (Ted Fried、MIT 形式の表示)。`fpga/vendor/mcl86/` に `eu.v` と `biu_min.v` を無変更で置き、マイクロコードは `.coe` から `mcl86_ucode.hex` (4096 語 × 32 ビット) に直しました (README に出どころ)。EU の中のマイクロコード ROM は `eu4kx32.v` (BSRAM 8 ブロック)。サイクル数を実機の 8088 に合わせるモードで使います (`BIU_CLK_COUNTER_ZERO` はコアの出力のまま)。
* **クロック**: BIU はシステムクロックで動き、「8088 の CLK」ピンを見て T1〜T4 を進めます。CLK はシステムクロックを `C88_DIV` 分周して作ります (54 MHz / 11 = 4.9 MHz)。XLINK の `XE_KHZ` は 4909 (= `$132D`)。
* **バスサイクル** (最小モード。`IO/M` は I/O と割り込み応答で H):

| サイクル | 動き |
|---|---|
| メモリ読み | `RD#` が下りたら、ALE で保持した 20 ビットのアドレスを XLINK の SMMU で物理アドレス (21 ビット) にして、`mem_*` のポートに要求を出す。応答が来るまで `READY` を L。データは `AD_IN` に出し続ける |
| メモリ書き | `WR#` が下りたら、同じように `AD_OUT[7:0]` のバイトを書く |
| I/O | ポート `$00`-`$0F` は XLINK のレジスタ (Z80 と同じ約束: メールボックス、ドアベル、`$0E` コンソール、`$0F` 電源)。それ以外は `$FF` |
| 割り込み応答 | `INTA#` が L のとき、XLINK のベクタ (`s_vec`) を返す |

* **割り込み**: `INTR` = XLINK の `sub_int` (レベル)、`NMI` = XLINK のパルスを 4 クロックに伸ばしたもの。リセット / HOLD は XLINK の `sub_rst_n` / `sub_hold` (HOLD は CLK を止める)。
* **制限**: MCL86 に `HLT` を知らせる端子がないので、XLINK の `XS_HALT` (サブ CPU が HALT 中) は常に 0 です。`TEST#` は H に固定。ほかは 8088 と同じです (8087 は無し)。

## 5. システムクロックと合成の結果

MCL86 の EU は、マイクロコード ROM の出力 (BSRAM のクロックから出力まで) から、オペランドの選択と ALU を通って、レジスタに書くまでを**1 クロックで**行います。これが設計全体でいちばん長い経路 (約 14.9ns) です。

| クロック | PH_DIV / 8088 の分周 | `clk81` の Fmax | 結果 | Logic | CLS | 備考 |
|---|---|---|---|---|---|---|
| 67.5 MHz | 9 / 14 | 66.745 MHz | **通らない** (最悪のスラック -0.167ns、7 本) | 7,754 | 4,944 | 9K と同じクロック。配置の選択 (`PLACE=0,2`) と `RETIME` でも変わらない |
| 60 MHz | 8 / 12 | 60.631 MHz | 通る (余裕 0.63 MHz) | 7,668 | 4,874 | 6809 の E は 1.875 MHz、8088 は 5.0 MHz |
| **54 MHz (既定)** | 7 / 11 | **56.582 MHz** (`xltest88`)、55.021 MHz (`boot`) | 通る (余裕 1.0〜2.6 MHz) | 7,731 | 4,920 | 6809 の E は 1.93 MHz、8088 は 4.9 MHz |

* 54 MHz の 2 つのビットストリーム (配置配線後、`impl/pnr/*.rpt.txt`): **`xltest88`** (6809 の試験 ROM が 8088 の自己判定を走らせる): Logic 7,731 / 20,736 (**38%**)、LUT 7,020、ALU 531、SSRAM 30、レジスタ 2,718 (18%)、CLS 4,920 / 10,368 (**48%**)、BSRAM 18 / 46 (40%: SP 1、SDPB 3、DPB 4、pROM 10)、I/O 15 / 66。**`boot`** (起動 ROM 256 バイト、SD カードから OS-9 を起動): Logic 7,727 (**38%**)、CLS 4,890 (47%)、BSRAM 17 / 46。負のスラックはどちらもありません。
* **余裕が大きい**: 20K では Logic も CLS も半分以下で、9K のような窮屈さはありません。BSRAM もあと 29 ブロック (約 58KB) あります。HDMI (約 2,000 LUT) は載ります。
* 配置配線の結果は RTL の小さな変更でも変わります (今回の 3 回のビルドの Fmax は 54 MHz で 55.0〜56.6)。**クロックを上げるなら、マイクロコード ROM の出力に FF を入れる (EU の改造が要る) ほうがよい**。
* GW2A の BSRAM では、9K と同じ書き方の SMMU が「読み出しの前に書く」モードの DPB になり、エラー PA2122 で止まりました。`xlink.v` に `SMMU_WT` を足し (8088 の側だけ 1)、読み出し用のコピーを `shr_ap.v` と同じ書き方にして通しました。9K (`z80_sub`) は `SMMU_WT = 0` で、回路は変わりません。

## 6. ピンの割り当て (`fpga/tn20k/constraints/tn20k.cst`)

1 章の表のとおりです。`sys_clk` 4、`s1` 88、`s2` 87、`uart_tx` 69、`uart_rx` 70、`sd_clk` 83、`sd_mosi` 82、`sd_miso` 84、`sd_cs` 81、`led[0..5]` 15-20。電圧は 3.3V (LVCMOS33)。

## 7. 検証 (実機なし)

| 試験 | コマンド | 結果 |
|---|---|---|
| MCL86 + XLINK + 試験用 RAM で 8088 の自己判定 (`tests/i8088/core.asm`、125 項目) | `make -C fpga/sim i8088` | 通る (メモリの遅れ 6〜50 クロックで確認) |
| SDRAM コントローラと SDRAM のモデル | `make -C fpga/tn20k/sim sdram` | 14,100 件、不一致 0、規則違反 0 |
| SoC 全体 (6809 の試験 ROM が 8088 の自己判定を SDRAM の上で走らせる) | `make -C fpga/tn20k/sim soc PH=7 D88=11 HZ=54000000` | `S L R A5 00 132D` (67.5 / 60 / 54 MHz のどれでも通る) |
| OS-9 Level 2 を SD カードのイメージから起動 (SoC 全体) | `make -C fpga/tn20k/sim boot DISK=… SCRIPT=…` | `OS9:` が出て `dir /d0` が通る (約 1.06 億クロック) |
| OS-9 から CP/M-86 のプログラム 3 つ (`cpm /d0/hello86.cmd abc def`、`small86.cmd`、`fileio86.cmd`) | 同上 (約 2.8 億クロック) | **`Hello from CP/M-86 on the 8088` / `!` / ` ABC DEF`**、`Hello from the small model` / `version ok, RETF ends`、`FILEIO86 OK` (ファイルの作成・書き・読み・削除で SD カードへの書き込みあり)。6809 の OS-9、XLINK、8088 の RTL、SDRAM が全部つながって動く |

まとめて: `make test-tn20k`。9K の既存の試験 (`make test-mh` 53 件、`make test-fpga`、`disktest`、`aciirq`) は変わりません (変更後に再確認済み)。

**SDRAM モデルの限界**: クロックの端で動くだけの理想的なモデルです。実チップの出力遅れ (tAC)、入出力のピンの遅れ、基板上の配線は入っていません。

## 8. 実機が来たら (未確認のこと)

1. **ビットストリームの書き込み** (まだしていません): `openFPGALoader -b tangnano20k fpga/tn20k/build/boot/impl/pnr/matenro20k_boot.fs` (SRAM に書く。フラッシュは `-f`)。作り直し: `fpga/tn20k/scripts/build.sh boot` (`xltest88` は 8088 の自己判定だけの試験)。
2. **ピンの確認**: 回路図が取れなかったので、すべてサンプルの `.cst` から読んだものです。特に **S1 / S2 の極性** (H で押下とした)、**UART の TX / RX の向き** (69 = FPGA の TX)、**SD カードの 4 本** は最初に見る。S1 の極性が逆だと、リセットが外れません。
3. **PLL**: rPLL の設定 (27 MHz × 2、VCO 864 MHz、`CLKOUTP` を 180 度) はツールを通りましたが、実機でロックするか未確認。LED2-5 が動けば PLL は上がっています。
4. **SDRAM**: 実チップで 54 MHz のタイミング (読み出しを READ から 3 クロックで取る) が合うか。メモリ検査 (`Matenro Memory >>>… OK 2048K`) が通れば、基本は合っています。外れるときは `sdram_ctl.v` の読み取りのタイミング (`cyc == 6`) を 1 つずらす。
5. **SD カード**: 9K と同じカードのイメージ (`fpga/tn9k/scripts/mkdisk.sh` + `bigd1.sh`) が使える (カードの先頭にドライブ 0、128MB の位置にドライブ 1)。
6. **8088**: OS-9 で `load xlink`、`load x0`、`cpm hello86.cmd` (CP/M-86 のプログラムは `tools/mkcmd.py` で作る)。
7. **性能**: `etime` で測り、MCL86 の 4.9 MHz 相当と、シミュレータの見積もり (docs/DESIGN.md の 8088 の章) を比べる。

## 9. ファイル

| ファイル | 内容 |
|---|---|
| `fpga/rtl/i8088_sub.v` | 8088 のサブ CPU (MCL86 + XLINK)。`z80_sub.v` と同じポート |
| `fpga/rtl/eu4kx32.v` | MCL86 のマイクロコード ROM (4K × 32) |
| `fpga/vendor/mcl86/` | MCL86 の `eu.v` `biu_min.v`、マイクロコード `mcl86_ucode.hex`、README (出どころとライセンス) |
| `fpga/rtl/sdram_ctl.v` | SDRAM コントローラ (`PsramController` と同じ要求) |
| `fpga/rtl/xlink.v` | `SMMU_WT` を足した (9K では 0) |
| `fpga/tn9k/rtl/matenro_soc.v` | `` `define SUB8088 `` で Z80 のかわりに 8088 (`C88_DIV` パラメータ) |
| `fpga/tn20k/rtl/tn20k_top.v` `tn20k_pll.v` | 20K の最上位と PLL |
| `fpga/tn20k/constraints/tn20k.cst` `tn20k.sdc` | ピンとタイミング |
| `fpga/tn20k/scripts/build.sh` | Gowin のビルド (`xltest88` / `boot`、`CLKMHZ=54|60|67.5`) |
| `fpga/tn20k/test/xltest88.asm` | 6809 の試験 ROM (8088 の自己判定を走らせる) |
| `fpga/tn20k/sim/` | SDRAM のモデルと試験、SoC 全体の Verilator (`sim_top.v`、Makefile) |
| `fpga/sim/i8088_soc.v` `tb_i8088_soc.v` | MCL86 + XLINK + 試験用 RAM の Verilator 試験 |
| `tests/i8088/core.asm` | 8088 の自己判定 (`-DHWPORTS` で FPGA 用: ポート RAM の 2 項目を飛ばし、結果をメールボックスに書く) |
