// SPDX-License-Identifier: MIT
// Copyright (c) 2026 sim09 contributors
//
// (dbg_uart.v of sim09 with the state of the Z80 of Matenro added at the end of the line: the address of the last instruction
// fetch, the address bus and the flags.)  A debugging aid for the real board: with DEBUG_TX defined (build.sh DEBUG=1) the UART pin carries, instead of the console,
// a line every 31 ms with the state of the machine:   PPPP SSSS AA BB XXXX YYYY UUUU CC DD xxxx
//   (then: pppp = the Z80's last M1 address, aaaa = its address bus, ff = flags: 80 stalled, 40 halted, 20 mem_req, 10 mem_wr, 08 M1, 04 MREQ, 02 RD, 01 WR)
//   P = program counter, S = stack pointer, A, B, X, Y, U, CC, DP = the CPU registers, x = status bits of the system.

module dbg_uart_z #(
    parameter BAUD_DIV = 586
) (
    input  wire         clk,
    input  wire [111:0] regs,               // as the CPU's RegData: A B X Y S U CC DP PC
    input  wire [15:0]  status,
    input  wire [39:0]  zdbg,               // the Z80: last instruction fetch address, address bus, flags
    output reg          txd
);
    // the line: 4+1+4+1+2+1+2+1+4+1+4+1+4+1+2+1+2+1+4 = 40 characters + CR LF
    function [7:0] hexc;
        input [3:0] n;
        hexc = (n < 4'd10) ? 8'h30 + n : 8'h41 + n - 4'd10;
    endfunction

    reg [24:0] tmr = 0;
    reg [111:0] r;
    reg [15:0]  st;
    reg [39:0]  zr;
    reg [5:0]  idx = 6'd63;
    reg [9:0]  sh = 10'h3ff;
    reg [3:0]  bit_n = 0;
    reg [9:0]  div = 0;
    reg        busy = 0;
    reg [7:0]  ch;
    reg [7:0]  ch_q;                         // ch, one clock late (the character multiplexer is a long path)
    reg        wt = 1'b0;                    // wait one clock after idx has changed

    always @(*) begin
        case (idx)
            6'd0:  ch = hexc(r[111:108]);  6'd1:  ch = hexc(r[107:104]);  6'd2:  ch = hexc(r[103:100]);  6'd3:  ch = hexc(r[99:96]);
            6'd4:  ch = " ";
            6'd5:  ch = hexc(r[63:60]);    6'd6:  ch = hexc(r[59:56]);    6'd7:  ch = hexc(r[55:52]);    6'd8:  ch = hexc(r[51:48]);
            6'd9:  ch = " ";
            6'd10: ch = hexc(r[7:4]);      6'd11: ch = hexc(r[3:0]);
            6'd12: ch = " ";
            6'd13: ch = hexc(r[15:12]);    6'd14: ch = hexc(r[11:8]);
            6'd15: ch = " ";
            6'd16: ch = hexc(r[31:28]);    6'd17: ch = hexc(r[27:24]);    6'd18: ch = hexc(r[23:20]);    6'd19: ch = hexc(r[19:16]);
            6'd20: ch = " ";
            6'd21: ch = hexc(r[47:44]);    6'd22: ch = hexc(r[43:40]);    6'd23: ch = hexc(r[39:36]);    6'd24: ch = hexc(r[35:32]);
            6'd25: ch = " ";
            6'd26: ch = hexc(r[79:76]);    6'd27: ch = hexc(r[75:72]);    6'd28: ch = hexc(r[71:68]);    6'd29: ch = hexc(r[67:64]);
            6'd30: ch = " ";
            6'd31: ch = hexc(r[87:84]);    6'd32: ch = hexc(r[83:80]);
            6'd33: ch = " ";
            6'd34: ch = hexc(r[95:92]);    6'd35: ch = hexc(r[91:88]);
            6'd36: ch = " ";
            6'd37: ch = hexc(st[15:12]);   6'd38: ch = hexc(st[11:8]);    6'd39: ch = hexc(st[7:4]);     6'd40: ch = hexc(st[3:0]);
            6'd41: ch = " ";
            6'd42: ch = hexc(zr[39:36]);   6'd43: ch = hexc(zr[35:32]);   6'd44: ch = hexc(zr[31:28]);   6'd45: ch = hexc(zr[27:24]);
            6'd46: ch = " ";
            6'd47: ch = hexc(zr[23:20]);   6'd48: ch = hexc(zr[19:16]);   6'd49: ch = hexc(zr[15:12]);   6'd50: ch = hexc(zr[11:8]);
            6'd51: ch = " ";
            6'd52: ch = hexc(zr[7:4]);     6'd53: ch = hexc(zr[3:0]);
            6'd54: ch = 8'h0d;
            default: ch = 8'h0a;
        endcase
    end

    always @(posedge clk) begin
        tmr <= tmr + 1'b1;
        ch_q <= ch;
        if (!busy) begin
            txd <= 1'b1;
            if (idx == 6'd63) begin
                if (tmr == 25'd0) begin r <= regs; st <= status; zr <= zdbg; idx <= 6'd0; wt <= 1'b1; end
            end else if (wt) begin
                wt <= 1'b0;
            end else begin
                txd <= 1'b0;                                  // the start bit
                sh <= {1'b1, 1'b1, ch_q};                       // the data bits, then the stop bit
                bit_n <= 4'd0; div <= 10'd0; busy <= 1'b1;
                idx <= (idx == 6'd55) ? 6'd63 : idx + 1'b1;
            end
        end else if (div == BAUD_DIV - 1) begin
            div <= 10'd0;
            if (bit_n == 4'd9) busy <= 1'b0;
            else begin txd <= sh[0]; sh <= {1'b1, sh[9:1]}; bit_n <= bit_n + 1'b1; end
        end else div <= div + 1'b1;
    end
endmodule
