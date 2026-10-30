// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsim_top.h for the primary calling header

#include "verilated.h"

#include "Vsim_top___024root.h"

VL_ATTR_COLD void Vsim_top___024root___stl_sequent__TOP__0(Vsim_top___024root* vlSelf);
VL_ATTR_COLD void Vsim_top___024root___stl_sequent__TOP__1(Vsim_top___024root* vlSelf);
void Vsim_top___024root___act_sequent__TOP__0(Vsim_top___024root* vlSelf);
void Vsim_top___024root___act_comb__TOP__0(Vsim_top___024root* vlSelf);

VL_ATTR_COLD void Vsim_top___024root___eval_stl(Vsim_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___eval_stl\n"); );
    // Body
    if (vlSelf->__VstlTriggered.at(0U)) {
        Vsim_top___024root___stl_sequent__TOP__0(vlSelf);
        Vsim_top___024root___stl_sequent__TOP__1(vlSelf);
    }
    if ((vlSelf->__VstlTriggered.at(0U) | vlSelf->__VstlTriggered.at(2U))) {
        Vsim_top___024root___act_sequent__TOP__0(vlSelf);
    }
    if (((vlSelf->__VstlTriggered.at(0U) | vlSelf->__VstlTriggered.at(1U)) 
         | vlSelf->__VstlTriggered.at(2U))) {
        Vsim_top___024root___act_comb__TOP__0(vlSelf);
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsim_top___024root___dump_triggers__act(Vsim_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VactTriggered.at(0U)) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @([hybrid] sim_top.soc.cpu.ALU16 or [hybrid] sim_top.soc.cpu.ALU)\n");
    }
    if (vlSelf->__VactTriggered.at(1U)) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @([hybrid] sim_top.soc.cpu.pc_p1)\n");
    }
    if (vlSelf->__VactTriggered.at(2U)) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @(posedge clk)\n");
    }
    if (vlSelf->__VactTriggered.at(3U)) {
        VL_DBG_MSGF("         'act' region trigger index 3 is active: @(posedge sim_top.soc.cpu.NMIClear or negedge sim_top.soc.cpu.NMISample2)\n");
    }
    if (vlSelf->__VactTriggered.at(4U)) {
        VL_DBG_MSGF("         'act' region trigger index 4 is active: @(negedge sim_top.soc.q)\n");
    }
    if (vlSelf->__VactTriggered.at(5U)) {
        VL_DBG_MSGF("         'act' region trigger index 5 is active: @(negedge sim_top.soc.e)\n");
    }
    if (vlSelf->__VactTriggered.at(6U)) {
        VL_DBG_MSGF("         'act' region trigger index 6 is active: @(posedge clk or negedge sim_top.soc.sub.sub_rst_n)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsim_top___024root___dump_triggers__nba(Vsim_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @([hybrid] sim_top.soc.cpu.ALU16 or [hybrid] sim_top.soc.cpu.ALU)\n");
    }
    if (vlSelf->__VnbaTriggered.at(1U)) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @([hybrid] sim_top.soc.cpu.pc_p1)\n");
    }
    if (vlSelf->__VnbaTriggered.at(2U)) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @(posedge clk)\n");
    }
    if (vlSelf->__VnbaTriggered.at(3U)) {
        VL_DBG_MSGF("         'nba' region trigger index 3 is active: @(posedge sim_top.soc.cpu.NMIClear or negedge sim_top.soc.cpu.NMISample2)\n");
    }
    if (vlSelf->__VnbaTriggered.at(4U)) {
        VL_DBG_MSGF("         'nba' region trigger index 4 is active: @(negedge sim_top.soc.q)\n");
    }
    if (vlSelf->__VnbaTriggered.at(5U)) {
        VL_DBG_MSGF("         'nba' region trigger index 5 is active: @(negedge sim_top.soc.e)\n");
    }
    if (vlSelf->__VnbaTriggered.at(6U)) {
        VL_DBG_MSGF("         'nba' region trigger index 6 is active: @(posedge clk or negedge sim_top.soc.sub.sub_rst_n)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vsim_top___024root___ctor_var_reset(Vsim_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->resetn = VL_RAND_RESET_I(1);
    vlSelf->rxd = VL_RAND_RESET_I(1);
    vlSelf->txd = VL_RAND_RESET_I(1);
    vlSelf->sd_clk = VL_RAND_RESET_I(1);
    vlSelf->sd_mosi = VL_RAND_RESET_I(1);
    vlSelf->sd_miso = VL_RAND_RESET_I(1);
    vlSelf->sd_cs = VL_RAND_RESET_I(1);
    vlSelf->led = VL_RAND_RESET_I(6);
    vlSelf->fl_cs = VL_RAND_RESET_I(1);
    vlSelf->fl_clk = VL_RAND_RESET_I(1);
    vlSelf->fl_mosi = VL_RAND_RESET_I(1);
    vlSelf->fl_miso = VL_RAND_RESET_I(1);
    vlSelf->kanji_ok = VL_RAND_RESET_I(1);
    vlSelf->term_stb = VL_RAND_RESET_I(1);
    vlSelf->term_byte = VL_RAND_RESET_I(8);
    VL_RAND_RESET_W(112, vlSelf->dbg_regs);
    vlSelf->dbg_lic = VL_RAND_RESET_I(1);
    vlSelf->dbg_addr = VL_RAND_RESET_I(16);
    vlSelf->dbg_acc = VL_RAND_RESET_I(1);
    vlSelf->dbg_din = VL_RAND_RESET_I(8);
    vlSelf->dbg_rnw = VL_RAND_RESET_I(1);
    vlSelf->dbg_vma = VL_RAND_RESET_I(1);
    vlSelf->dbg_ps_rd = VL_RAND_RESET_I(1);
    vlSelf->dbg_ps_wr = VL_RAND_RESET_I(1);
    vlSelf->dbg_ps_addr = VL_RAND_RESET_I(22);
    vlSelf->sim_top__DOT__ps_rd = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__ps_wr = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__ps_addr = VL_RAND_RESET_I(22);
    vlSelf->sim_top__DOT__ps_din = VL_RAND_RESET_I(16);
    vlSelf->sim_top__DOT__ps_dout = VL_RAND_RESET_I(16);
    vlSelf->sim_top__DOT__soc__DOT__rst = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__e = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__q = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__nreset_cpu = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__xl_rdata = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__xl_rcap = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__xl_cnt = VL_RAND_RESET_I(3);
    vlSelf->sim_top__DOT__soc__DOT__xl_cap = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__xw_act = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__xw_rdp = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__xw_wrp = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__win_addr = VL_RAND_RESET_I(21);
    vlSelf->sim_top__DOT__soc__DOT__win_wdata = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__zm_req = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__zm_wr = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__zm_ack = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__zm_addr = VL_RAND_RESET_I(21);
    vlSelf->sim_top__DOT__soc__DOT__zm_wdata = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__zm_rdata_w = VL_RAND_RESET_I(16);
    vlSelf->sim_top__DOT__soc__DOT__div = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__ph = VL_RAND_RESET_I(2);
    vlSelf->sim_top__DOT__soc__DOT__ecyc = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__acc_go = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__acc2 = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__mem_pend = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__disk_busy = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__ps_dout_m = VL_RAND_RESET_I(16);
    vlSelf->sim_top__DOT__soc__DOT__pwroff = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__osrun = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__acia_pend = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__settle = VL_RAND_RESET_I(6);
    vlSelf->sim_top__DOT__soc__DOT__cs_ = VL_RAND_RESET_I(4);
    vlSelf->sim_top__DOT__soc__DOT__cw = VL_RAND_RESET_I(22);
    vlSelf->sim_top__DOT__soc__DOT__c_wr = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__t_rd = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__ld_start = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__ld_done = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__ld_wr = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__rcnt = VL_RAND_RESET_I(4);
    vlSelf->sim_top__DOT__soc__DOT__go_req = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__l2 = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__bsy_d = VL_RAND_RESET_I(4);
    vlSelf->sim_top__DOT__soc__DOT__tp = VL_RAND_RESET_I(2);
    vlSelf->sim_top__DOT__soc__DOT__t_fail = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__t_faddr = VL_RAND_RESET_I(22);
    vlSelf->sim_top__DOT__soc__DOT__mi = VL_RAND_RESET_I(4);
    vlSelf->sim_top__DOT__soc__DOT__p_go = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__st_wr = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__st_d = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__st_d2 = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__p_ch = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__st_byte = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__td_r = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__t_got_r = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__cw_n = VL_RAND_RESET_I(22);
    vlSelf->sim_top__DOT__soc__DOT__cw_last = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__cw_pg = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__run = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__ld_addr = VL_RAND_RESET_I(22);
    vlSelf->sim_top__DOT__soc__DOT__ld_data = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__vma_pend = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__rd_reg = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__c_rd = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__c_cwr = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__c_addr = VL_RAND_RESET_I(22);
    vlSelf->sim_top__DOT__soc__DOT__c_wdata = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__c_rsel = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__c_isrd = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__mp_wait = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__pa = VL_RAND_RESET_I(22);
    vlSelf->sim_top__DOT__soc__DOT__in_io = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__off = VL_RAND_RESET_I(9);
    vlSelf->sim_top__DOT__soc__DOT__io_acia = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__io_power = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__io_timer = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__io_disk = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__io_hit = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__io_quiet = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__rom_sel = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__io_mmu = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__io_map = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__io_ta = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__io_modr = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__io_xl = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__pa_r = VL_RAND_RESET_I(22);
    vlSelf->sim_top__DOT__soc__DOT__ta = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->sim_top__DOT__soc__DOT__map_s[__Vi0] = VL_RAND_RESET_I(8);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->sim_top__DOT__soc__DOT__map_u[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->sim_top__DOT__soc__DOT__tr = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__tr_raw = VL_RAND_RESET_I(8);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->sim_top__DOT__soc__DOT__rom[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->sim_top__DOT__soc__DOT__rom_q = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__acia_rd = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__acia_byte = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__acia_wr = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__timer_wr = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__d_drive = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__d_lsn2 = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__d_lsn1 = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__d_lsn0 = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__d_bufh = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__d_bufl = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__d_47 = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__e040 = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__dgo = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__dwr = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__disk_result = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__d_rd = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__d_wr = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__d_addr = VL_RAND_RESET_I(22);
    vlSelf->sim_top__DOT__soc__DOT__d_din = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__sd_ready = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sd_fail = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__disk_busy_d = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT____Vcellinp__disk__lsn = VL_RAND_RESET_I(24);
    vlSelf->sim_top__DOT__soc__DOT__io_rdata = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__w_disk = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__w_off = VL_RAND_RESET_I(3);
    vlSelf->sim_top__DOT__soc__DOT__disk_sel = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__m_wr_s = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__m0_pulse = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__m0_req = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__m0_wrr = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__m0_addr = VL_RAND_RESET_I(22);
    vlSelf->sim_top__DOT__soc__DOT__m0_din = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__m0_ack = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__xl_acc = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__xl_re = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__xl_we = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__win_req = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__win_wr = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__win_rdata = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__xw_go = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__win_ack_r = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__win_wr_q = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__hb = VL_RAND_RESET_I(24);
    vlSelf->sim_top__DOT__soc__DOT____VdfgTmp_h20f74f65__0 = 0;
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DOutput = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__a = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__b = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__x = VL_RAND_RESET_I(16);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__y = VL_RAND_RESET_I(16);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u = VL_RAND_RESET_I(16);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s = VL_RAND_RESET_I(16);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc = VL_RAND_RESET_I(16);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__dp = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp = VL_RAND_RESET_I(16);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr = VL_RAND_RESET_I(16);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ea = VL_RAND_RESET_I(16);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__a_nxt = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__b_nxt = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__x_nxt = VL_RAND_RESET_I(16);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__y_nxt = VL_RAND_RESET_I(16);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u_nxt = VL_RAND_RESET_I(16);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s_nxt = VL_RAND_RESET_I(16);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_nxt = VL_RAND_RESET_I(16);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__dp_nxt = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc_nxt = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt = VL_RAND_RESET_I(16);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ea_nxt = VL_RAND_RESET_I(16);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt = VL_RAND_RESET_I(16);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__BS_nxt = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__BA_nxt = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_p1 = VL_RAND_RESET_I(16);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__NMIMask = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__NMILatched = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__NMISample = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__NMISample2 = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__NMIClear = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__NMIClear_nxt = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IRQLatched = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IRQSample = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IRQSample2 = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__FIRQLatched = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__FIRQSample = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__FIRQSample2 = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__HALTLatched = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__HALTSample = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__HALTSample2 = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DMABREQLatched = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DMABREQSample = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DMABREQSample2 = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IntType = VL_RAND_RESET_I(3);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IntType_nxt = VL_RAND_RESET_I(3);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__InstPage2 = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__InstPage3 = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__InstPage2_nxt = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__InstPage3_nxt = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1 = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst2 = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst3 = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1_nxt = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst2_nxt = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst3_nxt = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState = VL_RAND_RESET_I(7);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = VL_RAND_RESET_I(7);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__NextState = VL_RAND_RESET_I(7);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__NextState_nxt = VL_RAND_RESET_I(7);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__MappedInstruction = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rnRESET = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IndexedMode = VL_RAND_RESET_I(4);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IndexedIndirect = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IndexedRegister = VL_RAND_RESET_I(3);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IsStore8 = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Store8RegisterNum = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IsStore16 = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__StoreRegisterNum = VL_RAND_RESET_I(3);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IsSpecialImmediate = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16Reg = VL_RAND_RESET_I(3);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpWriteback = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16Opcode = VL_RAND_RESET_I(3);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16 = VL_RAND_RESET_I(24);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU8Op = VL_RAND_RESET_I(5);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU8Writeback = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU = VL_RAND_RESET_I(16);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__AddrModeType = VL_RAND_RESET_I(3);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Is8BitInst = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IsTargetRegA = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__TakeBranch = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__EXGTFRRegA = VL_RAND_RESET_I(16);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__EXGTFRRegB = VL_RAND_RESET_I(16);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT____Vconcswap_1_h74bdd05e__0 = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT____Vconcswap_1_h7a07b729__0 = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__loader__DOT__sgo = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__loader__DOT__sbusy = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__loader__DOT__sdone = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__loader__DOT__stx = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__loader__DOT__srx = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__loader__DOT__sh_in = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__loader__DOT__sh_out = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__loader__DOT__bcnt = VL_RAND_RESET_I(3);
    vlSelf->sim_top__DOT__soc__DOT__loader__DOT__hc = VL_RAND_RESET_I(2);
    vlSelf->sim_top__DOT__soc__DOT__loader__DOT__st = VL_RAND_RESET_I(4);
    vlSelf->sim_top__DOT__soc__DOT__loader__DOT__tries = VL_RAND_RESET_I(4);
    vlSelf->sim_top__DOT__soc__DOT__loader__DOT__ci = VL_RAND_RESET_I(3);
    vlSelf->sim_top__DOT__soc__DOT__loader__DOT__n = VL_RAND_RESET_I(18);
    vlSelf->sim_top__DOT__soc__DOT__loader__DOT__n_lt4 = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__loader__DOT__n_last = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__loader__DOT__magic = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__loader__DOT__cmd = VL_RAND_RESET_I(32);
    vlSelf->sim_top__DOT__soc__DOT__loader__DOT__pi = VL_RAND_RESET_I(4);
    vlSelf->sim_top__DOT__soc__DOT__loader__DOT__pw = VL_RAND_RESET_I(14);
    vlSelf->sim_top__DOT__soc__DOT__acia__DOT__rxs = VL_RAND_RESET_I(2);
    vlSelf->sim_top__DOT__soc__DOT__acia__DOT__rbaud = VL_RAND_RESET_I(10);
    vlSelf->sim_top__DOT__soc__DOT__acia__DOT__rbit = VL_RAND_RESET_I(4);
    vlSelf->sim_top__DOT__soc__DOT__acia__DOT__rbusy = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__acia__DOT__rsh = VL_RAND_RESET_I(8);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->sim_top__DOT__soc__DOT__acia__DOT__fifo[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->sim_top__DOT__soc__DOT__acia__DOT__wp = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__acia__DOT__rp = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__acia__DOT__last = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__acia__DOT__push = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__acia__DOT__push_d = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__acia__DOT__empty = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__acia__DOT__full = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__acia__DOT__rq = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__acia__DOT__pop = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__acia__DOT__thold = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__acia__DOT__tfull = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__acia__DOT__tsh = VL_RAND_RESET_I(10);
    vlSelf->sim_top__DOT__soc__DOT__acia__DOT__tbit = VL_RAND_RESET_I(4);
    vlSelf->sim_top__DOT__soc__DOT__acia__DOT__tbaud = VL_RAND_RESET_I(10);
    vlSelf->sim_top__DOT__soc__DOT__acia__DOT__tbusy = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__acia__DOT__status_r = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__acia__DOT__rdata_r = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__timer__DOT__running = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__timer__DOT__pending = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__timer__DOT__r0 = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__timer__DOT__tcnt = VL_RAND_RESET_I(16);
    vlSelf->sim_top__DOT__soc__DOT__timer__DOT__y = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__timer__DOT__mo = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__timer__DOT__d = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__timer__DOT__h = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__timer__DOT__mi = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__timer__DOT__s = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__timer__DOT__slo = VL_RAND_RESET_I(11);
    vlSelf->sim_top__DOT__soc__DOT__timer__DOT__shi = VL_RAND_RESET_I(11);
    vlSelf->sim_top__DOT__soc__DOT__timer__DOT__scarry = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__timer__DOT__sec_tick = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 6; ++__Vi0) {
        vlSelf->sim_top__DOT__soc__DOT__timer__DOT__l[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->sim_top__DOT__soc__DOT__timer__DOT__s59 = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__timer__DOT__mi59 = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__timer__DOT__h23 = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__timer__DOT__dlast = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__timer__DOT__mo12 = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__timer__DOT____Vlvbound_h29784b0a__0 = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__fast = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__spi_go = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__spi_tx = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__spi_rx = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__spi_busy = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__spi_done = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__hcnt = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__bcnt = VL_RAND_RESET_I(4);
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__sh_out = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__sh_in = VL_RAND_RESET_I(8);
    for (int __Vi0 = 0; __Vi0 < 512; ++__Vi0) {
        vlSelf->sim_top__DOT__soc__DOT__disk__DOT__bram[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__b_waddr = VL_RAND_RESET_I(9);
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__b_raddr = VL_RAND_RESET_I(9);
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__b_wdata = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__b_we = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__b_q = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__st = VL_RAND_RESET_I(6);
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__cmd_next = VL_RAND_RESET_I(6);
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__skip_next = VL_RAND_RESET_I(6);
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__c_inc = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__c_clr = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__cnt_lo = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__cnt_hi = VL_RAND_RESET_I(13);
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__cnt = VL_RAND_RESET_I(21);
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__idx = VL_RAND_RESET_I(10);
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__tries = VL_RAND_RESET_I(5);
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__ctry = VL_RAND_RESET_I(4);
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__cbuf = VL_RAND_RESET_Q(48);
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__cstep = VL_RAND_RESET_I(3);
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__rword = VL_RAND_RESET_I(32);
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__rbytes = VL_RAND_RESET_I(2);
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__skipn = VL_RAND_RESET_I(2);
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__sdv2 = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__ccs = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__pend = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__exec = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__cvalid = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__cblk = VL_RAND_RESET_I(24);
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__hit_q = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__idx_255 = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__idx_511 = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__idx_10 = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__blk = VL_RAND_RESET_I(24);
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__half = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__wr_r = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__buf_r = VL_RAND_RESET_I(16);
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__bad_drive = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__rx_fe = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__rx_ff = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__rx_resp = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__rx_r1 = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__rx_00 = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__rx_01 = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__rx_b2 = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__r1_ok = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__r1_idle = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__r1_ill = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__blk_arg = VL_RAND_RESET_I(32);
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__caller = VL_RAND_RESET_I(6);
    vlSelf->sim_top__DOT__soc__DOT__arb__DOT__st = VL_RAND_RESET_I(3);
    vlSelf->sim_top__DOT__soc__DOT__arb__DOT__sel = VL_RAND_RESET_I(2);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cnt = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cen_raw = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__zstall = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__rd_start = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__wr_end = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cen = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__sub_rst_n = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__sub_nmi = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__m1_n = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__mreq_n = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__iorq_n = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__rd_n = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__wr_n = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__A = VL_RAND_RESET_I(16);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__dout = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__di_q = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__nmi_n = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__nmi_pend = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__int_ack = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__io_rd = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__io_wr = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__mem_rd = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__mem_wrc = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__mem_rd_q = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__mem_wr_q = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__io_wr_q = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__dout_q = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__a_q = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__s_we = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__s_port = VL_RAND_RESET_I(4);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__port_ok = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__sub_phys = VL_RAND_RESET_I(21);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl_rdata = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT____Vcellinp__xl__s_we = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__wr_phys = VL_RAND_RESET_I(21);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__wr_data = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__zdat = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__zrel = VL_RAND_RESET_I(3);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__sel_io = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__sel_ack = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__no_read = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__di_reg = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ACC = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Ap = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Fp = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__SP = VL_RAND_RESET_I(16);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__PC = VL_RAND_RESET_I(16);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegDIH = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegDIL = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegBusA = VL_RAND_RESET_I(16);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegBusB = VL_RAND_RESET_I(16);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegBusC = VL_RAND_RESET_I(16);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegAddrA_r = VL_RAND_RESET_I(3);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegAddrA = VL_RAND_RESET_I(3);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegAddrB_r = VL_RAND_RESET_I(3);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegAddrC = VL_RAND_RESET_I(3);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegWEH = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegWEL = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Alternate = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__TmpAddr = VL_RAND_RESET_I(16);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ISet = VL_RAND_RESET_I(2);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegBusA_r = VL_RAND_RESET_I(16);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ID16 = VL_RAND_RESET_I(16);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_Mux = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstate = VL_RAND_RESET_I(7);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle = VL_RAND_RESET_I(7);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__last_mcycle = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__last_tstate = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IntE_FF1 = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IntE_FF2 = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Halt_FF = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__BusReq_s = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__BusAck = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ClkEn = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__NMI_s = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__INT_s = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IStatus = VL_RAND_RESET_I(2);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__XY_State = VL_RAND_RESET_I(2);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Pre_XY_F_M = VL_RAND_RESET_I(3);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__NextIs_XY_Fetch = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__XY_Ind = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__No_BTR = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__BTR_r = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Auto_Wait = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Auto_Wait_t1 = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Auto_Wait_t2 = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDecZ = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__BusB = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__BusA = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Q = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__cpi_xy_n = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg_r = VL_RAND_RESET_I(5);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Arith16_r = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Z16_r = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op_r = VL_RAND_RESET_I(4);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU_r = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__PreserveC_r = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles = VL_RAND_RESET_I(3);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = VL_RAND_RESET_I(3);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = VL_RAND_RESET_I(3);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IntCycle = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__NMICycle = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_WZ = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = VL_RAND_RESET_I(4);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Prefix = VL_RAND_RESET_I(2);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Acc = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = VL_RAND_RESET_I(4);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To = VL_RAND_RESET_I(4);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = VL_RAND_RESET_I(4);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__PreserveC = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Arith16 = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = VL_RAND_RESET_I(3);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Jump = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__JumpE = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__JumpXY = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Call = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RstP = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDZ = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDW = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDSPHL = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__iorq_i = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Special_LD = VL_RAND_RESET_I(3);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ExchangeDH = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ExchangeRp = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ExchangeAF = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ExchangeRS = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I_DJNZ = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I_CPL = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I_CCF = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I_SCF = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I_RETN = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I_BT = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I_BC = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I_BTR = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I_RLD = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I_RRD = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I_INRC = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__SetDI = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__SetEI = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IMode = VL_RAND_RESET_I(2);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Halt = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__PC16 = VL_RAND_RESET_I(16);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__SP16 = VL_RAND_RESET_I(16);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__SP16_A = VL_RAND_RESET_I(16);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__SP16_B = VL_RAND_RESET_I(16);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Oldnmi_n = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__SSS = VL_RAND_RESET_I(3);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__BitMask = VL_RAND_RESET_I(8);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_reg__DOT__RegsH[__Vi0] = VL_RAND_RESET_I(8);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_reg__DOT__RegsL[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__c_run = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__c_hold = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__c_shr = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__c_firq = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__c_ien = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__rst_pulse = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__pend_s2m = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__pend_m2s = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__m2s0 = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__m2s1 = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__m2s2 = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__m2s3 = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__s2m0 = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__s2m1 = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__s2m2 = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__s2m3 = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__mi = VL_RAND_RESET_I(7);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__svec = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__clk_cnt = VL_RAND_RESET_I(32);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__clk_latch = VL_RAND_RESET_I(32);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__win_busy = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 128; ++__Vi0) {
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__smmu[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__ei = VL_RAND_RESET_I(7);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__ext_rd = VL_RAND_RESET_I(8);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__win_sel = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT____VdfgTmp_h1ff8cf4e__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 2097152; ++__Vi0) {
        vlSelf->sim_top__DOT__mem__DOT__mem[__Vi0] = VL_RAND_RESET_I(16);
    }
    vlSelf->sim_top__DOT__mem__DOT__cnt = VL_RAND_RESET_I(16);
    vlSelf->sim_top__DOT__mem__DOT__is_wr = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__mem__DOT__a = VL_RAND_RESET_I(22);
    vlSelf->sim_top__DOT__mem__DOT__d = VL_RAND_RESET_I(16);
    vlSelf->sim_top__DOT__mem__DOT__bw = VL_RAND_RESET_I(1);
    vlSelf->sim_top__DOT__mem__DOT__refresh = VL_RAND_RESET_I(12);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__15__mode = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__16__mode = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__17__mode = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__ALUFn = VL_RAND_RESET_I(16);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__ALUFn = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__38__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__38__inst = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__38__hi = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__38__lo = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__39__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__39__inst = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__39__hi = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__39__lo = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__40__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__40__inst = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__40__hi = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__40__lo = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__41__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__41__inst = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__41__hi = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__41__lo = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__42__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__42__inst = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__42__hi = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__42__lo = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__43__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__43__inst = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__43__hi = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__43__lo = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set1__44__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set1__44__instr = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set1__44__result = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set1__44__hi = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set1__44__lo = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set0__45__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set0__45__instr = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set0__45__result = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set0__45__hi = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set0__45__lo = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__46__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__46__inst = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__46__hi = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__46__lo = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsOneByteInstruction__47__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsOneByteInstruction__47__inst = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsOneByteInstruction__47__is = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsOneByteInstruction__47__hi = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsOneByteInstruction__47__lo = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__76__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__76__FF = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__76__cc = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__77__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__77__FF = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__77__cc = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__78__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__78__FF = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__78__cc = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__79__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__79__FF = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__79__cc = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__80__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__80__FF = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__80__cc = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__81__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__81__FF = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__81__cc = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__82__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__82__FF = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__82__cc = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__83__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__83__FF = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__83__cc = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__84__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__84__FF = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__84__cc = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__85__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__85__FF = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__85__cc = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__86__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__86__FF = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__86__cc = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__87__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__87__FF = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__87__cc = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__88__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__88__FF = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__88__cc = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__89__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__89__FF = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__89__cc = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__90__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__90__FF = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__90__cc = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__91__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__91__FF = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__91__cc = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__92__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__92__FF = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__92__cc = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__93__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__93__FF = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__93__cc = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__94__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__94__FF = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__94__cc = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__95__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__95__FF = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__95__cc = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__96__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__96__FF = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__96__cc = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__97__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__97__FF = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__97__cc = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__98__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__98__FF = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__98__cc = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__99__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__99__FF = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__99__cc = VL_RAND_RESET_I(3);
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__settle = VL_RAND_RESET_I(6);
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__div = VL_RAND_RESET_I(8);
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__ph = VL_RAND_RESET_I(2);
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__p_go = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__cs_ = VL_RAND_RESET_I(4);
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__cw = VL_RAND_RESET_I(22);
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__bsy_d = VL_RAND_RESET_I(4);
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__rcnt = VL_RAND_RESET_I(4);
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__tp = VL_RAND_RESET_I(2);
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__t_fail = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__t_faddr = VL_RAND_RESET_I(22);
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__mi = VL_RAND_RESET_I(4);
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__mem_pend = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__mp_wait = VL_RAND_RESET_I(1);
    vlSelf->__Vdlyvset__sim_top__DOT__soc__DOT__map_s__v0 = 0;
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__l2 = VL_RAND_RESET_I(1);
    vlSelf->__Vdlyvset__sim_top__DOT__soc__DOT__map_s__v1 = 0;
    vlSelf->__Vdlyvset__sim_top__DOT__soc__DOT__map_s__v9 = 0;
    vlSelf->__Vdlyvset__sim_top__DOT__soc__DOT__map_s__v17 = 0;
    vlSelf->__Vdlyvset__sim_top__DOT__soc__DOT__map_u__v16 = 0;
    vlSelf->__Vdlyvset__sim_top__DOT__soc__DOT__map_s__v26 = 0;
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__c_isrd = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__m0_addr = VL_RAND_RESET_I(22);
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__xl_cnt = VL_RAND_RESET_I(3);
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__xw_act = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__sbusy = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__fl_clk = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__bcnt = VL_RAND_RESET_I(3);
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__st = VL_RAND_RESET_I(4);
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__pi = VL_RAND_RESET_I(4);
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__cmd = VL_RAND_RESET_I(32);
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__ci = VL_RAND_RESET_I(3);
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__n = VL_RAND_RESET_I(18);
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__stx = VL_RAND_RESET_I(8);
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__acia__DOT__tfull = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__timer__DOT__tcnt = VL_RAND_RESET_I(16);
    vlSelf->__Vdlyvdim0__sim_top__DOT__soc__DOT__disk__DOT__bram__v0 = 0;
    vlSelf->__Vdlyvval__sim_top__DOT__soc__DOT__disk__DOT__bram__v0 = VL_RAND_RESET_I(8);
    vlSelf->__Vdlyvset__sim_top__DOT__soc__DOT__disk__DOT__bram__v0 = 0;
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__disk__DOT__b_raddr = VL_RAND_RESET_I(9);
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__arb__DOT__st = VL_RAND_RESET_I(3);
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cnt = VL_RAND_RESET_I(8);
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__di_q = VL_RAND_RESET_I(8);
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__win_busy = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx = VL_RAND_RESET_I(8);
    vlSelf->__Vdly__sim_top__DOT__mem__DOT__cnt = VL_RAND_RESET_I(16);
    vlSelf->__Vdly__sim_top__DOT__ps_dout = VL_RAND_RESET_I(16);
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__PC = VL_RAND_RESET_I(16);
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__XY_State = VL_RAND_RESET_I(2);
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR = VL_RAND_RESET_I(8);
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__TmpAddr = VL_RAND_RESET_I(16);
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ACC = VL_RAND_RESET_I(8);
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F = VL_RAND_RESET_I(8);
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__SP = VL_RAND_RESET_I(16);
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Auto_Wait_t1 = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Auto_Wait_t2 = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IntE_FF1 = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IntE_FF2 = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstate = VL_RAND_RESET_I(7);
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Pre_XY_F_M = VL_RAND_RESET_I(3);
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle = VL_RAND_RESET_I(7);
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__NMICycle = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigrprev__TOP__sim_top__DOT__soc__DOT__cpu__DOT__ALU16 = VL_RAND_RESET_I(24);
    vlSelf->__Vtrigrprev__TOP__sim_top__DOT__soc__DOT__cpu__DOT__ALU = VL_RAND_RESET_I(16);
    vlSelf->__Vtrigrprev__TOP__sim_top__DOT__soc__DOT__cpu__DOT__pc_p1 = VL_RAND_RESET_I(16);
    vlSelf->__VstlDidInit = 0;
    vlSelf->__Vtrigrprev__TOP__clk = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigrprev__TOP__sim_top__DOT__soc__DOT__cpu__DOT__NMIClear = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigrprev__TOP__sim_top__DOT__soc__DOT__cpu__DOT__NMISample2 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigrprev__TOP__sim_top__DOT__soc__DOT__q = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigrprev__TOP__sim_top__DOT__soc__DOT__e = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigrprev__TOP__sim_top__DOT__soc__DOT__sub__DOT__sub_rst_n = VL_RAND_RESET_I(1);
    vlSelf->__VactDidInit = 0;
}
