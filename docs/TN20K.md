# Tang Nano 20K 版 (6809 + 8088) の設計

**状態 (2026-11-15): 実機で動きました** (54 MHz。OS-9 Level 2 が SD カードから起動し、CP/M-86 と MS-DOS 2.0 のプログラムが 8088 で動く。結果は 8 章)。それまでは合成・配置配線を通して `.fs` を作り、Verilator で確かめていました。

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

## 2.1 Z80 と 8088 の切り替え (`subsel`、2026-11-15)

20K の FPGA には **Z80 (TV80) と 8088 (MCL86) の両方**が載っています (`` `define SUBBOTH ``、`fpga/tn20k/scripts/build.sh` の既定。`SUBS=8088` で 8088 だけ)。同時には使わず、**OS-9 の実行中に切り替えます**。

```
subsel            今のサブ CPU を表示 (subsel: 8088)
subsel z80        Z80 に切り替える (cpm hello.com、CP/M-80)
subsel 8088       8088 に切り替える (cpm hello86.cmd、CP/M-86、dos ...)
```

* **レジスタ** SUBSEL = `$FFCF` (XLINK の隣、`$FFCA-$FFCE`): 読むと 1 (Z80) か 2 (8088)、書くと切り替え。電源を入れた直後は 8088 (`SUB_DEF8`)。リセットで元に戻る。9K の版 (Z80 だけ) には無く、読むと 0 で、`subsel` は「サブ CPU は 1 つだけ」と言う。
* **回路** (`matenro_soc.v`、`` `ifdef SUBBOTH ``): `z80_sub` と `i8088_sub` が同じポートを持つので、選ばれていない方を**リセットのまま**にして、出力 (XLINK の読み出し、割り込み、窓、メモリのポート) を `sel8` で選ぶだけです。XLINK は両方の中にあり、`XID` (`$FFCC`) は選ばれた方の 1 か 2 を返すので、`cpm` と `dos` はそのまま動きます。選び直したサブ CPU は、リセットから始まります (SMMU も初期値): 走らせるものは入れ直してください。
* `subsel` は XCTL を 0 にして (サブ CPU を止めて) から切り替えます。`cpm` は、Z80 のときに `.CMD` (CP/M-86) を渡されると、止まらずに `subsel 8088` と案内します。
* **シミュレータ**にも同じレジスタがあります (`matenro -sub 8088` で起動して `subsel z80`)。
* **資源**: Logic 9,792 / 20,736 (**48%**)、CLS 60%、BSRAM 18 / 46、レジスタ 3,319。`clk81` の Fmax は 54.111 MHz (制約 54 MHz。**余裕は 0.1 MHz** で、8088 だけのとき (55.0 MHz) より小さい)。負のスラックはありません。
* **検証**: `make -C fpga/tn20k/sim bothboot DISK=… SCRIPT=both.txt CLKS=2500000000 PH=7 D88=11 HZ=54000000 CZ=7` (SoC 全体の RTL で OS-9 が SD から起動し、`subsel`、`cpm hello86.cmd`、`subsel z80`、`cpm hello.com`、`subsel 8088` を通した。約 2 分)、C のシミュレータの `matenro_test.py` の `os9_subsel` (3 項目)。

## 2.2 HDMI の文字画面 (2026-11-15)

コンソール (OS-9 が UART に出す文字) を、HDMI コネクタのモニタに **80 × 25 の文字画面**で出します (640 × 480、60 Hz、DVI)。**出力だけ**で、入力は USB シリアルです。**実機のモニタに映ることを確かめました。**

