# 摩天楼 (Matenro) ユーザーマニュアル

摩天楼は、**MC6809 で OS-9 Level 2 を動かし、同じメモリに Z80 (CP/M-80) または 8088 (CP/M-86) をつないだ**マシンです。
OS-9 のコマンドから CP/M のプログラムを、そのまま動かせます。2 つの形があります。

| 形 | 内容 | サブ CPU |
|---|---|---|
| **シミュレータ** (`./matenro`) | Linux (Debian 12) で動く C のプログラム | Z80 または 8088 |
| **FPGA 版** (Tang Nano 9K) | 実機。OS-9 は SD カードから起動 | Z80 のみ |

設計の詳細は [DESIGN.md](DESIGN.md)、FPGA の詳細は [FPGA.md](FPGA.md) と [FPGA_RESOURCES.md](FPGA_RESOURCES.md)、クレジットは [../CREDITS.md](../CREDITS.md) にあります。
このマニュアルは「使う人」向けです。

---

## 1. 目次

1. [できること、できないこと](#2-できることできないこと)
2. [シミュレータを使う](#3-シミュレータを使う)
3. [FPGA 版 (Tang Nano 9K) を使う](#4-fpga-版-tang-nano-9k-を使う)
4. [OS-9 の起動のあと](#5-os-9-の起動のあと)
5. [CP/M のプログラムを動かす (`cpm`)](#6-cp-m-のプログラムを動かす-cpm)
6. [C で書く: `cpp80` と `cc80`、Turbo Pascal](#7-c-で書く-cpp80-と-cc80)
7. [`xrun` (サブ CPU に直接プログラムを渡す)](#8-xrun-サブ-cpu-に直接プログラムを渡す)
8. [SD カードのイメージを作る](#9-sd-カードのイメージを作る)
9. [FPGA のビットストリームを作る・書く](#10-fpga-のビットストリームを作る書く)
10. [困ったとき](#11-困ったとき)
11. [リファレンス](#12-リファレンス)

---

## 2. できることできないこと

**できること**

* OS-9 Level 2 のコマンドとアプリ (6809 側は sim09 と同じメモリマップ、物理 2MB、8KB × 8 ページの MMU)。
* `cpm ファイル` で、Z80 では CP/M-80 の `.COM`、8088 (シミュレータのみ) では CP/M-86 の `.CMD` を実行。コンソールとファイルは OS-9 のものを使います。
* OS-9 で作ったツールと CP/M のツールを続けて使う: C のソースを OS-9 の `cpp80` に通し、CP/M-80 の HI-TECH C でコンパイルして動かす (`cc80`)。
* パイプ・リダイレクト: `list a.txt ! cpm filter ! ...` のように、CP/M のフィルタを OS-9 のパイプにつなげます。

**できないこと (主なもの)**

* CP/M の本物の CCP・BDOS・BIOS は動きません。OS-9 が BDOS の役をします (**BDOS レベルの互換**)。BIOS は、コンソール (CONST/CONIN/CONOUT) の入口だけを用意してあります (Turbo Pascal が使います)。BIOS のディスクの入口を呼ぶプログラム、ディスクのセクタを直接読むプログラムは動きません。
* ワイルドカードの名前変更、SYS とアーカイブの属性は未対応です。ドライブ B: 以降は `-m=` で対応づけたものだけ、ユーザ番号は OS-9 のサブディレクトリです。
* 同時に動くサブ CPU は 1 つです。
* FPGA 版に載っているのは Z80 だけです (8088 は 9K の FPGA に入りません)。HDMI の画面、電池つきの時計 (RTC)、`/v0` (ホストのファイルを見せる機能) もありません。
* MS-DOS は対象外です。

詳しい制約は [DESIGN.md の 12.4](DESIGN.md) を見てください。

---

## 3. シミュレータを使う

### 3.1 用意するもの

* Linux (Debian 12 で確認)、`gcc`、`make`、`python3`。テストには `nasm` も要ります。
* [sim09](https://github.com/kaya-z/sim09) を `git clone` します (6809 のアセンブラ `tools/a09` と OS-9 のディスクイメージ `os9/` を、読み取り専用で使います)。

```sh
git clone https://github.com/kaya-z/sim09 ~/sim09
export A09=~/sim09/tools/a09
export OS9DIR=~/sim09/os9            # テスト用。FPGA のスクリプトは SIM09=~/sim09
make                                 # ./matenro ができる
make os9cmds                         # build/os9/ に cpm xrun reboot etime cpp80 cc80 (OS-9 のコマンド) ができる
```

テストは `make test` です (Z80 179 項目、8088 67 項目、統合テスト、OS-9 上の `cpm` など。`MATENRO_HTC` を設定すると HI-TECH C の試験も、`MATENRO_DOS_SRC` `MATENRO_DOS2_SRC` と `UASM` を設定すると MS-DOS の試験も走ります)。

### 3.2 すぐ試す

```sh
tools/try_cpm.sh            # Z80 (CP/M-80)
tools/try_cpm.sh 8088       # 8088 (CP/M-86)
```

OS-9 が起動するので、次のように打ちます。

```
OS9:chx /v0/cmds
OS9:chd /v0
OS9:cpm hello.com abc
Hello from CP/M-80 on the Z80
!
 ABC
```

`/v0` は、ホストの `$WORK/v0` (既定 `/tmp/matenro_try/v0`) を OS-9 に見せたディレクトリです。ここにホストで作った `.com` を置けば、OS-9 から見えます。
終了は **`Ctrl-]`** でモニタに入り、`q` です。

### 3.3 自分で起動する

```sh
./matenro -m 1M -sub z80 -rom $OS9DIR/os9v2.rom -0 OS9.dsk -1 WORK.dsk -v v0dir
```

| オプション | 意味 |
|---|---|
| `-sub z80\|8088` | サブ CPU を差し込む (Level 2 のみ) |
| `-m サイズ` | 6809 (OS-9) が使う RAM。`-m 1M` で下半分に閉じ込め、上半分がサブ CPU 用 (ドライバ `xlink` を使うなら付けない) |
| `-subclock Hz` | サブ CPU のクロック (既定: Z80 8MHz、8088 8MHz) |
| `-clock Hz` | 6809 のクロック (既定 2000000) |
| `-0 イメージ` `-1 イメージ` | ディスク `/d0` `/d1` (ディスクは書き換わるので、複製を使ってください) |
| `-v ディレクトリ` | ホストのディレクトリを `/v0` として見せる |
| `-max` | 実時間に合わせず全速で動かす |
| `-script ファイル` | `expect` / `send` / `sleep` / `quit` の行で端末を自動操作 |
| `-xt ファイル` `-xcon ファイル` | サブ CPU の命令トレース / デバッグコンソール |
| `-nomemtest` | 電源投入時のメモリ検査をしない |

全オプションは `./matenro -h` と [README.md](../README.md) にあります。

**ドライバを使う場合**: `-m` を付けずに起動し、OS-9 で `load xlink` `load x0` します。サブ CPU のメモリは OS-9 の空き RAM から借ります (FPGA 版と同じ使い方です)。

---

## 4. FPGA 版 (Tang Nano 9K) を使う

### 4.1 用意するもの

* **Tang Nano 9K** のボードと USB ケーブル (書き込みと、シリアルコンソールの両方に使います)。
* **microSD カード**と、ホストのカードリーダー。
* ホストの Linux に `openFPGALoader`。シリアルは `screen` `minicom` `picocom` など。

### 4.2 SD カードを作る

カードには、OS-9 の `/d0` (ドライブ 0) と `/d1` (ドライブ 1) をまとめたイメージを書きます。作り方は [9 章](#9-sd-カードのイメージを作る)です。

```sh
sudo dd if=fpga/tn9k/build/matenro_card.img of=/dev/sdX bs=1M conv=fsync     # sdX はカードの名前。全体が上書きされます
```

**`sdX` を間違えると、別のディスクを壊します。** `lsblk` で、カードリーダーのデバイスであることを確かめてから書いてください。

### 4.3 ビットストリームをフラッシュに書く

作ったビットストリーム (`matenro_boot.fs`、作り方は [10 章](#10-fpga-のビットストリームを作る書く)) を、ボードのフラッシュに書くと、電源を入れるたびに自動で読み込まれます。

```sh
openFPGALoader -b tangnano9k -f fpga/tn9k/build/boot/impl/pnr/matenro_boot.fs     # フラッシュ (電源を切っても残る)
openFPGALoader -b tangnano9k    fpga/tn9k/build/boot/impl/pnr/matenro_boot.fs     # SRAM だけ (試すとき。電源を切ると消える)
openFPGALoader -b tangnano9k -r                                                   # ボードをリセット (フラッシュから読み直す)
```

### 4.4 つなぐ

シリアルコンソールは **115200 bps、8N1、フロー制御なし**です。ボードの USB は 2 つのシリアルとして見え、Linux では `/dev/ttyUSB1` が JTAG、**`/dev/ttyUSB2` がコンソール**でした (番号は環境で変わります。`dmesg` で確認してください)。

```sh
picocom -b 115200 /dev/ttyUSB2
```

### 4.5 起動

電源を入れる (またはリセットする) と、次のように出ます。

```
Matenro Memory >>>>>>>>>>>>>>>>>>>>>>>> OK 2048K        ← PSRAM の検査 (約 4.5 秒)
NitrOS-9/6809 Level 2 V1.0.1
Tang Nano 9K
(C) 2014 The NitrOS-9 Project
http://www.nitros9.org
Shell
OS9:
```

メモリ検査で食い違いが見つかると、`NG @アドレス` と出ます (そのまま起動は続けます)。起動から `OS9:` まで、全部で約 5 秒です。

クロックは、システムが 67.5MHz、**6809 が 1.875MHz、Z80 が 7.5MHz** です。

**LED と S2 ボタン**: ボードの LED は 2 通りの表示を、ボタン **S2**（S1 はリセット）を押すたびに切り替えます。

| 表示 | LED0 | LED1 | LED2 | LED3 | LED4 | LED5 |
|---|---|---|---|---|---|---|
| **A**（起動時、リセットのあと） | 心拍（点滅） | 動作中 (PSRAM の準備と消去が済んだ) | カードの準備ができた (失敗は点滅) | カードのアクセス中 | OS が起動した | 電源オフ |
| **B**（S2 を押す） | **サブ CPU (Z80) が有効** (リセットが外れていて、止められていない: `cpm` を動かしている間) | 消灯 (予約) | 消灯 | 消灯 | 消灯 | 消灯 |

リセット (S1)、`reboot`、電源投入では表示 A に戻ります。LED の割り当ては `fpga/tn9k/rtl/tn9k_top.v` の先頭にも書いてあります。

---

## 5. OS-9 の起動のあと

FPGA 版 (またはドライバを使うシミュレータ) では、最初に次の 3 行を打ちます。

```
OS9:chx /d0/cmds        コマンドの場所を /d0/cmds にする
OS9:load xlink          サブ CPU を扱うドライバ (Z80 のメモリを OS-9 の空き RAM から借ります: Z80 は 64KB、8088 は 256KB)
OS9:load x0             ドライバのデスクリプタ
OS9:chd /d1             カレントのデータディレクトリを /d1 に (HI-TECH C や ZEXDOC を置いた場所)
```

* `/d0` は OS-9 のシステムディスク (1MB、4096 セクタ、2 セクタ/クラスタ) で、`cmds` に `cpm` `xrun` `reboot` `etime` `duo` `cpp80` `cc80` と、sim09 のコマンド (`dir` `copy` `attr` `mdir` `mfree` など) があります。`/d0/hello.com` も入っています。
* `/d1` は 2 つ目のディスク (512KB。64MB にもできる: 9 章) で、HI-TECH C、ZEXDOC などを置きます ([9 章](#9-sd-カードのイメージを作る))。
* `reboot` は機械を再起動します (電源を入れ直したのと同じ。FPGA 版は S1 を押したのと同じで、メモリ検査から SD からの読み込みまでやり直すので約 5 秒かかります。ディスクの内容はそのまま。開いたまま書いていないファイルの内容は失われます)。
  シミュレータでは、RAM を消して ROM イメージを読み直します。
* `Error #216` は「ファイルまたはコマンドが見つからない」です。`chx` が合っているか、ファイル名を確かめてください。

---

## 6. CP/M のプログラムを動かす (`cpm`)

```
cpm [-b] [-d] [-k] [-p=ディレクトリ] [-m=ドライブ:ディレクトリ] ファイル [引数...]
```

| オプション | 意味 |
|---|---|
| (なし) | `ファイル` を探して開く。拡張子がなければ `.COM` (8088 は `.CMD`) を付けて探す |
| `-p=dir` | ファイルが現在のディレクトリになければ、`dir` も探す (読み出しだけ)。プログラム自身もここから探す。HI-TECH C の `crtcpm.obj` `libc.lib` を置いた場所を指すのに使う |
| `-m=B:/d1` | CP/M のドライブ B: を OS-9 のディレクトリ `/d1` に対応づける (A:〜P: のうち 4 つまで。何度でも書ける)。A: は何も書かなければカレントのデータディレクトリです |
| `-k` | コマンドテール (引数) を**大文字にしない** (CP/M の CCP は大文字にしますが、HI-TECH C は大文字小文字を区別します) |
| `-b` | 拡張子での判定をやめ、すべてのファイルをバイナリとして扱う |
| `-d` | BDOS の呼び出しと、開けなかったファイルの OS-9 のエラー番号を表示 |

### 6.1 例

```
OS9:cpm /d0/hello.com abc
Hello from CP/M-80 on the Z80
!
 ABC
```

`hello.com` は、コマンドテール (`0080h`) の引数を表示するテスト用のプログラムです。`abc` は CP/M の流儀で大文字 (`ABC`) になって渡ります (`-k` を付けると小文字のままです)。

### 6.2 ファイル

* ファイルは **OS-9 のカレントデータディレクトリ**のファイルそのものです (`chd` で変えられます)。CP/M のドライブ文字は無視されます。ファイル名は 8.3 で、大文字小文字は区別されません (作ったファイルの名前は大文字になります)。
* **テキストファイルは自動で変換されます**: 拡張子が `.C` `.H` `.I` `.AS` `.ASM` `.TXT` などのファイルは、OS-9 の行末 (CR) と CP/M の行末 (CR LF) とファイル末尾の `^Z` を相互に変換します。それ以外 (`.COM` `.OBJ` `.LIB` `.DAT` など) はバイナリのままです。`-b` で全部バイナリ扱いにできます。
* 128 バイトのレコード単位で読み書きします。
* プログラムが閉じずに終わったファイルは、終了時に閉じます。同じ名前のファイルを複数回開いても、OS-9 のパスは 1 つだけ使います (OS-9 のシステムメモリを節約するためです)。

### 6.3 コンソールとパイプ

* 標準入力・標準出力・標準エラーは、OS-9 のものです。
* `STDIN` `STDOUT` `STDERR` という名前のファイルは、OS-9 の標準入出力に結び付きます。CP/M のフィルタをパイプにつなげられます。

```
OS9:list a.txt ! cpm tcat                 tests/cpm/tcat.asm: STDIN を読んで STDOUT へ写す (OUT.TXT にも書く) CP/M-80 のフィルタ
```

* キーの有無を調べる BDOS (6 と 11) は、標準入力が**ファイルのとき**は「キーなし」を返します (手順ファイルを読み捨てないためです)。キーボードとパイプは通常どおりです。

### 6.4 止める

* プログラムは、BDOS 0 か `RET` (Z80) / `RETF` (8088) で終わります。
* `Ctrl-C` は `cpm` の待ち中には効きません (この OS-9 は、プロセスが端末を読むときにしか入力を見ません)。止まったときは、シミュレータなら `Ctrl-]` でモニタに入って `q`、FPGA 版ならボードのリセット (`openFPGALoader -b tangnano9k -r`) です。

### 6.4a 動作を確認した CP/M のプログラム

次の実物のプログラムを、**無変更で**動かしました (どれもこのリポジトリには入っていません。自分で用意してください)。

| プログラム | 確認したこと |
|---|---|
| `STAT` | ドライブと空き容量 (`A: R/W, Space: 3968k`)、ファイルの一覧 (`stat *.*`、`stat b:*.*`) |
| `ASM` + `LOAD` | 8080 のソースをアセンブルし (`asm hi`)、`.HEX` から `.COM` を作って (`load hi`)、動かす |
| `PIP` | ファイルのコピー、ワイルドカード (`pip b:=*.asm`)、コンソールへ (`pip con:=file`) |
| `ED` | 新しいファイルを作って保存し、開き直して編集する (`.BAK` ができる) |
| `DDT` | プログラムを読み込み、ダンプ・逆アセンブル・実行する |
| `MBASIC` 5.21 | 計算、プログラムの実行、`SAVE`/`LOAD` (トークン形式と ASCII)、`FILES`、ファイルの入出力 (`OPEN`/`PRINT#`/`INPUT#`)、`SYSTEM` |
| Turbo Pascal 3.0 | 7.3 節 |
| HI-TECH C 3.09 | 7.2 節 (`cc80`) |
| ZEXDOC | Z80 の命令試験 |

SD カードのイメージに入れるには、`CPM=<ディレクトリ>` を付けて `mkdisk.sh` を動かします (`/d0/cpm` に入ります)。使うときは次のようにします。

```
OS9:chd /d1
OS9:cpm -p=/d0/cpm stat.com
OS9:cpm -p=/d0/cpm mbasic.com
```

* ドライブ B: 以降は `-m=B:/d1/b` で OS-9 のディレクトリに対応づけます (`cpm -m=B:/d1/b -p=/d0/cpm pip.com b:=*.asm`)。ユーザ番号は、ドライブの下のサブディレクトリ `U1`〜`U15` です。
* MBASIC の `SAVE "X.BAS"` が書くトークン形式のファイルは、**そのまま (バイナリで)** 扱います。`.BAS` で先頭が FFh でない既存のファイルは、ASCII のテキストとして変換します。`SAVE "X.BAS",A` で**新しく**作った ASCII のファイルは、変換されません (CP/M の行末 CR LF と ^Z のまま)。
* 動かなかった/試していないもの: `SUBMIT` と `XSUB` (CCP の仕組みが要る)、`SYSGEN` `MOVCPM` `DSKMAINT` (BIOS のディスクの入口を直接使う)、WordStar。`^C` での中断はできません (この OS-9 の端末は割り込みとして扱いません)。

### 6.5 実行時間の目安 (FPGA 版)

| 内容 | 時間 |
|---|---|
| `cpm hello.com` | 一瞬 |
| `cc80 -r hello.c` (HI-TECH C で 4 パス + リンク + 実行) | 約 81 秒 |
| ZEXDOC (Z80 の命令 67 項目) | 約 3 時間 4 分 (7.5MHz) |

シミュレータは全速で動かすと、同じ作業が数秒〜数十秒です。

### 6.6 時間を測る (`etime`)

`etime コマンド [引数…]` は、コマンドを動かして、かかった時間を出します。`-c` を付けると、サブ CPU (Z80) が実行したクロック数も出します。

```
OS9:etime -c cpm hello.com abc
Hello from CP/M-80 on the Z80
!
 ABC
Elapsed 0.142267 s
Sub CPU 230358 clocks (28 ms at 8000 kHz)
```

* 時間は、XLINK のマイクロ秒カウンタから読みます (OS-9 の時計は秒しか数えません)。FPGA 版はシステムクロックの実時間、シミュレータは 6809 の時間 (機械の時間) です。**71 分で一周します**。
* `-c` のクロック数は 32 ビットなので、7.5MHz では約 9.5 分で一周します。ミリ秒は クロック数 ÷ kHz です。
* シェルの組み込みコマンド (`chd` など) は測れません。`etime shell <手順ファイル` のように使います。終了ステータスはコマンドのものです。

---

### 6.7 二つの CPU で描く (`duo`)

```
duo [-1] [-z] [-n]
```

マンデルブロ集合の絵 (25 行 × 79 桁) を 6809 と Z80 が同時に計算して描くデモです。共通の行カウンタから行を一行ずつ取り、Z80 が idle なら次の行を渡し、Z80 が計算している間に 6809 が自分の行を計算します。Z80 のプログラム (`os9/duo/duoz80.asm`) は `duo` に組み込まれ、起動時に Z80 へ渡されます。Z80 は行の間は HALT で待ち、6809 のドアベルの割り込みで次の行を計算します。ドライバ (`load xlink`、`load x0`) があれば、6809 もドアベルの割り込みで起きます (なければ 1 tick ずつ眠ってフラグを見ます)。結果の行は共有 RAM から XLINK の窓で読み出します。両方とも固定小数点 (小数 8 ビット) なので、誰が計算した行でも絵は同じです。

絵は計算の後に書きます (Z80 の行はシアン、6809 の行は黄色)。最後に各 CPU が計算した行数と計算時間 (XLINK のマイクロ秒カウンタ) を出します。

| オプション | 意味 |
|---|---|
| `-1` | 6809 だけで計算する (比較用) |
| `-z` | Z80 だけで計算する |
| `-n` | 色を付けない |
| `-i` | `/x0` (XLINK ドライバ) が処理したドアベルの割り込みの数も出す |

シミュレータでの例: 二つの CPU で 4.1 s (6809 が 17 行、Z80 が 8 行)、`-1` で 5.6 s、`-z` で 10.6 s。Z80 にかけ算命令がないので、Z80 一つでは 6809 の約半分の速さです。

### 6.8 MS-DOS 1.25 を 8088 で動かす (`dos`、シミュレータのみ)

```
dos [-v=2 [-s=BIOS]] [-k=カーネル] -a=イメージ [-b=イメージ] [-c=イメージ] [-d=イメージ] [-p=プリンタ] [-i=補助入力] [-o=補助出力]
```

`-sub 8088` のシミュレータで、MS-DOS 1.25 (カーネルと `COMMAND`) が動きます。MS-DOS は Microsoft が公開したソース (`github.com/microsoft/MS-DOS`、MIT ライセンス) から、`tools/build_dosbin.sh` で組みます (MASM 互換のアセンブラ UASM が要ります。ソースもアセンブラもこのリポジトリには入っていません)。

```
MSDOS_SRC=.../MS-DOS/v1.25/source UASM=.../uasm tools/build_dosbin.sh dosbin      -> dosbin/msdos.sys dosbin/command.com
python3 tools/mkdosimg.py a.img 160 dosbin/command.com 他のファイル...            160 KB のディスクイメージ (320、360、8192 もある。360 は 2.0 用の 9 セクタ形式)
```

`msdos.sys` と `a.img` を OS-9 から見える場所に置き (`-v` で見せたホストのディレクトリなど)、`dos -a=a.img` を実行します。A: の `COMMAND.COM` が読まれて、日付と時刻を聞かれ (Enter でそのまま)、プロンプト `A:` が出ます。`DIR`、`TYPE`、`COPY`、`DEL` と、イメージに入れた `.COM` のプログラム (`CHKDSK` など) が使えます。キーボードは DOS がそのまま受けます (OS-9 は端末の変換を止めます)。**DOS を終わるキーは `^]` (Ctrl-]) です。**ただし `^]` はシミュレータが「モニタに入るキー」でもあり、端末で対話的に使うと DOS に届かずモニタに入ります。**`matenro` に `-e 0x1c` (モニタに入るキーを `^\` に変える) を付けて起動してください。**ディスクのイメージは OS-9 の普通のファイルで、DOS が書いた内容はそこに残ります。使えるメモリは 256 KB です。

* **日付と時刻**: `DATE` と `TIME` で変えられます。変えるのは DOS の時計だけで (OS-9 の時計とのずれを DOS が覚えます)、OS-9 の時計は変わりません。`dos` を終わると元に戻ります。
* **プリンタと補助ポート**: `-p=パス` を付けると、`PRN` (`COPY ファイル PRN` など) への出力がそのパスに追記されます。`-o=パス` は `AUX` への出力、`-i=パス` は `AUX` からの入力 (そのファイルの先頭から。終わりは `^Z`) です。パスはファイルでもデバイス (`/p` など) でもよく、ファイルがなければ作ります。付けなければ、出力は捨てて、入力はすぐ終わりになります。
* **実行ファイル**: Microsoft が公開した `bin` のうち、`EDLIN.COM` と `DEBUG.COM` が動きます (イメージに入れます)。`DEBUG` は PC DOS 用で、画面モードを `INT 10h` で問い合わせるので、BIOS がその最小の答えを返します。`BASIC.COM` は動きません (IBM PC 用の版で、起動しても何も出ません)。`FORMAT`、`DISKCOPY`、`MODE` などは試していません。

**MS-DOS 2.0** も動きます (`-v=2`)。BIOS は `tools/build_dosbin2.sh` で、カーネルと `COMMAND.COM` は公開された完成品を使います:

```
MSDOS2_SRC=.../MS-DOS/v2.0/source UASM=.../uasm tools/build_dosbin2.sh dos2bin     -> dos2bin/bios2.bin msdos.sys command.com
python3 tools/mkdosimg.py a.img 320 dos2bin/command.com 他のファイル...
dos -v=2 -a=a.img          (BIOS は bios2.bin、カーネルは msdos.sys がカレントのデータディレクトリにあること)
```

2.0 ではサブディレクトリ (`MKDIR`、`CD`)、`PRN`/`AUX`/`CON`、`EDLIN`、`DEBUG` が使えます (使い方と制限は 1.25 と同じ)。`CONFIG.SYS` はイメージに置けば `SYSINIT` が読みます (`FILES=` `BUFFERS=` など。知らない行は報告されます。`DEVICE=` でデバイスドライバも入れられます)。ディスクイメージは 160 KB、320 KB、360 KB、8 MB から起動できます。

詳しくは [DESIGN.md](DESIGN.md) の 18 章。

## 7. C で書く: `cpp80` と `cc80`

### 7.1 `cpp80` (C のプリプロセッサ)

OS-9 の 6809 のアセンブラで書いた、プリプロセッサです。

```
cpp80 [-Dname[=値]] [-Idir] [-oファイル] file.c
```

`#include` (4 段まで)、`#define` (引数あり/なし)、`#undef`、`#if` `#ifdef` `#ifndef` `#elif` `#else` `#endif`、`#error`、`#`(文字列化) と `##`(連結、関数形式マクロの中)、式 (`defined` `?:` 論理・ビット・比較・シフト・四則) に対応します。`-o` を付けなければ標準出力に出ます。

### 7.2 `cc80` (OS-9 の cpp80 → CP/M-80 の C コンパイラ)

```
cc80 [-s] [-c] [-r] [-k] [-v] [-lf] [-t=dir] [-Dname[=値]] [-Idir] file.c
```

`cpp80` で展開し (途中のファイルは、拡張子 `.i` のテキストです)、HI-TECH C 3.09 の各パス (`p1` `cgen` `zas` `linq`) を `cpm` で Z80 に動かして、`file.com` を作ります。

| オプション | 意味 |
|---|---|
| `-r` | できた `.com` をすぐ実行する |
| `-s` `-c` | `.as` / `.obj` で止める |
| `-k` | 途中のファイル (`.i` `.p1` `.as` `.obj`) を残す |
| `-v` | 実行するコマンドを表示する |
| `-lf` | 浮動小数点のライブラリ `libf.lib` をリンクする (HI-TECH C の `-LF` と同じ)。`float` の計算や `%f` の `printf` を使うときに要ります。コードの中に `float` の計算があれば (`fladd` `flmul` `aitof` などを呼んでいれば) **自動で付きます** |
| `-t=dir` | コンパイラのある場所 (既定 `/v0/htc`。FPGA 版では `-t=/d1/htc`) |
| `-D` `-I` | `cpp80` に渡す |

```
OS9:chd /d1
OS9:cc80 -t=/d1/htc -r hello.c
Hello from Hi-Tech C on CP/M
```

**HI-TECH C はこのリポジトリに入っていません。** 配布元 <https://github.com/agn453/HI-TECH-Z80-C> から自分で取得し、`P1.COM` `CGEN.COM` `ZAS.COM` `LINQ.COM` `CRTCPM.OBJ` `LIBC.LIB` `LIBF.LIB` とヘッダ (`*.H`) を、`-t` で指すディレクトリに置いてください。ライセンスは HI-TECH のものに従います。

手順ファイル (`shell <ファイル`) の中から `cc80` を続けて呼ぶこともできます。

---

### 7.3 Turbo Pascal 3.0 (CP/M-80)

Turbo Pascal 3.01A for CP/M-80 が動きます。**このリポジトリには入っていません** (ライセンス)。`TURBO.COM` `TURBO.MSG` `TURBO.OVR` (と、端末の設定に使う `TINST.COM` `TINST.DTA` `TINST.MSG`) を自分で用意してください。

**1. 端末の設定** (最初の 1 回だけ。付属の `TURBO.COM` は別の端末向けです): `TINST` で ANSI を選びます。

```
OS9:cpm tinst.com
  S                      画面の設定
  6                      端末の番号 (6 = ANSI) と Enter
  N                      定義は変更しない
  8                      CPU の周波数 (MHz。待ち時間の調整に使うだけ) と Enter
  Q                      終了 (ここで TURBO.COM に書かれます)
```

**2. 使う**: ソースのあるディレクトリで `TURBO.COM` を動かします (`TURBO.MSG` と `TURBO.OVR` は `-p=dir` で探せる場所に)。

```
OS9:chd /d1
OS9:cpm -p=/d1/tp /d1/tp/turbo.com
Include error messages (Y/N)? N
```

メニューのキーは、`W` 作業ファイル (`hello` と入力)、`E` 編集 (`^KD` で保存して抜ける)、`C` コンパイル、`R` 実行、`S` 保存 (古いファイルは `.BAK` になります)、`D` ディレクトリ、`Q` 終了、`O` コンパイラのオプションです。
オプションで `Com-file` を選んでコンパイルすると、`HELLO.COM` ができて、`cpm hello.com` で単独で動きます。

* `.PAS` と `.INC` はテキストファイルとして扱います (OS-9 の CR と CP/M の CR LF を変換します)。
* TP は端末をプログラムで直接動かすので、動いている間は端末が生入力になります (エコーなし、`^C` が効かない)。`Q` で終わると元に戻ります。
* 試験: `MATENRO_TP=<TURBO.COM のあるディレクトリ> python3 tests/matenro_test.py`。
* SD カードのイメージに入れる: `TP=<ディレクトリ>` を指定して `mkdisk_d1.sh` を動かすと、`/d1/tp` に ANSI 用に設定した TP が入り、`/d1/hello.pas` も入ります (9 章)。

---

### 7.4 OS-9 のプログラムから BDOS を呼ぶ (`bdos`)

6809 のアセンブラで書く OS-9 のプログラムは、`bdos` というサブルーチンモジュールで、CP/M の BDOS を**関数番号で**呼べます (Z80 は使いません。FCB やバッファは、プログラム自身のメモリに置きます)。使い方は `os9/bdos/bdos.d` に、動く例は `bdostest` (SD にも入っています) にあります。

```
OS9:chx /d0/cmds
OS9:load bdos
OS9:bdostest
BDOS lib: BDOS 9
!BDOS LIB OK
```

* 呼ぶ前に `load bdos` します。
* 作業領域 (`BDOSSZ` = 2500 バイト) は、呼び出し側が用意します。関数番号 `$FF` で初期化、`$FE` で終了 (開いたファイルを閉じる) を呼びます。
* 詳しくは [DESIGN.md](DESIGN.md) の 16 章です。

---

## 8. `xrun` (サブ CPU に直接プログラムを渡す)

CP/M ではなく、素のプログラムをサブ CPU に載せて走らせ、メールボックスで答えを受け取るコマンドです (主にテスト用)。

```
xrun [-l=16進アドレス] ファイル [n]
```

```
OS9:chx /v0/cmds
OS9:xrun /v0/sumz80.bin 100        Z80 に 100 を渡す → 1+2+...+100 = 5050 = $13BA
reply: BA 13 00 00
```

---

## 9. SD カードのイメージを作る

カードは、先頭にドライブ 0、**128MB の位置**にドライブ 1 を置いた生のイメージです。

| ファイル (`fpga/tn9k/build/`、git には入れない) | 内容 |
|---|---|
| `matenro_l2.dsk` (1MB、4096 セクタ) | `/d0`: OS-9 Level 2 のブート、コマンド (`cpm` `xrun` `reboot` `etime` `xlink` `x0` `cpp80` `cc80` ほか)、`hello.com` |
| `matenro_d1.dsk` (512KB、2048 セクタ) と `matenro_d1_big.dsk` (**64MB**) | `/d1`: HI-TECH C (`/d1/htc`)、`zexdoc.com` `zexall.com`、`zexdoc8.com` `zexall8.com` (8 項目目だけ)、`bstress.com` (リンクの負荷試験)、`demo.c` `mandel.c` (浮動小数点) `hello.c`、`TP=` を指定したときは Turbo Pascal (`/d1/tp`) と `hello.pas` |
| `matenro_card.img` (約 128MB)、`matenro_card_big.img` (約 192MB) | `/d0` と `/d1` を置くべき位置に置いたカード全体 (`_big` は 64MB の `/d1`) |

```sh
# /d0 (OS-9 とコマンド): sim09 のイメージに Matenro のコマンドを入れる
fpga/tn9k/scripts/mkdisk.sh fpga/tn9k/build/matenro_l2.dsk

# /d1 とカード全体: HTC と ZEX を指定して作る
HTC=<HI-TECH C のディレクトリ> ZEX=<zexdoc.com と zexall.com のディレクトリ> \
  TP=<Turbo Pascal のディレクトリ (TURBO.COM TURBO.MSG TURBO.OVR TINST.*。省いてもよい)> \
  fpga/tn9k/scripts/mkdisk_d1.sh fpga/tn9k/build/matenro_l2.dsk fpga/tn9k/build/matenro_d1.dsk fpga/tn9k/build/matenro_card.img
```

* `SIM09=<sim09 の場所>` の指定が要ります (既定は筆者の環境のパス)。
* HI-TECH C、ZEXDOC/ZEXALL、Turbo Pascal は、**このリポジトリに入っていません**。ZEXDOC は Frank D. Cringle の Z80 命令試験 (Yaze 付属、GPL v2) です。
* `/d1` (`matenro_d1.dsk`) は**2048 セクタ (512KB) で、空きは 130 セクタしかありません** (1 セクタの割り当て表の限界。`cc80 -r` は、できた `.COM` を残すので、使い終えたら `del` で消してください。満杯になると `cc80` は `cpm: a write failed (disk full)` で止まります)。`/d0` は 4096 セクタ (2 セクタ/クラスタ) で、空きは約 1900 セクタです。
* **`/d1` を 64MB のハードディスクのように使うには**、`fpga/tn9k/scripts/bigd1.sh` で、古い `/d1` のファイルをそのまま新しい大きなボリュームへ移します (`tools/mkrbf.py` が空のボリュームを作り、シミュレータが `copy` で移します。属性も同じ)。HTC や ZEX がなくてもできます:

  ```sh
  D0=fpga/tn9k/build/matenro_l2.dsk CARD=fpga/tn9k/build/matenro_card_big.img \
    fpga/tn9k/scripts/bigd1.sh fpga/tn9k/build/matenro_d1.dsk fpga/tn9k/build/matenro_d1_big.dsk
  ```

  大きさは `D1SECTORS=262144` (既定、64MB) で変えられます。割り当て表は 1 セクタに収まらなくなり (64MB で 128 セクタ)、OS-9 の RBF は複数セクタの表を扱えます (255 セクタまで)。カード全体は 128MB (ドライブ 1 の位置) + 64MB = 192MB になるので、**192MB 以上のカード**に書きます。空きは約 63MB で、`cc80` で `hello.c` `demo.c` `mandel.c` を続けて動かしても足ります。
* 大きな `/d1` の最初の割り当てが、大きなファイル (たとえば `copy /d0@ …`) だと、1 回だけ `Media Full` (エラー 248) で失敗します (次は通ります)。sim09 の元のボリュームでも同じで、小さなファイルを先に作れば出ません。
* 書き込みは [4.2](#42-sd-カードを作る) の `dd` です。
* `/d1` のファイルには `attr -s` を付けてあります。`s` 属性 (単一ユーザ) が付いていると、同じファイルを 2 回開けず、HI-TECH のリンカが `libc.lib: Can't open` で止まります。

---

## 10. FPGA のビットストリームを作る・書く

### 10.1 用意するもの

* **Gowin IDE** (`/usr/local/IDE` など。`gw_sh` を使います。ライセンスは Gowin のものに従います)。
* **TV80** (Z80 の Verilog コア、Guy Hutchison / MIT): <https://github.com/hutch31/tv80> の `rtl/core/` にある `tv80s.v` `tv80_core.v` `tv80_mcode.v` `tv80_alu.v` `tv80_reg.v`。リポジトリには入っていません。
* sim09 (`SIM09=` で場所を指定)。

### 10.2 作る

```sh
TV80=<TV80 のファイルのあるディレクトリ> SIM09=<sim09 の場所> fpga/tn9k/scripts/build.sh boot
# 結果: fpga/tn9k/build/boot/impl/pnr/matenro_boot.fs
```

| 環境変数 | 意味 |
|---|---|
| `MEMTEST=0` | 起動時のメモリ検査を入れない (既定は入れる) |
| `WDOG=1 TAG=_wd` | **診断ビルド** ([10.4](#104-診断ビルド))。出力は `build/boot_wd/` |
| `PLACE=n` | 配置の設定 (タイミングが通らないとき、別の値を試す) |
| `GOWIN_IDE=dir` | Gowin IDE の場所 |

**作ったら必ず**、`impl/pnr/matenro_boot_tr_content.html` の `Total Negative Slack Summary` が全部 0 であることを確かめてください (負の値があると、67.5MHz で正しく動かないことがあります)。配置配線の結果は、RTL を少し変えただけで変わります。`build.sh` は、制約のエラーでは「ビットストリームは新しくない」と止まります。

資源は 9K の LUT の 88%、タイミングは 67.5MHz を満たしますが、余裕は小さいです ([FPGA_RESOURCES.md](FPGA_RESOURCES.md))。

### 10.3 書く

[4.3](#43-ビットストリームをフラッシュに書く) のとおりです。まず SRAM だけに書いて動作を確かめ、よければ `-f` でフラッシュに書くのが安全です。

### 10.4 診断ビルド

ボードが無反応になったとき、何が止まっているかを調べるための版です (`WDOG=1`)。LUT が約 5% 増えるので、普段は使いません。

* 6809 が約 1 秒以上止まると、UART に 31ms ごとに状態の 1 行が出ます。
* ホストから **`0x1F` を 3 回送る**と、いつでも同じ行を出します (**`0x1E` を 3 回** で戻ります。コンソールは止まります)。

行の形式は `PPPP SSSS AA BB XXXX YYYY UUUU CC DD ssss pppp aaaa ff` (6809 の PC、S、A、B、X、Y、U、CC、DP、止めている要因、Z80 の最後の命令フェッチのアドレス、Z80 のアドレスバス、Z80 のフラグ) で、詳しくは [FPGA.md の 9.3](FPGA.md) です。

---

## 11. 困ったとき

| 症状 | 原因と対処 |
|---|---|
| `Error #216` | コマンド/ファイルが見つからない。`chx /d0/cmds`、ファイル名、`chd` を確かめる |
| `cpm: no Z80 or 8088 sub CPU` | シミュレータを `-sub z80` で起動していない、または FPGA 版で `load xlink` `load x0` をしていない |
| `libc.lib: Can't open` | ファイルに `s` 属性が付いている (`attr libc.lib -s` で外す)、または HI-TECH のファイルが `-t` のディレクトリに無い |
| `Not enough memory to run.` | OS-9 のシステムメモリが足りない。`load` したモジュールや、開いたままのパスを減らす。シェルの子プロセスを重ねすぎない |
| 起動時に何も出ない | シリアルのデバイス番号 (`/dev/ttyUSB2`) とボーレート (115200) を確かめる。ログを取るソフトは、ボードをリセットする**前に**起動しておく |
| 起動時に `NG @アドレス` | PSRAM に異常。ボードの接触や個体を疑う |
| 長い実行のあと止まる | `Ctrl-C` は効きません。診断ビルドで状態を取る ([10.4](#104-診断ビルド))、またはリセット |
| ボードの USB が見えなくなる | ケーブル、USB ポート、給電を確かめる (実機で 1 度あった)。見えなくなると、実行中のプログラムの経過が分からなくなる |

---

## 12. リファレンス

### 12.1 クロックとメモリ

| | シミュレータ | FPGA 版 |
|---|---|---|
| 6809 | 2MHz (既定) | 1.875MHz (67.5MHz ÷ 36) |
| Z80 | 8MHz (既定) | 7.5MHz (67.5MHz ÷ 9) |
| 8088 | 8MHz | なし |
| RAM | 物理 2MB を共有 | PSRAM 2MB を共有 |
| OS-9 | `-rom os9v2.rom` + ディスク | SD から起動 |

Z80 の CP/M のメモリは、`0100h` から TPA (約 63KB)、`FC00h` 以降にスタブ (BDOS = `FC06h`) です。Z80 のメモリ (64KB) は、OS-9 の空き RAM からドライバが借ります (シミュレータで `-m 1M` を使うときは、上半分の 1MB から取ります)。

### 12.2 実装している BDOS 関数

| 番号 | 内容 |
|---|---|
| 0 | システムリセット (プログラムの終了) |
| 1, 2, 6, 9, 10, 11 | コンソール入力・出力・直接入出力・文字列出力・行入力・状態 |
| 12 | バージョン (Z80: `0022h`) |
| 13, 14, 24, 25, 29 | ディスクのリセット/選択、ログインベクタ、現在のドライブ、読み出し専用ベクタ (A: と、`-m=` で対応づけたドライブ) |
| 32 | ユーザ番号 (1〜15 は、ドライブのディレクトリの下のサブディレクトリ `U1`〜`U15`) |
| 15, 16, 19, 22 | open、close、delete、make (`?` のワイルドカードの open は最初の一致、delete は全部) |
| 3, 4, 5, 7, 8, 28, 37, 40 | リーダ・パンチ・リスト、IOBYTE、書き込み禁止、ドライブのリセット、乱数書き込み |
| 30 | ファイルの属性 (読み出し専用) |
| 27, 31 | 割り当てベクタ、ディスクパラメータブロック (`STAT` 用の、4MB のディスクの値) |
| 17, 18 | 検索 (first/next、`?` のワイルドカード) |
| 20, 21, 33, 34, 35, 36 | 順次・乱数の読み書き、ファイルサイズ、乱数レコード番号の設定 |
| 26 | DMA アドレスの設定 |
| 51, 52 (CP/M-86) | DMA ベースの設定/取得 |
| 23 | 名前の変更 (新しい名前で作ってコピーし、古いファイルを消す)。新しい名前がもうあるか、古いファイルがなければ 255 |
| その他 | 何もしない (0) |

### 12.3 サブ CPU の入出力ポート (Z80 側から)

`$00`〜`$0F` が XLINK です。`$02` に何か書くと 6809 側に doorbell が鳴り、`$0E` はデバッグコンソール、`$0F` に `$A5` を書くとシミュレータが終わります (FPGA 版では電源オフではありません)。6809 側のレジスタは `$FFC9`〜`$FFCD` です。仕様の全部は [DESIGN.md](DESIGN.md) の 6 章・7 章です。

### 12.4 関連文書

| 文書 | 内容 |
|---|---|
| [../README.md](../README.md) | 概要、ビルドとテスト、主なオプション |
| [DESIGN.md](DESIGN.md) | 設計、XLINK のレジスタ、`cpm` の方式 (12 章)、`cpp80` `cc80` (13 章)、ドライバ (14 章) |
| [FPGA.md](FPGA.md) | FPGA の検討と実機の記録 (9 章)、診断ビルド (9.3)、タイミング (9.4)、メモリ検査 (9.5) |
| [FPGA_RESOURCES.md](FPGA_RESOURCES.md) | FPGA の資源とタイミングの記録 |
| [../CREDITS.md](../CREDITS.md) | 出典とライセンス |

このプロジェクトは Claude Code (Anthropic) で開発しました。
