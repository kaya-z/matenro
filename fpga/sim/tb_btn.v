// SPDX-License-Identifier: MIT
// tb_btn.v - self-checking test bench of tn9k/rtl/btn_toggle.v (run with Verilator, see the Makefile)
`timescale 1ns/1ps
module tb_btn;
    reg clk = 1'b0, rst_n = 1'b0, btn_n = 1'b1;
    wire state;
    btn_toggle #(.DEB_BITS(4)) dut (.clk(clk), .rst_n(rst_n), .btn_n(btn_n), .state(state));

    integer fails = 0, checks = 0, i;
    task check(input string what, input got, input want);
        begin
            checks = checks + 1;
            if (got !== want) begin fails = fails + 1; $display("FAIL %-50s got %0d want %0d", what, got, want); end
        end
    endtask
    task ticks(input integer n);
        integer k;
        begin for (k = 0; k < n; k = k + 1) begin clk = 1'b0; #5; clk = 1'b1; #5; end end
    endtask

    initial begin
        ticks(3); rst_n = 1'b1; ticks(3);
        check("state after the reset", state, 1'b0);
        // a bounce shorter than the debounce time does nothing
        btn_n = 1'b0; ticks(5); btn_n = 1'b1; ticks(40);
        check("a short bounce does not toggle", state, 1'b0);
        // a press with bounces: 0 1 0 1 0 ... then stable low
        for (i = 0; i < 4; i = i + 1) begin btn_n = 1'b0; ticks(6); btn_n = 1'b1; ticks(4); end
        btn_n = 1'b0; ticks(60);
        check("a press toggles (mode B)", state, 1'b1);
        ticks(100);
        check("holding the button toggles only once", state, 1'b1);
        // the release (with bounces) does not toggle
        for (i = 0; i < 4; i = i + 1) begin btn_n = 1'b1; ticks(6); btn_n = 1'b0; ticks(4); end
        btn_n = 1'b1; ticks(60);
        check("the release does not toggle", state, 1'b1);
        // the second press toggles back
        btn_n = 1'b0; ticks(60); btn_n = 1'b1; ticks(60);
        check("the second press toggles back (mode A)", state, 1'b0);
        // a press, then the reset: mode A again
        btn_n = 1'b0; ticks(60); btn_n = 1'b1; ticks(60);
        check("the third press toggles", state, 1'b1);
        rst_n = 1'b0; ticks(3); rst_n = 1'b1; ticks(3);
        check("the reset clears the state", state, 1'b0);
        $display("btn_toggle: %0d checks, %0d failed", checks, fails);
        if (fails != 0) $fatal(1, "btn_toggle test failed");
        $finish;
    end
endmodule