* **回路**: 端末 (`hdmi_term.v`: ESC シーケンス、色、スクロール)、表示 (`hdmi_video.v`)、TMDS のエンコーダ (`tmds_enc.v`) は **sim09 のものをそのまま**使います (`new-sbc09/fpga/tn9k/rtl`、同じ作者の MIT。build.sh とシミュレーションがそこから読み、コピーはしません)。20K 用に書いたのは `fpga/rtl/hdmi_text20.v` (9K の文字コードの復号と漢字の字形の読み出しを除いたまとめ役) と `fpga/tn20k/rtl/hdmi_phy20.v` (126 MHz の PLL = 27 × 14 / 3、画素クロック 25.2 MHz、OSER10 の 10:1 のシリアライザ、TLVDS の出力)。
* **ピン**: Sipeed の HDMI の例の `.cst` から: クロック 33/34、データ 0-2 は 35/36、37/38、39/40 (LVDS25)。d0 = 青 (同期つき)、d1 = 緑、d2 = 赤。
* **文字** (漢字の版、既定): 文字コードの復号 (UTF-8 が既定、`HDMI_CHARSET=0..3` で 0 raw、1 UTF-8、2 EUC-JP、3 Shift_JIS。動作中は `ESC % G` / `E` / `S` / `@`) と、JIS X 0208 の記号・ひらがな・カタカナ・第 1 水準漢字 (16×16、東雲フォント) は sim09 の `hdmi_decode.v` `hdmi_glyph.v` `psram_xfer.v` をそのまま使います。ASCII、半角カナ、Latin-1 は 8×16 のフォント。第 2 水準以降は〓。`KANJI=0` で漢字なし (`hdmi_text20.v`: 1 バイト = フォントの 1 字) の版を作れます。
* **字形のデータ** (`kanji.bin`、185,856 バイト、`new-sbc09/fpga/tn9k/images/kanji.bin`): SDRAM の **`$200000`** (OS-9 の 2 MB の上) にあります。復号器と字形の読み出しは、アービタのマスタ 1 と 2 で SDRAM から読みます。**SD カードから OS-9 のコマンド `kanjild` で読み込みます** (SPI フラッシュの版は 9K のもの。20K の SDRAM は電源を切ると消えるので、電源を入れるたびに `kanjild` が要ります):
  ```
  chx /d0/cmds
  kanjild                       (既定: /d1/kanji.bin)
  ```
  `$200000` は XLINK の窓 (21 ビット = 2 MB) の外なので、レジスタ **HCTL (`$FFC8`)** を足しました: ビット 1 = 窓が 2 MB 以降を見る (物理アドレスの bit 21)、ビット 0 = 字形のデータが入った (HDMI が漢字を出す。入るまでは〓)。`kanjild` はビット 1 を立てて、窓から書き、`KJF1` を読み戻して確かめて、ビット 0 を立てます。レジスタの有無は、`$FE` を書いて 2 が返るかで見ます (9K やシミュレータの RAM は `$FE` を返す)。
* **実機** (2026-11-15): SD カードの `/d1/kanji.bin` を `kanjild` で読み込み、`echo 日本語の表示テスト ひらがな カタカナ 漢字` (UTF-8) が HDMI のモニタに**漢字で出ることを確かめました**。
* **ビルド**: 既定で入る (`HDMI=0 fpga/tn20k/scripts/build.sh boot` で省く)。PLL は 2 つとも使います (システムと HDMI)。
* **資源** (`boot`、Z80 + 8088、54 MHz): 文字だけ (`KANJI=0`): Logic 11,316 / 20,736 (**55%**、HDMI で +1,528)、BSRAM 28 / 46、`clk81` 54.403 MHz。**漢字つき (既定)**: Logic 11,755 (**57%**、漢字で +439)、CLS 71%、BSRAM 31 / 46、PLL 2 / 2、`clk81` の Fmax は 54.324 MHz (制約 54 MHz)、`clk_pix` は 89.7 MHz。負のスラックなし。
* **検証**: `make -C fpga/tn20k/sim hdmik` (漢字つきの画面を SDRAM のモデルと `sdram_ctl` の上で: `kanji.bin` を `$200000` に置き、UTF-8 の日本語を送って、1 画面の漢字とひらがなとカタカナを字形のデータと突き合わせる: **誤り 0 画素**)、`make -C fpga/tn20k/sim kjboot` (SoC 全体の RTL で OS-9 が起動し、`kanjild` で読み込んだ SDRAM の `$200000` からの 185,856 バイトが `kanji.bin` と一致)、`make -C fpga/tn20k/sim hdmi` (sim09 の `tb_hdmi.cpp` が TMDS を復号して DC バランスと記号を調べ、1 画面を PPM にし、`check_hdmi.py` がフォントと突き合わせる: 色つきの 3 行で誤り 0 画素)、実機のモニタ。

## 2.3 HDMI のフレームバッファ (2026-11-15)

文字画面のかわりに、**320 × 240 画素、1 画素 8 ビット (256 色のパレット) の絵**を、2 倍にして 640 × 480 で出せます。**実機のモニタに映ることを確かめました。**

