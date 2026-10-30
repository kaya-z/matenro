// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsim_top.h for the primary calling header

#include "verilated.h"

#include "Vsim_top___024root.h"

VL_INLINE_OPT void Vsim_top___024root___nba_sequent__TOP__11(Vsim_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___nba_sequent__TOP__11\n"); );
    // Init
    SData/*15:0*/ sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__PC16_B;
    sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__PC16_B = 0;
    // Body
    if ((0x20U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
        if (((0x36U == (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)) 
             | (0xcbU == (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 7U;
        }
    }
    if ((0x40U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 5U;
        if ((1U != (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ISet))) {
            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
        }
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
            = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__SSS;
    }
    sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__PC16_B 
        = ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__JumpE)
            ? ((0xff00U & ((- (IData)((1U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__di_reg) 
                                             >> 7U)))) 
                           << 8U)) | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__di_reg))
            : ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__BTR_r)
                ? 0xfffeU : 1U));
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__PC16 
        = (0xffffU & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__PC) 
                      + (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__PC16_B)));
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__last_tstate 
        = (1U & ((0U == (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates))
                  ? (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstate)
                  : ((1U == (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates))
                      ? ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstate) 
                         >> 1U) : ((2U == (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates))
                                    ? ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstate) 
                                       >> 2U) : ((3U 
                                                  == (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates))
                                                  ? 
                                                 ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstate) 
                                                  >> 3U)
                                                  : 
                                                 ((4U 
                                                   == (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates))
                                                   ? 
                                                  ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstate) 
                                                   >> 4U)
                                                   : 
                                                  ((5U 
                                                    == (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates))
                                                    ? 
                                                   ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstate) 
                                                    >> 5U)
                                                    : 
                                                   ((6U 
                                                     == (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates)) 
                                                    & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstate) 
                                                       >> 6U)))))))));
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__NextIs_XY_Fetch 
        = (((0U != (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__XY_State)) 
            & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__XY_Ind))) 
           & (((2U == (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To)) 
               | ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                  & (0xcbU == (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) 
              | ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                 & (0x36U == (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))));
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegWEH = 0U;
    if ((1U & (((((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstate) 
                  >> 1U) & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU_r))) 
                & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Auto_Wait_t1))) 
               | ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU_r) 
                  & (7U != (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op_r)))))) {
        if ((0x10U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg_r))) {
            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg_r) 
                          >> 3U)))) {
                if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg_r))) {
                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg_r) 
                                  >> 1U)))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegWEH 
                            = (1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg_r)));
                    }
                } else {
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegWEH 
                        = (1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg_r)));
                }
            }
        }
    }
    if (((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ExchangeDH) 
         & (IData)((0U != (0x18U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstate)))))) {
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegWEH = 1U;
    }
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegWEL = 0U;
    if ((1U & (((((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstate) 
                  >> 1U) & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU_r))) 
                & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Auto_Wait_t1))) 
               | ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU_r) 
                  & (7U != (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op_r)))))) {
        if ((0x10U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg_r))) {
            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg_r) 
                          >> 3U)))) {
                if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg_r))) {
                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg_r) 
                                  >> 1U)))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegWEL 
                            = (1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg_r));
                    }
                } else {
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegWEL 
                        = (1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg_r));
                }
            }
        }
    }
    if (((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ExchangeDH) 
         & (IData)((0U != (0x18U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstate)))))) {
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegWEL = 1U;
    }
    if ((1U & (((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16) 
                >> 2U) & ((((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstate) 
                            >> 2U) & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) 
                          | (((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstate) 
                              >> 3U) & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))))) {
        if ((((0U == (3U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16))) 
              | (1U == (3U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16)))) 
             | (2U == (3U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16))))) {
            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegWEH = 1U;
            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegWEL = 1U;
        }
    }
}

