# 摩天楼 (Matenro): MC6809 (OS-9 Level 2) + 差し替え可能なサブ CPU (Z80 / 8088) のシミュレータと FPGA 実機 (Tang Nano 20K / 9K)

FM-11 の「マンハッタンシステム」のように、**異種 CPU を 1 つのメモリに密結合**したマシンを、C 言語のシミュレータと、FPGA ボード (**Tang Nano 20K** と **9K**) の実機で作りました。
MC6809 側は [sim09](https://github.com/kaya-z/sim09) をベースにしていて、OS-9 Level 2 がそのまま動きます。
サブ CPU は 1 ファイルで差し込む作りで、**Z80** と **8088** が入っています。
**OS-9 のコマンド `cpm` で、Z80 では CP/M-80 の `.COM`、8088 では CP/M-86 の `.CMD` が動きます** ([下](#cp-m-のプログラムを-os-9-から動かす))。8088 では MS-DOS も動きます (`dos`)。

| 形 | サブ CPU | 動かせるもの |
|---|---|---|
| **シミュレータ** (`./matenro`、Linux) | Z80 または 8088 | CP/M-80、CP/M-86、MS-DOS 1.25 / 2.0 |
| **Tang Nano 20K** (実機、54 MHz、HDMI つき) | Z80 と 8088 (OS-9 から `subsel` で切り替え) | 上の全部、HDMI の文字・漢字・フレームバッファ、デモ |
| **Tang Nano 9K** (実機、67.5 MHz) | Z80 のみ | CP/M-80 (HI-TECH C、Turbo Pascal、ZEXDOC) |

実機を使うなら **20K** をすすめます。9K は Z80 だけで、HDMI がありません。

* 2 つの CPU は**物理 RAM を共有**し、**それぞれの最大クロック** (6809 = 2 MHz、Z80 = 8 MHz、8088 = 8 MHz) で同時に動きます。
* **デモ `duo`: 6809 と Z80 が一つの絵を一緒に描きます** ([docs/MANUAL.md](docs/MANUAL.md) の 6.7)。マンデルブロ集合 (25 行 × 79 桁) の行を、6809 と Z80 が共通の行カウンタから一行ずつ取り、同時に計算します。Z80 のプログラムは OS-9 の `duo` コマンドに組み込まれ、共有 RAM を通して 6809 と受け渡します。絵は、Z80 が計算した行をシアン、6809 が計算した行を黄色で書き、最後に各 CPU の行数と計算時間を出します (`-1` は 6809 だけ、`-z` は Z80 だけ、`-n` は色なし)。**色は ANSI のエスケープシーケンス (`ESC [ 36 m` など) で付けます。シミュレータの端末では色が付きます。実機では、エスケープシーケンスが画面側で解釈されない端末では色が付きません。色なしで出すには `-n`。**シミュレータでは 4.1 秒 (6809 が 17 行、Z80 が 8 行)、**実機 (Tang Nano 9K) では 5.8 秒 (6809 が 18 行、Z80 が 7 行)** です。6809 だけだと 7.5 秒、つまり二つで約 1.3 倍の速さです。**20K の実機 (Z80 7.7 MHz) では 4.3 秒 (6809 が 18 行、Z80 が 7 行)、6809 だけで 5.9 秒、Z80 だけで 13.5 秒** です (約 1.4 倍)。
* **20K のデモ: 8088 と 6809 が HDMI に一緒に描きます** ([docs/MANUAL.md](docs/MANUAL.md) の 6.10)。マンデルブロ競演 (8088 が上半分、6809 が下半分、所要時間を比べる)、星空とボール、回る 3D の立方体を、`/d0` の `shell <show` で順に見せます (日本語のタイトル付き。電源を入れたあと `kanjild` が要ります)。

  ```
  OS9:chx /d0/cmds
  OS9:load xlink          (9K では要る。20K とシミュレータの -m 1M の運用では不要)
  OS9:load x0
  OS9:duo
  ```
* 6809 側のメモリ・MMU・I/O は sim09 のまま (Level 2: 8KB × 8 ページの MMU、物理 2MB、I/O は `$FF80`)。
* ストレージは SD カード相当のディスクイメージ (6809/OS-9 側だけが持つ。生デバイスも指せる)。
* 8088 では、CP/M-86 のほかに **MS-DOS 1.25 と 2.0 が動きます** (OS-9 のコマンド `dos`。カーネルと `COMMAND` は Microsoft が公開したものを組むか、そのまま使います。`EDLIN`、`DEBUG`、`DATE`/`TIME`、プリンタ、ディスクイメージ。使い方は [docs/MANUAL.md](docs/MANUAL.md) の 6.8、設計は [docs/DESIGN.md](docs/DESIGN.md) の 18 章)。**`cpm` のように OS-9 のコマンドラインから `dos -v=2 -a=dosrun2.img tbasic` で DOS のプログラムも実行できます** (実行モード、MANUAL 6.9: OS-9 のカレントディレクトリのファイルを DOS のディスクに出し入れします)。
* Linux (Debian 12) で動く C のプログラムです (gcc、make)。
* **FPGA 版 Tang Nano 9K (Z80 のみ) は動いています** ([docs/FPGA.md](docs/FPGA.md)): sim09 の SoC に Z80 をつないだもの (6809 コア + PSRAM + SD + XLINK + Z80、`fpga/tn9k/`) を作り、**実機で OS-9 Level 2 が SD カードから起動し、`cpm` で CP/M-80 のプログラムが動きます**。6809 は E = 1.875 MHz、Z80 は 7.5 MHz (システムクロック 67.5 MHz の 1/36 と 1/9) です。実機で HI-TECH C のコンパイル (`cc80`) と ZEXDOC (Z80 の命令 67 項目、約 3 時間) が通りました。LUT は 92% (CLS 96%。ほぼ満杯で、配置配線の結果で実機が止まることがあった: docs/FPGA_RESOURCES.md)、電源投入時に PSRAM の検査 (`Memory >>>>… OK 2048K`、約 4.5 秒) をします。タイミングは 67.5 MHz に収めていて、実機は 74.25 MHz でも動きましたが、ツールのモデルでは余裕が小さいです ([docs/FPGA_RESOURCES.md](docs/FPGA_RESOURCES.md))。XLINK (`fpga/rtl/xlink.v`) と Z80 (`fpga/rtl/z80_soc.v`) は Verilator でも C のシミュレータと同じ結果を確認しています (`make -C fpga/sim`)。8088 は 9K に載らないので、20K の版です (次の項目)。
* **FPGA 版 Tang Nano 20K (Z80 と 8088、HDMI) も実機で動いています** ([docs/TN20K.md](docs/TN20K.md)): 6809 + Z80 + 8088 (MCL86) と HDMI を載せた SoC (`fpga/tn20k/`) です。メモリはパッケージ内の SDRAM (OS-9 とサブ CPU が共有する 2MB。上は漢字と画面)、システムクロックは 54 MHz (6809 は E = 約 1.9 MHz、Z80 は 7.7 MHz、8088 は 4.9 MHz) です。ビットストリームはフラッシュに書けます (`openFPGALoader -f`)。Z80 と 8088 は OS-9 から `subsel z80` / `subsel 8088` で切り替えて使います (同時には動かしません)。実機で、OS-9 Level 2 の SD カードからの起動、CP/M-80、CP/M-86、MS-DOS 1.25 / 2.0 (OS-9 の `dos` コマンド。Tiny BASIC など)、HDMI の文字画面、漢字 (`kanjild`)、320×240・256 色のフレームバッファと文字の重ね表示 (`gfx`) を確かめました。CP/M-80、CP/M-86、MS-DOS のプログラムからは、6809 に頼む (BDOS 112、`INT E2h`) か、フレームバッファをメモリとして直接書いて描けます ([docs/MANUAL.md](docs/MANUAL.md) の 6.8)。資源と Fmax は [docs/FPGA_RESOURCES.md](docs/FPGA_RESOURCES.md) の 7 章です。

**使い方は [docs/MANUAL.md](docs/MANUAL.md)** (ユーザーマニュアル。シミュレータ、20K、9K の別に書いています)。実機のビットストリームの作り方と SD カードの作り方は、MANUAL の 9、10 章です。詳しい設計: [docs/DESIGN.md](docs/DESIGN.md)。クレジット: [CREDITS.md](CREDITS.md)。

## Claude Code による開発

このプロジェクトは **Claude Code (Anthropic の AI コーディングツール) を使って開発しました**。C のシミュレータ、Z80 / 8088 のコア、OS-9 のコマンドとドライバ (6809 のアセンブラ)、FPGA の RTL とビルドスクリプト、テスト、文書は、Claude が書いたものです。要求の提示、実機 (Tang Nano 9K と 20K) の接続、SD カードの書き込み、実機の結果の確認は人 (kaya-z) が行いました。土台の [sim09](https://github.com/kaya-z/sim09) と、使った外部のコード (TV80、ZEXDOC、HI-TECH C など) の出典とライセンスは [CREDITS.md](CREDITS.md) に書いています。

## ビルドとテスト

```sh
make            # ./matenro を作る
make test       # アセンブラ + Z80 / 8088 のテスト + 統合テスト (a09 と nasm が要る。下を見てください)
```

必要なもの: `gcc` `make` `python3`、テストには `nasm` (8088 のプログラム) と、6809 のアセンブラ `a09`。
`a09` と OS-9 のイメージは [sim09](https://github.com/kaya-z/sim09) のものを使います (`git clone https://github.com/kaya-z/sim09`)。
sim09 は、このリポジトリと同じ階層 (`../sim09`) に置くと、既定のまま見つかります。別の場所に置くときは、**`A09=<sim09>/tools/a09` と `OS9DIR=<sim09>/os9`** を環境変数で指定してください (FPGA のスクリプトは `SIM09=<sim09>`)。
sim09 は**読み取り専用**で使います (ディスクイメージはテストが一時ディレクトリに複製してから使います)。

**`git clone` から始める人は [docs/SETUP.md](docs/SETUP.md) を先に読んでください** (確認した環境、sim09 と TV80 など外部のものの入手、実行ファイル名の違い、clone だけで試験が通ることの検証)。

> **注意: Gowin IDE (FPGA のビットストリームを作るツール) について。** `fpga/*/scripts/build.sh` は、**筆者の環境の Gowin IDE V1.9.11.03 Education (Linux、`/usr/local/IDE`) に特化**していて、ほかの版や環境で動くことは確認していません。配置配線の結果 (Fmax、LUT 数) も、その版での値で、ほかの環境ではタイミングが通らないことがあります。Gowin IDE はこのリポジトリに入っておらず、ビットストリームも配っていません。シミュレータ、RTL の試験 (Verilator)、カードのイメージ作りは、Gowin IDE なしでできます。詳しくは [docs/SETUP.md の 7 章](docs/SETUP.md#7-gowin-ide-について-注意)。

テストの内容 (Debian 12 で全部通っています):

| | |
|---|---|
| `make test-z80` | Z80 の既知答えテスト 179 項目 |
| `make test-8088` | 8088 の自己判定プログラム (nasm) + クロック数 + 割り込み 67 項目 |
| `make test-mh` | 6809 ↔ Z80 / 8088 の統合 (メールボックス、doorbell の割り込み、共有 RAM、ウィンドウ、SMMU)、サブ CPU 単独、トレース、OS-9 Level 2 の起動 (サブ CPU なし/あり)、OS-9 上の `xrun`、**`cpm` で CP/M-80 と CP/M-86 のテストプログラム**を動かす、OS-9 の `cpp80` (6 項目)、**`dos` で MS-DOS 1.25 と 2.0 を 8088 で動かす** (`MATENRO_DOS_SRC` `MATENRO_DOS2_SRC` と `UASM` があれば。1.25 は 17 項目、2.0 は 20 項目 (実行モードの 4 項目を含む))、`MATENRO_HTC` があれば `cc80` で HI-TECH C まで通す、ドライバ `xlink` 3 項目 (Z80 と 8088、Z80 と BDOS を 3000 回繰り返す負荷試験)、外部のものを指定しないと、全部で 56 項目が通り (2026-11-19 に確認)、HI-TECH C、Turbo Pascal、DR のツール、MS-DOS の試験は `skip` と出ます。`MATENRO_HTC` `MATENRO_TP` `MATENRO_CPM` `MATENRO_DOS_SRC` などを指定すると、その分の項目が増えます |
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
make os9cmds                                              # build/os9/ に cpm xrun cpp80 cc80 (OS-9 のモジュール) を作る
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
ZEXDOC (Z80 の命令、67 項目)、HI-TECH C 3.09 のコンパイラ、Turbo Pascal 3.0 (編集、コンパイル、実行、保存)、Digital Research の `STAT` `ASM` `LOAD` `PIP` `ED` `DDT` と `MBASIC` 5.21 で確かめました。制約と仕組みは [docs/DESIGN.md](docs/DESIGN.md) の 12 章に書きました。

### MS-DOS のプログラムを OS-9 から動かす (`dos`)

8088 を載せた Tang Nano 20K の実機と、シミュレータ (`-sub 8088`) で動きます (9K にはありません)。OS-9 のコマンド `dos` (`os9/dos/`) が MS-DOS 1.25 または 2.0 を 8088 で起動して、**`cpm` のように、OS-9 のコマンドラインから DOS のプログラムを実行**します。カレントの OS-9 ディレクトリのファイルを DOS のディスクに出し入れします。

1. MS-DOS の部品を作ります。カーネルと `COMMAND` は Microsoft が公開したソースを組みます (このリポジトリには入っていません)。2.0 は `tools/build_dosbin2.sh` (`MSDOS2_SRC` と、MASM 互換のアセンブラ `UASM` が要ります)、1.25 は `tools/build_dosbin.sh` (`MSDOS_SRC`) です。
2. DOS のディスクのイメージを作ります: `tools/build_dosrun.sh OUTDIR DOSBIN DOS2BIN` で `dosrun.img` (1.25、160 KB) と `dosrun2.img` (2.0、360 KB) ができます。
3. `make os9cmds` で `build/os9/dos` を作り、OS-9 の `cmds` に入れます。8088 で起動して (`tools/try_cpm.sh 8088`、実機は `subsel 8088`)、カレントのデータディレクトリに `msdos.sys`、`bios2.bin` (2.0 だけ)、イメージ、DOS のプログラム (`.COM`、`.EXE`) を置きます。
4. 実行します。

```
OS9:chx /v0/cmds
OS9:chd /v0
OS9:dos -v=2 -a=dosrun2.img tbasic
```

* `-v=2` は MS-DOS 2.0 です (なしは 1.25)。`-a=` は DOS のディスクのイメージ、`-t=` は作業用イメージの置き場所 (空きの少ないディスクでは `-t=/d1/dostmp.img`) です。`-` で始まらない最初の語から行末までが DOS に渡すコマンドです (引数も、`COPY` のような内部コマンドも、バッチファイルも書けます)。
* プログラムが作ったファイルは、終わるときに OS-9 のカレントディレクトリに書き戻されます。名前は DOS の 8.3 に限ります。
* **画面に直接書くプログラム** (Turbo Pascal の `TURBO.COM` など) は、2.0 に `-w=1` を付けると、IBM PC の文字画面 (B800h) として HDMI に出ます (20K のみ)。
* 詳しくは [docs/MANUAL.md](docs/MANUAL.md) の 6.8 と 6.9、設計は [docs/DESIGN.md](docs/DESIGN.md) の 18 章です。

### OS-9 のツールと CP/M のツールを続けて使う (`cpp80` と `cc80`)

OS-9 側で作った C のプリプロセッサ `cpp80` (`os9/cpp/cpp.asm`、6809 のアセンブラ) を通して、CP/M-80 の C コンパイラ (HI-TECH C 3.09) でコンパイルし、
できた `.COM` を Z80 で動かすまでを、`cc80` (`os9/cc80/cc80.asm`) が 1 コマンドで行います。

```
OS9:cc80 -r -v demo.c
+ cpp80 -DCPM -DHI_TECH_C -Dz80 -I/v0/htc -odemo.i demo.c
+ cpm -k -p=/v0/htc p1 demo.i demo.p1 demo.p2
+ cpm -k -p=/v0/htc cgen demo.p1 demo.as
+ cpm -k -p=/v0/htc zas -J -N -Odemo.obj demo.as
+ cpm -k -p=/v0/htc linq -Z -Ptext=0,data,bss -C100H -Odemo.com crtcpm.obj demo.obj libc.lib
+ cpm demo.com
big 36
```

HI-TECH C (P1.COM CGEN.COM ZAS.COM LINQ.COM CRTCPM.OBJ LIBC.LIB LIBF.LIB とヘッダ) は**このリポジトリに入っていません**。<https://github.com/agn453/HI-TECH-Z80-C>
から自分で取得して `/v0/htc` (または `-t=dir`) に置いてください。テストは環境変数 `MATENRO_HTC=そのディレクトリ` のときだけ `cc80` を試します。
`cpp80` だけでも使えます (`cpp80 -Dname=v -Idir -ofile file.c`、`#` `##` は関数形式マクロのみ)。仕組みは [docs/DESIGN.md](docs/DESIGN.md) の 13 章です。

**実機 (Tang Nano 9K と 20K) で使うとき** (20K でも `subsel z80` のあと `cc80 -t=/d1/htc -r hello.c` が動くことを、実機で確かめました): 上の例はシミュレータ (`/v0/htc` がホストのディレクトリ) の場合です。実機は HI-TECH C が SD カードの `/d1/htc` にあるので、`-t=/d1/htc` が要ります。ソース (`hello.c` `demo.c` `mandel.c`) も `/d1` にあるので、先に `chd /d1` します。

```
OS9:chx /d0/cmds
OS9:load xlink              (9K だけ。20K は `subsel z80` にする)
OS9:load x0                 (9K だけ)
OS9:chd /d1
OS9:cc80 -t=/d1/htc -r demo.c
big 36
OS9:del DEMO.COM
```

* `chd /d1` を忘れる、または `/d0` のままだと、`cc80: cannot open demo.c` で止まります (何も消しません)。`-t=/d1/htc` を付けないと、`cpp80:stdio.h` / `cc80: failed: cpp80` で止まります。
* 既定の `/d1` (512KB) は空きが **130 セクタ**だけです。`cc80 -r` は、できた `.COM` を残すので、**使い終えたら `del` で消してください**。満杯になると `cpm: a write failed (disk full)` / `cc80: failed: cpm` で止まります。`/d1` は **64MB のハードディスク**にもできます (`fpga/tn9k/scripts/bigd1.sh`、docs/MANUAL.md の 9 章)。そのカードイメージ `matenro_card_big.img` (約 192MB) なら、空きは約 63MB です。
* 時間の目安 (実機): `hello.c` は 1 分ほど、`mandel.c` (浮動小数点) は約 3 分です。コンパイル中はプロンプトが戻りません (待ってください)。

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
| `-nomemtest` | 電源投入時のメモリ検査をしない (実機と同じく、既定では `Matenro Memory >>>>…>>> OK 2048K` (行頭の `Matenro` で、素の sim09 の板と見分ける) を出す。手順は `src/memtest.c`) |
| `-memfault アドレス` | (デバッグ) メモリ検査に、この物理アドレス (16 進) のビット固定故障を見せて `NG @アドレス` の表示を試す |

## サブ CPU を足す

`src/xxx.c` に `const sub_cpu_ops_t sub_cpu_xxx` を書き (`src/subcpu.h`、手本は `src/z80.c`)、`xlink.c` の `registry[]` と `Makefile` に 1 行ずつ足すだけです。

## ファイル

```
src/            sim09 の複製 (m6809 dis6809 console net vdisk dbg) + 変更 (machine main) + 新規 (subcpu.h z80.c i8088.c xlink.c/h)
os9/            xrun.asm と cpm/ cpp/ cc80/ dos/ gfx/ demo/ (OS-9 Level 2 のコマンド `xrun` `cpm` `cpp80` `cc80` `dos` `gfx` とデモ)、sub/ (デモのサブ CPU プログラム)
demo/           20K のデモの 8088 側 (mand88.asm stars88.asm cube88.asm)
tools/          z80asm.py (Z80 アセンブラ)、mkcmd.py (CP/M-86 の .CMD を作る)、build_cpm.sh (OS-9 コマンドのビルド)、build_dosbin*.sh と build_dosrun.sh と mkdosimg.py (MS-DOS の部品とディスクイメージ)
tests/          z80_test.c i8088_test.c (+ i8088/core.asm) matenro_test.py z80asm_test.py mh/xlink_test.asm cpm/ (CP/M のテストプログラム) cpp/ (cpp80 と cc80 の C ソース)
docs/           MANUAL.md (ユーザーマニュアル) SETUP.md (clone から使うまで) DESIGN.md (設計・レジスタ仕様) FPGA.md (9K の検討と記録) TN20K.md (20K の設計と記録) FPGA_RESOURCES.md (資源とタイミング)
fpga/           rtl/ (xlink.v z80_sub.v z80_soc.v)、sim/ (Verilator のテスト、テストベンチは Verilog: make -C fpga/sim)、synth/run.sh (Gowin で合成して資源を出す)
fpga/tn9k/      Tang Nano 9K の SoC (rtl/、scripts/build.sh でビットストリーム、mkdisk.sh と mkdisk_d1.sh で SD イメージ、sim/ で RTL シミュレーション)
fpga/tn20k/     Tang Nano 20K の SoC (rtl/ に 20K 専用の matenro_soc.v などの写し (9K と分けてある) と HDMI、scripts/build.sh でビットストリーム、mkdisk.sh で SD イメージ、sim/ で RTL シミュレーション)。8088 とその部品は fpga/rtl/ と fpga/vendor/
```

## できていないこと

* FM-11 の実際のマンハッタンシステムとの互換性 (考え方だけを借りています)。
* FPGA 版の **RTC** (載せられますが、書いていません)。
* FPGA のタイミングの余裕は小さいです (9K は 67.5 MHz で 0.1〜0.5 ns、20K は 54 MHz に対して Fmax が 58.4 MHz)。実機では問題なく動いていますが、RTL を変えるたびに配置配線の結果が変わるので、毎回 `Total Negative Slack Summary` を見てください。
* 実物の CP/M ソフトでの検証は ZEXDOC、HI-TECH C、Turbo Pascal 3.0、DR の標準ツールと MBASIC です (WordStar など他は未確認)。CP/M の CCP/BDOS/BIOS の実物、BIOS のディスクの入口 (コンソールの入口だけ用意)、複数ドライブ、ワイルドカードの名前変更は未対応。
* MS-DOS は 1.25 と 2.0 だけです (2.0 のカーネルは Microsoft が公開した完成品を使います)。IBM PC 用の `BASIC.COM` は動きません。MS-DOS は 8088 を載せた 20K の実機とシミュレータで動きます (9K にはありません)。
* 実機の待ちのモデルは**入れてあります** (`-hw`、既定。PSRAM の応答待ちと、6809 と Z80 が PSRAM を取り合うときの待ち。`-nohw` で理想の機械。docs/DESIGN.md の 17 章)。ただし精度は最大 2.7% 差 (`duo` の実機との比較) で、命令の中のバスサイクルの順序や割り込みの入り方などは近似です。8088 は 20K の実機でも動かして確かめました (CP/M-86、MS-DOS)。ただしクロック数はプリフェッチキューを作っていないので近似で、命令の基準は Intel の資料です。
* 8086 の外部テストスイートでの検証、サブ CPU の逆アセンブル付きトレース。
