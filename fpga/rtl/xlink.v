// SPDX-License-Identifier: MIT
// xlink.v - cross link of the Matenro machine (RTL of src/xlink.c)
//
// Register for register the same interface as the C simulator (docs/DESIGN.md, chapters 6 and 7):
//   * 6809 side: five registers at $FFC9-$FFCD (m_addr 0..4) = XCTL XSTAT/ACK XID/BELL XIDX XDAT
//   * sub CPU side: ports $00-$0F
//   * SMMU: 128 x 8 bit table, sub CPU address -> physical RAM address (21 bit)
//   * window: 21 bit physical address counter with a memory port (request / acknowledge)
//
// One clock domain (clk).  The CPUs' bus enables (m_re/m_we/s_re/s_we) are one-clock strobes
// that the SoC derives from its E / sub CPU clock phases.  Credits: the register layout is original;
// the structure of the strobe/stall handshake follows sim09's fpga/tn9k/rtl/sd_disk.v idea (CPU is
// stalled while the memory port works).
module xlink #(
    parameter [7:0]  SUB_ID  = 8'd1,        // 1 = Z80, 2 = 8088
    parameter [15:0] SUB_KHZ = 16'd7500
) (
    input  wire        clk,
    input  wire        rst,                  // synchronous, high
    // ---- 6809 side
    input  wire [2:0]  m_addr,               // 0..4
    input  wire        m_re,
    input  wire        m_we,
    input  wire [7:0]  m_wdata,
    output reg  [7:0]  m_rdata,
    output wire        m_wait,               // stall the 6809 (window access in progress)
    output wire        irq_n_o,              // 6809 IRQ request (active high here)
    output wire        firq_o,               // 6809 FIRQ request
    output wire        shr_o,                // XC_SHR: 6809 MMU may map the pool
    // ---- sub CPU control
    output wire        sub_rst_n,            // reset of the sub CPU (low = reset)
    output wire        sub_hold,             // freeze (bus hold)
    output wire        sub_int,              // maskable interrupt (level)
    output reg         sub_nmi,              // NMI pulse (one clock)
    input  wire        sub_halted,
    input  wire        sub_clk_en,           // one pulse per sub CPU clock (for the counter)
    // ---- sub CPU I/O ports $00-$0F
    input  wire [3:0]  s_port,
    input  wire        s_re,
    input  wire        s_we,
    input  wire [7:0]  s_wdata,
    output reg  [7:0]  s_rdata,
    output wire [7:0]  s_vec,                // interrupt acknowledge byte
    output reg         con_we,               // debug console byte
    output reg  [7:0]  con_data,
    output reg         pwr_we,               // power off request ($A5 / $A6 in pwr_data)
    output reg  [7:0]  pwr_data,
    // ---- SMMU: sub CPU memory address -> physical
    input  wire [19:0] sub_addr,
    input  wire        sub_is_z80,           // 16 bit address space (mask the upper 4 bits)
    output wire [20:0] sub_phys,
    // ---- window memory port (to the RAM arbiter)
    output reg         win_req,
    output reg         win_wr,
    output reg  [20:0] win_addr,
    output reg  [7:0]  win_wdata,
    input  wire        win_ack,
    input  wire [7:0]  win_rdata
);
    // ------------------------------------------------------------ registers
    reg        c_run, c_hold, c_shr, c_firq, c_ien;
    reg        rst_pulse;
    reg        pend_s2m, pend_m2s;
    reg [7:0]  idx;
    reg [7:0]  m2s0, m2s1, m2s2, m2s3;
    reg [7:0]  s2m0, s2m1, s2m2, s2m3;
    reg [6:0]  mi;
    reg [7:0]  svec;
    reg [31:0] clk_cnt, clk_latch;
    reg        win_busy, win_is_read;

    assign shr_o     = c_shr;
    assign sub_hold  = c_hold;
    assign sub_rst_n = c_run & ~rst_pulse;
    assign sub_int   = pend_m2s;
    assign irq_n_o   = pend_s2m & c_ien & ~c_firq;
    assign firq_o    = pend_s2m & c_ien &  c_firq;
    assign s_vec     = svec;
    assign m_wait    = win_busy;

    // ------------------------------------------------------------ SMMU (128 x 8)
    reg [7:0] smmu [0:127];
    wire [6:0] blk = sub_is_z80 ? {4'b0, sub_addr[15:13]} : sub_addr[19:13];
    assign sub_phys = {smmu[blk], sub_addr[12:0]};

    // reset values: block i -> $80 + i  (xbase = $80)
    integer k;
    initial for (k = 0; k < 128; k = k + 1) smmu[k] = 8'h80 + k[7:0];

    // ------------------------------------------------------------ extended register read
    wire [6:0] ei = idx[6:0];
    reg  [7:0] ext_rd;
    always @* begin
        ext_rd = 8'hff;
        case (ei)
            7'h00: ext_rd = m2s0;   7'h01: ext_rd = m2s1;   7'h02: ext_rd = m2s2;   7'h03: ext_rd = m2s3;
            7'h04: ext_rd = s2m0;   7'h05: ext_rd = s2m1;   7'h06: ext_rd = s2m2;   7'h07: ext_rd = s2m3;
            7'h08: ext_rd = {1'b0, mi};
            7'h09: ext_rd = smmu[mi];
            7'h0a: ext_rd = {3'b0, win_addr[20:16]};
            7'h0b: ext_rd = win_addr[15:8];
            7'h0c: ext_rd = win_addr[7:0];
            7'h0d: ext_rd = win_rdata;
            7'h0e: ext_rd = SUB_KHZ[15:8];
            7'h0f: ext_rd = SUB_KHZ[7:0];
            7'h10: ext_rd = clk_cnt[31:24];
            7'h11: ext_rd = clk_latch[23:16];
            7'h12: ext_rd = clk_latch[15:8];
            7'h13: ext_rd = clk_latch[7:0];
            default: ext_rd = 8'hff;
        endcase
    end

    always @* begin
        case (m_addr)
            3'd0:    m_rdata = {3'b0, c_ien, c_firq, c_shr, c_hold, c_run};
            3'd1:    m_rdata = {4'b0, c_run & ~c_hold, c_run & ~c_hold & sub_halted, pend_m2s, pend_s2m};
            3'd2:    m_rdata = SUB_ID;
            3'd3:    m_rdata = idx;
            3'd4:    m_rdata = ext_rd;
            default: m_rdata = 8'h00;
        endcase
    end

    wire dat_acc  = (m_re | m_we) & (m_addr == 3'd4);
    wire win_sel  = (ei == 7'h0d);

    // ------------------------------------------------------------ sequential logic
    always @(posedge clk) begin
        sub_nmi <= 1'b0;
        con_we  <= 1'b0;
        pwr_we  <= 1'b0;
        rst_pulse <= 1'b0;
        if (sub_clk_en) clk_cnt <= clk_cnt + 32'd1;

        // ---- window memory port
        if (win_busy && win_ack) begin
            win_req  <= 1'b0;
            win_busy <= 1'b0;
            win_addr <= win_addr + 21'd1;
        end

        // ---- 6809 side
        if (m_we) begin
            case (m_addr)
                3'd0: begin
                    c_run <= m_wdata[0]; c_hold <= m_wdata[1]; c_shr <= m_wdata[2];
                    c_firq <= m_wdata[3]; c_ien <= m_wdata[4];
                    if (m_wdata[7]) rst_pulse <= 1'b1;
                end
                3'd1: pend_s2m <= 1'b0;
                3'd2: if (m_wdata[7]) sub_nmi <= 1'b1; else pend_m2s <= 1'b1;
                3'd3: idx <= m_wdata;
                3'd4: begin
                    case (ei)
                        7'h00: m2s0 <= m_wdata;  7'h01: m2s1 <= m_wdata;
                        7'h02: m2s2 <= m_wdata;  7'h03: m2s3 <= m_wdata;
                        7'h08: mi <= m_wdata[6:0];
                        7'h09: smmu[mi] <= m_wdata;
                        7'h0a: win_addr[20:16] <= m_wdata[4:0];
                        7'h0b: win_addr[15:8]  <= m_wdata;
                        7'h0c: win_addr[7:0]   <= m_wdata;
                        7'h0d: begin
                            win_req <= 1'b1; win_wr <= 1'b1; win_wdata <= m_wdata; win_busy <= 1'b1;
                        end
                        default: ;
                    endcase
                end
                default: ;
            endcase
        end
        if (m_re && m_addr == 3'd4) begin
            if (ei == 7'h10) clk_latch <= clk_cnt;
            if (win_sel) begin win_req <= 1'b1; win_wr <= 1'b0; win_busy <= 1'b1; end
        end
        if (dat_acc && idx[7] && !win_sel) idx <= {1'b1, ei + 7'd1};

        // ---- sub CPU side
        if (s_we) begin
            case (s_port)
                4'h2: pend_s2m <= 1'b1;
                4'h3: pend_m2s <= 1'b0;
                4'h8: s2m0 <= s_wdata;  4'h9: s2m1 <= s_wdata;
                4'ha: s2m2 <= s_wdata;  4'hb: s2m3 <= s_wdata;
                4'hc: svec <= s_wdata;
                4'he: begin con_we <= 1'b1; con_data <= s_wdata; end
                4'hf: begin pwr_we <= 1'b1; pwr_data <= s_wdata; end
                default: ;
            endcase
        end

        if (rst) begin
            c_run <= 1'b0; c_hold <= 1'b0; c_shr <= 1'b0; c_firq <= 1'b0; c_ien <= 1'b0;
            pend_s2m <= 1'b0; pend_m2s <= 1'b0; idx <= 8'h00; mi <= 7'd0;
            svec <= 8'hff; win_req <= 1'b0; win_busy <= 1'b0; win_addr <= 21'd0; win_wr <= 1'b0;
            clk_cnt <= 32'd0; m2s0 <= 0; m2s1 <= 0; m2s2 <= 0; m2s3 <= 0;
            s2m0 <= 0; s2m1 <= 0; s2m2 <= 0; s2m3 <= 0; win_wdata <= 8'h00;
        end
    end

    // ------------------------------------------------------------ sub CPU port read
    always @* begin
        case (s_port)
            4'h0:    s_rdata = SUB_ID;
            4'h1:    s_rdata = {1'b1, 5'b0, pend_s2m, pend_m2s};
            4'h4:    s_rdata = m2s0;  4'h5: s_rdata = m2s1;  4'h6: s_rdata = m2s2;  4'h7: s_rdata = m2s3;
            4'h8:    s_rdata = s2m0;  4'h9: s_rdata = s2m1;  4'ha: s_rdata = s2m2;  4'hb: s_rdata = s2m3;
            4'hc:    s_rdata = svec;
            default: s_rdata = 8'hff;
        endcase
    end
endmodule