VL_INLINE_OPT void Vsim_top___024root___nba_comb__TOP__6(Vsim_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___nba_comb__TOP__6\n"); );
    // Init
    CData/*2:0*/ sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegAddrB;
    sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegAddrB = 0;
    SData/*15:0*/ sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ID16_B;
    sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ID16_B = 0;
    CData/*0:0*/ sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__UseCarry;
    sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__UseCarry = 0;
    CData/*0:0*/ sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__Carry7_v;
    sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__Carry7_v = 0;
    CData/*0:0*/ sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__OverFlow_v;
    sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__OverFlow_v = 0;
    CData/*0:0*/ sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__HalfCarry_v;
    sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__HalfCarry_v = 0;
    CData/*0:0*/ sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__Carry_v;
    sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__Carry_v = 0;
    CData/*7:0*/ sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__Q_v;
    sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__Q_v = 0;
    CData/*1:0*/ sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__addsub1;
    sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__addsub1 = 0;
    CData/*3:0*/ sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__addsub3;
    sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__addsub3 = 0;
    CData/*4:0*/ sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__addsub4;
    sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__addsub4 = 0;
    CData/*7:0*/ sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t;
    sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t = 0;
    SData/*8:0*/ sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q;
    sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q = 0;
    CData/*4:0*/ __Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__100__Vfuncout;
    __Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__100__Vfuncout = 0;
    CData/*3:0*/ __Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__100__A;
    __Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__100__A = 0;
    CData/*3:0*/ __Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__100__B;
    __Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__100__B = 0;
    CData/*0:0*/ __Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__100__Sub;
    __Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__100__Sub = 0;
    CData/*0:0*/ __Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__100__Carry_In;
    __Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__100__Carry_In = 0;
    CData/*3:0*/ __Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__101__Vfuncout;
    __Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__101__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__101__A;
    __Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__101__A = 0;
    CData/*2:0*/ __Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__101__B;
    __Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__101__B = 0;
    CData/*0:0*/ __Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__101__Sub;
    __Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__101__Sub = 0;
    CData/*0:0*/ __Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__101__Carry_In;
    __Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__101__Carry_In = 0;
    CData/*1:0*/ __Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__102__Vfuncout;
    __Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__102__Vfuncout = 0;
    CData/*0:0*/ __Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__102__A;
    __Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__102__A = 0;
    CData/*0:0*/ __Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__102__B;
    __Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__102__B = 0;
    CData/*0:0*/ __Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__102__Sub;
    __Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__102__Sub = 0;
    CData/*0:0*/ __Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__102__Carry_In;
    __Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__102__Carry_In = 0;
    // Body
    if (vlSelf->sim_top__DOT__soc__DOT__sub__DOT__s_we) {
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT____Vcellinp__xl__s_we 
            = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__port_ok;
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__s_port 
            = (0xfU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__a_q));
    } else {
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT____Vcellinp__xl__s_we = 0U;
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__s_port 
            = (0xfU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__A));
    }
    sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__UseCarry 
        = (IData)((1U == (5U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op_r))));
    __Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__100__Carry_In 
        = (1U & (((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op_r) 
                  >> 1U) ^ ((IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__UseCarry) 
                            & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F))));
    __Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__100__Sub 
        = (1U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op_r) 
                 >> 1U));
    __Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__100__B 
        = (0xfU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__BusB));
    __Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__100__A 
        = (0xfU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__BusA));
    __Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__100__Vfuncout 
        = (0x1fU & (((IData)(__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__100__A) 
                     + (0xfU & ((IData)(__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__100__Sub)
                                 ? (~ (IData)(__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__100__B))
                                 : (IData)(__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__100__B)))) 
                    + (IData)(__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__100__Carry_In)));
    sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__addsub4 
        = __Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__100__Vfuncout;
    sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__HalfCarry_v 
        = (1U & ((IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__addsub4) 
                 >> 4U));
    __Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__101__Carry_In 
        = sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__HalfCarry_v;
    __Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__101__Sub 
        = (1U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op_r) 
                 >> 1U));
    __Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__101__B 
        = (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__BusB) 
                 >> 4U));
    __Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__101__A 
        = (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__BusA) 
                 >> 4U));
    __Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__101__Vfuncout 
        = (0xfU & (((IData)(__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__101__A) 
                    + (7U & ((IData)(__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__101__Sub)
                              ? (~ (IData)(__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__101__B))
                              : (IData)(__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__101__B)))) 
                   + (IData)(__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__101__Carry_In)));
    sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__addsub3 
        = __Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__101__Vfuncout;
    sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__Carry7_v 
        = (1U & ((IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__addsub3) 
                 >> 3U));
    __Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__102__Carry_In 
        = sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__Carry7_v;
    __Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__102__Sub 
        = (1U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op_r) 
                 >> 1U));
    __Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__102__B 
        = (1U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__BusB) 
                 >> 7U));
    __Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__102__A 
        = (1U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__BusA) 
                 >> 7U));
    __Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__102__Vfuncout 
        = (3U & (((IData)(__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__102__A) 
                  + (1U & ((IData)(__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__102__Sub)
                            ? (~ (IData)(__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__102__B))
                            : (IData)(__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__102__B)))) 
                 + (IData)(__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__102__Carry_In)));
    sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__addsub1 
        = __Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__102__Vfuncout;
    sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__Carry_v 
        = (1U & ((IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__addsub1) 
                 >> 1U));
    sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__Q_v 
        = ((0x80U & ((IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__addsub1) 
                     << 7U)) | ((0x70U & ((IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__addsub3) 
                                          << 4U)) | 
                                (0xfU & (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__addsub4))));
    sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__OverFlow_v 
        = ((IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__Carry_v) 
           ^ (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__Carry7_v));
    if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstate))) {
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__SP16_A 
            = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegBusC;
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__SP16_B 
            = ((0xff00U & ((- (IData)((1U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__di_reg) 
                                             >> 7U)))) 
                           << 8U)) | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__di_reg));
    } else {
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__SP16_A 
            = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__SP;
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__SP16_B 
            = ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16))
                ? 0xffffU : 1U);
    }
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__SP16 
        = (0xffffU & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__SP16_A) 
                      + (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__SP16_B)));
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegAddrA 
        = (((((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstate) 
              >> 2U) | ((((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstate) 
                          >> 3U) & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)) 
                        & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16) 
                           >> 2U))) & (0U == (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__XY_State)))
            ? (((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Alternate) 
                << 2U) | (3U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16)))
            : (((((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstate) 
                  >> 2U) | ((((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstate) 
                              >> 3U) & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)) 
                            & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16) 
                               >> 2U))) & (2U == (3U 
                                                  & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16))))
                ? (3U | (4U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__XY_State) 
                               << 1U))) : (((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ExchangeDH) 
                                            & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstate) 
                                               >> 3U))
                                            ? (2U | 
                                               ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Alternate) 
                                                << 2U))
                                            : (((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ExchangeDH) 
                                                & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstate) 
                                                   >> 4U))
                                                ? (1U 
                                                   | ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Alternate) 
                                                      << 2U))
                                                : (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegAddrA_r)))));
    sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t = 0U;
    sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q = 0U;
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out 
        = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F;
    if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op_r))) {
        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op_r))) {
            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op_r))) {
                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op_r)))) {
                    sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t 
                        = ((0xf0U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__BusA)) 
                           | (0xfU & ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op_r))
                                       ? ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__BusB) 
                                          >> 4U) : (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__BusB))));
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out 
                        = (0xefU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out));
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out 
                        = (0xfdU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out));
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out 
                        = ((0xf7U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out)) 
                           | (8U & (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t)));
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out 
                        = ((0x1fU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out)) 
                           | ((0x80U & (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t)) 
                              | (((0U == (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t)) 
                                  << 6U) | (0x20U & (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t)))));
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out 
                        = ((0xfbU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out)) 
                           | (4U & ((~ VL_REDXOR_8(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t)) 
                                    << 2U)));
                }
            } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op_r))) {
                sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t 
                    = ((0xf0U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__BusA)) 
                       | (0xfU & ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op_r))
                                   ? ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__BusB) 
                                      >> 4U) : (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__BusB))));
                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out 
                    = (0xefU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out));
                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out 
                    = (0xfdU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out));
                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out 
                    = ((0xf7U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out)) 
                       | (8U & (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t)));
                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out 
                    = ((0x1fU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out)) 
                       | ((0x80U & (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t)) 
                          | (((0U == (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t)) 
                              << 6U) | (0x20U & (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t)))));
                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out 
                    = ((0xfbU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out)) 
                       | (4U & ((~ VL_REDXOR_8(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t)) 
                                << 2U)));
            } else {
                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out 
                    = ((0xefU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out)) 
                       | (0x10U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F)));
                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out 
                    = ((0xfeU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out)) 
                       | (1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F)));
                sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q 
                    = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__BusA;
                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F))) {
                    if ((1U & ((9U < (0xfU & (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q))) 
                               | ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F) 
                                  >> 4U)))) {
                        if ((5U < (0xfU & (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q)))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out 
                                = (0xefU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out));
                        }
                        sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q 
                            = ((0x100U & (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q)) 
                               | (0xffU & ((IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q) 
                                           - (IData)(6U))));
                    }
                    if ((1U & ((0x99U < (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__BusA)) 
                               | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F)))) {
                        sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q 
                            = (0x1ffU & ((IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q) 
                                         - (IData)(0x160U)));
                    }
                } else {
                    if ((1U & ((9U < (0xfU & (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q))) 
                               | ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F) 
                                  >> 4U)))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out 
                            = ((0xefU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out)) 
                               | ((9U < (0xfU & (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q))) 
                                  << 4U));
                        sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q 
                            = (0x1ffU & ((IData)(6U) 
                                         + (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q)));
                    }
                    if ((1U & ((9U < (0x1fU & ((IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q) 
                                               >> 4U))) 
                               | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F)))) {
                        sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q 
                            = (0x1ffU & ((IData)(0x60U) 
                                         + (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q)));
                    }
                }
                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out 
                    = ((0xf7U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out)) 
                       | (8U & (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q)));
                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out 
                    = ((0xdfU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out)) 
                       | (0x20U & (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q)));
                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out 
                    = ((0xfeU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out)) 
                       | (1U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F) 
                                | ((IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q) 
                                   >> 8U))));
                sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t 
                    = (0xffU & (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q));
                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out 
                    = ((0x3fU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out)) 
                       | ((0x80U & (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q)) 
                          | ((0U == (0xffU & (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q))) 
                             << 6U)));
                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out 
                    = ((0xfbU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out)) 
                       | (4U & ((~ VL_REDXOR_32((0xffU 
                                                 & (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q)))) 
                                << 2U)));
            }
        } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op_r))) {
            sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t 
                = ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op_r))
                    ? ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__BusB) 
                       & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__BitMask)))
                    : ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__BusB) 
                       | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__BitMask)));
        } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op_r))) {
            sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t 
                = ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__BusB) 
                   & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__BitMask));
            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out 
                = ((0x7fU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out)) 
                   | (0x80U & (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t)));
            if ((0U == (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t))) {
                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out 
                    = (0x40U | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out));
                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out 
                    = (4U | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out));
            } else {
                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out 
                    = (0xbfU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out));
                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out 
                    = (0xfbU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out));
            }
            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out 
                = (0x10U | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out));
            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out 
                = (0xfdU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out));
            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out 
                = (0xf7U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out));
            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out 
                = (0xdfU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out));
            if ((6U != (7U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out 
                    = ((0xf7U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out)) 
                       | (8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__BusB)));
                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out 
                    = ((0xdfU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out)) 
                       | (0x20U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__BusB)));
            }
        } else {
            if ((0x20U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                if ((0x10U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t 
                            = (0x7fU & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__BusA) 
                                        >> 1U));
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out 
                            = ((0xfeU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out)) 
                               | (1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__BusA)));
                    } else {
                        sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t 
                            = (1U | (0xfeU & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__BusA) 
                                              << 1U)));
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out 
                            = ((0xfeU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out)) 
                               | (1U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__BusA) 
                                        >> 7U)));
                    }
                } else if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t 
                        = ((0x80U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__BusA)) 
                           | (0x7fU & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__BusA) 
                                       >> 1U)));
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out 
                        = ((0xfeU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out)) 
                           | (1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__BusA)));
                } else {
                    sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t 
                        = (0xfeU & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__BusA) 
                                    << 1U));
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out 
                        = ((0xfeU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out)) 
                           | (1U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__BusA) 
                                    >> 7U)));
                }
            } else if ((0x10U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t 
                        = ((0x80U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F) 
                                     << 7U)) | (0x7fU 
                                                & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__BusA) 
                                                   >> 1U)));
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out 
                        = ((0xfeU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out)) 
                           | (1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__BusA)));
                } else {
                    sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t 
                        = ((0xfeU & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__BusA) 
                                     << 1U)) | (1U 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F)));
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out 
                        = ((0xfeU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out)) 
                           | (1U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__BusA) 
                                    >> 7U)));
                }
            } else if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t 
                    = ((0x80U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__BusA) 
                                 << 7U)) | (0x7fU & 
                                            ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__BusA) 
                                             >> 1U)));
                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out 
                    = ((0xfeU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out)) 
                       | (1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__BusA)));
            } else {
                sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t 
                    = ((0xfeU & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__BusA) 
                                 << 1U)) | (1U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__BusA) 
                                                  >> 7U)));
                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out 
                    = ((0xfeU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out)) 
                       | (1U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__BusA) 
                                >> 7U)));
            }
            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out 
                = (0xefU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out));
            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out 
                = (0xfdU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out));
            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out 
                = ((0xf7U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out)) 
                   | (8U & (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t)));
            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out 
                = ((0x1fU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out)) 
                   | ((0x80U & (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t)) 
                      | (((0U == (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t)) 
                          << 6U) | (0x20U & (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t)))));
            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out 
                = ((0xfbU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out)) 
                   | (4U & ((~ VL_REDXOR_8(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t)) 
                            << 2U)));
            if ((0U == (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ISet))) {
                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out 
                    = ((0xfbU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out)) 
                       | (4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F)));
                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out 
                    = ((0x3fU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out)) 
                       | (0xc0U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F)));
            }
        }
    } else {
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out 
            = (0xfcU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out));
        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op_r))) {
            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op_r))) {
                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op_r))) {
                    sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t 
                        = sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__Q_v;
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out 
                        = ((0xfcU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out)) 
                           | (2U | (1U & (~ (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__Carry_v)))));
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out 
                        = ((0xefU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out)) 
                           | (0x10U & ((~ (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__HalfCarry_v)) 
                                       << 4U)));
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out 
                        = ((0xfbU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out)) 
                           | ((IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__OverFlow_v) 
                              << 2U));
                } else {
                    sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t 
                        = ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__BusA) 
                           | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__BusB));
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out 
                        = (0xefU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out));
                }
            } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op_r))) {
                sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t 
                    = ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__BusA) 
                       ^ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__BusB));
                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out 
                    = (0xefU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out));
            } else {
                sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t 
                    = ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__BusA) 
                       & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__BusB));
                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out 
                    = (0x10U | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out));
            }
        } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op_r))) {
            sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t 
                = sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__Q_v;
            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out 
                = ((0xfcU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out)) 
                   | (2U | (1U & (~ (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__Carry_v)))));
            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out 
                = ((0xefU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out)) 
                   | (0x10U & ((~ (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__HalfCarry_v)) 
                               << 4U)));
            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out 
                = ((0xfbU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out)) 
                   | ((IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__OverFlow_v) 
                      << 2U));
        } else {
            sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t 
                = sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__Q_v;
            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out 
                = ((0xfeU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out)) 
                   | (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__Carry_v));
            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out 
                = ((0xefU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out)) 
                   | ((IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__HalfCarry_v) 
                      << 4U));
            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out 
                = ((0xfbU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out)) 
                   | ((IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__OverFlow_v) 
                      << 2U));
        }
        if ((7U == (7U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op_r)))) {
            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out 
                = ((0xf7U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out)) 
                   | (8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__BusB)));
            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out 
                = ((0xdfU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out)) 
                   | (0x20U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__BusB)));
        } else {
            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out 
                = ((0xf7U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out)) 
                   | (8U & (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t)));
            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out 
                = ((0xdfU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out)) 
                   | (0x20U & (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t)));
        }
        if ((0U == (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t))) {
            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out 
                = (0x40U | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out));
            if (vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Z16_r) {
                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out 
                    = ((0xbfU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out)) 
                       | (0x40U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F)));
            }
        } else {
            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out 
                = (0xbfU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out));
        }
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out 
            = ((0x7fU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out)) 
               | (0x80U & (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t)));
        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op_r))) {
            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op_r))) {
                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op_r)))) {
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out 
                        = ((0xfbU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out)) 
                           | (4U & ((~ VL_REDXOR_8(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t)) 
                                    << 2U)));
                }
            } else {
                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out 
                    = ((0xfbU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out)) 
                       | (4U & ((~ VL_REDXOR_8(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t)) 
                                << 2U)));
            }
        }
        if (vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Arith16_r) {
            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out 
                = ((0x3fU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out)) 
                   | (0xc0U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F)));
            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out 
                = ((0xfbU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out)) 
                   | (4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F)));
        }
    }
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Q 
        = sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t;
    sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegAddrB 
        = (((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ExchangeDH) 
            & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstate) 
               >> 3U)) ? (1U | ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Alternate) 
                                << 2U)) : (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegAddrB_r));
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegBusB 
        = ((vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_reg__DOT__RegsH
            [sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegAddrB] 
            << 8U) | vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_reg__DOT__RegsL
           [sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegAddrB]);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegBusA 
        = ((vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_reg__DOT__RegsH
            [vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegAddrA] 
            << 8U) | vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_reg__DOT__RegsL
           [vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegAddrA]);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__cpi_xy_n 
        = (0xffU & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Q) 
                    - (1U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out) 
                             >> 4U))));
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_Mux 
        = ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ExchangeRp)
            ? (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__BusB)
            : ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU_r)
                ? (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Q)
                : (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__di_reg)));
    sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ID16_B 
        = ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16))
            ? 0xffffU : 1U);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ID16 
        = (0xffffU & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegBusA) 
                      + (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ID16_B)));
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegDIH 
        = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_Mux;
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegDIL 
        = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_Mux;
    if (((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ExchangeDH) 
         & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstate) 
            >> 3U))) {
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegDIH 
            = (0xffU & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegBusB) 
                        >> 8U));
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegDIL 
            = (0xffU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegBusB));
    } else if (((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ExchangeDH) 
                & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstate) 
                   >> 4U))) {
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegDIH 
            = (0xffU & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegBusA_r) 
                        >> 8U));
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegDIL 
            = (0xffU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegBusA_r));
    } else if ((1U & (((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16) 
                       >> 2U) & ((((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstate) 
                                   >> 2U) & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) 
                                 | (((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstate) 
                                     >> 3U) & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))))) {
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegDIH 
            = (0xffU & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ID16) 
                        >> 8U));
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegDIL 
            = (0xffU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ID16));
    }
}

