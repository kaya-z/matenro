# 環境構築 (git clone から)

このリポジトリを `git clone` した人が、**自分の計算機で**シミュレータの作成、試験、SD カードのイメージ作りまでできるようにするための手順です。ビットストリームの作成 (Gowin IDE) は、**筆者の環境に特化している**ので、7 章を先に読んでください。

## 1. 動作を確認した環境

筆者の環境 (Debian 12 / x86-64) だけで確認しています。ほかの OS、CPU、ツールのバージョンでは確認していません。

| ツール | 確認した版 | 使う場所 |
|---|---|---|
| OS | Debian GNU/Linux 12 (bookworm)、x86-64 | |
| `gcc`、GNU `make` | gcc 12.2.0、GNU Make 4.3 | シミュレータ (`make`) |
| `python3` | 3.11.2 | 試験、アセンブラ (`tools/z80asm.py`)、各スクリプト |
| `nasm` | 2.16.01 | 8088 / CP/M-86 / DOS のプログラム |
| `git` | 2.39 | |
| [sim09](https://github.com/kaya-z/sim09) | `git clone` したそのまま | 6809 のアセンブラ `tools/a09`、OS-9 のイメージ `os9/`、FPGA の部品 `fpga/tn9k/rtl` |
| Verilator | 5.006 | RTL の試験 (`make test-fpga`、`make test-tn20k`) |
| `openFPGALoader` | 0.10.0 | ビットストリームをボードに書く |
| **Gowin IDE** | **V1.9.11.03 Education (Linux)** | ビットストリームを作る (**7 章**) |

## 2. clone する

sim09 は、**このリポジトリと同じ階層** (`../sim09`) に置くと、何も指定せずに見つかります。

```sh
mkdir work && cd work
git clone https://github.com/kaya-z/matenro
git clone https://github.com/kaya-z/sim09           # 読み取り専用で使います (変更しません)
cd matenro
make                # ./matenro ができる
make test           # アセンブラ 90、Z80 179、8088 67 の項目と、統合試験 (下)
```

別の場所に置くときは、`SIM09=<sim09 のディレクトリ>` (FPGA、カードのスクリプトと、`fpga/*/sim` の Makefile)、`A09=<sim09>/tools/a09` と `OS9DIR=<sim09>/os9` (`make test`) を指定します。**`SIM09` は sim09 のディレクトリそのもの** (`~/sim09`) です。旧い書き方 (`~/sim09/fpga/tn9k`) も、そのまま受け付けます。

**ほかに要るもの (必要なときだけ)**: どれもこのリポジトリには入っていません。

| 何のために | 入手先 | 指定の仕方 |
|---|---|---|
| FPGA の RTL 試験、ビットストリーム (Z80 の Verilog コア) | [hutch31/tv80](https://github.com/hutch31/tv80) の `rtl/core/` | `TV80=<そのディレクトリ>` (既定は `private/tv80src/rtl/core`) |
| MS-DOS 1.25 / 2.0 の試験、20K のカード (`dos`) | [microsoft/MS-DOS](https://github.com/microsoft/MS-DOS) の `v1.25/source`、`v2.0/source` (MIT)、それを組む MASM 互換のアセンブラ [UASM](https://github.com/Terraspace/UASM) | `MATENRO_DOS_SRC=` `MATENRO_DOS2_SRC=` `UASM=` (カードは `MSDOS2_SRC=` `UASM=`) |
| Turbo Pascal、HI-TECH C、DR の CP/M ツール、ZEXDOC | 各自 | `MATENRO_TP=` `MATENRO_HTC=` `MATENRO_CPM=` (試験)、`TPDIR=` `HTC=` `ZEX=` `TP=` (カード) |

指定がなければ、その試験は `skip` と出て飛ばされます (失敗にはなりません)。

## 3. 何ができるか (外部のものなし)

| 目的 | 手順 | 結果 (筆者の環境) |
|---|---|---|
| シミュレータ | `make` | `./matenro` |
| 試験 | `make test` | アセンブラ 90、Z80 179、8088 67、統合 56 項目、**すべて通る** (外部のものが要る項目は `skip`) |
| RTL の試験 (XLINK、SoC) | `make test-fpga TV80=<tv80/rtl/core>` | 通る (Verilator、TV80 が要る) |
| 20K の RTL の試験 | `make test-tn20k TV80=<tv80/rtl/core>` | 通る (6 章。約 25 分) |
| 9K のカード (`/d0`) | `fpga/tn9k/scripts/mkdisk.sh OUT.dsk` | 通る |
| 20K のカード | `MSDOS2_SRC=… UASM=… fpga/tn20k/scripts/mkdisk.sh …` | MS-DOS のソースと UASM が要る |
| ビットストリーム | `fpga/tn20k/scripts/build.sh boot` ほか | **Gowin IDE が要る (7 章)** |

SD カードへの書き込み (`dd`)、ボードの USB シリアル (`/dev/ttyUSB*`。番号は環境で変わります。`dialout` グループへの追加と、`openFPGALoader` 用の udev の設定が要ることがあります) は、[MANUAL.md](MANUAL.md) の 4 章と 10 章にあります。

## 4. 実行ファイルの違い、環境ごとに変わるところ

このリポジトリのスクリプトは、すべて POSIX の `/bin/sh` (bash の機能は使っていません) ですが、次の点は**環境で違う**ことがあります。

| 項目 | 内容 | 違う環境でのやり方 |
|---|---|---|
| C コンパイラ | Makefile は `CC ?= gcc` | `CC=cc make` や `CC=clang make` |
| `make` | GNU make の書き方 (`$(abspath …)`、`?=` など) | BSD の `make` では `gmake` を使う |
| **`sim09` の実行ファイル** | `tools/a09`、`tools/make9rom`、`tools/os9mod` は **x86-64 Linux の実行ファイルがそのまま入っている** | ほかの CPU や OS では、sim09 の `tools/a09.c`、`makerom.c`、`os9mod.c` を `cc` で組み直して、同じ名前で置く (`cc -O2 -o tools/a09 tools/a09.c`) |
| `python3` | 名前は `python3` のまま呼んでいる | `python3` が無ければ、`PATH` の中に `python3` の名前を作る (`ln -s $(command -v python) ~/bin/python3`) |
| `nasm` | 名前は `nasm` のまま | 実行ファイル名が違うなら、`PATH` に別名を作る |
| GNU の機能 | スクリプトが、`sed -i`、`stat -c`、`readlink -f`、`dd status=none`、`mktemp -d` を使う (カードの `mkdisk.sh`、`build.sh`) | macOS や BSD では、GNU の coreutils と sed を入れて、`gsed` などを `sed` の名前で先に `PATH` に置く |
| `verilator` | 5.006 で確認。`-Wno-…` の一覧を Makefile が決め打ちしている | 版が違うと、警告の名前が変わって止まることがある |
| 絶対パス | リポジトリの中に、作者のマシンの絶対パスは**ありません** (2026-11-19 に `grep` で確認) | |
| 既定の置き場所 | sim09 は `../sim09`。Gowin IDE は `/usr/local/IDE`。TV80 (`private/tv80src/rtl/core`)、DOS の組み上がり (`private/dosout`)、DOS 版 Turbo Pascal (`private/TurboPascal/MSDOS`) は、**筆者の作業場所 `private/`** (`.gitignore` で git の管理外。clone には**ありません**) | 環境変数 `SIM09`、`GOWIN_IDE`、`TV80`、`DOSOUT`、`TPDIR` で変える |

## 5. 検証の方法と結果 (2026-11-19)

第三者が clone した状況を、次の方法で確かめました。

1. 作業ツリーとは別の場所に `git clone` して、`sim09` を GitHub から clone しなおし、TV80 も GitHub から取った。
2. 筆者のホームと、NAS のディレクトリ (`/export`、`/home`、`/tmp`) を **bubblewrap で空にして見えなくした環境**の中で、clone のコマンドだけを実行した (筆者のパスや設定が、隠れて効いていないことの確認)。
3. その結果:
   * `make`、`make test` (アセンブラ 90、Z80 179、8088 67、統合 56 項目、失敗なし)、`make test-fpga TV80=…`、`fpga/tn9k/scripts/mkdisk.sh` が通った。
   * `make test-tn20k TV80=…` も通った (6 章)。

見つかって直したこと:

* `fpga/tn9k/sim/Makefile` と `fpga/tn20k/sim/Makefile` の `SIM09` の既定値が**相対パス**で、Verilator が別のディレクトリで動くと、`tb.cpp` が見つからず失敗した (筆者の環境では、絶対パスを環境変数で指定していたので気づかなかった)。`$(abspath …)` にした。
* `SIM09` の意味が、スクリプトで違っていた (カードは sim09 のディレクトリ、`build.sh` と `sim` の Makefile は `sim09/fpga/tn9k`)。どれも、sim09 のディレクトリを渡せば動くようにした。
* MANUAL の「`SIM09` の既定は筆者の環境のパス」という記述を直した。

## 6. 20K の RTL の試験

`make test-tn20k` は、Verilator で 20K の SoC を動かす試験です。**TV80** と sim09 の `tb.cpp` が要ります。筆者の環境で、clone だけの状態 (5 章) で通った結果:

| 試験 | 結果 |
|---|---|
| 8088 の SoC (`i8088_soc`) | 6 項目、失敗 0 |
| SDRAM のコントローラとモデル | 72,693 項目、失敗 0、モデルの誤り 0 |
| 読み出しキャッシュ (`rcache`) | 35,072 回の参照、失敗 0 |
| HDMI の文字、漢字、フレームバッファの表示 | 誤った画素 0 (文字 0 / 307,200) |
| 描画 (`gfx`)、CP/M-80 と CP/M-86 の `gdemo`、`gdirect` | 誤ったバイト 0 / 76,800 (6 項目) |

* かかる時間は約 25 分です (CPU の数で変わります。Verilator は `-j 8` で組み直します)。
* 途中で、`fbsoc ... | grep -q FBALIVE` の行に `Error 141` と出ますが、これは `grep -q` が先に終わったことによる SIGPIPE で、試験の失敗ではありません (そのあとの試験が続きます)。

## 7. Gowin IDE について (注意)

**ビットストリームを作るスクリプトは、筆者の環境の Gowin IDE に特化しています。** ほかの版や環境で動くことは、確認していません。

* **版**: Gowin IDE **V1.9.11.03 Education** (Linux、`/usr/local/IDE`)。デバイスは `GW1NR-9C` (Tang Nano 9K) と `GW2AR-18C` (Tang Nano 20K)。
* **呼び出し方**: `fpga/tn9k/scripts/build.sh`、`fpga/tn20k/scripts/build.sh`、`fpga/synth/run.sh` が、`env -u DISPLAY QT_QPA_PLATFORM=offscreen $GOWIN_IDE/bin/gw_sh build.tcl` を呼びます (画面なしで動かすための指定。**環境変数 `GOWIN_IDE`** か、第 2 引数で IDE の場所を変えられます)。Tcl のコマンドと、`set_option` の項目は、この版のものです。
* **タイミングの制約を書き換えています**: `build.sh` は、生成した `timing.sdc` を `sed -i` で書き換えて、システムクロックを、実際の PLL (54 MHz) より高い値 (27 × 15 / 7 = 57.857 MHz) だと IDE に教えます (`OVER=1`、既定。実際の PLL は変えません。`fpga/tn20k/scripts/build.sh` の先頭のコメント)。ほかの版の IDE では、この行の書き方が変わっていることがあります。
* **結果は IDE の版と乱数で変わります**: 配置配線の結果 (Fmax、LUT 数) は、版、設定、入力のわずかな違いで数 MHz 動きます。docs/FPGA_RESOURCES.md の数字は、この版での値です。`clk81` の余裕が小さい版 (見かけの制約 57.857 MHz に対して 57.932 MHz) もあり、**ほかの環境では、タイミングが通らないことがあります**。
* **ライセンス**: Gowin IDE は Gowin の製品で、**このリポジトリには入っていません**。使うときは、Gowin のライセンス (Education 版など) に従います。
* **ビットストリームを配っていません**: `.fs` はリポジトリに入っていません。ボードで試すには、自分でビルドする必要があります。
* ほかのツール (Yosys + nextpnr-gowin / Apicula) では、**作っていません**。HDMI の出力 (`OSER10`)、BSRAM の使い方などは、未確認です。

ビットストリームを作らなくても、シミュレータ (`make test`)、RTL の試験 (Verilator)、カードのイメージ作りは、Gowin IDE なしでできます。
