// SPDX-License-Identifier: MIT
// tn20k_pll.v - 27 MHz -> the system clock and the same clock shifted by 180 degrees (the SDRAM clock) for the GW2AR-18 (Tang Nano 20K).
// Output = 27 MHz * (FBDIV + 1) / (IDIV + 1).  Default: 67.5 MHz = 27 * 5 / 2 (IDIV 1: PFD 13.5 MHz, ODIV 8: VCO 540 MHz).
// Other settings (build.sh CLKMHZ=): 60 MHz = 27 * 20 / 9 (IDIV 8, FBDIV 19, ODIV 16: VCO 960 MHz), 54 MHz = 27 * 2 (IDIV 0, FBDIV 1, ODIV 16: VCO 864 MHz).
// PSDA_SEL "1000" is a phase shift of CLKOUTP by 180 degrees (as in the Sipeed examples for this chip).
module tn20k_pll #(
    parameter IDIV = 1,                     // IDIV_SEL: the input divider is IDIV + 1
    parameter FBDIV = 4,                    // FBDIV_SEL: the multiplier is FBDIV + 1
    parameter ODIV = 8                      // ODIV_SEL: 2, 4, 8, 16, ... (the VCO = output * ODIV must be 500-1250 MHz)
) (
    input  wire clkin,
    output wire clkout,
    output wire clkoutp,
    output wire lock
);
    wire gnd = 1'b0;
    wire vcc = 1'b1;
    wire clkoutd, clkoutd3;
    rPLL #(
        .FCLKIN("27"),
        .DYN_IDIV_SEL("false"), .IDIV_SEL(IDIV),
        .DYN_FBDIV_SEL("false"), .FBDIV_SEL(FBDIV),
        .DYN_ODIV_SEL("false"), .ODIV_SEL(ODIV),
        .PSDA_SEL("1000"), .DYN_DA_EN("false"), .DUTYDA_SEL("1000"),
        .CLKOUT_FT_DIR(1'b1), .CLKOUTP_FT_DIR(1'b1), .CLKOUT_DLY_STEP(0), .CLKOUTP_DLY_STEP(0),
        .CLKFB_SEL("internal"), .CLKOUT_BYPASS("false"), .CLKOUTP_BYPASS("false"), .CLKOUTD_BYPASS("false"),
        .DYN_SDIV_SEL(2), .CLKOUTD_SRC("CLKOUT"), .CLKOUTD3_SRC("CLKOUT"),
        .DEVICE("GW2AR-18C")
    ) rpll_inst (
        .CLKOUT(clkout), .LOCK(lock), .CLKOUTP(clkoutp), .CLKOUTD(clkoutd), .CLKOUTD3(clkoutd3),
        .RESET(gnd), .RESET_P(gnd), .CLKIN(clkin), .CLKFB(gnd),
        .FBDSEL({6{gnd}}), .IDSEL({6{gnd}}), .ODSEL({6{gnd}}),
        .PSDA({4{gnd}}), .DUTYDA({4{gnd}}), .FDLY({4{vcc}})
    );
endmodule