| 項目 | 内容 |
|---|---|
| 絵 | SDRAM の `$300000` から 76,800 バイト (1 行 320 バイト)。OS-9 の 2 MB の上、漢字のデータ (`$200000`) の次 |
| 色 | 1 バイト = パレットの番号。パレットの初期値は `rrrgggbb` (3-3-2)。256 エントリ × 24 ビット (R、G、B) |
| レジスタ | `$FFB8` GCTL (bit 0: 絵を出す、0 で文字画面。bit 1: 絵の上に文字を重ねる)、`$FFB9` PIDX (パレットの番号)、`$FFBA` PDAT (R、G、B を 1 バイトずつ書く。3 つ目でそのエントリが決まり、番号が進む) |
| 書き込み | 6809 から XLINK の窓 (HCTL ビット 1 = 2 MB 以降。窓のアドレス `$100000` が物理 `$300000`) で書く。**OS-9 のコマンド `gfx`**: `on` `over` `off` `fill n` `test` `load ファイル` `pal ファイル`、描画の `pix` `line` `rect` `box` `text` (MANUAL 6.8.3) |

* **回路**: `fpga/rtl/hdmi_fb.v` (ラインバッファ 2 面 × 80 語、パレット、文字画面との切り替え) と `fpga/rtl/hdmi_screen20.v` (sim09 の `hdmi_text.v` と同じ部品で、表示と TMDS のエンコーダの間にフレームバッファを入れたもの)。
* **SDRAM の読み出し**: コントローラ (`sdram_ctl.v`) に 32 ビット幅の読み出しデータ `dout32` を足し、フレームバッファが**自分で**読みます (1 回で 4 画素、1 行 80 回)。トップ (`tn20k_top.v`) が、SoC の要求より先に通します (`fb_go = fb_rq && !busy && SoC の要求なし`。SoC には同じクロックで busy を見せるので、始めることはありません)。1 行 (画面の 2 行分) の読み出しは 17.8 µs で、画面の 2 行 (63.5 µs) の間に済むので、SoC の SDRAM の時間の約 28% を使います。
* **ラインバッファ**: 表示している行の次の行を、もう一方の半面に先読みします。フレームの始めに行 0 と 1、そのあと画面の 2 行ごとに 1 行。
* **レジスタの場所**: SAM の領域 (`$FFC0-$FFDF` の `$FFD0` 付近) や `$FFE0` 付近は、OS-9 が起動中に RAM として使うので、I/O にすると**起動が止まります**。`$FFB8-$FFBA` は大丈夫でした。
* **資源** (`boot`、Z80 + 8088 + 漢字 + フレームバッファ、54 MHz): Logic 12,070 / 20,736 (**59%**)、CLS 73%、BSRAM 33 / 46、`clk81` の Fmax は 55.178 MHz (制約 54 MHz)、`clk_pix` は 74.7 MHz。負のスラックなし。
* **検証**: `make -C fpga/tn20k/sim hdmig` (SDRAM のモデルに置いた 320 × 240 の絵を、`sdram_ctl` を通して表示し、640 × 480 の全画素を期待値と比べる: **誤り 0**)、`make -C fpga/tn20k/sim gfxboot` (SoC 全体の RTL で OS-9 が起動し、`gfx test` が SDRAM の `$300000` に描いた 76,800 バイトを、期待の絵と比べる: 誤り 0)、実機のモニタ。
* **重ね合わせ** (`gfx over`、GCTL bit 1。**実機で確かめました**): 文字の画素が黒でないところは文字、黒のところは絵を出します (背景が黒の文字は絵の上に透けて見える。背景に色をつけた文字は不透明)。選ぶのは `hdmi_fb.v` の出力段だけです。
* **SoC との共用で直したこと** (`gfx on` のあと OS-9 のプロンプトに戻れなくなった不具合): (1) フレームバッファの読み出しは、SoC の読み出しデータ `dout` を**更新しない** (`sdram_ctl.v` の `wide` の読み出しは `dout32` だけに入れる)。調停回路は、アクセスが終わって SDRAM が空いてから `dout` を取りに行くので、その前に割り込んだ絵の読み出しが `dout` を上書きすると、CPU が命令の代わりに画素を受け取って暴走した。(2) 調停回路の「決めた」から「SDRAM に出す」までの 2 クロック (`psram_arb4.v` の `c_issue`、SoC の `ps_issue`) には割り込まない。`make -C fpga/tn20k/sim fbsoc FBFIX=1` が、SoC 全体の RTL (HDMI とフレームバッファつき) で `gfx test` `gfx on` のあと `dir` と `echo` が動くことを確かめる (直す前は止まる)。
* **バースト読み出しは実機で動かなかった**: SDRAM のバースト長を 4 にして 16 バイトずつ読むと (SDRAM の時間を 28% から 6% 程度に減らせる見込み)、シミュレーションのモデルでは通るが、実機ではメモリ検査が 1 番地目 (`NG@000001`) で失敗した。書き込みの設定 (A9) をチップが守らないなど、モデルとの違いが原因と見ている。BL1 のまま、32 ビットの単独読み出し (1 行 80 回) にした。
* **描画** (`gfx pix` `line` `rect` `box` `text`): 6809 のソフト (`os9/gfx/gfx.asm`) だけで、FPGA の資源は要りません。点ごとに窓のアドレスを置いて書く (1 点約 60 µs)。四角と文字は、行ごとにアドレスを置いて連続して書く。文字は 8 × 16 のフォント (`font8x16.hex` から `os9/gfx/mkfont.py` がビルド時に作る 1,520 バイト)。`make -C fpga/tn20k/sim gfxdraw`: SoC 全体の RTL で 11 本のコマンド (線 5 本、四角、点、文字 2 つ。範囲外に出る点と四角と文字を含む) を走らせ、SDRAM の 76,800 バイトを Python の参照実装 (`check_gfxdraw.py`) と比べる: **誤り 0**。
* **サブ CPU から描く** (代行型、MANUAL 6.8.4): CP/M-80 / CP/M-86 は BDOS の関数 112、MS-DOS は INT E2h (BIOS)。サブ CPU が操作を書いたブロック (16 ビットのワード 7 つと文字列) を渡し、`cpm` / `dos` (6809) が `gfxlib.inc` で描く (`gfx` と同じコード: 点 約 60 µs)。`make -C fpga/tn20k/sim gfxsub`: SoC 全体の RTL で、`subsel z80` のあと `cpm gdemo.com` (CP/M-80) と `cpm gdemo86.cmd` (CP/M-86) が描いた絵を、Python の参照実装と比べる: **誤り 0**。`gfxdos`: MS-DOS 1.25 の `gdemo.com`。
* **まだないもの**: サブ CPU が直接 VRAM に書く経路 (今は 6809 の代行だけ)、描画の関数のうち、円、塗りつぶしの多角形、文字の透明な背景、SDRAM のバースト読み出し (実機で動く形が見つかれば)。

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

