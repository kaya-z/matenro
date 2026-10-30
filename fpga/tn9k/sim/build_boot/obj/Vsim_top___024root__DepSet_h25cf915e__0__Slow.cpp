// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsim_top.h for the primary calling header

#include "verilated.h"

#include "Vsim_top__Syms.h"
#include "Vsim_top___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsim_top___024root___dump_triggers__stl(Vsim_top___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vsim_top___024root___eval_triggers__stl(Vsim_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.at(0U) = (0U == vlSelf->__VstlIterCount);
    vlSelf->__VstlTriggered.at(1U) = ((vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16 
                                       != vlSelf->__Vtrigrprev__TOP__sim_top__DOT__soc__DOT__cpu__DOT__ALU16) 
                                      | ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU) 
                                         != (IData)(vlSelf->__Vtrigrprev__TOP__sim_top__DOT__soc__DOT__cpu__DOT__ALU)));
    vlSelf->__VstlTriggered.at(2U) = ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_p1) 
                                      != (IData)(vlSelf->__Vtrigrprev__TOP__sim_top__DOT__soc__DOT__cpu__DOT__pc_p1));
    vlSelf->__Vtrigrprev__TOP__sim_top__DOT__soc__DOT__cpu__DOT__ALU16 
        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16;
    vlSelf->__Vtrigrprev__TOP__sim_top__DOT__soc__DOT__cpu__DOT__ALU 
        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU;
    vlSelf->__Vtrigrprev__TOP__sim_top__DOT__soc__DOT__cpu__DOT__pc_p1 
        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_p1;
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->__VstlDidInit))))) {
        vlSelf->__VstlDidInit = 1U;
        vlSelf->__VstlTriggered.at(1U) = 1U;
        vlSelf->__VstlTriggered.at(2U) = 1U;
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vsim_top___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
