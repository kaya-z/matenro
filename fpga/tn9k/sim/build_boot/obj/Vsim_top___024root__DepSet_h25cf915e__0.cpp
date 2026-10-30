// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsim_top.h for the primary calling header

#include "verilated.h"

#include "Vsim_top__Syms.h"
#include "Vsim_top___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsim_top___024root___dump_triggers__act(Vsim_top___024root* vlSelf);
#endif  // VL_DEBUG

void Vsim_top___024root___eval_triggers__act(Vsim_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.at(0U) = ((vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16 
                                       != vlSelf->__Vtrigrprev__TOP__sim_top__DOT__soc__DOT__cpu__DOT__ALU16) 
                                      | ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU) 
                                         != (IData)(vlSelf->__Vtrigrprev__TOP__sim_top__DOT__soc__DOT__cpu__DOT__ALU)));
    vlSelf->__VactTriggered.at(1U) = ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_p1) 
                                      != (IData)(vlSelf->__Vtrigrprev__TOP__sim_top__DOT__soc__DOT__cpu__DOT__pc_p1));
    vlSelf->__VactTriggered.at(2U) = ((IData)(vlSelf->clk) 
                                      & (~ (IData)(vlSelf->__Vtrigrprev__TOP__clk)));
    vlSelf->__VactTriggered.at(3U) = (((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__NMIClear) 
                                       & (~ (IData)(vlSelf->__Vtrigrprev__TOP__sim_top__DOT__soc__DOT__cpu__DOT__NMIClear))) 
                                      | ((~ (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__NMISample2)) 
                                         & (IData)(vlSelf->__Vtrigrprev__TOP__sim_top__DOT__soc__DOT__cpu__DOT__NMISample2)));
    vlSelf->__VactTriggered.at(4U) = ((~ (IData)(vlSelf->sim_top__DOT__soc__DOT__q)) 
                                      & (IData)(vlSelf->__Vtrigrprev__TOP__sim_top__DOT__soc__DOT__q));
    vlSelf->__VactTriggered.at(5U) = ((~ (IData)(vlSelf->sim_top__DOT__soc__DOT__e)) 
                                      & (IData)(vlSelf->__Vtrigrprev__TOP__sim_top__DOT__soc__DOT__e));
    vlSelf->__VactTriggered.at(6U) = (((IData)(vlSelf->clk) 
                                       & (~ (IData)(vlSelf->__Vtrigrprev__TOP__clk))) 
                                      | ((~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__sub_rst_n)) 
                                         & (IData)(vlSelf->__Vtrigrprev__TOP__sim_top__DOT__soc__DOT__sub__DOT__sub_rst_n)));
    vlSelf->__Vtrigrprev__TOP__sim_top__DOT__soc__DOT__cpu__DOT__ALU16 
        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16;
    vlSelf->__Vtrigrprev__TOP__sim_top__DOT__soc__DOT__cpu__DOT__ALU 
        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU;
    vlSelf->__Vtrigrprev__TOP__sim_top__DOT__soc__DOT__cpu__DOT__pc_p1 
        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_p1;
    vlSelf->__Vtrigrprev__TOP__clk = vlSelf->clk;
    vlSelf->__Vtrigrprev__TOP__sim_top__DOT__soc__DOT__cpu__DOT__NMIClear 
        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__NMIClear;
    vlSelf->__Vtrigrprev__TOP__sim_top__DOT__soc__DOT__cpu__DOT__NMISample2 
        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__NMISample2;
    vlSelf->__Vtrigrprev__TOP__sim_top__DOT__soc__DOT__q 
        = vlSelf->sim_top__DOT__soc__DOT__q;
    vlSelf->__Vtrigrprev__TOP__sim_top__DOT__soc__DOT__e 
        = vlSelf->sim_top__DOT__soc__DOT__e;
    vlSelf->__Vtrigrprev__TOP__sim_top__DOT__soc__DOT__sub__DOT__sub_rst_n 
        = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__sub_rst_n;
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->__VactDidInit))))) {
        vlSelf->__VactDidInit = 1U;
        vlSelf->__VactTriggered.at(0U) = 1U;
        vlSelf->__VactTriggered.at(1U) = 1U;
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vsim_top___024root___dump_triggers__act(vlSelf);
    }
#endif
}