## 7. 検証 (シミュレーション)

| 試験 | コマンド | 結果 |
|---|---|---|
| MCL86 + XLINK + 試験用 RAM で 8088 の自己判定 (`tests/i8088/core.asm`、125 項目) | `make -C fpga/sim i8088` | 通る (メモリの遅れ 6〜50 クロックで確認) |
| SDRAM コントローラと SDRAM のモデル | `make -C fpga/tn20k/sim sdram` | 14,100 件、不一致 0、規則違反 0 |
| SoC 全体 (6809 の試験 ROM が 8088 の自己判定を SDRAM の上で走らせる) | `make -C fpga/tn20k/sim soc PH=7 D88=11 HZ=54000000` | `S L R A5 00 132D` (67.5 / 60 / 54 MHz のどれでも通る) |
| OS-9 Level 2 を SD カードのイメージから起動 (SoC 全体) | `make -C fpga/tn20k/sim boot DISK=… SCRIPT=…` | `OS9:` が出て `dir /d0` が通る (約 1.06 億クロック) |
| OS-9 から CP/M-86 のプログラム 3 つ (`cpm /d0/hello86.cmd abc def`、`small86.cmd`、`fileio86.cmd`) | 同上 (約 2.8 億クロック) | **`Hello from CP/M-86 on the 8088` / `!` / ` ABC DEF`**、`Hello from the small model` / `version ok, RETF ends`、`FILEIO86 OK` (ファイルの作成・書き・読み・削除で SD カードへの書き込みあり)。6809 の OS-9、XLINK、8088 の RTL、SDRAM が全部つながって動く |