VL_INLINE_OPT void Vsim_top___024root___nba_comb__TOP__7(Vsim_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___nba_comb__TOP__7\n"); );
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

VL_INLINE_OPT void Vsim_top___024root___nba_sequent__TOP__12(Vsim_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___nba_sequent__TOP__12\n"); );
    // Body
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__di_q 
        = vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__di_q;
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cnt = vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cnt;
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__sub_rst_n 
        = ((~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__rst_pulse)) 
           & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__c_run));
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cen_raw 
        = (8U == (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cnt));
}

VL_INLINE_OPT void Vsim_top___024root___nba_comb__TOP__8(Vsim_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___nba_comb__TOP__8\n"); );
    // Body
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
}

VL_INLINE_OPT void Vsim_top___024root___nba_comb__TOP__9(Vsim_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___nba_comb__TOP__9\n"); );
    // Body
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cen = 
        ((~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__zstall) 
             | ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__rd_start) 
                | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__wr_end)))) 
         & (8U == (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cnt)));
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ClkEn 
        = ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cen) 
           & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__BusAck)));
}

void Vsim_top___024root___nba_sequent__TOP__0(Vsim_top___024root* vlSelf);
void Vsim_top___024root___nba_sequent__TOP__1(Vsim_top___024root* vlSelf);
void Vsim_top___024root___nba_sequent__TOP__2(Vsim_top___024root* vlSelf);
void Vsim_top___024root___nba_sequent__TOP__3(Vsim_top___024root* vlSelf);
void Vsim_top___024root___nba_comb__TOP__0(Vsim_top___024root* vlSelf);
void Vsim_top___024root___nba_sequent__TOP__4(Vsim_top___024root* vlSelf);
void Vsim_top___024root___nba_sequent__TOP__5(Vsim_top___024root* vlSelf);
void Vsim_top___024root___nba_sequent__TOP__6(Vsim_top___024root* vlSelf);
void Vsim_top___024root___nba_comb__TOP__1(Vsim_top___024root* vlSelf);
void Vsim_top___024root___nba_sequent__TOP__7(Vsim_top___024root* vlSelf);
void Vsim_top___024root___nba_comb__TOP__2(Vsim_top___024root* vlSelf);
void Vsim_top___024root___act_sequent__TOP__0(Vsim_top___024root* vlSelf);
void Vsim_top___024root___nba_comb__TOP__4(Vsim_top___024root* vlSelf);
void Vsim_top___024root___nba_sequent__TOP__8(Vsim_top___024root* vlSelf);
void Vsim_top___024root___nba_comb__TOP__5(Vsim_top___024root* vlSelf);
void Vsim_top___024root___nba_sequent__TOP__9(Vsim_top___024root* vlSelf);
void Vsim_top___024root___nba_sequent__TOP__10(Vsim_top___024root* vlSelf);

