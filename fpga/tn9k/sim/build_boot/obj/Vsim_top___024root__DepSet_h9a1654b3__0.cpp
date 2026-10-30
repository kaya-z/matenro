// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsim_top.h for the primary calling header

#include "verilated.h"

#include "Vsim_top___024root.h"

VL_INLINE_OPT void Vsim_top___024root___act_sequent__TOP__0(Vsim_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___act_sequent__TOP__0\n"); );
    // Init
    SData/*15:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__EXGTFRRegister__36__Vfuncout;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__EXGTFRRegister__36__Vfuncout = 0;
    CData/*3:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__EXGTFRRegister__36__regid;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__EXGTFRRegister__36__regid = 0;
    SData/*15:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__EXGTFRRegister__37__Vfuncout;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__EXGTFRRegister__37__Vfuncout = 0;
    CData/*3:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__EXGTFRRegister__37__regid;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__EXGTFRRegister__37__regid = 0;
    // Body
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__EXGTFRRegister__36__regid 
        = (0xfU & ((IData)(vlSelf->dbg_din) >> 4U));
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__EXGTFRRegister__36__Vfuncout 
        = ((8U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__EXGTFRRegister__36__regid))
            ? ((4U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__EXGTFRRegister__36__regid))
                ? 0U : ((2U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__EXGTFRRegister__36__regid))
                         ? ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__EXGTFRRegister__36__regid))
                             ? (0xff00U | (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__dp))
                             : (0xff00U | (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc)))
                         : ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__EXGTFRRegister__36__regid))
                             ? (0xff00U | (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__b))
                             : (0xff00U | (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__a)))))
            : ((4U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__EXGTFRRegister__36__regid))
                ? ((2U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__EXGTFRRegister__36__regid))
                    ? 0U : ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__EXGTFRRegister__36__regid))
                             ? (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_p1)
                             : (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s)))
                : ((2U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__EXGTFRRegister__36__regid))
                    ? ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__EXGTFRRegister__36__regid))
                        ? (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u)
                        : (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__y))
                    : ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__EXGTFRRegister__36__regid))
                        ? (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__x)
                        : (((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__a) 
                            << 8U) | (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__b))))));
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__EXGTFRRegA 
        = __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__EXGTFRRegister__36__Vfuncout;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__EXGTFRRegister__37__regid 
        = (0xfU & (IData)(vlSelf->dbg_din));
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__EXGTFRRegister__37__Vfuncout 
        = ((8U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__EXGTFRRegister__37__regid))
            ? ((4U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__EXGTFRRegister__37__regid))
                ? 0U : ((2U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__EXGTFRRegister__37__regid))
                         ? ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__EXGTFRRegister__37__regid))
                             ? (0xff00U | (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__dp))
                             : (0xff00U | (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc)))
                         : ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__EXGTFRRegister__37__regid))
                             ? (0xff00U | (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__b))
                             : (0xff00U | (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__a)))))
            : ((4U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__EXGTFRRegister__37__regid))
                ? ((2U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__EXGTFRRegister__37__regid))
                    ? 0U : ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__EXGTFRRegister__37__regid))
                             ? (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_p1)
                             : (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s)))
                : ((2U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__EXGTFRRegister__37__regid))
                    ? ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__EXGTFRRegister__37__regid))
                        ? (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u)
                        : (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__y))
                    : ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__EXGTFRRegister__37__regid))
                        ? (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__x)
                        : (((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__a) 
                            << 8U) | (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__b))))));
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__EXGTFRRegB 
        = __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__EXGTFRRegister__37__Vfuncout;
}

VL_INLINE_OPT void Vsim_top___024root___act_comb__TOP__0(Vsim_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___act_comb__TOP__0\n"); );
    // Init
    CData/*0:0*/ sim_top__DOT__soc__DOT__cpu__DOT__RnWOut;
    sim_top__DOT__soc__DOT__cpu__DOT__RnWOut = 0;
    CData/*0:0*/ sim_top__DOT__soc__DOT__cpu__DOT__rLIC;
    sim_top__DOT__soc__DOT__cpu__DOT__rLIC = 0;
    SData/*15:0*/ sim_top__DOT__soc__DOT__cpu__DOT__pc_p2;
    sim_top__DOT__soc__DOT__cpu__DOT__pc_p2 = 0;
    SData/*15:0*/ sim_top__DOT__soc__DOT__cpu__DOT__pc_p3;
    sim_top__DOT__soc__DOT__cpu__DOT__pc_p3 = 0;
    SData/*15:0*/ sim_top__DOT__soc__DOT__cpu__DOT__s_p1;
    sim_top__DOT__soc__DOT__cpu__DOT__s_p1 = 0;
    SData/*15:0*/ sim_top__DOT__soc__DOT__cpu__DOT__s_m1;
    sim_top__DOT__soc__DOT__cpu__DOT__s_m1 = 0;
    SData/*15:0*/ sim_top__DOT__soc__DOT__cpu__DOT__u_p1;
    sim_top__DOT__soc__DOT__cpu__DOT__u_p1 = 0;
    SData/*15:0*/ sim_top__DOT__soc__DOT__cpu__DOT__u_m1;
    sim_top__DOT__soc__DOT__cpu__DOT__u_m1 = 0;
    SData/*15:0*/ sim_top__DOT__soc__DOT__cpu__DOT__addr_p1;
    sim_top__DOT__soc__DOT__cpu__DOT__addr_p1 = 0;
    SData/*15:0*/ sim_top__DOT__soc__DOT__cpu__DOT__ea_p1;
    sim_top__DOT__soc__DOT__cpu__DOT__ea_p1 = 0;
    CData/*2:0*/ sim_top__DOT__soc__DOT__cpu__DOT__ALU16_OP;
    sim_top__DOT__soc__DOT__cpu__DOT__ALU16_OP = 0;
    SData/*15:0*/ sim_top__DOT__soc__DOT__cpu__DOT__ALU16_A;
    sim_top__DOT__soc__DOT__cpu__DOT__ALU16_A = 0;
    SData/*15:0*/ sim_top__DOT__soc__DOT__cpu__DOT__ALU16_B;
    sim_top__DOT__soc__DOT__cpu__DOT__ALU16_B = 0;
    CData/*7:0*/ sim_top__DOT__soc__DOT__cpu__DOT__ALU16_CC;
    sim_top__DOT__soc__DOT__cpu__DOT__ALU16_CC = 0;
    CData/*7:0*/ sim_top__DOT__soc__DOT__cpu__DOT__ALU_A;
    sim_top__DOT__soc__DOT__cpu__DOT__ALU_A = 0;
    CData/*7:0*/ sim_top__DOT__soc__DOT__cpu__DOT__ALU_B;
    sim_top__DOT__soc__DOT__cpu__DOT__ALU_B = 0;
    CData/*7:0*/ sim_top__DOT__soc__DOT__cpu__DOT__ALU_CC;
    sim_top__DOT__soc__DOT__cpu__DOT__ALU_CC = 0;
    CData/*4:0*/ sim_top__DOT__soc__DOT__cpu__DOT__ALU_OP;
    sim_top__DOT__soc__DOT__cpu__DOT__ALU_OP = 0;
    IData/*23:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__Vfuncout;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__operation16;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__operation16 = 0;
    SData/*15:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__a_arg;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__a_arg = 0;
    SData/*15:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__b_arg;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__b_arg = 0;
    CData/*7:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__cc_arg;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__cc_arg = 0;
    CData/*7:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__cc_out;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__cc_out = 0;
    SData/*15:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__Vfuncout;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__Vfuncout = 0;
    CData/*4:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__operation;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__operation = 0;
    CData/*7:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__a_arg;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__a_arg = 0;
    CData/*7:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__b_arg;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__b_arg = 0;
    CData/*7:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_arg;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_arg = 0;
    CData/*7:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_out;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_out = 0;
    // Body
    sim_top__DOT__soc__DOT__cpu__DOT__rLIC = 0U;
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt = 0xffffU;
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_p1 
        = (0xffffU & ((IData)(1U) + (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc)));
    sim_top__DOT__soc__DOT__cpu__DOT__pc_p2 = (0xffffU 
                                               & ((IData)(2U) 
                                                  + (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc)));
    sim_top__DOT__soc__DOT__cpu__DOT__pc_p3 = (0xffffU 
                                               & ((IData)(3U) 
                                                  + (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc)));
    sim_top__DOT__soc__DOT__cpu__DOT__s_p1 = (0xffffU 
                                              & ((IData)(1U) 
                                                 + (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s)));
    sim_top__DOT__soc__DOT__cpu__DOT__s_m1 = (0xffffU 
                                              & ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s) 
                                                 - (IData)(1U)));
    sim_top__DOT__soc__DOT__cpu__DOT__u_p1 = (0xffffU 
                                              & ((IData)(1U) 
                                                 + (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u)));
    sim_top__DOT__soc__DOT__cpu__DOT__u_m1 = (0xffffU 
                                              & ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u) 
                                                 - (IData)(1U)));
    sim_top__DOT__soc__DOT__cpu__DOT__addr_p1 = (0xffffU 
                                                 & ((IData)(1U) 
                                                    + (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr)));
    sim_top__DOT__soc__DOT__cpu__DOT__ea_p1 = (0xffffU 
                                               & ((IData)(1U) 
                                                  + (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ea)));
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__a_nxt 
        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__a;
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__b_nxt 
        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__b;
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__x_nxt 
        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__x;
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__y_nxt 
        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__y;
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s_nxt 
        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s;
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u_nxt 
        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u;
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc_nxt 
        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc;
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__dp_nxt 
        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__dp;
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_nxt 
        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc;
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt 
        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp;
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ea_nxt 
        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ea;
    sim_top__DOT__soc__DOT__cpu__DOT__ALU_A = 0U;
    sim_top__DOT__soc__DOT__cpu__DOT__ALU_B = 0U;
    sim_top__DOT__soc__DOT__cpu__DOT__ALU_CC = 0U;
    sim_top__DOT__soc__DOT__cpu__DOT__ALU_OP = 0U;
    sim_top__DOT__soc__DOT__cpu__DOT__ALU16_OP = 0U;
    sim_top__DOT__soc__DOT__cpu__DOT__ALU16_A = 0U;
    sim_top__DOT__soc__DOT__cpu__DOT__ALU16_B = 0U;
    sim_top__DOT__soc__DOT__cpu__DOT__ALU16_CC = 0U;
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DOutput = 0U;
    sim_top__DOT__soc__DOT__cpu__DOT__RnWOut = 1U;
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1_nxt 
        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1;
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst2_nxt 
        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst2;
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__InstPage2_nxt 
        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__InstPage2;
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__InstPage3_nxt 
        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__InstPage3;
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt 
        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState;
    if ((0x40U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
        if ((0x20U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
            if ((0x10U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 4U;
                } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 4U;
                } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt = 0xffffU;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                        sim_top__DOT__soc__DOT__cpu__DOT__rLIC = 1U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 4U;
                    } else {
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt = 0xffffU;
                        sim_top__DOT__soc__DOT__cpu__DOT__rLIC = 1U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 4U;
                    }
                } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt = 0xffffU;
                    sim_top__DOT__soc__DOT__cpu__DOT__rLIC = 1U;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 0U;
                    if ((1U & (~ (((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__NMILatched) 
                                   & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__FIRQLatched)) 
                                  & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IRQLatched))))) {
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x72U;
                    }
                } else {
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt = 0xffffU;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 4U;
                }
            } else if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 0U;
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt = 0xffffU;
                            sim_top__DOT__soc__DOT__cpu__DOT__rLIC = 1U;
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt 
                                = ((0xfff0U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt)) 
                                   | (0xfU & ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp) 
                                              - (IData)(1U))));
                            if (((0U == (0xfU & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp))) 
                                 | (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DMABREQSample2))) {
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x70U;
                            }
                        } else {
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt = 0xffffU;
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 0U;
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x6eU;
                            if (vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__NMILatched) {
                                if ((1U & ((~ (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__FIRQLatched)) 
                                           & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc) 
                                                 >> 6U))))) {
                                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc_nxt 
                                        = (0x40U | (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc_nxt));
                                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x5bU;
                                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc_nxt 
                                        = (0x10U | (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc_nxt));
                                } else if ((1U & ((~ (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IRQLatched)) 
                                                  & (~ 
                                                     ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc) 
                                                      >> 4U))))) {
                                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc_nxt 
                                        = (0x10U | (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc_nxt));
                                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x5bU;
                                }
                            } else {
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc_nxt 
                                    = (0x40U | (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc_nxt));
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x5bU;
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc_nxt 
                                    = (0x10U | (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc_nxt));
                            }
                        }
                    } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt = 0xffffU;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x53U;
                    } else {
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                            = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc_nxt 
                            = (0x80U | (0x7fU & ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc) 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst2))));
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt = 0xffU;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 0U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x6dU;
                    }
                } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt = 0U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x69U;
                    } else {
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                            = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x6bU;
                    }
                } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt = 0xdeadU;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x6aU;
                } else {
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 4U;
                }
            } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 4U;
                    } else {
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt = 0xffffU;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 4U;
                    }
                } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 4U;
                } else {
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 0U;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt = 0xffffU;
                    sim_top__DOT__soc__DOT__cpu__DOT__rLIC = 1U;
                    if (vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__HALTSample2) {
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x66U;
                    }
                }
            } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt = 0xffffU;
                    sim_top__DOT__soc__DOT__cpu__DOT__rLIC = 1U;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 4U;
                } else {
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp;
                    sim_top__DOT__soc__DOT__cpu__DOT__rLIC = 1U;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 4U;
                }
            } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt = 0xffffU;
                sim_top__DOT__soc__DOT__cpu__DOT__rLIC = 1U;
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 4U;
            } else {
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt = 0xffffU;
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 0U;
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x61U;
            }
        } else if ((0x10U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
            if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                                = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc;
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt = 0xffU;
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x58U;
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc_nxt 
                                = (0x80U | (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc_nxt));
                        } else {
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                                = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc;
                            sim_top__DOT__soc__DOT__cpu__DOT__rLIC = 1U;
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 4U;
                        }
                    } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                            = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt = 0x2081U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x58U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc_nxt 
                            = (0x7fU & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc_nxt));
                    } else {
                        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IntType))) {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IntType) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IntType))) {
                                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt = 0xfff3U;
                                    sim_top__DOT__soc__DOT__cpu__DOT__rLIC = 1U;
                                } else {
                                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt = 0xfff5U;
                                    sim_top__DOT__soc__DOT__cpu__DOT__rLIC = 1U;
                                }
                            }
                        } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IntType))) {
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IntType))) {
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt = 0xfffbU;
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc_nxt 
                                    = (0x40U | (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc_nxt));
                                sim_top__DOT__soc__DOT__cpu__DOT__rLIC = 1U;
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc_nxt 
                                    = (0x10U | (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc_nxt));
                            } else {
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt = 0xfff7U;
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc_nxt 
                                    = (0x40U | (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc_nxt));
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc_nxt 
                                    = (0x10U | (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc_nxt));
                            }
                        } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IntType))) {
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt = 0xfff9U;
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc_nxt 
                                = (0x10U | (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc_nxt));
                        } else {
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt = 0xfffdU;
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc_nxt 
                                = (0x10U | (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc_nxt));
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc_nxt 
                                = (0x40U | (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc_nxt));
                        }
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_nxt 
                            = ((0xff00U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_nxt)) 
                               | (IData)(vlSelf->dbg_din));
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x73U;
                        sim_top__DOT__soc__DOT__cpu__DOT__rLIC = 1U;
                    }
                } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                            = ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IntType))
                                ? ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IntType))
                                    ? 0xfff8U : ((1U 
                                                  & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IntType))
                                                  ? 0xfff2U
                                                  : 0xfff4U))
                                : ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IntType))
                                    ? ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IntType))
                                        ? 0xfffaU : 0xfff6U)
                                    : ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IntType))
                                        ? 0xfff8U : 0xfffcU)));
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_nxt 
                            = ((0xffU & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_nxt)) 
                               | ((IData)(vlSelf->dbg_din) 
                                  << 8U));
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                        sim_top__DOT__soc__DOT__cpu__DOT__rLIC = 1U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x5cU;
                    } else {
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt = 0xffffU;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x5bU;
                        sim_top__DOT__soc__DOT__cpu__DOT__rLIC = 1U;
                    }
                } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt = 0x20ffU;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x58U;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc_nxt 
                        = (0x80U | (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc_nxt));
                } else {
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt = 0xffffU;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x53U;
                }
            } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                            = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt = 0x20ffU;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 0U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x58U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc_nxt 
                            = (0x80U | (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc_nxt));
                    } else {
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp))) {
                            if ((0x4000U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp))) {
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                                    = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u;
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u_nxt 
                                    = sim_top__DOT__soc__DOT__cpu__DOT__u_p1;
                            } else {
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                                    = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s;
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s_nxt 
                                    = sim_top__DOT__soc__DOT__cpu__DOT__s_p1;
                            }
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc_nxt 
                                = vlSelf->dbg_din;
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt 
                                = ((0x1000U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp))
                                    ? ((0xff00U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt)) 
                                       | ((0x80U & (IData)(vlSelf->dbg_din))
                                           ? 0xfeU : 0x80U))
                                    : (0xfffeU & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt)));
                        } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp))) {
                            if ((0x4000U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp))) {
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                                    = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u;
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u_nxt 
                                    = sim_top__DOT__soc__DOT__cpu__DOT__u_p1;
                            } else {
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                                    = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s;
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s_nxt 
                                    = sim_top__DOT__soc__DOT__cpu__DOT__s_p1;
                            }
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__a_nxt 
                                = vlSelf->dbg_din;
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt 
                                = (0xfffdU & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt));
                        } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp))) {
                            if ((0x4000U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp))) {
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                                    = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u;
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u_nxt 
                                    = sim_top__DOT__soc__DOT__cpu__DOT__u_p1;
                            } else {
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                                    = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s;
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s_nxt 
                                    = sim_top__DOT__soc__DOT__cpu__DOT__s_p1;
                            }
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__b_nxt 
                                = vlSelf->dbg_din;
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt 
                                = (0xfffbU & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt));
                        } else if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp))) {
                            if ((0x4000U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp))) {
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                                    = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u;
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u_nxt 
                                    = sim_top__DOT__soc__DOT__cpu__DOT__u_p1;
                            } else {
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                                    = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s;
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s_nxt 
                                    = sim_top__DOT__soc__DOT__cpu__DOT__s_p1;
                            }
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__dp_nxt 
                                = vlSelf->dbg_din;
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt 
                                = (0xfff7U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt));
                        } else if ((IData)((0x10U == 
                                            (0x8010U 
                                             & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp))))) {
                            if ((0x4000U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp))) {
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                                    = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u;
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u_nxt 
                                    = sim_top__DOT__soc__DOT__cpu__DOT__u_p1;
                            } else {
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                                    = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s;
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s_nxt 
                                    = sim_top__DOT__soc__DOT__cpu__DOT__s_p1;
                            }
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__x_nxt 
                                = ((0xffU & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__x_nxt)) 
                                   | ((IData)(vlSelf->dbg_din) 
                                      << 8U));
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt 
                                = (0x8000U | (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt));
                        } else if ((IData)((0x8010U 
                                            == (0x8010U 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp))))) {
                            if ((0x4000U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp))) {
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                                    = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u;
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u_nxt 
                                    = sim_top__DOT__soc__DOT__cpu__DOT__u_p1;
                            } else {
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                                    = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s;
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s_nxt 
                                    = sim_top__DOT__soc__DOT__cpu__DOT__s_p1;
                            }
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__x_nxt 
                                = ((0xff00U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__x_nxt)) 
                                   | (IData)(vlSelf->dbg_din));
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt 
                                = (0xffefU & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt));
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt 
                                = (0x7fffU & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt));
                        } else if ((IData)((0x20U == 
                                            (0x8020U 
                                             & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp))))) {
                            if ((0x4000U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp))) {
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                                    = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u;
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u_nxt 
                                    = sim_top__DOT__soc__DOT__cpu__DOT__u_p1;
                            } else {
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                                    = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s;
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s_nxt 
                                    = sim_top__DOT__soc__DOT__cpu__DOT__s_p1;
                            }
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__y_nxt 
                                = ((0xffU & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__y_nxt)) 
                                   | ((IData)(vlSelf->dbg_din) 
                                      << 8U));
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt 
                                = (0x8000U | (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt));
                        } else if ((IData)((0x8020U 
                                            == (0x8020U 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp))))) {
                            if ((0x4000U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp))) {
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                                    = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u;
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u_nxt 
                                    = sim_top__DOT__soc__DOT__cpu__DOT__u_p1;
                            } else {
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                                    = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s;
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s_nxt 
                                    = sim_top__DOT__soc__DOT__cpu__DOT__s_p1;
                            }
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__y_nxt 
                                = ((0xff00U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__y_nxt)) 
                                   | (IData)(vlSelf->dbg_din));
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt 
                                = (0xffdfU & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt));
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt 
                                = (0x7fffU & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt));
                        } else if ((IData)((0x40U == 
                                            (0x8040U 
                                             & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp))))) {
                            if ((0x4000U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp))) {
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                                    = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u;
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u_nxt 
                                    = sim_top__DOT__soc__DOT__cpu__DOT__u_p1;
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s_nxt 
                                    = ((0xffU & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s_nxt)) 
                                       | ((IData)(vlSelf->dbg_din) 
                                          << 8U));
                            } else {
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                                    = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s;
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s_nxt 
                                    = sim_top__DOT__soc__DOT__cpu__DOT__s_p1;
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u_nxt 
                                    = ((0xffU & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u_nxt)) 
                                       | ((IData)(vlSelf->dbg_din) 
                                          << 8U));
                            }
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt 
                                = (0x8000U | (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt));
                        } else if ((IData)((0x8040U 
                                            == (0x8040U 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp))))) {
                            if ((0x4000U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp))) {
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                                    = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u;
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u_nxt 
                                    = sim_top__DOT__soc__DOT__cpu__DOT__u_p1;
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s_nxt 
                                    = ((0xff00U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s_nxt)) 
                                       | (IData)(vlSelf->dbg_din));
                            } else {
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                                    = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s;
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s_nxt 
                                    = sim_top__DOT__soc__DOT__cpu__DOT__s_p1;
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u_nxt 
                                    = ((0xff00U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u_nxt)) 
                                       | (IData)(vlSelf->dbg_din));
                            }
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt 
                                = (0xffbfU & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt));
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt 
                                = (0x7fffU & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt));
                        } else if ((IData)((0x80U == 
                                            (0x8080U 
                                             & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp))))) {
                            if ((0x4000U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp))) {
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                                    = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u;
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u_nxt 
                                    = sim_top__DOT__soc__DOT__cpu__DOT__u_p1;
                            } else {
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                                    = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s;
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s_nxt 
                                    = sim_top__DOT__soc__DOT__cpu__DOT__s_p1;
                            }
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_nxt 
                                = ((0xffU & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_nxt)) 
                                   | ((IData)(vlSelf->dbg_din) 
                                      << 8U));
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt 
                                = (0x8000U | (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt));
                        } else if ((IData)((0x8080U 
                                            == (0x8080U 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp))))) {
                            if ((0x4000U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp))) {
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                                    = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u;
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u_nxt 
                                    = sim_top__DOT__soc__DOT__cpu__DOT__u_p1;
                            } else {
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                                    = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s;
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s_nxt 
                                    = sim_top__DOT__soc__DOT__cpu__DOT__s_p1;
                            }
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_nxt 
                                = ((0xff00U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_nxt)) 
                                   | (IData)(vlSelf->dbg_din));
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt 
                                = (0xff7fU & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt));
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt 
                                = (0x7fffU & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt));
                        } else {
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                                = ((0x4000U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp))
                                    ? (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u)
                                    : (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s));
                            if ((4U == (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__NextState))) {
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                                sim_top__DOT__soc__DOT__cpu__DOT__rLIC = 1U;
                            } else {
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 0U;
                            }
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt 
                                = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__NextState;
                        }
                    }
                } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt = 0xffffU;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x56U;
                } else {
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt = 0xffffU;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 0U;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x55U;
                }
            } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                    if ((IData)((0x80U == (0x8080U 
                                           & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp))))) {
                        if ((0x4000U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp))) {
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                                = sim_top__DOT__soc__DOT__cpu__DOT__u_m1;
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u_nxt 
                                = sim_top__DOT__soc__DOT__cpu__DOT__u_m1;
                        } else {
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                                = sim_top__DOT__soc__DOT__cpu__DOT__s_m1;
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s_nxt 
                                = sim_top__DOT__soc__DOT__cpu__DOT__s_m1;
                        }
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DOutput 
                            = (0xffU & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc));
                        sim_top__DOT__soc__DOT__cpu__DOT__RnWOut = 0U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt 
                            = (0x8000U | (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt));
                    } else if ((IData)((0x8080U == 
                                        (0x8080U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp))))) {
                        if ((0x4000U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp))) {
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                                = sim_top__DOT__soc__DOT__cpu__DOT__u_m1;
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u_nxt 
                                = sim_top__DOT__soc__DOT__cpu__DOT__u_m1;
                        } else {
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                                = sim_top__DOT__soc__DOT__cpu__DOT__s_m1;
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s_nxt 
                                = sim_top__DOT__soc__DOT__cpu__DOT__s_m1;
                        }
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DOutput 
                            = (0xffU & ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc) 
                                        >> 8U));
                        sim_top__DOT__soc__DOT__cpu__DOT__RnWOut = 0U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt 
                            = (0xff7fU & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt));
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt 
                            = (0x7fffU & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt));
                    } else if ((IData)((0x40U == (0x8040U 
                                                  & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp))))) {
                        if ((0x4000U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp))) {
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                                = sim_top__DOT__soc__DOT__cpu__DOT__u_m1;
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DOutput 
                                = (0xffU & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s));
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u_nxt 
                                = sim_top__DOT__soc__DOT__cpu__DOT__u_m1;
                        } else {
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                                = sim_top__DOT__soc__DOT__cpu__DOT__s_m1;
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DOutput 
                                = (0xffU & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u));
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s_nxt 
                                = sim_top__DOT__soc__DOT__cpu__DOT__s_m1;
                        }
                        sim_top__DOT__soc__DOT__cpu__DOT__RnWOut = 0U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt 
                            = (0x8000U | (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt));
                    } else if ((IData)((0x8040U == 
                                        (0x8040U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp))))) {
                        if ((0x4000U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp))) {
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                                = sim_top__DOT__soc__DOT__cpu__DOT__u_m1;
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DOutput 
                                = (0xffU & ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s) 
                                            >> 8U));
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u_nxt 
                                = sim_top__DOT__soc__DOT__cpu__DOT__u_m1;
                        } else {
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                                = sim_top__DOT__soc__DOT__cpu__DOT__s_m1;
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DOutput 
                                = (0xffU & ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u) 
                                            >> 8U));
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s_nxt 
                                = sim_top__DOT__soc__DOT__cpu__DOT__s_m1;
                        }
                        sim_top__DOT__soc__DOT__cpu__DOT__RnWOut = 0U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt 
                            = (0xffbfU & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt));
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt 
                            = (0x7fffU & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt));
                    } else if ((IData)((0x20U == (0x8020U 
                                                  & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp))))) {
                        if ((0x4000U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp))) {
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                                = sim_top__DOT__soc__DOT__cpu__DOT__u_m1;
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u_nxt 
                                = sim_top__DOT__soc__DOT__cpu__DOT__u_m1;
                        } else {
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                                = sim_top__DOT__soc__DOT__cpu__DOT__s_m1;
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s_nxt 
                                = sim_top__DOT__soc__DOT__cpu__DOT__s_m1;
                        }
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DOutput 
                            = (0xffU & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__y));
                        sim_top__DOT__soc__DOT__cpu__DOT__RnWOut = 0U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt 
                            = (0x8000U | (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt));
                    } else if ((IData)((0x8020U == 
                                        (0x8020U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp))))) {
                        if ((0x4000U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp))) {
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                                = sim_top__DOT__soc__DOT__cpu__DOT__u_m1;
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u_nxt 
                                = sim_top__DOT__soc__DOT__cpu__DOT__u_m1;
                        } else {
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                                = sim_top__DOT__soc__DOT__cpu__DOT__s_m1;
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s_nxt 
                                = sim_top__DOT__soc__DOT__cpu__DOT__s_m1;
                        }
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DOutput 
                            = (0xffU & ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__y) 
                                        >> 8U));
                        sim_top__DOT__soc__DOT__cpu__DOT__RnWOut = 0U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt 
                            = (0xffdfU & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt));
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt 
                            = (0x7fffU & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt));
                    } else if ((IData)((0x10U == (0x8010U 
                                                  & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp))))) {
                        if ((0x4000U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp))) {
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                                = sim_top__DOT__soc__DOT__cpu__DOT__u_m1;
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u_nxt 
                                = sim_top__DOT__soc__DOT__cpu__DOT__u_m1;
                        } else {
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                                = sim_top__DOT__soc__DOT__cpu__DOT__s_m1;
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s_nxt 
                                = sim_top__DOT__soc__DOT__cpu__DOT__s_m1;
                        }
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DOutput 
                            = (0xffU & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__x));
                        sim_top__DOT__soc__DOT__cpu__DOT__RnWOut = 0U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt 
                            = (0x8000U | (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt));
                    } else if ((IData)((0x8010U == 
                                        (0x8010U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp))))) {
                        if ((0x4000U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp))) {
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                                = sim_top__DOT__soc__DOT__cpu__DOT__u_m1;
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u_nxt 
                                = sim_top__DOT__soc__DOT__cpu__DOT__u_m1;
                        } else {
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                                = sim_top__DOT__soc__DOT__cpu__DOT__s_m1;
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s_nxt 
                                = sim_top__DOT__soc__DOT__cpu__DOT__s_m1;
                        }
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DOutput 
                            = (0xffU & ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__x) 
                                        >> 8U));
                        sim_top__DOT__soc__DOT__cpu__DOT__RnWOut = 0U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt 
                            = (0xffefU & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt));
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt 
                            = (0x7fffU & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt));
                    } else if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp))) {
                        if ((0x4000U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp))) {
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                                = sim_top__DOT__soc__DOT__cpu__DOT__u_m1;
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u_nxt 
                                = sim_top__DOT__soc__DOT__cpu__DOT__u_m1;
                        } else {
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                                = sim_top__DOT__soc__DOT__cpu__DOT__s_m1;
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s_nxt 
                                = sim_top__DOT__soc__DOT__cpu__DOT__s_m1;
                        }
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DOutput 
                            = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__dp;
                        sim_top__DOT__soc__DOT__cpu__DOT__RnWOut = 0U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt 
                            = (0xfff7U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt));
                    } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp))) {
                        if ((0x4000U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp))) {
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                                = sim_top__DOT__soc__DOT__cpu__DOT__u_m1;
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u_nxt 
                                = sim_top__DOT__soc__DOT__cpu__DOT__u_m1;
                        } else {
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                                = sim_top__DOT__soc__DOT__cpu__DOT__s_m1;
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s_nxt 
                                = sim_top__DOT__soc__DOT__cpu__DOT__s_m1;
                        }
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DOutput 
                            = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__b;
                        sim_top__DOT__soc__DOT__cpu__DOT__RnWOut = 0U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt 
                            = (0xfffbU & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt));
                    } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp))) {
                        if ((0x4000U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp))) {
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                                = sim_top__DOT__soc__DOT__cpu__DOT__u_m1;
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u_nxt 
                                = sim_top__DOT__soc__DOT__cpu__DOT__u_m1;
                        } else {
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                                = sim_top__DOT__soc__DOT__cpu__DOT__s_m1;
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s_nxt 
                                = sim_top__DOT__soc__DOT__cpu__DOT__s_m1;
                        }
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DOutput 
                            = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__a;
                        sim_top__DOT__soc__DOT__cpu__DOT__RnWOut = 0U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt 
                            = (0xfffdU & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt));
                    } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp))) {
                        if ((0x4000U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp))) {
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                                = sim_top__DOT__soc__DOT__cpu__DOT__u_m1;
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u_nxt 
                                = sim_top__DOT__soc__DOT__cpu__DOT__u_m1;
                        } else {
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                                = sim_top__DOT__soc__DOT__cpu__DOT__s_m1;
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s_nxt 
                                = sim_top__DOT__soc__DOT__cpu__DOT__s_m1;
                        }
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DOutput 
                            = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc;
                        sim_top__DOT__soc__DOT__cpu__DOT__RnWOut = 0U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt 
                            = (0xfffeU & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt));
                    }
                    if ((0x2000U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp))) {
                        sim_top__DOT__soc__DOT__cpu__DOT__rLIC = 1U;
                    }
                    if ((0U == (0xffU & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt)))) {
                        if ((4U == (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__NextState))) {
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                            sim_top__DOT__soc__DOT__cpu__DOT__rLIC = 1U;
                        } else {
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 0U;
                        }
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt 
                            = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__NextState;
                    }
                } else {
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                        = ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1))
                            ? (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u)
                            : (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s));
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x53U;
                }
            } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt = 0xffffU;
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x52U;
            } else {
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt = 0xffffU;
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 0U;
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x51U;
            }
        } else if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
            if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 4U;
                } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt = 0xffffU;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 0U;
                    if ((0U != (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__a))) {
                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__b))) {
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt 
                                = (0xffffU & ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp) 
                                              + (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ea)));
                        }
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ea_nxt 
                            = (0xfffeU & ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ea) 
                                          << 1U));
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__b_nxt 
                            = (0x7fU & ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__b) 
                                        >> 1U));
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__a_nxt 
                            = (0xffU & ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__a) 
                                        - (IData)(1U)));
                    } else {
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__a_nxt 
                            = (0xffU & ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp) 
                                        >> 8U));
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__b_nxt 
                            = (0xffU & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp));
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc_nxt 
                            = ((0xfbU & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc_nxt)) 
                               | ((0U == (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp)) 
                                  << 2U));
                        sim_top__DOT__soc__DOT__cpu__DOT__rLIC = 1U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 4U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc_nxt 
                            = ((0xfeU & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc_nxt)) 
                               | (1U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp) 
                                        >> 7U)));
                    }
                } else {
                    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__38__inst 
                        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt = 0xffffU;
                    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__38__hi 
                        = (0xfU & ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__38__inst) 
                                   >> 4U));
                    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__38__lo 
                        = (0xfU & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__38__inst));
                    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__38__Vfuncout = 0U;
                    if ((((0U == (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__38__hi)) 
                          | (6U == (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__38__hi))) 
                         | (7U == (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__38__hi)))) {
                        if ((0xeU == (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__38__lo))) {
                            vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__38__Vfuncout = 1U;
                        }
                    }
                    if (vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__38__Vfuncout) {
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_nxt 
                            = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ea;
                        sim_top__DOT__soc__DOT__cpu__DOT__rLIC = 1U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 4U;
                    } else {
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x2cU;
                    }
                }
            } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                        = sim_top__DOT__soc__DOT__cpu__DOT__ea_p1;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ea_nxt 
                        = ((0xff00U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt)) 
                           | (IData)(vlSelf->dbg_din));
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 0U;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x4cU;
                } else {
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ea;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt 
                        = ((0xffU & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt)) 
                           | ((IData)(vlSelf->dbg_din) 
                              << 8U));
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x4bU;
                }
            } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                    = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc;
                if (vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IndexedIndirect) {
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x4aU;
                } else {
                    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__39__inst 
                        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1;
                    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__39__hi 
                        = (0xfU & ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__39__inst) 
                                   >> 4U));
                    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__39__lo 
                        = (0xfU & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__39__inst));
                    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__39__Vfuncout = 0U;
                    if ((((0U == (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__39__hi)) 
                          | (6U == (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__39__hi))) 
                         | (7U == (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__39__hi)))) {
                        if ((0xeU == (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__39__lo))) {
                            vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__39__Vfuncout = 1U;
                        }
                    }
                    if (vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__39__Vfuncout) {
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_nxt 
                            = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ea;
                        sim_top__DOT__soc__DOT__cpu__DOT__rLIC = 1U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 4U;
                    } else {
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x2cU;
                    }
                }
            } else {
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ea_nxt 
                    = ((0xff00U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ea_nxt)) 
                       | (IData)(vlSelf->dbg_din));
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                    = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc;
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_nxt 
                    = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_p1;
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x49U;
            }
        } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt = 0xffffU;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 0U;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x42U;
                } else {
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                        = sim_top__DOT__soc__DOT__cpu__DOT__pc_p3;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x45U;
                }
            } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                    = sim_top__DOT__soc__DOT__cpu__DOT__pc_p2;
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 0U;
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x41U;
            } else {
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                    = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_p1;
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x45U;
            }
        } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 4U;
            } else {
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt = 0xffffU;
                if (vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IndexedIndirect) {
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x4aU;
                } else {
                    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__40__inst 
                        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1;
                    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__40__hi 
                        = (0xfU & ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__40__inst) 
                                   >> 4U));
                    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__40__lo 
                        = (0xfU & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__40__inst));
                    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__40__Vfuncout = 0U;
                    if ((((0U == (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__40__hi)) 
                          | (6U == (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__40__hi))) 
                         | (7U == (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__40__hi)))) {
                        if ((0xeU == (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__40__lo))) {
                            vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__40__Vfuncout = 1U;
                        }
                    }
                    if (vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__40__Vfuncout) {
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_nxt 
                            = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ea;
                        sim_top__DOT__soc__DOT__cpu__DOT__rLIC = 1U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 4U;
                    } else {
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x2cU;
                    }
                }
            }
        } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt = 0xffffU;
            if ((4U == (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IndexedRegister))) {
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 0U;
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x47U;
            } else {
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 0U;
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x42U;
            }
        } else {
            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc;
            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 0U;
            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x41U;
        }
    } else if ((0x20U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
        if ((0x10U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
            if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt = 0xffffU;
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 0U;
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x41U;
                        } else {
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_nxt 
                                = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_p1;
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                                = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc;
                            sim_top__DOT__soc__DOT__cpu__DOT__ALU16_A 
                                = ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IndexedRegister))
                                    ? ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IndexedRegister))
                                        ? (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__x)
                                        : ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IndexedRegister))
                                            ? (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__x)
                                            : (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_nxt)))
                                    : ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IndexedRegister))
                                        ? ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IndexedRegister))
                                            ? (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s)
                                            : (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u))
                                        : ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IndexedRegister))
                                            ? (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__y)
                                            : (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__x))));
                            sim_top__DOT__soc__DOT__cpu__DOT__ALU16_OP = 1U;
                            sim_top__DOT__soc__DOT__cpu__DOT__ALU16_B 
                                = ((0xff00U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp)) 
                                   | (IData)(vlSelf->dbg_din));
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ea_nxt 
                                = (0xffffU & vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16);
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x40U;
                        }
                    } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt 
                            = ((0xff00U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt)) 
                               | (IData)(vlSelf->dbg_din));
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                            = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_nxt 
                            = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_p1;
                        sim_top__DOT__soc__DOT__cpu__DOT__ALU16_B 
                            = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt;
                        sim_top__DOT__soc__DOT__cpu__DOT__ALU16_A 
                            = ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IndexedRegister))
                                ? ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IndexedRegister))
                                    ? 0U : ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IndexedRegister))
                                             ? 0U : (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc)))
                                : ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IndexedRegister))
                                    ? ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IndexedRegister))
                                        ? (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s)
                                        : (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u))
                                    : ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IndexedRegister))
                                        ? (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__y)
                                        : (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__x))));
                        sim_top__DOT__soc__DOT__cpu__DOT__ALU16_OP = 1U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ea_nxt 
                            = (0xffffU & vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16);
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x40U;
                    } else {
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt = 0xffffU;
                        if (vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IndexedIndirect) {
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x4aU;
                        } else {
                            vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__41__inst 
                                = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1;
                            vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__41__hi 
                                = (0xfU & ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__41__inst) 
                                           >> 4U));
                            vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__41__lo 
                                = (0xfU & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__41__inst));
                            vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__41__Vfuncout = 0U;
                            if ((((0U == (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__41__hi)) 
                                  | (6U == (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__41__hi))) 
                                 | (7U == (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__41__hi)))) {
                                if ((0xeU == (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__41__lo))) {
                                    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__41__Vfuncout = 1U;
                                }
                            }
                            if (vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__41__Vfuncout) {
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_nxt 
                                    = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ea;
                                sim_top__DOT__soc__DOT__cpu__DOT__rLIC = 1U;
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 4U;
                            } else {
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x2cU;
                            }
                        }
                    }
                } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 4U;
                    } else {
                        sim_top__DOT__soc__DOT__cpu__DOT__ALU16_A 
                            = ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IndexedRegister))
                                ? ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IndexedRegister))
                                    ? 0U : ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IndexedRegister))
                                             ? 0U : (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_p1)))
                                : ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IndexedRegister))
                                    ? ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IndexedRegister))
                                        ? (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s)
                                        : (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u))
                                    : ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IndexedRegister))
                                        ? (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__y)
                                        : (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__x))));
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                            = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc;
                        sim_top__DOT__soc__DOT__cpu__DOT__ALU16_OP = 1U;
                        if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IndexedMode))) {
                            if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IndexedMode))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IndexedMode))) {
                                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IndexedMode))) {
                                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ea_nxt 
                                            = ((0xffU 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ea_nxt)) 
                                               | ((IData)(vlSelf->dbg_din) 
                                                  << 8U));
                                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_nxt 
                                            = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_p1;
                                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x48U;
                                    } else {
                                        sim_top__DOT__soc__DOT__cpu__DOT__rLIC = 1U;
                                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 4U;
                                    }
                                } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IndexedMode))) {
                                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt 
                                        = ((0xffU & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt)) 
                                           | ((IData)(vlSelf->dbg_din) 
                                              << 8U));
                                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_nxt 
                                        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_p1;
                                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x3eU;
                                } else {
                                    sim_top__DOT__soc__DOT__cpu__DOT__ALU16_B 
                                        = ((0xff00U 
                                            & ((- (IData)(
                                                          (1U 
                                                           & ((IData)(vlSelf->dbg_din) 
                                                              >> 7U)))) 
                                               << 8U)) 
                                           | (IData)(vlSelf->dbg_din));
                                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_nxt 
                                        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_p1;
                                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ea_nxt 
                                        = (0xffffU 
                                           & vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16);
                                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 0U;
                                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x3cU;
                                }
                            } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IndexedMode))) {
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IndexedMode))) {
                                    sim_top__DOT__soc__DOT__cpu__DOT__ALU16_B 
                                        = (((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__a) 
                                            << 8U) 
                                           | (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__b));
                                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ea_nxt 
                                        = (0xffffU 
                                           & vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16);
                                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x44U;
                                } else {
                                    sim_top__DOT__soc__DOT__cpu__DOT__rLIC = 1U;
                                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 4U;
                                }
                            } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IndexedMode))) {
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt 
                                    = ((0xffU & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt)) 
                                       | ((IData)(vlSelf->dbg_din) 
                                          << 8U));
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_nxt 
                                    = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_p1;
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x3eU;
                            } else {
                                sim_top__DOT__soc__DOT__cpu__DOT__ALU16_B 
                                    = ((0xff00U & (
                                                   (- (IData)(
                                                              (1U 
                                                               & ((IData)(vlSelf->dbg_din) 
                                                                  >> 7U)))) 
                                                   << 8U)) 
                                       | (IData)(vlSelf->dbg_din));
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_nxt 
                                    = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_p1;
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ea_nxt 
                                    = (0xffffU & vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16);
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 0U;
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x3cU;
                            }
                        } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IndexedMode))) {
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IndexedMode))) {
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IndexedMode))) {
                                    sim_top__DOT__soc__DOT__cpu__DOT__ALU16_B 
                                        = ((0xffe0U 
                                            & ((- (IData)(
                                                          (1U 
                                                           & ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst2) 
                                                              >> 4U)))) 
                                               << 5U)) 
                                           | (0x1fU 
                                              & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst2)));
                                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ea_nxt 
                                        = (0xffffU 
                                           & vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16);
                                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 0U;
                                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x3cU;
                                } else {
                                    sim_top__DOT__soc__DOT__cpu__DOT__ALU16_B 
                                        = ((0xff00U 
                                            & ((- (IData)(
                                                          (1U 
                                                           & ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__a) 
                                                              >> 7U)))) 
                                               << 8U)) 
                                           | (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__a));
                                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 0U;
                                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x3cU;
                                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ea_nxt 
                                        = (0xffffU 
                                           & vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16);
                                }
                            } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IndexedMode))) {
                                sim_top__DOT__soc__DOT__cpu__DOT__ALU16_B 
                                    = ((0xff00U & (
                                                   (- (IData)(
                                                              (1U 
                                                               & ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__b) 
                                                                  >> 7U)))) 
                                                   << 8U)) 
                                       | (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__b));
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 0U;
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x3cU;
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ea_nxt 
                                    = (0xffffU & vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16);
                            } else {
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ea_nxt 
                                    = ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IndexedRegister))
                                        ? 0U : ((2U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IndexedRegister))
                                                 ? 
                                                ((1U 
                                                  & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IndexedRegister))
                                                  ? (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s)
                                                  : (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u))
                                                 : 
                                                ((1U 
                                                  & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IndexedRegister))
                                                  ? (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__y)
                                                  : (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__x))));
                                if (vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IndexedIndirect) {
                                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x4aU;
                                } else {
                                    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__42__inst 
                                        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1;
                                    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__42__hi 
                                        = (0xfU & ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__42__inst) 
                                                   >> 4U));
                                    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__42__lo 
                                        = (0xfU & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__42__inst));
                                    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__42__Vfuncout = 0U;
                                    if ((((0U == (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__42__hi)) 
                                          | (6U == (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__42__hi))) 
                                         | (7U == (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__42__hi)))) {
                                        if ((0xeU == (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__42__lo))) {
                                            vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__42__Vfuncout = 1U;
                                        }
                                    }
                                    if (vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__42__Vfuncout) {
                                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_nxt 
                                            = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ea_nxt;
                                        sim_top__DOT__soc__DOT__cpu__DOT__rLIC = 1U;
                                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 4U;
                                    } else {
                                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x2cU;
                                    }
                                }
                            }
                        } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IndexedMode))) {
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IndexedMode))) {
                                sim_top__DOT__soc__DOT__cpu__DOT__ALU16_B = 0xfffeU;
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IndexedRegister) 
                                              >> 2U)))) {
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IndexedRegister))) {
                                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IndexedRegister))) {
                                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s_nxt 
                                                = (0xffffU 
                                                   & vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16);
                                        } else {
                                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u_nxt 
                                                = (0xffffU 
                                                   & vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16);
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IndexedRegister))) {
                                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__y_nxt 
                                            = (0xffffU 
                                               & vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16);
                                    } else {
                                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__x_nxt 
                                            = (0xffffU 
                                               & vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16);
                                    }
                                }
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ea_nxt 
                                    = (0xffffU & vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16);
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x3fU;
                            } else {
                                sim_top__DOT__soc__DOT__cpu__DOT__ALU16_B = 0xffffU;
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IndexedRegister) 
                                              >> 2U)))) {
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IndexedRegister))) {
                                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IndexedRegister))) {
                                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s_nxt 
                                                = (0xffffU 
                                                   & vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16);
                                        } else {
                                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u_nxt 
                                                = (0xffffU 
                                                   & vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16);
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IndexedRegister))) {
                                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__y_nxt 
                                            = (0xffffU 
                                               & vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16);
                                    } else {
                                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__x_nxt 
                                            = (0xffffU 
                                               & vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16);
                                    }
                                }
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ea_nxt 
                                    = (0xffffU & vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16);
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 0U;
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x41U;
                            }
                        } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IndexedMode))) {
                            sim_top__DOT__soc__DOT__cpu__DOT__ALU16_B = 2U;
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ea_nxt 
                                = sim_top__DOT__soc__DOT__cpu__DOT__ALU16_A;
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IndexedRegister) 
                                          >> 2U)))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IndexedRegister))) {
                                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IndexedRegister))) {
                                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s_nxt 
                                            = (0xffffU 
                                               & vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16);
                                    } else {
                                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u_nxt 
                                            = (0xffffU 
                                               & vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16);
                                    }
                                } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IndexedRegister))) {
                                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__y_nxt 
                                        = (0xffffU 
                                           & vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16);
                                } else {
                                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__x_nxt 
                                        = (0xffffU 
                                           & vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16);
                                }
                            }
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 0U;
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x3fU;
                        } else {
                            sim_top__DOT__soc__DOT__cpu__DOT__ALU16_B = 1U;
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ea_nxt 
                                = sim_top__DOT__soc__DOT__cpu__DOT__ALU16_A;
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IndexedRegister) 
                                          >> 2U)))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IndexedRegister))) {
                                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IndexedRegister))) {
                                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s_nxt 
                                            = (0xffffU 
                                               & vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16);
                                    } else {
                                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u_nxt 
                                            = (0xffffU 
                                               & vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16);
                                    }
                                } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IndexedRegister))) {
                                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__y_nxt 
                                        = (0xffffU 
                                           & vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16);
                                } else {
                                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__x_nxt 
                                        = (0xffffU 
                                           & vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16);
                                }
                            }
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 0U;
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x41U;
                        }
                    }
                } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__43__inst 
                        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt = 0xffffU;
                    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__43__hi 
                        = (0xfU & ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__43__inst) 
                                   >> 4U));
                    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__43__lo 
                        = (0xfU & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__43__inst));
                    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__43__Vfuncout = 0U;
                    if ((((0U == (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__43__hi)) 
                          | (6U == (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__43__hi))) 
                         | (7U == (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__43__hi)))) {
                        if ((0xeU == (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__43__lo))) {
                            vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__43__Vfuncout = 1U;
                        }
                    }
                    if (vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__43__Vfuncout) {
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_nxt 
                            = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ea;
                        sim_top__DOT__soc__DOT__cpu__DOT__rLIC = 1U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 4U;
                    } else {
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x2cU;
                    }
                } else {
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_nxt 
                        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_p1;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ea_nxt 
                        = ((0xff00U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ea_nxt)) 
                           | (IData)(vlSelf->dbg_din));
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 0U;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x39U;
                }
            } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                            = sim_top__DOT__soc__DOT__cpu__DOT__s_m1;
                        sim_top__DOT__soc__DOT__cpu__DOT__RnWOut = 0U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DOutput 
                            = (0xffU & ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp) 
                                        >> 8U));
                        sim_top__DOT__soc__DOT__cpu__DOT__rLIC = 1U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 4U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s_nxt 
                            = sim_top__DOT__soc__DOT__cpu__DOT__s_m1;
                    } else {
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                            = sim_top__DOT__soc__DOT__cpu__DOT__s_m1;
                        sim_top__DOT__soc__DOT__cpu__DOT__RnWOut = 0U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DOutput 
                            = (0xffU & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp));
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x37U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s_nxt 
                            = sim_top__DOT__soc__DOT__cpu__DOT__s_m1;
                    }
                } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt = 0xffffU;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x36U;
                } else {
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 4U;
                }
            } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 4U;
                } else {
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ea;
                    sim_top__DOT__soc__DOT__cpu__DOT__ALU16_OP 
                        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16Opcode;
                    sim_top__DOT__soc__DOT__cpu__DOT__ALU16_CC 
                        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc;
                    sim_top__DOT__soc__DOT__cpu__DOT__ALU16_B 
                        = ((0xff00U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp)) 
                           | (IData)(vlSelf->dbg_din));
                    sim_top__DOT__soc__DOT__cpu__DOT__ALU16_A 
                        = ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16Reg))
                            ? ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16Reg))
                                ? 0U : ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16Reg))
                                         ? 0U : (((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__a) 
                                                  << 8U) 
                                                 | (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__b))))
                            : ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16Reg))
                                ? ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16Reg))
                                    ? (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s)
                                    : (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u))
                                : ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16Reg))
                                    ? (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__y)
                                    : (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__x))));
                    if (vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpWriteback) {
                        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16Reg))) {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16Reg) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16Reg)))) {
                                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc_nxt 
                                        = (0xffU & 
                                           (vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16 
                                            >> 0x10U));
                                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__a_nxt 
                                        = (0xffU & 
                                           (vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16 
                                            >> 8U));
                                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__b_nxt 
                                        = (0xffU & vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16);
                                }
                            }
                        } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16Reg))) {
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16Reg))) {
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc_nxt 
                                    = (0xffU & (vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16 
                                                >> 0x10U));
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s_nxt 
                                    = (0xffffU & vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16);
                            } else {
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc_nxt 
                                    = (0xffU & (vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16 
                                                >> 0x10U));
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u_nxt 
                                    = (0xffffU & vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16);
                            }
                        } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16Reg))) {
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc_nxt 
                                = (0xffU & (vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16 
                                            >> 0x10U));
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__y_nxt 
                                = (0xffffU & vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16);
                        } else {
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc_nxt 
                                = (0xffU & (vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16 
                                            >> 0x10U));
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__x_nxt 
                                = (0xffffU & vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16);
                        }
                    } else {
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc_nxt 
                            = (0xffU & (vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16 
                                        >> 0x10U));
                    }
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 0U;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x2aU;
                }
            } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                    = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ea;
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ea_nxt 
                    = sim_top__DOT__soc__DOT__cpu__DOT__ea_p1;
                if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__StoreRegisterNum))) {
                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__StoreRegisterNum) 
                                  >> 1U)))) {
                        if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__StoreRegisterNum)))) {
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DOutput 
                                = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__b;
                        }
                    }
                } else {
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DOutput 
                        = (0xffU & ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__StoreRegisterNum))
                                     ? ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__StoreRegisterNum))
                                         ? (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s)
                                         : (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u))
                                     : ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__StoreRegisterNum))
                                         ? (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__y)
                                         : (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__x))));
                }
                sim_top__DOT__soc__DOT__cpu__DOT__RnWOut = 0U;
                sim_top__DOT__soc__DOT__cpu__DOT__rLIC = 1U;
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 4U;
            } else {
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                    = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ea;
                if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16Reg))) {
                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16Reg) 
                                  >> 1U)))) {
                        if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16Reg)))) {
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__b_nxt 
                                = vlSelf->dbg_din;
                            sim_top__DOT__soc__DOT__cpu__DOT__ALU16_B 
                                = ((0xffU & (IData)(sim_top__DOT__soc__DOT__cpu__DOT__ALU16_B)) 
                                   | ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__a) 
                                      << 8U));
                        }
                    }
                } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16Reg))) {
                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16Reg))) {
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s_nxt 
                            = ((0xff00U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s_nxt)) 
                               | (IData)(vlSelf->dbg_din));
                        sim_top__DOT__soc__DOT__cpu__DOT__ALU16_B 
                            = ((0xffU & (IData)(sim_top__DOT__soc__DOT__cpu__DOT__ALU16_B)) 
                               | (0xff00U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s)));
                    } else {
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u_nxt 
                            = ((0xff00U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u_nxt)) 
                               | (IData)(vlSelf->dbg_din));
                        sim_top__DOT__soc__DOT__cpu__DOT__ALU16_B 
                            = ((0xffU & (IData)(sim_top__DOT__soc__DOT__cpu__DOT__ALU16_B)) 
                               | (0xff00U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u)));
                    }
                } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16Reg))) {
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__y_nxt 
                        = ((0xff00U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__y_nxt)) 
                           | (IData)(vlSelf->dbg_din));
                    sim_top__DOT__soc__DOT__cpu__DOT__ALU16_B 
                        = ((0xffU & (IData)(sim_top__DOT__soc__DOT__cpu__DOT__ALU16_B)) 
                           | (0xff00U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__y)));
                } else {
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__x_nxt 
                        = ((0xff00U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__x_nxt)) 
                           | (IData)(vlSelf->dbg_din));
                    sim_top__DOT__soc__DOT__cpu__DOT__ALU16_B 
                        = ((0xffU & (IData)(sim_top__DOT__soc__DOT__cpu__DOT__ALU16_B)) 
                           | (0xff00U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__x)));
                }
                sim_top__DOT__soc__DOT__cpu__DOT__ALU16_OP 
                    = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16Opcode;
                sim_top__DOT__soc__DOT__cpu__DOT__ALU16_CC 
                    = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc;
                sim_top__DOT__soc__DOT__cpu__DOT__ALU16_A = 0U;
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc_nxt 
                    = (0xffU & (vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16 
                                >> 0x10U));
                sim_top__DOT__soc__DOT__cpu__DOT__rLIC = 1U;
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 4U;
                sim_top__DOT__soc__DOT__cpu__DOT__ALU16_B 
                    = ((0xff00U & (IData)(sim_top__DOT__soc__DOT__cpu__DOT__ALU16_B)) 
                       | (IData)(vlSelf->dbg_din));
            }
        } else if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
            if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                            = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ea;
                        sim_top__DOT__soc__DOT__cpu__DOT__RnWOut = 0U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DOutput 
                            = (0xffU & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp));
                        sim_top__DOT__soc__DOT__cpu__DOT__rLIC = 1U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 4U;
                    } else {
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt = 0xffffU;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x2fU;
                    }
                } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 4U;
                } else {
                    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set1__44__instr 
                        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1;
                    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set1__44__hi 
                        = (0xfU & ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set1__44__instr) 
                                   >> 4U));
                    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set1__44__lo 
                        = (0xfU & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set1__44__instr));
                    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set1__44__result 
                        = ((8U <= (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set1__44__hi)) 
                           & (((0xbU >= (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set1__44__lo)) 
                               & (3U != (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set1__44__lo))) 
                              & (7U != (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set1__44__lo))));
                    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set1__44__Vfuncout 
                        = vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set1__44__result;
                    if (vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set1__44__Vfuncout) {
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                            = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ea;
                        sim_top__DOT__soc__DOT__cpu__DOT__ALU_OP 
                            = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU8Op;
                        sim_top__DOT__soc__DOT__cpu__DOT__ALU_B 
                            = vlSelf->dbg_din;
                        sim_top__DOT__soc__DOT__cpu__DOT__ALU_CC 
                            = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc;
                        sim_top__DOT__soc__DOT__cpu__DOT__ALU_A 
                            = ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IsTargetRegA)
                                ? (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__a)
                                : (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__b));
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc_nxt 
                            = (0xffU & ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU) 
                                        >> 8U));
                        if (vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU8Writeback) {
                            if (vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IsTargetRegA) {
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__a_nxt 
                                    = (0xffU & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU));
                            } else {
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__b_nxt 
                                    = (0xffU & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU));
                            }
                        }
                        sim_top__DOT__soc__DOT__cpu__DOT__rLIC = 1U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 4U;
                    } else if (vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IsStore8) {
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                            = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ea;
                        sim_top__DOT__soc__DOT__cpu__DOT__RnWOut = 0U;
                        sim_top__DOT__soc__DOT__cpu__DOT__ALU_OP = 0x16U;
                        sim_top__DOT__soc__DOT__cpu__DOT__ALU_A = 0U;
                        sim_top__DOT__soc__DOT__cpu__DOT__ALU_CC 
                            = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc;
                        if (vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Store8RegisterNum) {
                            if (vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Store8RegisterNum) {
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DOutput 
                                    = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__b;
                                sim_top__DOT__soc__DOT__cpu__DOT__ALU_B 
                                    = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__b;
                            }
                        } else {
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DOutput 
                                = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__a;
                            sim_top__DOT__soc__DOT__cpu__DOT__ALU_B 
                                = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__a;
                        }
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc_nxt 
                            = (0xffU & ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU) 
                                        >> 8U));
                        sim_top__DOT__soc__DOT__cpu__DOT__rLIC = 1U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 4U;
                    } else if (((7U != (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16Opcode)) 
                                & (2U == (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16Opcode)))) {
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                            = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ea;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ea_nxt 
                            = sim_top__DOT__soc__DOT__cpu__DOT__ea_p1;
                        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16Reg))) {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16Reg) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16Reg)))) {
                                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__a_nxt 
                                        = vlSelf->dbg_din;
                                }
                            }
                        } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16Reg))) {
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16Reg))) {
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s_nxt 
                                    = ((0xffU & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s_nxt)) 
                                       | ((IData)(vlSelf->dbg_din) 
                                          << 8U));
                            } else {
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u_nxt 
                                    = ((0xffU & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u_nxt)) 
                                       | ((IData)(vlSelf->dbg_din) 
                                          << 8U));
                            }
                        } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16Reg))) {
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__y_nxt 
                                = ((0xffU & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__y_nxt)) 
                                   | ((IData)(vlSelf->dbg_din) 
                                      << 8U));
                        } else {
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__x_nxt 
                                = ((0xffU & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__x_nxt)) 
                                   | ((IData)(vlSelf->dbg_din) 
                                      << 8U));
                        }
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x30U;
                    } else if (vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IsStore16) {
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                            = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ea;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ea_nxt 
                            = sim_top__DOT__soc__DOT__cpu__DOT__ea_p1;
                        sim_top__DOT__soc__DOT__cpu__DOT__ALU16_OP = 2U;
                        sim_top__DOT__soc__DOT__cpu__DOT__ALU16_CC 
                            = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc;
                        sim_top__DOT__soc__DOT__cpu__DOT__ALU16_A = 0U;
                        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__StoreRegisterNum))) {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__StoreRegisterNum) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__StoreRegisterNum)))) {
                                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DOutput 
                                        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__a;
                                    sim_top__DOT__soc__DOT__cpu__DOT__ALU16_B 
                                        = (((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__a) 
                                            << 8U) 
                                           | (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__b));
                                }
                            }
                        } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__StoreRegisterNum))) {
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__StoreRegisterNum))) {
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DOutput 
                                    = (0xffU & ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s) 
                                                >> 8U));
                                sim_top__DOT__soc__DOT__cpu__DOT__ALU16_B 
                                    = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s;
                            } else {
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DOutput 
                                    = (0xffU & ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u) 
                                                >> 8U));
                                sim_top__DOT__soc__DOT__cpu__DOT__ALU16_B 
                                    = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u;
                            }
                        } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__StoreRegisterNum))) {
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DOutput 
                                = (0xffU & ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__y) 
                                            >> 8U));
                            sim_top__DOT__soc__DOT__cpu__DOT__ALU16_B 
                                = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__y;
                        } else {
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DOutput 
                                = (0xffU & ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__x) 
                                            >> 8U));
                            sim_top__DOT__soc__DOT__cpu__DOT__ALU16_B 
                                = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__x;
                        }
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc_nxt 
                            = (0xffU & (vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16 
                                        >> 0x10U));
                        sim_top__DOT__soc__DOT__cpu__DOT__RnWOut = 0U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x31U;
                    } else {
                        vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set0__45__instr 
                            = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1;
                        vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set0__45__hi 
                            = (0xfU & ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set0__45__instr) 
                                       >> 4U));
                        vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set0__45__lo 
                            = (0xfU & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set0__45__instr));
                        vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set0__45__result 
                            = ((((((0U == (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set0__45__hi)) 
                                   | (4U == (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set0__45__hi))) 
                                  | (5U == (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set0__45__hi))) 
                                 | (6U == (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set0__45__hi))) 
                                | (7U == (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set0__45__hi))) 
                               & (((((1U != (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set0__45__lo)) 
                                     & (2U != (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set0__45__lo))) 
                                    & (5U != (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set0__45__lo))) 
                                   & (0xbU != (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set0__45__lo))) 
                                  & (0xeU != (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set0__45__lo))));
                        vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set0__45__Vfuncout 
                            = vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set0__45__result;
                        if (vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set0__45__Vfuncout) {
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                                = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ea;
                            sim_top__DOT__soc__DOT__cpu__DOT__ALU_OP 
                                = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU8Op;
                            sim_top__DOT__soc__DOT__cpu__DOT__ALU_A 
                                = vlSelf->dbg_din;
                            sim_top__DOT__soc__DOT__cpu__DOT__ALU_CC 
                                = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc;
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt 
                                = (((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc) 
                                    << 8U) | (0xffU 
                                              & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU)));
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc_nxt 
                                = (0xffU & ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU) 
                                            >> 8U));
                            if ((0xdU == (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU8Op))) {
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 0U;
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x60U;
                            } else {
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 0U;
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x2eU;
                            }
                        } else if ((((7U != (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16Opcode)) 
                                     & (2U != (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16Opcode))) 
                                    & ((0x30U > (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1)) 
                                       | (0x33U < (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1))))) {
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                                = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ea;
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ea_nxt 
                                = sim_top__DOT__soc__DOT__cpu__DOT__ea_p1;
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt 
                                = ((0xffU & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt)) 
                                   | ((IData)(vlSelf->dbg_din) 
                                      << 8U));
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x32U;
                        } else if ((((0x9dU == (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1)) 
                                     | (0xadU == (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1))) 
                                    | (0xbdU == (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1)))) {
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_nxt 
                                = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ea;
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                                = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ea;
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt 
                                = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc;
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 0U;
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x35U;
                        } else if (((0x30U <= (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1)) 
                                    & (0x33U >= (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1)))) {
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt = 0xffffU;
                            sim_top__DOT__soc__DOT__cpu__DOT__ALU16_OP 
                                = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16Opcode;
                            sim_top__DOT__soc__DOT__cpu__DOT__ALU16_CC 
                                = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc;
                            sim_top__DOT__soc__DOT__cpu__DOT__ALU16_A 
                                = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ea;
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16Reg) 
                                          >> 2U)))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16Reg))) {
                                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16Reg))) {
                                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s_nxt 
                                            = (0xffffU 
                                               & vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16);
                                    } else {
                                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u_nxt 
                                            = (0xffffU 
                                               & vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16);
                                    }
                                } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16Reg))) {
                                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc_nxt 
                                        = (0xffU & 
                                           (vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16 
                                            >> 0x10U));
                                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__y_nxt 
                                        = (0xffffU 
                                           & vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16);
                                } else {
                                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc_nxt 
                                        = (0xffU & 
                                           (vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16 
                                            >> 0x10U));
                                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__x_nxt 
                                        = (0xffffU 
                                           & vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16);
                                }
                            }
                            sim_top__DOT__soc__DOT__cpu__DOT__rLIC = 1U;
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 4U;
                        }
                    }
                }
            } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__46__inst 
                        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt = 0xffffU;
                    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__46__hi 
                        = (0xfU & ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__46__inst) 
                                   >> 4U));
                    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__46__lo 
                        = (0xfU & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__46__inst));
                    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__46__Vfuncout = 0U;
                    if ((((0U == (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__46__hi)) 
                          | (6U == (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__46__hi))) 
                         | (7U == (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__46__hi)))) {
                        if ((0xeU == (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__46__lo))) {
                            vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__46__Vfuncout = 1U;
                        }
                    }
                    if (vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsJMP__46__Vfuncout) {
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_nxt 
                            = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ea;
                        sim_top__DOT__soc__DOT__cpu__DOT__rLIC = 1U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 4U;
                    } else {
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x2cU;
                    }
                } else {
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt = 0xffffU;
                    sim_top__DOT__soc__DOT__cpu__DOT__rLIC = 1U;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 4U;
                }
            } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                sim_top__DOT__soc__DOT__cpu__DOT__ALU16_OP 
                    = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16Opcode;
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                    = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc;
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_nxt 
                    = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_p1;
                sim_top__DOT__soc__DOT__cpu__DOT__ALU16_CC 
                    = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc;
                sim_top__DOT__soc__DOT__cpu__DOT__ALU16_B 
                    = (((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst2) 
                        << 8U) | (IData)(vlSelf->dbg_din));
                sim_top__DOT__soc__DOT__cpu__DOT__ALU16_A 
                    = ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16Reg))
                        ? ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16Reg))
                            ? 0U : ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16Reg))
                                     ? 0U : (((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__a) 
                                              << 8U) 
                                             | (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__b))))
                        : ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16Reg))
                            ? ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16Reg))
                                ? (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s)
                                : (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u))
                            : ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16Reg))
                                ? (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__y)
                                : (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__x))));
                if (vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpWriteback) {
                    if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16Reg))) {
                        if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16Reg) 
                                      >> 1U)))) {
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16Reg)))) {
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc_nxt 
                                    = (0xffU & (vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16 
                                                >> 0x10U));
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__a_nxt 
                                    = (0xffU & (vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16 
                                                >> 8U));
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__b_nxt 
                                    = (0xffU & vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16);
                            }
                        }
                    } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16Reg))) {
                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16Reg))) {
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc_nxt 
                                = (0xffU & (vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16 
                                            >> 0x10U));
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s_nxt 
                                = (0xffffU & vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16);
                        } else {
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc_nxt 
                                = (0xffU & (vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16 
                                            >> 0x10U));
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u_nxt 
                                = (0xffffU & vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16);
                        }
                    } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16Reg))) {
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc_nxt 
                            = (0xffU & (vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16 
                                        >> 0x10U));
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__y_nxt 
                            = (0xffffU & vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16);
                    } else {
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc_nxt 
                            = (0xffU & (vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16 
                                        >> 0x10U));
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__x_nxt 
                            = (0xffffU & vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16);
                    }
                } else {
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc_nxt 
                        = (0xffU & (vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16 
                                    >> 0x10U));
                }
                if ((2U == (IData)(sim_top__DOT__soc__DOT__cpu__DOT__ALU16_OP))) {
                    sim_top__DOT__soc__DOT__cpu__DOT__rLIC = 1U;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 4U;
                } else {
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 0U;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x63U;
                }
            } else {
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt = 0xffffU;
                sim_top__DOT__soc__DOT__cpu__DOT__rLIC = 1U;
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 4U;
            }
        } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s_nxt 
                        = sim_top__DOT__soc__DOT__cpu__DOT__s_p1;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_nxt 
                        = ((0xff00U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_nxt)) 
                           | (IData)(vlSelf->dbg_din));
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 0U;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x28U;
                } else {
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s_nxt 
                        = sim_top__DOT__soc__DOT__cpu__DOT__s_p1;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_nxt 
                        = ((0xffU & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_nxt)) 
                           | ((IData)(vlSelf->dbg_din) 
                              << 8U));
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x27U;
                }
            } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 4U;
            } else {
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt = 0xffffU;
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                sim_top__DOT__soc__DOT__cpu__DOT__rLIC = 1U;
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 4U;
            }
        } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt = 0xffffU;
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                sim_top__DOT__soc__DOT__cpu__DOT__rLIC = 1U;
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 4U;
            } else {
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 0U;
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt = 0xffffU;
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x23U;
            }
        } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt = 0xffffU;
            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 0U;
            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x22U;
        } else {
            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt = 0xffffU;
            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 0U;
            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x21U;
        }
    } else if ((0x10U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
        if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
            if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt = 0xffffU;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 0U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x20U;
                    } else {
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt = 0xffffU;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 0U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x1fU;
                    }
                } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt = 0xffffU;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                    sim_top__DOT__soc__DOT__cpu__DOT__rLIC = 1U;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 4U;
                } else {
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt = 0xffffU;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 0U;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x1dU;
                }
            } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt = 0xffffU;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 0U;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x1cU;
                } else {
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt = 0xffffU;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 0U;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x1bU;
                }
            } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 4U;
            } else {
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                    = sim_top__DOT__soc__DOT__cpu__DOT__s_m1;
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DOutput 
                    = (0xffU & ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp) 
                                >> 8U));
                sim_top__DOT__soc__DOT__cpu__DOT__RnWOut = 0U;
                sim_top__DOT__soc__DOT__cpu__DOT__rLIC = 1U;
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 4U;
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s_nxt 
                    = sim_top__DOT__soc__DOT__cpu__DOT__s_m1;
            }
        } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                        = sim_top__DOT__soc__DOT__cpu__DOT__s_m1;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DOutput 
                        = (0xffU & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp));
                    sim_top__DOT__soc__DOT__cpu__DOT__RnWOut = 0U;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x18U;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s_nxt 
                        = sim_top__DOT__soc__DOT__cpu__DOT__s_m1;
                } else {
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt = 0xffffU;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x17U;
                }
            } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                    = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc;
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 0U;
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x16U;
            } else {
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt = 0xffffU;
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt 
                    = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc;
                if (vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__TakeBranch) {
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_nxt 
                        = (0xffffU & ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc) 
                                      + ((0xff00U & 
                                          ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst2) 
                                                          >> 7U)))) 
                                           << 8U)) 
                                         | (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst2))));
                    if ((0x8dU == (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1))) {
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x15U;
                    } else {
                        sim_top__DOT__soc__DOT__cpu__DOT__rLIC = 1U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 4U;
                    }
                } else {
                    sim_top__DOT__soc__DOT__cpu__DOT__rLIC = 1U;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 4U;
                }
            }
        } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt 
                    = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc;
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt = 0xffffU;
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_nxt 
                    = (0xffffU & ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc) 
                                  + (((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst2) 
                                      << 8U) | (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst3))));
                if ((0x17U == (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1))) {
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x15U;
                } else {
                    sim_top__DOT__soc__DOT__cpu__DOT__rLIC = 1U;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 4U;
                }
            } else {
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt = 0xffffU;
                if (vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__TakeBranch) {
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 0U;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x13U;
                } else {
                    sim_top__DOT__soc__DOT__cpu__DOT__rLIC = 1U;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 4U;
                }
            }
        } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc;
            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_nxt 
                = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_p1;
            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 0U;
            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x12U;
        } else {
            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 4U;
        }
    } else if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 4U;
        } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 4U;
        } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 4U;
        } else {
            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                = sim_top__DOT__soc__DOT__cpu__DOT__addr_p1;
            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_nxt 
                = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_p1;
            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst2_nxt 
                = vlSelf->dbg_din;
            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 4U;
            if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__AddrModeType))) {
                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__AddrModeType))) {
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 4U;
                } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__AddrModeType))) {
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ea_nxt 
                        = ((0xffU & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ea_nxt)) 
                           | ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst2_nxt) 
                              << 8U));
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x38U;
                } else {
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x3aU;
                }
            } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__AddrModeType))) {
                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__AddrModeType))) {
                    if ((((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__InstPage2) 
                          | (0x16U == (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1))) 
                         | (0x17U == (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1)))) {
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x11U;
                    } else {
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 0U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x14U;
                    }
                } else {
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ea_nxt 
                        = (((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__dp) 
                            << 8U) | (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst2_nxt));
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 0U;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x2bU;
                }
            } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__AddrModeType))) {
                if (vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IsSpecialImmediate) {
                    if ((0x1cU == (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1))) {
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_nxt 
                            = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_p1;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc_nxt 
                            = ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc) 
                               & (IData)(vlSelf->dbg_din));
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x5eU;
                    } else if ((0x1aU == (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1))) {
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_nxt 
                            = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_p1;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc_nxt 
                            = ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc) 
                               | (IData)(vlSelf->dbg_din));
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x5eU;
                    } else if (((0x34U == (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1)) 
                                | (0x36U == (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1)))) {
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_nxt 
                            = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_p1;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt 
                            = ((0x1fffU & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt)) 
                               | (0x4000U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1) 
                                             << 0xdU)));
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 0U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x50U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt 
                            = ((0xc000U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt)) 
                               | (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst2_nxt));
                    } else if (((0x35U == (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1)) 
                                | (0x37U == (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1)))) {
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_nxt 
                            = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_p1;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt 
                            = ((0xffU & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt)) 
                               | (0x4000U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1) 
                                             << 0xdU)));
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 0U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x54U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt 
                            = ((0xff00U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt)) 
                               | (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst2_nxt));
                    } else if ((0x1fU == (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1))) {
                        if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst2_nxt))) {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst2_nxt) 
                                          >> 2U)))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst2_nxt))) {
                                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst2_nxt))) {
                                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__dp_nxt 
                                            = (0xffU 
                                               & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__EXGTFRRegA));
                                    } else {
                                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc_nxt 
                                            = (0xffU 
                                               & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__EXGTFRRegA));
                                    }
                                } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst2_nxt))) {
                                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__b_nxt 
                                        = (0xffU & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__EXGTFRRegA));
                                } else {
                                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__a_nxt 
                                        = (0xffU & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__EXGTFRRegA));
                                }
                            }
                        } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst2_nxt))) {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst2_nxt) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst2_nxt))) {
                                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_nxt 
                                        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__EXGTFRRegA;
                                } else {
                                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s_nxt 
                                        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__EXGTFRRegA;
                                }
                            }
                        } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst2_nxt))) {
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst2_nxt))) {
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u_nxt 
                                    = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__EXGTFRRegA;
                            } else {
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__y_nxt 
                                    = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__EXGTFRRegA;
                            }
                        } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst2_nxt))) {
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__x_nxt 
                                = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__EXGTFRRegA;
                        } else {
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__a_nxt 
                                = (0xffU & ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__EXGTFRRegA) 
                                            >> 8U));
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__b_nxt 
                                = (0xffU & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__EXGTFRRegA));
                        }
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 0U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x1aU;
                    } else if ((0x1eU == (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1))) {
                        if ((0x80U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst2_nxt))) {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst2_nxt) 
                                          >> 6U)))) {
                                if ((0x20U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst2_nxt))) {
                                    if ((0x10U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst2_nxt))) {
                                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__dp_nxt 
                                            = (0xffU 
                                               & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__EXGTFRRegB));
                                    } else {
                                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc_nxt 
                                            = (0xffU 
                                               & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__EXGTFRRegB));
                                    }
                                } else if ((0x10U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst2_nxt))) {
                                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__b_nxt 
                                        = (0xffU & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__EXGTFRRegB));
                                } else {
                                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__a_nxt 
                                        = (0xffU & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__EXGTFRRegB));
                                }
                            }
                        } else if ((0x40U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst2_nxt))) {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst2_nxt) 
                                          >> 5U)))) {
                                if ((0x10U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst2_nxt))) {
                                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_nxt 
                                        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__EXGTFRRegB;
                                } else {
                                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s_nxt 
                                        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__EXGTFRRegB;
                                }
                            }
                        } else if ((0x20U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst2_nxt))) {
                            if ((0x10U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst2_nxt))) {
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u_nxt 
                                    = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__EXGTFRRegB;
                            } else {
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__y_nxt 
                                    = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__EXGTFRRegB;
                            }
                        } else if ((0x10U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst2_nxt))) {
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__x_nxt 
                                = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__EXGTFRRegB;
                        } else {
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__a_nxt 
                                = (0xffU & ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__EXGTFRRegB) 
                                            >> 8U));
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__b_nxt 
                                = (0xffU & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__EXGTFRRegB));
                        }
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 0U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x1eU;
                        if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst2_nxt))) {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst2_nxt) 
                                          >> 2U)))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst2_nxt))) {
                                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst2_nxt))) {
                                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__dp_nxt 
                                            = (0xffU 
                                               & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__EXGTFRRegA));
                                    } else {
                                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc_nxt 
                                            = (0xffU 
                                               & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__EXGTFRRegA));
                                    }
                                } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst2_nxt))) {
                                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__b_nxt 
                                        = (0xffU & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__EXGTFRRegA));
                                } else {
                                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__a_nxt 
                                        = (0xffU & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__EXGTFRRegA));
                                }
                            }
                        } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst2_nxt))) {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst2_nxt) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst2_nxt))) {
                                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_nxt 
                                        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__EXGTFRRegA;
                                } else {
                                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s_nxt 
                                        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__EXGTFRRegA;
                                }
                            }
                        } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst2_nxt))) {
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst2_nxt))) {
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u_nxt 
                                    = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__EXGTFRRegA;
                            } else {
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__y_nxt 
                                    = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__EXGTFRRegA;
                            }
                        } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst2_nxt))) {
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__x_nxt 
                                = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__EXGTFRRegA;
                        } else {
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__a_nxt 
                                = (0xffU & ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__EXGTFRRegA) 
                                            >> 8U));
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__b_nxt 
                                = (0xffU & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__EXGTFRRegA));
                        }
                    }
                } else if (vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Is8BitInst) {
                    sim_top__DOT__soc__DOT__cpu__DOT__ALU_OP 
                        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU8Op;
                    sim_top__DOT__soc__DOT__cpu__DOT__ALU_A 
                        = ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IsTargetRegA)
                            ? (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__a)
                            : (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__b));
                    sim_top__DOT__soc__DOT__cpu__DOT__ALU_B 
                        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst2_nxt;
                    sim_top__DOT__soc__DOT__cpu__DOT__ALU_CC 
                        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc_nxt 
                        = (0xffU & ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU) 
                                    >> 8U));
                    if (vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU8Writeback) {
                        if (vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IsTargetRegA) {
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__a_nxt 
                                = (0xffU & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU));
                        } else {
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__b_nxt 
                                = (0xffU & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU));
                        }
                    }
                    sim_top__DOT__soc__DOT__cpu__DOT__rLIC = 1U;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 4U;
                } else if ((7U != (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16Opcode))) {
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x29U;
                }
            } else {
                vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsOneByteInstruction__47__inst 
                    = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1;
                if ((0x12U == (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1))) {
                    sim_top__DOT__soc__DOT__cpu__DOT__rLIC = 1U;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 4U;
                } else if ((0x19U == (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1))) {
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt 
                        = ((0xff0fU & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt)) 
                           | (((1U & (((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc) 
                                       | (9U < (0xfU 
                                                & ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__a) 
                                                   >> 4U)))) 
                                      | ((8U < (0xfU 
                                                & ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__a) 
                                                   >> 4U))) 
                                         & (9U < (0xfU 
                                                  & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__a))))))
                                ? 6U : 0U) << 4U));
                    sim_top__DOT__soc__DOT__cpu__DOT__rLIC = 1U;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 4U;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt 
                        = ((0xfff0U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt)) 
                           | ((1U & (((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc) 
                                      >> 5U) | (9U 
                                                < (0xfU 
                                                   & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__a)))))
                               ? 6U : 0U));
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT____Vconcswap_1_h74bdd05e__0 
                        = (1U & (((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__a) 
                                  + (0xffU & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt))) 
                                 >> 8U));
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT____Vconcswap_1_h7a07b729__0 
                        = (0xffU & ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__a) 
                                    + (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt)));
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt 
                        = ((0xfeffU & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt)) 
                           | ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT____Vconcswap_1_h74bdd05e__0) 
                              << 8U));
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__a_nxt 
                        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT____Vconcswap_1_h7a07b729__0;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc_nxt 
                        = ((0xfeU & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc_nxt)) 
                           | (1U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc_nxt) 
                                    | ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt) 
                                       >> 8U))));
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc_nxt 
                        = ((0xf3U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc_nxt)) 
                           | ((8U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__a_nxt) 
                                     >> 4U)) | ((0U 
                                                 == (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__a_nxt)) 
                                                << 2U)));
                } else if ((0x13U == (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1))) {
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x71U;
                    sim_top__DOT__soc__DOT__cpu__DOT__rLIC = 1U;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 0U;
                } else if ((0x3dU == (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1))) {
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt = 0U;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ea_nxt 
                        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__a;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__a_nxt = 8U;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 0U;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x4dU;
                } else if ((0x39U == (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1))) {
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x26U;
                } else if ((0x3bU == (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1))) {
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt = 0x1001U;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x56U;
                } else if ((0x3fU == (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1))) {
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x5fU;
                } else if ((0x3cU == (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1))) {
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x6cU;
                } else if ((0x1dU == (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1))) {
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__a_nxt 
                        = (0xffU & (- (IData)((1U & 
                                               ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__b) 
                                                >> 7U)))));
                    sim_top__DOT__soc__DOT__cpu__DOT__rLIC = 1U;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 4U;
                } else if ((0x3aU == (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1))) {
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__x_nxt 
                        = (0xffffU & ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__x) 
                                      + (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__b)));
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 0U;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x24U;
                } else {
                    sim_top__DOT__soc__DOT__cpu__DOT__ALU_OP 
                        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU8Op;
                    sim_top__DOT__soc__DOT__cpu__DOT__ALU_A 
                        = ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IsTargetRegA)
                            ? (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__a)
                            : (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__b));
                    sim_top__DOT__soc__DOT__cpu__DOT__ALU_B = 0U;
                    sim_top__DOT__soc__DOT__cpu__DOT__ALU_CC 
                        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc_nxt 
                        = (0xffU & ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU) 
                                    >> 8U));
                    if (vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU8Writeback) {
                        if (vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IsTargetRegA) {
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__a_nxt 
                                = (0xffU & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU));
                        } else {
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__b_nxt 
                                = (0xffU & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU));
                        }
                    }
                    sim_top__DOT__soc__DOT__cpu__DOT__rLIC = 1U;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 4U;
                }
                vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsOneByteInstruction__47__hi 
                    = (0xfU & ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsOneByteInstruction__47__inst) 
                               >> 4U));
                vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsOneByteInstruction__47__lo 
                    = (0xfU & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsOneByteInstruction__47__inst));
                vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsOneByteInstruction__47__is = 0U;
                if (((4U == (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsOneByteInstruction__47__hi)) 
                     | (5U == (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsOneByteInstruction__47__hi)))) {
                    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsOneByteInstruction__47__is = 1U;
                } else if ((1U == (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsOneByteInstruction__47__hi))) {
                    if (((((2U == (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsOneByteInstruction__47__lo)) 
                           | (3U == (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsOneByteInstruction__47__lo))) 
                          | (9U == (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsOneByteInstruction__47__lo))) 
                         | (0xdU == (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsOneByteInstruction__47__lo)))) {
                        vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsOneByteInstruction__47__is = 1U;
                    }
                } else if ((3U == (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsOneByteInstruction__47__hi))) {
                    if (((9U <= (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsOneByteInstruction__47__lo)) 
                         & (0xcU != (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsOneByteInstruction__47__lo)))) {
                        vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsOneByteInstruction__47__is = 1U;
                    }
                } else {
                    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsOneByteInstruction__47__is = 0U;
                }
                vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsOneByteInstruction__47__Vfuncout 
                    = vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsOneByteInstruction__47__is;
                if (vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsOneByteInstruction__47__Vfuncout) {
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_nxt 
                        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc;
                }
            }
        }
    } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 4U;
        } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1_nxt 
                = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__MappedInstruction;
            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc;
            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_nxt 
                = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_p1;
            sim_top__DOT__soc__DOT__cpu__DOT__RnWOut = 1U;
            if ((0x10U == (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1_nxt))) {
                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__InstPage3)))) {
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__InstPage2_nxt = 1U;
                }
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 5U;
            } else if ((0x11U == (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1_nxt))) {
                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__InstPage2)))) {
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__InstPage3_nxt = 1U;
                }
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 5U;
            } else {
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 8U;
            }
        } else if (vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DMABREQLatched) {
            if (vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__HALTLatched) {
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                    = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc;
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_nxt 
                    = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_p1;
                sim_top__DOT__soc__DOT__cpu__DOT__RnWOut = 1U;
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1_nxt 
                    = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__MappedInstruction;
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__InstPage2_nxt = 0U;
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__InstPage3_nxt = 0U;
                if (vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__NMILatched) {
                    if ((1U & ((~ (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__FIRQLatched)) 
                               & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc) 
                                     >> 6U))))) {
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_nxt 
                            = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x5dU;
                    } else if ((1U & ((~ (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IRQLatched)) 
                                      & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc) 
                                            >> 4U))))) {
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_nxt 
                            = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x59U;
                    } else if ((0x10U == (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1_nxt))) {
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__InstPage2_nxt = 1U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 5U;
                    } else if ((0x11U == (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1_nxt))) {
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__InstPage3_nxt = 1U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 5U;
                    } else {
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 8U;
                    }
                } else {
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_nxt 
                        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x57U;
                }
            } else {
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                    = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc;
                sim_top__DOT__soc__DOT__cpu__DOT__RnWOut = 1U;
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 0U;
                sim_top__DOT__soc__DOT__cpu__DOT__rLIC = 1U;
                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x64U;
            }
        } else {
            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc;
            sim_top__DOT__soc__DOT__cpu__DOT__RnWOut = 1U;
            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 0U;
            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt 
                = (0xfU | (0xfff0U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp)));
            sim_top__DOT__soc__DOT__cpu__DOT__rLIC = 1U;
            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 0x6fU;
        }
    } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt 
                = sim_top__DOT__soc__DOT__cpu__DOT__addr_p1;
            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_nxt 
                = ((0xff00U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_nxt)) 
                   | (IData)(vlSelf->dbg_din));
            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
            sim_top__DOT__soc__DOT__cpu__DOT__rLIC = 1U;
            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 4U;
        } else {
            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 4U;
        }
    } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt = 0xfffeU;
        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_nxt 
            = ((0xffU & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_nxt)) 
               | ((IData)(vlSelf->dbg_din) << 8U));
        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
        sim_top__DOT__soc__DOT__cpu__DOT__rLIC = 1U;
        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 3U;
    } else {
        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt = 0xffffU;
        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__a_nxt = 0U;
        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__b_nxt = 0U;
        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__x_nxt = 0U;
        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__y_nxt = 0U;
        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s_nxt = 0xfffdU;
        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u_nxt = 0U;
        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc_nxt = 0x50U;
        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__dp_nxt = 0U;
        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ea_nxt = 0xffffU;
        sim_top__DOT__soc__DOT__cpu__DOT__RnWOut = 1U;
        sim_top__DOT__soc__DOT__cpu__DOT__rLIC = 0U;
        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA = 1U;
        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt = 1U;
    }
    vlSelf->dbg_lic = sim_top__DOT__soc__DOT__cpu__DOT__rLIC;
    vlSelf->dbg_rnw = sim_top__DOT__soc__DOT__cpu__DOT__RnWOut;
    vlSelf->sim_top__DOT__soc__DOT__xl_re = ((IData)(vlSelf->sim_top__DOT__soc__DOT__xl_acc) 
                                             & (IData)(sim_top__DOT__soc__DOT__cpu__DOT__RnWOut));
    vlSelf->sim_top__DOT__soc__DOT__xl_we = ((~ (IData)(sim_top__DOT__soc__DOT__cpu__DOT__RnWOut)) 
                                             & (IData)(vlSelf->sim_top__DOT__soc__DOT__xl_acc));
    vlSelf->sim_top__DOT__soc__DOT__timer_wr = ((IData)(vlSelf->sim_top__DOT__soc__DOT____VdfgTmp_h20f74f65__0) 
                                                & ((~ (IData)(sim_top__DOT__soc__DOT__cpu__DOT__RnWOut)) 
                                                   & (IData)(vlSelf->sim_top__DOT__soc__DOT__io_timer)));
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_arg 
        = sim_top__DOT__soc__DOT__cpu__DOT__ALU_CC;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__b_arg 
        = sim_top__DOT__soc__DOT__cpu__DOT__ALU_B;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__a_arg 
        = sim_top__DOT__soc__DOT__cpu__DOT__ALU_A;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__operation 
        = sim_top__DOT__soc__DOT__cpu__DOT__ALU_OP;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_out 
        = __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_arg;
    if ((0x10U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__operation))) {
        if ((8U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__operation))) {
            if ((4U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__operation))) {
                vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__ALUFn = 0U;
            } else if ((2U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__operation))) {
                if ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__operation))) {
                    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_out 
                        = ((0xfeU & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_out)) 
                           | (1U & (((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__a_arg) 
                                     + (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__b_arg)) 
                                    >> 8U)));
                    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__ALUFn 
                        = (0xffU & ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__a_arg) 
                                    + (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__b_arg)));
                    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_out 
                        = ((0xfdU & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_out)) 
                           | (2U & (((((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__a_arg) 
                                       & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__b_arg)) 
                                      >> 6U) & ((~ 
                                                 ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__ALUFn) 
                                                  >> 7U)) 
                                                << 1U)) 
                                    | ((((~ ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__a_arg) 
                                             >> 7U)) 
                                         & (~ ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__b_arg) 
                                               >> 7U))) 
                                        << 1U) & ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__ALUFn) 
                                                  >> 6U)))));
                    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_out 
                        = ((0xdfU & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_out)) 
                           | (0x20U & ((((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__a_arg) 
                                         ^ (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__b_arg)) 
                                        ^ (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__ALUFn)) 
                                       << 1U)));
                } else {
                    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__ALUFn 
                        = ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__a_arg) 
                           | (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__b_arg));
                    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_out 
                        = (0xfdU & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_out));
                }
            } else if ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__operation))) {
                __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_out 
                    = ((0xfeU & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_out)) 
                       | (1U & ((((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__a_arg) 
                                  + (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__b_arg)) 
                                 + (1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_arg))) 
                                >> 8U)));
                vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__ALUFn 
                    = (0xffU & (((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__a_arg) 
                                 + (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__b_arg)) 
                                + (1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_arg))));
                __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_out 
                    = ((0xfdU & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_out)) 
                       | (2U & (((((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__a_arg) 
                                   & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__b_arg)) 
                                  >> 6U) & ((~ ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__ALUFn) 
                                                >> 7U)) 
                                            << 1U)) 
                                | ((((~ ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__a_arg) 
                                         >> 7U)) & 
                                     (~ ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__b_arg) 
                                         >> 7U))) << 1U) 
                                   & ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__ALUFn) 
                                      >> 6U)))));
                __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_out 
                    = ((0xdfU & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_out)) 
                       | (0x20U & ((((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__a_arg) 
                                     ^ (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__b_arg)) 
                                    ^ (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__ALUFn)) 
                                   << 1U)));
            } else {
                vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__ALUFn 
                    = ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__a_arg) 
                       ^ (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__b_arg));
                __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_out 
                    = (0xfdU & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_out));
            }
        } else if ((4U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__operation))) {
            if ((2U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__operation))) {
                if ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__operation))) {
                    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__ALUFn = 0U;
                } else {
                    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__ALUFn 
                        = __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__b_arg;
                    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_out 
                        = (0xfdU & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_out));
                }
            } else if ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__operation))) {
                vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__ALUFn 
                    = ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__a_arg) 
                       & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__b_arg));
                __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_out 
                    = (0xfdU & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_out));
            } else {
                vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__ALUFn 
                    = ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__a_arg) 
                       & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__b_arg));
                __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_out 
                    = (0xfdU & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_out));
            }
        } else if ((2U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__operation))) {
            if ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__operation))) {
                vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__ALUFn = 0U;
            } else {
                __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_out 
                    = ((0xfeU & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_out)) 
                       | (1U & ((((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__a_arg) 
                                  - (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__b_arg)) 
                                 - (1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_arg))) 
                                >> 8U)));
                vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__ALUFn 
                    = (0xffU & (((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__a_arg) 
                                 - (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__b_arg)) 
                                - (1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_arg))));
                __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_out 
                    = ((0xfdU & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_out)) 
                       | (2U & ((0x3fffffeU & ((((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__a_arg) 
                                                 >> 6U) 
                                                & ((~ 
                                                    ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__b_arg) 
                                                     >> 7U)) 
                                                   << 1U)) 
                                               & ((~ 
                                                   ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__ALUFn) 
                                                    >> 7U)) 
                                                  << 1U))) 
                                | (0x3fffffeU & (((
                                                   (~ 
                                                    ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__a_arg) 
                                                     >> 7U)) 
                                                   << 1U) 
                                                  & ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__b_arg) 
                                                     >> 6U)) 
                                                 & ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__ALUFn) 
                                                    >> 6U))))));
            }
        } else if ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__operation))) {
            __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_out 
                = ((0xfeU & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_out)) 
                   | (1U & (((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__a_arg) 
                             - (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__b_arg)) 
                            >> 8U)));
            vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__ALUFn 
                = (0xffU & ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__a_arg) 
                            - (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__b_arg)));
            __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_out 
                = ((0xfdU & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_out)) 
                   | (2U & ((0x3fffffeU & ((((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__a_arg) 
                                             >> 6U) 
                                            & ((~ ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__b_arg) 
                                                   >> 7U)) 
                                               << 1U)) 
                                           & ((~ ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__ALUFn) 
                                                  >> 7U)) 
                                              << 1U))) 
                            | (0x3fffffeU & ((((~ ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__a_arg) 
                                                   >> 7U)) 
                                               << 1U) 
                                              & ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__b_arg) 
                                                 >> 6U)) 
                                             & ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__ALUFn) 
                                                >> 6U))))));
        } else {
            __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_out 
                = ((0xfeU & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_out)) 
                   | (1U & (((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__a_arg) 
                             - (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__b_arg)) 
                            >> 8U)));
            vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__ALUFn 
                = (0xffU & ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__a_arg) 
                            - (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__b_arg)));
            __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_out 
                = ((0xfdU & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_out)) 
                   | (2U & ((0x3fffffeU & ((((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__a_arg) 
                                             >> 6U) 
                                            & ((~ ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__b_arg) 
                                                   >> 7U)) 
                                               << 1U)) 
                                           & ((~ ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__ALUFn) 
                                                  >> 7U)) 
                                              << 1U))) 
                            | (0x3fffffeU & ((((~ ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__a_arg) 
                                                   >> 7U)) 
                                               << 1U) 
                                              & ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__b_arg) 
                                                 >> 6U)) 
                                             & ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__ALUFn) 
                                                >> 6U))))));
        }
    } else if ((8U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__operation))) {
        if ((4U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__operation))) {
            if ((2U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__operation))) {
                if ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__operation))) {
                    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__ALUFn = 0U;
                    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_out 
                        = (0xfcU & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_out));
                } else {
                    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__ALUFn = 0U;
                }
            } else if ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__operation))) {
                vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__ALUFn 
                    = __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__a_arg;
                __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_out 
                    = (0xfdU & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_out));
            } else {
                vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__ALUFn 
                    = (0xffU & ((IData)(1U) + (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__a_arg)));
                __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_out 
                    = ((0xfdU & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_out)) 
                       | ((IData)(((~ ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__a_arg) 
                                       >> 7U)) & ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__ALUFn) 
                                                  >> 7U))) 
                          << 1U));
            }
        } else if ((2U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__operation))) {
            if ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__operation))) {
                vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__ALUFn = 0U;
            } else {
                vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__ALUFn 
                    = (0xffU & ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__a_arg) 
                                - (IData)(1U)));
                __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_out 
                    = ((0xfdU & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_out)) 
                       | ((IData)((((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__a_arg) 
                                    >> 7U) & (~ ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__ALUFn) 
                                                 >> 7U)))) 
                          << 1U));
            }
        } else if ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__operation))) {
            __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_out 
                = ((0xfeU & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_out)) 
                   | (1U & ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__a_arg) 
                            >> 7U)));
            vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__ALUFn 
                = ((0xfeU & ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__a_arg) 
                             << 1U)) | (1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_arg)));
            __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_out 
                = ((0xfdU & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_out)) 
                   | (2U & (VL_REDXOR_8((0xc0U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__a_arg))) 
                            << 1U)));
        } else {
            __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_out 
                = ((0xfeU & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_out)) 
                   | (1U & ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__a_arg) 
                            >> 7U)));
            vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__ALUFn 
                = (0xfeU & ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__a_arg) 
                            << 1U));
            __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_out 
                = ((0xfdU & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_out)) 
                   | (2U & (VL_REDXOR_8((0xc0U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__a_arg))) 
                            << 1U)));
        }
    } else if ((4U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__operation))) {
        if ((2U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__operation))) {
            if ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__operation))) {
                vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__ALUFn 
                    = ((0x80U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__a_arg)) 
                       | (0x7fU & ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__a_arg) 
                                   >> 1U)));
                __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_out 
                    = ((0xfeU & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_out)) 
                       | (1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__a_arg)));
            } else {
                vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__ALUFn 
                    = ((0x80U & ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_arg) 
                                 << 7U)) | (0x7fU & 
                                            ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__a_arg) 
                                             >> 1U)));
                __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_out 
                    = ((0xfeU & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_out)) 
                       | (1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__a_arg)));
            }
        } else if ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__operation))) {
            vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__ALUFn = 0U;
        } else {
            vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__ALUFn 
                = (0xffU & ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__a_arg) 
                            >> 1U));
            __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_out 
                = ((0xfeU & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_out)) 
                   | (1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__a_arg)));
        }
    } else if ((2U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__operation))) {
        if ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__operation))) {
            vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__ALUFn 
                = (0xffU & (~ (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__a_arg)));
            __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_out 
                = (1U | (0xfcU & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_out)));
        } else {
            vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__ALUFn = 0U;
        }
    } else if ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__operation))) {
        vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__ALUFn = 0U;
    } else {
        vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__ALUFn 
            = (0xffU & ((IData)(1U) + (~ (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__a_arg))));
        __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_out 
            = ((0xfcU & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_out)) 
               | (((0x80U == (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__a_arg)) 
                   << 1U) | (0U != (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__ALUFn))));
    }
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_out 
        = ((0xf3U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_out)) 
           | ((8U & ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__ALUFn) 
                     >> 4U)) | ((0U == (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__ALUFn)) 
                                << 2U)));
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__Vfuncout 
        = (((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__cc_out) 
            << 8U) | (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__ALUFn));
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU = __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUInst__29__Vfuncout;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__cc_arg 
        = sim_top__DOT__soc__DOT__cpu__DOT__ALU16_CC;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__b_arg 
        = sim_top__DOT__soc__DOT__cpu__DOT__ALU16_B;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__a_arg 
        = sim_top__DOT__soc__DOT__cpu__DOT__ALU16_A;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__operation16 
        = sim_top__DOT__soc__DOT__cpu__DOT__ALU16_OP;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__cc_out 
        = __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__cc_arg;
    if ((4U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__operation16))) {
        vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__ALUFn 
            = ((2U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__operation16))
                ? 0U : ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__operation16))
                         ? 0U : (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__a_arg)));
    } else if ((2U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__operation16))) {
        if ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__operation16))) {
            __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__cc_out 
                = ((0xfeU & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__cc_out)) 
                   | (1U & (((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__a_arg) 
                             - (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__b_arg)) 
                            >> 0x10U)));
            vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__ALUFn 
                = (0xffffU & ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__a_arg) 
                              - (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__b_arg)));
            __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__cc_out 
                = ((0xfdU & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__cc_out)) 
                   | (2U & ((0x3fffeU & ((((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__a_arg) 
                                           >> 0xeU) 
                                          & ((~ ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__b_arg) 
                                                 >> 0xfU)) 
                                             << 1U)) 
                                         & ((~ ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__ALUFn) 
                                                >> 0xfU)) 
                                            << 1U))) 
                            | (0x3fffeU & ((((~ ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__a_arg) 
                                                 >> 0xfU)) 
                                             << 1U) 
                                            & ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__b_arg) 
                                               >> 0xeU)) 
                                           & ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__ALUFn) 
                                              >> 0xeU))))));
        } else {
            vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__ALUFn 
                = __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__b_arg;
            __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__cc_out 
                = (0xfdU & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__cc_out));
        }
    } else if ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__operation16))) {
        __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__cc_out 
            = ((0xfeU & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__cc_out)) 
               | (1U & (((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__a_arg) 
                         + (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__b_arg)) 
                        >> 0x10U)));
        vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__ALUFn 
            = (0xffffU & ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__a_arg) 
                          + (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__b_arg)));
        __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__cc_out 
            = ((0xfdU & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__cc_out)) 
               | (2U & (((((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__a_arg) 
                           & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__b_arg)) 
                          >> 0xeU) & ((~ ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__ALUFn) 
                                          >> 0xfU)) 
                                      << 1U)) | (((
                                                   (~ 
                                                    ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__a_arg) 
                                                     >> 0xfU)) 
                                                   & (~ 
                                                      ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__b_arg) 
                                                       >> 0xfU))) 
                                                  << 1U) 
                                                 & ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__ALUFn) 
                                                    >> 0xeU)))));
    } else {
        __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__cc_out 
            = ((0xfeU & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__cc_out)) 
               | (1U & (((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__a_arg) 
                         - (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__b_arg)) 
                        >> 0x10U)));
        vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__ALUFn 
            = (0xffffU & ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__a_arg) 
                          - (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__b_arg)));
        __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__cc_out 
            = ((0xfdU & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__cc_out)) 
               | (2U & ((0x3fffeU & ((((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__a_arg) 
                                       >> 0xeU) & (
                                                   (~ 
                                                    ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__b_arg) 
                                                     >> 0xfU)) 
                                                   << 1U)) 
                                     & ((~ ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__ALUFn) 
                                            >> 0xfU)) 
                                        << 1U))) | 
                        (0x3fffeU & ((((~ ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__a_arg) 
                                           >> 0xfU)) 
                                       << 1U) & ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__b_arg) 
                                                 >> 0xeU)) 
                                     & ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__ALUFn) 
                                        >> 0xeU))))));
    }
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__cc_out 
        = ((0xfbU & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__cc_out)) 
           | ((0U == (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__ALUFn)) 
              << 2U));
    if ((4U != (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__operation16))) {
        __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__cc_out 
            = ((0xf7U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__cc_out)) 
               | (8U & ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__ALUFn) 
                        >> 0xcU)));
    }
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__Vfuncout 
        = (((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__cc_out) 
            << 0x10U) | (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__ALUFn));
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16 
        = __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16Inst__26__Vfuncout;
    vlSelf->dbg_addr = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt;
    vlSelf->sim_top__DOT__soc__DOT__pa = ((((0x7fU 
                                             == (0x7fU 
                                                 & ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt) 
                                                    >> 9U)))
                                             ? 0x3fU
                                             : ((IData)(vlSelf->sim_top__DOT__soc__DOT__tr)
                                                 ? 
                                                vlSelf->sim_top__DOT__soc__DOT__map_u
                                                [(7U 
                                                  & ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt) 
                                                     >> 0xdU))]
                                                 : 
                                                vlSelf->sim_top__DOT__soc__DOT__map_s
                                                [(7U 
                                                  & ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt) 
                                                     >> 0xdU))])) 
                                           << 0xdU) 
                                          | (0x1fffU 
                                             & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt)));
    if (vlSelf->sim_top__DOT__soc__DOT__l2) {
        vlSelf->sim_top__DOT__soc__DOT__in_io = (0x1ffU 
                                                 == 
                                                 (0x1ffU 
                                                  & ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt) 
                                                     >> 7U)));
        vlSelf->sim_top__DOT__soc__DOT__off = (0x1ffU 
                                               & (0x7fU 
                                                  & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt)));
        vlSelf->sim_top__DOT__soc__DOT__ta = ((~ (IData)(vlSelf->sim_top__DOT__soc__DOT__in_io)) 
                                              & (IData)(
                                                        ((0x7ffb0U 
                                                          == 
                                                          (0x3ffff8U 
                                                           & vlSelf->sim_top__DOT__soc__DOT__pa_r)) 
                                                         & (6U 
                                                            >= 
                                                            (7U 
                                                             & vlSelf->sim_top__DOT__soc__DOT__pa_r)))));
    } else {
        vlSelf->sim_top__DOT__soc__DOT__in_io = (0x70U 
                                                 == 
                                                 (0x7fU 
                                                  & ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt) 
                                                     >> 9U)));
        vlSelf->sim_top__DOT__soc__DOT__off = (0x1ffU 
                                               & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt));
        vlSelf->sim_top__DOT__soc__DOT__ta = 0U;
    }
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl_rdata 
        = ((4U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__off) 
                  - (IData)(1U))) ? ((2U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__off) 
                                            - (IData)(1U)))
                                      ? 0U : ((1U & 
                                               ((IData)(vlSelf->sim_top__DOT__soc__DOT__off) 
                                                - (IData)(1U)))
                                               ? 0U
                                               : (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__ext_rd)))
            : ((2U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__off) 
                      - (IData)(1U))) ? ((1U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__off) 
                                                - (IData)(1U)))
                                          ? (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx)
                                          : 1U) : (
                                                   (1U 
                                                    & ((IData)(vlSelf->sim_top__DOT__soc__DOT__off) 
                                                       - (IData)(1U)))
                                                    ? 
                                                   ((((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__c_run) 
                                                      & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__c_hold))) 
                                                     << 3U) 
                                                    | (((((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__c_run) 
                                                          & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__c_hold))) 
                                                         & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Halt_FF)) 
                                                        << 2U) 
                                                       | (((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__pend_m2s) 
                                                           << 1U) 
                                                          | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__pend_s2m))))
                                                    : 
                                                   (((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__c_ien) 
                                                     << 4U) 
                                                    | (((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__c_firq) 
                                                        << 3U) 
                                                       | (((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__c_shr) 
                                                           << 2U) 
                                                          | (((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__c_hold) 
                                                              << 1U) 
                                                             | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__c_run))))))));
    vlSelf->sim_top__DOT__soc__DOT__io_rdata = 0U;
    if (vlSelf->sim_top__DOT__soc__DOT__io_acia) {
        vlSelf->sim_top__DOT__soc__DOT__io_rdata = 
            ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__off))
              ? (IData)(vlSelf->sim_top__DOT__soc__DOT__acia__DOT__rdata_r)
              : (IData)(vlSelf->sim_top__DOT__soc__DOT__acia__DOT__status_r));
    } else if (((IData)(vlSelf->sim_top__DOT__soc__DOT__io_timer) 
                | (IData)(vlSelf->sim_top__DOT__soc__DOT__io_ta))) {
        vlSelf->sim_top__DOT__soc__DOT__io_rdata = 
            ((0U == (7U & (IData)(vlSelf->sim_top__DOT__soc__DOT__off)))
              ? (IData)(vlSelf->sim_top__DOT__soc__DOT__timer__DOT__r0)
              : ((7U == (7U & (IData)(vlSelf->sim_top__DOT__soc__DOT__off)))
                  ? 0U : ((5U >= (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__off) 
                                        - (IData)(1U))))
                           ? vlSelf->sim_top__DOT__soc__DOT__timer__DOT__l
                          [(7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__off) 
                                  - (IData)(1U)))] : 0U)));
    } else if (vlSelf->sim_top__DOT__soc__DOT__io_xl) {
        vlSelf->sim_top__DOT__soc__DOT__io_rdata = vlSelf->sim_top__DOT__soc__DOT__xl_rdata;
    } else if (vlSelf->sim_top__DOT__soc__DOT__io_mmu) {
        vlSelf->sim_top__DOT__soc__DOT__io_rdata = vlSelf->sim_top__DOT__soc__DOT__tr_raw;
    } else if (vlSelf->sim_top__DOT__soc__DOT__io_map) {
        vlSelf->sim_top__DOT__soc__DOT__io_rdata = 
            ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__off))
              ? vlSelf->sim_top__DOT__soc__DOT__map_u
             [(7U & (IData)(vlSelf->sim_top__DOT__soc__DOT__off))]
              : vlSelf->sim_top__DOT__soc__DOT__map_s
             [(7U & (IData)(vlSelf->sim_top__DOT__soc__DOT__off))]);
    } else if (vlSelf->sim_top__DOT__soc__DOT__io_disk) {
        vlSelf->sim_top__DOT__soc__DOT__io_rdata = 
            ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__off))
              ? ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__off))
                  ? ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__off))
                      ? (IData)(vlSelf->sim_top__DOT__soc__DOT__d_47)
                      : (IData)(vlSelf->sim_top__DOT__soc__DOT__d_bufl))
                  : ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__off))
                      ? (IData)(vlSelf->sim_top__DOT__soc__DOT__d_bufh)
                      : (IData)(vlSelf->sim_top__DOT__soc__DOT__d_lsn0)))
              : ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__off))
                  ? ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__off))
                      ? (IData)(vlSelf->sim_top__DOT__soc__DOT__d_lsn1)
                      : (IData)(vlSelf->sim_top__DOT__soc__DOT__d_lsn2))
                  : ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__off))
                      ? (IData)(vlSelf->sim_top__DOT__soc__DOT__d_drive)
                      : (IData)(vlSelf->sim_top__DOT__soc__DOT__e040))));
    }
}

void Vsim_top___024root___eval_act(Vsim_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___eval_act\n"); );
    // Body
    if (vlSelf->__VactTriggered.at(1U)) {
        Vsim_top___024root___act_sequent__TOP__0(vlSelf);
    }
    if ((vlSelf->__VactTriggered.at(0U) | vlSelf->__VactTriggered.at(1U))) {
        Vsim_top___024root___act_comb__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vsim_top___024root___nba_sequent__TOP__0(Vsim_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*7:0*/ __Vfunc_sim_top__DOT__soc__DOT__timer__DOT__dim__48__Vfuncout;
    __Vfunc_sim_top__DOT__soc__DOT__timer__DOT__dim__48__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_sim_top__DOT__soc__DOT__timer__DOT__dim__48__yr;
    __Vfunc_sim_top__DOT__soc__DOT__timer__DOT__dim__48__yr = 0;
    CData/*7:0*/ __Vfunc_sim_top__DOT__soc__DOT__timer__DOT__dim__48__m;
    __Vfunc_sim_top__DOT__soc__DOT__timer__DOT__dim__48__m = 0;
    CData/*7:0*/ __Vtask_sim_top__DOT__soc__DOT__disk__DOT__xfer__53__b;
    __Vtask_sim_top__DOT__soc__DOT__disk__DOT__xfer__53__b = 0;
    IData/*31:0*/ __Vtask_sim_top__DOT__soc__DOT__disk__DOT__send_cmd__56__arg;
    __Vtask_sim_top__DOT__soc__DOT__disk__DOT__send_cmd__56__arg = 0;
    IData/*31:0*/ __Vtask_sim_top__DOT__soc__DOT__disk__DOT__send_cmd__60__arg;
    __Vtask_sim_top__DOT__soc__DOT__disk__DOT__send_cmd__60__arg = 0;
    CData/*7:0*/ __Vtask_sim_top__DOT__soc__DOT__disk__DOT__xfer__64__b;
    __Vtask_sim_top__DOT__soc__DOT__disk__DOT__xfer__64__b = 0;
    CData/*5:0*/ __Vfunc_sim_top__DOT__soc__DOT__disk__DOT__retmap__65__Vfuncout;
    __Vfunc_sim_top__DOT__soc__DOT__disk__DOT__retmap__65__Vfuncout = 0;
    CData/*5:0*/ __Vfunc_sim_top__DOT__soc__DOT__disk__DOT__retmap__65__c;
    __Vfunc_sim_top__DOT__soc__DOT__disk__DOT__retmap__65__c = 0;
    IData/*31:0*/ __Vtask_sim_top__DOT__soc__DOT__disk__DOT__send_cmd__69__arg;
    __Vtask_sim_top__DOT__soc__DOT__disk__DOT__send_cmd__69__arg = 0;
    CData/*0:0*/ __Vdly__sim_top__DOT__soc__DOT__acc_go;
    __Vdly__sim_top__DOT__soc__DOT__acc_go = 0;
    CData/*0:0*/ __Vdly__sim_top__DOT__soc__DOT__c_wr;
    __Vdly__sim_top__DOT__soc__DOT__c_wr = 0;
    CData/*0:0*/ __Vdly__sim_top__DOT__soc__DOT__t_rd;
    __Vdly__sim_top__DOT__soc__DOT__t_rd = 0;
    CData/*0:0*/ __Vdly__sim_top__DOT__soc__DOT__ld_start;
    __Vdly__sim_top__DOT__soc__DOT__ld_start = 0;
    CData/*0:0*/ __Vdly__sim_top__DOT__soc__DOT__st_wr;
    __Vdly__sim_top__DOT__soc__DOT__st_wr = 0;
    CData/*0:0*/ __Vdly__sim_top__DOT__soc__DOT__st_d;
    __Vdly__sim_top__DOT__soc__DOT__st_d = 0;
    CData/*0:0*/ __Vdly__sim_top__DOT__soc__DOT__st_d2;
    __Vdly__sim_top__DOT__soc__DOT__st_d2 = 0;
    CData/*0:0*/ __Vdly__sim_top__DOT__soc__DOT__dgo;
    __Vdly__sim_top__DOT__soc__DOT__dgo = 0;
    CData/*7:0*/ __Vdly__sim_top__DOT__soc__DOT__d_drive;
    __Vdly__sim_top__DOT__soc__DOT__d_drive = 0;
    CData/*0:0*/ __Vdly__sim_top__DOT__soc__DOT__xw_rdp;
    __Vdly__sim_top__DOT__soc__DOT__xw_rdp = 0;
    CData/*0:0*/ __Vdly__sim_top__DOT__soc__DOT__xw_wrp;
    __Vdly__sim_top__DOT__soc__DOT__xw_wrp = 0;
    CData/*0:0*/ __Vdly__sim_top__DOT__soc__DOT__win_ack_r;
    __Vdly__sim_top__DOT__soc__DOT__win_ack_r = 0;
    CData/*0:0*/ __Vdly__sim_top__DOT__soc__DOT__xw_go;
    __Vdly__sim_top__DOT__soc__DOT__xw_go = 0;
    CData/*0:0*/ __Vdly__sim_top__DOT__soc__DOT__win_wr_q;
    __Vdly__sim_top__DOT__soc__DOT__win_wr_q = 0;
    CData/*0:0*/ __Vdly__sim_top__DOT__soc__DOT__loader__DOT__sgo;
    __Vdly__sim_top__DOT__soc__DOT__loader__DOT__sgo = 0;
    CData/*1:0*/ __Vdly__sim_top__DOT__soc__DOT__acia__DOT__rxs;
    __Vdly__sim_top__DOT__soc__DOT__acia__DOT__rxs = 0;
    CData/*0:0*/ __Vdly__sim_top__DOT__soc__DOT__acia__DOT__rbusy;
    __Vdly__sim_top__DOT__soc__DOT__acia__DOT__rbusy = 0;
    CData/*3:0*/ __Vdly__sim_top__DOT__soc__DOT__acia__DOT__rbit;
    __Vdly__sim_top__DOT__soc__DOT__acia__DOT__rbit = 0;
    CData/*7:0*/ __Vdly__sim_top__DOT__soc__DOT__acia__DOT__rsh;
    __Vdly__sim_top__DOT__soc__DOT__acia__DOT__rsh = 0;
    CData/*7:0*/ __Vdly__sim_top__DOT__soc__DOT__acia__DOT__wp;
    __Vdly__sim_top__DOT__soc__DOT__acia__DOT__wp = 0;
    CData/*7:0*/ __Vdlyvdim0__sim_top__DOT__soc__DOT__acia__DOT__fifo__v0;
    __Vdlyvdim0__sim_top__DOT__soc__DOT__acia__DOT__fifo__v0 = 0;
    CData/*7:0*/ __Vdlyvval__sim_top__DOT__soc__DOT__acia__DOT__fifo__v0;
    __Vdlyvval__sim_top__DOT__soc__DOT__acia__DOT__fifo__v0 = 0;
    CData/*0:0*/ __Vdlyvset__sim_top__DOT__soc__DOT__acia__DOT__fifo__v0;
    __Vdlyvset__sim_top__DOT__soc__DOT__acia__DOT__fifo__v0 = 0;
    CData/*7:0*/ __Vdly__sim_top__DOT__soc__DOT__acia__DOT__rp;
    __Vdly__sim_top__DOT__soc__DOT__acia__DOT__rp = 0;
    CData/*0:0*/ __Vdly__sim_top__DOT__soc__DOT__acia__DOT__tbusy;
    __Vdly__sim_top__DOT__soc__DOT__acia__DOT__tbusy = 0;
    SData/*9:0*/ __Vdly__sim_top__DOT__soc__DOT__acia__DOT__tsh;
    __Vdly__sim_top__DOT__soc__DOT__acia__DOT__tsh = 0;
    CData/*7:0*/ __Vdly__sim_top__DOT__soc__DOT__timer__DOT__y;
    __Vdly__sim_top__DOT__soc__DOT__timer__DOT__y = 0;
    CData/*7:0*/ __Vdly__sim_top__DOT__soc__DOT__timer__DOT__mo;
    __Vdly__sim_top__DOT__soc__DOT__timer__DOT__mo = 0;
    CData/*7:0*/ __Vdly__sim_top__DOT__soc__DOT__timer__DOT__d;
    __Vdly__sim_top__DOT__soc__DOT__timer__DOT__d = 0;
    CData/*7:0*/ __Vdly__sim_top__DOT__soc__DOT__timer__DOT__h;
    __Vdly__sim_top__DOT__soc__DOT__timer__DOT__h = 0;
    CData/*7:0*/ __Vdly__sim_top__DOT__soc__DOT__timer__DOT__mi;
    __Vdly__sim_top__DOT__soc__DOT__timer__DOT__mi = 0;
    CData/*7:0*/ __Vdly__sim_top__DOT__soc__DOT__timer__DOT__s;
    __Vdly__sim_top__DOT__soc__DOT__timer__DOT__s = 0;
    SData/*10:0*/ __Vdly__sim_top__DOT__soc__DOT__timer__DOT__slo;
    __Vdly__sim_top__DOT__soc__DOT__timer__DOT__slo = 0;
    SData/*10:0*/ __Vdly__sim_top__DOT__soc__DOT__timer__DOT__shi;
    __Vdly__sim_top__DOT__soc__DOT__timer__DOT__shi = 0;
    CData/*0:0*/ __Vdly__sim_top__DOT__soc__DOT__timer__DOT__scarry;
    __Vdly__sim_top__DOT__soc__DOT__timer__DOT__scarry = 0;
    CData/*0:0*/ __Vdlyvset__sim_top__DOT__soc__DOT__timer__DOT__l__v0;
    __Vdlyvset__sim_top__DOT__soc__DOT__timer__DOT__l__v0 = 0;
    CData/*7:0*/ __Vdlyvval__sim_top__DOT__soc__DOT__timer__DOT__l__v6;
    __Vdlyvval__sim_top__DOT__soc__DOT__timer__DOT__l__v6 = 0;
    CData/*0:0*/ __Vdlyvset__sim_top__DOT__soc__DOT__timer__DOT__l__v6;
    __Vdlyvset__sim_top__DOT__soc__DOT__timer__DOT__l__v6 = 0;
    CData/*7:0*/ __Vdlyvval__sim_top__DOT__soc__DOT__timer__DOT__l__v7;
    __Vdlyvval__sim_top__DOT__soc__DOT__timer__DOT__l__v7 = 0;
    CData/*7:0*/ __Vdlyvval__sim_top__DOT__soc__DOT__timer__DOT__l__v8;
    __Vdlyvval__sim_top__DOT__soc__DOT__timer__DOT__l__v8 = 0;
    CData/*7:0*/ __Vdlyvval__sim_top__DOT__soc__DOT__timer__DOT__l__v9;
    __Vdlyvval__sim_top__DOT__soc__DOT__timer__DOT__l__v9 = 0;
    CData/*7:0*/ __Vdlyvval__sim_top__DOT__soc__DOT__timer__DOT__l__v10;
    __Vdlyvval__sim_top__DOT__soc__DOT__timer__DOT__l__v10 = 0;
    CData/*7:0*/ __Vdlyvval__sim_top__DOT__soc__DOT__timer__DOT__l__v11;
    __Vdlyvval__sim_top__DOT__soc__DOT__timer__DOT__l__v11 = 0;
    CData/*2:0*/ __Vdlyvdim0__sim_top__DOT__soc__DOT__timer__DOT__l__v12;
    __Vdlyvdim0__sim_top__DOT__soc__DOT__timer__DOT__l__v12 = 0;
    CData/*7:0*/ __Vdlyvval__sim_top__DOT__soc__DOT__timer__DOT__l__v12;
    __Vdlyvval__sim_top__DOT__soc__DOT__timer__DOT__l__v12 = 0;
    CData/*0:0*/ __Vdlyvset__sim_top__DOT__soc__DOT__timer__DOT__l__v12;
    __Vdlyvset__sim_top__DOT__soc__DOT__timer__DOT__l__v12 = 0;
    CData/*0:0*/ __Vdly__sim_top__DOT__soc__DOT__disk__DOT__spi_done;
    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__spi_done = 0;
    CData/*0:0*/ __Vdly__sim_top__DOT__soc__DOT__disk__DOT__spi_busy;
    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__spi_busy = 0;
    CData/*0:0*/ __Vdly__sd_clk;
    __Vdly__sd_clk = 0;
    CData/*3:0*/ __Vdly__sim_top__DOT__soc__DOT__disk__DOT__bcnt;
    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__bcnt = 0;
    CData/*7:0*/ __Vdly__sim_top__DOT__soc__DOT__disk__DOT__spi_rx;
    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__spi_rx = 0;
    CData/*0:0*/ __Vdly__sim_top__DOT__soc__DOT__disk__DOT__hit_q;
    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__hit_q = 0;
    CData/*7:0*/ __Vdly__sim_top__DOT__soc__DOT__disk__DOT__cnt_lo;
    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__cnt_lo = 0;
    SData/*12:0*/ __Vdly__sim_top__DOT__soc__DOT__disk__DOT__cnt_hi;
    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__cnt_hi = 0;
    CData/*0:0*/ __Vdly__sim_top__DOT__soc__DOT__disk__DOT__wr_r;
    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__wr_r = 0;
    SData/*15:0*/ __Vdly__sim_top__DOT__soc__DOT__disk__DOT__buf_r;
    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__buf_r = 0;
    IData/*21:0*/ __Vdly__sim_top__DOT__soc__DOT__d_addr;
    __Vdly__sim_top__DOT__soc__DOT__d_addr = 0;
    CData/*5:0*/ __Vdly__sim_top__DOT__soc__DOT__disk__DOT__caller;
    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__caller = 0;
    CData/*0:0*/ __Vdly__sim_top__DOT__soc__DOT__disk__DOT__pend;
    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__pend = 0;
    CData/*5:0*/ __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st;
    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st = 0;
    SData/*9:0*/ __Vdly__sim_top__DOT__soc__DOT__disk__DOT__idx;
    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__idx = 0;
    CData/*1:0*/ __Vdly__sim_top__DOT__soc__DOT__disk__DOT__skipn;
    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__skipn = 0;
    CData/*5:0*/ __Vdly__sim_top__DOT__soc__DOT__disk__DOT__skip_next;
    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__skip_next = 0;
    QData/*47:0*/ __Vdly__sim_top__DOT__soc__DOT__disk__DOT__cbuf;
    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__cbuf = 0;
    CData/*2:0*/ __Vdly__sim_top__DOT__soc__DOT__disk__DOT__cstep;
    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__cstep = 0;
    CData/*4:0*/ __Vdly__sim_top__DOT__soc__DOT__disk__DOT__tries;
    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__tries = 0;
    CData/*5:0*/ __Vdly__sim_top__DOT__soc__DOT__disk__DOT__cmd_next;
    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__cmd_next = 0;
    CData/*1:0*/ __Vdly__sim_top__DOT__soc__DOT__disk__DOT__rbytes;
    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__rbytes = 0;
    IData/*31:0*/ __Vdly__sim_top__DOT__soc__DOT__disk__DOT__rword;
    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__rword = 0;
    CData/*0:0*/ __Vdly__sim_top__DOT__soc__DOT__disk__DOT__r1_ok;
    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__r1_ok = 0;
    CData/*0:0*/ __Vdly__sim_top__DOT__soc__DOT__disk__DOT__r1_idle;
    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__r1_idle = 0;
    CData/*0:0*/ __Vdly__sim_top__DOT__soc__DOT__disk__DOT__r1_ill;
    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__r1_ill = 0;
    CData/*0:0*/ __Vdly__sim_top__DOT__soc__DOT__m0_ack;
    __Vdly__sim_top__DOT__soc__DOT__m0_ack = 0;
    CData/*0:0*/ __Vdly__sim_top__DOT__soc__DOT__zm_ack;
    __Vdly__sim_top__DOT__soc__DOT__zm_ack = 0;
    CData/*2:0*/ __Vdly__sim_top__DOT__soc__DOT__sub__DOT__zrel;
    __Vdly__sim_top__DOT__soc__DOT__sub__DOT__zrel = 0;
    CData/*2:0*/ __Vdlyvdim0__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_reg__DOT__RegsH__v0;
    __Vdlyvdim0__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_reg__DOT__RegsH__v0 = 0;
    CData/*7:0*/ __Vdlyvval__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_reg__DOT__RegsH__v0;
    __Vdlyvval__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_reg__DOT__RegsH__v0 = 0;
    CData/*0:0*/ __Vdlyvset__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_reg__DOT__RegsH__v0;
    __Vdlyvset__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_reg__DOT__RegsH__v0 = 0;
    CData/*2:0*/ __Vdlyvdim0__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_reg__DOT__RegsL__v0;
    __Vdlyvdim0__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_reg__DOT__RegsL__v0 = 0;
    CData/*7:0*/ __Vdlyvval__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_reg__DOT__RegsL__v0;
    __Vdlyvval__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_reg__DOT__RegsL__v0 = 0;
    CData/*0:0*/ __Vdlyvset__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_reg__DOT__RegsL__v0;
    __Vdlyvset__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_reg__DOT__RegsL__v0 = 0;
    IData/*31:0*/ __Vdly__sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__clk_cnt;
    __Vdly__sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__clk_cnt = 0;
    CData/*6:0*/ __Vdlyvdim0__sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__smmu__v0;
    __Vdlyvdim0__sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__smmu__v0 = 0;
    CData/*7:0*/ __Vdlyvval__sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__smmu__v0;
    __Vdlyvval__sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__smmu__v0 = 0;
    CData/*0:0*/ __Vdlyvset__sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__smmu__v0;
    __Vdlyvset__sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__smmu__v0 = 0;
    IData/*20:0*/ __Vdlyvdim0__sim_top__DOT__mem__DOT__mem__v0;
    __Vdlyvdim0__sim_top__DOT__mem__DOT__mem__v0 = 0;
    CData/*3:0*/ __Vdlyvlsb__sim_top__DOT__mem__DOT__mem__v0;
    __Vdlyvlsb__sim_top__DOT__mem__DOT__mem__v0 = 0;
    CData/*7:0*/ __Vdlyvval__sim_top__DOT__mem__DOT__mem__v0;
    __Vdlyvval__sim_top__DOT__mem__DOT__mem__v0 = 0;
    CData/*0:0*/ __Vdlyvset__sim_top__DOT__mem__DOT__mem__v0;
    __Vdlyvset__sim_top__DOT__mem__DOT__mem__v0 = 0;
    IData/*20:0*/ __Vdlyvdim0__sim_top__DOT__mem__DOT__mem__v1;
    __Vdlyvdim0__sim_top__DOT__mem__DOT__mem__v1 = 0;
    CData/*3:0*/ __Vdlyvlsb__sim_top__DOT__mem__DOT__mem__v1;
    __Vdlyvlsb__sim_top__DOT__mem__DOT__mem__v1 = 0;
    CData/*7:0*/ __Vdlyvval__sim_top__DOT__mem__DOT__mem__v1;
    __Vdlyvval__sim_top__DOT__mem__DOT__mem__v1 = 0;
    CData/*0:0*/ __Vdlyvset__sim_top__DOT__mem__DOT__mem__v1;
    __Vdlyvset__sim_top__DOT__mem__DOT__mem__v1 = 0;
    IData/*20:0*/ __Vdlyvdim0__sim_top__DOT__mem__DOT__mem__v2;
    __Vdlyvdim0__sim_top__DOT__mem__DOT__mem__v2 = 0;
    SData/*15:0*/ __Vdlyvval__sim_top__DOT__mem__DOT__mem__v2;
    __Vdlyvval__sim_top__DOT__mem__DOT__mem__v2 = 0;
    CData/*0:0*/ __Vdlyvset__sim_top__DOT__mem__DOT__mem__v2;
    __Vdlyvset__sim_top__DOT__mem__DOT__mem__v2 = 0;
    SData/*11:0*/ __Vdly__sim_top__DOT__mem__DOT__refresh;
    __Vdly__sim_top__DOT__mem__DOT__refresh = 0;
    // Body
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__settle 
        = vlSelf->sim_top__DOT__soc__DOT__settle;
    __Vdly__sim_top__DOT__soc__DOT__acia__DOT__rp = vlSelf->sim_top__DOT__soc__DOT__acia__DOT__rp;
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__xl_cnt 
        = vlSelf->sim_top__DOT__soc__DOT__xl_cnt;
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cnt 
        = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cnt;
    __Vdly__sim_top__DOT__soc__DOT__acia__DOT__rsh 
        = vlSelf->sim_top__DOT__soc__DOT__acia__DOT__rsh;
    __Vdly__sim_top__DOT__soc__DOT__acia__DOT__rbit 
        = vlSelf->sim_top__DOT__soc__DOT__acia__DOT__rbit;
    __Vdly__sim_top__DOT__soc__DOT__acia__DOT__rbusy 
        = vlSelf->sim_top__DOT__soc__DOT__acia__DOT__rbusy;
    __Vdly__sim_top__DOT__soc__DOT__acia__DOT__rxs 
        = vlSelf->sim_top__DOT__soc__DOT__acia__DOT__rxs;
    __Vdly__sim_top__DOT__soc__DOT__sub__DOT__zrel 
        = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__zrel;
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__bcnt 
        = vlSelf->sim_top__DOT__soc__DOT__loader__DOT__bcnt;
    vlSelf->__Vdly__fl_clk = vlSelf->fl_clk;
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__sbusy 
        = vlSelf->sim_top__DOT__soc__DOT__loader__DOT__sbusy;
    __Vdly__sim_top__DOT__soc__DOT__acia__DOT__tsh 
        = vlSelf->sim_top__DOT__soc__DOT__acia__DOT__tsh;
    __Vdly__sim_top__DOT__soc__DOT__acia__DOT__tbusy 
        = vlSelf->sim_top__DOT__soc__DOT__acia__DOT__tbusy;
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__acia__DOT__tfull 
        = vlSelf->sim_top__DOT__soc__DOT__acia__DOT__tfull;
    __Vdlyvset__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_reg__DOT__RegsL__v0 = 0U;
    __Vdlyvset__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_reg__DOT__RegsH__v0 = 0U;
    __Vdly__sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__clk_cnt 
        = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__clk_cnt;
    __Vdlyvset__sim_top__DOT__soc__DOT__acia__DOT__fifo__v0 = 0U;
    __Vdly__sim_top__DOT__soc__DOT__acia__DOT__wp = vlSelf->sim_top__DOT__soc__DOT__acia__DOT__wp;
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__stx 
        = vlSelf->sim_top__DOT__soc__DOT__loader__DOT__stx;
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__n 
        = vlSelf->sim_top__DOT__soc__DOT__loader__DOT__n;
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__ci 
        = vlSelf->sim_top__DOT__soc__DOT__loader__DOT__ci;
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__cmd 
        = vlSelf->sim_top__DOT__soc__DOT__loader__DOT__cmd;
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__pi 
        = vlSelf->sim_top__DOT__soc__DOT__loader__DOT__pi;
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__st 
        = vlSelf->sim_top__DOT__soc__DOT__loader__DOT__st;
    __Vdly__sim_top__DOT__soc__DOT__loader__DOT__sgo 
        = vlSelf->sim_top__DOT__soc__DOT__loader__DOT__sgo;
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx 
        = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx;
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__win_busy 
        = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__win_busy;
    __Vdlyvset__sim_top__DOT__soc__DOT__timer__DOT__l__v0 = 0U;
    __Vdlyvset__sim_top__DOT__soc__DOT__timer__DOT__l__v6 = 0U;
    __Vdlyvset__sim_top__DOT__soc__DOT__timer__DOT__l__v12 = 0U;
    __Vdlyvset__sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__smmu__v0 = 0U;
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__arb__DOT__st 
        = vlSelf->sim_top__DOT__soc__DOT__arb__DOT__st;
    __Vdly__sim_top__DOT__soc__DOT__zm_ack = vlSelf->sim_top__DOT__soc__DOT__zm_ack;
    __Vdly__sim_top__DOT__soc__DOT__m0_ack = vlSelf->sim_top__DOT__soc__DOT__m0_ack;
    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__r1_ill 
        = vlSelf->sim_top__DOT__soc__DOT__disk__DOT__r1_ill;
    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__r1_idle 
        = vlSelf->sim_top__DOT__soc__DOT__disk__DOT__r1_idle;
    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__r1_ok 
        = vlSelf->sim_top__DOT__soc__DOT__disk__DOT__r1_ok;
    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__rword 
        = vlSelf->sim_top__DOT__soc__DOT__disk__DOT__rword;
    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__rbytes 
        = vlSelf->sim_top__DOT__soc__DOT__disk__DOT__rbytes;
    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__cmd_next 
        = vlSelf->sim_top__DOT__soc__DOT__disk__DOT__cmd_next;
    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__tries 
        = vlSelf->sim_top__DOT__soc__DOT__disk__DOT__tries;
    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__cstep 
        = vlSelf->sim_top__DOT__soc__DOT__disk__DOT__cstep;
    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__cbuf 
        = vlSelf->sim_top__DOT__soc__DOT__disk__DOT__cbuf;
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__disk__DOT__b_raddr 
        = vlSelf->sim_top__DOT__soc__DOT__disk__DOT__b_raddr;
    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__skip_next 
        = vlSelf->sim_top__DOT__soc__DOT__disk__DOT__skip_next;
    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__skipn 
        = vlSelf->sim_top__DOT__soc__DOT__disk__DOT__skipn;
    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__idx 
        = vlSelf->sim_top__DOT__soc__DOT__disk__DOT__idx;
    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st = vlSelf->sim_top__DOT__soc__DOT__disk__DOT__st;
    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__caller 
        = vlSelf->sim_top__DOT__soc__DOT__disk__DOT__caller;
    __Vdly__sim_top__DOT__soc__DOT__d_addr = vlSelf->sim_top__DOT__soc__DOT__d_addr;
    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__pend 
        = vlSelf->sim_top__DOT__soc__DOT__disk__DOT__pend;
    __Vdly__sim_top__DOT__soc__DOT__win_wr_q = vlSelf->sim_top__DOT__soc__DOT__win_wr_q;
    __Vdly__sim_top__DOT__soc__DOT__xw_go = vlSelf->sim_top__DOT__soc__DOT__xw_go;
    __Vdly__sim_top__DOT__soc__DOT__win_ack_r = vlSelf->sim_top__DOT__soc__DOT__win_ack_r;
    __Vdly__sim_top__DOT__soc__DOT__xw_rdp = vlSelf->sim_top__DOT__soc__DOT__xw_rdp;
    __Vdly__sim_top__DOT__soc__DOT__xw_wrp = vlSelf->sim_top__DOT__soc__DOT__xw_wrp;
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__xw_act 
        = vlSelf->sim_top__DOT__soc__DOT__xw_act;
    __Vdly__sim_top__DOT__soc__DOT__dgo = vlSelf->sim_top__DOT__soc__DOT__dgo;
    __Vdly__sim_top__DOT__soc__DOT__d_drive = vlSelf->sim_top__DOT__soc__DOT__d_drive;
    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__wr_r 
        = vlSelf->sim_top__DOT__soc__DOT__disk__DOT__wr_r;
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__c_isrd 
        = vlSelf->sim_top__DOT__soc__DOT__c_isrd;
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__mp_wait 
        = vlSelf->sim_top__DOT__soc__DOT__mp_wait;
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__mem_pend 
        = vlSelf->sim_top__DOT__soc__DOT__mem_pend;
    vlSelf->__Vdlyvset__sim_top__DOT__soc__DOT__map_u__v16 = 0U;
    vlSelf->__Vdlyvset__sim_top__DOT__soc__DOT__map_s__v9 = 0U;
    vlSelf->__Vdlyvset__sim_top__DOT__soc__DOT__map_s__v26 = 0U;
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__l2 = vlSelf->sim_top__DOT__soc__DOT__l2;
    vlSelf->__Vdlyvset__sim_top__DOT__soc__DOT__map_s__v0 = 0U;
    vlSelf->__Vdlyvset__sim_top__DOT__soc__DOT__map_s__v1 = 0U;
    vlSelf->__Vdlyvset__sim_top__DOT__soc__DOT__map_s__v17 = 0U;
    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__cnt_hi 
        = vlSelf->sim_top__DOT__soc__DOT__disk__DOT__cnt_hi;
    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__cnt_lo 
        = vlSelf->sim_top__DOT__soc__DOT__disk__DOT__cnt_lo;
    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__hit_q 
        = vlSelf->sim_top__DOT__soc__DOT__disk__DOT__hit_q;
    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__buf_r 
        = vlSelf->sim_top__DOT__soc__DOT__disk__DOT__buf_r;
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__ph = vlSelf->sim_top__DOT__soc__DOT__ph;
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__div = vlSelf->sim_top__DOT__soc__DOT__div;
    __Vdly__sim_top__DOT__soc__DOT__acc_go = vlSelf->sim_top__DOT__soc__DOT__acc_go;
    __Vdly__sim_top__DOT__soc__DOT__timer__DOT__scarry 
        = vlSelf->sim_top__DOT__soc__DOT__timer__DOT__scarry;
    __Vdly__sim_top__DOT__soc__DOT__timer__DOT__shi 
        = vlSelf->sim_top__DOT__soc__DOT__timer__DOT__shi;
    __Vdly__sim_top__DOT__soc__DOT__timer__DOT__slo 
        = vlSelf->sim_top__DOT__soc__DOT__timer__DOT__slo;
    __Vdly__sim_top__DOT__soc__DOT__timer__DOT__s = vlSelf->sim_top__DOT__soc__DOT__timer__DOT__s;
    __Vdly__sim_top__DOT__soc__DOT__timer__DOT__mi 
        = vlSelf->sim_top__DOT__soc__DOT__timer__DOT__mi;
    __Vdly__sim_top__DOT__soc__DOT__timer__DOT__h = vlSelf->sim_top__DOT__soc__DOT__timer__DOT__h;
    __Vdly__sim_top__DOT__soc__DOT__timer__DOT__d = vlSelf->sim_top__DOT__soc__DOT__timer__DOT__d;
    __Vdly__sim_top__DOT__soc__DOT__timer__DOT__mo 
        = vlSelf->sim_top__DOT__soc__DOT__timer__DOT__mo;
    __Vdly__sim_top__DOT__soc__DOT__timer__DOT__y = vlSelf->sim_top__DOT__soc__DOT__timer__DOT__y;
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__m0_addr 
        = vlSelf->sim_top__DOT__soc__DOT__m0_addr;
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__timer__DOT__tcnt 
        = vlSelf->sim_top__DOT__soc__DOT__timer__DOT__tcnt;
    vlSelf->__Vdlyvset__sim_top__DOT__soc__DOT__disk__DOT__bram__v0 = 0U;
    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__spi_rx 
        = vlSelf->sim_top__DOT__soc__DOT__disk__DOT__spi_rx;
    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__bcnt 
        = vlSelf->sim_top__DOT__soc__DOT__disk__DOT__bcnt;
    __Vdly__sd_clk = vlSelf->sd_clk;
    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__spi_busy 
        = vlSelf->sim_top__DOT__soc__DOT__disk__DOT__spi_busy;
    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__spi_done 
        = vlSelf->sim_top__DOT__soc__DOT__disk__DOT__spi_done;
    __Vdly__sim_top__DOT__mem__DOT__refresh = vlSelf->sim_top__DOT__mem__DOT__refresh;
    vlSelf->__Vdly__sim_top__DOT__ps_dout = vlSelf->sim_top__DOT__ps_dout;
    vlSelf->__Vdly__sim_top__DOT__mem__DOT__cnt = vlSelf->sim_top__DOT__mem__DOT__cnt;
    __Vdlyvset__sim_top__DOT__mem__DOT__mem__v0 = 0U;
    __Vdlyvset__sim_top__DOT__mem__DOT__mem__v1 = 0U;
    __Vdlyvset__sim_top__DOT__mem__DOT__mem__v2 = 0U;
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__mi = vlSelf->sim_top__DOT__soc__DOT__mi;
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__t_faddr 
        = vlSelf->sim_top__DOT__soc__DOT__t_faddr;
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__t_fail 
        = vlSelf->sim_top__DOT__soc__DOT__t_fail;
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__tp = vlSelf->sim_top__DOT__soc__DOT__tp;
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__rcnt = vlSelf->sim_top__DOT__soc__DOT__rcnt;
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__bsy_d = vlSelf->sim_top__DOT__soc__DOT__bsy_d;
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__cw = vlSelf->sim_top__DOT__soc__DOT__cw;
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__cs_ = vlSelf->sim_top__DOT__soc__DOT__cs_;
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__p_go = vlSelf->sim_top__DOT__soc__DOT__p_go;
    __Vdly__sim_top__DOT__soc__DOT__st_d2 = vlSelf->sim_top__DOT__soc__DOT__st_d2;
    __Vdly__sim_top__DOT__soc__DOT__st_d = vlSelf->sim_top__DOT__soc__DOT__st_d;
    __Vdly__sim_top__DOT__soc__DOT__ld_start = vlSelf->sim_top__DOT__soc__DOT__ld_start;
    __Vdly__sim_top__DOT__soc__DOT__st_wr = vlSelf->sim_top__DOT__soc__DOT__st_wr;
    __Vdly__sim_top__DOT__soc__DOT__t_rd = vlSelf->sim_top__DOT__soc__DOT__t_rd;
    __Vdly__sim_top__DOT__soc__DOT__c_wr = vlSelf->sim_top__DOT__soc__DOT__c_wr;
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__di_q 
        = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__di_q;
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__settle 
        = ((0x3eU & ((IData)(vlSelf->sim_top__DOT__soc__DOT__settle) 
                     << 1U)) | ((IData)(vlSelf->sim_top__DOT__soc__DOT__mem_pend) 
                                | (IData)(vlSelf->sim_top__DOT__soc__DOT__disk_busy)));
    vlSelf->sim_top__DOT__soc__DOT__hb = (0xffffffU 
                                          & ((IData)(1U) 
                                             + vlSelf->sim_top__DOT__soc__DOT__hb));
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cnt 
        = (((IData)(vlSelf->sim_top__DOT__soc__DOT__rst) 
            | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cen_raw))
            ? 0U : (0xffU & ((IData)(1U) + (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cnt))));
    if (vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ClkEn) {
        if (vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegWEL) {
            __Vdlyvval__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_reg__DOT__RegsL__v0 
                = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegDIL;
            __Vdlyvset__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_reg__DOT__RegsL__v0 = 1U;
            __Vdlyvdim0__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_reg__DOT__RegsL__v0 
                = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegAddrA;
        }
        if (vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegWEH) {
            __Vdlyvval__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_reg__DOT__RegsH__v0 
                = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegDIH;
            __Vdlyvset__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_reg__DOT__RegsH__v0 = 1U;
            __Vdlyvdim0__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_reg__DOT__RegsH__v0 
                = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegAddrA;
        }
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegBusA_r 
            = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegBusA;
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegAddrC 
            = (((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Alternate) 
                << 2U) | (3U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To)));
        if (((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__JumpXY) 
             | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDSPHL))) {
            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegAddrC 
                = (2U | ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Alternate) 
                         << 2U));
        }
        if ((1U & ((((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__JumpXY) 
                     | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDSPHL)) 
                    & (0U != (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__XY_State))) 
                   | ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                      >> 5U)))) {
            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegAddrC 
                = (3U | (4U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__XY_State) 
                               << 1U)));
        }
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegAddrB_r 
            = (((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Alternate) 
                << 2U) | (3U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To) 
                                >> 1U)));
        if ((((~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__XY_Ind)) 
              & (4U == (6U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To)))) 
             & (0U != (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__XY_State)))) {
            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegAddrB_r 
                = (3U | (4U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__XY_State) 
                               << 1U)));
        }
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegAddrA_r 
            = (((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Alternate) 
                << 2U) | (3U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To) 
                                >> 1U)));
        if ((((~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__XY_Ind)) 
              & (4U == (6U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)))) 
             & (0U != (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__XY_State)))) {
            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegAddrA_r 
                = (3U | (4U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__XY_State) 
                               << 1U)));
        }
    }
    if (vlSelf->sim_top__DOT__soc__DOT__xl_we) {
        if ((1U & (~ (1U & (((IData)(vlSelf->sim_top__DOT__soc__DOT__off) 
                             - (IData)(1U)) >> 2U))))) {
            if ((2U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__off) 
                       - (IData)(1U)))) {
                if ((1U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__off) 
                           - (IData)(1U)))) {
                    vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx 
                        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DOutput;
                }
            }
        }
    }
    if ((((((IData)(vlSelf->sim_top__DOT__soc__DOT__xl_re) 
            | (IData)(vlSelf->sim_top__DOT__soc__DOT__xl_we)) 
           & (4U == (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__off) 
                           - (IData)(1U))))) & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx) 
                                                >> 7U)) 
         & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__win_sel)))) {
        vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx 
            = (0x80U | (0x7fU & ((IData)(1U) + (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__ei))));
    }
    if (vlSelf->sim_top__DOT__soc__DOT__disk__DOT__c_clr) {
        __Vdly__sim_top__DOT__soc__DOT__disk__DOT__cnt_lo = 0U;
        __Vdly__sim_top__DOT__soc__DOT__disk__DOT__cnt_hi = 0U;
    } else if (vlSelf->sim_top__DOT__soc__DOT__disk__DOT__c_inc) {
        __Vdly__sim_top__DOT__soc__DOT__disk__DOT__cnt_lo 
            = (0xffU & ((IData)(1U) + (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__cnt_lo)));
        if ((0xffU == (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__cnt_lo))) {
            __Vdly__sim_top__DOT__soc__DOT__disk__DOT__cnt_hi 
                = (0x1fffU & ((IData)(1U) + (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__cnt_hi)));
        }
    }
    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__hit_q 
        = ((IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__cvalid) 
           & (vlSelf->sim_top__DOT__soc__DOT__disk__DOT__cblk 
              == vlSelf->sim_top__DOT__soc__DOT__disk__DOT__blk));
    if (vlSelf->sim_top__DOT__soc__DOT__m0_pulse) {
        vlSelf->__Vdly__sim_top__DOT__soc__DOT__m0_addr 
            = ((IData)(vlSelf->sim_top__DOT__soc__DOT__run)
                ? ((IData)(vlSelf->sim_top__DOT__soc__DOT__xw_act)
                    ? vlSelf->sim_top__DOT__soc__DOT__win_addr
                    : ((IData)(vlSelf->sim_top__DOT__soc__DOT__disk_sel)
                        ? ((IData)(vlSelf->sim_top__DOT__soc__DOT__l2)
                            ? ((((0x7fU == (0x7fU & 
                                            (vlSelf->sim_top__DOT__soc__DOT__d_addr 
                                             >> 9U)))
                                  ? 0x3fU : ((IData)(vlSelf->sim_top__DOT__soc__DOT__tr)
                                              ? vlSelf->sim_top__DOT__soc__DOT__map_u
                                             [(7U & 
                                               (vlSelf->sim_top__DOT__soc__DOT__d_addr 
                                                >> 0xdU))]
                                              : vlSelf->sim_top__DOT__soc__DOT__map_s
                                             [(7U & 
                                               (vlSelf->sim_top__DOT__soc__DOT__d_addr 
                                                >> 0xdU))])) 
                                << 0xdU) | (0x1fffU 
                                            & vlSelf->sim_top__DOT__soc__DOT__d_addr))
                            : vlSelf->sim_top__DOT__soc__DOT__d_addr)
                        : vlSelf->sim_top__DOT__soc__DOT__c_addr))
                : ((IData)(vlSelf->sim_top__DOT__soc__DOT__ld_wr)
                    ? vlSelf->sim_top__DOT__soc__DOT__ld_addr
                    : vlSelf->sim_top__DOT__soc__DOT__cw));
    }
    if (vlSelf->sim_top__DOT__soc__DOT__disk__DOT__b_we) {
        vlSelf->__Vdlyvval__sim_top__DOT__soc__DOT__disk__DOT__bram__v0 
            = vlSelf->sim_top__DOT__soc__DOT__disk__DOT__b_wdata;
        vlSelf->__Vdlyvset__sim_top__DOT__soc__DOT__disk__DOT__bram__v0 = 1U;
        vlSelf->__Vdlyvdim0__sim_top__DOT__soc__DOT__disk__DOT__bram__v0 
            = vlSelf->sim_top__DOT__soc__DOT__disk__DOT__b_waddr;
    }
    if (vlSelf->resetn) {
        if ((0U != (IData)(vlSelf->sim_top__DOT__mem__DOT__cnt))) {
            vlSelf->__Vdly__sim_top__DOT__mem__DOT__cnt 
                = (0xffffU & ((IData)(vlSelf->sim_top__DOT__mem__DOT__cnt) 
                              - (IData)(1U)));
            if ((1U == (IData)(vlSelf->sim_top__DOT__mem__DOT__cnt))) {
                if (vlSelf->sim_top__DOT__mem__DOT__is_wr) {
                    if (vlSelf->sim_top__DOT__mem__DOT__bw) {
                        if ((1U & vlSelf->sim_top__DOT__mem__DOT__a)) {
                            __Vdlyvval__sim_top__DOT__mem__DOT__mem__v0 
                                = (0xffU & ((IData)(vlSelf->sim_top__DOT__mem__DOT__d) 
                                            >> 8U));
                            __Vdlyvset__sim_top__DOT__mem__DOT__mem__v0 = 1U;
                            __Vdlyvlsb__sim_top__DOT__mem__DOT__mem__v0 = 8U;
                            __Vdlyvdim0__sim_top__DOT__mem__DOT__mem__v0 
                                = (0x1fffffU & (vlSelf->sim_top__DOT__mem__DOT__a 
                                                >> 1U));
                        } else {
                            __Vdlyvval__sim_top__DOT__mem__DOT__mem__v1 
                                = (0xffU & (IData)(vlSelf->sim_top__DOT__mem__DOT__d));
                            __Vdlyvset__sim_top__DOT__mem__DOT__mem__v1 = 1U;
                            __Vdlyvlsb__sim_top__DOT__mem__DOT__mem__v1 = 0U;
                            __Vdlyvdim0__sim_top__DOT__mem__DOT__mem__v1 
                                = (0x1fffffU & (vlSelf->sim_top__DOT__mem__DOT__a 
                                                >> 1U));
                        }
                    } else {
                        __Vdlyvval__sim_top__DOT__mem__DOT__mem__v2 
                            = vlSelf->sim_top__DOT__mem__DOT__d;
                        __Vdlyvset__sim_top__DOT__mem__DOT__mem__v2 = 1U;
                        __Vdlyvdim0__sim_top__DOT__mem__DOT__mem__v2 
                            = (0x1fffffU & (vlSelf->sim_top__DOT__mem__DOT__a 
                                            >> 1U));
                    }
                } else {
                    vlSelf->__Vdly__sim_top__DOT__ps_dout 
                        = vlSelf->sim_top__DOT__mem__DOT__mem
                        [(0x1fffffU & (vlSelf->sim_top__DOT__mem__DOT__a 
                                       >> 1U))];
                }
            }
        } else if (((IData)(vlSelf->sim_top__DOT__ps_rd) 
                    | (IData)(vlSelf->sim_top__DOT__ps_wr))) {
            __Vdly__sim_top__DOT__mem__DOT__refresh 
                = (0xfffU & ((IData)(1U) + (IData)(vlSelf->sim_top__DOT__mem__DOT__refresh)));
            vlSelf->sim_top__DOT__mem__DOT__is_wr = vlSelf->sim_top__DOT__ps_wr;
            vlSelf->sim_top__DOT__mem__DOT__a = vlSelf->sim_top__DOT__ps_addr;
            vlSelf->sim_top__DOT__mem__DOT__d = vlSelf->sim_top__DOT__ps_din;
            vlSelf->sim_top__DOT__mem__DOT__bw = 1U;
            vlSelf->__Vdly__sim_top__DOT__mem__DOT__cnt 
                = (0xffffU & (((IData)(vlSelf->sim_top__DOT__ps_wr)
                                ? 7U : 0xcU) + ((0x7cfU 
                                                 == 
                                                 VL_MODDIV_III(32, (IData)(vlSelf->sim_top__DOT__mem__DOT__refresh), (IData)(0x7d0U)))
                                                 ? 3U
                                                 : 0U)));
        }
    } else {
        vlSelf->__Vdly__sim_top__DOT__mem__DOT__cnt = 0x190U;
        __Vdly__sim_top__DOT__mem__DOT__refresh = 0U;
        vlSelf->sim_top__DOT__mem__DOT__is_wr = 0U;
    }
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__di_q 
        = (((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__int_ack) 
            | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__sel_ack))
            ? (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__svec)
            : (((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__io_rd) 
                | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__sel_io))
                ? ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__port_ok)
                    ? ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__s_port))
                        ? ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__s_port))
                            ? ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__s_port))
                                ? 0xffU : ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__s_port))
                                            ? 0xffU
                                            : (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__svec)))
                            : ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__s_port))
                                ? ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__s_port))
                                    ? (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__s2m3)
                                    : (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__s2m2))
                                : ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__s_port))
                                    ? (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__s2m1)
                                    : (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__s2m0))))
                        : ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__s_port))
                            ? ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__s_port))
                                ? ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__s_port))
                                    ? (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__m2s3)
                                    : (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__m2s2))
                                : ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__s_port))
                                    ? (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__m2s1)
                                    : (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__m2s0)))
                            : ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__s_port))
                                ? 0xffU : ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__s_port))
                                            ? (0x80U 
                                               | (((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__pend_s2m) 
                                                   << 1U) 
                                                  | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__pend_m2s)))
                                            : 1U))))
                    : 0xffU) : (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__zdat)));
    vlSelf->sim_top__DOT__soc__DOT__pa_r = vlSelf->sim_top__DOT__soc__DOT__pa;
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__mem_rd_q 
        = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__mem_rd;
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__mem_wr_q 
        = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__mem_wrc;
    vlSelf->sim_top__DOT__soc__DOT__io_ta = vlSelf->sim_top__DOT__soc__DOT__ta;
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__io_wr_q 
        = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__io_wr;
    vlSelf->sim_top__DOT__soc__DOT__acia__DOT__status_r 
        = ((2U & ((~ (IData)(vlSelf->sim_top__DOT__soc__DOT__acia__DOT__tfull)) 
                  << 1U)) | (1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__acia__DOT__empty))));
    vlSelf->sim_top__DOT__soc__DOT__io_timer = (((IData)(vlSelf->sim_top__DOT__soc__DOT__in_io) 
                                                 & (0x30U 
                                                    <= (IData)(vlSelf->sim_top__DOT__soc__DOT__off))) 
                                                & (0x36U 
                                                   >= (IData)(vlSelf->sim_top__DOT__soc__DOT__off)));
    vlSelf->sim_top__DOT__soc__DOT__io_xl = (((IData)(vlSelf->sim_top__DOT__soc__DOT__in_io) 
                                              & (0x49U 
                                                 <= (IData)(vlSelf->sim_top__DOT__soc__DOT__off))) 
                                             & (0x4dU 
                                                >= (IData)(vlSelf->sim_top__DOT__soc__DOT__off)));
    vlSelf->sim_top__DOT__soc__DOT__acia__DOT__rdata_r 
        = ((IData)(vlSelf->sim_top__DOT__soc__DOT__acia__DOT__empty)
            ? (IData)(vlSelf->sim_top__DOT__soc__DOT__acia__DOT__last)
            : (IData)(vlSelf->sim_top__DOT__soc__DOT__acia__DOT__rq));
    if (vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cen) {
        __Vdly__sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__clk_cnt 
            = ((IData)(1U) + vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__clk_cnt);
    }
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__rst_pulse = 0U;
    vlSelf->sim_top__DOT__soc__DOT__acia_rd = (((((IData)(vlSelf->sim_top__DOT__soc__DOT__acc2) 
                                                  & (IData)(vlSelf->sim_top__DOT__soc__DOT__vma_pend)) 
                                                 & (IData)(vlSelf->dbg_rnw)) 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__io_acia)) 
                                               & (IData)(vlSelf->sim_top__DOT__soc__DOT__off));
    __Vdly__sim_top__DOT__soc__DOT__xw_rdp = 0U;
    __Vdly__sim_top__DOT__soc__DOT__xw_wrp = 0U;
    __Vdly__sim_top__DOT__soc__DOT__win_ack_r = 0U;
    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__spi_done = 0U;
    if (__Vdlyvset__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_reg__DOT__RegsL__v0) {
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_reg__DOT__RegsL[__Vdlyvdim0__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_reg__DOT__RegsL__v0] 
            = __Vdlyvval__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_reg__DOT__RegsL__v0;
    }
    if (__Vdlyvset__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_reg__DOT__RegsH__v0) {
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_reg__DOT__RegsH[__Vdlyvdim0__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_reg__DOT__RegsH__v0] 
            = __Vdlyvval__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_reg__DOT__RegsH__v0;
    }
    if (vlSelf->sim_top__DOT__soc__DOT__rst) {
        __Vdly__sim_top__DOT__soc__DOT__acia__DOT__rp = 0U;
        __Vdly__sim_top__DOT__soc__DOT__acia__DOT__wp = 0U;
        vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx = 0U;
        __Vdlyvset__sim_top__DOT__soc__DOT__timer__DOT__l__v0 = 1U;
    } else {
        if (vlSelf->sim_top__DOT__soc__DOT__acia__DOT__pop) {
            __Vdly__sim_top__DOT__soc__DOT__acia__DOT__rp 
                = (0xffU & ((IData)(1U) + (IData)(vlSelf->sim_top__DOT__soc__DOT__acia__DOT__rp)));
        }
        if (((IData)(vlSelf->sim_top__DOT__soc__DOT__acia__DOT__push) 
             & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__acia__DOT__full)))) {
            __Vdlyvval__sim_top__DOT__soc__DOT__acia__DOT__fifo__v0 
                = vlSelf->sim_top__DOT__soc__DOT__acia__DOT__push_d;
            __Vdlyvset__sim_top__DOT__soc__DOT__acia__DOT__fifo__v0 = 1U;
            __Vdlyvdim0__sim_top__DOT__soc__DOT__acia__DOT__fifo__v0 
                = vlSelf->sim_top__DOT__soc__DOT__acia__DOT__wp;
            __Vdly__sim_top__DOT__soc__DOT__acia__DOT__wp 
                = (0xffU & ((IData)(1U) + (IData)(vlSelf->sim_top__DOT__soc__DOT__acia__DOT__wp)));
        }
        if (vlSelf->sim_top__DOT__soc__DOT__timer_wr) {
            if ((0U == (7U & (IData)(vlSelf->sim_top__DOT__soc__DOT__off)))) {
                if ((0x8fU != (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DOutput))) {
                    if ((0x80U != (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DOutput))) {
                        if ((4U == (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DOutput))) {
                            __Vdlyvval__sim_top__DOT__soc__DOT__timer__DOT__l__v6 
                                = vlSelf->sim_top__DOT__soc__DOT__timer__DOT__y;
                            __Vdlyvset__sim_top__DOT__soc__DOT__timer__DOT__l__v6 = 1U;
                            __Vdlyvval__sim_top__DOT__soc__DOT__timer__DOT__l__v7 
                                = vlSelf->sim_top__DOT__soc__DOT__timer__DOT__mo;
                            __Vdlyvval__sim_top__DOT__soc__DOT__timer__DOT__l__v8 
                                = vlSelf->sim_top__DOT__soc__DOT__timer__DOT__d;
                            __Vdlyvval__sim_top__DOT__soc__DOT__timer__DOT__l__v9 
                                = vlSelf->sim_top__DOT__soc__DOT__timer__DOT__h;
                            __Vdlyvval__sim_top__DOT__soc__DOT__timer__DOT__l__v10 
                                = vlSelf->sim_top__DOT__soc__DOT__timer__DOT__mi;
                            __Vdlyvval__sim_top__DOT__soc__DOT__timer__DOT__l__v11 
                                = vlSelf->sim_top__DOT__soc__DOT__timer__DOT__s;
                        }
                    }
                }
            } else if ((6U >= (7U & (IData)(vlSelf->sim_top__DOT__soc__DOT__off)))) {
                vlSelf->sim_top__DOT__soc__DOT__timer__DOT____Vlvbound_h29784b0a__0 
                    = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DOutput;
                if ((5U >= (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__off) 
                                  - (IData)(1U))))) {
                    __Vdlyvval__sim_top__DOT__soc__DOT__timer__DOT__l__v12 
                        = vlSelf->sim_top__DOT__soc__DOT__timer__DOT____Vlvbound_h29784b0a__0;
                    __Vdlyvset__sim_top__DOT__soc__DOT__timer__DOT__l__v12 = 1U;
                    __Vdlyvdim0__sim_top__DOT__soc__DOT__timer__DOT__l__v12 
                        = (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__off) 
                                 - (IData)(1U)));
                }
            }
        }
    }
    if (__Vdlyvset__sim_top__DOT__soc__DOT__timer__DOT__l__v0) {
        vlSelf->sim_top__DOT__soc__DOT__timer__DOT__l[0U] = 0U;
        vlSelf->sim_top__DOT__soc__DOT__timer__DOT__l[1U] = 0U;
        vlSelf->sim_top__DOT__soc__DOT__timer__DOT__l[2U] = 0U;
        vlSelf->sim_top__DOT__soc__DOT__timer__DOT__l[3U] = 0U;
        vlSelf->sim_top__DOT__soc__DOT__timer__DOT__l[4U] = 0U;
        vlSelf->sim_top__DOT__soc__DOT__timer__DOT__l[5U] = 0U;
    }
    if (__Vdlyvset__sim_top__DOT__soc__DOT__timer__DOT__l__v6) {
        vlSelf->sim_top__DOT__soc__DOT__timer__DOT__l[0U] 
            = __Vdlyvval__sim_top__DOT__soc__DOT__timer__DOT__l__v6;
        vlSelf->sim_top__DOT__soc__DOT__timer__DOT__l[1U] 
            = __Vdlyvval__sim_top__DOT__soc__DOT__timer__DOT__l__v7;
        vlSelf->sim_top__DOT__soc__DOT__timer__DOT__l[2U] 
            = __Vdlyvval__sim_top__DOT__soc__DOT__timer__DOT__l__v8;
        vlSelf->sim_top__DOT__soc__DOT__timer__DOT__l[3U] 
            = __Vdlyvval__sim_top__DOT__soc__DOT__timer__DOT__l__v9;
        vlSelf->sim_top__DOT__soc__DOT__timer__DOT__l[4U] 
            = __Vdlyvval__sim_top__DOT__soc__DOT__timer__DOT__l__v10;
        vlSelf->sim_top__DOT__soc__DOT__timer__DOT__l[5U] 
            = __Vdlyvval__sim_top__DOT__soc__DOT__timer__DOT__l__v11;
    }
    if (__Vdlyvset__sim_top__DOT__soc__DOT__timer__DOT__l__v12) {
        vlSelf->sim_top__DOT__soc__DOT__timer__DOT__l[__Vdlyvdim0__sim_top__DOT__soc__DOT__timer__DOT__l__v12] 
            = __Vdlyvval__sim_top__DOT__soc__DOT__timer__DOT__l__v12;
    }
    if (vlSelf->sim_top__DOT__soc__DOT__xl_we) {
        if ((4U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__off) 
                   - (IData)(1U)))) {
            if ((1U & (~ (3U & (((IData)(vlSelf->sim_top__DOT__soc__DOT__off) 
                                 - (IData)(1U)) >> 1U))))) {
                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__off) 
                              - (IData)(1U))))) {
                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx) 
                                  >> 6U)))) {
                        if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx) 
                                      >> 5U)))) {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx) 
                                          >> 4U)))) {
                                if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx))) {
                                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx) 
                                                  >> 2U)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx) 
                                                    >> 1U)))) {
                                            if ((1U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx))) {
                                                __Vdlyvval__sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__smmu__v0 
                                                    = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DOutput;
                                                __Vdlyvset__sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__smmu__v0 = 1U;
                                                __Vdlyvdim0__sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__smmu__v0 
                                                    = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__mi;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (__Vdlyvset__sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__smmu__v0) {
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__smmu[__Vdlyvdim0__sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__smmu__v0] 
            = __Vdlyvval__sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__smmu__v0;
    }
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__cnt_lo 
        = __Vdly__sim_top__DOT__soc__DOT__disk__DOT__cnt_lo;
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__cnt_hi 
        = __Vdly__sim_top__DOT__soc__DOT__disk__DOT__cnt_hi;
    vlSelf->sim_top__DOT__mem__DOT__refresh = __Vdly__sim_top__DOT__mem__DOT__refresh;
    if (__Vdlyvset__sim_top__DOT__mem__DOT__mem__v0) {
        vlSelf->sim_top__DOT__mem__DOT__mem[__Vdlyvdim0__sim_top__DOT__mem__DOT__mem__v0] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__sim_top__DOT__mem__DOT__mem__v0))) 
                & vlSelf->sim_top__DOT__mem__DOT__mem
                [__Vdlyvdim0__sim_top__DOT__mem__DOT__mem__v0]) 
               | (0xffffU & ((IData)(__Vdlyvval__sim_top__DOT__mem__DOT__mem__v0) 
                             << (IData)(__Vdlyvlsb__sim_top__DOT__mem__DOT__mem__v0))));
    }
    if (__Vdlyvset__sim_top__DOT__mem__DOT__mem__v1) {
        vlSelf->sim_top__DOT__mem__DOT__mem[__Vdlyvdim0__sim_top__DOT__mem__DOT__mem__v1] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__sim_top__DOT__mem__DOT__mem__v1))) 
                & vlSelf->sim_top__DOT__mem__DOT__mem
                [__Vdlyvdim0__sim_top__DOT__mem__DOT__mem__v1]) 
               | (0xffffU & ((IData)(__Vdlyvval__sim_top__DOT__mem__DOT__mem__v1) 
                             << (IData)(__Vdlyvlsb__sim_top__DOT__mem__DOT__mem__v1))));
    }
    if (__Vdlyvset__sim_top__DOT__mem__DOT__mem__v2) {
        vlSelf->sim_top__DOT__mem__DOT__mem[__Vdlyvdim0__sim_top__DOT__mem__DOT__mem__v2] 
            = __Vdlyvval__sim_top__DOT__mem__DOT__mem__v2;
    }
    if (vlSelf->sim_top__DOT__soc__DOT__rst) {
        __Vdly__sim_top__DOT__soc__DOT__timer__DOT__y = 0x7eU;
        __Vdly__sim_top__DOT__soc__DOT__timer__DOT__mo = 1U;
        __Vdly__sim_top__DOT__soc__DOT__timer__DOT__d = 1U;
        __Vdly__sim_top__DOT__soc__DOT__timer__DOT__h = 0U;
        __Vdly__sim_top__DOT__soc__DOT__timer__DOT__mi = 0U;
        __Vdly__sim_top__DOT__soc__DOT__timer__DOT__s = 0U;
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__zstall = 0U;
        __Vdly__sim_top__DOT__soc__DOT__sub__DOT__zrel = 0U;
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__zrel 
            = __Vdly__sim_top__DOT__soc__DOT__sub__DOT__zrel;
        vlSelf->txd = 1U;
        vlSelf->__Vdly__sim_top__DOT__soc__DOT__acia__DOT__tfull = 0U;
        __Vdly__sim_top__DOT__soc__DOT__acia__DOT__tbusy = 0U;
    } else {
        if (vlSelf->sim_top__DOT__soc__DOT__timer__DOT__sec_tick) {
            if (vlSelf->sim_top__DOT__soc__DOT__timer__DOT__s59) {
                if (vlSelf->sim_top__DOT__soc__DOT__timer__DOT__mi59) {
                    if (vlSelf->sim_top__DOT__soc__DOT__timer__DOT__h23) {
                        if (vlSelf->sim_top__DOT__soc__DOT__timer__DOT__dlast) {
                            if (vlSelf->sim_top__DOT__soc__DOT__timer__DOT__mo12) {
                                __Vdly__sim_top__DOT__soc__DOT__timer__DOT__y 
                                    = (0xffU & ((IData)(1U) 
                                                + (IData)(vlSelf->sim_top__DOT__soc__DOT__timer__DOT__y)));
                                __Vdly__sim_top__DOT__soc__DOT__timer__DOT__mo = 1U;
                            } else {
                                __Vdly__sim_top__DOT__soc__DOT__timer__DOT__mo 
                                    = (0xffU & ((IData)(1U) 
                                                + (IData)(vlSelf->sim_top__DOT__soc__DOT__timer__DOT__mo)));
                            }
                            __Vdly__sim_top__DOT__soc__DOT__timer__DOT__d = 1U;
                        } else {
                            __Vdly__sim_top__DOT__soc__DOT__timer__DOT__d 
                                = (0xffU & ((IData)(1U) 
                                            + (IData)(vlSelf->sim_top__DOT__soc__DOT__timer__DOT__d)));
                        }
                        __Vdly__sim_top__DOT__soc__DOT__timer__DOT__h = 0U;
                    } else {
                        __Vdly__sim_top__DOT__soc__DOT__timer__DOT__h 
                            = (0xffU & ((IData)(1U) 
                                        + (IData)(vlSelf->sim_top__DOT__soc__DOT__timer__DOT__h)));
                    }
                    __Vdly__sim_top__DOT__soc__DOT__timer__DOT__mi = 0U;
                } else {
                    __Vdly__sim_top__DOT__soc__DOT__timer__DOT__mi 
                        = (0xffU & ((IData)(1U) + (IData)(vlSelf->sim_top__DOT__soc__DOT__timer__DOT__mi)));
                }
                __Vdly__sim_top__DOT__soc__DOT__timer__DOT__s = 0U;
            } else {
                __Vdly__sim_top__DOT__soc__DOT__timer__DOT__s 
                    = (0xffU & ((IData)(1U) + (IData)(vlSelf->sim_top__DOT__soc__DOT__timer__DOT__s)));
            }
        }
        if (vlSelf->sim_top__DOT__soc__DOT__sub__DOT__rd_start) {
            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__zstall = 1U;
        } else if (vlSelf->sim_top__DOT__soc__DOT__sub__DOT__wr_end) {
            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__zstall = 1U;
        }
        if (vlSelf->sim_top__DOT__soc__DOT__zm_ack) {
            __Vdly__sim_top__DOT__soc__DOT__sub__DOT__zrel = 5U;
        } else if ((0U != (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__zrel))) {
            __Vdly__sim_top__DOT__soc__DOT__sub__DOT__zrel 
                = (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__zrel) 
                         - (IData)(1U)));
            if ((1U == (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__zrel))) {
                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__zstall = 0U;
            }
        }
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__zrel 
            = __Vdly__sim_top__DOT__soc__DOT__sub__DOT__zrel;
        if (vlSelf->term_stb) {
            vlSelf->__Vdly__sim_top__DOT__soc__DOT__acia__DOT__tfull = 1U;
        }
        if (vlSelf->sim_top__DOT__soc__DOT__acia__DOT__tbusy) {
            if ((0U != (IData)(vlSelf->sim_top__DOT__soc__DOT__acia__DOT__tbaud))) {
                vlSelf->sim_top__DOT__soc__DOT__acia__DOT__tbaud 
                    = (0x3ffU & ((IData)(vlSelf->sim_top__DOT__soc__DOT__acia__DOT__tbaud) 
                                 - (IData)(1U)));
            } else {
                vlSelf->sim_top__DOT__soc__DOT__acia__DOT__tbaud = 0x249U;
                if ((9U == (IData)(vlSelf->sim_top__DOT__soc__DOT__acia__DOT__tbit))) {
                    __Vdly__sim_top__DOT__soc__DOT__acia__DOT__tbusy = 0U;
                    vlSelf->txd = 1U;
                } else {
                    __Vdly__sim_top__DOT__soc__DOT__acia__DOT__tsh 
                        = (0x200U | (0x1ffU & ((IData)(vlSelf->sim_top__DOT__soc__DOT__acia__DOT__tsh) 
                                               >> 1U)));
                    vlSelf->sim_top__DOT__soc__DOT__acia__DOT__tbit 
                        = (0xfU & ((IData)(1U) + (IData)(vlSelf->sim_top__DOT__soc__DOT__acia__DOT__tbit)));
                    vlSelf->txd = (1U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__acia__DOT__tsh) 
                                         >> 1U));
                }
            }
        } else if (vlSelf->sim_top__DOT__soc__DOT__acia__DOT__tfull) {
            __Vdly__sim_top__DOT__soc__DOT__acia__DOT__tsh 
                = (0x200U | ((IData)(vlSelf->sim_top__DOT__soc__DOT__acia__DOT__thold) 
                             << 1U));
            vlSelf->sim_top__DOT__soc__DOT__acia__DOT__tbit = 0U;
            vlSelf->sim_top__DOT__soc__DOT__acia__DOT__tbaud = 0x249U;
            __Vdly__sim_top__DOT__soc__DOT__acia__DOT__tbusy = 1U;
            vlSelf->__Vdly__sim_top__DOT__soc__DOT__acia__DOT__tfull 
                = vlSelf->term_stb;
            vlSelf->txd = 0U;
        }
    }
    vlSelf->sim_top__DOT__soc__DOT__acia__DOT__tbusy 
        = __Vdly__sim_top__DOT__soc__DOT__acia__DOT__tbusy;
    vlSelf->sim_top__DOT__soc__DOT__acia__DOT__tsh 
        = __Vdly__sim_top__DOT__soc__DOT__acia__DOT__tsh;
    if (((IData)(vlSelf->sim_top__DOT__soc__DOT__xl_re) 
         & (4U == (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__off) 
                         - (IData)(1U)))))) {
        if ((0x10U == (0x7fU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx)))) {
            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__clk_latch 
                = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__clk_cnt;
        }
    }
    if (vlSelf->sim_top__DOT__soc__DOT__rst) {
        __Vdly__sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__clk_cnt = 0U;
    }
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__clk_cnt 
        = __Vdly__sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__clk_cnt;
    if (vlSelf->sim_top__DOT__soc__DOT__xl_we) {
        if ((1U & (~ (1U & (((IData)(vlSelf->sim_top__DOT__soc__DOT__off) 
                             - (IData)(1U)) >> 2U))))) {
            if ((1U & (~ (3U & (((IData)(vlSelf->sim_top__DOT__soc__DOT__off) 
                                 - (IData)(1U)) >> 1U))))) {
                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__off) 
                              - (IData)(1U))))) {
                    if ((0x80U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DOutput))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__rst_pulse = 1U;
                    }
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__c_shr 
                        = (1U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DOutput) 
                                 >> 2U));
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__c_ien 
                        = (1U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DOutput) 
                                 >> 4U));
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__c_run 
                        = (1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DOutput));
                }
                if ((1U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__off) 
                           - (IData)(1U)))) {
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__pend_s2m = 0U;
                }
            }
        }
        if ((4U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__off) 
                   - (IData)(1U)))) {
            if ((1U & (~ (3U & (((IData)(vlSelf->sim_top__DOT__soc__DOT__off) 
                                 - (IData)(1U)) >> 1U))))) {
                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__off) 
                              - (IData)(1U))))) {
                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx) 
                                  >> 6U)))) {
                        if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx) 
                                      >> 5U)))) {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx) 
                                          >> 4U)))) {
                                if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx))) {
                                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx) 
                                                  >> 2U)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx) 
                                                    >> 1U)))) {
                                            if ((1U 
                                                 & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx)))) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__mi 
                                                    = 
                                                    (0x7fU 
                                                     & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DOutput));
                                            }
                                        }
                                    }
                                }
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx) 
                                              >> 3U)))) {
                                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx) 
                                                  >> 2U)))) {
                                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx))) {
                                            if ((1U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx))) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__m2s3 
                                                    = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DOutput;
                                            }
                                            if ((1U 
                                                 & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx)))) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__m2s2 
                                                    = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DOutput;
                                            }
                                        }
                                        if ((1U & (~ 
                                                   ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx) 
                                                    >> 1U)))) {
                                            if ((1U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx))) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__m2s1 
                                                    = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DOutput;
                                            }
                                            if ((1U 
                                                 & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx)))) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__m2s0 
                                                    = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DOutput;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlSelf->sim_top__DOT__soc__DOT__rst) {
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__c_shr = 0U;
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__c_ien = 0U;
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__c_run = 0U;
        vlSelf->__Vdly__sim_top__DOT__soc__DOT__xw_act = 0U;
        __Vdly__sim_top__DOT__soc__DOT__xw_go = 0U;
    } else {
        if (((((IData)(vlSelf->sim_top__DOT__soc__DOT__win_req) 
               & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__xw_act))) 
              & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__win_ack_r))) 
             & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__xw_go)))) {
            vlSelf->__Vdly__sim_top__DOT__soc__DOT__xw_act = 1U;
            __Vdly__sim_top__DOT__soc__DOT__xw_go = 1U;
            __Vdly__sim_top__DOT__soc__DOT__win_wr_q 
                = vlSelf->sim_top__DOT__soc__DOT__win_wr;
        } else if (vlSelf->sim_top__DOT__soc__DOT__xw_go) {
            __Vdly__sim_top__DOT__soc__DOT__xw_go = 0U;
            __Vdly__sim_top__DOT__soc__DOT__xw_rdp 
                = (1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__win_wr_q)));
            __Vdly__sim_top__DOT__soc__DOT__xw_wrp 
                = vlSelf->sim_top__DOT__soc__DOT__win_wr_q;
        }
        if ((((((IData)(vlSelf->sim_top__DOT__soc__DOT__xw_act) 
                & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__xw_go))) 
               & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__xw_rdp))) 
              & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__xw_wrp))) 
             & (IData)(vlSelf->sim_top__DOT__soc__DOT__m0_ack))) {
            vlSelf->__Vdly__sim_top__DOT__soc__DOT__xw_act = 0U;
            __Vdly__sim_top__DOT__soc__DOT__win_ack_r = 1U;
            vlSelf->sim_top__DOT__soc__DOT__win_rdata 
                = (0xffU & ((1U & vlSelf->sim_top__DOT__soc__DOT__win_addr)
                             ? ((IData)(vlSelf->sim_top__DOT__soc__DOT__ps_dout_m) 
                                >> 8U) : (IData)(vlSelf->sim_top__DOT__soc__DOT__ps_dout_m)));
        }
    }
    if (vlSelf->sim_top__DOT__soc__DOT__xl_we) {
        if ((4U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__off) 
                   - (IData)(1U)))) {
            if ((1U & (~ (3U & (((IData)(vlSelf->sim_top__DOT__soc__DOT__off) 
                                 - (IData)(1U)) >> 1U))))) {
                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__off) 
                              - (IData)(1U))))) {
                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx) 
                                  >> 6U)))) {
                        if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx) 
                                      >> 5U)))) {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx) 
                                          >> 4U)))) {
                                if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx))) {
                                    if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx) 
                                                    >> 1U)))) {
                                            if ((1U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx))) {
                                                vlSelf->sim_top__DOT__soc__DOT__win_wr = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    vlSelf->sim_top__DOT__soc__DOT__xw_go = __Vdly__sim_top__DOT__soc__DOT__xw_go;
    vlSelf->sim_top__DOT__soc__DOT__win_wr_q = __Vdly__sim_top__DOT__soc__DOT__win_wr_q;
    vlSelf->sim_top__DOT__soc__DOT__xw_rdp = __Vdly__sim_top__DOT__soc__DOT__xw_rdp;
    vlSelf->sim_top__DOT__soc__DOT__xw_wrp = __Vdly__sim_top__DOT__soc__DOT__xw_wrp;
    if (vlSelf->sim_top__DOT__soc__DOT__rst) {
        __Vdly__sim_top__DOT__soc__DOT__disk__DOT__spi_busy = 0U;
        __Vdly__sd_clk = 0U;
        vlSelf->sd_mosi = 1U;
    } else if (vlSelf->sim_top__DOT__soc__DOT__disk__DOT__spi_busy) {
        if (((IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__hcnt) 
             != ((IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__fast)
                  ? 2U : 0x7fU))) {
            vlSelf->sim_top__DOT__soc__DOT__disk__DOT__hcnt 
                = (0xffU & ((IData)(1U) + (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__hcnt)));
        } else {
            vlSelf->sim_top__DOT__soc__DOT__disk__DOT__hcnt = 0U;
            if (vlSelf->sd_clk) {
                __Vdly__sim_top__DOT__soc__DOT__disk__DOT__bcnt 
                    = (0xfU & ((IData)(1U) + (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__bcnt)));
                __Vdly__sd_clk = 0U;
                vlSelf->sd_mosi = (1U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__sh_out) 
                                         >> 7U));
                if ((7U == (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__bcnt))) {
                    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__spi_busy = 0U;
                    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__spi_done = 1U;
                    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__spi_rx 
                        = vlSelf->sim_top__DOT__soc__DOT__disk__DOT__sh_in;
                }
                vlSelf->sim_top__DOT__soc__DOT__disk__DOT__sh_out 
                    = (1U | (0xfeU & ((IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__sh_out) 
                                      << 1U)));
            } else {
                vlSelf->sim_top__DOT__soc__DOT__disk__DOT__sh_in 
                    = ((0xfeU & ((IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__sh_in) 
                                 << 1U)) | (IData)(vlSelf->sd_miso));
                __Vdly__sd_clk = 1U;
            }
        }
    } else {
        __Vdly__sd_clk = 0U;
        if (vlSelf->sim_top__DOT__soc__DOT__disk__DOT__spi_go) {
            vlSelf->sim_top__DOT__soc__DOT__disk__DOT__sh_out 
                = (1U | (0xfeU & ((IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__spi_tx) 
                                  << 1U)));
            vlSelf->sd_mosi = (1U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__spi_tx) 
                                     >> 7U));
            __Vdly__sim_top__DOT__soc__DOT__disk__DOT__bcnt = 0U;
            vlSelf->sim_top__DOT__soc__DOT__disk__DOT__hcnt = 0U;
            __Vdly__sim_top__DOT__soc__DOT__disk__DOT__spi_busy = 1U;
        } else {
            vlSelf->sd_mosi = 1U;
        }
    }
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__spi_busy 
        = __Vdly__sim_top__DOT__soc__DOT__disk__DOT__spi_busy;
    vlSelf->sd_clk = __Vdly__sd_clk;
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__bcnt 
        = __Vdly__sim_top__DOT__soc__DOT__disk__DOT__bcnt;
    vlSelf->sim_top__DOT__soc__DOT__acia__DOT__full 
        = ((0xffU & ((IData)(1U) + (IData)(vlSelf->sim_top__DOT__soc__DOT__acia__DOT__wp))) 
           == (IData)(vlSelf->sim_top__DOT__soc__DOT__acia__DOT__rp));
    __Vdly__sim_top__DOT__soc__DOT__acia__DOT__rxs 
        = ((2U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__acia__DOT__rxs) 
                  << 1U)) | (IData)(vlSelf->rxd));
    vlSelf->sim_top__DOT__soc__DOT__acia__DOT__push = 0U;
    __Vdly__sim_top__DOT__soc__DOT__dgo = 0U;
    if (((IData)(vlSelf->sim_top__DOT__soc__DOT__disk_busy_d) 
         & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__disk_busy)))) {
        vlSelf->sim_top__DOT__soc__DOT__e040 = vlSelf->sim_top__DOT__soc__DOT__disk_result;
    }
    vlSelf->sim_top__DOT__soc__DOT__timer__DOT__s59 
        = (0x3bU == (IData)(vlSelf->sim_top__DOT__soc__DOT__timer__DOT__s));
    vlSelf->sim_top__DOT__soc__DOT__timer__DOT__mi59 
        = (0x3bU == (IData)(vlSelf->sim_top__DOT__soc__DOT__timer__DOT__mi));
    vlSelf->sim_top__DOT__soc__DOT__timer__DOT__h23 
        = (0x17U == (IData)(vlSelf->sim_top__DOT__soc__DOT__timer__DOT__h));
    vlSelf->sim_top__DOT__soc__DOT__timer__DOT__mo12 
        = (0xcU == (IData)(vlSelf->sim_top__DOT__soc__DOT__timer__DOT__mo));
    __Vfunc_sim_top__DOT__soc__DOT__timer__DOT__dim__48__m 
        = vlSelf->sim_top__DOT__soc__DOT__timer__DOT__mo;
    __Vfunc_sim_top__DOT__soc__DOT__timer__DOT__dim__48__yr 
        = vlSelf->sim_top__DOT__soc__DOT__timer__DOT__y;
    __Vfunc_sim_top__DOT__soc__DOT__timer__DOT__dim__48__Vfuncout 
        = ((2U == (IData)(__Vfunc_sim_top__DOT__soc__DOT__timer__DOT__dim__48__m))
            ? ((0U == (3U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__timer__DOT__dim__48__yr)))
                ? 0x1dU : 0x1cU) : (((((4U == (IData)(__Vfunc_sim_top__DOT__soc__DOT__timer__DOT__dim__48__m)) 
                                       | (6U == (IData)(__Vfunc_sim_top__DOT__soc__DOT__timer__DOT__dim__48__m))) 
                                      | (9U == (IData)(__Vfunc_sim_top__DOT__soc__DOT__timer__DOT__dim__48__m))) 
                                     | (0xbU == (IData)(__Vfunc_sim_top__DOT__soc__DOT__timer__DOT__dim__48__m)))
                                     ? 0x1eU : 0x1fU));
    vlSelf->sim_top__DOT__soc__DOT__timer__DOT__dlast 
        = ((IData)(vlSelf->sim_top__DOT__soc__DOT__timer__DOT__d) 
           == (IData)(__Vfunc_sim_top__DOT__soc__DOT__timer__DOT__dim__48__Vfuncout));
    vlSelf->sim_top__DOT__soc__DOT__ld_addr = (0x3fffffU 
                                               & ((IData)(0x200000U) 
                                                  + vlSelf->sim_top__DOT__soc__DOT__loader__DOT__n));
    if ((((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__mem_rd) 
          | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__mem_wrc)) 
         | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__io_wr))) {
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__sel_ack = 0U;
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__sel_io = 0U;
    } else if (vlSelf->sim_top__DOT__soc__DOT__sub__DOT__int_ack) {
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__sel_ack = 1U;
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__sel_io = 0U;
    } else if (vlSelf->sim_top__DOT__soc__DOT__sub__DOT__io_rd) {
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__sel_ack = 0U;
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__sel_io = 1U;
    }
    if (vlSelf->sim_top__DOT__soc__DOT__sub__DOT____Vcellinp__xl__s_we) {
        if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__s_port) 
                      >> 3U)))) {
            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__s_port) 
                          >> 2U)))) {
                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__s_port))) {
                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__s_port)))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__pend_s2m = 1U;
                    }
                }
            }
        }
        if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__s_port))) {
            if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__s_port))) {
                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__s_port) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__s_port)))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__svec 
                            = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__dout_q;
                    }
                }
            }
            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__s_port) 
                          >> 2U)))) {
                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__s_port))) {
                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__s_port))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__s2m3 
                            = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__dout_q;
                    }
                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__s_port)))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__s2m2 
                            = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__dout_q;
                    }
                }
                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__s_port) 
                              >> 1U)))) {
                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__s_port))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__s2m1 
                            = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__dout_q;
                    }
                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__s_port)))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__s2m0 
                            = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__dout_q;
                    }
                }
            }
        }
    }
    if (vlSelf->sim_top__DOT__soc__DOT__sub__DOT__io_wr) {
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__a_q 
            = (0xffU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__A));
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__dout_q 
            = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__dout;
    }
    if (((IData)(vlSelf->sim_top__DOT__soc__DOT__xl_re) 
         & (4U == (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__off) 
                         - (IData)(1U)))))) {
        if ((0xdU == (0x7fU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx)))) {
            vlSelf->sim_top__DOT__soc__DOT__win_wr = 0U;
        }
    }
    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__rst)))) {
        if (vlSelf->term_stb) {
            vlSelf->sim_top__DOT__soc__DOT__acia__DOT__thold 
                = vlSelf->term_byte;
        }
    }
    if (((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__win_busy) 
         & (IData)(vlSelf->sim_top__DOT__soc__DOT__win_ack_r))) {
        vlSelf->sim_top__DOT__soc__DOT__win_addr = 
            (0x1fffffU & ((IData)(1U) + vlSelf->sim_top__DOT__soc__DOT__win_addr));
        vlSelf->sim_top__DOT__soc__DOT__win_req = 0U;
        vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__win_busy = 0U;
    }
    if (vlSelf->sim_top__DOT__soc__DOT__xl_we) {
        if ((4U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__off) 
                   - (IData)(1U)))) {
            if ((1U & (~ (3U & (((IData)(vlSelf->sim_top__DOT__soc__DOT__off) 
                                 - (IData)(1U)) >> 1U))))) {
                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__off) 
                              - (IData)(1U))))) {
                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx) 
                                  >> 6U)))) {
                        if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx) 
                                      >> 5U)))) {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx) 
                                          >> 4U)))) {
                                if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx))) {
                                    if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx) 
                                                    >> 1U)))) {
                                            if ((1U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx))) {
                                                vlSelf->sim_top__DOT__soc__DOT__win_req = 1U;
                                                vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__win_busy = 1U;
                                            } else {
                                                vlSelf->sim_top__DOT__soc__DOT__win_addr 
                                                    = 
                                                    ((0x1fff00U 
                                                      & vlSelf->sim_top__DOT__soc__DOT__win_addr) 
                                                     | (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DOutput));
                                            }
                                        }
                                    } else if ((2U 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx))) {
                                        vlSelf->sim_top__DOT__soc__DOT__win_addr 
                                            = ((1U 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx))
                                                ? (
                                                   (0x1f00ffU 
                                                    & vlSelf->sim_top__DOT__soc__DOT__win_addr) 
                                                   | ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DOutput) 
                                                      << 8U))
                                                : (
                                                   (0xffffU 
                                                    & vlSelf->sim_top__DOT__soc__DOT__win_addr) 
                                                   | (0x1f0000U 
                                                      & ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DOutput) 
                                                         << 0x10U))));
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (((IData)(vlSelf->sim_top__DOT__soc__DOT__xl_re) 
         & (4U == (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__off) 
                         - (IData)(1U)))))) {
        if ((0xdU == (0x7fU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx)))) {
            vlSelf->sim_top__DOT__soc__DOT__win_req = 1U;
            vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__win_busy = 1U;
        }
    }
    vlSelf->sim_top__DOT__soc__DOT__acia__DOT__wp = __Vdly__sim_top__DOT__soc__DOT__acia__DOT__wp;
    if (vlSelf->sim_top__DOT__soc__DOT__rst) {
        __Vdly__sim_top__DOT__soc__DOT__acia__DOT__rbusy = 0U;
        vlSelf->sim_top__DOT__soc__DOT__acia__DOT__rxs 
            = __Vdly__sim_top__DOT__soc__DOT__acia__DOT__rxs;
        vlSelf->sim_top__DOT__soc__DOT__acia__DOT__rbusy 
            = __Vdly__sim_top__DOT__soc__DOT__acia__DOT__rbusy;
        vlSelf->sim_top__DOT__soc__DOT__acia__DOT__rbit 
            = __Vdly__sim_top__DOT__soc__DOT__acia__DOT__rbit;
        vlSelf->sim_top__DOT__soc__DOT__acia__DOT__rsh 
            = __Vdly__sim_top__DOT__soc__DOT__acia__DOT__rsh;
        vlSelf->sim_top__DOT__soc__DOT__timer__DOT__s 
            = __Vdly__sim_top__DOT__soc__DOT__timer__DOT__s;
        vlSelf->sim_top__DOT__soc__DOT__timer__DOT__mi 
            = __Vdly__sim_top__DOT__soc__DOT__timer__DOT__mi;
        vlSelf->sim_top__DOT__soc__DOT__timer__DOT__h 
            = __Vdly__sim_top__DOT__soc__DOT__timer__DOT__h;
        vlSelf->sim_top__DOT__soc__DOT__timer__DOT__y 
            = __Vdly__sim_top__DOT__soc__DOT__timer__DOT__y;
        vlSelf->sim_top__DOT__soc__DOT__timer__DOT__d 
            = __Vdly__sim_top__DOT__soc__DOT__timer__DOT__d;
        vlSelf->sim_top__DOT__soc__DOT__timer__DOT__mo 
            = __Vdly__sim_top__DOT__soc__DOT__timer__DOT__mo;
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__mi = 0U;
    } else {
        if (vlSelf->sim_top__DOT__soc__DOT__acia__DOT__rbusy) {
            if ((0U != (IData)(vlSelf->sim_top__DOT__soc__DOT__acia__DOT__rbaud))) {
                vlSelf->sim_top__DOT__soc__DOT__acia__DOT__rbaud 
                    = (0x3ffU & ((IData)(vlSelf->sim_top__DOT__soc__DOT__acia__DOT__rbaud) 
                                 - (IData)(1U)));
            } else {
                vlSelf->sim_top__DOT__soc__DOT__acia__DOT__rbaud = 0x249U;
                if ((0U == (IData)(vlSelf->sim_top__DOT__soc__DOT__acia__DOT__rbit))) {
                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__acia__DOT__rxs))) {
                        __Vdly__sim_top__DOT__soc__DOT__acia__DOT__rbusy = 0U;
                    }
                    __Vdly__sim_top__DOT__soc__DOT__acia__DOT__rbit = 1U;
                } else if ((8U >= (IData)(vlSelf->sim_top__DOT__soc__DOT__acia__DOT__rbit))) {
                    __Vdly__sim_top__DOT__soc__DOT__acia__DOT__rbit 
                        = (0xfU & ((IData)(1U) + (IData)(vlSelf->sim_top__DOT__soc__DOT__acia__DOT__rbit)));
                    __Vdly__sim_top__DOT__soc__DOT__acia__DOT__rsh 
                        = ((0x80U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__acia__DOT__rxs) 
                                     << 6U)) | (0x7fU 
                                                & ((IData)(vlSelf->sim_top__DOT__soc__DOT__acia__DOT__rsh) 
                                                   >> 1U)));
                } else {
                    __Vdly__sim_top__DOT__soc__DOT__acia__DOT__rbusy = 0U;
                    vlSelf->sim_top__DOT__soc__DOT__acia__DOT__push = 1U;
                    vlSelf->sim_top__DOT__soc__DOT__acia__DOT__push_d 
                        = vlSelf->sim_top__DOT__soc__DOT__acia__DOT__rsh;
                }
            }
        } else if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__acia__DOT__rxs) 
                             >> 1U)))) {
            __Vdly__sim_top__DOT__soc__DOT__acia__DOT__rbit = 0U;
            __Vdly__sim_top__DOT__soc__DOT__acia__DOT__rbusy = 1U;
            vlSelf->sim_top__DOT__soc__DOT__acia__DOT__rbaud = 0x125U;
        }
        vlSelf->sim_top__DOT__soc__DOT__acia__DOT__rxs 
            = __Vdly__sim_top__DOT__soc__DOT__acia__DOT__rxs;
        vlSelf->sim_top__DOT__soc__DOT__acia__DOT__rbusy 
            = __Vdly__sim_top__DOT__soc__DOT__acia__DOT__rbusy;
        vlSelf->sim_top__DOT__soc__DOT__acia__DOT__rbit 
            = __Vdly__sim_top__DOT__soc__DOT__acia__DOT__rbit;
        vlSelf->sim_top__DOT__soc__DOT__acia__DOT__rsh 
            = __Vdly__sim_top__DOT__soc__DOT__acia__DOT__rsh;
        vlSelf->sim_top__DOT__soc__DOT__timer__DOT__s 
            = __Vdly__sim_top__DOT__soc__DOT__timer__DOT__s;
        vlSelf->sim_top__DOT__soc__DOT__timer__DOT__mi 
            = __Vdly__sim_top__DOT__soc__DOT__timer__DOT__mi;
        vlSelf->sim_top__DOT__soc__DOT__timer__DOT__h 
            = __Vdly__sim_top__DOT__soc__DOT__timer__DOT__h;
        vlSelf->sim_top__DOT__soc__DOT__timer__DOT__y 
            = __Vdly__sim_top__DOT__soc__DOT__timer__DOT__y;
        vlSelf->sim_top__DOT__soc__DOT__timer__DOT__d 
            = __Vdly__sim_top__DOT__soc__DOT__timer__DOT__d;
        vlSelf->sim_top__DOT__soc__DOT__timer__DOT__mo 
            = __Vdly__sim_top__DOT__soc__DOT__timer__DOT__mo;
    }
    if (vlSelf->sim_top__DOT__soc__DOT__dgo) {
        __Vdly__sim_top__DOT__soc__DOT__disk__DOT__wr_r 
            = vlSelf->sim_top__DOT__soc__DOT__dwr;
        __Vdly__sim_top__DOT__soc__DOT__disk__DOT__buf_r 
            = (((IData)(vlSelf->sim_top__DOT__soc__DOT__d_bufh) 
                << 8U) | (IData)(vlSelf->sim_top__DOT__soc__DOT__d_bufl));
    }
    if (vlSelf->sim_top__DOT__soc__DOT__rst) {
        vlSelf->sim_top__DOT__soc__DOT__e040 = 0U;
        __Vdly__sim_top__DOT__soc__DOT__d_drive = 0U;
        vlSelf->sim_top__DOT__soc__DOT__d_lsn2 = 0U;
        vlSelf->sim_top__DOT__soc__DOT__d_lsn1 = 0U;
        vlSelf->sim_top__DOT__soc__DOT__d_lsn0 = 0U;
        vlSelf->sim_top__DOT__soc__DOT__d_bufh = 0U;
        vlSelf->sim_top__DOT__soc__DOT__d_bufl = 0U;
        vlSelf->sim_top__DOT__soc__DOT__d_47 = 0U;
        __Vdly__sim_top__DOT__soc__DOT__timer__DOT__slo = 0U;
        __Vdly__sim_top__DOT__soc__DOT__timer__DOT__shi = 0U;
        __Vdly__sim_top__DOT__soc__DOT__timer__DOT__scarry = 0U;
        vlSelf->sim_top__DOT__soc__DOT__timer__DOT__sec_tick = 0U;
    } else {
        if (vlSelf->sim_top__DOT__soc__DOT__w_disk) {
            if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__w_off))) {
                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__w_off))) {
                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__w_off))) {
                        vlSelf->sim_top__DOT__soc__DOT__d_47 
                            = vlSelf->sim_top__DOT__soc__DOT__c_wdata;
                    } else {
                        vlSelf->sim_top__DOT__soc__DOT__d_bufl 
                            = vlSelf->sim_top__DOT__soc__DOT__c_wdata;
                    }
                } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__w_off))) {
                    vlSelf->sim_top__DOT__soc__DOT__d_bufh 
                        = vlSelf->sim_top__DOT__soc__DOT__c_wdata;
                } else {
                    vlSelf->sim_top__DOT__soc__DOT__d_lsn0 
                        = vlSelf->sim_top__DOT__soc__DOT__c_wdata;
                }
            } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__w_off))) {
                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__w_off))) {
                    vlSelf->sim_top__DOT__soc__DOT__d_lsn1 
                        = vlSelf->sim_top__DOT__soc__DOT__c_wdata;
                } else {
                    vlSelf->sim_top__DOT__soc__DOT__d_lsn2 
                        = vlSelf->sim_top__DOT__soc__DOT__c_wdata;
                }
            } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__w_off))) {
                __Vdly__sim_top__DOT__soc__DOT__d_drive 
                    = vlSelf->sim_top__DOT__soc__DOT__c_wdata;
            } else if (((0x81U == (IData)(vlSelf->sim_top__DOT__soc__DOT__c_wdata)) 
                        | (0x55U == (IData)(vlSelf->sim_top__DOT__soc__DOT__c_wdata)))) {
                __Vdly__sim_top__DOT__soc__DOT__dgo = 1U;
                vlSelf->sim_top__DOT__soc__DOT__dwr 
                    = (0x55U == (IData)(vlSelf->sim_top__DOT__soc__DOT__c_wdata));
            } else {
                vlSelf->sim_top__DOT__soc__DOT__e040 = 0xffU;
            }
        }
        vlSelf->sim_top__DOT__soc__DOT__timer__DOT__sec_tick = 0U;
        __Vdly__sim_top__DOT__soc__DOT__timer__DOT__scarry = 0U;
        if (vlSelf->sim_top__DOT__soc__DOT__timer__DOT__scarry) {
            __Vdly__sim_top__DOT__soc__DOT__timer__DOT__shi 
                = (0x7ffU & ((IData)(1U) + (IData)(vlSelf->sim_top__DOT__soc__DOT__timer__DOT__shi)));
        }
        if (vlSelf->sim_top__DOT__soc__DOT__ecyc) {
            if ((0x1c9c37U == (((IData)(vlSelf->sim_top__DOT__soc__DOT__timer__DOT__shi) 
                                << 0xbU) | (IData)(vlSelf->sim_top__DOT__soc__DOT__timer__DOT__slo)))) {
                __Vdly__sim_top__DOT__soc__DOT__timer__DOT__slo = 0U;
                __Vdly__sim_top__DOT__soc__DOT__timer__DOT__shi = 0U;
                vlSelf->sim_top__DOT__soc__DOT__timer__DOT__sec_tick = 1U;
            } else {
                __Vdly__sim_top__DOT__soc__DOT__timer__DOT__slo 
                    = (0x7ffU & ((IData)(1U) + (IData)(vlSelf->sim_top__DOT__soc__DOT__timer__DOT__slo)));
                if ((0x7ffU == (IData)(vlSelf->sim_top__DOT__soc__DOT__timer__DOT__slo))) {
                    __Vdly__sim_top__DOT__soc__DOT__timer__DOT__scarry = 1U;
                }
            }
        }
    }
    vlSelf->sim_top__DOT__soc__DOT__timer__DOT__slo 
        = __Vdly__sim_top__DOT__soc__DOT__timer__DOT__slo;
    vlSelf->sim_top__DOT__soc__DOT__timer__DOT__shi 
        = __Vdly__sim_top__DOT__soc__DOT__timer__DOT__shi;
    vlSelf->sim_top__DOT__soc__DOT__timer__DOT__scarry 
        = __Vdly__sim_top__DOT__soc__DOT__timer__DOT__scarry;
    vlSelf->sim_top__DOT__soc__DOT__win_ack_r = __Vdly__sim_top__DOT__soc__DOT__win_ack_r;
    vlSelf->sim_top__DOT__soc__DOT__disk_busy_d = vlSelf->sim_top__DOT__soc__DOT__disk_busy;
    vlSelf->sim_top__DOT__soc__DOT__w_off = (7U & (IData)(vlSelf->sim_top__DOT__soc__DOT__off));
    vlSelf->sim_top__DOT__soc__DOT__w_disk = ((((IData)(vlSelf->sim_top__DOT__soc__DOT__acc2) 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__vma_pend)) 
                                               & (~ (IData)(vlSelf->dbg_rnw))) 
                                              & (IData)(vlSelf->sim_top__DOT__soc__DOT__io_disk));
    __Vdly__sim_top__DOT__soc__DOT__d_addr = (0xffffU 
                                              & ((IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__buf_r) 
                                                 + 
                                                 (0xffU 
                                                  & (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__idx))));
    if ((0x1cU == (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__st))) {
        vlSelf->sim_top__DOT__soc__DOT__disk__DOT__b_waddr 
            = (0x1ffU & (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__idx));
        vlSelf->sim_top__DOT__soc__DOT__disk__DOT__b_wdata 
            = (0xffU & (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__spi_rx));
    } else {
        vlSelf->sim_top__DOT__soc__DOT__disk__DOT__b_waddr 
            = (0x1ffU & (((IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__half) 
                          << 8U) | (0xffU & (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__idx))));
        vlSelf->sim_top__DOT__soc__DOT__disk__DOT__b_wdata 
            = (0xffU & ((1U & vlSelf->sim_top__DOT__soc__DOT__d_addr)
                         ? ((IData)(vlSelf->sim_top__DOT__soc__DOT__ps_dout_m) 
                            >> 8U) : (IData)(vlSelf->sim_top__DOT__soc__DOT__ps_dout_m)));
    }
    if ((0x10U != (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__st))) {
        __Vdly__sim_top__DOT__soc__DOT__disk__DOT__caller 
            = vlSelf->sim_top__DOT__soc__DOT__disk__DOT__st;
    }
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__spi_go = 0U;
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__c_inc = 0U;
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__c_clr = 0U;
    vlSelf->sim_top__DOT__soc__DOT__d_rd = 0U;
    vlSelf->sim_top__DOT__soc__DOT__d_wr = 0U;
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__b_we = 0U;
    if (vlSelf->sim_top__DOT__soc__DOT__rst) {
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__pend_s2m = 0U;
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__m2s3 = 0U;
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__m2s2 = 0U;
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__m2s1 = 0U;
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__m2s0 = 0U;
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__svec = 0xffU;
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__s2m3 = 0U;
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__s2m2 = 0U;
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__s2m1 = 0U;
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__s2m0 = 0U;
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__zdat = 0xffU;
        vlSelf->sim_top__DOT__soc__DOT__acia__DOT__last = 2U;
        vlSelf->sim_top__DOT__soc__DOT__win_wr = 0U;
        vlSelf->sim_top__DOT__soc__DOT__win_addr = 0U;
        vlSelf->sim_top__DOT__soc__DOT__win_req = 0U;
        vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__win_busy = 0U;
    } else {
        if (vlSelf->sim_top__DOT__soc__DOT__zm_ack) {
            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__zm_wr)))) {
                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__zdat 
                    = (0xffU & ((1U & vlSelf->sim_top__DOT__soc__DOT__zm_addr)
                                 ? ((IData)(vlSelf->sim_top__DOT__soc__DOT__zm_rdata_w) 
                                    >> 8U) : (IData)(vlSelf->sim_top__DOT__soc__DOT__zm_rdata_w)));
            }
        }
        if (vlSelf->sim_top__DOT__soc__DOT__acia__DOT__pop) {
            vlSelf->sim_top__DOT__soc__DOT__acia__DOT__last 
                = vlSelf->sim_top__DOT__soc__DOT__acia__DOT__rq;
        }
    }
    if (vlSelf->sim_top__DOT__soc__DOT__dgo) {
        __Vdly__sim_top__DOT__soc__DOT__disk__DOT__pend = 1U;
    }
    if (vlSelf->sim_top__DOT__soc__DOT__rst) {
        __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st = 0U;
        vlSelf->sim_top__DOT__soc__DOT__sd_ready = 0U;
        vlSelf->sim_top__DOT__soc__DOT__sd_fail = 0U;
        vlSelf->sd_cs = 1U;
        vlSelf->sim_top__DOT__soc__DOT__disk__DOT__fast = 0U;
        __Vdly__sim_top__DOT__soc__DOT__disk__DOT__pend = 0U;
        vlSelf->sim_top__DOT__soc__DOT__disk__DOT__exec = 0U;
        vlSelf->sim_top__DOT__soc__DOT__disk__DOT__cvalid = 0U;
        vlSelf->sim_top__DOT__soc__DOT__disk_result = 0xffU;
        vlSelf->sim_top__DOT__soc__DOT__disk__DOT__c_clr = 1U;
    } else if ((0x20U & (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__st))) {
        if ((0x10U & (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__st))) {
            if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__st))) {
                __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st = 0U;
            } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__st))) {
                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__st))) {
                    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st 
                        = ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__st))
                            ? 0U : ((IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__bad_drive)
                                     ? 0x35U : ((IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__hit_q)
                                                 ? 0x1eU
                                                 : 0x17U)));
                } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__st))) {
                    vlSelf->sd_cs = 1U;
                    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__cvalid = 0U;
                    vlSelf->sim_top__DOT__soc__DOT__disk_result = 0xffU;
                    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__spi_tx = 0xffU;
                    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__spi_go = 1U;
                    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st = 0x10U;
                } else {
                    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__pend = 0U;
                    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__exec = 0U;
                    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st = 0xeU;
                }
            } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__st))) {
                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__st))) {
                    vlSelf->sd_cs = 1U;
                    vlSelf->sim_top__DOT__soc__DOT__disk_result = 0U;
                    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__spi_tx = 0xffU;
                    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__spi_go = 1U;
                    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st = 0x10U;
                } else if (vlSelf->sim_top__DOT__soc__DOT__disk__DOT__rx_ff) {
                    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__cvalid = 1U;
                    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__cblk 
                        = vlSelf->sim_top__DOT__soc__DOT__disk__DOT__blk;
                    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st = 0x33U;
                } else if ((0x80000U & vlSelf->sim_top__DOT__soc__DOT__disk__DOT__cnt)) {
                    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st = 0x35U;
                } else {
                    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__c_inc = 1U;
                    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st = 0x31U;
                }
            } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__st))) {
                vlSelf->sim_top__DOT__soc__DOT__disk__DOT__spi_tx = 0xffU;
                vlSelf->sim_top__DOT__soc__DOT__disk__DOT__spi_go = 1U;
                __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st = 0x10U;
            } else {
                vlSelf->sim_top__DOT__soc__DOT__disk__DOT__c_clr = 1U;
                __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st 
                    = ((IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__rx_resp)
                        ? 0x31U : 0x35U);
            }
        } else if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__st))) {
            if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__st))) {
                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__st))) {
                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__st))) {
                        vlSelf->sim_top__DOT__soc__DOT__disk__DOT__spi_tx = 0xffU;
                        vlSelf->sim_top__DOT__soc__DOT__disk__DOT__spi_go = 1U;
                        __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st = 0x10U;
                    } else {
                        __Vdly__sim_top__DOT__soc__DOT__disk__DOT__idx 
                            = (0x3ffU & ((IData)(1U) 
                                         + (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__idx)));
                        if (vlSelf->sim_top__DOT__soc__DOT__disk__DOT__idx_511) {
                            __Vdly__sim_top__DOT__soc__DOT__disk__DOT__skipn = 2U;
                            __Vdly__sim_top__DOT__soc__DOT__disk__DOT__skip_next = 0x2fU;
                            __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st = 0x16U;
                        } else {
                            __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st = 0x2bU;
                        }
                    }
                } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__st))) {
                    __Vtask_sim_top__DOT__soc__DOT__disk__DOT__xfer__53__b 
                        = vlSelf->sim_top__DOT__soc__DOT__disk__DOT__b_q;
                    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__spi_tx 
                        = __Vtask_sim_top__DOT__soc__DOT__disk__DOT__xfer__53__b;
                    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__spi_go = 1U;
                    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st = 0x10U;
                } else {
                    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st = 0x2dU;
                }
            } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__st))) {
                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__st))) {
                    vlSelf->__Vdly__sim_top__DOT__soc__DOT__disk__DOT__b_raddr 
                        = (0x1ffU & (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__idx));
                    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st = 0x2cU;
                } else {
                    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__idx = 0U;
                    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st = 0x2bU;
                }
            } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__st))) {
                vlSelf->sim_top__DOT__soc__DOT__disk__DOT__spi_tx = 0xfeU;
                vlSelf->sim_top__DOT__soc__DOT__disk__DOT__spi_go = 1U;
                __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st = 0x10U;
            } else if (vlSelf->sim_top__DOT__soc__DOT__disk__DOT__r1_ok) {
                vlSelf->sim_top__DOT__soc__DOT__disk__DOT__spi_tx = 0xffU;
                vlSelf->sim_top__DOT__soc__DOT__disk__DOT__spi_go = 1U;
                __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st = 0x10U;
            } else {
                __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st = 0x35U;
            }
        } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__st))) {
            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__st))) {
                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__st))) {
                    __Vtask_sim_top__DOT__soc__DOT__disk__DOT__send_cmd__56__arg 
                        = vlSelf->sim_top__DOT__soc__DOT__disk__DOT__blk_arg;
                    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__cvalid = 0U;
                    vlSelf->sd_cs = 0U;
                    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__cbuf 
                        = (0x5800000000ffULL | ((QData)((IData)(__Vtask_sim_top__DOT__soc__DOT__disk__DOT__send_cmd__56__arg)) 
                                                << 8U));
                    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__cstep = 0U;
                    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__tries = 0U;
                    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__cmd_next = 0x28U;
                    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st = 0x11U;
                } else if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__m0_req)))) {
                    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__idx 
                        = (0x3ffU & ((IData)(1U) + (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__idx)));
                    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__b_we = 1U;
                    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st 
                        = ((IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__idx_255)
                            ? 0x27U : 0x24U);
                }
            } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__st))) {
                __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st = 0x26U;
            } else {
                vlSelf->sim_top__DOT__soc__DOT__d_rd = 1U;
                __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st = 0x25U;
            }
        } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__st))) {
            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__st))) {
                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__m0_req)))) {
                    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__idx 
                        = (0x3ffU & ((IData)(1U) + (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__idx)));
                    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st 
                        = ((IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__idx_255)
                            ? 0x33U : 0x1fU);
                }
            } else {
                __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st = 0x23U;
            }
        } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__st))) {
            vlSelf->sim_top__DOT__soc__DOT__d_wr = 1U;
            __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st = 0x22U;
        } else {
            __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st = 0x21U;
        }
    } else if ((0x10U & (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__st))) {
        if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__st))) {
            if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__st))) {
                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__st))) {
                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__st))) {
                        vlSelf->__Vdly__sim_top__DOT__soc__DOT__disk__DOT__b_raddr 
                            = (((IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__half) 
                                << 8U) | (0xffU & (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__idx)));
                        __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st = 0x20U;
                    } else {
                        __Vdly__sim_top__DOT__soc__DOT__disk__DOT__idx = 0U;
                        __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st 
                            = ((IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__wr_r)
                                ? 0x24U : 0x1fU);
                    }
                } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__st))) {
                    vlSelf->sd_cs = 1U;
                    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__cvalid = 1U;
                    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__cblk 
                        = vlSelf->sim_top__DOT__soc__DOT__disk__DOT__blk;
                    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__spi_tx = 0xffU;
                    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__spi_go = 1U;
                    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st = 0x10U;
                } else {
                    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__idx 
                        = (0x3ffU & ((IData)(1U) + (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__idx)));
                    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__b_we = 1U;
                    if (vlSelf->sim_top__DOT__soc__DOT__disk__DOT__idx_511) {
                        __Vdly__sim_top__DOT__soc__DOT__disk__DOT__skipn = 2U;
                        __Vdly__sim_top__DOT__soc__DOT__disk__DOT__skip_next = 0x1dU;
                        __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st = 0x16U;
                    } else {
                        __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st = 0x1bU;
                    }
                }
            } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__st))) {
                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__st))) {
                    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__spi_tx = 0xffU;
                    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__spi_go = 1U;
                    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st = 0x10U;
                } else if (vlSelf->sim_top__DOT__soc__DOT__disk__DOT__rx_fe) {
                    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__idx = 0U;
                    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st = 0x1bU;
                } else if ((1U & ((~ (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__rx_ff)) 
                                  | (vlSelf->sim_top__DOT__soc__DOT__disk__DOT__cnt 
                                     >> 0x10U)))) {
                    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st = 0x35U;
                } else {
                    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__c_inc = 1U;
                    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st = 0x19U;
                }
            } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__st))) {
                vlSelf->sim_top__DOT__soc__DOT__disk__DOT__spi_tx = 0xffU;
                vlSelf->sim_top__DOT__soc__DOT__disk__DOT__spi_go = 1U;
                __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st = 0x10U;
            } else {
                vlSelf->sim_top__DOT__soc__DOT__disk__DOT__c_clr = 1U;
                __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st 
                    = ((IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__r1_ok)
                        ? 0x19U : 0x35U);
            }
        } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__st))) {
            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__st))) {
                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__st))) {
                    __Vtask_sim_top__DOT__soc__DOT__disk__DOT__send_cmd__60__arg 
                        = vlSelf->sim_top__DOT__soc__DOT__disk__DOT__blk_arg;
                    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__cvalid = 0U;
                    vlSelf->sd_cs = 0U;
                    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__cbuf 
                        = (0x5100000000ffULL | ((QData)((IData)(__Vtask_sim_top__DOT__soc__DOT__disk__DOT__send_cmd__60__arg)) 
                                                << 8U));
                    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__cstep = 0U;
                    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__tries = 0U;
                    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__cmd_next = 0x18U;
                    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st = 0x11U;
                } else if ((0U == (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__skipn))) {
                    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st 
                        = vlSelf->sim_top__DOT__soc__DOT__disk__DOT__skip_next;
                } else {
                    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__skipn 
                        = (3U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__skipn) 
                                 - (IData)(1U)));
                    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__spi_tx = 0xffU;
                    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__spi_go = 1U;
                    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st = 0x10U;
                }
            } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__st))) {
                __Vdly__sim_top__DOT__soc__DOT__disk__DOT__rbytes 
                    = (3U & ((IData)(1U) + (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__rbytes)));
                __Vdly__sim_top__DOT__soc__DOT__disk__DOT__rword 
                    = ((vlSelf->sim_top__DOT__soc__DOT__disk__DOT__rword 
                        << 8U) | (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__spi_rx));
                __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st 
                    = ((3U == (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__rbytes))
                        ? (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__cmd_next)
                        : 0x14U);
            } else {
                vlSelf->sim_top__DOT__soc__DOT__disk__DOT__spi_tx = 0xffU;
                vlSelf->sim_top__DOT__soc__DOT__disk__DOT__spi_go = 1U;
                __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st = 0x10U;
            }
        } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__st))) {
            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__st))) {
                if (vlSelf->sim_top__DOT__soc__DOT__disk__DOT__rx_r1) {
                    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__r1_ok 
                        = vlSelf->sim_top__DOT__soc__DOT__disk__DOT__rx_00;
                    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__r1_idle 
                        = vlSelf->sim_top__DOT__soc__DOT__disk__DOT__rx_01;
                    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__r1_ill 
                        = vlSelf->sim_top__DOT__soc__DOT__disk__DOT__rx_b2;
                    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st 
                        = vlSelf->sim_top__DOT__soc__DOT__disk__DOT__cmd_next;
                } else if ((0x10U & (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__tries))) {
                    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__r1_ok = 0U;
                    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__r1_idle = 0U;
                    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__r1_ill = 1U;
                    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st 
                        = vlSelf->sim_top__DOT__soc__DOT__disk__DOT__cmd_next;
                } else {
                    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st = 0x12U;
                }
            } else {
                __Vdly__sim_top__DOT__soc__DOT__disk__DOT__tries 
                    = (0x1fU & ((IData)(1U) + (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__tries)));
                vlSelf->sim_top__DOT__soc__DOT__disk__DOT__spi_tx = 0xffU;
                vlSelf->sim_top__DOT__soc__DOT__disk__DOT__spi_go = 1U;
                __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st = 0x10U;
            }
        } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__st))) {
            if ((6U == (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__cstep))) {
                __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st = 0x12U;
            } else {
                __Vtask_sim_top__DOT__soc__DOT__disk__DOT__xfer__64__b 
                    = (0xffU & (IData)((vlSelf->sim_top__DOT__soc__DOT__disk__DOT__cbuf 
                                        >> 0x28U)));
                __Vdly__sim_top__DOT__soc__DOT__disk__DOT__cstep 
                    = (7U & ((IData)(1U) + (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__cstep)));
                vlSelf->sim_top__DOT__soc__DOT__disk__DOT__spi_tx 
                    = __Vtask_sim_top__DOT__soc__DOT__disk__DOT__xfer__64__b;
                vlSelf->sim_top__DOT__soc__DOT__disk__DOT__spi_go = 1U;
                __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st = 0x10U;
                __Vdly__sim_top__DOT__soc__DOT__disk__DOT__cbuf 
                    = (0xffULL | (0xffffffffff00ULL 
                                  & (vlSelf->sim_top__DOT__soc__DOT__disk__DOT__cbuf 
                                     << 8U)));
            }
        } else if (vlSelf->sim_top__DOT__soc__DOT__disk__DOT__spi_done) {
            __Vfunc_sim_top__DOT__soc__DOT__disk__DOT__retmap__65__c 
                = vlSelf->sim_top__DOT__soc__DOT__disk__DOT__caller;
            __Vfunc_sim_top__DOT__soc__DOT__disk__DOT__retmap__65__Vfuncout 
                = ((0x20U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__disk__DOT__retmap__65__c))
                    ? ((0x10U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__disk__DOT__retmap__65__c))
                        ? ((8U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__disk__DOT__retmap__65__c))
                            ? 0x34U : ((4U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__disk__DOT__retmap__65__c))
                                        ? 0x34U : (
                                                   (2U 
                                                    & (IData)(__Vfunc_sim_top__DOT__soc__DOT__disk__DOT__retmap__65__c))
                                                    ? 0x34U
                                                    : 
                                                   ((1U 
                                                     & (IData)(__Vfunc_sim_top__DOT__soc__DOT__disk__DOT__retmap__65__c))
                                                     ? 0x32U
                                                     : 0x34U))))
                        : ((8U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__disk__DOT__retmap__65__c))
                            ? ((4U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__disk__DOT__retmap__65__c))
                                ? ((2U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__disk__DOT__retmap__65__c))
                                    ? ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__disk__DOT__retmap__65__c))
                                        ? 0x30U : 0x34U)
                                    : ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__disk__DOT__retmap__65__c))
                                        ? 0x2eU : 0x34U))
                                : ((2U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__disk__DOT__retmap__65__c))
                                    ? 0x34U : ((1U 
                                                & (IData)(__Vfunc_sim_top__DOT__soc__DOT__disk__DOT__retmap__65__c))
                                                ? 0x2aU
                                                : 0x29U)))
                            : 0x34U)) : ((0x10U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__disk__DOT__retmap__65__c))
                                          ? ((8U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__disk__DOT__retmap__65__c))
                                              ? ((4U 
                                                  & (IData)(__Vfunc_sim_top__DOT__soc__DOT__disk__DOT__retmap__65__c))
                                                  ? 
                                                 ((2U 
                                                   & (IData)(__Vfunc_sim_top__DOT__soc__DOT__disk__DOT__retmap__65__c))
                                                   ? 0x34U
                                                   : 
                                                  ((1U 
                                                    & (IData)(__Vfunc_sim_top__DOT__soc__DOT__disk__DOT__retmap__65__c))
                                                    ? 0x1eU
                                                    : 0x34U))
                                                  : 
                                                 ((2U 
                                                   & (IData)(__Vfunc_sim_top__DOT__soc__DOT__disk__DOT__retmap__65__c))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(__Vfunc_sim_top__DOT__soc__DOT__disk__DOT__retmap__65__c))
                                                    ? 0x1cU
                                                    : 0x34U)
                                                   : 
                                                  ((1U 
                                                    & (IData)(__Vfunc_sim_top__DOT__soc__DOT__disk__DOT__retmap__65__c))
                                                    ? 0x1aU
                                                    : 0x34U)))
                                              : ((4U 
                                                  & (IData)(__Vfunc_sim_top__DOT__soc__DOT__disk__DOT__retmap__65__c))
                                                  ? 
                                                 ((2U 
                                                   & (IData)(__Vfunc_sim_top__DOT__soc__DOT__disk__DOT__retmap__65__c))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(__Vfunc_sim_top__DOT__soc__DOT__disk__DOT__retmap__65__c))
                                                    ? 0x34U
                                                    : 0x16U)
                                                   : 
                                                  ((1U 
                                                    & (IData)(__Vfunc_sim_top__DOT__soc__DOT__disk__DOT__retmap__65__c))
                                                    ? 0x34U
                                                    : 0x15U))
                                                  : 
                                                 ((2U 
                                                   & (IData)(__Vfunc_sim_top__DOT__soc__DOT__disk__DOT__retmap__65__c))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(__Vfunc_sim_top__DOT__soc__DOT__disk__DOT__retmap__65__c))
                                                    ? 0x34U
                                                    : 0x13U)
                                                   : 
                                                  ((1U 
                                                    & (IData)(__Vfunc_sim_top__DOT__soc__DOT__disk__DOT__retmap__65__c))
                                                    ? 0x11U
                                                    : 0x34U))))
                                          : ((8U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__disk__DOT__retmap__65__c))
                                              ? ((4U 
                                                  & (IData)(__Vfunc_sim_top__DOT__soc__DOT__disk__DOT__retmap__65__c))
                                                  ? 
                                                 ((2U 
                                                   & (IData)(__Vfunc_sim_top__DOT__soc__DOT__disk__DOT__retmap__65__c))
                                                   ? 0x34U
                                                   : 
                                                  ((1U 
                                                    & (IData)(__Vfunc_sim_top__DOT__soc__DOT__disk__DOT__retmap__65__c))
                                                    ? 0xeU
                                                    : 0x34U))
                                                  : 0x34U)
                                              : ((4U 
                                                  & (IData)(__Vfunc_sim_top__DOT__soc__DOT__disk__DOT__retmap__65__c))
                                                  ? 0x34U
                                                  : 
                                                 ((2U 
                                                   & (IData)(__Vfunc_sim_top__DOT__soc__DOT__disk__DOT__retmap__65__c))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(__Vfunc_sim_top__DOT__soc__DOT__disk__DOT__retmap__65__c))
                                                    ? 0x34U
                                                    : 2U)
                                                   : 0x34U)))));
            __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st 
                = __Vfunc_sim_top__DOT__soc__DOT__disk__DOT__retmap__65__Vfuncout;
        }
    } else if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__st))) {
        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__st))) {
            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__st))) {
                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__st))) {
                    if (vlSelf->sim_top__DOT__soc__DOT__disk__DOT__pend) {
                        vlSelf->sim_top__DOT__soc__DOT__disk_result = 0xffU;
                        __Vdly__sim_top__DOT__soc__DOT__disk__DOT__pend = 0U;
                        __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st = 0U;
                    }
                } else if (vlSelf->sim_top__DOT__soc__DOT__disk__DOT__pend) {
                    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__exec = 1U;
                    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st = 0x36U;
                }
            } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__st))) {
                vlSelf->sim_top__DOT__soc__DOT__disk__DOT__ccs 
                    = ((IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__sdv2) 
                       & (vlSelf->sim_top__DOT__soc__DOT__disk__DOT__rword 
                          >> 0x1eU));
                vlSelf->sim_top__DOT__soc__DOT__disk__DOT__fast = 1U;
                vlSelf->sd_cs = 1U;
                vlSelf->sim_top__DOT__soc__DOT__sd_ready = 1U;
                vlSelf->sim_top__DOT__soc__DOT__sd_fail = 0U;
                vlSelf->sim_top__DOT__soc__DOT__disk__DOT__spi_tx = 0xffU;
                vlSelf->sim_top__DOT__soc__DOT__disk__DOT__spi_go = 1U;
                __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st = 0x10U;
            } else {
                __Vdly__sim_top__DOT__soc__DOT__disk__DOT__cbuf = 0x500000020015ULL;
                __Vdly__sim_top__DOT__soc__DOT__disk__DOT__cstep = 0U;
                __Vdly__sim_top__DOT__soc__DOT__disk__DOT__tries = 0U;
                __Vdly__sim_top__DOT__soc__DOT__disk__DOT__cmd_next = 0xdU;
                __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st = 0x11U;
            }
        } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__st))) {
            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__st))) {
                __Vdly__sim_top__DOT__soc__DOT__disk__DOT__rbytes = 0U;
                __Vdly__sim_top__DOT__soc__DOT__disk__DOT__cmd_next = 0xdU;
                __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st = 0x14U;
            } else {
                vlSelf->sim_top__DOT__soc__DOT__disk__DOT__ccs = 0U;
                __Vdly__sim_top__DOT__soc__DOT__disk__DOT__cbuf = 0x7a00000000fdULL;
                __Vdly__sim_top__DOT__soc__DOT__disk__DOT__cstep = 0U;
                __Vdly__sim_top__DOT__soc__DOT__disk__DOT__tries = 0U;
                __Vdly__sim_top__DOT__soc__DOT__disk__DOT__cmd_next = 0xbU;
                __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st = 0x11U;
            }
        } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__st))) {
            if (vlSelf->sim_top__DOT__soc__DOT__disk__DOT__r1_ok) {
                __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st 
                    = ((IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__sdv2)
                        ? 0xaU : 0xcU);
            } else if ((0x1000U & vlSelf->sim_top__DOT__soc__DOT__disk__DOT__cnt)) {
                vlSelf->sim_top__DOT__soc__DOT__sd_fail = 1U;
                vlSelf->sd_cs = 1U;
                __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st = 0xfU;
            } else {
                vlSelf->sim_top__DOT__soc__DOT__disk__DOT__c_inc = 1U;
                __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st = 7U;
            }
        } else {
            __Vtask_sim_top__DOT__soc__DOT__disk__DOT__send_cmd__69__arg 
                = ((IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__sdv2)
                    ? 0x40000000U : 0U);
            __Vdly__sim_top__DOT__soc__DOT__disk__DOT__cbuf 
                = (0x690000000077ULL | ((QData)((IData)(__Vtask_sim_top__DOT__soc__DOT__disk__DOT__send_cmd__69__arg)) 
                                        << 8U));
            __Vdly__sim_top__DOT__soc__DOT__disk__DOT__cstep = 0U;
            __Vdly__sim_top__DOT__soc__DOT__disk__DOT__tries = 0U;
            __Vdly__sim_top__DOT__soc__DOT__disk__DOT__cmd_next = 9U;
            __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st = 0x11U;
        }
    } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__st))) {
        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__st))) {
            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__st))) {
                __Vdly__sim_top__DOT__soc__DOT__disk__DOT__cbuf = 0x770000000065ULL;
                __Vdly__sim_top__DOT__soc__DOT__disk__DOT__cstep = 0U;
                __Vdly__sim_top__DOT__soc__DOT__disk__DOT__tries = 0U;
                __Vdly__sim_top__DOT__soc__DOT__disk__DOT__cmd_next = 8U;
                __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st = 0x11U;
            } else {
                vlSelf->sim_top__DOT__soc__DOT__disk__DOT__c_clr = 1U;
                if (vlSelf->sim_top__DOT__soc__DOT__disk__DOT__r1_ill) {
                    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__sdv2 = 0U;
                    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st = 7U;
                } else {
                    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__sdv2 = 1U;
                    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__rbytes = 0U;
                    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__cmd_next = 7U;
                    __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st = 0x14U;
                }
            }
        } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__st))) {
            __Vdly__sim_top__DOT__soc__DOT__disk__DOT__cbuf = 0x48000001aa87ULL;
            __Vdly__sim_top__DOT__soc__DOT__disk__DOT__cstep = 0U;
            __Vdly__sim_top__DOT__soc__DOT__disk__DOT__tries = 0U;
            __Vdly__sim_top__DOT__soc__DOT__disk__DOT__cmd_next = 6U;
            __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st = 0x11U;
        } else if (vlSelf->sim_top__DOT__soc__DOT__disk__DOT__r1_idle) {
            __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st = 5U;
        } else if ((0xfU == (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__ctry))) {
            vlSelf->sim_top__DOT__soc__DOT__sd_fail = 1U;
            vlSelf->sd_cs = 1U;
            __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st = 0xfU;
        } else {
            vlSelf->sim_top__DOT__soc__DOT__disk__DOT__ctry 
                = (0xfU & ((IData)(1U) + (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__ctry)));
            __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st = 3U;
        }
    } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__st))) {
        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__st))) {
            vlSelf->sd_cs = 0U;
            __Vdly__sim_top__DOT__soc__DOT__disk__DOT__cbuf = 0x400000000095ULL;
            __Vdly__sim_top__DOT__soc__DOT__disk__DOT__cstep = 0U;
            __Vdly__sim_top__DOT__soc__DOT__disk__DOT__tries = 0U;
            __Vdly__sim_top__DOT__soc__DOT__disk__DOT__cmd_next = 4U;
            __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st = 0x11U;
        } else if (vlSelf->sim_top__DOT__soc__DOT__disk__DOT__idx_10) {
            __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st = 3U;
        } else {
            __Vdly__sim_top__DOT__soc__DOT__disk__DOT__idx 
                = (0x3ffU & ((IData)(1U) + (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__idx)));
            vlSelf->sim_top__DOT__soc__DOT__disk__DOT__spi_tx = 0xffU;
            vlSelf->sim_top__DOT__soc__DOT__disk__DOT__spi_go = 1U;
            __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st = 0x10U;
        }
    } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__st))) {
        vlSelf->sim_top__DOT__soc__DOT__disk__DOT__c_inc = 1U;
        if ((0x40000U & vlSelf->sim_top__DOT__soc__DOT__disk__DOT__cnt)) {
            __Vdly__sim_top__DOT__soc__DOT__disk__DOT__idx = 0U;
            __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st = 2U;
        }
    } else {
        vlSelf->sim_top__DOT__soc__DOT__disk__DOT__ctry = 0U;
        vlSelf->sd_cs = 1U;
        vlSelf->sim_top__DOT__soc__DOT__disk__DOT__fast = 0U;
        vlSelf->sim_top__DOT__soc__DOT__sd_ready = 0U;
        vlSelf->sim_top__DOT__soc__DOT__disk__DOT__cvalid = 0U;
        vlSelf->sim_top__DOT__soc__DOT__disk__DOT__c_clr = 1U;
        __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st = 1U;
    }
    if (vlSelf->sim_top__DOT__soc__DOT__dgo) {
        vlSelf->sim_top__DOT__soc__DOT__disk__DOT__half 
            = (1U & vlSelf->sim_top__DOT__soc__DOT____Vcellinp__disk__lsn);
        vlSelf->sim_top__DOT__soc__DOT__disk__DOT__bad_drive 
            = (1U < (IData)(vlSelf->sim_top__DOT__soc__DOT__d_drive));
        vlSelf->sim_top__DOT__soc__DOT__disk__DOT__blk 
            = (0xffffffU & ((0x7fffffU & (vlSelf->sim_top__DOT__soc__DOT____Vcellinp__disk__lsn 
                                          >> 1U)) + 
                            ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__d_drive))
                              ? 0x40000U : 0U)));
    }
    vlSelf->sim_top__DOT__soc__DOT__acia__DOT__rq = 
        vlSelf->sim_top__DOT__soc__DOT__acia__DOT__fifo
        [vlSelf->sim_top__DOT__soc__DOT__acia__DOT__rp];
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__buf_r 
        = __Vdly__sim_top__DOT__soc__DOT__disk__DOT__buf_r;
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__hit_q 
        = __Vdly__sim_top__DOT__soc__DOT__disk__DOT__hit_q;
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__wr_r 
        = __Vdly__sim_top__DOT__soc__DOT__disk__DOT__wr_r;
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__spi_done 
        = __Vdly__sim_top__DOT__soc__DOT__disk__DOT__spi_done;
    vlSelf->sim_top__DOT__soc__DOT__d_addr = __Vdly__sim_top__DOT__soc__DOT__d_addr;
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__caller 
        = __Vdly__sim_top__DOT__soc__DOT__disk__DOT__caller;
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__st = __Vdly__sim_top__DOT__soc__DOT__disk__DOT__st;
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__cnt 
        = (((IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__cnt_hi) 
            << 8U) | (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__cnt_lo));
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__skipn 
        = __Vdly__sim_top__DOT__soc__DOT__disk__DOT__skipn;
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__skip_next 
        = __Vdly__sim_top__DOT__soc__DOT__disk__DOT__skip_next;
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__cbuf 
        = __Vdly__sim_top__DOT__soc__DOT__disk__DOT__cbuf;
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__cstep 
        = __Vdly__sim_top__DOT__soc__DOT__disk__DOT__cstep;
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__tries 
        = __Vdly__sim_top__DOT__soc__DOT__disk__DOT__tries;
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__cmd_next 
        = __Vdly__sim_top__DOT__soc__DOT__disk__DOT__cmd_next;
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__rbytes 
        = __Vdly__sim_top__DOT__soc__DOT__disk__DOT__rbytes;
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__rword 
        = __Vdly__sim_top__DOT__soc__DOT__disk__DOT__rword;
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__r1_ok 
        = __Vdly__sim_top__DOT__soc__DOT__disk__DOT__r1_ok;
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__r1_idle 
        = __Vdly__sim_top__DOT__soc__DOT__disk__DOT__r1_idle;
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__r1_ill 
        = __Vdly__sim_top__DOT__soc__DOT__disk__DOT__r1_ill;
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__pend 
        = __Vdly__sim_top__DOT__soc__DOT__disk__DOT__pend;
    if (__Vdlyvset__sim_top__DOT__soc__DOT__acia__DOT__fifo__v0) {
        vlSelf->sim_top__DOT__soc__DOT__acia__DOT__fifo[__Vdlyvdim0__sim_top__DOT__soc__DOT__acia__DOT__fifo__v0] 
            = __Vdlyvval__sim_top__DOT__soc__DOT__acia__DOT__fifo__v0;
    }
    vlSelf->sim_top__DOT__soc__DOT__acia__DOT__rp = __Vdly__sim_top__DOT__soc__DOT__acia__DOT__rp;
    vlSelf->sim_top__DOT__soc__DOT__io_disk = (((IData)(vlSelf->sim_top__DOT__soc__DOT__in_io) 
                                                & (0x40U 
                                                   <= (IData)(vlSelf->sim_top__DOT__soc__DOT__off))) 
                                               & (0x47U 
                                                  >= (IData)(vlSelf->sim_top__DOT__soc__DOT__off)));
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__idx_511 
        = (0x1ffU == (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__idx));
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__idx_255 
        = (0xffU == (0xffU & (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__idx)));
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__idx_10 
        = (0xaU == (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__idx));
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__rx_ff 
        = (0xffU == (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__spi_rx));
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__rx_resp 
        = (5U == (0x1fU & (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__spi_rx)));
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__rx_fe 
        = (0xfeU == (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__spi_rx));
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__rx_r1 
        = (1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__spi_rx) 
                    >> 7U)));
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__rx_00 
        = (0U == (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__spi_rx));
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__rx_01 
        = (1U == (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__spi_rx));
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__rx_b2 
        = (1U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__spi_rx) 
                 >> 2U));
    vlSelf->sim_top__DOT__soc__DOT__acia__DOT__empty 
        = ((IData)(vlSelf->sim_top__DOT__soc__DOT__acia__DOT__rp) 
           == (IData)(vlSelf->sim_top__DOT__soc__DOT__acia__DOT__wp));
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__idx 
        = __Vdly__sim_top__DOT__soc__DOT__disk__DOT__idx;
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__spi_rx 
        = __Vdly__sim_top__DOT__soc__DOT__disk__DOT__spi_rx;
    vlSelf->sim_top__DOT__soc__DOT____Vcellinp__disk__lsn 
        = (((IData)(vlSelf->sim_top__DOT__soc__DOT__d_lsn2) 
            << 0x10U) | (((IData)(vlSelf->sim_top__DOT__soc__DOT__d_lsn1) 
                          << 8U) | (IData)(vlSelf->sim_top__DOT__soc__DOT__d_lsn0)));
    vlSelf->sim_top__DOT__soc__DOT__dgo = __Vdly__sim_top__DOT__soc__DOT__dgo;
    vlSelf->sim_top__DOT__soc__DOT__d_drive = __Vdly__sim_top__DOT__soc__DOT__d_drive;
    vlSelf->sim_top__DOT__soc__DOT__acia__DOT__pop 
        = ((~ (IData)(vlSelf->sim_top__DOT__soc__DOT__acia__DOT__empty)) 
           & (IData)(vlSelf->sim_top__DOT__soc__DOT__acia_rd));
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__blk_arg 
        = ((IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__ccs)
            ? vlSelf->sim_top__DOT__soc__DOT__disk__DOT__blk
            : (vlSelf->sim_top__DOT__soc__DOT__disk__DOT__blk 
               << 9U));
}

VL_INLINE_OPT void Vsim_top___024root___nba_sequent__TOP__1(Vsim_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___nba_sequent__TOP__1\n"); );
    // Body
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Pre_XY_F_M 
        = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Pre_XY_F_M;
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IntE_FF2 
        = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IntE_FF2;
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IntE_FF1 
        = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IntE_FF1;
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Auto_Wait_t2 
        = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Auto_Wait_t2;
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Auto_Wait_t1 
        = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Auto_Wait_t1;
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstate 
        = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstate;
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__NMICycle 
        = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__NMICycle;
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle 
        = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle;
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ACC 
        = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ACC;
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__TmpAddr 
        = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__TmpAddr;
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__PC 
        = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__PC;
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__SP 
        = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__SP;
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__XY_State 
        = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__XY_State;
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F 
        = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F;
    vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR 
        = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR;
    if (vlSelf->sim_top__DOT__soc__DOT__sub__DOT__sub_rst_n) {
        if (vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ClkEn) {
            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                          & (IData)((0U != (0xeU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstate)))))))) {
                if (vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ExchangeRS) {
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Alternate 
                        = (1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Alternate)));
                }
            }
            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Arith16_r 
                = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Arith16;
            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles 
                = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d;
            if (((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                 & (0U != (0xeU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstate))))) {
                if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstate))) {
                    if ((0U != (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Prefix))) {
                        if ((3U != (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Prefix))) {
                            if ((2U == (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Prefix))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__XY_Ind = 0U;
                            }
                        }
                    } else {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__XY_Ind = 0U;
                    }
                }
            } else if ((0x20U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__XY_Ind = 1U;
            }
        }
        if ((4U == (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cnt))) {
            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__wr_n = 1U;
            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                if ((((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstate) 
                      >> 1U) & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write))) {
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__wr_n = 0U;
                }
            }
            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__rd_n = 1U;
            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__iorq_n = 1U;
            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__mreq_n = 1U;
            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstate))) {
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__rd_n 
                        = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IntCycle;
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__iorq_n 
                        = (1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IntCycle)));
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__mreq_n 
                        = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IntCycle;
                }
            } else {
                if ((1U & ((((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstate) 
                             >> 1U) & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__no_read))) 
                           & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write))))) {
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__rd_n = 0U;
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__iorq_n 
                        = (1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__iorq_i)));
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__mreq_n 
                        = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__iorq_i;
                }
                if ((((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstate) 
                      >> 1U) & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write))) {
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__iorq_n 
                        = (1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__iorq_i)));
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__mreq_n 
                        = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__iorq_i;
                }
            }
        }
    } else {
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Alternate = 0U;
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Arith16_r = 0U;
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles = 0U;
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__wr_n = 1U;
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__rd_n = 1U;
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__iorq_n = 1U;
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__mreq_n = 1U;
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__XY_Ind = 0U;
    }
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__io_wr 
        = (1U & ((~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__iorq_n)) 
                 & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__wr_n))));
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__mem_rd 
        = (1U & ((~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__mreq_n)) 
                 & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__rd_n))));
}

VL_INLINE_OPT void Vsim_top___024root___nba_sequent__TOP__2(Vsim_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___nba_sequent__TOP__2\n"); );
    // Body
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__NMISample2 
        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__NMISample;
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__FIRQLatched 
        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__FIRQSample2;
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DMABREQLatched 
        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DMABREQSample2;
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__HALTLatched 
        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__HALTSample2;
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IRQLatched 
        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IRQSample2;
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__FIRQSample2 
        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__FIRQSample;
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DMABREQSample2 
        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DMABREQSample;
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__HALTSample2 
        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__HALTSample;
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IRQSample2 
        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IRQSample;
}

VL_INLINE_OPT void Vsim_top___024root___nba_sequent__TOP__3(Vsim_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___nba_sequent__TOP__3\n"); );
    // Body
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__NMILatched 
        = ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__NMIClear) 
           | (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__NMIMask));
}

VL_INLINE_OPT void Vsim_top___024root___nba_comb__TOP__0(Vsim_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___nba_comb__TOP__0\n"); );
    // Body
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__s_we 
        = ((~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__io_wr)) 
           & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__io_wr_q));
}

VL_INLINE_OPT void Vsim_top___024root___nba_sequent__TOP__4(Vsim_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___nba_sequent__TOP__4\n"); );
    // Body
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__NMISample = 1U;
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__FIRQSample 
        = (1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT____VdfgTmp_h1ff8cf4e__0) 
                    & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__c_firq))));
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DMABREQSample = 1U;
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__HALTSample = 1U;
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IRQSample 
        = (1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__timer__DOT__pending) 
                    | ((~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__c_firq)) 
                       & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT____VdfgTmp_h1ff8cf4e__0)))));
}

VL_INLINE_OPT void Vsim_top___024root___nba_sequent__TOP__5(Vsim_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___nba_sequent__TOP__5\n"); );
    // Init
    CData/*7:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__15__Vfuncout;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__15__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__15__postbyte;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__15__postbyte = 0;
    CData/*2:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__15__regnum;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__15__regnum = 0;
    CData/*0:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__15__indirect;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__15__indirect = 0;
    CData/*7:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__16__Vfuncout;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__16__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__16__postbyte;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__16__postbyte = 0;
    CData/*2:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__16__regnum;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__16__regnum = 0;
    CData/*0:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__16__indirect;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__16__indirect = 0;
    CData/*7:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__17__Vfuncout;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__17__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__17__postbyte;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__17__postbyte = 0;
    CData/*2:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__17__regnum;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__17__regnum = 0;
    CData/*0:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__17__indirect;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__17__indirect = 0;
    CData/*1:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST8__18__Vfuncout;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST8__18__Vfuncout = 0;
    CData/*0:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST8__18__regnum;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST8__18__regnum = 0;
    CData/*0:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST8__18__IsStore;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST8__18__IsStore = 0;
    CData/*1:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST8__19__Vfuncout;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST8__19__Vfuncout = 0;
    CData/*0:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST8__19__regnum;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST8__19__regnum = 0;
    CData/*0:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST8__19__IsStore;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST8__19__IsStore = 0;
    CData/*3:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST16__20__Vfuncout;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST16__20__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST16__20__inst;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST16__20__inst = 0;
    CData/*2:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST16__20__regnum;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST16__20__regnum = 0;
    CData/*0:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST16__20__IsStore;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST16__20__IsStore = 0;
    CData/*3:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST16__21__Vfuncout;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST16__21__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST16__21__inst;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST16__21__inst = 0;
    CData/*2:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST16__21__regnum;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST16__21__regnum = 0;
    CData/*0:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST16__21__IsStore;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST16__21__IsStore = 0;
    CData/*0:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsSpecialImm__22__Vfuncout;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsSpecialImm__22__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsSpecialImm__22__inst;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsSpecialImm__22__inst = 0;
    CData/*0:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsSpecialImm__22__is;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsSpecialImm__22__is = 0;
    CData/*3:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsSpecialImm__22__hi;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsSpecialImm__22__hi = 0;
    CData/*3:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsSpecialImm__22__lo;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsSpecialImm__22__lo = 0;
    CData/*2:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16RegFromInst__23__Vfuncout;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16RegFromInst__23__Vfuncout = 0;
    CData/*0:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16RegFromInst__23__Page2;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16RegFromInst__23__Page2 = 0;
    CData/*0:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16RegFromInst__23__Page3;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16RegFromInst__23__Page3 = 0;
    CData/*7:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16RegFromInst__23__inst;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16RegFromInst__23__inst = 0;
    CData/*2:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16RegFromInst__23__srcreg;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16RegFromInst__23__srcreg = 0;
    CData/*3:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__Vfuncout;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__Vfuncout = 0;
    CData/*0:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__Page2;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__Page2 = 0;
    CData/*0:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__Page3;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__Page3 = 0;
    CData/*7:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__inst;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__inst = 0;
    CData/*2:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__aluop;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__aluop = 0;
    CData/*0:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__writeback;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__writeback = 0;
    CData/*3:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__Vfuncout;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__Vfuncout = 0;
    CData/*0:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__Page2;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__Page2 = 0;
    CData/*0:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__Page3;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__Page3 = 0;
    CData/*7:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__inst;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__inst = 0;
    CData/*2:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__aluop;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__aluop = 0;
    CData/*0:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__writeback;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__writeback = 0;
    CData/*5:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUOpFromInst__27__Vfuncout;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUOpFromInst__27__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUOpFromInst__27__inst;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUOpFromInst__27__inst = 0;
    CData/*4:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUOpFromInst__27__op;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUOpFromInst__27__op = 0;
    CData/*0:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUOpFromInst__27__writeback;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUOpFromInst__27__writeback = 0;
    CData/*5:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUOpFromInst__28__Vfuncout;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUOpFromInst__28__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUOpFromInst__28__inst;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUOpFromInst__28__inst = 0;
    CData/*4:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUOpFromInst__28__op;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUOpFromInst__28__op = 0;
    CData/*0:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUOpFromInst__28__writeback;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUOpFromInst__28__writeback = 0;
    CData/*2:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__addressing_mode_type__30__Vfuncout;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__addressing_mode_type__30__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__addressing_mode_type__30__inst;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__addressing_mode_type__30__inst = 0;
    CData/*0:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU8BitOp__31__Vfuncout;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU8BitOp__31__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU8BitOp__31__instr;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU8BitOp__31__instr = 0;
    CData/*0:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set0__32__Vfuncout;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set0__32__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set0__32__instr;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set0__32__instr = 0;
    CData/*0:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set0__32__result;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set0__32__result = 0;
    CData/*3:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set0__32__hi;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set0__32__hi = 0;
    CData/*3:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set0__32__lo;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set0__32__lo = 0;
    CData/*0:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set1__33__Vfuncout;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set1__33__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set1__33__instr;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set1__33__instr = 0;
    CData/*0:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set1__33__result;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set1__33__result = 0;
    CData/*3:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set1__33__hi;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set1__33__hi = 0;
    CData/*3:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set1__33__lo;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set1__33__lo = 0;
    CData/*0:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsRegA__34__Vfuncout;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsRegA__34__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsRegA__34__instr;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsRegA__34__instr = 0;
    CData/*0:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsRegA__34__result;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsRegA__34__result = 0;
    CData/*3:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsRegA__34__hi;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsRegA__34__hi = 0;
    CData/*0:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__take_branch__35__Vfuncout;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__take_branch__35__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__take_branch__35__Inst1;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__take_branch__35__Inst1 = 0;
    CData/*7:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__take_branch__35__cc;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__take_branch__35__cc = 0;
    // Body
    if (vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rnRESET) {
        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState 
            = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState_nxt;
        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__NextState 
            = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__NextState_nxt;
        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__a 
            = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__a_nxt;
        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__b 
            = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__b_nxt;
        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__x 
            = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__x_nxt;
        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__y 
            = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__y_nxt;
        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u 
            = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u_nxt;
        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc 
            = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc_nxt;
        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__dp 
            = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__dp_nxt;
        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc 
            = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc_nxt;
        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp 
            = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__tmp_nxt;
        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr 
            = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__addr_nxt;
        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ea 
            = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ea_nxt;
        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__InstPage2 
            = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__InstPage2_nxt;
        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__InstPage3 
            = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__InstPage3_nxt;
        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1 
            = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1_nxt;
        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst2 
            = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst2_nxt;
        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst3 
            = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst3_nxt;
        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__NMIClear 
            = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__NMIClear_nxt;
        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IntType 
            = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IntType_nxt;
        if (((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s) 
             != (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s_nxt))) {
            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__NMIMask = 0U;
        }
        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s 
            = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s_nxt;
    } else {
        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState = 0U;
        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__NMIMask = 1U;
        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__NMIClear = 0U;
    }
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__NMIClear_nxt 
        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__NMIClear;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__15__postbyte 
        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst2;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__15__indirect = 0U;
    if ((0x80U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__15__postbyte))) {
        vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__15__mode 
            = (0xfU & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__15__postbyte));
        __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__15__indirect 
            = (1U & ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__15__postbyte) 
                     >> 4U));
    } else {
        vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__15__mode = 7U;
    }
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__15__regnum 
        = (((0xcU != (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__15__mode)) 
            & (0xdU != (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__15__mode)))
            ? (3U & ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__15__postbyte) 
                     >> 5U)) : 4U);
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__15__Vfuncout 
        = (((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__15__indirect) 
            << 7U) | (((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__15__mode) 
                       << 3U) | (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__15__regnum)));
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IndexedIndirect 
        = (1U & ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__15__Vfuncout) 
                 >> 7U));
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__16__postbyte 
        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst2;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__16__indirect = 0U;
    if ((0x80U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__16__postbyte))) {
        vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__16__mode 
            = (0xfU & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__16__postbyte));
        __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__16__indirect 
            = (1U & ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__16__postbyte) 
                     >> 4U));
    } else {
        vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__16__mode = 7U;
    }
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__16__regnum 
        = (((0xcU != (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__16__mode)) 
            & (0xdU != (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__16__mode)))
            ? (3U & ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__16__postbyte) 
                     >> 5U)) : 4U);
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__16__Vfuncout 
        = (((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__16__indirect) 
            << 7U) | (((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__16__mode) 
                       << 3U) | (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__16__regnum)));
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IndexedMode 
        = (0xfU & ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__16__Vfuncout) 
                   >> 3U));
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__17__postbyte 
        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst2;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__17__indirect = 0U;
    if ((0x80U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__17__postbyte))) {
        vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__17__mode 
            = (0xfU & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__17__postbyte));
        __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__17__indirect 
            = (1U & ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__17__postbyte) 
                     >> 4U));
    } else {
        vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__17__mode = 7U;
    }
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__17__regnum 
        = (((0xcU != (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__17__mode)) 
            & (0xdU != (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__17__mode)))
            ? (3U & ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__17__postbyte) 
                     >> 5U)) : 4U);
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__17__Vfuncout 
        = (((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__17__indirect) 
            << 7U) | (((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__17__mode) 
                       << 3U) | (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__17__regnum)));
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IndexedRegister 
        = (7U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IndexDecode__17__Vfuncout));
    vlSelf->dbg_regs[0U] = (((IData)((((QData)((IData)(
                                                       (((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u) 
                                                         << 0x10U) 
                                                        | (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s)))) 
                                       << 0x20U) | (QData)((IData)(
                                                                   (((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__y) 
                                                                     << 0x10U) 
                                                                    | (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__x)))))) 
                             << 0x10U) | (((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__b) 
                                           << 8U) | (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__a)));
    vlSelf->dbg_regs[1U] = (((IData)((((QData)((IData)(
                                                       (((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u) 
                                                         << 0x10U) 
                                                        | (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s)))) 
                                       << 0x20U) | (QData)((IData)(
                                                                   (((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__y) 
                                                                     << 0x10U) 
                                                                    | (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__x)))))) 
                             >> 0x10U) | ((IData)((
                                                   (((QData)((IData)(
                                                                     (((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u) 
                                                                       << 0x10U) 
                                                                      | (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s)))) 
                                                     << 0x20U) 
                                                    | (QData)((IData)(
                                                                      (((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__y) 
                                                                        << 0x10U) 
                                                                       | (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__x))))) 
                                                   >> 0x20U)) 
                                          << 0x10U));
    vlSelf->dbg_regs[2U] = (((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__dp) 
                             << 0x18U) | (((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc) 
                                           << 0x10U) 
                                          | ((IData)(
                                                     ((((QData)((IData)(
                                                                        (((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__u) 
                                                                          << 0x10U) 
                                                                         | (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__s)))) 
                                                        << 0x20U) 
                                                       | (QData)((IData)(
                                                                         (((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__y) 
                                                                           << 0x10U) 
                                                                          | (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__x))))) 
                                                      >> 0x20U)) 
                                             >> 0x10U)));
    vlSelf->dbg_regs[3U] = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__pc;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST8__18__IsStore = 0U;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST8__18__regnum = 1U;
    if ((((0x97U == (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1)) 
          | (0xa7U == (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1))) 
         | (0xb7U == (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1)))) {
        __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST8__18__IsStore = 1U;
        __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST8__18__regnum = 0U;
    } else if ((((0xd7U == (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1)) 
                 | (0xe7U == (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1))) 
                | (0xf7U == (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1)))) {
        __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST8__18__IsStore = 1U;
        __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST8__18__regnum = 1U;
    }
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST8__18__Vfuncout 
        = (((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST8__18__IsStore) 
            << 1U) | (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST8__18__regnum));
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IsStore8 
        = (1U & ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST8__18__Vfuncout) 
                 >> 1U));
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST8__19__IsStore = 0U;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST8__19__regnum = 1U;
    if ((((0x97U == (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1)) 
          | (0xa7U == (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1))) 
         | (0xb7U == (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1)))) {
        __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST8__19__IsStore = 1U;
        __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST8__19__regnum = 0U;
    } else if ((((0xd7U == (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1)) 
                 | (0xe7U == (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1))) 
                | (0xf7U == (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1)))) {
        __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST8__19__IsStore = 1U;
        __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST8__19__regnum = 1U;
    }
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST8__19__Vfuncout 
        = (((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST8__19__IsStore) 
            << 1U) | (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST8__19__regnum));
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Store8RegisterNum 
        = (1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST8__19__Vfuncout));
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__take_branch__35__cc 
        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__take_branch__35__Inst1 
        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__take_branch__35__Vfuncout = 0U;
    if ((((0x8dU == (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__take_branch__35__Inst1)) 
          | (0x17U == (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__take_branch__35__Inst1))) 
         | (0x16U == (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__take_branch__35__Inst1)))) {
        __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__take_branch__35__Vfuncout = 1U;
    } else if ((8U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__take_branch__35__Inst1))) {
        if ((4U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__take_branch__35__Inst1))) {
            if ((2U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__take_branch__35__Inst1))) {
                if ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__take_branch__35__Inst1))) {
                    if ((1U & ((1U == ((1U & ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__take_branch__35__cc) 
                                              >> 3U)) 
                                       ^ (1U & ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__take_branch__35__cc) 
                                                >> 1U)))) 
                               | ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__take_branch__35__cc) 
                                  >> 2U)))) {
                        __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__take_branch__35__Vfuncout = 1U;
                    }
                } else if (((0U == ((1U & ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__take_branch__35__cc) 
                                           >> 3U)) 
                                    ^ (1U & ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__take_branch__35__cc) 
                                             >> 1U)))) 
                            & (~ ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__take_branch__35__cc) 
                                  >> 2U)))) {
                    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__take_branch__35__Vfuncout = 1U;
                }
            } else if ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__take_branch__35__Inst1))) {
                if ((1U == ((1U & ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__take_branch__35__cc) 
                                   >> 3U)) ^ (1U & 
                                              ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__take_branch__35__cc) 
                                               >> 1U))))) {
                    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__take_branch__35__Vfuncout = 1U;
                }
            } else if ((0U == ((1U & ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__take_branch__35__cc) 
                                      >> 3U)) ^ (1U 
                                                 & ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__take_branch__35__cc) 
                                                    >> 1U))))) {
                __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__take_branch__35__Vfuncout = 1U;
            }
        } else if ((2U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__take_branch__35__Inst1))) {
            if ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__take_branch__35__Inst1))) {
                if ((8U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__take_branch__35__cc))) {
                    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__take_branch__35__Vfuncout = 1U;
                }
            } else if ((1U & (~ ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__take_branch__35__cc) 
                                 >> 3U)))) {
                __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__take_branch__35__Vfuncout = 1U;
            }
        } else if ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__take_branch__35__Inst1))) {
            if ((2U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__take_branch__35__cc))) {
                __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__take_branch__35__Vfuncout = 1U;
            }
        } else if ((1U & (~ ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__take_branch__35__cc) 
                             >> 1U)))) {
            __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__take_branch__35__Vfuncout = 1U;
        }
    } else if ((4U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__take_branch__35__Inst1))) {
        if ((2U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__take_branch__35__Inst1))) {
            if ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__take_branch__35__Inst1))) {
                if ((4U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__take_branch__35__cc))) {
                    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__take_branch__35__Vfuncout = 1U;
                }
            } else if ((1U & (~ ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__take_branch__35__cc) 
                                 >> 2U)))) {
                __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__take_branch__35__Vfuncout = 1U;
            }
        } else if ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__take_branch__35__Inst1))) {
            if ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__take_branch__35__cc))) {
                __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__take_branch__35__Vfuncout = 1U;
            }
        } else if ((1U & (~ (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__take_branch__35__cc)))) {
            __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__take_branch__35__Vfuncout = 1U;
        }
    } else if ((2U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__take_branch__35__Inst1))) {
        if ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__take_branch__35__Inst1))) {
            if ((IData)((0U != (5U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__take_branch__35__cc))))) {
                __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__take_branch__35__Vfuncout = 1U;
            }
        } else if ((0U == (1U & (((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__take_branch__35__cc) 
                                  >> 2U) | (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__take_branch__35__cc))))) {
            __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__take_branch__35__Vfuncout = 1U;
        }
    } else {
        __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__take_branch__35__Vfuncout 
            = (1U & (~ (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__take_branch__35__Inst1)));
    }
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__TakeBranch 
        = __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__take_branch__35__Vfuncout;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUOpFromInst__27__inst 
        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUOpFromInst__27__op 
        = ((0x10U & ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUOpFromInst__27__inst) 
                     >> 3U)) | (0xfU & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUOpFromInst__27__inst)));
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUOpFromInst__27__writeback 
        = ((0x11U != (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUOpFromInst__27__op)) 
           & ((0xdU != (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUOpFromInst__27__op)) 
              & (0x15U != (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUOpFromInst__27__op))));
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUOpFromInst__27__Vfuncout 
        = (((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUOpFromInst__27__writeback) 
            << 5U) | (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUOpFromInst__27__op));
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU8Writeback 
        = (1U & ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUOpFromInst__27__Vfuncout) 
                 >> 5U));
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUOpFromInst__28__inst 
        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUOpFromInst__28__op 
        = ((0x10U & ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUOpFromInst__28__inst) 
                     >> 3U)) | (0xfU & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUOpFromInst__28__inst)));
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUOpFromInst__28__writeback 
        = ((0x11U != (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUOpFromInst__28__op)) 
           & ((0xdU != (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUOpFromInst__28__op)) 
              & (0x15U != (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUOpFromInst__28__op))));
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUOpFromInst__28__Vfuncout 
        = (((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUOpFromInst__28__writeback) 
            << 5U) | (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUOpFromInst__28__op));
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU8Op 
        = (0x1fU & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALUOpFromInst__28__Vfuncout));
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsRegA__34__instr 
        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsRegA__34__hi 
        = (0xfU & ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsRegA__34__instr) 
                   >> 4U));
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsRegA__34__result 
        = (((((4U == (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsRegA__34__hi)) 
              | (8U == (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsRegA__34__hi))) 
             | (9U == (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsRegA__34__hi))) 
            | (0xaU == (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsRegA__34__hi))) 
           | (0xbU == (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsRegA__34__hi)));
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsRegA__34__Vfuncout 
        = __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsRegA__34__result;
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IsTargetRegA 
        = __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsRegA__34__Vfuncout;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST16__20__inst 
        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST16__20__IsStore = 0U;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST16__20__regnum = 7U;
    if ((((0x9fU == (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST16__20__inst)) 
          | (0xafU == (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST16__20__inst))) 
         | (0xbfU == (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST16__20__inst)))) {
        __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST16__20__IsStore = 1U;
        __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST16__20__regnum 
            = ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__InstPage2)
                ? 1U : 0U);
    } else if ((((0xdfU == (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST16__20__inst)) 
                 | (0xefU == (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST16__20__inst))) 
                | (0xffU == (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST16__20__inst)))) {
        __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST16__20__IsStore = 1U;
        __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST16__20__regnum 
            = ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__InstPage2)
                ? 3U : 2U);
    } else if ((((0xddU == (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST16__20__inst)) 
                 | (0xedU == (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST16__20__inst))) 
                | (0xfdU == (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST16__20__inst)))) {
        __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST16__20__IsStore = 1U;
        __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST16__20__regnum = 4U;
    }
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST16__20__Vfuncout 
        = (((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST16__20__IsStore) 
            << 3U) | (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST16__20__regnum));
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IsStore16 
        = (1U & ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST16__20__Vfuncout) 
                 >> 3U));
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST16__21__inst 
        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST16__21__IsStore = 0U;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST16__21__regnum = 7U;
    if ((((0x9fU == (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST16__21__inst)) 
          | (0xafU == (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST16__21__inst))) 
         | (0xbfU == (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST16__21__inst)))) {
        __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST16__21__IsStore = 1U;
        __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST16__21__regnum 
            = ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__InstPage2)
                ? 1U : 0U);
    } else if ((((0xdfU == (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST16__21__inst)) 
                 | (0xefU == (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST16__21__inst))) 
                | (0xffU == (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST16__21__inst)))) {
        __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST16__21__IsStore = 1U;
        __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST16__21__regnum 
            = ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__InstPage2)
                ? 3U : 2U);
    } else if ((((0xddU == (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST16__21__inst)) 
                 | (0xedU == (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST16__21__inst))) 
                | (0xfdU == (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST16__21__inst)))) {
        __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST16__21__IsStore = 1U;
        __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST16__21__regnum = 4U;
    }
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST16__21__Vfuncout 
        = (((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST16__21__IsStore) 
            << 3U) | (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST16__21__regnum));
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__StoreRegisterNum 
        = (7U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsST16__21__Vfuncout));
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__addressing_mode_type__30__inst 
        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__addressing_mode_type__30__Vfuncout 
        = ((0x80U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__addressing_mode_type__30__inst))
            ? ((0x40U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__addressing_mode_type__30__inst))
                ? ((0x20U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__addressing_mode_type__30__inst))
                    ? ((0x10U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__addressing_mode_type__30__inst))
                        ? 5U : 4U) : ((0x10U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__addressing_mode_type__30__inst))
                                       ? 2U : 1U)) : 
               ((0x20U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__addressing_mode_type__30__inst))
                 ? ((0x10U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__addressing_mode_type__30__inst))
                     ? 5U : 4U) : ((0x10U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__addressing_mode_type__30__inst))
                                    ? 2U : ((7U == 
                                             (0xfU 
                                              & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__addressing_mode_type__30__inst)))
                                             ? 7U : 
                                            ((0xfU 
                                              == (0xfU 
                                                  & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__addressing_mode_type__30__inst)))
                                              ? 7U : 
                                             ((0xdU 
                                               == (0xfU 
                                                   & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__addressing_mode_type__30__inst)))
                                               ? 3U
                                               : 1U))))))
            : ((0x40U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__addressing_mode_type__30__inst))
                ? ((0x20U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__addressing_mode_type__30__inst))
                    ? ((0x10U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__addressing_mode_type__30__inst))
                        ? 5U : 4U) : 0U) : ((0x20U 
                                             & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__addressing_mode_type__30__inst))
                                             ? ((0x10U 
                                                 & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__addressing_mode_type__30__inst))
                                                 ? 
                                                ((8U 
                                                  & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__addressing_mode_type__30__inst))
                                                  ? 
                                                 ((4U 
                                                   & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__addressing_mode_type__30__inst))
                                                   ? 
                                                  ((2U 
                                                    & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__addressing_mode_type__30__inst))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__addressing_mode_type__30__inst))
                                                     ? 0U
                                                     : 7U)
                                                    : 0U)
                                                   : 
                                                  ((2U 
                                                    & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__addressing_mode_type__30__inst))
                                                    ? 0U
                                                    : 
                                                   ((1U 
                                                     & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__addressing_mode_type__30__inst))
                                                     ? 0U
                                                     : 7U)))
                                                  : 
                                                 ((4U 
                                                   & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__addressing_mode_type__30__inst))
                                                   ? 1U
                                                   : 4U))
                                                 : 3U)
                                             : ((0x10U 
                                                 & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__addressing_mode_type__30__inst))
                                                 ? 
                                                ((8U 
                                                  & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__addressing_mode_type__30__inst))
                                                  ? 
                                                 ((4U 
                                                   & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__addressing_mode_type__30__inst))
                                                   ? 
                                                  ((2U 
                                                    & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__addressing_mode_type__30__inst))
                                                    ? 1U
                                                    : 
                                                   ((1U 
                                                     & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__addressing_mode_type__30__inst))
                                                     ? 0U
                                                     : 1U))
                                                   : 
                                                  ((2U 
                                                    & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__addressing_mode_type__30__inst))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__addressing_mode_type__30__inst))
                                                     ? 7U
                                                     : 1U)
                                                    : 
                                                   ((1U 
                                                     & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__addressing_mode_type__30__inst))
                                                     ? 0U
                                                     : 7U)))
                                                  : 
                                                 ((4U 
                                                   & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__addressing_mode_type__30__inst))
                                                   ? 
                                                  ((2U 
                                                    & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__addressing_mode_type__30__inst))
                                                    ? 3U
                                                    : 7U)
                                                   : 
                                                  ((2U 
                                                    & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__addressing_mode_type__30__inst))
                                                    ? 0U
                                                    : 7U)))
                                                 : 2U))));
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__AddrModeType 
        = __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__addressing_mode_type__30__Vfuncout;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16RegFromInst__23__inst 
        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16RegFromInst__23__Page3 
        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__InstPage3;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16RegFromInst__23__Page2 
        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__InstPage2;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16RegFromInst__23__srcreg 
        = ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16RegFromInst__23__Page2)
            ? ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16RegFromInst__23__Page3)
                ? 7U : ((0x80U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16RegFromInst__23__inst))
                         ? ((0x40U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16RegFromInst__23__inst))
                             ? ((8U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16RegFromInst__23__inst))
                                 ? ((4U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16RegFromInst__23__inst))
                                     ? ((2U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16RegFromInst__23__inst))
                                         ? ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16RegFromInst__23__inst))
                                             ? 7U : 3U)
                                         : 7U) : 7U)
                                 : 7U) : ((8U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16RegFromInst__23__inst))
                                           ? ((4U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16RegFromInst__23__inst))
                                               ? ((2U 
                                                   & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16RegFromInst__23__inst))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16RegFromInst__23__inst))
                                                    ? 7U
                                                    : 1U)
                                                   : 
                                                  ((1U 
                                                    & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16RegFromInst__23__inst))
                                                    ? 7U
                                                    : 1U))
                                               : 7U)
                                           : ((4U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16RegFromInst__23__inst))
                                               ? 7U
                                               : ((2U 
                                                   & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16RegFromInst__23__inst))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16RegFromInst__23__inst))
                                                    ? 4U
                                                    : 7U)
                                                   : 7U))))
                         : 7U)) : ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16RegFromInst__23__Page3)
                                    ? ((0x80U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16RegFromInst__23__inst))
                                        ? ((0x40U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16RegFromInst__23__inst))
                                            ? 7U : 
                                           ((8U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16RegFromInst__23__inst))
                                             ? ((4U 
                                                 & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16RegFromInst__23__inst))
                                                 ? 
                                                ((2U 
                                                  & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16RegFromInst__23__inst))
                                                  ? 7U
                                                  : 
                                                 ((1U 
                                                   & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16RegFromInst__23__inst))
                                                   ? 7U
                                                   : 3U))
                                                 : 7U)
                                             : ((4U 
                                                 & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16RegFromInst__23__inst))
                                                 ? 7U
                                                 : 
                                                ((2U 
                                                  & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16RegFromInst__23__inst))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16RegFromInst__23__inst))
                                                   ? 2U
                                                   : 7U)
                                                  : 7U))))
                                        : 7U) : ((0x80U 
                                                  & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16RegFromInst__23__inst))
                                                  ? 
                                                 ((0x40U 
                                                   & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16RegFromInst__23__inst))
                                                   ? 
                                                  ((8U 
                                                    & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16RegFromInst__23__inst))
                                                    ? 
                                                   ((4U 
                                                     & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16RegFromInst__23__inst))
                                                     ? 
                                                    ((2U 
                                                      & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16RegFromInst__23__inst))
                                                      ? 
                                                     ((1U 
                                                       & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16RegFromInst__23__inst))
                                                       ? 7U
                                                       : 2U)
                                                      : 
                                                     ((1U 
                                                       & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16RegFromInst__23__inst))
                                                       ? 7U
                                                       : 4U))
                                                     : 7U)
                                                    : 
                                                   ((4U 
                                                     & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16RegFromInst__23__inst))
                                                     ? 7U
                                                     : 
                                                    ((2U 
                                                      & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16RegFromInst__23__inst))
                                                      ? 
                                                     ((1U 
                                                       & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16RegFromInst__23__inst))
                                                       ? 4U
                                                       : 7U)
                                                      : 7U)))
                                                   : 
                                                  ((8U 
                                                    & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16RegFromInst__23__inst))
                                                    ? 
                                                   ((4U 
                                                     & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16RegFromInst__23__inst))
                                                     ? 
                                                    ((2U 
                                                      & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16RegFromInst__23__inst))
                                                      ? 
                                                     ((1U 
                                                       & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16RegFromInst__23__inst))
                                                       ? 7U
                                                       : 0U)
                                                      : 
                                                     ((1U 
                                                       & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16RegFromInst__23__inst))
                                                       ? 7U
                                                       : 0U))
                                                     : 7U)
                                                    : 
                                                   ((4U 
                                                     & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16RegFromInst__23__inst))
                                                     ? 7U
                                                     : 
                                                    ((2U 
                                                      & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16RegFromInst__23__inst))
                                                      ? 
                                                     ((1U 
                                                       & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16RegFromInst__23__inst))
                                                       ? 4U
                                                       : 7U)
                                                      : 7U))))
                                                  : 
                                                 ((0x40U 
                                                   & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16RegFromInst__23__inst))
                                                   ? 7U
                                                   : 
                                                  ((0x20U 
                                                    & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16RegFromInst__23__inst))
                                                    ? 
                                                   ((0x10U 
                                                     & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16RegFromInst__23__inst))
                                                     ? 
                                                    ((8U 
                                                      & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16RegFromInst__23__inst))
                                                      ? 
                                                     ((4U 
                                                       & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16RegFromInst__23__inst))
                                                       ? 7U
                                                       : 
                                                      ((2U 
                                                        & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16RegFromInst__23__inst))
                                                        ? 
                                                       ((1U 
                                                         & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16RegFromInst__23__inst))
                                                         ? 7U
                                                         : 0U)
                                                        : 7U))
                                                      : 
                                                     ((4U 
                                                       & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16RegFromInst__23__inst))
                                                       ? 7U
                                                       : 
                                                      ((2U 
                                                        & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16RegFromInst__23__inst))
                                                        ? 
                                                       ((1U 
                                                         & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16RegFromInst__23__inst))
                                                         ? 2U
                                                         : 3U)
                                                        : 
                                                       ((1U 
                                                         & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16RegFromInst__23__inst))
                                                         ? 1U
                                                         : 0U))))
                                                     : 7U)
                                                    : 7U)))));
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16RegFromInst__23__Vfuncout 
        = __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16RegFromInst__23__srcreg;
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16Reg 
        = __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16RegFromInst__23__Vfuncout;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__inst 
        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__Page3 
        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__InstPage3;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__Page2 
        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__InstPage2;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__aluop = 7U;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__writeback = 1U;
    if (__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__Page2) {
        if (__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__Page3) {
            __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__aluop = 7U;
        } else if ((0x80U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__inst))) {
            if ((0x40U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__inst))) {
                __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__aluop 
                    = ((8U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__inst))
                        ? ((4U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__inst))
                            ? ((2U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__inst))
                                ? ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__inst))
                                    ? 7U : 2U) : 7U)
                            : 7U) : 7U);
            } else if ((8U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__inst))) {
                if ((4U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__inst))) {
                    if ((2U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__inst))) {
                        __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__aluop 
                            = ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__inst))
                                ? 7U : 2U);
                    } else if ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__inst))) {
                        __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__aluop = 7U;
                    } else {
                        __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__aluop = 3U;
                        __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__writeback = 0U;
                    }
                } else {
                    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__aluop = 7U;
                }
            } else if ((4U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__inst))) {
                __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__aluop = 7U;
            } else if ((2U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__inst))) {
                if ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__inst))) {
                    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__aluop = 3U;
                    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__writeback = 0U;
                } else {
                    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__aluop = 7U;
                }
            } else {
                __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__aluop = 7U;
            }
        } else {
            __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__aluop = 7U;
        }
    } else if (__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__Page3) {
        if ((0x80U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__inst))) {
            if ((0x40U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__inst))) {
                __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__aluop = 7U;
            } else if ((8U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__inst))) {
                if ((4U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__inst))) {
                    if ((2U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__inst))) {
                        __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__aluop = 7U;
                    } else if ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__inst))) {
                        __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__aluop = 7U;
                    } else {
                        __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__aluop = 3U;
                        __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__writeback = 0U;
                    }
                } else {
                    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__aluop = 7U;
                }
            } else if ((4U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__inst))) {
                __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__aluop = 7U;
            } else if ((2U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__inst))) {
                if ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__inst))) {
                    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__aluop = 3U;
                    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__writeback = 0U;
                } else {
                    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__aluop = 7U;
                }
            } else {
                __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__aluop = 7U;
            }
        } else {
            __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__aluop = 7U;
        }
    } else if ((0x80U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__inst))) {
        if ((0x40U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__inst))) {
            __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__aluop 
                = ((8U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__inst))
                    ? ((4U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__inst))
                        ? ((2U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__inst))
                            ? ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__inst))
                                ? 7U : 2U) : ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__inst))
                                               ? 7U
                                               : 2U))
                        : 7U) : ((4U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__inst))
                                  ? 7U : ((2U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__inst))
                                           ? ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__inst))
                                               ? 1U
                                               : 7U)
                                           : 7U)));
        } else if ((8U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__inst))) {
            if ((4U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__inst))) {
                if ((2U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__inst))) {
                    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__aluop 
                        = ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__inst))
                            ? 7U : 2U);
                } else if ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__inst))) {
                    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__aluop = 7U;
                } else {
                    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__aluop = 3U;
                    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__writeback = 0U;
                }
            } else {
                __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__aluop = 7U;
            }
        } else {
            __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__aluop 
                = ((4U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__inst))
                    ? 7U : ((2U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__inst))
                             ? ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__inst))
                                 ? 0U : 7U) : 7U));
        }
    } else {
        __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__aluop 
            = ((0x40U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__inst))
                ? 7U : ((0x20U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__inst))
                         ? ((0x10U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__inst))
                             ? ((8U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__inst))
                                 ? ((4U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__inst))
                                     ? 7U : ((2U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__inst))
                                              ? ((1U 
                                                  & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__inst))
                                                  ? 7U
                                                  : 1U)
                                              : 7U))
                                 : ((4U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__inst))
                                     ? 7U : 4U)) : 7U)
                         : 7U));
    }
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__Vfuncout 
        = (((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__writeback) 
            << 3U) | (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__aluop));
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpWriteback 
        = (1U & ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__24__Vfuncout) 
                 >> 3U));
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__inst 
        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__Page3 
        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__InstPage3;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__Page2 
        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__InstPage2;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__aluop = 7U;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__writeback = 1U;
    if (__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__Page2) {
        if (__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__Page3) {
            __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__aluop = 7U;
        } else if ((0x80U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__inst))) {
            if ((0x40U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__inst))) {
                __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__aluop 
                    = ((8U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__inst))
                        ? ((4U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__inst))
                            ? ((2U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__inst))
                                ? ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__inst))
                                    ? 7U : 2U) : 7U)
                            : 7U) : 7U);
            } else if ((8U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__inst))) {
                if ((4U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__inst))) {
                    if ((2U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__inst))) {
                        __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__aluop 
                            = ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__inst))
                                ? 7U : 2U);
                    } else if ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__inst))) {
                        __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__aluop = 7U;
                    } else {
                        __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__aluop = 3U;
                        __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__writeback = 0U;
                    }
                } else {
                    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__aluop = 7U;
                }
            } else if ((4U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__inst))) {
                __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__aluop = 7U;
            } else if ((2U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__inst))) {
                if ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__inst))) {
                    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__aluop = 3U;
                    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__writeback = 0U;
                } else {
                    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__aluop = 7U;
                }
            } else {
                __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__aluop = 7U;
            }
        } else {
            __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__aluop = 7U;
        }
    } else if (__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__Page3) {
        if ((0x80U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__inst))) {
            if ((0x40U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__inst))) {
                __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__aluop = 7U;
            } else if ((8U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__inst))) {
                if ((4U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__inst))) {
                    if ((2U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__inst))) {
                        __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__aluop = 7U;
                    } else if ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__inst))) {
                        __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__aluop = 7U;
                    } else {
                        __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__aluop = 3U;
                        __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__writeback = 0U;
                    }
                } else {
                    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__aluop = 7U;
                }
            } else if ((4U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__inst))) {
                __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__aluop = 7U;
            } else if ((2U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__inst))) {
                if ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__inst))) {
                    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__aluop = 3U;
                    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__writeback = 0U;
                } else {
                    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__aluop = 7U;
                }
            } else {
                __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__aluop = 7U;
            }
        } else {
            __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__aluop = 7U;
        }
    } else if ((0x80U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__inst))) {
        if ((0x40U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__inst))) {
            __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__aluop 
                = ((8U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__inst))
                    ? ((4U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__inst))
                        ? ((2U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__inst))
                            ? ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__inst))
                                ? 7U : 2U) : ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__inst))
                                               ? 7U
                                               : 2U))
                        : 7U) : ((4U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__inst))
                                  ? 7U : ((2U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__inst))
                                           ? ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__inst))
                                               ? 1U
                                               : 7U)
                                           : 7U)));
        } else if ((8U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__inst))) {
            if ((4U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__inst))) {
                if ((2U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__inst))) {
                    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__aluop 
                        = ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__inst))
                            ? 7U : 2U);
                } else if ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__inst))) {
                    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__aluop = 7U;
                } else {
                    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__aluop = 3U;
                    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__writeback = 0U;
                }
            } else {
                __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__aluop = 7U;
            }
        } else {
            __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__aluop 
                = ((4U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__inst))
                    ? 7U : ((2U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__inst))
                             ? ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__inst))
                                 ? 0U : 7U) : 7U));
        }
    } else {
        __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__aluop 
            = ((0x40U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__inst))
                ? 7U : ((0x20U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__inst))
                         ? ((0x10U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__inst))
                             ? ((8U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__inst))
                                 ? ((4U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__inst))
                                     ? 7U : ((2U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__inst))
                                              ? ((1U 
                                                  & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__inst))
                                                  ? 7U
                                                  : 1U)
                                              : 7U))
                                 : ((4U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__inst))
                                     ? 7U : 4U)) : 7U)
                         : 7U));
    }
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__Vfuncout 
        = (((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__writeback) 
            << 3U) | (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__aluop));
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__ALU16Opcode 
        = (7U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU16OpFromInst__25__Vfuncout));
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsSpecialImm__22__inst 
        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsSpecialImm__22__hi 
        = (0xfU & ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsSpecialImm__22__inst) 
                   >> 4U));
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsSpecialImm__22__lo 
        = (0xfU & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsSpecialImm__22__inst));
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsSpecialImm__22__is = 0U;
    if ((1U == (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsSpecialImm__22__hi))) {
        if (((((0xaU == (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsSpecialImm__22__lo)) 
               | (0xcU == (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsSpecialImm__22__lo))) 
              | (0xeU == (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsSpecialImm__22__lo))) 
             | (0xfU == (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsSpecialImm__22__lo)))) {
            __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsSpecialImm__22__is = 1U;
        }
    } else if ((3U == (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsSpecialImm__22__hi))) {
        if (((3U <= (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsSpecialImm__22__lo)) 
             & (7U >= (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsSpecialImm__22__lo)))) {
            __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsSpecialImm__22__is = 1U;
        }
    } else {
        __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsSpecialImm__22__is = 0U;
    }
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsSpecialImm__22__Vfuncout 
        = __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsSpecialImm__22__is;
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IsSpecialImmediate 
        = __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsSpecialImm__22__Vfuncout;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU8BitOp__31__instr 
        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set1__33__instr 
        = __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU8BitOp__31__instr;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set1__33__hi 
        = (0xfU & ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set1__33__instr) 
                   >> 4U));
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set1__33__lo 
        = (0xfU & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set1__33__instr));
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set1__33__result 
        = ((8U <= (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set1__33__hi)) 
           & (((0xbU >= (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set1__33__lo)) 
               & (3U != (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set1__33__lo))) 
              & (7U != (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set1__33__lo))));
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set1__33__Vfuncout 
        = __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set1__33__result;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set0__32__instr 
        = __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU8BitOp__31__instr;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set0__32__hi 
        = (0xfU & ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set0__32__instr) 
                   >> 4U));
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set0__32__lo 
        = (0xfU & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set0__32__instr));
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set0__32__result 
        = ((((((0U == (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set0__32__hi)) 
               | (4U == (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set0__32__hi))) 
              | (5U == (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set0__32__hi))) 
             | (6U == (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set0__32__hi))) 
            | (7U == (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set0__32__hi))) 
           & (((((1U != (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set0__32__lo)) 
                 & (2U != (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set0__32__lo))) 
                & (5U != (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set0__32__lo))) 
               & (0xbU != (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set0__32__lo))) 
              & (0xeU != (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set0__32__lo))));
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set0__32__Vfuncout 
        = __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set0__32__result;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU8BitOp__31__Vfuncout 
        = ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set0__32__Vfuncout) 
           | (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__IsALU8Set1__33__Vfuncout));
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Is8BitInst 
        = __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__ALU8BitOp__31__Vfuncout;
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rnRESET 
        = vlSelf->sim_top__DOT__soc__DOT__nreset_cpu;
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__NextState_nxt 
        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__NextState;
    if ((0x40U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
        if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState) 
                      >> 5U)))) {
            if ((0x10U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState) 
                                  >> 2U)))) {
                        if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState) 
                                      >> 1U)))) {
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState)))) {
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__NMIClear_nxt = 0U;
                            }
                        }
                    }
                } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__NMIClear_nxt = 1U;
                        }
                    }
                }
            }
        }
        if ((0x20U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState) 
                          >> 4U)))) {
                if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                    if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                        if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState) 
                                      >> 1U)))) {
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState)))) {
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__NextState_nxt = 0x6eU;
                            }
                        }
                    }
                }
            }
        } else if ((0x10U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
            if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__NextState_nxt = 0x5aU;
                        }
                    } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__NextState_nxt = 0x5aU;
                    }
                } else if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState) 
                                     >> 1U)))) {
                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__NextState_nxt = 0x5aU;
                    }
                }
            } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__NextState_nxt = 0x5aU;
                    }
                }
            }
        }
    } else if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState) 
                         >> 5U)))) {
        if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState) 
                      >> 4U)))) {
            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState) 
                          >> 3U)))) {
                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState) 
                              >> 2U)))) {
                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState) 
                                  >> 1U)))) {
                        if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState)))) {
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__NMIClear_nxt = 0U;
                        }
                    }
                }
            }
            if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState) 
                              >> 2U)))) {
                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState) 
                                  >> 1U)))) {
                        if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState)))) {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__AddrModeType) 
                                          >> 2U)))) {
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__AddrModeType) 
                                              >> 1U)))) {
                                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__AddrModeType))) {
                                        if (vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IsSpecialImmediate) {
                                            if ((0x1cU 
                                                 != (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1))) {
                                                if (
                                                    (0x1aU 
                                                     != (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1))) {
                                                    if (
                                                        ((0x34U 
                                                          == (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1)) 
                                                         | (0x36U 
                                                            == (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1)))) {
                                                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__NextState_nxt = 4U;
                                                    } else if (
                                                               ((0x35U 
                                                                 == (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1)) 
                                                                | (0x37U 
                                                                   == (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1)))) {
                                                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__NextState_nxt = 4U;
                                                    }
                                                }
                                            }
                                        }
                                    } else if ((0x12U 
                                                != (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1))) {
                                        if ((0x19U 
                                             != (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1))) {
                                            if ((0x13U 
                                                 != (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1))) {
                                                if (
                                                    (0x3dU 
                                                     != (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1))) {
                                                    if (
                                                        (0x39U 
                                                         != (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1))) {
                                                        if (
                                                            (0x3bU 
                                                             == (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst1))) {
                                                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__NextState_nxt = 4U;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

VL_INLINE_OPT void Vsim_top___024root___nba_sequent__TOP__6(Vsim_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___nba_sequent__TOP__6\n"); );
    // Init
    CData/*7:0*/ __Vfunc_sim_top__DOT__soc__DOT__msg__0__Vfuncout;
    __Vfunc_sim_top__DOT__soc__DOT__msg__0__Vfuncout = 0;
    CData/*3:0*/ __Vfunc_sim_top__DOT__soc__DOT__msg__0__i;
    __Vfunc_sim_top__DOT__soc__DOT__msg__0__i = 0;
    CData/*0:0*/ __Vfunc_sim_top__DOT__soc__DOT__msg__0__fail;
    __Vfunc_sim_top__DOT__soc__DOT__msg__0__fail = 0;
    IData/*21:0*/ __Vfunc_sim_top__DOT__soc__DOT__msg__0__fa;
    __Vfunc_sim_top__DOT__soc__DOT__msg__0__fa = 0;
    CData/*7:0*/ __Vfunc_sim_top__DOT__soc__DOT__msg__1__Vfuncout;
    __Vfunc_sim_top__DOT__soc__DOT__msg__1__Vfuncout = 0;
    CData/*3:0*/ __Vfunc_sim_top__DOT__soc__DOT__msg__1__i;
    __Vfunc_sim_top__DOT__soc__DOT__msg__1__i = 0;
    CData/*0:0*/ __Vfunc_sim_top__DOT__soc__DOT__msg__1__fail;
    __Vfunc_sim_top__DOT__soc__DOT__msg__1__fail = 0;
    IData/*21:0*/ __Vfunc_sim_top__DOT__soc__DOT__msg__1__fa;
    __Vfunc_sim_top__DOT__soc__DOT__msg__1__fa = 0;
    CData/*7:0*/ __Vfunc_sim_top__DOT__soc__DOT__hexc__2__Vfuncout;
    __Vfunc_sim_top__DOT__soc__DOT__hexc__2__Vfuncout = 0;
    CData/*3:0*/ __Vfunc_sim_top__DOT__soc__DOT__hexc__2__n;
    __Vfunc_sim_top__DOT__soc__DOT__hexc__2__n = 0;
    CData/*7:0*/ __Vfunc_sim_top__DOT__soc__DOT__hexc__3__Vfuncout;
    __Vfunc_sim_top__DOT__soc__DOT__hexc__3__Vfuncout = 0;
    CData/*3:0*/ __Vfunc_sim_top__DOT__soc__DOT__hexc__3__n;
    __Vfunc_sim_top__DOT__soc__DOT__hexc__3__n = 0;
    CData/*7:0*/ __Vfunc_sim_top__DOT__soc__DOT__hexc__4__Vfuncout;
    __Vfunc_sim_top__DOT__soc__DOT__hexc__4__Vfuncout = 0;
    CData/*3:0*/ __Vfunc_sim_top__DOT__soc__DOT__hexc__4__n;
    __Vfunc_sim_top__DOT__soc__DOT__hexc__4__n = 0;
    CData/*7:0*/ __Vfunc_sim_top__DOT__soc__DOT__hexc__5__Vfuncout;
    __Vfunc_sim_top__DOT__soc__DOT__hexc__5__Vfuncout = 0;
    CData/*3:0*/ __Vfunc_sim_top__DOT__soc__DOT__hexc__5__n;
    __Vfunc_sim_top__DOT__soc__DOT__hexc__5__n = 0;
    CData/*7:0*/ __Vfunc_sim_top__DOT__soc__DOT__hexc__6__Vfuncout;
    __Vfunc_sim_top__DOT__soc__DOT__hexc__6__Vfuncout = 0;
    CData/*3:0*/ __Vfunc_sim_top__DOT__soc__DOT__hexc__6__n;
    __Vfunc_sim_top__DOT__soc__DOT__hexc__6__n = 0;
    CData/*7:0*/ __Vfunc_sim_top__DOT__soc__DOT__hexc__7__Vfuncout;
    __Vfunc_sim_top__DOT__soc__DOT__hexc__7__Vfuncout = 0;
    CData/*3:0*/ __Vfunc_sim_top__DOT__soc__DOT__hexc__7__n;
    __Vfunc_sim_top__DOT__soc__DOT__hexc__7__n = 0;
    CData/*7:0*/ __Vfunc_sim_top__DOT__soc__DOT__hexc__8__Vfuncout;
    __Vfunc_sim_top__DOT__soc__DOT__hexc__8__Vfuncout = 0;
    CData/*3:0*/ __Vfunc_sim_top__DOT__soc__DOT__hexc__8__n;
    __Vfunc_sim_top__DOT__soc__DOT__hexc__8__n = 0;
    CData/*7:0*/ __Vfunc_sim_top__DOT__soc__DOT__hexc__9__Vfuncout;
    __Vfunc_sim_top__DOT__soc__DOT__hexc__9__Vfuncout = 0;
    CData/*3:0*/ __Vfunc_sim_top__DOT__soc__DOT__hexc__9__n;
    __Vfunc_sim_top__DOT__soc__DOT__hexc__9__n = 0;
    CData/*7:0*/ __Vfunc_sim_top__DOT__soc__DOT__hexc__10__Vfuncout;
    __Vfunc_sim_top__DOT__soc__DOT__hexc__10__Vfuncout = 0;
    CData/*3:0*/ __Vfunc_sim_top__DOT__soc__DOT__hexc__10__n;
    __Vfunc_sim_top__DOT__soc__DOT__hexc__10__n = 0;
    CData/*7:0*/ __Vfunc_sim_top__DOT__soc__DOT__hexc__11__Vfuncout;
    __Vfunc_sim_top__DOT__soc__DOT__hexc__11__Vfuncout = 0;
    CData/*3:0*/ __Vfunc_sim_top__DOT__soc__DOT__hexc__11__n;
    __Vfunc_sim_top__DOT__soc__DOT__hexc__11__n = 0;
    CData/*7:0*/ __Vfunc_sim_top__DOT__soc__DOT__hexc__12__Vfuncout;
    __Vfunc_sim_top__DOT__soc__DOT__hexc__12__Vfuncout = 0;
    CData/*3:0*/ __Vfunc_sim_top__DOT__soc__DOT__hexc__12__n;
    __Vfunc_sim_top__DOT__soc__DOT__hexc__12__n = 0;
    CData/*7:0*/ __Vfunc_sim_top__DOT__soc__DOT__hexc__13__Vfuncout;
    __Vfunc_sim_top__DOT__soc__DOT__hexc__13__Vfuncout = 0;
    CData/*3:0*/ __Vfunc_sim_top__DOT__soc__DOT__hexc__13__n;
    __Vfunc_sim_top__DOT__soc__DOT__hexc__13__n = 0;
    CData/*7:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__MapInstruction__14__Vfuncout;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__MapInstruction__14__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__MapInstruction__14__i;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__MapInstruction__14__i = 0;
    CData/*3:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__MapInstruction__14__topnyb;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__MapInstruction__14__topnyb = 0;
    CData/*3:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__MapInstruction__14__btmnyb;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__MapInstruction__14__btmnyb = 0;
    CData/*7:0*/ __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__MapInstruction__14__newinst;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__MapInstruction__14__newinst = 0;
    CData/*0:0*/ __Vdly__sim_top__DOT__soc__DOT__acc_go;
    __Vdly__sim_top__DOT__soc__DOT__acc_go = 0;
    CData/*0:0*/ __Vdly__sim_top__DOT__soc__DOT__c_wr;
    __Vdly__sim_top__DOT__soc__DOT__c_wr = 0;
    CData/*0:0*/ __Vdly__sim_top__DOT__soc__DOT__t_rd;
    __Vdly__sim_top__DOT__soc__DOT__t_rd = 0;
    CData/*0:0*/ __Vdly__sim_top__DOT__soc__DOT__ld_start;
    __Vdly__sim_top__DOT__soc__DOT__ld_start = 0;
    CData/*0:0*/ __Vdly__sim_top__DOT__soc__DOT__st_wr;
    __Vdly__sim_top__DOT__soc__DOT__st_wr = 0;
    CData/*0:0*/ __Vdly__sim_top__DOT__soc__DOT__st_d;
    __Vdly__sim_top__DOT__soc__DOT__st_d = 0;
    CData/*0:0*/ __Vdly__sim_top__DOT__soc__DOT__st_d2;
    __Vdly__sim_top__DOT__soc__DOT__st_d2 = 0;
    CData/*2:0*/ __Vdlyvdim0__sim_top__DOT__soc__DOT__map_u__v16;
    __Vdlyvdim0__sim_top__DOT__soc__DOT__map_u__v16 = 0;
    CData/*7:0*/ __Vdlyvval__sim_top__DOT__soc__DOT__map_u__v16;
    __Vdlyvval__sim_top__DOT__soc__DOT__map_u__v16 = 0;
    CData/*2:0*/ __Vdlyvdim0__sim_top__DOT__soc__DOT__map_s__v26;
    __Vdlyvdim0__sim_top__DOT__soc__DOT__map_s__v26 = 0;
    CData/*7:0*/ __Vdlyvval__sim_top__DOT__soc__DOT__map_s__v26;
    __Vdlyvval__sim_top__DOT__soc__DOT__map_s__v26 = 0;
    CData/*0:0*/ __Vdly__sim_top__DOT__soc__DOT__loader__DOT__sgo;
    __Vdly__sim_top__DOT__soc__DOT__loader__DOT__sgo = 0;
    CData/*0:0*/ __Vdly__sim_top__DOT__soc__DOT__m0_ack;
    __Vdly__sim_top__DOT__soc__DOT__m0_ack = 0;
    CData/*0:0*/ __Vdly__sim_top__DOT__soc__DOT__zm_ack;
    __Vdly__sim_top__DOT__soc__DOT__zm_ack = 0;
    // Body
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT____VdfgTmp_h1ff8cf4e__0 
        = ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__c_ien) 
           & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__pend_s2m));
    __Vdly__sim_top__DOT__soc__DOT__c_wr = 0U;
    __Vdly__sim_top__DOT__soc__DOT__t_rd = 0U;
    __Vdly__sim_top__DOT__soc__DOT__ld_start = 0U;
    __Vdly__sim_top__DOT__soc__DOT__st_wr = 0U;
    __Vdly__sim_top__DOT__soc__DOT__st_d = vlSelf->sim_top__DOT__soc__DOT__st_wr;
    __Vdly__sim_top__DOT__soc__DOT__st_d2 = vlSelf->sim_top__DOT__soc__DOT__st_d;
    if ((((((IData)(vlSelf->sim_top__DOT__soc__DOT__p_go) 
            & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__st_wr))) 
           & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__st_d))) 
          & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__st_d2))) 
         & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__acia__DOT__tfull)))) {
        __Vdly__sim_top__DOT__soc__DOT__st_wr = 1U;
        vlSelf->sim_top__DOT__soc__DOT__st_byte = vlSelf->sim_top__DOT__soc__DOT__p_ch;
        vlSelf->__Vdly__sim_top__DOT__soc__DOT__p_go = 0U;
    }
    if (vlSelf->sim_top__DOT__soc__DOT__xl_we) {
        if ((1U & (~ (1U & (((IData)(vlSelf->sim_top__DOT__soc__DOT__off) 
                             - (IData)(1U)) >> 2U))))) {
            if ((1U & (~ (3U & (((IData)(vlSelf->sim_top__DOT__soc__DOT__off) 
                                 - (IData)(1U)) >> 1U))))) {
                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__off) 
                              - (IData)(1U))))) {
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__c_firq 
                        = (1U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DOutput) 
                                 >> 3U));
                }
            }
        }
    }
    if (vlSelf->sim_top__DOT__soc__DOT__rst) {
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__c_firq = 0U;
        vlSelf->sim_top__DOT__soc__DOT__timer__DOT__pending = 0U;
        vlSelf->sim_top__DOT__soc__DOT__timer__DOT__r0 = 0U;
        vlSelf->__Vdly__sim_top__DOT__soc__DOT__timer__DOT__tcnt = 0U;
        vlSelf->sim_top__DOT__soc__DOT__timer__DOT__tcnt 
            = vlSelf->__Vdly__sim_top__DOT__soc__DOT__timer__DOT__tcnt;
        vlSelf->__Vdly__sim_top__DOT__soc__DOT__cs_ = 0U;
        vlSelf->__Vdly__sim_top__DOT__soc__DOT__cw = 0U;
        vlSelf->__Vdly__sim_top__DOT__soc__DOT__bsy_d = 0U;
        vlSelf->__Vdly__sim_top__DOT__soc__DOT__rcnt = 0U;
        vlSelf->sim_top__DOT__soc__DOT__nreset_cpu = 0U;
        vlSelf->__Vdly__sim_top__DOT__soc__DOT__tp = 3U;
        vlSelf->__Vdly__sim_top__DOT__soc__DOT__t_fail = 0U;
        vlSelf->__Vdly__sim_top__DOT__soc__DOT__t_faddr = 0U;
        vlSelf->__Vdly__sim_top__DOT__soc__DOT__mi = 0U;
        vlSelf->__Vdly__sim_top__DOT__soc__DOT__p_go = 0U;
        vlSelf->sim_top__DOT__soc__DOT__p_ch = 0U;
    } else {
        if (((IData)(vlSelf->sim_top__DOT__soc__DOT__acc2) 
             & ((~ (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__BA_nxt)) 
                & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__BS_nxt)))) {
            vlSelf->sim_top__DOT__soc__DOT__timer__DOT__pending = 0U;
        }
        if (((IData)(vlSelf->sim_top__DOT__soc__DOT__timer__DOT__running) 
             & (IData)(vlSelf->sim_top__DOT__soc__DOT__ecyc))) {
            if ((0x927bU == (IData)(vlSelf->sim_top__DOT__soc__DOT__timer__DOT__tcnt))) {
                vlSelf->__Vdly__sim_top__DOT__soc__DOT__timer__DOT__tcnt = 0U;
                vlSelf->sim_top__DOT__soc__DOT__timer__DOT__pending = 1U;
                vlSelf->sim_top__DOT__soc__DOT__timer__DOT__r0 
                    = (0x10U | (IData)(vlSelf->sim_top__DOT__soc__DOT__timer__DOT__r0));
            } else {
                vlSelf->__Vdly__sim_top__DOT__soc__DOT__timer__DOT__tcnt 
                    = (0xffffU & ((IData)(1U) + (IData)(vlSelf->sim_top__DOT__soc__DOT__timer__DOT__tcnt)));
            }
        }
        if (vlSelf->sim_top__DOT__soc__DOT__timer_wr) {
            if ((0U == (7U & (IData)(vlSelf->sim_top__DOT__soc__DOT__off)))) {
                if ((0x8fU == (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DOutput))) {
                    vlSelf->__Vdly__sim_top__DOT__soc__DOT__timer__DOT__tcnt = 0U;
                    vlSelf->sim_top__DOT__soc__DOT__timer__DOT__pending = 0U;
                    vlSelf->sim_top__DOT__soc__DOT__timer__DOT__r0 
                        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DOutput;
                } else if ((0x80U == (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DOutput))) {
                    vlSelf->sim_top__DOT__soc__DOT__timer__DOT__pending = 0U;
                    vlSelf->sim_top__DOT__soc__DOT__timer__DOT__r0 
                        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DOutput;
                } else if ((4U != (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DOutput))) {
                    vlSelf->sim_top__DOT__soc__DOT__timer__DOT__r0 
                        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DOutput;
                }
            }
        }
        vlSelf->sim_top__DOT__soc__DOT__timer__DOT__tcnt 
            = vlSelf->__Vdly__sim_top__DOT__soc__DOT__timer__DOT__tcnt;
        vlSelf->__Vdly__sim_top__DOT__soc__DOT__bsy_d 
            = ((0xeU & ((IData)(vlSelf->sim_top__DOT__soc__DOT__bsy_d) 
                        << 1U)) | (IData)(vlSelf->sim_top__DOT__soc__DOT__m0_req));
        if (vlSelf->sim_top__DOT__soc__DOT__go_req) {
            vlSelf->sim_top__DOT__soc__DOT__nreset_cpu = 0U;
            vlSelf->__Vdly__sim_top__DOT__soc__DOT__rcnt = 0U;
        }
        if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cs_))) {
            if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cs_))) {
                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cs_))) {
                    vlSelf->__Vdly__sim_top__DOT__soc__DOT__cs_ = 0U;
                } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cs_))) {
                    vlSelf->__Vdly__sim_top__DOT__soc__DOT__cs_ = 0U;
                } else if ((1U & (((~ (IData)(vlSelf->sim_top__DOT__soc__DOT__p_go)) 
                                   & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__st_wr))) 
                                  & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__st_d))))) {
                    __Vfunc_sim_top__DOT__soc__DOT__msg__0__fa 
                        = vlSelf->sim_top__DOT__soc__DOT__t_faddr;
                    __Vfunc_sim_top__DOT__soc__DOT__msg__0__fail 
                        = vlSelf->sim_top__DOT__soc__DOT__t_fail;
                    __Vfunc_sim_top__DOT__soc__DOT__msg__0__i 
                        = vlSelf->sim_top__DOT__soc__DOT__mi;
                    if (__Vfunc_sim_top__DOT__soc__DOT__msg__0__fail) {
                        if ((8U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__msg__0__i))) {
                            if ((4U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__msg__0__i))) {
                                __Vfunc_sim_top__DOT__soc__DOT__msg__0__Vfuncout = 0U;
                            } else if ((2U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__msg__0__i))) {
                                __Vfunc_sim_top__DOT__soc__DOT__msg__0__Vfuncout 
                                    = ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__msg__0__i))
                                        ? 0xaU : 0xdU);
                            } else if ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__msg__0__i))) {
                                __Vfunc_sim_top__DOT__soc__DOT__hexc__8__n 
                                    = (0xfU & __Vfunc_sim_top__DOT__soc__DOT__msg__0__fa);
                                __Vfunc_sim_top__DOT__soc__DOT__hexc__8__Vfuncout 
                                    = (0xffU & ((0xaU 
                                                 > (IData)(__Vfunc_sim_top__DOT__soc__DOT__hexc__8__n))
                                                 ? 
                                                ((IData)(0x30U) 
                                                 + (IData)(__Vfunc_sim_top__DOT__soc__DOT__hexc__8__n))
                                                 : 
                                                ((IData)(0x37U) 
                                                 + (IData)(__Vfunc_sim_top__DOT__soc__DOT__hexc__8__n))));
                                __Vfunc_sim_top__DOT__soc__DOT__msg__0__Vfuncout 
                                    = __Vfunc_sim_top__DOT__soc__DOT__hexc__8__Vfuncout;
                            } else {
                                __Vfunc_sim_top__DOT__soc__DOT__hexc__9__n 
                                    = (0xfU & (__Vfunc_sim_top__DOT__soc__DOT__msg__0__fa 
                                               >> 4U));
                                __Vfunc_sim_top__DOT__soc__DOT__hexc__9__Vfuncout 
                                    = (0xffU & ((0xaU 
                                                 > (IData)(__Vfunc_sim_top__DOT__soc__DOT__hexc__9__n))
                                                 ? 
                                                ((IData)(0x30U) 
                                                 + (IData)(__Vfunc_sim_top__DOT__soc__DOT__hexc__9__n))
                                                 : 
                                                ((IData)(0x37U) 
                                                 + (IData)(__Vfunc_sim_top__DOT__soc__DOT__hexc__9__n))));
                                __Vfunc_sim_top__DOT__soc__DOT__msg__0__Vfuncout 
                                    = __Vfunc_sim_top__DOT__soc__DOT__hexc__9__Vfuncout;
                            }
                        } else if ((4U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__msg__0__i))) {
                            if ((2U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__msg__0__i))) {
                                if ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__msg__0__i))) {
                                    __Vfunc_sim_top__DOT__soc__DOT__hexc__10__n 
                                        = (0xfU & (__Vfunc_sim_top__DOT__soc__DOT__msg__0__fa 
                                                   >> 8U));
                                    __Vfunc_sim_top__DOT__soc__DOT__hexc__10__Vfuncout 
                                        = (0xffU & 
                                           ((0xaU > (IData)(__Vfunc_sim_top__DOT__soc__DOT__hexc__10__n))
                                             ? ((IData)(0x30U) 
                                                + (IData)(__Vfunc_sim_top__DOT__soc__DOT__hexc__10__n))
                                             : ((IData)(0x37U) 
                                                + (IData)(__Vfunc_sim_top__DOT__soc__DOT__hexc__10__n))));
                                    __Vfunc_sim_top__DOT__soc__DOT__msg__0__Vfuncout 
                                        = __Vfunc_sim_top__DOT__soc__DOT__hexc__10__Vfuncout;
                                } else {
                                    __Vfunc_sim_top__DOT__soc__DOT__hexc__11__n 
                                        = (0xfU & (__Vfunc_sim_top__DOT__soc__DOT__msg__0__fa 
                                                   >> 0xcU));
                                    __Vfunc_sim_top__DOT__soc__DOT__hexc__11__Vfuncout 
                                        = (0xffU & 
                                           ((0xaU > (IData)(__Vfunc_sim_top__DOT__soc__DOT__hexc__11__n))
                                             ? ((IData)(0x30U) 
                                                + (IData)(__Vfunc_sim_top__DOT__soc__DOT__hexc__11__n))
                                             : ((IData)(0x37U) 
                                                + (IData)(__Vfunc_sim_top__DOT__soc__DOT__hexc__11__n))));
                                    __Vfunc_sim_top__DOT__soc__DOT__msg__0__Vfuncout 
                                        = __Vfunc_sim_top__DOT__soc__DOT__hexc__11__Vfuncout;
                                }
                            } else if ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__msg__0__i))) {
                                __Vfunc_sim_top__DOT__soc__DOT__hexc__12__n 
                                    = (0xfU & (__Vfunc_sim_top__DOT__soc__DOT__msg__0__fa 
                                               >> 0x10U));
                                __Vfunc_sim_top__DOT__soc__DOT__hexc__12__Vfuncout 
                                    = (0xffU & ((0xaU 
                                                 > (IData)(__Vfunc_sim_top__DOT__soc__DOT__hexc__12__n))
                                                 ? 
                                                ((IData)(0x30U) 
                                                 + (IData)(__Vfunc_sim_top__DOT__soc__DOT__hexc__12__n))
                                                 : 
                                                ((IData)(0x37U) 
                                                 + (IData)(__Vfunc_sim_top__DOT__soc__DOT__hexc__12__n))));
                                __Vfunc_sim_top__DOT__soc__DOT__msg__0__Vfuncout 
                                    = __Vfunc_sim_top__DOT__soc__DOT__hexc__12__Vfuncout;
                            } else {
                                __Vfunc_sim_top__DOT__soc__DOT__hexc__13__n 
                                    = (3U & (__Vfunc_sim_top__DOT__soc__DOT__msg__0__fa 
                                             >> 0x14U));
                                __Vfunc_sim_top__DOT__soc__DOT__hexc__13__Vfuncout 
                                    = (0xffU & ((0xaU 
                                                 > (IData)(__Vfunc_sim_top__DOT__soc__DOT__hexc__13__n))
                                                 ? 
                                                ((IData)(0x30U) 
                                                 + (IData)(__Vfunc_sim_top__DOT__soc__DOT__hexc__13__n))
                                                 : 
                                                ((IData)(0x37U) 
                                                 + (IData)(__Vfunc_sim_top__DOT__soc__DOT__hexc__13__n))));
                                __Vfunc_sim_top__DOT__soc__DOT__msg__0__Vfuncout 
                                    = __Vfunc_sim_top__DOT__soc__DOT__hexc__13__Vfuncout;
                            }
                        } else {
                            __Vfunc_sim_top__DOT__soc__DOT__msg__0__Vfuncout 
                                = ((2U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__msg__0__i))
                                    ? ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__msg__0__i))
                                        ? 0x40U : 0x47U)
                                    : ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__msg__0__i))
                                        ? 0x4eU : 0x20U));
                        }
                    } else {
                        __Vfunc_sim_top__DOT__soc__DOT__msg__0__Vfuncout 
                            = ((8U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__msg__0__i))
                                ? ((4U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__msg__0__i))
                                    ? 0U : ((2U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__msg__0__i))
                                             ? ((1U 
                                                 & (IData)(__Vfunc_sim_top__DOT__soc__DOT__msg__0__i))
                                                 ? 0U
                                                 : 0xaU)
                                             : ((1U 
                                                 & (IData)(__Vfunc_sim_top__DOT__soc__DOT__msg__0__i))
                                                 ? 0xdU
                                                 : 0x4bU)))
                                : ((4U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__msg__0__i))
                                    ? ((2U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__msg__0__i))
                                        ? ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__msg__0__i))
                                            ? 0x38U
                                            : 0x34U)
                                        : ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__msg__0__i))
                                            ? 0x30U
                                            : 0x32U))
                                    : ((2U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__msg__0__i))
                                        ? ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__msg__0__i))
                                            ? 0x20U
                                            : 0x4bU)
                                        : ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__msg__0__i))
                                            ? 0x4fU
                                            : 0x20U))));
                    }
                    if ((0U == (IData)(__Vfunc_sim_top__DOT__soc__DOT__msg__0__Vfuncout))) {
                        vlSelf->__Vdly__sim_top__DOT__soc__DOT__cs_ = 1U;
                    } else {
                        __Vfunc_sim_top__DOT__soc__DOT__msg__1__fa 
                            = vlSelf->sim_top__DOT__soc__DOT__t_faddr;
                        __Vfunc_sim_top__DOT__soc__DOT__msg__1__fail 
                            = vlSelf->sim_top__DOT__soc__DOT__t_fail;
                        __Vfunc_sim_top__DOT__soc__DOT__msg__1__i 
                            = vlSelf->sim_top__DOT__soc__DOT__mi;
                        vlSelf->__Vdly__sim_top__DOT__soc__DOT__p_go = 1U;
                        if (__Vfunc_sim_top__DOT__soc__DOT__msg__1__fail) {
                            if ((8U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__msg__1__i))) {
                                if ((4U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__msg__1__i))) {
                                    __Vfunc_sim_top__DOT__soc__DOT__msg__1__Vfuncout = 0U;
                                } else if ((2U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__msg__1__i))) {
                                    __Vfunc_sim_top__DOT__soc__DOT__msg__1__Vfuncout 
                                        = ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__msg__1__i))
                                            ? 0xaU : 0xdU);
                                } else if ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__msg__1__i))) {
                                    __Vfunc_sim_top__DOT__soc__DOT__hexc__2__n 
                                        = (0xfU & __Vfunc_sim_top__DOT__soc__DOT__msg__1__fa);
                                    __Vfunc_sim_top__DOT__soc__DOT__hexc__2__Vfuncout 
                                        = (0xffU & 
                                           ((0xaU > (IData)(__Vfunc_sim_top__DOT__soc__DOT__hexc__2__n))
                                             ? ((IData)(0x30U) 
                                                + (IData)(__Vfunc_sim_top__DOT__soc__DOT__hexc__2__n))
                                             : ((IData)(0x37U) 
                                                + (IData)(__Vfunc_sim_top__DOT__soc__DOT__hexc__2__n))));
                                    __Vfunc_sim_top__DOT__soc__DOT__msg__1__Vfuncout 
                                        = __Vfunc_sim_top__DOT__soc__DOT__hexc__2__Vfuncout;
                                } else {
                                    __Vfunc_sim_top__DOT__soc__DOT__hexc__3__n 
                                        = (0xfU & (__Vfunc_sim_top__DOT__soc__DOT__msg__1__fa 
                                                   >> 4U));
                                    __Vfunc_sim_top__DOT__soc__DOT__hexc__3__Vfuncout 
                                        = (0xffU & 
                                           ((0xaU > (IData)(__Vfunc_sim_top__DOT__soc__DOT__hexc__3__n))
                                             ? ((IData)(0x30U) 
                                                + (IData)(__Vfunc_sim_top__DOT__soc__DOT__hexc__3__n))
                                             : ((IData)(0x37U) 
                                                + (IData)(__Vfunc_sim_top__DOT__soc__DOT__hexc__3__n))));
                                    __Vfunc_sim_top__DOT__soc__DOT__msg__1__Vfuncout 
                                        = __Vfunc_sim_top__DOT__soc__DOT__hexc__3__Vfuncout;
                                }
                            } else if ((4U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__msg__1__i))) {
                                if ((2U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__msg__1__i))) {
                                    if ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__msg__1__i))) {
                                        __Vfunc_sim_top__DOT__soc__DOT__hexc__4__n 
                                            = (0xfU 
                                               & (__Vfunc_sim_top__DOT__soc__DOT__msg__1__fa 
                                                  >> 8U));
                                        __Vfunc_sim_top__DOT__soc__DOT__hexc__4__Vfuncout 
                                            = (0xffU 
                                               & ((0xaU 
                                                   > (IData)(__Vfunc_sim_top__DOT__soc__DOT__hexc__4__n))
                                                   ? 
                                                  ((IData)(0x30U) 
                                                   + (IData)(__Vfunc_sim_top__DOT__soc__DOT__hexc__4__n))
                                                   : 
                                                  ((IData)(0x37U) 
                                                   + (IData)(__Vfunc_sim_top__DOT__soc__DOT__hexc__4__n))));
                                        __Vfunc_sim_top__DOT__soc__DOT__msg__1__Vfuncout 
                                            = __Vfunc_sim_top__DOT__soc__DOT__hexc__4__Vfuncout;
                                    } else {
                                        __Vfunc_sim_top__DOT__soc__DOT__hexc__5__n 
                                            = (0xfU 
                                               & (__Vfunc_sim_top__DOT__soc__DOT__msg__1__fa 
                                                  >> 0xcU));
                                        __Vfunc_sim_top__DOT__soc__DOT__hexc__5__Vfuncout 
                                            = (0xffU 
                                               & ((0xaU 
                                                   > (IData)(__Vfunc_sim_top__DOT__soc__DOT__hexc__5__n))
                                                   ? 
                                                  ((IData)(0x30U) 
                                                   + (IData)(__Vfunc_sim_top__DOT__soc__DOT__hexc__5__n))
                                                   : 
                                                  ((IData)(0x37U) 
                                                   + (IData)(__Vfunc_sim_top__DOT__soc__DOT__hexc__5__n))));
                                        __Vfunc_sim_top__DOT__soc__DOT__msg__1__Vfuncout 
                                            = __Vfunc_sim_top__DOT__soc__DOT__hexc__5__Vfuncout;
                                    }
                                } else if ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__msg__1__i))) {
                                    __Vfunc_sim_top__DOT__soc__DOT__hexc__6__n 
                                        = (0xfU & (__Vfunc_sim_top__DOT__soc__DOT__msg__1__fa 
                                                   >> 0x10U));
                                    __Vfunc_sim_top__DOT__soc__DOT__hexc__6__Vfuncout 
                                        = (0xffU & 
                                           ((0xaU > (IData)(__Vfunc_sim_top__DOT__soc__DOT__hexc__6__n))
                                             ? ((IData)(0x30U) 
                                                + (IData)(__Vfunc_sim_top__DOT__soc__DOT__hexc__6__n))
                                             : ((IData)(0x37U) 
                                                + (IData)(__Vfunc_sim_top__DOT__soc__DOT__hexc__6__n))));
                                    __Vfunc_sim_top__DOT__soc__DOT__msg__1__Vfuncout 
                                        = __Vfunc_sim_top__DOT__soc__DOT__hexc__6__Vfuncout;
                                } else {
                                    __Vfunc_sim_top__DOT__soc__DOT__hexc__7__n 
                                        = (3U & (__Vfunc_sim_top__DOT__soc__DOT__msg__1__fa 
                                                 >> 0x14U));
                                    __Vfunc_sim_top__DOT__soc__DOT__hexc__7__Vfuncout 
                                        = (0xffU & 
                                           ((0xaU > (IData)(__Vfunc_sim_top__DOT__soc__DOT__hexc__7__n))
                                             ? ((IData)(0x30U) 
                                                + (IData)(__Vfunc_sim_top__DOT__soc__DOT__hexc__7__n))
                                             : ((IData)(0x37U) 
                                                + (IData)(__Vfunc_sim_top__DOT__soc__DOT__hexc__7__n))));
                                    __Vfunc_sim_top__DOT__soc__DOT__msg__1__Vfuncout 
                                        = __Vfunc_sim_top__DOT__soc__DOT__hexc__7__Vfuncout;
                                }
                            } else {
                                __Vfunc_sim_top__DOT__soc__DOT__msg__1__Vfuncout 
                                    = ((2U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__msg__1__i))
                                        ? ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__msg__1__i))
                                            ? 0x40U
                                            : 0x47U)
                                        : ((1U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__msg__1__i))
                                            ? 0x4eU
                                            : 0x20U));
                            }
                        } else {
                            __Vfunc_sim_top__DOT__soc__DOT__msg__1__Vfuncout 
                                = ((8U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__msg__1__i))
                                    ? ((4U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__msg__1__i))
                                        ? 0U : ((2U 
                                                 & (IData)(__Vfunc_sim_top__DOT__soc__DOT__msg__1__i))
                                                 ? 
                                                ((1U 
                                                  & (IData)(__Vfunc_sim_top__DOT__soc__DOT__msg__1__i))
                                                  ? 0U
                                                  : 0xaU)
                                                 : 
                                                ((1U 
                                                  & (IData)(__Vfunc_sim_top__DOT__soc__DOT__msg__1__i))
                                                  ? 0xdU
                                                  : 0x4bU)))
                                    : ((4U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__msg__1__i))
                                        ? ((2U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__msg__1__i))
                                            ? ((1U 
                                                & (IData)(__Vfunc_sim_top__DOT__soc__DOT__msg__1__i))
                                                ? 0x38U
                                                : 0x34U)
                                            : ((1U 
                                                & (IData)(__Vfunc_sim_top__DOT__soc__DOT__msg__1__i))
                                                ? 0x30U
                                                : 0x32U))
                                        : ((2U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__msg__1__i))
                                            ? ((1U 
                                                & (IData)(__Vfunc_sim_top__DOT__soc__DOT__msg__1__i))
                                                ? 0x20U
                                                : 0x4bU)
                                            : ((1U 
                                                & (IData)(__Vfunc_sim_top__DOT__soc__DOT__msg__1__i))
                                                ? 0x4fU
                                                : 0x20U))));
                        }
                        vlSelf->sim_top__DOT__soc__DOT__p_ch 
                            = __Vfunc_sim_top__DOT__soc__DOT__msg__1__Vfuncout;
                        vlSelf->__Vdly__sim_top__DOT__soc__DOT__mi 
                            = (0xfU & ((IData)(1U) 
                                       + (IData)(vlSelf->sim_top__DOT__soc__DOT__mi)));
                    }
                }
            } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cs_))) {
                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cs_))) {
                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__p_go)))) {
                        if ((((IData)(vlSelf->sim_top__DOT__soc__DOT__t_got_r) 
                              != (IData)(vlSelf->sim_top__DOT__soc__DOT__td_r)) 
                             & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__t_fail)))) {
                            vlSelf->__Vdly__sim_top__DOT__soc__DOT__t_fail = 1U;
                            vlSelf->__Vdly__sim_top__DOT__soc__DOT__t_faddr 
                                = vlSelf->sim_top__DOT__soc__DOT__cw;
                        }
                        if (((IData)(vlSelf->sim_top__DOT__soc__DOT__cw_pg) 
                             | (IData)(vlSelf->sim_top__DOT__soc__DOT__cw_last))) {
                            vlSelf->sim_top__DOT__soc__DOT__p_ch = 0x3eU;
                            vlSelf->__Vdly__sim_top__DOT__soc__DOT__p_go = 1U;
                        }
                        if (vlSelf->sim_top__DOT__soc__DOT__cw_last) {
                            vlSelf->__Vdly__sim_top__DOT__soc__DOT__tp 
                                = (3U & ((IData)(1U) 
                                         + (IData)(vlSelf->sim_top__DOT__soc__DOT__tp)));
                            vlSelf->__Vdly__sim_top__DOT__soc__DOT__cw = 0U;
                            vlSelf->__Vdly__sim_top__DOT__soc__DOT__cs_ 
                                = ((2U == (IData)(vlSelf->sim_top__DOT__soc__DOT__tp))
                                    ? 0xcU : 7U);
                        } else {
                            vlSelf->__Vdly__sim_top__DOT__soc__DOT__cw 
                                = vlSelf->sim_top__DOT__soc__DOT__cw_n;
                            vlSelf->__Vdly__sim_top__DOT__soc__DOT__cs_ = 9U;
                        }
                    }
                } else if ((((~ (IData)(vlSelf->sim_top__DOT__soc__DOT__t_rd)) 
                             & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__m0_req))) 
                            & (0U == (3U & (IData)(vlSelf->sim_top__DOT__soc__DOT__bsy_d))))) {
                    vlSelf->__Vdly__sim_top__DOT__soc__DOT__cs_ = 0xbU;
                }
            } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cs_))) {
                __Vdly__sim_top__DOT__soc__DOT__t_rd = 1U;
                vlSelf->__Vdly__sim_top__DOT__soc__DOT__cs_ = 0xaU;
            } else if ((((~ (IData)(vlSelf->sim_top__DOT__soc__DOT__c_wr)) 
                         & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__m0_req))) 
                        & (0U == (3U & (IData)(vlSelf->sim_top__DOT__soc__DOT__bsy_d))))) {
                if (vlSelf->sim_top__DOT__soc__DOT__cw_last) {
                    vlSelf->__Vdly__sim_top__DOT__soc__DOT__cw = 0U;
                    vlSelf->__Vdly__sim_top__DOT__soc__DOT__cs_ = 9U;
                } else {
                    vlSelf->__Vdly__sim_top__DOT__soc__DOT__cw 
                        = vlSelf->sim_top__DOT__soc__DOT__cw_n;
                    vlSelf->__Vdly__sim_top__DOT__soc__DOT__cs_ = 7U;
                }
            }
        } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cs_))) {
            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cs_))) {
                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cs_))) {
                    __Vdly__sim_top__DOT__soc__DOT__c_wr = 1U;
                    vlSelf->__Vdly__sim_top__DOT__soc__DOT__cs_ = 8U;
                } else if ((1U & (((~ (IData)(vlSelf->sim_top__DOT__soc__DOT__p_go)) 
                                   & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__st_wr))) 
                                  & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__st_d))))) {
                    vlSelf->sim_top__DOT__soc__DOT__p_ch 
                        = ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__mi))
                            ? 0x20U : ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__mi))
                                        ? ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__mi))
                                            ? 0x20U
                                            : ((1U 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__mi))
                                                ? 0x79U
                                                : 0x72U))
                                        : ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__mi))
                                            ? ((1U 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__mi))
                                                ? 0x6fU
                                                : 0x6dU)
                                            : ((1U 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__mi))
                                                ? 0x65U
                                                : 0x4dU))));
                    vlSelf->__Vdly__sim_top__DOT__soc__DOT__p_go = 1U;
                    if ((6U == (IData)(vlSelf->sim_top__DOT__soc__DOT__mi))) {
                        vlSelf->__Vdly__sim_top__DOT__soc__DOT__mi = 0U;
                        vlSelf->__Vdly__sim_top__DOT__soc__DOT__cs_ = 7U;
                    } else {
                        vlSelf->__Vdly__sim_top__DOT__soc__DOT__mi 
                            = (0xfU & ((IData)(1U) 
                                       + (IData)(vlSelf->sim_top__DOT__soc__DOT__mi)));
                    }
                }
            } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cs_))) {
                if (vlSelf->sim_top__DOT__soc__DOT__ld_done) {
                    vlSelf->__Vdly__sim_top__DOT__soc__DOT__cs_ = 3U;
                }
            } else {
                __Vdly__sim_top__DOT__soc__DOT__ld_start = 1U;
                vlSelf->__Vdly__sim_top__DOT__soc__DOT__cs_ = 5U;
            }
        } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cs_))) {
            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cs_))) {
                if (vlSelf->sim_top__DOT__soc__DOT__ecyc) {
                    if ((0xfU == (IData)(vlSelf->sim_top__DOT__soc__DOT__rcnt))) {
                        vlSelf->sim_top__DOT__soc__DOT__nreset_cpu = 1U;
                    } else {
                        vlSelf->__Vdly__sim_top__DOT__soc__DOT__rcnt 
                            = (0xfU & ((IData)(1U) 
                                       + (IData)(vlSelf->sim_top__DOT__soc__DOT__rcnt)));
                    }
                }
            } else if ((((~ (IData)(vlSelf->sim_top__DOT__soc__DOT__c_wr)) 
                         & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__m0_req))) 
                        & (0U == (3U & (IData)(vlSelf->sim_top__DOT__soc__DOT__bsy_d))))) {
                if ((0x1fffffU == vlSelf->sim_top__DOT__soc__DOT__cw)) {
                    vlSelf->__Vdly__sim_top__DOT__soc__DOT__cs_ = 4U;
                } else {
                    vlSelf->__Vdly__sim_top__DOT__soc__DOT__cw 
                        = vlSelf->sim_top__DOT__soc__DOT__cw_n;
                    vlSelf->__Vdly__sim_top__DOT__soc__DOT__cs_ = 1U;
                }
            }
        } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cs_))) {
            __Vdly__sim_top__DOT__soc__DOT__c_wr = 1U;
            vlSelf->__Vdly__sim_top__DOT__soc__DOT__cs_ = 2U;
        } else if (((0U == (IData)(vlSelf->sim_top__DOT__soc__DOT__bsy_d)) 
                    & (0U == (IData)(vlSelf->sim_top__DOT__mem__DOT__cnt)))) {
            vlSelf->__Vdly__sim_top__DOT__soc__DOT__cs_ = 1U;
        }
    }
    vlSelf->sim_top__DOT__soc__DOT__st_d = __Vdly__sim_top__DOT__soc__DOT__st_d;
    vlSelf->sim_top__DOT__soc__DOT__st_d2 = __Vdly__sim_top__DOT__soc__DOT__st_d2;
    vlSelf->sim_top__DOT__soc__DOT__p_go = vlSelf->__Vdly__sim_top__DOT__soc__DOT__p_go;
    vlSelf->sim_top__DOT__soc__DOT__bsy_d = vlSelf->__Vdly__sim_top__DOT__soc__DOT__bsy_d;
    vlSelf->sim_top__DOT__soc__DOT__rcnt = vlSelf->__Vdly__sim_top__DOT__soc__DOT__rcnt;
    vlSelf->sim_top__DOT__soc__DOT__t_fail = vlSelf->__Vdly__sim_top__DOT__soc__DOT__t_fail;
    vlSelf->sim_top__DOT__soc__DOT__t_faddr = vlSelf->__Vdly__sim_top__DOT__soc__DOT__t_faddr;
    vlSelf->sim_top__DOT__soc__DOT__mi = vlSelf->__Vdly__sim_top__DOT__soc__DOT__mi;
    vlSelf->sim_top__DOT__soc__DOT__st_wr = __Vdly__sim_top__DOT__soc__DOT__st_wr;
    vlSelf->sim_top__DOT__soc__DOT__acia__DOT__tfull 
        = vlSelf->__Vdly__sim_top__DOT__soc__DOT__acia__DOT__tfull;
    vlSelf->sim_top__DOT__soc__DOT__t_rd = __Vdly__sim_top__DOT__soc__DOT__t_rd;
    vlSelf->sim_top__DOT__soc__DOT__c_wr = __Vdly__sim_top__DOT__soc__DOT__c_wr;
    vlSelf->sim_top__DOT__soc__DOT__cw_pg = (0x3ffffU 
                                             == (0x3ffffU 
                                                 & vlSelf->sim_top__DOT__soc__DOT__cw));
    vlSelf->sim_top__DOT__soc__DOT__cw_last = (0x3fffU 
                                               == vlSelf->sim_top__DOT__soc__DOT__cw);
    vlSelf->sim_top__DOT__soc__DOT__cw_n = (0x3fffffU 
                                            & ((IData)(1U) 
                                               + vlSelf->sim_top__DOT__soc__DOT__cw));
    vlSelf->sim_top__DOT__soc__DOT__t_got_r = (0xffU 
                                               & ((1U 
                                                   & vlSelf->sim_top__DOT__soc__DOT__cw)
                                                   ? 
                                                  ((IData)(vlSelf->sim_top__DOT__soc__DOT__ps_dout_m) 
                                                   >> 8U)
                                                   : (IData)(vlSelf->sim_top__DOT__soc__DOT__ps_dout_m)));
    vlSelf->sim_top__DOT__soc__DOT__ecyc = 0U;
    __Vdly__sim_top__DOT__soc__DOT__acc_go = 0U;
    if (vlSelf->sim_top__DOT__soc__DOT__rst) {
        vlSelf->sim_top__DOT__soc__DOT__timer__DOT__running = 0U;
        vlSelf->__Vdly__sim_top__DOT__soc__DOT__div = 0U;
        vlSelf->__Vdly__sim_top__DOT__soc__DOT__ph = 0U;
        vlSelf->sim_top__DOT__soc__DOT__e = 1U;
        vlSelf->sim_top__DOT__soc__DOT__q = 0U;
        vlSelf->sim_top__DOT__soc__DOT__div = vlSelf->__Vdly__sim_top__DOT__soc__DOT__div;
        vlSelf->sim_top__DOT__soc__DOT__ph = vlSelf->__Vdly__sim_top__DOT__soc__DOT__ph;
        vlSelf->sim_top__DOT__soc__DOT__settle = vlSelf->__Vdly__sim_top__DOT__soc__DOT__settle;
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__win_busy 
            = vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__win_busy;
        vlSelf->sim_top__DOT__soc__DOT__go_req = 0U;
        vlSelf->sim_top__DOT__soc__DOT__c_rd = 0U;
        vlSelf->sim_top__DOT__soc__DOT__c_cwr = 0U;
        vlSelf->sim_top__DOT__soc__DOT__xl_rcap = 0U;
        vlSelf->__Vdly__sim_top__DOT__soc__DOT__xl_cnt = 0U;
        vlSelf->sim_top__DOT__soc__DOT__xl_cnt = vlSelf->__Vdly__sim_top__DOT__soc__DOT__xl_cnt;
        vlSelf->__Vdly__sim_top__DOT__soc__DOT__mem_pend = 0U;
        vlSelf->__Vdly__sim_top__DOT__soc__DOT__mp_wait = 0U;
        vlSelf->sim_top__DOT__soc__DOT__pwroff = 0U;
        vlSelf->sim_top__DOT__soc__DOT__osrun = 0U;
        vlSelf->sim_top__DOT__soc__DOT__acia_pend = 0U;
        vlSelf->__Vdlyvset__sim_top__DOT__soc__DOT__map_s__v0 = 1U;
        vlSelf->sim_top__DOT__soc__DOT__tr = 0U;
        vlSelf->sim_top__DOT__soc__DOT__tr_raw = 0xffU;
        vlSelf->__Vdly__sim_top__DOT__soc__DOT__l2 = 0U;
        vlSelf->sim_top__DOT__soc__DOT__rd_reg = 0U;
        vlSelf->__Vdlyvset__sim_top__DOT__soc__DOT__map_s__v1 = 1U;
    } else {
        if (vlSelf->sim_top__DOT__soc__DOT__timer_wr) {
            if ((0U == (7U & (IData)(vlSelf->sim_top__DOT__soc__DOT__off)))) {
                if ((0x8fU == (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DOutput))) {
                    vlSelf->sim_top__DOT__soc__DOT__timer__DOT__running = 1U;
                } else if ((0x80U == (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DOutput))) {
                    vlSelf->sim_top__DOT__soc__DOT__timer__DOT__running = 0U;
                }
            }
        }
        if ((8U != (IData)(vlSelf->sim_top__DOT__soc__DOT__div))) {
            vlSelf->__Vdly__sim_top__DOT__soc__DOT__div 
                = (0xffU & ((IData)(1U) + (IData)(vlSelf->sim_top__DOT__soc__DOT__div)));
        } else if ((1U & (~ ((0U == (IData)(vlSelf->sim_top__DOT__soc__DOT__ph)) 
                             & ((IData)(vlSelf->sim_top__DOT__soc__DOT__mem_pend) 
                                | ((IData)(vlSelf->sim_top__DOT__soc__DOT__disk_busy) 
                                   | ((IData)(vlSelf->sim_top__DOT__soc__DOT__pwroff) 
                                      | ((IData)(vlSelf->sim_top__DOT__soc__DOT__acia_pend) 
                                         | ((0U != (IData)(vlSelf->sim_top__DOT__soc__DOT__settle)) 
                                            | ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__win_busy) 
                                               | (IData)(vlSelf->sim_top__DOT__soc__DOT__xl_rcap))))))))))) {
            vlSelf->__Vdly__sim_top__DOT__soc__DOT__ph 
                = (3U & ((IData)(1U) + (IData)(vlSelf->sim_top__DOT__soc__DOT__ph)));
            vlSelf->__Vdly__sim_top__DOT__soc__DOT__div = 0U;
            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__ph))) {
                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__ph))) {
                    vlSelf->sim_top__DOT__soc__DOT__q = 0U;
                } else {
                    vlSelf->sim_top__DOT__soc__DOT__e = 1U;
                    __Vdly__sim_top__DOT__soc__DOT__acc_go = 1U;
                }
            } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__ph))) {
                vlSelf->sim_top__DOT__soc__DOT__q = 1U;
            } else {
                vlSelf->sim_top__DOT__soc__DOT__e = 0U;
                vlSelf->sim_top__DOT__soc__DOT__ecyc = 1U;
            }
        }
        vlSelf->sim_top__DOT__soc__DOT__div = vlSelf->__Vdly__sim_top__DOT__soc__DOT__div;
        vlSelf->sim_top__DOT__soc__DOT__ph = vlSelf->__Vdly__sim_top__DOT__soc__DOT__ph;
        vlSelf->sim_top__DOT__soc__DOT__settle = vlSelf->__Vdly__sim_top__DOT__soc__DOT__settle;
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__win_busy 
            = vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__win_busy;
        vlSelf->sim_top__DOT__soc__DOT__go_req = 0U;
        vlSelf->sim_top__DOT__soc__DOT__c_rd = 0U;
        vlSelf->sim_top__DOT__soc__DOT__c_cwr = 0U;
        if (vlSelf->sim_top__DOT__soc__DOT__xl_re) {
            vlSelf->sim_top__DOT__soc__DOT__xl_rcap = 1U;
            vlSelf->__Vdly__sim_top__DOT__soc__DOT__xl_cnt = 4U;
        } else if ((0U != (IData)(vlSelf->sim_top__DOT__soc__DOT__xl_cnt))) {
            vlSelf->__Vdly__sim_top__DOT__soc__DOT__xl_cnt 
                = (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__xl_cnt) 
                         - (IData)(1U)));
        } else if (vlSelf->sim_top__DOT__soc__DOT__xl_cap) {
            vlSelf->sim_top__DOT__soc__DOT__xl_rcap = 0U;
        }
        vlSelf->sim_top__DOT__soc__DOT__xl_cnt = vlSelf->__Vdly__sim_top__DOT__soc__DOT__xl_cnt;
        vlSelf->sim_top__DOT__soc__DOT__c_addr = ((IData)(vlSelf->sim_top__DOT__soc__DOT__l2)
                                                   ? vlSelf->sim_top__DOT__soc__DOT__pa
                                                   : (IData)(vlSelf->dbg_addr));
        if (vlSelf->sim_top__DOT__soc__DOT__acc2) {
            if (vlSelf->sim_top__DOT__soc__DOT__vma_pend) {
                if (vlSelf->sim_top__DOT__soc__DOT__io_hit) {
                    if (vlSelf->dbg_rnw) {
                        vlSelf->sim_top__DOT__soc__DOT__rd_reg 
                            = vlSelf->sim_top__DOT__soc__DOT__io_rdata;
                    } else {
                        if (((IData)(vlSelf->sim_top__DOT__soc__DOT__io_power) 
                             & (0xa5U == (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DOutput)))) {
                            vlSelf->sim_top__DOT__soc__DOT__pwroff = 1U;
                            vlSelf->sim_top__DOT__soc__DOT__osrun = 0U;
                        }
                        if (vlSelf->sim_top__DOT__soc__DOT__io_modr) {
                            if (((0xa2U == (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DOutput)) 
                                 & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__l2)))) {
                                vlSelf->__Vdly__sim_top__DOT__soc__DOT__l2 = 1U;
                                vlSelf->sim_top__DOT__soc__DOT__tr = 0U;
                                vlSelf->sim_top__DOT__soc__DOT__tr_raw = 0xffU;
                                vlSelf->__Vdlyvset__sim_top__DOT__soc__DOT__map_s__v9 = 1U;
                            }
                            if (((0xa3U == (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DOutput)) 
                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__l2))) {
                                vlSelf->sim_top__DOT__soc__DOT__go_req = 1U;
                                vlSelf->sim_top__DOT__soc__DOT__tr = 0U;
                                vlSelf->sim_top__DOT__soc__DOT__tr_raw = 0xffU;
                                vlSelf->__Vdlyvset__sim_top__DOT__soc__DOT__map_s__v17 = 1U;
                            }
                        }
                        if (((IData)(vlSelf->sim_top__DOT__soc__DOT__io_acia) 
                             & (IData)(vlSelf->sim_top__DOT__soc__DOT__off))) {
                            vlSelf->sim_top__DOT__soc__DOT__acia_pend = 1U;
                            vlSelf->sim_top__DOT__soc__DOT__acia_byte 
                                = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DOutput;
                        }
                        if (((IData)(vlSelf->sim_top__DOT__soc__DOT__io_power) 
                             & (0xa4U == (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DOutput)))) {
                            vlSelf->sim_top__DOT__soc__DOT__osrun = 1U;
                        }
                        if (vlSelf->sim_top__DOT__soc__DOT__io_mmu) {
                            vlSelf->sim_top__DOT__soc__DOT__tr_raw 
                                = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DOutput;
                            vlSelf->sim_top__DOT__soc__DOT__tr 
                                = (1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DOutput));
                        }
                        if (vlSelf->sim_top__DOT__soc__DOT__io_map) {
                            if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__off))) {
                                __Vdlyvval__sim_top__DOT__soc__DOT__map_u__v16 
                                    = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DOutput;
                                vlSelf->__Vdlyvset__sim_top__DOT__soc__DOT__map_u__v16 = 1U;
                                __Vdlyvdim0__sim_top__DOT__soc__DOT__map_u__v16 
                                    = (7U & (IData)(vlSelf->sim_top__DOT__soc__DOT__off));
                            } else {
                                __Vdlyvval__sim_top__DOT__soc__DOT__map_s__v26 
                                    = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DOutput;
                                vlSelf->__Vdlyvset__sim_top__DOT__soc__DOT__map_s__v26 = 1U;
                                __Vdlyvdim0__sim_top__DOT__soc__DOT__map_s__v26 
                                    = (7U & (IData)(vlSelf->sim_top__DOT__soc__DOT__off));
                            }
                        }
                    }
                } else if (((IData)(vlSelf->dbg_rnw) 
                            & (IData)(vlSelf->sim_top__DOT__soc__DOT__rom_sel))) {
                    vlSelf->sim_top__DOT__soc__DOT__rd_reg 
                        = vlSelf->sim_top__DOT__soc__DOT__rom_q;
                } else if ((1U & (~ ((~ (IData)(vlSelf->dbg_rnw)) 
                                     & ((IData)(vlSelf->sim_top__DOT__soc__DOT__rom_sel) 
                                        | (IData)(vlSelf->sim_top__DOT__soc__DOT__io_quiet)))))) {
                    vlSelf->sim_top__DOT__soc__DOT__c_rd 
                        = vlSelf->dbg_rnw;
                    vlSelf->sim_top__DOT__soc__DOT__c_cwr 
                        = (1U & (~ (IData)(vlSelf->dbg_rnw)));
                    vlSelf->__Vdly__sim_top__DOT__soc__DOT__c_isrd 
                        = vlSelf->dbg_rnw;
                    vlSelf->__Vdly__sim_top__DOT__soc__DOT__mem_pend = 1U;
                    vlSelf->__Vdly__sim_top__DOT__soc__DOT__mp_wait = 1U;
                }
            }
        }
        if (vlSelf->sim_top__DOT__soc__DOT__acia_wr) {
            vlSelf->sim_top__DOT__soc__DOT__acia_pend = 0U;
        }
        if (vlSelf->sim_top__DOT__soc__DOT__xl_cap) {
            vlSelf->sim_top__DOT__soc__DOT__rd_reg 
                = vlSelf->sim_top__DOT__soc__DOT__xl_rdata;
        }
        if (vlSelf->sim_top__DOT__soc__DOT__mem_pend) {
            if (vlSelf->sim_top__DOT__soc__DOT__mp_wait) {
                vlSelf->__Vdly__sim_top__DOT__soc__DOT__mp_wait = 0U;
            } else if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__m0_req)))) {
                vlSelf->__Vdly__sim_top__DOT__soc__DOT__mem_pend = 0U;
                if (vlSelf->sim_top__DOT__soc__DOT__c_isrd) {
                    vlSelf->sim_top__DOT__soc__DOT__rd_reg 
                        = (0xffU & ((IData)(vlSelf->sim_top__DOT__soc__DOT__c_rsel)
                                     ? ((IData)(vlSelf->sim_top__DOT__soc__DOT__ps_dout_m) 
                                        >> 8U) : (IData)(vlSelf->sim_top__DOT__soc__DOT__ps_dout_m)));
                }
            }
        }
    }
    vlSelf->sim_top__DOT__soc__DOT__mp_wait = vlSelf->__Vdly__sim_top__DOT__soc__DOT__mp_wait;
    vlSelf->sim_top__DOT__soc__DOT__c_isrd = vlSelf->__Vdly__sim_top__DOT__soc__DOT__c_isrd;
    vlSelf->sim_top__DOT__soc__DOT__mem_pend = vlSelf->__Vdly__sim_top__DOT__soc__DOT__mem_pend;
    if (vlSelf->__Vdlyvset__sim_top__DOT__soc__DOT__map_s__v0) {
        vlSelf->sim_top__DOT__soc__DOT__map_u[0U] = 0xffU;
        vlSelf->sim_top__DOT__soc__DOT__map_s[0U] = 0xffU;
    }
    if (vlSelf->__Vdlyvset__sim_top__DOT__soc__DOT__map_s__v1) {
        vlSelf->sim_top__DOT__soc__DOT__map_u[1U] = 0xffU;
        vlSelf->sim_top__DOT__soc__DOT__map_u[2U] = 0xffU;
        vlSelf->sim_top__DOT__soc__DOT__map_u[3U] = 0xffU;
        vlSelf->sim_top__DOT__soc__DOT__map_u[4U] = 0xffU;
        vlSelf->sim_top__DOT__soc__DOT__map_u[5U] = 0xffU;
        vlSelf->sim_top__DOT__soc__DOT__map_u[6U] = 0xffU;
        vlSelf->sim_top__DOT__soc__DOT__map_u[7U] = 0xffU;
        vlSelf->sim_top__DOT__soc__DOT__map_s[1U] = 0xffU;
        vlSelf->sim_top__DOT__soc__DOT__map_s[2U] = 0xffU;
        vlSelf->sim_top__DOT__soc__DOT__map_s[3U] = 0xffU;
        vlSelf->sim_top__DOT__soc__DOT__map_s[4U] = 0xffU;
        vlSelf->sim_top__DOT__soc__DOT__map_s[5U] = 0xffU;
        vlSelf->sim_top__DOT__soc__DOT__map_s[6U] = 0xffU;
        vlSelf->sim_top__DOT__soc__DOT__map_s[7U] = 0xffU;
        vlSelf->sim_top__DOT__soc__DOT__map_s[7U] = 0x3fU;
    }
    if (vlSelf->__Vdlyvset__sim_top__DOT__soc__DOT__map_s__v17) {
        vlSelf->sim_top__DOT__soc__DOT__map_u[0U] = 0xffU;
        vlSelf->sim_top__DOT__soc__DOT__map_u[1U] = 0xffU;
        vlSelf->sim_top__DOT__soc__DOT__map_u[2U] = 0xffU;
        vlSelf->sim_top__DOT__soc__DOT__map_u[3U] = 0xffU;
        vlSelf->sim_top__DOT__soc__DOT__map_u[4U] = 0xffU;
        vlSelf->sim_top__DOT__soc__DOT__map_u[5U] = 0xffU;
        vlSelf->sim_top__DOT__soc__DOT__map_u[6U] = 0xffU;
        vlSelf->sim_top__DOT__soc__DOT__map_u[7U] = 0xffU;
    }
    if (vlSelf->__Vdlyvset__sim_top__DOT__soc__DOT__map_u__v16) {
        vlSelf->sim_top__DOT__soc__DOT__map_u[__Vdlyvdim0__sim_top__DOT__soc__DOT__map_u__v16] 
            = __Vdlyvval__sim_top__DOT__soc__DOT__map_u__v16;
    }
    if (vlSelf->__Vdlyvset__sim_top__DOT__soc__DOT__map_s__v9) {
        vlSelf->sim_top__DOT__soc__DOT__map_s[0U] = 0U;
        vlSelf->sim_top__DOT__soc__DOT__map_s[1U] = 1U;
        vlSelf->sim_top__DOT__soc__DOT__map_s[2U] = 2U;
        vlSelf->sim_top__DOT__soc__DOT__map_s[3U] = 3U;
        vlSelf->sim_top__DOT__soc__DOT__map_s[4U] = 4U;
        vlSelf->sim_top__DOT__soc__DOT__map_s[5U] = 5U;
        vlSelf->sim_top__DOT__soc__DOT__map_s[6U] = 6U;
        vlSelf->sim_top__DOT__soc__DOT__map_s[7U] = 0x3fU;
    }
    if (vlSelf->__Vdlyvset__sim_top__DOT__soc__DOT__map_s__v17) {
        vlSelf->sim_top__DOT__soc__DOT__map_s[0U] = 0xffU;
        vlSelf->sim_top__DOT__soc__DOT__map_s[1U] = 0xffU;
        vlSelf->sim_top__DOT__soc__DOT__map_s[2U] = 0xffU;
        vlSelf->sim_top__DOT__soc__DOT__map_s[3U] = 0xffU;
        vlSelf->sim_top__DOT__soc__DOT__map_s[4U] = 0xffU;
        vlSelf->sim_top__DOT__soc__DOT__map_s[5U] = 0xffU;
        vlSelf->sim_top__DOT__soc__DOT__map_s[6U] = 0xffU;
        vlSelf->sim_top__DOT__soc__DOT__map_s[7U] = 0xffU;
        vlSelf->sim_top__DOT__soc__DOT__map_s[7U] = 0x3fU;
    }
    if (vlSelf->__Vdlyvset__sim_top__DOT__soc__DOT__map_s__v26) {
        vlSelf->sim_top__DOT__soc__DOT__map_s[__Vdlyvdim0__sim_top__DOT__soc__DOT__map_s__v26] 
            = __Vdlyvval__sim_top__DOT__soc__DOT__map_s__v26;
    }
    vlSelf->sim_top__DOT__soc__DOT__xl_cap = ((IData)(vlSelf->sim_top__DOT__soc__DOT__xl_rcap) 
                                              & ((~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__win_busy)) 
                                                 & (0U 
                                                    == (IData)(vlSelf->sim_top__DOT__soc__DOT__xl_cnt))));
    vlSelf->term_byte = ((IData)(vlSelf->sim_top__DOT__soc__DOT__st_wr)
                          ? (IData)(vlSelf->sim_top__DOT__soc__DOT__st_byte)
                          : (IData)(vlSelf->sim_top__DOT__soc__DOT__acia_byte));
    vlSelf->sim_top__DOT__soc__DOT__acia_wr = ((~ (IData)(vlSelf->sim_top__DOT__soc__DOT__acia__DOT__tfull)) 
                                               & (IData)(vlSelf->sim_top__DOT__soc__DOT__acia_pend));
    vlSelf->sim_top__DOT__soc__DOT__rom_q = vlSelf->sim_top__DOT__soc__DOT__rom
        [(0xffU & (IData)(vlSelf->dbg_addr))];
    vlSelf->sim_top__DOT__soc__DOT__xl_rdata = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl_rdata;
    vlSelf->sim_top__DOT__soc__DOT__rom_sel = ((~ (IData)(vlSelf->sim_top__DOT__soc__DOT__l2)) 
                                               & (0xff00U 
                                                  <= (IData)(vlSelf->dbg_addr)));
    vlSelf->sim_top__DOT__soc__DOT__io_power = ((IData)(vlSelf->sim_top__DOT__soc__DOT__in_io) 
                                                & (0xfU 
                                                   == (IData)(vlSelf->sim_top__DOT__soc__DOT__off)));
    vlSelf->sim_top__DOT__soc__DOT__io_modr = ((IData)(vlSelf->sim_top__DOT__soc__DOT__in_io) 
                                               & (0xeU 
                                                  == (IData)(vlSelf->sim_top__DOT__soc__DOT__off)));
    vlSelf->sim_top__DOT__soc__DOT__io_acia = ((IData)(vlSelf->sim_top__DOT__soc__DOT__in_io) 
                                               & (0U 
                                                  == 
                                                  (0x1feU 
                                                   & (IData)(vlSelf->sim_top__DOT__soc__DOT__off))));
    vlSelf->sim_top__DOT__soc__DOT__io_quiet = ((((~ (IData)(vlSelf->sim_top__DOT__soc__DOT__l2)) 
                                                  & (IData)(vlSelf->sim_top__DOT__soc__DOT__in_io)) 
                                                 & (0x80U 
                                                    > (IData)(vlSelf->sim_top__DOT__soc__DOT__off))) 
                                                & (~ 
                                                   ((((((0U 
                                                         == 
                                                         (0xffU 
                                                          & ((IData)(vlSelf->sim_top__DOT__soc__DOT__off) 
                                                             >> 1U))) 
                                                        | (0xfU 
                                                           == (IData)(vlSelf->sim_top__DOT__soc__DOT__off))) 
                                                       | (0xeU 
                                                          == (IData)(vlSelf->sim_top__DOT__soc__DOT__off))) 
                                                      | ((0x30U 
                                                          <= (IData)(vlSelf->sim_top__DOT__soc__DOT__off)) 
                                                         & (0x36U 
                                                            >= (IData)(vlSelf->sim_top__DOT__soc__DOT__off)))) 
                                                     | ((0x40U 
                                                         <= (IData)(vlSelf->sim_top__DOT__soc__DOT__off)) 
                                                        & (0x47U 
                                                           >= (IData)(vlSelf->sim_top__DOT__soc__DOT__off)))) 
                                                    | ((0x49U 
                                                        <= (IData)(vlSelf->sim_top__DOT__soc__DOT__off)) 
                                                       & (0x4dU 
                                                          >= (IData)(vlSelf->sim_top__DOT__soc__DOT__off))))));
    vlSelf->sim_top__DOT__soc__DOT__io_hit = (((IData)(vlSelf->sim_top__DOT__soc__DOT__in_io) 
                                               & (((((((0U 
                                                        == 
                                                        (0xffU 
                                                         & ((IData)(vlSelf->sim_top__DOT__soc__DOT__off) 
                                                            >> 1U))) 
                                                       | (0xfU 
                                                          == (IData)(vlSelf->sim_top__DOT__soc__DOT__off))) 
                                                      | (0xeU 
                                                         == (IData)(vlSelf->sim_top__DOT__soc__DOT__off))) 
                                                     | ((0x30U 
                                                         <= (IData)(vlSelf->sim_top__DOT__soc__DOT__off)) 
                                                        & (0x36U 
                                                           >= (IData)(vlSelf->sim_top__DOT__soc__DOT__off)))) 
                                                    | ((0x40U 
                                                        <= (IData)(vlSelf->sim_top__DOT__soc__DOT__off)) 
                                                       & (0x47U 
                                                          >= (IData)(vlSelf->sim_top__DOT__soc__DOT__off)))) 
                                                   | ((0x49U 
                                                       <= (IData)(vlSelf->sim_top__DOT__soc__DOT__off)) 
                                                      & (0x4dU 
                                                         >= (IData)(vlSelf->sim_top__DOT__soc__DOT__off)))) 
                                                  | ((IData)(vlSelf->sim_top__DOT__soc__DOT__l2) 
                                                     & ((0x11U 
                                                         == (IData)(vlSelf->sim_top__DOT__soc__DOT__off)) 
                                                        | ((0x20U 
                                                            <= (IData)(vlSelf->sim_top__DOT__soc__DOT__off)) 
                                                           & (0x2fU 
                                                              >= (IData)(vlSelf->sim_top__DOT__soc__DOT__off))))))) 
                                              | (IData)(vlSelf->sim_top__DOT__soc__DOT__ta));
    vlSelf->sim_top__DOT__soc__DOT__io_mmu = (((IData)(vlSelf->sim_top__DOT__soc__DOT__l2) 
                                               & (IData)(vlSelf->sim_top__DOT__soc__DOT__in_io)) 
                                              & (0x11U 
                                                 == (IData)(vlSelf->sim_top__DOT__soc__DOT__off)));
    vlSelf->sim_top__DOT__soc__DOT__io_map = ((((IData)(vlSelf->sim_top__DOT__soc__DOT__l2) 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__in_io)) 
                                               & (0x20U 
                                                  <= (IData)(vlSelf->sim_top__DOT__soc__DOT__off))) 
                                              & (0x2fU 
                                                 >= (IData)(vlSelf->sim_top__DOT__soc__DOT__off)));
    vlSelf->dbg_din = vlSelf->sim_top__DOT__soc__DOT__rd_reg;
    vlSelf->sim_top__DOT__ps_rd = 0U;
    vlSelf->sim_top__DOT__ps_wr = 0U;
    __Vdly__sim_top__DOT__soc__DOT__m0_ack = 0U;
    __Vdly__sim_top__DOT__soc__DOT__zm_ack = 0U;
    vlSelf->term_stb = ((IData)(vlSelf->sim_top__DOT__soc__DOT__acia_wr) 
                        | (IData)(vlSelf->sim_top__DOT__soc__DOT__st_wr));
    vlSelf->sim_top__DOT__soc__DOT__l2 = vlSelf->__Vdly__sim_top__DOT__soc__DOT__l2;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__MapInstruction__14__i 
        = vlSelf->dbg_din;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__MapInstruction__14__newinst 
        = __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__MapInstruction__14__i;
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__MapInstruction__14__topnyb 
        = (0xfU & ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__MapInstruction__14__i) 
                   >> 4U));
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__MapInstruction__14__btmnyb 
        = (0xfU & (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__MapInstruction__14__i));
    if ((((((0U == (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__MapInstruction__14__topnyb)) 
            | (4U == (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__MapInstruction__14__topnyb))) 
           | (5U == (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__MapInstruction__14__topnyb))) 
          | (6U == (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__MapInstruction__14__topnyb))) 
         | (7U == (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__MapInstruction__14__topnyb)))) {
        if ((1U == (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__MapInstruction__14__btmnyb))) {
            __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__MapInstruction__14__newinst 
                = ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__MapInstruction__14__topnyb) 
                   << 4U);
        }
        if ((2U == (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__MapInstruction__14__btmnyb))) {
            __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__MapInstruction__14__newinst 
                = (3U | ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__MapInstruction__14__topnyb) 
                         << 4U));
        }
        if ((5U == (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__MapInstruction__14__btmnyb))) {
            __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__MapInstruction__14__newinst 
                = (4U | ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__MapInstruction__14__topnyb) 
                         << 4U));
        }
        if ((0xbU == (IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__MapInstruction__14__btmnyb))) {
            __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__MapInstruction__14__newinst 
                = (0xaU | ((IData)(__Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__MapInstruction__14__topnyb) 
                           << 4U));
        }
    }
    __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__MapInstruction__14__Vfuncout 
        = __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__MapInstruction__14__newinst;
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__MappedInstruction 
        = __Vfunc_sim_top__DOT__soc__DOT__cpu__DOT__MapInstruction__14__Vfuncout;
    if (vlSelf->sim_top__DOT__soc__DOT__rst) {
        vlSelf->sim_top__DOT__soc__DOT__vma_pend = 1U;
        vlSelf->__Vdly__sim_top__DOT__soc__DOT__arb__DOT__st = 0U;
    } else {
        if (vlSelf->sim_top__DOT__soc__DOT__acc2) {
            vlSelf->sim_top__DOT__soc__DOT__vma_pend 
                = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__rAVMA;
        }
        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__arb__DOT__st))) {
            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__arb__DOT__st))) {
                vlSelf->__Vdly__sim_top__DOT__soc__DOT__arb__DOT__st = 0U;
            } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__arb__DOT__st))) {
                vlSelf->__Vdly__sim_top__DOT__soc__DOT__arb__DOT__st = 0U;
            } else {
                if ((0U == (IData)(vlSelf->sim_top__DOT__soc__DOT__arb__DOT__sel))) {
                    vlSelf->sim_top__DOT__soc__DOT__ps_dout_m 
                        = vlSelf->sim_top__DOT__ps_dout;
                    __Vdly__sim_top__DOT__soc__DOT__m0_ack = 1U;
                } else if ((1U != (IData)(vlSelf->sim_top__DOT__soc__DOT__arb__DOT__sel))) {
                    if ((3U == (IData)(vlSelf->sim_top__DOT__soc__DOT__arb__DOT__sel))) {
                        vlSelf->sim_top__DOT__soc__DOT__zm_rdata_w 
                            = vlSelf->sim_top__DOT__ps_dout;
                        __Vdly__sim_top__DOT__soc__DOT__zm_ack = 1U;
                    }
                }
                vlSelf->__Vdly__sim_top__DOT__soc__DOT__arb__DOT__st = 5U;
            }
        } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__arb__DOT__st))) {
            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__arb__DOT__st))) {
                if ((0U == (IData)(vlSelf->sim_top__DOT__mem__DOT__cnt))) {
                    vlSelf->__Vdly__sim_top__DOT__soc__DOT__arb__DOT__st = 4U;
                }
            } else {
                vlSelf->__Vdly__sim_top__DOT__soc__DOT__arb__DOT__st = 3U;
            }
        } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__arb__DOT__st))) {
            vlSelf->sim_top__DOT__ps_rd = ((((1U == (IData)(vlSelf->sim_top__DOT__soc__DOT__arb__DOT__sel)) 
                                             | (2U 
                                                == (IData)(vlSelf->sim_top__DOT__soc__DOT__arb__DOT__sel))) 
                                            | ((0U 
                                                == (IData)(vlSelf->sim_top__DOT__soc__DOT__arb__DOT__sel)) 
                                               & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__m0_wrr)))) 
                                           | ((3U == (IData)(vlSelf->sim_top__DOT__soc__DOT__arb__DOT__sel)) 
                                              & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__zm_wr))));
            vlSelf->sim_top__DOT__ps_wr = (((0U == (IData)(vlSelf->sim_top__DOT__soc__DOT__arb__DOT__sel)) 
                                            & (IData)(vlSelf->sim_top__DOT__soc__DOT__m0_wrr)) 
                                           | ((3U == (IData)(vlSelf->sim_top__DOT__soc__DOT__arb__DOT__sel)) 
                                              & (IData)(vlSelf->sim_top__DOT__soc__DOT__zm_wr)));
            vlSelf->__Vdly__sim_top__DOT__soc__DOT__arb__DOT__st = 2U;
        } else if ((0U == (IData)(vlSelf->sim_top__DOT__mem__DOT__cnt))) {
            if (vlSelf->sim_top__DOT__soc__DOT__zm_req) {
                vlSelf->sim_top__DOT__soc__DOT__arb__DOT__sel = 3U;
                vlSelf->sim_top__DOT__ps_addr = vlSelf->sim_top__DOT__soc__DOT__zm_addr;
                vlSelf->sim_top__DOT__ps_din = (0xffffU 
                                                & (((IData)(vlSelf->sim_top__DOT__soc__DOT__zm_wdata) 
                                                    << 8U) 
                                                   | (IData)(vlSelf->sim_top__DOT__soc__DOT__zm_wdata)));
                vlSelf->__Vdly__sim_top__DOT__soc__DOT__arb__DOT__st = 1U;
            } else if (vlSelf->sim_top__DOT__soc__DOT__m0_req) {
                vlSelf->sim_top__DOT__soc__DOT__arb__DOT__sel = 0U;
                vlSelf->sim_top__DOT__ps_addr = vlSelf->sim_top__DOT__soc__DOT__m0_addr;
                vlSelf->sim_top__DOT__ps_din = (0xffffU 
                                                & (((IData)(vlSelf->sim_top__DOT__soc__DOT__m0_din) 
                                                    << 8U) 
                                                   | (IData)(vlSelf->sim_top__DOT__soc__DOT__m0_din)));
                vlSelf->__Vdly__sim_top__DOT__soc__DOT__arb__DOT__st = 1U;
            }
        }
    }
    vlSelf->sim_top__DOT__ps_dout = vlSelf->__Vdly__sim_top__DOT__ps_dout;
    vlSelf->sim_top__DOT__soc__DOT__m0_addr = vlSelf->__Vdly__sim_top__DOT__soc__DOT__m0_addr;
    vlSelf->sim_top__DOT__soc__DOT__arb__DOT__st = vlSelf->__Vdly__sim_top__DOT__soc__DOT__arb__DOT__st;
    vlSelf->sim_top__DOT__mem__DOT__cnt = vlSelf->__Vdly__sim_top__DOT__mem__DOT__cnt;
    vlSelf->dbg_vma = vlSelf->sim_top__DOT__soc__DOT__vma_pend;
    vlSelf->sim_top__DOT__soc__DOT__acc2 = vlSelf->sim_top__DOT__soc__DOT__acc_go;
    vlSelf->dbg_ps_rd = vlSelf->sim_top__DOT__ps_rd;
    vlSelf->dbg_ps_wr = vlSelf->sim_top__DOT__ps_wr;
    vlSelf->dbg_ps_addr = vlSelf->sim_top__DOT__ps_addr;
    if (vlSelf->sim_top__DOT__soc__DOT__m0_pulse) {
        vlSelf->sim_top__DOT__soc__DOT__m0_wrr = vlSelf->sim_top__DOT__soc__DOT__m_wr_s;
        vlSelf->sim_top__DOT__soc__DOT__m0_din = ((IData)(vlSelf->sim_top__DOT__soc__DOT__run)
                                                   ? 
                                                  ((IData)(vlSelf->sim_top__DOT__soc__DOT__xw_act)
                                                    ? (IData)(vlSelf->sim_top__DOT__soc__DOT__win_wdata)
                                                    : 
                                                   ((IData)(vlSelf->sim_top__DOT__soc__DOT__disk_sel)
                                                     ? (IData)(vlSelf->sim_top__DOT__soc__DOT__d_din)
                                                     : (IData)(vlSelf->sim_top__DOT__soc__DOT__c_wdata)))
                                                   : 
                                                  ((IData)(vlSelf->sim_top__DOT__soc__DOT__ld_wr)
                                                    ? (IData)(vlSelf->sim_top__DOT__soc__DOT__ld_data)
                                                    : (IData)(vlSelf->sim_top__DOT__soc__DOT__td_r)));
    }
    if (vlSelf->sim_top__DOT__soc__DOT__xl_we) {
        if ((4U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__off) 
                   - (IData)(1U)))) {
            if ((1U & (~ (3U & (((IData)(vlSelf->sim_top__DOT__soc__DOT__off) 
                                 - (IData)(1U)) >> 1U))))) {
                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__off) 
                              - (IData)(1U))))) {
                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx) 
                                  >> 6U)))) {
                        if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx) 
                                      >> 5U)))) {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx) 
                                          >> 4U)))) {
                                if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx))) {
                                    if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx) 
                                                    >> 1U)))) {
                                            if ((1U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx))) {
                                                vlSelf->sim_top__DOT__soc__DOT__win_wdata 
                                                    = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DOutput;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__rst)))) {
        vlSelf->sim_top__DOT__soc__DOT__c_rsel = (1U 
                                                  & (IData)(vlSelf->dbg_addr));
        vlSelf->sim_top__DOT__soc__DOT__c_wdata = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DOutput;
    }
    vlSelf->sim_top__DOT__soc__DOT__acc_go = __Vdly__sim_top__DOT__soc__DOT__acc_go;
    if (vlSelf->sim_top__DOT__soc__DOT__rst) {
        vlSelf->sim_top__DOT__soc__DOT__zm_wr = 0U;
        vlSelf->sim_top__DOT__soc__DOT__zm_req = 0U;
    } else {
        if (vlSelf->sim_top__DOT__soc__DOT__sub__DOT__rd_start) {
            vlSelf->sim_top__DOT__soc__DOT__zm_wr = 0U;
            vlSelf->sim_top__DOT__soc__DOT__zm_req = 1U;
        } else if (vlSelf->sim_top__DOT__soc__DOT__sub__DOT__wr_end) {
            vlSelf->sim_top__DOT__soc__DOT__zm_wr = 1U;
            vlSelf->sim_top__DOT__soc__DOT__zm_req = 1U;
        }
        if (vlSelf->sim_top__DOT__soc__DOT__zm_ack) {
            vlSelf->sim_top__DOT__soc__DOT__zm_req = 0U;
        }
    }
    vlSelf->sim_top__DOT__soc__DOT__zm_ack = __Vdly__sim_top__DOT__soc__DOT__zm_ack;
    vlSelf->sim_top__DOT__soc__DOT__xw_act = vlSelf->__Vdly__sim_top__DOT__soc__DOT__xw_act;
    vlSelf->dbg_acc = vlSelf->sim_top__DOT__soc__DOT__acc2;
    vlSelf->sim_top__DOT__soc__DOT____VdfgTmp_h20f74f65__0 
        = ((IData)(vlSelf->sim_top__DOT__soc__DOT__acc2) 
           & (IData)(vlSelf->sim_top__DOT__soc__DOT__vma_pend));
    vlSelf->sim_top__DOT__soc__DOT__td_r = ((0U == (IData)(vlSelf->sim_top__DOT__soc__DOT__tp))
                                             ? 0x55U
                                             : ((1U 
                                                 == (IData)(vlSelf->sim_top__DOT__soc__DOT__tp))
                                                 ? 0xaaU
                                                 : 
                                                ((2U 
                                                  == (IData)(vlSelf->sim_top__DOT__soc__DOT__tp))
                                                  ? 
                                                 (0xffU 
                                                  & (vlSelf->sim_top__DOT__soc__DOT__cw 
                                                     ^ 
                                                     ((vlSelf->sim_top__DOT__soc__DOT__cw 
                                                       >> 8U) 
                                                      ^ 
                                                      (0x3fU 
                                                       & (vlSelf->sim_top__DOT__soc__DOT__cw 
                                                          >> 0x10U)))))
                                                  : 0U)));
    vlSelf->sim_top__DOT__soc__DOT__d_din = vlSelf->sim_top__DOT__soc__DOT__disk__DOT__b_q;
    vlSelf->sim_top__DOT__soc__DOT__disk_sel = vlSelf->sim_top__DOT__soc__DOT__disk_busy;
    vlSelf->sim_top__DOT__soc__DOT__run = ((~ (IData)(vlSelf->sim_top__DOT__soc__DOT__rst)) 
                                           & (3U == (IData)(vlSelf->sim_top__DOT__soc__DOT__cs_)));
    __Vdly__sim_top__DOT__soc__DOT__loader__DOT__sgo = 0U;
    vlSelf->sim_top__DOT__soc__DOT__ld_wr = 0U;
    if (vlSelf->sim_top__DOT__soc__DOT__rst) {
        vlSelf->sim_top__DOT__soc__DOT__zm_addr = 0U;
    } else if (vlSelf->sim_top__DOT__soc__DOT__sub__DOT__rd_start) {
        vlSelf->sim_top__DOT__soc__DOT__zm_addr = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__sub_phys;
    } else if (vlSelf->sim_top__DOT__soc__DOT__sub__DOT__wr_end) {
        vlSelf->sim_top__DOT__soc__DOT__zm_addr = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__wr_phys;
    }
    if (vlSelf->sim_top__DOT__soc__DOT__sub__DOT__mem_wrc) {
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__wr_phys 
            = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__sub_phys;
    }
    if (vlSelf->sim_top__DOT__soc__DOT__rst) {
        vlSelf->sim_top__DOT__soc__DOT__zm_wdata = 0U;
    } else if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__rd_start)))) {
        if (vlSelf->sim_top__DOT__soc__DOT__sub__DOT__wr_end) {
            vlSelf->sim_top__DOT__soc__DOT__zm_wdata 
                = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__wr_data;
        }
    }
    if (vlSelf->sim_top__DOT__soc__DOT__sub__DOT__mem_wrc) {
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__wr_data 
            = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__dout;
    }
    vlSelf->sim_top__DOT__soc__DOT__xl_acc = ((IData)(vlSelf->sim_top__DOT__soc__DOT____VdfgTmp_h20f74f65__0) 
                                              & (IData)(vlSelf->sim_top__DOT__soc__DOT__io_xl));
    vlSelf->sim_top__DOT__soc__DOT__tp = vlSelf->__Vdly__sim_top__DOT__soc__DOT__tp;
    vlSelf->sim_top__DOT__soc__DOT__cw = vlSelf->__Vdly__sim_top__DOT__soc__DOT__cw;
    vlSelf->sim_top__DOT__soc__DOT__disk_busy = ((IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__exec) 
                                                 | (IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__pend));
    vlSelf->sim_top__DOT__soc__DOT__cs_ = vlSelf->__Vdly__sim_top__DOT__soc__DOT__cs_;
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx 
        = vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx;
    if (vlSelf->sim_top__DOT__soc__DOT__rst) {
        vlSelf->sim_top__DOT__soc__DOT__win_wdata = 0U;
        vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__st = 0U;
        vlSelf->sim_top__DOT__soc__DOT__ld_done = 0U;
        vlSelf->kanji_ok = 0U;
        vlSelf->fl_cs = 1U;
    } else if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__loader__DOT__st))) {
        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__loader__DOT__st))) {
            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__loader__DOT__st))) {
                vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__st = 0U;
            } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__loader__DOT__st))) {
                if ((0U == (IData)(vlSelf->sim_top__DOT__soc__DOT__loader__DOT__pw))) {
                    vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__pi 
                        = (0xfU & ((IData)(1U) + (IData)(vlSelf->sim_top__DOT__soc__DOT__loader__DOT__pi)));
                    vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__st = 0xbU;
                } else {
                    vlSelf->sim_top__DOT__soc__DOT__loader__DOT__pw 
                        = (0x3fffU & ((IData)(vlSelf->sim_top__DOT__soc__DOT__loader__DOT__pw) 
                                      - (IData)(1U)));
                }
            } else if (vlSelf->sim_top__DOT__soc__DOT__loader__DOT__sdone) {
                vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__pi 
                    = (0xfU & ((IData)(1U) + (IData)(vlSelf->sim_top__DOT__soc__DOT__loader__DOT__pi)));
                vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__st = 0xbU;
            }
        } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__loader__DOT__st))) {
            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__loader__DOT__st))) {
                if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__loader__DOT__pi))) {
                    if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__loader__DOT__pi))) {
                        vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__cmd = 0x3100000U;
                        vlSelf->fl_cs = 0U;
                        vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__ci = 0U;
                        vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__n = 0U;
                        vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__st = 2U;
                    } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__loader__DOT__pi))) {
                        vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__cmd = 0x3100000U;
                        vlSelf->fl_cs = 0U;
                        vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__ci = 0U;
                        vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__n = 0U;
                        vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__st = 2U;
                    } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__loader__DOT__pi))) {
                        vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__cmd = 0x3100000U;
                        vlSelf->fl_cs = 0U;
                        vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__ci = 0U;
                        vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__n = 0U;
                        vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__st = 2U;
                    } else {
                        vlSelf->fl_cs = 1U;
                        vlSelf->sim_top__DOT__soc__DOT__loader__DOT__pw = 0x2ee0U;
                        vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__st = 0xdU;
                    }
                } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__loader__DOT__pi))) {
                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__loader__DOT__pi))) {
                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__loader__DOT__pi))) {
                            vlSelf->fl_cs = 0U;
                            vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__stx = 0x99U;
                            __Vdly__sim_top__DOT__soc__DOT__loader__DOT__sgo = 1U;
                            vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__st = 0xcU;
                        } else {
                            vlSelf->fl_cs = 1U;
                            vlSelf->sim_top__DOT__soc__DOT__loader__DOT__pw = 0xc8U;
                            vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__st = 0xdU;
                        }
                    } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__loader__DOT__pi))) {
                        vlSelf->fl_cs = 0U;
                        vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__stx = 0x66U;
                        __Vdly__sim_top__DOT__soc__DOT__loader__DOT__sgo = 1U;
                        vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__st = 0xcU;
                    } else {
                        vlSelf->fl_cs = 1U;
                        vlSelf->sim_top__DOT__soc__DOT__loader__DOT__pw = 0xfa0U;
                        vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__st = 0xdU;
                    }
                } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__loader__DOT__pi))) {
                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__loader__DOT__pi))) {
                        vlSelf->fl_cs = 0U;
                        vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__stx = 0xabU;
                        __Vdly__sim_top__DOT__soc__DOT__loader__DOT__sgo = 1U;
                        vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__st = 0xcU;
                    } else {
                        vlSelf->fl_cs = 1U;
                        vlSelf->sim_top__DOT__soc__DOT__loader__DOT__pw = 0xfa0U;
                        vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__st = 0xdU;
                    }
                } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__loader__DOT__pi))) {
                    vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__stx = 0xffU;
                    __Vdly__sim_top__DOT__soc__DOT__loader__DOT__sgo = 1U;
                    vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__st = 0xcU;
                } else {
                    vlSelf->fl_cs = 0U;
                    vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__stx = 0xffU;
                    __Vdly__sim_top__DOT__soc__DOT__loader__DOT__sgo = 1U;
                    vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__st = 0xcU;
                }
            } else {
                vlSelf->fl_cs = 1U;
                vlSelf->sim_top__DOT__soc__DOT__ld_done = 1U;
                vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__st = 0U;
            }
        } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__loader__DOT__st))) {
            vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__n 
                = (0x3ffffU & ((IData)(1U) + vlSelf->sim_top__DOT__soc__DOT__loader__DOT__n));
            if (vlSelf->sim_top__DOT__soc__DOT__loader__DOT__n_last) {
                vlSelf->kanji_ok = 1U;
                vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__st = 0xaU;
            } else {
                vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__st = 4U;
            }
        } else if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__m0_req)))) {
            vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__st = 9U;
        }
    } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__loader__DOT__st))) {
        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__loader__DOT__st))) {
            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__loader__DOT__st))) {
                vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__st = 8U;
            } else if (((IData)(vlSelf->sim_top__DOT__soc__DOT__loader__DOT__n_lt4) 
                        & ((IData)(vlSelf->sim_top__DOT__soc__DOT__loader__DOT__srx) 
                           != (IData)(vlSelf->sim_top__DOT__soc__DOT__loader__DOT__magic)))) {
                if ((7U == (IData)(vlSelf->sim_top__DOT__soc__DOT__loader__DOT__tries))) {
                    vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__st = 0xaU;
                } else {
                    vlSelf->sim_top__DOT__soc__DOT__loader__DOT__tries 
                        = (0xfU & ((IData)(1U) + (IData)(vlSelf->sim_top__DOT__soc__DOT__loader__DOT__tries)));
                    vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__pi = 0xfU;
                    vlSelf->fl_cs = 1U;
                    vlSelf->sim_top__DOT__soc__DOT__loader__DOT__pw = 0x3e8U;
                    vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__st = 0xdU;
                }
            } else {
                vlSelf->sim_top__DOT__soc__DOT__ld_data 
                    = vlSelf->sim_top__DOT__soc__DOT__loader__DOT__srx;
                vlSelf->sim_top__DOT__soc__DOT__ld_wr = 1U;
                vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__st = 7U;
            }
        } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__loader__DOT__st))) {
            if (vlSelf->sim_top__DOT__soc__DOT__loader__DOT__sdone) {
                vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__st = 6U;
            }
        } else {
            vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__stx = 0xffU;
            __Vdly__sim_top__DOT__soc__DOT__loader__DOT__sgo = 1U;
            vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__st = 5U;
        }
    } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__loader__DOT__st))) {
        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__loader__DOT__st))) {
            if (vlSelf->sim_top__DOT__soc__DOT__loader__DOT__sdone) {
                vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__st = 2U;
            }
        } else if ((4U == (IData)(vlSelf->sim_top__DOT__soc__DOT__loader__DOT__ci))) {
            vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__st = 4U;
        } else {
            vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__ci 
                = (7U & ((IData)(1U) + (IData)(vlSelf->sim_top__DOT__soc__DOT__loader__DOT__ci)));
            vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__stx 
                = (vlSelf->sim_top__DOT__soc__DOT__loader__DOT__cmd 
                   >> 0x18U);
            __Vdly__sim_top__DOT__soc__DOT__loader__DOT__sgo = 1U;
            vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__st = 3U;
            vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__cmd 
                = (vlSelf->sim_top__DOT__soc__DOT__loader__DOT__cmd 
                   << 8U);
        }
    } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__loader__DOT__st))) {
        vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__st = 0U;
    } else if (vlSelf->sim_top__DOT__soc__DOT__ld_start) {
        vlSelf->sim_top__DOT__soc__DOT__loader__DOT__tries = 0U;
        vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__pi = 0U;
        vlSelf->sim_top__DOT__soc__DOT__ld_done = 0U;
        vlSelf->kanji_ok = 0U;
        vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__st = 0xbU;
    }
    vlSelf->sim_top__DOT__soc__DOT__ld_start = __Vdly__sim_top__DOT__soc__DOT__ld_start;
    vlSelf->sim_top__DOT__soc__DOT__loader__DOT__st 
        = vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__st;
    vlSelf->sim_top__DOT__soc__DOT__loader__DOT__pi 
        = vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__pi;
    vlSelf->sim_top__DOT__soc__DOT__loader__DOT__cmd 
        = vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__cmd;
    vlSelf->sim_top__DOT__soc__DOT__loader__DOT__ci 
        = vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__ci;
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__b_q 
        = vlSelf->sim_top__DOT__soc__DOT__disk__DOT__bram
        [vlSelf->sim_top__DOT__soc__DOT__disk__DOT__b_raddr];
    vlSelf->led = (0x3fU & (~ (((IData)(vlSelf->sim_top__DOT__soc__DOT__pwroff) 
                                << 5U) | (((IData)(vlSelf->sim_top__DOT__soc__DOT__osrun) 
                                           << 4U) | 
                                          (((IData)(vlSelf->sim_top__DOT__soc__DOT__disk__DOT__exec) 
                                            << 3U) 
                                           | ((4U & 
                                               (((IData)(vlSelf->sim_top__DOT__soc__DOT__sd_fail)
                                                  ? 
                                                 (vlSelf->sim_top__DOT__soc__DOT__hb 
                                                  >> 0x16U)
                                                  : (IData)(vlSelf->sim_top__DOT__soc__DOT__sd_ready)) 
                                                << 2U)) 
                                              | (((IData)(vlSelf->sim_top__DOT__soc__DOT__run) 
                                                  << 1U) 
                                                 | (1U 
                                                    & (vlSelf->sim_top__DOT__soc__DOT__hb 
                                                       >> 0x17U)))))))));
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__ei 
        = (0x7fU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx));
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__win_sel 
        = (0xdU == (0x7fU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx)));
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__ext_rd 
        = ((0x40U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx))
            ? 0xffU : ((0x20U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx))
                        ? 0xffU : (0xffU & ((0x10U 
                                             & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx))
                                             ? ((8U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx))
                                                 ? 0xffU
                                                 : 
                                                ((4U 
                                                  & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx))
                                                  ? 0xffU
                                                  : 
                                                 ((2U 
                                                   & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx))
                                                    ? vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__clk_latch
                                                    : 
                                                   (vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__clk_latch 
                                                    >> 8U))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx))
                                                    ? 
                                                   (vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__clk_latch 
                                                    >> 0x10U)
                                                    : 
                                                   (vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__clk_cnt 
                                                    >> 0x18U)))))
                                             : ((8U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx))
                                                 ? 
                                                ((4U 
                                                  & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx))
                                                  ? 
                                                 ((2U 
                                                   & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx))
                                                    ? 0x4cU
                                                    : 0x1dU)
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx))
                                                    ? (IData)(vlSelf->sim_top__DOT__soc__DOT__win_rdata)
                                                    : vlSelf->sim_top__DOT__soc__DOT__win_addr))
                                                  : 
                                                 ((2U 
                                                   & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx))
                                                    ? 
                                                   (vlSelf->sim_top__DOT__soc__DOT__win_addr 
                                                    >> 8U)
                                                    : 
                                                   (0x1fU 
                                                    & (vlSelf->sim_top__DOT__soc__DOT__win_addr 
                                                       >> 0x10U)))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx))
                                                    ? 
                                                   vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__smmu
                                                   [vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__mi]
                                                    : (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__mi))))
                                                 : 
                                                ((4U 
                                                  & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx))
                                                  ? 
                                                 ((2U 
                                                   & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx))
                                                    ? (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__s2m3)
                                                    : (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__s2m2))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx))
                                                    ? (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__s2m1)
                                                    : (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__s2m0)))
                                                  : 
                                                 ((2U 
                                                   & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx))
                                                    ? (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__m2s3)
                                                    : (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__m2s2))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__idx))
                                                    ? (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__m2s1)
                                                    : (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__m2s0)))))))));
    vlSelf->sim_top__DOT__soc__DOT__m_wr_s = ((IData)(vlSelf->sim_top__DOT__soc__DOT__run)
                                               ? ((IData)(vlSelf->sim_top__DOT__soc__DOT__xw_act)
                                                   ? (IData)(vlSelf->sim_top__DOT__soc__DOT__xw_wrp)
                                                   : 
                                                  ((IData)(vlSelf->sim_top__DOT__soc__DOT__disk_sel)
                                                    ? (IData)(vlSelf->sim_top__DOT__soc__DOT__d_wr)
                                                    : (IData)(vlSelf->sim_top__DOT__soc__DOT__c_cwr)))
                                               : ((IData)(vlSelf->sim_top__DOT__soc__DOT__c_wr) 
                                                  | (IData)(vlSelf->sim_top__DOT__soc__DOT__ld_wr)));
    vlSelf->sim_top__DOT__soc__DOT__loader__DOT__n_last 
        = (0x2d5ffU == vlSelf->sim_top__DOT__soc__DOT__loader__DOT__n);
    vlSelf->sim_top__DOT__soc__DOT__loader__DOT__n_lt4 
        = (0U == (0xffffU & (vlSelf->sim_top__DOT__soc__DOT__loader__DOT__n 
                             >> 2U)));
    vlSelf->sim_top__DOT__soc__DOT__loader__DOT__magic 
        = ((0U == (3U & vlSelf->sim_top__DOT__soc__DOT__loader__DOT__n))
            ? 0x4bU : ((1U == (3U & vlSelf->sim_top__DOT__soc__DOT__loader__DOT__n))
                        ? 0x4aU : ((2U == (3U & vlSelf->sim_top__DOT__soc__DOT__loader__DOT__n))
                                    ? 0x46U : 0x31U)));
    if (vlSelf->sim_top__DOT__soc__DOT__m0_ack) {
        vlSelf->sim_top__DOT__soc__DOT__m0_req = 0U;
    }
    if (vlSelf->sim_top__DOT__soc__DOT__m0_pulse) {
        vlSelf->sim_top__DOT__soc__DOT__m0_req = 1U;
    }
    vlSelf->sim_top__DOT__soc__DOT__loader__DOT__sdone = 0U;
    if (vlSelf->sim_top__DOT__soc__DOT__rst) {
        vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__sbusy = 0U;
        vlSelf->__Vdly__fl_clk = 0U;
        vlSelf->fl_mosi = 1U;
    } else if (vlSelf->sim_top__DOT__soc__DOT__loader__DOT__sbusy) {
        if ((1U != (IData)(vlSelf->sim_top__DOT__soc__DOT__loader__DOT__hc))) {
            vlSelf->sim_top__DOT__soc__DOT__loader__DOT__hc 
                = (3U & ((IData)(1U) + (IData)(vlSelf->sim_top__DOT__soc__DOT__loader__DOT__hc)));
        } else {
            vlSelf->sim_top__DOT__soc__DOT__loader__DOT__hc = 0U;
            if (vlSelf->fl_clk) {
                vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__bcnt 
                    = (7U & ((IData)(1U) + (IData)(vlSelf->sim_top__DOT__soc__DOT__loader__DOT__bcnt)));
                vlSelf->__Vdly__fl_clk = 0U;
                vlSelf->fl_mosi = (1U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__loader__DOT__sh_out) 
                                         >> 7U));
                if ((7U == (IData)(vlSelf->sim_top__DOT__soc__DOT__loader__DOT__bcnt))) {
                    vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__sbusy = 0U;
                    vlSelf->sim_top__DOT__soc__DOT__loader__DOT__sdone = 1U;
                    vlSelf->sim_top__DOT__soc__DOT__loader__DOT__srx 
                        = vlSelf->sim_top__DOT__soc__DOT__loader__DOT__sh_in;
                }
                vlSelf->sim_top__DOT__soc__DOT__loader__DOT__sh_out 
                    = (1U | (0xfeU & ((IData)(vlSelf->sim_top__DOT__soc__DOT__loader__DOT__sh_out) 
                                      << 1U)));
            } else {
                vlSelf->sim_top__DOT__soc__DOT__loader__DOT__sh_in 
                    = ((0xfeU & ((IData)(vlSelf->sim_top__DOT__soc__DOT__loader__DOT__sh_in) 
                                 << 1U)) | (IData)(vlSelf->fl_miso));
                vlSelf->__Vdly__fl_clk = 1U;
            }
        }
    } else {
        vlSelf->__Vdly__fl_clk = 0U;
        if (vlSelf->sim_top__DOT__soc__DOT__loader__DOT__sgo) {
            vlSelf->sim_top__DOT__soc__DOT__loader__DOT__sh_out 
                = (1U | (0xfeU & ((IData)(vlSelf->sim_top__DOT__soc__DOT__loader__DOT__stx) 
                                  << 1U)));
            vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__sbusy = 1U;
            vlSelf->fl_mosi = (1U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__loader__DOT__stx) 
                                     >> 7U));
            vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__bcnt = 0U;
            vlSelf->sim_top__DOT__soc__DOT__loader__DOT__hc = 0U;
        }
    }
    vlSelf->sim_top__DOT__soc__DOT__disk__DOT__b_raddr 
        = vlSelf->__Vdly__sim_top__DOT__soc__DOT__disk__DOT__b_raddr;
    if (vlSelf->__Vdlyvset__sim_top__DOT__soc__DOT__disk__DOT__bram__v0) {
        vlSelf->sim_top__DOT__soc__DOT__disk__DOT__bram[vlSelf->__Vdlyvdim0__sim_top__DOT__soc__DOT__disk__DOT__bram__v0] 
            = vlSelf->__Vdlyvval__sim_top__DOT__soc__DOT__disk__DOT__bram__v0;
    }
    vlSelf->sim_top__DOT__soc__DOT__loader__DOT__n 
        = vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__n;
    vlSelf->sim_top__DOT__soc__DOT__m0_ack = __Vdly__sim_top__DOT__soc__DOT__m0_ack;
    vlSelf->sim_top__DOT__soc__DOT__m0_pulse = (((IData)(vlSelf->sim_top__DOT__soc__DOT__run)
                                                  ? 
                                                 ((IData)(vlSelf->sim_top__DOT__soc__DOT__xw_act)
                                                   ? (IData)(vlSelf->sim_top__DOT__soc__DOT__xw_rdp)
                                                   : 
                                                  ((IData)(vlSelf->sim_top__DOT__soc__DOT__disk_sel)
                                                    ? (IData)(vlSelf->sim_top__DOT__soc__DOT__d_rd)
                                                    : (IData)(vlSelf->sim_top__DOT__soc__DOT__c_rd)))
                                                  : (IData)(vlSelf->sim_top__DOT__soc__DOT__t_rd)) 
                                                | (IData)(vlSelf->sim_top__DOT__soc__DOT__m_wr_s));
    vlSelf->sim_top__DOT__soc__DOT__loader__DOT__sgo 
        = __Vdly__sim_top__DOT__soc__DOT__loader__DOT__sgo;
    vlSelf->sim_top__DOT__soc__DOT__loader__DOT__stx 
        = vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__stx;
    vlSelf->sim_top__DOT__soc__DOT__loader__DOT__sbusy 
        = vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__sbusy;
    vlSelf->fl_clk = vlSelf->__Vdly__fl_clk;
    vlSelf->sim_top__DOT__soc__DOT__loader__DOT__bcnt 
        = vlSelf->__Vdly__sim_top__DOT__soc__DOT__loader__DOT__bcnt;
}