まとめて: `make test-tn20k`。9K の既存の試験 (`make test-mh` 53 件、`make test-fpga`、`disktest`、`aciirq`) は変わりません (変更後に再確認済み)。

**SDRAM モデルの限界**: クロックの端で動くだけの理想的なモデルです。実チップの出力遅れ (tAC)、入出力のピンの遅れ、基板上の配線は入っていません。

## 8. 実機の結果 (2026-11-15)

Tang Nano 20K を USB に接続し、**54 MHz のビットストリームを SRAM に書いて** (`openFPGALoader -m`。フラッシュには書いていません) 確かめました。UART は FT2232 の 2 番目のチャンネル (`/dev/ttyUSB2`、115200 8N1)。

| 項目 | 結果 |
|---|---|
| ピン、PLL、リセット | 動く。UART の向き (69 = FPGA の TX) も合っていた。S1 / S2 の極性は、リセットが外れて動いたので S1 は合っている。S2 は未確認 |
| SDRAM (54 MHz) | `Matenro Memory >>>… OK 2048K` が通った。読み取りのタイミング (READ から 3 クロック) はそのままで合った |
| 8088 の自己判定 (`xltest88`) | 書き込んだだけで `SLR A5 00 132D` (期待値どおり。XE は 4,909 kHz) |
| SD カード (`boot`) | **9K と同じ形式のカード** (先頭の 1MB が `/d0`、128MB の位置に `/d1`) から OS-9 Level 2 が起動した。ピン (81-84) は合っていた |
| CP/M-86 | `cpm hello86.cmd abc` が `Hello from CP/M-86 on the 8088` / `!` / ` ABC`。`fileio86.cmd` が `FILEIO86 OK` (SD への書き込みを含む)、`line86.cmd` (行入力) も動いた |
| MS-DOS 2.0 | `dos -v=2 -a=dosrun2.img -t=/d1/dostmp.img tbasic` で DOS が起動し、Tiny BASIC (`tests/dos/tbasic.asm`) が `RUN` で計算と `RND` を出し、`bye` で OS-9 に戻った (MANUAL 6.9 の実行モード) |

* **ブートのメッセージ**: `Tang Nano 9K` は、カードの ROM イメージ (LSN 1100 から 112 セクタ) の INIT モジュールの中の名前です。`mkdisk.sh` が sim09 の `init.asm` の写し (名前だけ `Tang Nano 20K` にしたもの。sim09 は変えない) からモジュールを作り直し、`make9rom` でイメージを作り直して差し替えます。
* **カード**: `fpga/tn20k/scripts/mkdisk.sh` が `/d0` を作る (9K の `/d0` に `dos`、CP/M-86 の試験、`/d0/dos` の MS-DOS 2.0 の一式を足したもの)。9K のカード全体のイメージの先頭 1MB を差し替える: `sudo dd if=fpga/tn20k/build/matenro20k_l2.dsk of=/dev/sdX bs=1M count=1 conv=fsync`。**MS-DOS の作業用イメージは 360KB で `/d0` に置けないので、`dos -t=/d1/dostmp.img` で `/d1` (64MB) に置く。**
* **SKK 辞書** (`jwp` の既定 `/d1/skk.dic`、UTF-8、約 5.6MB): `mkdisk.sh` が `SKK-JISYO.L` (`apt install skkdic`、場所は `SKKJISYO=`) から sim09 の `tools/mkskkdic.py -e utf8` で作り、`kanji.bin` と一緒に `/d1` に入れます。`/d1` だけを書き直すなら `sudo dd if=fpga/tn20k/build/matenro20k_d1.dsk of=/dev/sdX bs=1M seek=128 conv=fsync` (`/d0` は変わりません)。
* **未確認**: 性能 (`etime` で MCL86 の 4.9 MHz 相当を測る)、S2 ボタン、フラッシュへの書き込み (`-f`)、電源を入れ直したときの起動 (今は SRAM に書いたので、電源を切ると消える)、`load xlink` のドライバを入れた場合。
* **わかったこと**: 書き込み直後の UART に数文字の文字化けが出ることがある (`OOOKKHHHjymmm>`)。ツール (`openFPGALoader`) が JTAG を動かすときの雑音と見ている。UART を読む `cat` を 2 本同時に走らせると文字が欠ける (基板の不具合ではない)。

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