void Vsim_top___024root___eval_nba(Vsim_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(2U)) {
        Vsim_top___024root___nba_sequent__TOP__0(vlSelf);
    }
    if (vlSelf->__VnbaTriggered.at(6U)) {
        Vsim_top___024root___nba_sequent__TOP__1(vlSelf);
    }
    if (vlSelf->__VnbaTriggered.at(5U)) {
        Vsim_top___024root___nba_sequent__TOP__2(vlSelf);
    }
    if (vlSelf->__VnbaTriggered.at(3U)) {
        Vsim_top___024root___nba_sequent__TOP__3(vlSelf);
    }
    if ((vlSelf->__VnbaTriggered.at(2U) | vlSelf->__VnbaTriggered.at(6U))) {
        Vsim_top___024root___nba_comb__TOP__0(vlSelf);
    }
    if (vlSelf->__VnbaTriggered.at(4U)) {
        Vsim_top___024root___nba_sequent__TOP__4(vlSelf);
    }
    if (vlSelf->__VnbaTriggered.at(5U)) {
        Vsim_top___024root___nba_sequent__TOP__5(vlSelf);
    }
    if (vlSelf->__VnbaTriggered.at(2U)) {
        Vsim_top___024root___nba_sequent__TOP__6(vlSelf);
    }
    if ((vlSelf->__VnbaTriggered.at(3U) | vlSelf->__VnbaTriggered.at(5U))) {
        Vsim_top___024root___nba_comb__TOP__1(vlSelf);
    }
    if (vlSelf->__VnbaTriggered.at(5U)) {
        Vsim_top___024root___nba_sequent__TOP__7(vlSelf);
    }
    if ((vlSelf->__VnbaTriggered.at(2U) | vlSelf->__VnbaTriggered.at(5U))) {
        Vsim_top___024root___nba_comb__TOP__2(vlSelf);
    }
    if (((vlSelf->__VnbaTriggered.at(1U) | vlSelf->__VnbaTriggered.at(2U)) 
         | vlSelf->__VnbaTriggered.at(5U))) {
        Vsim_top___024root___act_sequent__TOP__0(vlSelf);
    }
    if ((vlSelf->__VnbaTriggered.at(2U) | vlSelf->__VnbaTriggered.at(6U))) {
        Vsim_top___024root___nba_comb__TOP__4(vlSelf);
    }
    if (vlSelf->__VnbaTriggered.at(6U)) {
        Vsim_top___024root___nba_sequent__TOP__8(vlSelf);
    }
    if ((vlSelf->__VnbaTriggered.at(2U) | vlSelf->__VnbaTriggered.at(6U))) {
        Vsim_top___024root___nba_comb__TOP__5(vlSelf);
    }
    if (vlSelf->__VnbaTriggered.at(2U)) {
        Vsim_top___024root___nba_sequent__TOP__9(vlSelf);
    }
    if (vlSelf->__VnbaTriggered.at(6U)) {
        Vsim_top___024root___nba_sequent__TOP__10(vlSelf);
        Vsim_top___024root___nba_sequent__TOP__11(vlSelf);
    }
    if ((vlSelf->__VnbaTriggered.at(2U) | vlSelf->__VnbaTriggered.at(6U))) {
        Vsim_top___024root___nba_comb__TOP__6(vlSelf);
    }
    if (((((vlSelf->__VnbaTriggered.at(0U) | vlSelf->__VnbaTriggered.at(1U)) 
           | vlSelf->__VnbaTriggered.at(2U)) | vlSelf->__VnbaTriggered.at(3U)) 
         | vlSelf->__VnbaTriggered.at(5U))) {
        Vsim_top___024root___nba_comb__TOP__7(vlSelf);
    }
    if (vlSelf->__VnbaTriggered.at(2U)) {
        Vsim_top___024root___nba_sequent__TOP__12(vlSelf);
    }
    if ((((((vlSelf->__VnbaTriggered.at(0U) | vlSelf->__VnbaTriggered.at(1U)) 
            | vlSelf->__VnbaTriggered.at(2U)) | vlSelf->__VnbaTriggered.at(3U)) 
          | vlSelf->__VnbaTriggered.at(5U)) | vlSelf->__VnbaTriggered.at(6U))) {
        Vsim_top___024root___nba_comb__TOP__8(vlSelf);
    }
    if ((vlSelf->__VnbaTriggered.at(2U) | vlSelf->__VnbaTriggered.at(6U))) {
        Vsim_top___024root___nba_comb__TOP__9(vlSelf);
    }
}

void Vsim_top___024root___eval_triggers__act(Vsim_top___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vsim_top___024root___dump_triggers__act(Vsim_top___024root* vlSelf);
#endif  // VL_DEBUG
void Vsim_top___024root___eval_act(Vsim_top___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vsim_top___024root___dump_triggers__nba(Vsim_top___024root* vlSelf);
#endif  // VL_DEBUG

void Vsim_top___024root___eval(Vsim_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___eval\n"); );
    // Init
    VlTriggerVec<7> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            Vsim_top___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vsim_top___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("sim_top.v", 6, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                Vsim_top___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vsim_top___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("sim_top.v", 6, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vsim_top___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vsim_top___024root___eval_debug_assertions(Vsim_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->resetn & 0xfeU))) {
        Verilated::overWidthError("resetn");}
    if (VL_UNLIKELY((vlSelf->rxd & 0xfeU))) {
        Verilated::overWidthError("rxd");}
    if (VL_UNLIKELY((vlSelf->sd_miso & 0xfeU))) {
        Verilated::overWidthError("sd_miso");}
    if (VL_UNLIKELY((vlSelf->fl_miso & 0xfeU))) {
        Verilated::overWidthError("fl_miso");}
}
#endif  // VL_DEBUG
