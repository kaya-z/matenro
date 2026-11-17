// SPDX-License-Identifier: MIT
// i8088_sub.v - the 8088 sub CPU of the Matenro machine without a memory: MCL86 + XLINK + SMMU
//
// The same ports as z80_sub.v (the SoC plugs in one or the other, parameter SUBCPU of matenro_soc.v): the 6809 side is the register
// port m_* of the XLINK and the window port win_*; the memory of the 8088 goes out through a request / acknowledge port (mem_*), which
// the SoC connects to the PSRAM / SDRAM arbiter, so that an access may take any number of clocks (READY of the 8088 is held low).
//
// The core is MCL86 (Ted Fried, MicroCore Labs; fpga/vendor/mcl86): a microsequenced execution unit (eu.v) and the bus interface unit
// with the 8088 pins in minimum mode (biu_min.v).  The BIU runs on the system clock and looks at an "8088 CLK" pin that this module
// makes by dividing the system clock (CLKDIV, 67.5 MHz / 14 = 4.82 MHz); it then does the bus cycles of the 8088 (T1: ALE and the address,
// T2: RD# or WR#, T3: READY is sampled, the data are taken on the next rising edge of CLK).
//
// Bus cycles (IO/M# is high for I/O and for the interrupt acknowledge, as on the 8088):
//   memory read    RD# falls: the physical address (SMMU of the XLINK) goes to mem_*, READY stays low until mem_ack, AD_IN = the byte
//   memory write   WR# falls: the same with the byte of AD_OUT[7:0]
//   I/O read/write ports $00-$0F (the high bits must be 0; other ports read $FF): the registers of the XLINK, as for the Z80
//   interrupt ack  INTA# low: the byte is the vector of the XLINK (s_vec)
//
// Credits: MCL86 is not written by the Matenro authors (fpga/vendor/mcl86/README.md, CREDITS.md).
module i8088_sub #(
    parameter CLKDIV = 14,                   // 8088 CLK = clk / CLKDIV (the BIU needs CLK slower than clk by 4 or more)
    parameter [16:0] CLK_KHZ = 17'd67500     // clk in kHz
) (
    input  wire        clk,
    input  wire        rst,                  // synchronous, high
    // ---- 6809 side (XLINK registers)
    input  wire [2:0]  m_addr,
    input  wire        m_re,
    input  wire        m_we,
    input  wire [7:0]  m_wdata,
    output reg  [7:0]  m_rdata,              // one clock late
    output wire        m_wait,
    output wire        m_win,
    output wire        sub_on,               // the 8088 is enabled: out of reset and not held
    output wire        irq_o,
    output wire        firq_o,
    // ---- window to the physical memory (served by the SoC)
    output wire        win_req,
    output wire        win_wr,
    output wire [20:0] win_addr,
    output wire [7:0]  win_wdata,
    input  wire        win_ack,
    input  wire [7:0]  win_rdata,
    // ---- memory port of the 8088 (physical addresses)
    output reg         mem_req,              // held until mem_ack
    output reg         mem_wr,
    output reg  [20:0] mem_addr,
    output wire [20:0] mem_lk,               // the physical address of the latched bus address, in every clock (valid well before mem_req: for a cache look-up)
    output reg  [7:0]  mem_wdata,
    input  wire        mem_ack,              // one clock
    input  wire [7:0]  mem_rdata,
    // ---- debug / power
    output wire        con_we,
    output wire [7:0]  con_data,
    output wire        pwr_we,
    output wire [7:0]  pwr_data,
    output wire        z80_halted,           // (the name of z80_sub: no HLT pin on MCL86, always 0)
    output wire [39:0] dbg_z
);
    // ------------------------------------------------------------ the 8088 CLK pin
    wire        sub_rst_n, sub_hold, sub_int, sub_nmi;
    wire        run = sub_rst_n & ~sub_hold;
    assign sub_on = run;

    reg [7:0] cnt = 8'd0;
    reg       cpu_clk = 1'b0;                // the CLK pin: high for a third of the period (as the 8088)
    reg       clk_pulse = 1'b0;              // one system clock per CLK period (XE_CLK counts these)
    localparam HI = CLKDIV / 3;
    always @(posedge clk) begin
        clk_pulse <= 1'b0;
        if (rst) begin cnt <= 8'd0; cpu_clk <= 1'b0; end
        else if (run) begin
            cnt <= (cnt == CLKDIV - 1) ? 8'd0 : cnt + 8'd1;
            cpu_clk <= (cnt >= CLKDIV - HI - 1);              // high in the last HI clocks of the period (the next value of cnt is counted)
            if (cnt == CLKDIV - HI - 2) clk_pulse <= 1'b1;  // the rising edge of CLK
        end
    end

    // ------------------------------------------------------------ MCL86
    wire        biu_rst = rst | ~sub_rst_n;
    wire        inta_n, ale, rd_n, wr_n, iom, dtr, den, ad_oe;
    wire [19:0] ad_out;
    reg  [7:0]  ad_in;
    reg         ready_in;

    wire [15:0] eu_biu_command, eu_biu_dataout, eu_register_r3;
    wire        eu_prefix_lock, eu_flag_i, biu_done, biu_clk_counter_zero, biu_nmi_caught, biu_nmi_debounce, biu_intr;
    wire [1:0]  biu_segment;
    wire [7:0]  pfq_top_byte;
    wire        pfq_empty;
    wire [15:0] pfq_addr_out, biu_reg_es, biu_reg_ss, biu_reg_cs, biu_reg_ds, biu_reg_rm, biu_reg_reg, biu_return_data;

    // NMI: the XLINK gives a one-clock pulse, the BIU wants a rising edge that it sees through its input pipeline
    reg [3:0] nmi_sr = 4'd0;
    always @(posedge clk) nmi_sr <= {nmi_sr[2:0], sub_nmi};
    wire nmi_pin = |nmi_sr;

    biu_min biu (
        .CORE_CLK_INT(clk), .CLK(cpu_clk), .RESET_INT(biu_rst), .READY_IN(ready_in), .NMI(nmi_pin), .INTR(sub_int),
        .INTA_n(inta_n), .ALE(ale), .RD_n(rd_n), .WR_n(wr_n), .IOM(iom), .DTR(dtr), .DEN(den), .AD_OE(ad_oe),
        .AD_OUT(ad_out), .AD_IN(ad_in),
        .EU_BIU_COMMAND(eu_biu_command), .EU_BIU_DATAOUT(eu_biu_dataout), .EU_REGISTER_R3(eu_register_r3), .EU_PREFIX_LOCK(eu_prefix_lock),
        .BIU_DONE(biu_done), .BIU_CLK_COUNTER_ZERO(biu_clk_counter_zero), .BIU_SEGMENT(biu_segment), .BIU_NMI_CAUGHT(biu_nmi_caught),
        .BIU_NMI_DEBOUNCE(biu_nmi_debounce), .BIU_INTR(biu_intr),
        .PFQ_TOP_BYTE(pfq_top_byte), .PFQ_EMPTY(pfq_empty), .PFQ_ADDR_OUT(pfq_addr_out),
        .BIU_REGISTER_ES(biu_reg_es), .BIU_REGISTER_SS(biu_reg_ss), .BIU_REGISTER_CS(biu_reg_cs), .BIU_REGISTER_DS(biu_reg_ds),
        .BIU_REGISTER_RM(biu_reg_rm), .BIU_REGISTER_REG(biu_reg_reg), .BIU_RETURN_DATA(biu_return_data));

    mcl86_eu_core eu (
        .CORE_CLK_INT(clk), .RESET_INT(biu_rst), .TEST_N_INT(1'b1),
        .EU_BIU_COMMAND(eu_biu_command), .EU_BIU_DATAOUT(eu_biu_dataout), .EU_REGISTER_R3(eu_register_r3), .EU_PREFIX_LOCK(eu_prefix_lock),
        .EU_FLAG_I(eu_flag_i),
        .BIU_DONE(biu_done), .BIU_CLK_COUNTER_ZERO(biu_clk_counter_zero), .BIU_NMI_CAUGHT(biu_nmi_caught), .BIU_NMI_DEBOUNCE(biu_nmi_debounce),
        .BIU_INTR(biu_intr),
        .PFQ_TOP_BYTE(pfq_top_byte), .PFQ_EMPTY(pfq_empty), .PFQ_ADDR_OUT(pfq_addr_out),
        .BIU_REGISTER_ES(biu_reg_es), .BIU_REGISTER_SS(biu_reg_ss), .BIU_REGISTER_CS(biu_reg_cs), .BIU_REGISTER_DS(biu_reg_ds),
        .BIU_REGISTER_RM(biu_reg_rm), .BIU_REGISTER_REG(biu_reg_reg), .BIU_RETURN_DATA(biu_return_data));

    // ------------------------------------------------------------ the cycle on the bus
    reg [19:0] a_lat;                        // the address of the cycle (the BIU holds it on AD_OUT while ALE is high)
    reg        io_lat;
    always @(posedge clk) if (ale) begin a_lat <= ad_out; io_lat <= iom; end

    reg rd_q = 1'b0, wr_q = 1'b0;
    always @(posedge clk) begin rd_q <= ~rd_n; wr_q <= ~wr_n; end
    wire rd_start = ~rd_n & ~rd_q;
    wire wr_start = ~wr_n & ~wr_q;
    wire act      = ~rd_n | ~wr_n;           // a data cycle is on the bus

    // ---- XLINK and its port bus
    wire [7:0]  s_rdata, s_vec;
    wire [20:0] sub_phys;
    assign mem_lk = sub_phys;
    wire [7:0]  xl_rdata;
    always @(posedge clk) m_rdata <= xl_rdata;

    reg        s_we = 1'b0;                  // one clock: the write of an I/O port, with the byte of dout_q
    reg [7:0]  dout_q;
    wire       port_ok = (a_lat[15:4] == 12'h000);
    wire [3:0] s_port  = a_lat[3:0];

    xlink #(.SUB_ID(8'd2), .SUB_KHZ(CLK_KHZ / CLKDIV), .CLK_KHZ(CLK_KHZ), .SMMU_WT(1)) xl (
        .clk(clk), .rst(rst),
        .m_addr(m_addr), .m_re(m_re), .m_we(m_we), .m_wdata(m_wdata), .m_rdata(xl_rdata), .m_wait(m_wait), .m_win(m_win),
        .irq_n_o(irq_o), .firq_o(firq_o), .shr_o(),
        .sub_rst_n(sub_rst_n), .sub_hold(sub_hold), .sub_int(sub_int), .sub_nmi(sub_nmi),
        .sub_halted(1'b0), .sub_clk_en(clk_pulse),
        .s_port(s_port), .s_re(1'b0), .s_we(s_we & port_ok), .s_wdata(dout_q),
        .s_rdata(s_rdata), .s_vec(s_vec),
        .con_we(con_we), .con_data(con_data), .pwr_we(pwr_we), .pwr_data(pwr_data),
        .sub_addr(a_lat), .sub_is_z80(1'b0), .sub_phys(sub_phys),
        .win_req(win_req), .win_wr(win_wr), .win_addr(win_addr), .win_wdata(win_wdata),
        .win_ack(win_ack), .win_rdata(win_rdata));
    assign z80_halted = 1'b0;

    // ---- the data of the cycle: what AD_IN shows, and READY
    reg        data_ok;                      // the data of this cycle are there (read) / the access is done (write)
    reg [7:0]  rd_data;
    reg [2:0]  dly;                          // clocks until the answer of a port or of the interrupt ack
    reg        pend_io_rd, pend_int, pend_io_wr;

    always @(posedge clk) begin
        s_we <= 1'b0;
        if (rst || !sub_rst_n) begin
            mem_req <= 1'b0; mem_wr <= 1'b0; mem_addr <= 21'd0; mem_wdata <= 8'd0; data_ok <= 1'b0; rd_data <= 8'hff;
            dly <= 3'd0; pend_io_rd <= 1'b0; pend_int <= 1'b0; pend_io_wr <= 1'b0;
        end else begin
            if (!act) data_ok <= 1'b0;
            if (rd_start) begin
                if (!inta_n) begin pend_int <= 1'b1; dly <= 3'd2; end
                else if (io_lat) begin pend_io_rd <= 1'b1; dly <= 3'd2; end
                else begin mem_req <= 1'b1; mem_wr <= 1'b0; mem_addr <= sub_phys; end
            end
            if (wr_start) begin
                dout_q <= ad_out[7:0];
                if (io_lat) begin pend_io_wr <= 1'b1; dly <= 3'd2; end
                else begin mem_req <= 1'b1; mem_wr <= 1'b1; mem_addr <= sub_phys; mem_wdata <= ad_out[7:0]; end
            end
            if (mem_ack) begin
                mem_req <= 1'b0; data_ok <= 1'b1;
                if (!mem_wr) rd_data <= mem_rdata;
            end
            if (dly != 3'd0) begin
                dly <= dly - 3'd1;
                if (dly == 3'd1) begin
                    if (pend_int)  rd_data <= s_vec;
                    if (pend_io_rd) rd_data <= port_ok ? s_rdata : 8'hff;
                    if (pend_io_wr) s_we <= 1'b1;
                    pend_int <= 1'b0; pend_io_rd <= 1'b0; pend_io_wr <= 1'b0;
                    data_ok <= 1'b1;
                end
            end
        end
    end

    always @(*) begin
        ad_in    = rd_data;
        ready_in = ~(act & ~data_ok);
    end

    assign dbg_z = {a_lat, 12'd0, mem_req, mem_wr, ~rd_n, ~wr_n, iom, ale, ~inta_n, data_ok};
endmodule
