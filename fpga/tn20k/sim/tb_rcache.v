// SPDX-License-Identifier: MIT
// tb_rcache.v - rcache.v against a model: random fills, updates, invalidations and lookups (the lookup address is held for several clocks, as the SoC does).
// The model: for each line the word and a valid flag; a lookup hits when the line is valid and the tag (the address bits above the index) is the same.
`timescale 1ns/1ps
module tb_rcache;
    reg clk = 0, rst = 1;
    always #5 clk = ~clk;
    localparam IDX = 6;                          // a small cache (64 lines) so that the lines collide
    reg [21:0] a = 0;
    wire hit; wire [7:0] hbyte;
    reg fill_we = 0, upd_we = 0, inv_we = 0;
    reg [19:0] fill_a = 0, inv_a = 0;
    reg [31:0] fill_d = 0;
    reg [7:0]  upd_d = 0;
    rcache #(.IDX(IDX)) dut (.clk(clk), .rst(rst), .a(a), .hit(hit), .hbyte(hbyte), .fill_we(fill_we), .fill_a(fill_a), .fill_d(fill_d),
                            .upd_we(upd_we), .upd_d(upd_d), .inv_we(inv_we), .inv_a(inv_a));
    reg [31:0] m_d [0:(1<<IDX)-1];
    reg [19:0] m_t [0:(1<<IDX)-1];               // the word address of the line (index and tag)
    reg        m_v [0:(1<<IDX)-1];
    integer i, n, fails = 0, checks = 0, hits = 0, k;
    reg [19:0] wa;
    reg [21:0] la;
    reg [7:0]  e;
    reg        eh;

    task fill(input [19:0] w, input [31:0] d);
        begin @(posedge clk); fill_a <= w; fill_d <= d; fill_we <= 1; @(posedge clk); fill_we <= 0;
              m_d[w[IDX-1:0]] = d; m_t[w[IDX-1:0]] = w; m_v[w[IDX-1:0]] = 1; end
    endtask
    task inval(input [19:0] w);                  // the line of the index of w becomes invalid, whatever its tag
        begin @(posedge clk); inv_a <= w; inv_we <= 1; @(posedge clk); inv_we <= 0; m_v[w[IDX-1:0]] = 0; end
    endtask
    task update(input [21:0] ad, input [7:0] d);   // the lookup address is the address of the write
        begin
            a <= ad; repeat (4) @(posedge clk);
            upd_d <= d; upd_we <= 1; @(posedge clk); upd_we <= 0;
            if (m_v[ad[IDX+1:2]] && m_t[ad[IDX+1:2]] == ad[21:2]) m_d[ad[IDX+1:2]][8 * ad[1:0] +: 8] = d;
        end
    endtask
    task look(input [21:0] ad);
        begin
            a <= ad; repeat (4) @(posedge clk);
            eh = m_v[ad[IDX+1:2]] && m_t[ad[IDX+1:2]] == ad[21:2];
            e  = m_d[ad[IDX+1:2]][8 * ad[1:0] +: 8];
            checks = checks + 1;
            if (hit !== eh) begin fails = fails + 1; if (fails < 10) $display("FAIL hit %06X got %b want %b", ad, hit, eh); end
            else if (eh) begin
                hits = hits + 1;
                if (hbyte !== e) begin fails = fails + 1; if (fails < 10) $display("FAIL byte %06X got %02X want %02X", ad, hbyte, e); end
            end
        end
    endtask

    initial begin
        for (i = 0; i < (1<<IDX); i = i + 1) begin m_d[i] = 0; m_t[i] = 0; m_v[i] = 0; end
        repeat (4) @(posedge clk); rst = 0; repeat (4) @(posedge clk);
        for (n = 0; n < 60000; n = n + 1) begin
            wa = (($urandom % 4) << IDX) | ($urandom % (1<<IDX));      // 4 tags per index: lines collide
            la = {wa, 2'b00} | ($urandom % 4);
            case ($urandom % 8)
            0: fill(wa, $urandom);
            1: fill(wa, $urandom);
            2: inval(wa);
            3: update(la, $urandom);
            default: look(la);
            endcase
            if (n % 50 == 0) begin                  // a fill and an invalidation in the same clock (the fill goes first, the invalidation is applied after it)
                @(posedge clk); fill_a <= wa; fill_d <= 32'hdeadbeef; fill_we <= 1; inv_a <= wa ^ (1 << 3); inv_we <= 1;
                @(posedge clk); fill_we <= 0; inv_we <= 0;
                m_d[wa[IDX-1:0]] = 32'hdeadbeef; m_t[wa[IDX-1:0]] = wa; m_v[wa[IDX-1:0]] = 1;
                m_v[(wa ^ (1 << 3)) & ((1<<IDX)-1)] = 0;
                repeat (3) @(posedge clk);
            end
        end
        $display("rcache: %0d lookups (%0d hits), %0d failed", checks, hits, fails);
        if (fails != 0) $fatal(1, "rcache test failed");
        $finish;
    end
endmodule
