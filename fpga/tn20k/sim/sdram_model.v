// SPDX-License-Identifier: MIT
// sdram_model.v - a behavioural model of the 64 Mbit 32 bit SDR SDRAM of the GW2AR-18 for the simulation of sdram_ctl.v.
// It runs on the SDRAM clock (O_sdram_clk) and checks the rules that the controller must keep (counted in SDRAM clock edges):
// the start-up sequence (PRECHARGE ALL, 2 x AUTO REFRESH, MODE REGISTER SET with CAS latency 2 / burst 1), tRCD >= 2, tRC >= 5 for the same bank,
// tRP >= 2 after the auto precharge, tWR >= 2 after a write, refresh at least every 1100 clocks.  Read data come CL = 2 clocks after READ and
// stay for one clock.  `errors` counts the violations.
module sdram_model #(
    parameter MAXREFRESH = 1100
) (
    input  wire        clk,
    input  wire        cke,
    input  wire        cs_n,
    input  wire        ras_n,
    input  wire        cas_n,
    input  wire        we_n,
    input  wire [3:0]  dqm,
    input  wire [10:0] a,
    input  wire [1:0]  ba,
    inout  wire [31:0] dq,
    output reg  [31:0] errors,
    output reg         init_done
);
    reg [31:0] mem [0:(1<<21)-1];            // 2 K rows x 256 columns x 4 banks x 32 bit = 8 MB
    integer i;
    initial begin
        for (i = 0; i < (1<<21); i = i + 1) mem[i] = 32'h0;
        errors = 0; init_done = 0;
    end

    wire [2:0] cmd = {ras_n, cas_n, we_n};
    localparam [2:0] C_MRS = 3'b000, C_REF = 3'b001, C_PRE = 3'b010, C_ACT = 3'b011, C_WR = 3'b100, C_RD = 3'b101;

    integer now = 0;
    integer act_t [0:3];
    reg     open_row [0:3];
    reg [10:0] row_q [0:3];
    integer pre_t [0:3];                      // when the (auto) precharge of the bank began
    integer wr_t [0:3];                       // the last write to the bank
    integer last_ref = 0;
    integer nref = 0;
    reg     mrs_ok = 0;
    reg     pre_seen = 0;
    initial for (i = 0; i < 4; i = i + 1) begin act_t[i] = -100; open_row[i] = 0; pre_t[i] = -100; wr_t[i] = -100; row_q[i] = 0; end

    // read pipeline: data appear CL = 2 clocks after the READ and last one clock
    reg [31:0] rd_p1, rd_p2;
    reg        rv1, rv2;
    reg [31:0] dq_o;
    reg        dq_oe;
    assign dq = dq_oe ? dq_o : 32'bz;

    wire [20:0] caddr = {ba, row_q[ba], 8'b0};

    task err(input [255:0] msg);
        begin errors = errors + 1; $display("SDRAM MODEL ERROR @%0d: %0s", now, msg); end
    endtask

    always @(posedge clk) begin
        now = now + 1;
        dq_oe <= 1'b0;
        rv2 <= rv1; rd_p2 <= rd_p1;
        rv1 <= 1'b0;
        if (rv2) begin dq_o <= rd_p2; dq_oe <= 1'b1; end
        if (init_done && (now - last_ref) > MAXREFRESH) begin err("refresh interval"); last_ref = now; end
        if (cke && !cs_n) begin
            case (cmd)
            C_PRE: begin
                pre_seen = 1;
                if (a[10]) for (i = 0; i < 4; i = i + 1) begin open_row[i] = 0; pre_t[i] = now; end
                else begin open_row[ba] = 0; pre_t[ba] = now; end
            end
            C_REF: begin
                for (i = 0; i < 4; i = i + 1) if (open_row[i]) err("REFRESH with an open bank");
                if (now - last_ref < 5 && nref > 0) err("tRC between refreshes");
                nref = nref + 1; last_ref = now;
                if (!pre_seen) err("REFRESH before PRECHARGE");
            end
            C_MRS: begin
                if (a[6:4] != 3'd2 || a[2:0] != 3'd0) err("mode register is not CL2 / BL1");
                mrs_ok = 1;
                if (nref < 2) err("MODE REGISTER SET before two refreshes");
                init_done = 1; last_ref = now;
            end
            C_ACT: begin
                if (!init_done) err("ACTIVE before the start-up sequence is done");
                if (open_row[ba]) err("ACTIVE on an open bank");
                if (now - pre_t[ba] < 2) err("tRP");
                if (now - act_t[ba] < 5) err("tRC");
                act_t[ba] = now; open_row[ba] = 1; row_q[ba] = a;
            end
            C_RD: begin
                if (!open_row[ba]) err("READ on a closed bank");
                if (now - act_t[ba] < 2) err("tRCD (read)");
                if (!a[10]) err("READ without auto precharge");
                rd_p1 <= mem[{ba, row_q[ba], a[7:0]}]; rv1 <= 1'b1;
                open_row[ba] = 0; pre_t[ba] = now + 1;
            end
            C_WR: begin
                if (!open_row[ba]) err("WRITE on a closed bank");
                if (now - act_t[ba] < 2) err("tRCD (write)");
                if (!a[10]) err("WRITE without auto precharge");
                begin : wr
                    reg [31:0] old;
                    old = mem[{ba, row_q[ba], a[7:0]}];
                    if (!dqm[0]) old[7:0]   = dq[7:0];
                    if (!dqm[1]) old[15:8]  = dq[15:8];
                    if (!dqm[2]) old[23:16] = dq[23:16];
                    if (!dqm[3]) old[31:24] = dq[31:24];
                    mem[{ba, row_q[ba], a[7:0]}] = old;
                end
                open_row[ba] = 0; pre_t[ba] = now + 3;     // data in this clock, tWR 2 clocks, then the precharge
            end
            default: ;
            endcase
        end
    end
endmodule
