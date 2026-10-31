# クレジット

各ソースの先頭にも、参考にしたものを書いています。

## ベース: sim09 (new-sbc09、MIT)

`/export/nas/archives/MC6809/new-sbc09/src/` の MC6809 シミュレータを**複製して拡張**しました (元のディレクトリは参照と複製だけで、変更していません)。

* 無変更で複製: `m6809.c` `m6809.h` `dis6809.c` `console.c` `console.h` `net.c` `net.h` `dbg.c` `dbg.h` `os9names.h`
* 変更して複製: `machine.c` `machine.h` `main.c` (変更点は `docs/DESIGN.md` の 5 章)、`vdisk.c` (VRBF ファイルのリダイレクトと close。13.3 章)

sim09 自身が参考にしたもの (sim09 の `CREDITS.md` より。これらのコードはここにも sim09 経由で入っていませんが、考え方・仕様・互換性の出典です):

* **sbc09** (Lennart Benschop, Jens Diemer, Johann E. Klasek ほか / GPL v2) <https://github.com/cmarrin/6809/tree/main/sbc09>:
  `v09s.c` を MC6809 の命令仕様の基準にしています。
* **Shinji Kono の sbc09** (OS-9 対応版 / GPL v2) <https://github.com/shinji-kono/sbc09>: メモリマップ、MMU、I/O レジスタ、ディスクコマンド、
  VRBF の規約 (`engine.c` `io.c` `v09.c` `vdisk.c` `trace.c`)。`os9/` のディスクイメージと ROM はこのプロジェクト由来で、**このリポジトリには
  複製していません** (テストが `new-sbc09/os9/` を読み取り専用で使います)。
* **MAME `m6809.cpp`** (Nathan Woods, Tim Lindner ほか / BSD-3-Clause): クロック・サイクル・CPU 状態の考え方 (コードは使っていません)。
* **NitrOS-9 プロジェクト** (GPL v2) <https://github.com/nitros9project/nitros9>: OS-9 のシステムコールの定義。`os9/xrun.asm` と `os9/xlink/` は
  `new-sbc09/os9/nitros9-code/defs/` の定義ファイルを `a09 -I` で**読むだけ**で、複製していません。

## このプロジェクトで書いたもの (MIT)

| ファイル | 参考にしたもの |
|---|---|
| `src/z80.c` | Zilog "Z80 CPU User Manual" (UM0080) の命令・フラグ・T ステート。Sean Young "The Undocumented Z80 Documented" (X/Y フラグ、IXH/IXL、`DD CB` のコピー、`SLL`、ブロック I/O のフラグ、MEMPTR)。Cristian Dinu "Decoding Z80 opcodes" の x/y/z/p/q によるデコード。他の Z80 エミュレータのコードは使っていません |
| `src/i8088.c` | Intel "MCS-86 / iAPX 86,88 User's Manual" の命令・フラグ・EA とクロック数・割り込みの手順・リセット状態。8086 の未定義の動き (`60-6F` など) の知識。他の x86 エミュレータのコードは使っていません |
| `src/memtest.c` | 実機 (new-sbc09 の `fpga/tn9k/rtl/sbc09_soc.v` の `MEMTEST`、起動時に RTL が行う 2MB のメモリ検査) の手順と表示 (`Memory >>>> OK 2048K` / `NG @アドレス`)。コードは新しく書きました |
| `src/xlink.c` `xlink.h` `subcpu.h` | **FM-11 マンハッタンシステム** (富士通) の考え方 (異種 CPU がメインメモリを共有する)。資料やコードは見ていません。レジスタの構成は新しく設計しました。スケジューリングは sim09 の `machine_run` (MAME のデバイススケジューラに倣ったもの) に倣っています |
| `os9/cpm/cpm.asm` `z80shim.asm` `i8088shim.asm` `tests/cpm/*` | **Digital Research の CP/M 2.2 と CP/M-86 の公開仕様**: BDOS の関数番号、FCB の配置、結果の返し方、ゼロページ/ベースページ、`.CMD` のヘッダ (グループ記述子)。CP/M の実物のコード (CCP、BDOS、BIOS) は見ていません。OS-9 のコマンドの形式は `xrun` と同じ |
| `os9/xlink/xlink.asm` `x0.asm` | NitrOS-9 のドライバの形 (sim09 の `level1/pty.asm` と `level2/pty-dd.asm`、ジョイスティックのドライバの IRQ パケット)、カーネルの `F$AlHRAM` `F$DelRAM` の仕様。コードは新しく書きました |
| `os9/cpp/cpp.asm` | ANSI C (X3.159) と K&R のプリプロセッサの規則。他のプリプロセッサのコードは使っていません |
| `os9/cc80/cc80.asm` | HI-TECH C 3.09 (CP/M-80) のパスの順序と引数。`github.com/agn453/HI-TECH-Z80-C` の `OPTIONS` と、元のドライバ `C309.COM` が作る `$$EXEC.$$$` の内容を見て決めました。そのコードは使っていません |
| `tools/z80asm.py` | Zilog の Z80 マニュアルの機械語。他のアセンブラのコードは使っていません |
| `tools/mkcmd.py` | CP/M-86 System Guide の `.CMD` ヘッダ |
| `os9/xrun.asm` | モジュールの形式 (`mod`/`emod`、`os9` 呼び出し) は sim09 の `os9/misc/shutdown.asm` と NitrOS-9 のコマンドの書き方に従っています。コードは新しく書きました |
| `tests/` | テストはすべて新しく書きました。期待値は上の資料から手で計算したものです |

