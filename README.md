# 摩天楼 (Matenro): MC6809 (OS-9 Level 2) + 差し替え可能なサブ CPU (Z80 / 8088) のシミュレータ

FM-11 の「マンハッタンシステム」のように、**異種 CPU を 1 つのメモリに密結合**したマシンを C 言語で作りました。
MC6809 側は [sim09](https://github.com/kaya-z/sim09) をベースにしていて、OS-9 Level 2 がそのまま動きます。
サブ CPU は 1 ファイルで差し込む作りで、**Z80** と **8088** が入っています。
**OS-9 のコマンド `cpm` で、Z80 では CP/M-80 の `.COM`、8088 では CP/M-86 の `.CMD` が動きます** ([下](#cp-m-のプログラムを-os-9-から動かす))。

* 2 つの CPU は**物理 RAM を共有**し、**それぞれの最大クロック** (6809 = 2 MHz、Z80 = 8 MHz、8088 = 8 MHz) で同時に動きます。
* 6809 側のメモリ・MMU・I/O は sim09 のまま (Level 2: 8KB × 8 ページの MMU、物理 2MB、I/O は `$FF80`)。
* ストレージは SD カード相当のディスクイメージ (6809/OS-9 側だけが持つ。生デバイスも指せる)。
* Linux (Debian 12) で動く C のプログラムです (gcc、make)。
* **FPGA 版 (Tang Nano 9K) は動いています** ([docs/FPGA.md](docs/FPGA.md)): sim09 の SoC に Z80 をつないだもの (6809 コア + PSRAM + SD + XLINK + Z80、`fpga/tn9k/`) を作り、**実機で OS-9 Level 2 が SD カードから起動し、`cpm` で CP/M-80 のプログラムが動きます**。6809 は E = 1.875 MHz、Z80 は 7.5 MHz (システムクロック 67.5 MHz の 1/36 と 1/9) です。実機で HI-TECH C のコンパイル (`cc80`) と ZEXDOC (Z80 の命令 67 項目、約 3 時間) が通りました。LUT は 88%、電源投入時に PSRAM の検査 (`Memory >>>>… OK 2048K`、約 4.5 秒) をします。タイミングは 67.5 MHz に収めていて、実機は 74.25 MHz でも動きましたが、ツールのモデルでは余裕が小さいです ([docs/FPGA_RESOURCES.md](docs/FPGA_RESOURCES.md))。XLINK (`fpga/rtl/xlink.v`) と Z80 (`fpga/rtl/z80_soc.v`) は Verilator でも C のシミュレータと同じ結果を確認しています (`make -C fpga/sim`)。8088 は 9K に載らないので、シミュレータだけです (20K のボードが要ります)。

**使い方は [docs/MANUAL.md](docs/MANUAL.md)** (ユーザーマニュアル)。詳しい設計: [docs/DESIGN.md](docs/DESIGN.md)。クレジット: [CREDITS.md](CREDITS.md)。

## Claude Code による開発

このプロジェクトは **Claude Code (Anthropic の AI コーディングツール) を使って開発しました**。C のシミュレータ、Z80 / 8088 のコア、OS-9 のコマンドとドライバ (6809 のアセンブラ)、FPGA の RTL とビルドスクリプト、テスト、文書は、Claude が書いたものです。要求の提示、実機 (Tang Nano 9K) の接続、SD カードの書き込み、実機の結果の確認は人 (kaya-z) が行いました。土台の [sim09](https://github.com/kaya-z/sim09) と、使った外部のコード (TV80、ZEXDOC、HI-TECH C など) の出典とライセンスは [CREDITS.md](CREDITS.md) に書いています。

## ビルドとテスト

```sh
make            # ./matenro を作る
make test       # アセンブラ + Z80 / 8088 のテスト + 統合テスト (a09 と nasm が要る。下を見てください)
```

必要なもの: `gcc` `make` `python3`、テストには `nasm` (8088 のプログラム) と、6809 のアセンブラ `a09`。
`a09` と OS-9 のイメージは [sim09](https://github.com/kaya-z/sim09) のものを使います (`git clone https://github.com/kaya-z/sim09`)。
テストの既定の場所は筆者の環境のパスなので、**`A09=<sim09>/tools/a09` と `OS9DIR=<sim09>/os9`** を環境変数で指定してください (FPGA のスクリプトは `SIM09=<sim09>`)。
sim09 は**読み取り専用**で使います (ディスクイメージはテストが一時ディレクトリに複製してから使います)。

テストの内容 (Debian 12 で全部通っています):

| | |
|---|---|
| `make test-z80` | Z80 の既知答えテスト 179 項目 |
| `make test-8088` | 8088 の自己判定プログラム (nasm) + クロック数 + 割り込み 64 項目 |
| `make test-mh` | 6809 ↔ Z80 / 8088 の統合 (メールボックス、doorbell の割り込み、共有 RAM、ウィンドウ、SMMU)、サブ CPU 単独、トレース、OS-9 Level 2 の起動 (サブ CPU なし/あり)、OS-9 上の `xrun`、**`cpm` で CP/M-80 と CP/M-86 のテストプログラム**を動かす、OS-9 の `cpp` (6 項目)、`MATENRO_HTC` があれば `cc80` で HI-TECH C まで通す、ドライバ `xlink` 3 項目 (Z80 と 8088、Z80 と BDOS を 3000 回繰り返す負荷試験)、全部で 38 項目 (`MATENRO_HTC` があれば 41 項目) |
| `make test-asm` | 自作 Z80 アセンブラの既知の機械語 90 項目 |

**テストの限界**: 期待値は資料から手で計算したものです。Z80 は公開テスト ZEXDOC (67 項目) を `cpm` 経由で、シミュレータと**実機の FPGA** (7.5 MHz、約 3 時間) の両方で通しました (リポジトリには入れていません)。実機の 1 回目は、7 項目目のあとで出力が止まりましたが、同じ条件で 2 回やり直すと 2 回とも完走し、原因は分かっていません ([docs/FPGA.md](docs/FPGA.md) の 9.3)。8086 の公開テストは**走らせていません**。
8088 のクロック数は、プリフェッチキューを作っていないので近似です ([docs/DESIGN.md](docs/DESIGN.md) の 3.2)。

## 使い方

### サブ CPU だけを動かす (6809 は何もしない)

```sh
./matenro -max -m 1M -rom idle.rom -sub z80 -xrun -xload prog.bin@0 -xcon out.txt
```

`-xload ファイル@16進アドレス` でサブ CPU のアドレス空間にプログラムを置き、`-xrun` でリセットを外します。サブ CPU のデバッグコンソール
(ポート `$0E`) は `-xcon` のファイル (既定は stderr) に出ます。ポート `$0F` に `$A5` を書くとシミュレータが終わります。
`-xt trace.txt` でサブ CPU の命令ごとのトレース (PC とレジスタ) が取れます。

### OS-9 Level 2 から使う (`xrun`)

OS-9 の上で動くコマンド `xrun` (`os9/xrun.asm`) が、サブ CPU のプログラムをファイルから読み込んで動かし、メールボックスで答えを受け取ります。
サブ CPU の RAM は OS-9 の RAM とぶつからないよう、`-m 1M` で OS-9 を下半分 1MB に閉じ込めます (上半分がサブ CPU のプール)。

```sh
SIM09=~/sim09                                                          # git clone https://github.com/kaya-z/sim09
SBC=$SIM09/os9
mkdir -p /tmp/mh/v0 && cp $SBC/OS9.dsk $SBC/WORK.dsk /tmp/mh/          # ディスクは書き換わるので複製を使う
cp -r $SBC/level2/cmds /tmp/mh/v0/cmds
(cd os9 && $SIM09/tools/a09 -I $SBC/nitros9-code/defs/ -o /tmp/mh/v0/cmds/xrun xrun.asm)
python3 os9/sub/sumz80.py /tmp/mh/v0/sumz80.bin                        # Z80 のデモ (1+2+...+n)
nasm -f bin os9/sub/sum8088.asm -o /tmp/mh/v0/sum8088.bin              # 8088 のデモ

./matenro -m 1M -sub z80 -rom $SBC/os9v2.rom -0 /tmp/mh/OS9.dsk -1 /tmp/mh/WORK.dsk -v /tmp/mh/v0
```

```
OS9:chx /v0/cmds
OS9:xrun /v0/sumz80.bin 100        Z80 に 100 を渡す → 1+2+...+100 = 5050 = $13BA が返る
reply: BA 13 00 00
```

8088 なら `-sub 8088` で起動して `xrun /v0/sum8088.bin 100` です。`xrun [-l=16進アドレス] ファイル [n]` の詳細は `os9/xrun.asm` の先頭にあります。
終了は `Ctrl-]` でモニタに入って `q` です (sim09 と同じ)。

### CP/M のプログラムを OS-9 から動かす

**すぐ試す**: `tools/try_cpm.sh` (Z80)、`tools/try_cpm.sh 8088` (8088)。OS-9 が起動するので `chx /v0/cmds`、`chd /v0`、`cpm hello.com abc` と打ちます。作業場所は `/tmp/matenro_try` (環境変数 `WORK`)。

OS-9 のコマンド `cpm` (`os9/cpm/cpm.asm`) が、CP/M-80 (`-sub z80`) または CP/M-86 (`-sub 8088`) のプログラムをサブ CPU で動かします。
BDOS の呼び出しは OS-9 が引き受けて、コンソールは OS-9 の標準入出力、ファイルは OS-9 のファイル (カレントデータディレクトリ) になります。

```sh
make os9cmds                                              # build/os9/ に cpm xrun cpp cc80 (OS-9 のモジュール) を作る
python3 tools/z80asm.py tests/cpm/hello.asm -o /tmp/mh/v0/hello.com                       # CP/M-80 のプログラム (自作の小さなアセンブラ)
nasm -f bin tests/cpm/hello86.asm -o /tmp/h86.bin && python3 tools/mkcmd.py 8080 /tmp/h86.bin /tmp/mh/v0/hello86.cmd   # CP/M-86 のプログラム
cp build/os9/cpm /tmp/mh/v0/cmds/                          # /tmp/mh の準備は上の xrun の例と同じ
./matenro -m 1M -sub z80 -rom $SBC/os9v2.rom -0 /tmp/mh/OS9.dsk -1 /tmp/mh/WORK.dsk -v /tmp/mh/v0
```

```
OS9:chx /v0/cmds
OS9:chd /v0
OS9:cpm hello.com abc def
Hello from CP/M-80 on the Z80
!
 ABC DEF
```

8088 のときは `-sub 8088` で起動して `cpm hello86.cmd abc` です。CP/M の CCP/BDOS/BIOS の実物は動かさない BDOS レベルの互換で、実物のソフトは
ZEXDOC (Z80 の命令、67 項目)と HI-TECH C 3.09 のコンパイラで確かめました。制約と仕組みは [docs/DESIGN.md](docs/DESIGN.md) の 12 章に書きました。

### OS-9 のツールと CP/M のツールを続けて使う (`cpp` と `cc80`)

OS-9 側で作った C のプリプロセッサ `cpp` (`os9/cpp/cpp.asm`、6809 のアセンブラ) を通して、CP/M-80 の C コンパイラ (HI-TECH C 3.09) でコンパイルし、
できた `.COM` を Z80 で動かすまでを、`cc80` (`os9/cc80/cc80.asm`) が 1 コマンドで行います。

```
OS9:cc80 -r -v demo.c
+ cpp -DCPM -DHI_TECH_C -Dz80 -I/v0/htc -odemo.i demo.c
+ cpm -k -p=/v0/htc p1 demo.i demo.p1 demo.p2
+ cpm -k -p=/v0/htc cgen demo.p1 demo.as
+ cpm -k -p=/v0/htc zas -J -N -Odemo.obj demo.as
+ cpm -k -p=/v0/htc linq -Z -Ptext=0,data,bss -C100H -Odemo.com crtcpm.obj demo.obj libc.lib
+ cpm demo.com
big 36
```

HI-TECH C (P1.COM CGEN.COM ZAS.COM LINQ.COM CRTCPM.OBJ LIBC.LIB LIBF.LIB とヘッダ) は**このリポジトリに入っていません**。<https://github.com/agn453/HI-TECH-Z80-C>
から自分で取得して `/v0/htc` (または `-t=dir`) に置いてください。テストは環境変数 `MATENRO_HTC=そのディレクトリ` のときだけ `cc80` を試します。
`cpp` だけでも使えます (`cpp -Dname=v -Idir -ofile file.c`、`#` `##` は関数形式マクロのみ)。仕組みは [docs/DESIGN.md](docs/DESIGN.md) の 13 章です。

### 主なオプション (sim09 のオプションは、そのまま使えます)

| オプション | 意味 |
|---|---|
| `-sub z80\|8088` | サブ CPU を差し込む (Level 2 のみ) |
| `-subclock Hz` | サブ CPU のクロック (既定はその CPU の最大: Z80 8 MHz、8088 8 MHz) |
| `-clock Hz` | 6809 のクロック (既定 2000000 = MC68B09E。sim09 は 1843200) |
| `-m サイズ` | 6809 (OS-9) が使う RAM (既定 2M)。残りが 2MB までサブ CPU 用のプール |
| `-xbase ブロック` | サブ CPU のアドレス 0 が写る物理 8KB ブロック (既定 `$80` = 物理 1MB) |
| `-xload ファイル@アドレス` | サブ CPU のアドレス空間にバイナリを置く (繰り返し可) |
| `-xrun` | 電源投入時からサブ CPU を動かす (普通は 6809 が `XCTL` で動かす) |
| `-xt ファイル` `-xcon ファイル` | サブ CPU のトレース / デバッグコンソールの出力先 |
| `-xquantum n` | 2 つの CPU を同期させる間隔 (6809 のサイクル数、既定 16) |
| `-L1` | Level 1 のマシン (フラット 64KB、サブ CPU なし) |
| `-max` | 実時間に合わせず全速で実行 |
| `-nomemtest` | 電源投入時のメモリ検査をしない (実機と同じく、既定では `Memory >>>>…>>> OK 2048K` を出す。手順は `src/memtest.c`) |
| `-memfault アドレス` | (デバッグ) メモリ検査に、この物理アドレス (16 進) のビット固定故障を見せて `NG @アドレス` の表示を試す |

## サブ CPU を足す

`src/xxx.c` に `const sub_cpu_ops_t sub_cpu_xxx` を書き (`src/subcpu.h`、手本は `src/z80.c`)、`xlink.c` の `registry[]` と `Makefile` に 1 行ずつ足すだけです。

## ファイル

```
src/            sim09 の複製 (m6809 dis6809 console net vdisk dbg) + 変更 (machine main) + 新規 (subcpu.h z80.c i8088.c xlink.c/h)
os9/            xrun.asm と cpm/ cpp/ cc80/ (OS-9 Level 2 のコマンド `xrun` `cpm` `cpp` `cc80`)、sub/ (デモのサブ CPU プログラム)
tools/          z80asm.py (Z80 アセンブラ)、mkcmd.py (CP/M-86 の .CMD を作る)、build_cpm.sh (OS-9 コマンドのビルド)
tests/          z80_test.c i8088_test.c (+ i8088/core.asm) matenro_test.py z80asm_test.py mh/xlink_test.asm cpm/ (CP/M のテストプログラム) cpp/ (cpp と cc80 の C ソース)
docs/           DESIGN.md (設計・レジスタ仕様) FPGA.md (FPGA の検討)
fpga/           rtl/ (xlink.v z80_sub.v z80_soc.v)、sim/ (Verilator のテスト、テストベンチは Verilog: make -C fpga/sim)、synth/run.sh (Gowin で合成して資源を出す)
fpga/tn9k/      Tang Nano 9K の SoC (rtl/、scripts/build.sh でビットストリーム、mkdisk.sh と mkdisk_d1.sh で SD イメージ、sim/ で RTL シミュレーション)
```

## できていないこと

* **8088 の FPGA 版**。8088 のコアは手元になく、見積もり (3,000〜6,000 LUT) だけです。9K には載らず、20K のボードが要ります (シミュレータでは動きます)。
* FPGA 版の **HDMI の画面と RTC** (どちらも載せられますが、書いていません。9K の LUT は残り約 10% で HDMI は載りません)。
* FPGA のタイミングの余裕は小さいです (67.5 MHz で 0.1〜0.5 ns)。実機では問題なく動いていますが、RTL を変えるたびに配置配線の結果が変わるので、毎回 `Total Negative Slack Summary` を見てください。
* 実物の CP/M ソフトでの検証は ZEXDOC と HI-TECH C だけです (WordStar など他は未確認)。CP/M の CCP/BDOS/BIOS の実物、BIOS 直接呼び出し、複数ドライブ、リネームは未対応。MS-DOS は対象外にしました (8088 は CP/M-86 を選びました)。
* OS-9 のデバイスドライバ (`os9/xlink`、メモリを OS-9 の空き RAM から借りる) は doorbell を**割り込みで通知しません** (sim09 の Clock が割り込み表を調べないため。ポーリングで待ちます。docs/DESIGN.md の 14 章)。
* メモリ競合 (2 つの CPU が同じ RAM を取り合うときの待ち) のモデル。
* 8086 の外部テストスイートでの検証、サブ CPU の逆アセンブル付きトレース。
* FM-11 の実際のマンハッタンシステムとの互換性 (考え方だけを借りています)。