## FPGA の測定にだけ使ったもの (リポジトリには入れていません)

* **TV80** (Guy Hutchison、VHDL の T80 (Daniel Wallner) が元 / MIT) <https://github.com/hutch31/tv80> の `rtl/core/` の 5 ファイル: LUT 数の測定と `fpga/rtl/z80_soc.v` の Verilator テストに一時ディレクトリへ取得して使うだけで、このリポジトリには入れていません (`make -C fpga/sim soc TV80=ディレクトリ`)。

* **ZEXDOC / ZEXALL** (Frank D. Cringle、Yaze 付属 / GPL v2、Ian Bartholomew 改) : `src/z80.c` の検証 (ZEXDOC 67 項目)。取得したのは一時ディレクトリで、リポジトリには入れていません。
* **HI-TECH C 3.09 (Z80 CP/M)** (HI-TECH Software; 無償利用の許諾、Tony Nicholson の `agn453/HI-TECH-Z80-C`): `cc80` の検証。`MATENRO_HTC` で指すだけで、リポジトリには入れていません。

## sim09 の FPGA (new-sbc09/fpga/tn9k、MIT) から複製して変えたもの

`fpga/tn9k/rtl/matenro_soc.v` (`sbc09_soc.v` に XLINK と Z80 を足した)、`psram_arb4.v` (`psram_arb.v` に 4 番目のマスタを足した)、`tn9k_top.v` (SoC の名前と `MEMTEST` の指定だけ)、`fpga/tn9k/sim/sim_top.v` (SoC の名前だけ)。いずれも冒頭に「sim09 contributors の MIT」と変更点を書いてあります。それ以外 (UART、タイマ、SD ディスク、PSRAM コントローラ (Feng Zhou)、6809 コア (Greg Miller、BSD-3-Clause)、PLL、ピンとタイミングの制約、テストベンチ `tb.cpp`、PSRAM のモデル) は複製せずに `new-sbc09` を読んで使います。

## ツール (使うだけ、複製していません)

* `a09` (sbc09 プロジェクトの 6809 アセンブラ、GPL v2): `new-sbc09/tools/a09` をテストと `xrun` のビルドで**実行するだけ**です (`A09=` で場所を変えられます)。
* `nasm` (BSD-2-Clause): 8088 のテストプログラムのアセンブル。
