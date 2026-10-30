// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsim_top.h for the primary calling header

#include "verilated.h"

#include "Vsim_top___024root.h"

VL_INLINE_OPT void Vsim_top___024root___nba_comb__TOP__1(Vsim_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___nba_comb__TOP__1\n"); );
    // Body
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IntType_nxt 
        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IntType;
    if ((0x40U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
        if ((0x20U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState) 
                          >> 4U)))) {
                if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                    if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState)))) {
                                if (vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__NMILatched) {
                                    if ((1U & ((~ (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__FIRQLatched)) 
                                               & (~ 
                                                  ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc) 
                                                   >> 6U))))) {
                                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IntType_nxt = 2U;
                                    } else if ((1U 
                                                & ((~ (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IRQLatched)) 
                                                   & (~ 
                                                      ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__cc) 
                                                       >> 4U))))) {
                                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IntType_nxt = 1U;
                                    }
                                } else {
                                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IntType_nxt = 0U;
                                }
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
                            if (vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__InstPage3) {
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IntType_nxt = 5U;
                            }
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IntType_nxt 
                                = ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__InstPage2)
                                    ? 4U : 3U);
                        }
                    } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IntType_nxt = 2U;
                    }
                } else if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState) 
                                     >> 1U)))) {
                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IntType_nxt = 1U;
                    }
                }
            } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IntType_nxt = 0U;
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
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IntType_nxt = 7U;
                        }
                    }
                }
            }
        }
    }
}

VL_INLINE_OPT void Vsim_top___024root___nba_sequent__TOP__7(Vsim_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___nba_sequent__TOP__7\n"); );
    // Body
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__BA_nxt = 0U;
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__BS_nxt = 0U;
    if ((0x40U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
        if ((0x20U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
            if ((0x10U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState) 
                              >> 3U)))) {
                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState)))) {
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__BA_nxt = 1U;
                            }
                        } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__BA_nxt = 1U;
                        }
                    }
                }
            } else if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__BA_nxt = 1U;
                        }
                    }
                }
            } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState)))) {
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__BA_nxt = 1U;
                    }
                }
            }
            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState) 
                          >> 4U)))) {
                if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                    if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__BS_nxt = 1U;
                            }
                        }
                    }
                } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState) 
                                  >> 1U)))) {
                        if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState)))) {
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__BS_nxt = 1U;
                        }
                    }
                }
            }
        } else if ((0x10U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
            if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState) 
                                  >> 1U)))) {
                        if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState)))) {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IntType) 
                                          >> 2U)))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IntType))) {
                                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IntType)))) {
                                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__BS_nxt = 1U;
                                    }
                                } else {
                                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__BS_nxt = 1U;
                                }
                            }
                        }
                    }
                } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IntType))) {
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IntType))) {
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__BS_nxt = 1U;
                            }
                        } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IntType))) {
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__IntType)))) {
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__BS_nxt = 1U;
                            }
                        } else {
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__BS_nxt = 1U;
                        }
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
                if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState) 
                                  >> 1U)))) {
                        if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState)))) {
                            if (vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DMABREQLatched) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__HALTLatched)))) {
                                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__BA_nxt = 1U;
                                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__BS_nxt = 1U;
                                }
                            } else {
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__BA_nxt = 1U;
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__BS_nxt = 1U;
                            }
                        }
                    }
                } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                        vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__BS_nxt = 1U;
                    }
                } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__BS_nxt = 1U;
                }
            }
        }
    }
}

VL_INLINE_OPT void Vsim_top___024root___nba_comb__TOP__2(Vsim_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___nba_comb__TOP__2\n"); );
    // Body
    vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst3_nxt 
        = vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst3;
    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState) 
                  >> 6U)))) {
        if ((0x20U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
            if ((0x10U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState)))) {
                                vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst3_nxt 
                                    = vlSelf->dbg_din;
                            }
                        }
                    }
                }
            }
        } else if ((0x10U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState) 
                          >> 3U)))) {
                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState) 
                              >> 2U)))) {
                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState) 
                                  >> 1U)))) {
                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__CpuState))) {
                            vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__Inst3_nxt 
                                = vlSelf->dbg_din;
                        }
                    }
                }
            }
        }
    }
}

VL_INLINE_OPT void Vsim_top___024root___nba_comb__TOP__4(Vsim_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___nba_comb__TOP__4\n"); );
    // Body
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__rd_start 
        = ((~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__mem_rd_q)) 
           & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__mem_rd));
}

extern const VlUnpacked<CData/*3:0*/, 128> Vsim_top__ConstPool__TABLE_hab4e292f_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vsim_top__ConstPool__TABLE_h302f44b7_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vsim_top__ConstPool__TABLE_hf2e2ed2e_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vsim_top__ConstPool__TABLE_h19b4d42c_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vsim_top__ConstPool__TABLE_hfc5fe02f_0;

VL_INLINE_OPT void Vsim_top___024root___nba_sequent__TOP__8(Vsim_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___nba_sequent__TOP__8\n"); );
    // Init
    CData/*2:0*/ __Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcyc_to_number__74__Vfuncout;
    __Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcyc_to_number__74__Vfuncout = 0;
    CData/*6:0*/ __Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcyc_to_number__74__mcyc;
    __Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcyc_to_number__74__mcyc = 0;
    CData/*6:0*/ __Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__number_to_bitvec__75__Vfuncout;
    __Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__number_to_bitvec__75__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__number_to_bitvec__75__num;
    __Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__number_to_bitvec__75__num = 0;
    CData/*6:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__mem_wrc 
        = (1U & ((~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__mreq_n)) 
                 & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__wr_n))));
    if (vlSelf->sim_top__DOT__soc__DOT__sub__DOT__sub_rst_n) {
        if (vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ClkEn) {
            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Z16_r 
                = ((IData)(((2U == (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ISet)) 
                            & (1U == (5U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op))))) 
                   & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                      >> 2U));
            if (((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                 & (0U != (0xeU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstate))))) {
                if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstate))) {
                    if ((1U & (((((~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Jump)) 
                                  & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Call))) 
                                 & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__NMICycle))) 
                                & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IntCycle))) 
                               & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Halt_FF) 
                                     | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Halt)))))) {
                        vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__PC 
                            = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__PC16;
                    }
                    if (((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IntCycle) 
                         & (1U == (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IStatus)))) {
                        vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR = 0xffU;
                    } else if ((((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Halt_FF) 
                                 | ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IntCycle) 
                                    & (2U == (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IStatus)))) 
                                | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__NMICycle))) {
                        vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR = 0U;
                        vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__TmpAddr 
                            = ((0xff00U & (IData)(vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__TmpAddr)) 
                               | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__di_q));
                    } else {
                        vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR 
                            = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__di_q;
                    }
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ISet = 0U;
                    if ((0U != (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Prefix))) {
                        if ((3U == (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Prefix))) {
                            vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__XY_State 
                                = ((0x20U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))
                                    ? 2U : 1U);
                        } else if ((2U == (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Prefix))) {
                            vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__XY_State = 0U;
                        }
                        if ((3U != (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Prefix))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ISet 
                                = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Prefix;
                        }
                    } else {
                        vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__XY_State = 0U;
                    }
                }
            } else {
                if (vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__last_tstate) {
                    if (vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Jump) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__A 
                            = (((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__di_reg) 
                                << 8U) | (0xffU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__TmpAddr)));
                        vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__PC 
                            = (((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__di_reg) 
                                << 8U) | (0xffU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__TmpAddr)));
                    } else if (vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__JumpXY) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__A 
                            = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegBusC;
                        vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__PC 
                            = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegBusC;
                    } else if (((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Call) 
                                | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RstP))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__A 
                            = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__TmpAddr;
                        vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__PC 
                            = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__TmpAddr;
                    } else if (((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__last_mcycle) 
                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__NMICycle))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__A = 0x66U;
                        vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__PC = 0x66U;
                    } else if (((((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                  >> 2U) & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IntCycle)) 
                                & (2U == (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IStatus)))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__A 
                            = (((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I) 
                                << 8U) | (0xffU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__TmpAddr)));
                        vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__PC 
                            = (((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I) 
                                << 8U) | (0xffU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__TmpAddr)));
                    } else {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__A 
                            = (0xffffU & ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To))
                                           ? ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To))
                                               ? ((1U 
                                                   & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To))
                                                   ? (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__PC)
                                                   : 
                                                  ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_WZ)
                                                    ? 
                                                   ((IData)(1U) 
                                                    + (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__TmpAddr))
                                                    : 
                                                   (((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__di_reg) 
                                                     << 8U) 
                                                    | (0xffU 
                                                       & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__TmpAddr)))))
                                               : ((1U 
                                                   & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To))
                                                   ? (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__SP)
                                                   : 
                                                  (((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ACC) 
                                                    << 8U) 
                                                   | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__di_reg))))
                                           : ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To))
                                               ? ((1U 
                                                   & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To))
                                                   ? (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__PC)
                                                   : 
                                                  ((0U 
                                                    == (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__XY_State))
                                                    ? (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegBusC)
                                                    : 
                                                   ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__NextIs_XY_Fetch)
                                                     ? (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__PC)
                                                     : (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__TmpAddr))))
                                               : (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegBusC))));
                    }
                    if (vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I_CPL) {
                        vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ACC 
                            = (0xffU & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ACC)));
                        vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F 
                            = ((0xcfU & (IData)(vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F)) 
                               | (0x10U | (0x20U & 
                                           ((~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ACC) 
                                                >> 5U)) 
                                            << 5U))));
                        vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F 
                            = ((0xf7U & (IData)(vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F)) 
                               | (8U & ((~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ACC) 
                                            >> 3U)) 
                                        << 3U)));
                        vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F 
                            = (2U | (IData)(vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F));
                    }
                    if (vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I_CCF) {
                        vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F 
                            = ((0xfeU & (IData)(vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F)) 
                               | (1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F))));
                        vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F 
                            = ((0xc7U & (IData)(vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F)) 
                               | ((0x20U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ACC)) 
                                  | ((0x10U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F) 
                                               << 4U)) 
                                     | (8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ACC)))));
                        vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F 
                            = (0xfdU & (IData)(vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F));
                    }
                    if (vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I_SCF) {
                        vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F 
                            = (1U | (IData)(vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F));
                        vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F 
                            = ((0xc7U & (IData)(vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F)) 
                               | (0x28U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ACC)));
                        vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F 
                            = (0xfdU & (IData)(vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F));
                    }
                }
                if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstate))) {
                    if (vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__JumpE) {
                        vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__PC 
                            = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__PC16;
                    } else if (vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC) {
                        vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__PC 
                            = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__PC16;
                    }
                    if (vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RstP) {
                        vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__TmpAddr 
                            = (0x38U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR));
                    }
                    if (vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__BTR_r) {
                        vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__PC 
                            = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__PC16;
                    }
                    if (((1U == (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ISet)) 
                         & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                            >> 6U))) {
                        vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR 
                            = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__di_q;
                    }
                }
                if ((1U & (((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstate) 
                            >> 2U) | (((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstate) 
                                       >> 4U) & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))))) {
                    if ((7U == (7U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16)))) {
                        vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__SP 
                            = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__SP16;
                    }
                }
                if ((1U & (((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstate) 
                            >> 3U) & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                      >> 5U)))) {
                    vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__TmpAddr 
                        = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__SP16;
                }
                if (vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDSPHL) {
                    vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__SP 
                        = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegBusC;
                }
                if (vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ExchangeAF) {
                    vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ACC 
                        = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Ap;
                    vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F 
                        = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Fp;
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Ap 
                        = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ACC;
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Fp 
                        = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F;
                }
                if ((0x20U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                    if ((1U == (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Prefix))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ISet = 1U;
                    }
                }
            }
            if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstate))) {
                if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Special_LD))) {
                    if ((0U == (3U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Special_LD)))) {
                        vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F 
                            = ((0xfbU & (IData)(vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F)) 
                               | ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IntE_FF2) 
                                  << 2U));
                        vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ACC 
                            = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I;
                        vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F 
                            = ((0x3fU & (IData)(vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F)) 
                               | ((0x80U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I)) 
                                  | ((0U == (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I)) 
                                     << 6U)));
                        vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F 
                            = (0xefU & (IData)(vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F));
                        vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F 
                            = (0xfdU & (IData)(vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F));
                    } else if ((1U == (3U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Special_LD)))) {
                        vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F 
                            = ((0xfbU & (IData)(vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F)) 
                               | ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IntE_FF2) 
                                  << 2U));
                        vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ACC = 0U;
                        vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F 
                            = ((0x3fU & (IData)(vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F)) 
                               | ((0x80U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I)) 
                                  | ((0U == (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I)) 
                                     << 6U)));
                        vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F 
                            = (0xefU & (IData)(vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F));
                        vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F 
                            = (0xfdU & (IData)(vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F));
                    } else if ((2U == (3U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Special_LD)))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I 
                            = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ACC;
                    }
                }
                if (vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDZ) {
                    vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__TmpAddr 
                        = ((0xff00U & (IData)(vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__TmpAddr)) 
                           | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__di_reg));
                }
                if (vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDW) {
                    vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__TmpAddr 
                        = ((0xffU & (IData)(vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__TmpAddr)) 
                           | ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__di_reg) 
                              << 8U));
                }
            }
            if ((((~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I_DJNZ)) 
                  & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU_r)) 
                 | (9U == (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op_r)))) {
                vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F 
                    = ((1U & (IData)(vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F)) 
                       | (0xfeU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out)));
                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__PreserveC_r)))) {
                    vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F 
                        = ((0xfeU & (IData)(vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F)) 
                           | (1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out)));
                }
            }
            if (((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__last_tstate) 
                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I_INRC))) {
                vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F 
                    = (0xefU & (IData)(vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F));
                vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F 
                    = (0xfdU & (IData)(vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F));
                vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F 
                    = ((0x3fU & (IData)(vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F)) 
                       | ((0x80U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__di_reg)) 
                          | ((0U == (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__di_reg)) 
                             << 6U)));
                vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F 
                    = ((0xfbU & (IData)(vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F)) 
                       | (4U & ((~ VL_REDXOR_8(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__di_reg)) 
                                << 2U)));
            }
            if ((1U & (((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstate) 
                        >> 1U) & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Auto_Wait_t1))))) {
                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__dout 
                    = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__BusB;
                if (vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I_RLD) {
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__dout 
                        = ((0xf0U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__BusB) 
                                     << 4U)) | (0xfU 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__BusA)));
                }
                if (vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I_RRD) {
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__dout 
                        = ((0xf0U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__BusA) 
                                     << 4U)) | (0xfU 
                                                & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__BusB) 
                                                   >> 4U)));
                }
            }
            if ((((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstate) 
                  >> 1U) & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I_BT))) {
                vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F 
                    = ((0xc7U & (IData)(vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F)) 
                       | ((0x20U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Q) 
                                    << 4U)) | (8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Q))));
                vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F 
                    = (0xfdU & (IData)(vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F));
            }
            if ((((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstate) 
                  >> 1U) & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I_BC))) {
                vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F 
                    = ((0xf7U & (IData)(vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F)) 
                       | (8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__cpi_xy_n)));
                vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F 
                    = ((0xdfU & (IData)(vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F)) 
                       | (0x20U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__cpi_xy_n) 
                                   << 4U)));
            }
            if (((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I_BC) 
                 | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I_BT))) {
                vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F 
                    = ((0xfbU & (IData)(vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F)) 
                       | ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDecZ) 
                          << 2U));
            }
            if ((1U & (((((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstate) 
                          >> 1U) & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU_r))) 
                        & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Auto_Wait_t1))) 
                       | ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU_r) 
                          & (7U != (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op_r)))))) {
                if ((0x10U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg_r))) {
                    if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg_r))) {
                        if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg_r) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg_r))) {
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg_r))) {
                                    vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F 
                                        = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_Mux;
                                }
                            } else {
                                vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__SP 
                                    = ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg_r))
                                        ? ((0xffU & (IData)(vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__SP)) 
                                           | ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_Mux) 
                                              << 8U))
                                        : ((0xff00U 
                                            & (IData)(vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__SP)) 
                                           | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_Mux)));
                            }
                        }
                    } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg_r))) {
                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg_r))) {
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg_r))) {
                                vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ACC 
                                    = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_Mux;
                            } else {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__dout 
                                    = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_Mux;
                            }
                        }
                    }
                }
            }
            if ((3U != (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IMode))) {
                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IStatus 
                    = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IMode;
            }
            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__PreserveC_r 
                = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__PreserveC;
            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg_r = 0U;
            if (vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__last_tstate) {
                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg_r 
                    = (((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg) 
                        << 4U) | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To));
                if (vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Acc) {
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg_r = 0x17U;
                }
            }
            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op_r = 0U;
            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                          & (IData)((0U != (0xeU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstate)))))))) {
                if (vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__last_tstate) {
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op_r 
                        = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op;
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__BTR_r 
                        = ((((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I_BT) 
                             | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I_BC)) 
                            | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I_BTR)) 
                           & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__No_BTR)));
                }
            }
        }
        if (vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cen) {
            vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Auto_Wait_t1 
                = ((~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__last_tstate)) 
                   & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Auto_Wait) 
                      | ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__iorq_i) 
                         & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Auto_Wait_t2)))));
            vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Auto_Wait_t2 
                = ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Auto_Wait_t1) 
                   & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__last_tstate)));
            if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstate))) {
                if (vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__SetEI) {
                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__NMICycle)))) {
                        vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IntE_FF1 = 1U;
                    }
                    vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IntE_FF2 = 1U;
                }
                if (vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I_RETN) {
                    vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IntE_FF1 
                        = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IntE_FF2;
                }
            }
            if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstate))) {
                if (vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__SetDI) {
                    vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IntE_FF1 = 0U;
                    vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IntE_FF2 = 0U;
                }
            }
            if (((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IntCycle) 
                 | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__NMICycle))) {
                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Halt_FF = 0U;
            }
            if ((1U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                       & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstate) 
                          >> 2U)))) {
                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__m1_n = 1U;
            }
            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__BusReq_s) 
                          & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__BusAck))))) {
                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__BusAck = 0U;
                if (vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__last_tstate) {
                    if (vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Halt) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Halt_FF = 1U;
                    }
                    if (vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__BusReq_s) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__BusAck = 1U;
                    } else {
                        vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstate = 2U;
                        if (vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__NextIs_XY_Fetch) {
                            __Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcyc_to_number__74__mcyc 
                                = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle;
                            __Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcyc_to_number__74__Vfuncout 
                                = ((0x40U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcyc_to_number__74__mcyc))
                                    ? 7U : ((0x20U 
                                             & (IData)(__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcyc_to_number__74__mcyc))
                                             ? 6U : 
                                            ((0x10U 
                                              & (IData)(__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcyc_to_number__74__mcyc))
                                              ? 5U : 
                                             ((8U & (IData)(__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcyc_to_number__74__mcyc))
                                               ? 4U
                                               : ((4U 
                                                   & (IData)(__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcyc_to_number__74__mcyc))
                                                   ? 3U
                                                   : 
                                                  ((2U 
                                                    & (IData)(__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcyc_to_number__74__mcyc))
                                                    ? 2U
                                                    : 1U))))));
                            vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Pre_XY_F_M 
                                = __Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcyc_to_number__74__Vfuncout;
                            vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle = 0x20U;
                            if ((0x36U == (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Pre_XY_F_M = 2U;
                            }
                        } else if ((0x40U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            __Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__number_to_bitvec__75__num 
                                = (7U & ((IData)(1U) 
                                         + (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Pre_XY_F_M)));
                            __Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__number_to_bitvec__75__Vfuncout 
                                = ((1U == (IData)(__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__number_to_bitvec__75__num))
                                    ? 1U : ((2U == (IData)(__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__number_to_bitvec__75__num))
                                             ? 2U : 
                                            ((3U == (IData)(__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__number_to_bitvec__75__num))
                                              ? 4U : 
                                             ((4U == (IData)(__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__number_to_bitvec__75__num))
                                               ? 8U
                                               : ((5U 
                                                   == (IData)(__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__number_to_bitvec__75__num))
                                                   ? 0x10U
                                                   : 
                                                  ((6U 
                                                    == (IData)(__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__number_to_bitvec__75__num))
                                                    ? 0x20U
                                                    : 
                                                   ((7U 
                                                     == (IData)(__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__number_to_bitvec__75__num))
                                                     ? 0x40U
                                                     : 0U)))))));
                            vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle 
                                = __Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__number_to_bitvec__75__Vfuncout;
                        } else if ((((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__last_mcycle) 
                                     | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__No_BTR)) 
                                    | ((((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                         >> 1U) & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I_DJNZ)) 
                                       & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDecZ)))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__m1_n = 0U;
                            vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle = 1U;
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IntCycle = 0U;
                            vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__NMICycle = 0U;
                            if (((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__NMI_s) 
                                 & (0U == (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Prefix)))) {
                                vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__NMICycle = 1U;
                                vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IntE_FF1 = 0U;
                            } else if (((((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IntE_FF1) 
                                          & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__INT_s)) 
                                         & (0U == (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Prefix))) 
                                        & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__SetEI)))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IntCycle = 1U;
                                vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IntE_FF1 = 0U;
                                vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IntE_FF2 = 0U;
                            }
                        } else {
                            vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle 
                                = ((0x7eU & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                             << 1U)) 
                                   | (1U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                            >> 6U)));
                        }
                    }
                } else if ((1U & ((~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Auto_Wait) 
                                      & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Auto_Wait_t2)))) 
                                  & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__iorq_i) 
                                        & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Auto_Wait_t1))))))) {
                    vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstate 
                        = ((0x7eU & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstate) 
                                     << 1U)) | (1U 
                                                & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstate) 
                                                   >> 6U)));
                }
            }
            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstate))) {
                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__m1_n = 0U;
            }
            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__No_BTR 
                = ((((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I_BT) 
                     & ((~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                            >> 4U)) | (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F) 
                                          >> 2U)))) 
                    | ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I_BC) 
                       & ((~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                              >> 4U)) | (4U != (0x44U 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F)))))) 
                   | ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I_BTR) 
                      & ((~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                             >> 4U)) | ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F) 
                                        >> 6U))));
        }
    } else {
        vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__PC = 0U;
        vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F = 0xffU;
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__A = 0U;
        vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__TmpAddr = 0U;
        vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR = 0U;
        vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__XY_State = 0U;
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__dout = 0U;
        vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ACC = 0xffU;
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Ap = 0xffU;
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Fp = 0xffU;
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I = 0U;
        vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__SP = 0xffffU;
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Z16_r = 0U;
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IStatus = 0U;
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__PreserveC_r = 0U;
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg_r = 0U;
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op_r = 0U;
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ISet = 0U;
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__BTR_r = 0U;
        vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IntE_FF1 = 0U;
        vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle = 1U;
        vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstate = 1U;
        vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Pre_XY_F_M = 0U;
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Halt_FF = 0U;
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__BusAck = 0U;
        vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__NMICycle = 0U;
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IntCycle = 0U;
        vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IntE_FF2 = 0U;
        vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Auto_Wait_t1 = 0U;
        vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Auto_Wait_t2 = 0U;
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__m1_n = 1U;
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__No_BTR = 0U;
    }
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__TmpAddr 
        = vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__TmpAddr;
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__XY_State 
        = vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__XY_State;
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Auto_Wait_t2 
        = vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Auto_Wait_t2;
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IntE_FF1 
        = vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IntE_FF1;
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IntE_FF2 
        = vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IntE_FF2;
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Pre_XY_F_M 
        = vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Pre_XY_F_M;
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Auto_Wait_t1 
        = vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Auto_Wait_t1;
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__int_ack 
        = (1U & ((~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__iorq_n)) 
                 & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__m1_n))));
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__io_rd 
        = ((~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__iorq_n)) 
           & ((~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__rd_n)) 
              & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__m1_n)));
    __Vtableidx1 = (((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Oldnmi_n) 
                     << 6U) | (((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__nmi_n) 
                                << 5U) | (((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__NMICycle) 
                                           << 4U) | 
                                          ((8U & ((~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__pend_m2s)) 
                                                  << 3U)) 
                                           | ((4U & 
                                               ((~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__c_hold)) 
                                                << 2U)) 
                                              | (((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cen) 
                                                  << 1U) 
                                                 | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__sub_rst_n)))))));
    if ((1U & Vsim_top__ConstPool__TABLE_hab4e292f_0
         [__Vtableidx1])) {
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__BusReq_s 
            = Vsim_top__ConstPool__TABLE_h302f44b7_0
            [__Vtableidx1];
    }
    if ((2U & Vsim_top__ConstPool__TABLE_hab4e292f_0
         [__Vtableidx1])) {
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__INT_s 
            = Vsim_top__ConstPool__TABLE_hf2e2ed2e_0
            [__Vtableidx1];
    }
    if ((4U & Vsim_top__ConstPool__TABLE_hab4e292f_0
         [__Vtableidx1])) {
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__NMI_s 
            = Vsim_top__ConstPool__TABLE_h19b4d42c_0
            [__Vtableidx1];
    }
    if ((8U & Vsim_top__ConstPool__TABLE_hab4e292f_0
         [__Vtableidx1])) {
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Oldnmi_n 
            = Vsim_top__ConstPool__TABLE_hfc5fe02f_0
            [__Vtableidx1];
    }
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR 
        = vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR;
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__NMICycle 
        = vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__NMICycle;
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDSPHL = 0U;
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IMode = 3U;
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I_SCF = 0U;
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ExchangeRS = 0U;
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Prefix = 0U;
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I_CCF = 0U;
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ExchangeAF = 0U;
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Special_LD = 0U;
    if ((0U != (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ISet))) {
        if ((1U != (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ISet))) {
            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                          >> 7U)))) {
                if ((0x40U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((0x20U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((0x10U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 3U)))) {
                                if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IMode 
                                            = ((1U 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))
                                                ? 2U
                                                : 1U);
                                    }
                                }
                            }
                        } else if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IMode = 0U;
                                    }
                                }
                            }
                        } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IMode = 0U;
                                }
                            }
                        }
                    } else if ((0x10U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IMode = 2U;
                                    }
                                }
                            }
                        } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IMode = 1U;
                                }
                            }
                        }
                    } else if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IMode = 0U;
                                }
                            }
                        }
                    } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IMode = 0U;
                            }
                        }
                    }
                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                  >> 5U)))) {
                        if ((0x10U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Special_LD = 5U;
                                        }
                                    }
                                }
                            } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Special_LD = 4U;
                                    }
                                }
                            }
                        } else if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Special_LD = 7U;
                                    }
                                }
                            }
                        } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Special_LD = 6U;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__JumpXY = 0U;
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__SetDI = 0U;
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__SetEI = 0U;
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Halt = 0U;
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I_CPL = 0U;
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ExchangeRp = 0U;
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_alu__DOT__BitMask 
        = ((0x20U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))
            ? ((0x10U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))
                ? ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))
                    ? 0x80U : 0x40U) : ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))
                                         ? 0x20U : 0x10U))
            : ((0x10U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))
                ? ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))
                    ? 8U : 4U) : ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))
                                   ? 2U : 1U)));
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ExchangeDH = 0U;
    if ((0U == (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ISet))) {
        if ((0x80U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
            if ((0x40U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                if ((0x20U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((0x10U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 2U)))) {
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDSPHL = 1U;
                                    }
                                }
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__SetEI = 1U;
                                    }
                                }
                            }
                            if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Prefix = 3U;
                                    }
                                }
                            }
                        }
                        if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                      >> 3U)))) {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 2U)))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__SetDI = 1U;
                                    }
                                }
                            }
                        }
                    } else if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Prefix = 2U;
                                }
                            }
                        }
                    }
                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                  >> 4U)))) {
                        if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 2U)))) {
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__JumpXY = 1U;
                                    }
                                }
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ExchangeDH = 1U;
                                    }
                                }
                            }
                        }
                    }
                } else if ((0x10U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Prefix = 3U;
                                }
                            }
                        }
                    }
                } else if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Prefix = 1U;
                            }
                        }
                    }
                }
                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                              >> 5U)))) {
                    if ((0x10U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 2U)))) {
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ExchangeRS = 1U;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                      >> 7U)))) {
            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                          >> 6U)))) {
                if ((0x20U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((0x10U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                      >> 3U)))) {
                            if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I_SCF = 1U;
                                    }
                                }
                            }
                        }
                        if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I_CCF = 1U;
                                    }
                                }
                            }
                        }
                    }
                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                  >> 4U)))) {
                        if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I_CPL = 1U;
                                    }
                                }
                            }
                        }
                    }
                }
                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                              >> 5U)))) {
                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                  >> 4U)))) {
                        if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 2U)))) {
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ExchangeAF = 1U;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if ((0x40U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                if ((0x36U == (0x3fU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Halt = 1U;
                }
                if ((0x36U != (0x3fU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                    if ((6U != (7U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                        if ((6U != (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 3U)))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ExchangeRp = 1U;
                        }
                    }
                }
            }
        }
    }
}

VL_INLINE_OPT void Vsim_top___024root___nba_comb__TOP__5(Vsim_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___nba_comb__TOP__5\n"); );
    // Body
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__wr_end 
        = ((~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__mem_wrc)) 
           & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__mem_wr_q));
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__sub_phys 
        = ((vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__smmu
            [(7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__A) 
                    >> 0xdU))] << 0xdU) | (0x1fffU 
                                           & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__A)));
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__port_ok 
        = ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__s_we)
            ? (0U == (0xfU & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__a_q) 
                              >> 4U))) : (0U == (0xfU 
                                                 & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__A) 
                                                    >> 4U))));
}

VL_INLINE_OPT void Vsim_top___024root___nba_sequent__TOP__9(Vsim_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___nba_sequent__TOP__9\n"); );
    // Body
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegBusC 
        = ((vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_reg__DOT__RegsH
            [vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegAddrC] 
            << 8U) | vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_reg__DOT__RegsL
           [vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegAddrC]);
    if (vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ClkEn) {
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__BusA 
            = (0xffU & ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To))
                         ? ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To))
                             ? 0U : ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To))
                                      ? 0U : ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To))
                                               ? ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__SP) 
                                                  >> 8U)
                                               : (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__SP))))
                         : ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To))
                             ? ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To))
                                 ? ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To))
                                     ? (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ACC)
                                     : (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__di_reg))
                                 : ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To))
                                     ? (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegBusA)
                                     : ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegBusA) 
                                        >> 8U))) : 
                            ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To))
                              ? (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegBusA)
                              : ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegBusA) 
                                 >> 8U)))));
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__BusB 
            = (0xffU & ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To))
                         ? ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To))
                             ? ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To))
                                 ? 0U : ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To))
                                          ? ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__PC) 
                                             >> 8U)
                                          : (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__PC)))
                             : ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To))
                                 ? ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To))
                                     ? (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F)
                                     : 1U) : ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To))
                                               ? ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__SP) 
                                                  >> 8U)
                                               : (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__SP))))
                         : ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To))
                             ? ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To))
                                 ? ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To))
                                     ? (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ACC)
                                     : (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__di_reg))
                                 : ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To))
                                     ? (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegBusB)
                                     : ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegBusB) 
                                        >> 8U))) : 
                            ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To))
                              ? (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegBusB)
                              : ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RegBusB) 
                                 >> 8U)))));
        if (((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I_DJNZ) 
             & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU_r))) {
            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDecZ 
                = (1U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F_Out) 
                         >> 6U));
        }
        if (((((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstate) 
               >> 2U) | (((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstate) 
                          >> 3U) & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) 
             & (4U == (7U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16))))) {
            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDecZ 
                = (0U != (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ID16));
        }
    }
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__nmi_n 
        = (1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__nmi_pend)));
    if (vlSelf->sim_top__DOT__soc__DOT__xl_we) {
        if ((1U & (~ (1U & (((IData)(vlSelf->sim_top__DOT__soc__DOT__off) 
                             - (IData)(1U)) >> 2U))))) {
            if ((1U & (~ (3U & (((IData)(vlSelf->sim_top__DOT__soc__DOT__off) 
                                 - (IData)(1U)) >> 1U))))) {
                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__off) 
                              - (IData)(1U))))) {
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__c_hold 
                        = (1U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DOutput) 
                                 >> 1U));
                }
            }
            if ((2U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__off) 
                       - (IData)(1U)))) {
                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__off) 
                              - (IData)(1U))))) {
                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DOutput) 
                                  >> 7U)))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__pend_m2s = 1U;
                    }
                }
            }
        }
    }
    if (vlSelf->sim_top__DOT__soc__DOT__sub__DOT____Vcellinp__xl__s_we) {
        if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__s_port) 
                      >> 3U)))) {
            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__s_port) 
                          >> 2U)))) {
                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__s_port))) {
                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__s_port))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__pend_m2s = 0U;
                    }
                }
            }
        }
    }
    if (vlSelf->sim_top__DOT__soc__DOT__rst) {
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__c_hold = 0U;
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__xl__DOT__pend_m2s = 0U;
    }
    if (vlSelf->sim_top__DOT__soc__DOT__sub__DOT__sub_nmi) {
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__nmi_pend = 1U;
    } else if (vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cen) {
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__nmi_pend = 0U;
    }
    vlSelf->sim_top__DOT__soc__DOT__rst = (1U & (~ (IData)(vlSelf->resetn)));
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__sub_nmi = 0U;
    if (vlSelf->sim_top__DOT__soc__DOT__xl_we) {
        if ((1U & (~ (1U & (((IData)(vlSelf->sim_top__DOT__soc__DOT__off) 
                             - (IData)(1U)) >> 2U))))) {
            if ((2U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__off) 
                       - (IData)(1U)))) {
                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__off) 
                              - (IData)(1U))))) {
                    if ((0x80U & (IData)(vlSelf->sim_top__DOT__soc__DOT__cpu__DOT__DOutput))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__sub_nmi = 1U;
                    }
                }
            }
        }
    }
}

VL_INLINE_OPT void Vsim_top___024root___nba_sequent__TOP__10(Vsim_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___nba_sequent__TOP__10\n"); );
    // Init
    CData/*2:0*/ sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD;
    sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD = 0;
    CData/*1:0*/ sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR;
    sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR = 0;
    // Body
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ACC 
        = vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ACC;
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__PC 
        = vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__PC;
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__SP 
        = vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__SP;
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F 
        = vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F;
    if (vlSelf->sim_top__DOT__soc__DOT__sub__DOT__sub_rst_n) {
        if ((4U == (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cnt))) {
            if ((1U & ((((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstate) 
                         >> 2U) & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write))) 
                       & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__no_read))))) {
                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__di_reg 
                    = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__di_q;
            }
        }
        if (vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ClkEn) {
            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU_r = 0U;
            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                          & (IData)((0U != (0xeU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstate)))))))) {
                if (vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__last_tstate) {
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU_r 
                        = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU;
                }
            }
        }
    } else {
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__di_reg = 0U;
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU_r = 0U;
    }
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstate 
        = vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstate;
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle 
        = vlSelf->__Vdly__sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle;
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__last_mcycle 
        = (1U & ((1U == (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles))
                  ? (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)
                  : ((2U == (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles))
                      ? ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                         >> 1U) : ((3U == (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles))
                                    ? ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                       >> 2U) : ((4U 
                                                  == (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles))
                                                  ? 
                                                 ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 3U)
                                                  : 
                                                 ((5U 
                                                   == (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles))
                                                   ? 
                                                  ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                   >> 4U)
                                                   : 
                                                  ((6U 
                                                    == (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles))
                                                    ? 
                                                   ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 5U)
                                                    : 
                                                   ((7U 
                                                     == (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles)) 
                                                    & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                       >> 6U)))))))));
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Auto_Wait = 0U;
    if (((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IntCycle) 
         | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__NMICycle))) {
        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Auto_Wait = 1U;
        }
    }
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__iorq_i = 0U;
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Acc = 0U;
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RstP = 0U;
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Arith16 = 0U;
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 0U;
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_WZ = 0U;
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op 
        = (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                 >> 3U));
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__PreserveC = 0U;
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I_DJNZ = 0U;
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I_RLD = 0U;
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I_BTR = 0U;
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I_RETN = 0U;
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 0U;
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I_BT = 0U;
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I_BC = 0U;
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I_RRD = 0U;
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__no_read = 0U;
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Call = 0U;
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDW = 0U;
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I_INRC = 0U;
    if ((0U != (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ISet))) {
        if ((1U != (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ISet))) {
            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                          >> 7U)))) {
                if ((0x40U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((0x20U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                      >> 4U)))) {
                            if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                            if ((1U 
                                                 & (~ 
                                                    ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                     >> 1U)))) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                         >> 2U)))) {
                                                    if (
                                                        (8U 
                                                         & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I_RLD = 1U;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 3U)))) {
                                if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                            if ((1U 
                                                 & (~ 
                                                    ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                     >> 1U)))) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                         >> 2U)))) {
                                                    if (
                                                        (8U 
                                                         & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I_RRD = 1U;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if ((0x10U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                  >> 1U)))) {
                                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                            if ((1U 
                                                 & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                         >> 1U)))) {
                                                    if (
                                                        (4U 
                                                         & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I_RETN = 1U;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                              >> 2U)))) {
                                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                  >> 1U)))) {
                                        if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                            if ((1U 
                                                 & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                                if (
                                                    (2U 
                                                     & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I_INRC = 1U;
                                                }
                                            }
                                        }
                                    }
                                }
                            } else {
                                if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                  >> 1U)))) {
                                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                            if ((1U 
                                                 & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                         >> 1U)))) {
                                                    if (
                                                        (4U 
                                                         & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I_RETN = 1U;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                              >> 2U)))) {
                                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                  >> 1U)))) {
                                        if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                            if ((1U 
                                                 & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                                if (
                                                    (2U 
                                                     & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I_INRC = 1U;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        } else if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                        if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                            if ((1U 
                                                 & (~ 
                                                    ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                     >> 1U)))) {
                                                if (
                                                    (4U 
                                                     & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I_RETN = 1U;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 2U)))) {
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                        if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                            if ((2U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I_INRC = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        } else {
                            if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                        if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                            if ((1U 
                                                 & (~ 
                                                    ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                     >> 1U)))) {
                                                if (
                                                    (4U 
                                                     & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I_RETN = 1U;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 2U)))) {
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                        if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                            if ((2U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I_INRC = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((0x10U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                        if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                            if ((1U 
                                                 & (~ 
                                                    ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                     >> 1U)))) {
                                                if (
                                                    (4U 
                                                     & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I_RETN = 1U;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 2U)))) {
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                        if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                            if ((2U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I_INRC = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        } else {
                            if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                        if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                            if ((1U 
                                                 & (~ 
                                                    ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                     >> 1U)))) {
                                                if (
                                                    (4U 
                                                     & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I_RETN = 1U;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 2U)))) {
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                        if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                            if ((2U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I_INRC = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 1U)))) {
                                            if ((4U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I_RETN = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I_INRC = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    } else {
                        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 1U)))) {
                                            if ((4U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I_RETN = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I_INRC = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if ((0x80U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                              >> 6U)))) {
                    if ((0x20U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 1U)))) {
                                            if ((4U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I_BTR = 1U;
                                            }
                                        }
                                    }
                                } else if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I_BTR = 1U;
                                        }
                                    }
                                }
                            }
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 1U)))) {
                                            if ((4U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I_BT = 1U;
                                            }
                                        }
                                    }
                                }
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 1U)))) {
                                            if ((4U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I_BC = 1U;
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
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 0U;
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDZ = 0U;
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 0U;
    if ((0U == (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ISet))) {
        if ((0x80U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
            if ((0x40U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                              >> 5U)))) {
                    if ((0x10U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 2U)))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 1U)))) {
                                            if ((4U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__iorq_i = 1U;
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Acc = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        } else if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                             >> 2U)))) {
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__iorq_i = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                if ((0x20U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((0x10U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                        if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                            if ((1U 
                                                 & (~ 
                                                    ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                     >> 1U)))) {
                                                if (
                                                    (4U 
                                                     & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RstP = 1U;
                                                }
                                            }
                                            if ((2U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                            } else if (
                                                       (4U 
                                                        & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                            }
                                        }
                                    }
                                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                        }
                                    }
                                } else if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 2U)))) {
                                            if ((8U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                            } else if (
                                                       (0x10U 
                                                        & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                            }
                                        }
                                    }
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                    } else if ((4U 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                    }
                                }
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 1U)))) {
                                            if ((1U 
                                                 & (~ 
                                                    ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                     >> 2U)))) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                         >> 3U)))) {
                                                    if (
                                                        (0x10U 
                                                         & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Call = 1U;
                                                    }
                                                }
                                            }
                                            if ((4U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDW = 1U;
                                            }
                                        }
                                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDZ = 1U;
                                        }
                                    }
                                }
                            } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDZ = 1U;
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                    } else if ((4U 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                    }
                                }
                            } else if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDZ = 1U;
                                    }
                                }
                            }
                        } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 1U)))) {
                                            if ((4U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RstP = 1U;
                                            }
                                        }
                                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                        } else if (
                                                   (4U 
                                                    & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                        }
                                    }
                                }
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                    }
                                }
                            } else {
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                        } else if (
                                                   (4U 
                                                    & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                        }
                                    }
                                } else if ((1U & (~ 
                                                  ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                   >> 1U)))) {
                                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 2U)))) {
                                        if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                        } else if (
                                                   (0x10U 
                                                    & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                        }
                                    }
                                }
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                    } else if ((4U 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                    }
                                }
                            }
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 2U)))) {
                                            if ((1U 
                                                 & (~ 
                                                    ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                     >> 3U)))) {
                                                if (
                                                    (0x10U 
                                                     & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Call = 1U;
                                                }
                                            }
                                        }
                                        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDW = 1U;
                                        }
                                    }
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDZ = 1U;
                                    }
                                }
                            }
                        } else {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                        } else if (
                                                   (4U 
                                                    & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                        }
                                    }
                                }
                            }
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDZ = 1U;
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                    } else if ((4U 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                    }
                                }
                            } else if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDZ = 1U;
                                    }
                                }
                            }
                        }
                    } else if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 1U)))) {
                                            if ((4U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RstP = 1U;
                                            }
                                        }
                                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                        } else if (
                                                   (4U 
                                                    & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                        }
                                    }
                                }
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                    }
                                }
                            } else if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 2U)))) {
                                        if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                        } else if (
                                                   (0x10U 
                                                    & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                        }
                                    }
                                }
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                }
                            }
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 2U)))) {
                                            if ((1U 
                                                 & (~ 
                                                    ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                     >> 3U)))) {
                                                if (
                                                    (0x10U 
                                                     & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Call = 1U;
                                                }
                                            }
                                        }
                                        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDW = 1U;
                                        }
                                    }
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDZ = 1U;
                                    }
                                }
                            }
                        } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDZ = 1U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                }
                            }
                        } else if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDZ = 1U;
                                }
                            }
                        }
                    } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RstP = 1U;
                                        }
                                    }
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                    } else if ((4U 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                    }
                                }
                            }
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                }
                            }
                        } else {
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                    } else if ((4U 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                    }
                                }
                            } else if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                 >> 1U)))) {
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 2U)))) {
                                    if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                    } else if ((0x10U 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                    }
                                }
                            }
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                }
                            }
                        }
                        if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 2U)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 3U)))) {
                                            if ((0x10U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Call = 1U;
                                            }
                                        }
                                    }
                                    if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDW = 1U;
                                    }
                                }
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDZ = 1U;
                                }
                            }
                        }
                    } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                } else if ((1U & (~ 
                                                  ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                   >> 2U)))) {
                                    if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                    }
                                }
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                    } else if ((1U 
                                                & (~ 
                                                   ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 3U)))) {
                                        if ((0x10U 
                                             & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                        }
                                    }
                                }
                            }
                        }
                        if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDZ = 1U;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                            } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                            }
                        }
                    } else {
                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                }
                            }
                        }
                        if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDZ = 1U;
                                }
                            }
                        }
                    }
                } else if ((0x10U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 1U)))) {
                                            if ((4U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RstP = 1U;
                                            }
                                        }
                                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                        } else if (
                                                   (4U 
                                                    & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                        }
                                    }
                                }
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                    }
                                }
                            } else if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 2U)))) {
                                        if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                        } else if (
                                                   (0x10U 
                                                    & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                        }
                                    }
                                }
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                }
                            }
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 2U)))) {
                                            if ((1U 
                                                 & (~ 
                                                    ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                     >> 3U)))) {
                                                if (
                                                    (0x10U 
                                                     & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Call = 1U;
                                                }
                                            }
                                        }
                                        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDW = 1U;
                                        }
                                    }
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDZ = 1U;
                                    }
                                }
                            }
                        } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDZ = 1U;
                                }
                            }
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                }
                            } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                            } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                            }
                        } else if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDZ = 1U;
                                }
                            }
                        }
                    } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RstP = 1U;
                                        }
                                    }
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                    } else if ((4U 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                    }
                                }
                            }
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                }
                            }
                        } else {
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                    } else if ((4U 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                    }
                                }
                            } else if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                 >> 1U)))) {
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 2U)))) {
                                    if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                    } else if ((0x10U 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                    }
                                }
                            }
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                }
                            }
                        }
                        if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 2U)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 3U)))) {
                                            if ((0x10U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Call = 1U;
                                            }
                                        }
                                    }
                                    if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDW = 1U;
                                    }
                                }
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDZ = 1U;
                                }
                            }
                        }
                    } else {
                        if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                    } else if ((4U 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                    }
                                }
                            }
                        }
                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                    }
                                }
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                }
                            } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                            } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                            }
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDZ = 1U;
                                }
                            }
                        } else if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDZ = 1U;
                                }
                            }
                        }
                    }
                } else if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RstP = 1U;
                                        }
                                    }
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                    } else if ((4U 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                    }
                                }
                            }
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                }
                            }
                        } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 2U)))) {
                                    if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                    } else if ((0x10U 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                    }
                                }
                            }
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                            } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                            }
                        } else {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 2U)))) {
                                    if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                    } else if ((0x10U 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                    }
                                }
                            }
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                            } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                            }
                        }
                        if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 2U)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 3U)))) {
                                            if ((0x10U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Call = 1U;
                                            }
                                        }
                                    }
                                    if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDW = 1U;
                                    }
                                }
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDZ = 1U;
                                }
                            } else {
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 2U)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 3U)))) {
                                            if ((0x10U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Call = 1U;
                                            }
                                        }
                                    }
                                    if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDW = 1U;
                                    }
                                }
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDZ = 1U;
                                }
                            }
                        }
                    } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDZ = 1U;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                            } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                            }
                        }
                    } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDZ = 1U;
                            }
                        }
                    } else if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDZ = 1U;
                        }
                    }
                } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__RstP = 1U;
                                    }
                                }
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                }
                            }
                        }
                        if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                            }
                        }
                    } else {
                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                }
                            }
                        } else if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                             >> 1U)))) {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 2U)))) {
                                if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                } else if ((0x10U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                }
                            }
                        }
                        if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                            } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                            }
                        }
                    }
                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                  >> 1U)))) {
                        if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 2U)))) {
                                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 3U)))) {
                                        if ((0x10U 
                                             & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Call = 1U;
                                        }
                                    }
                                }
                                if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDW = 1U;
                                }
                            }
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDZ = 1U;
                            }
                        }
                    }
                } else {
                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                  >> 1U)))) {
                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                }
                            }
                        }
                    }
                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDZ = 1U;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                            }
                            if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                            }
                        } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDZ = 1U;
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                        } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                        }
                    } else if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                        if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDZ = 1U;
                            }
                        }
                    }
                }
            } else if ((6U == (7U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                    }
                }
            } else {
                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
            }
        } else {
            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                          >> 6U)))) {
                if ((0x20U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((0x10U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 2U)))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                        if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Acc = 1U;
                                        }
                                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDZ = 1U;
                                        }
                                    }
                                }
                            }
                            if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                        if ((6U == 
                                             (7U & 
                                              ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                               >> 3U)))) {
                                            if ((1U 
                                                 & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                                if (
                                                    (2U 
                                                     & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                                }
                                            }
                                        } else {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                        }
                                    } else if ((6U 
                                                == 
                                                (7U 
                                                 & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                    >> 3U)))) {
                                        if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                            if ((2U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                            }
                                        }
                                    } else {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                    }
                                }
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                        if ((6U == 
                                             (7U & 
                                              ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                               >> 3U)))) {
                                            if ((2U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                            }
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                        }
                                    }
                                }
                            } else {
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                        } else if (
                                                   (4U 
                                                    & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                        }
                                    }
                                }
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                        }
                                        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                        }
                                    }
                                } else if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                    }
                                }
                            }
                        } else {
                            if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                        if ((6U == 
                                             (7U & 
                                              ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                               >> 3U)))) {
                                            if ((1U 
                                                 & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                                if (
                                                    (2U 
                                                     & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                                }
                                            }
                                        } else {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                        }
                                    } else if ((6U 
                                                == 
                                                (7U 
                                                 & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                    >> 3U)))) {
                                        if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                            if ((2U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                            }
                                        }
                                    } else {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                    }
                                }
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                        if ((6U == 
                                             (7U & 
                                              ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                               >> 3U)))) {
                                            if ((2U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                            }
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                        }
                                    }
                                }
                            } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                    } else if ((4U 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                    }
                                }
                            } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                }
                            } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                            }
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 2U)))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDZ = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((6U == (7U 
                                                & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                   >> 3U)))) {
                                        if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                            if ((2U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                            }
                                        }
                                    } else {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                    }
                                } else if ((6U == (7U 
                                                   & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                      >> 3U)))) {
                                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                        }
                                    }
                                } else {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                }
                            }
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((6U == (7U 
                                                & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                   >> 3U)))) {
                                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                        }
                                    } else if ((2U 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                    }
                                }
                            }
                        } else {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                    } else if ((4U 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                    }
                                }
                            }
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                    } else if ((4U 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                    }
                                }
                            } else if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                }
                            }
                        }
                        if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDZ = 1U;
                                    }
                                }
                            }
                        }
                    } else {
                        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                }
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((6U == (7U 
                                                & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                   >> 3U)))) {
                                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                        }
                                    } else if ((2U 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                    }
                                }
                            } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((6U == (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                  >> 3U)))) {
                                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                        }
                                    }
                                } else {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                }
                            } else if ((6U == (7U & 
                                               ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                >> 3U)))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                    }
                                }
                            } else {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                            }
                        } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                }
                            }
                        } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                            } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                            }
                        } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                        }
                        if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDZ = 1U;
                                    }
                                }
                            }
                        }
                    }
                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                  >> 4U)))) {
                        if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 2U)))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 1U)))) {
                                            if ((4U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDW = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        } else if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                             >> 2U)))) {
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDW = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else {
                    if ((0x10U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 2U)))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Acc = 1U;
                                        }
                                    }
                                }
                            }
                            if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                    }
                                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                        if ((6U == 
                                             (7U & 
                                              ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                               >> 3U)))) {
                                            if ((2U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                            }
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                        }
                                    }
                                } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((6U == (7U 
                                                & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                   >> 3U)))) {
                                        if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                            if ((2U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                            }
                                        }
                                    } else {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                    }
                                } else if ((6U == (7U 
                                                   & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                      >> 3U)))) {
                                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                        }
                                    }
                                } else {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                }
                            } else if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                 >> 1U)))) {
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                    } else if ((4U 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                    }
                                }
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                    }
                                }
                            }
                        } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                }
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((6U == (7U 
                                                & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                   >> 3U)))) {
                                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                        }
                                    } else if ((2U 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                    }
                                }
                            } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((6U == (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                  >> 3U)))) {
                                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                        }
                                    }
                                } else {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                }
                            } else if ((6U == (7U & 
                                               ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                >> 3U)))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                    }
                                }
                            } else {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                            }
                        } else if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                             >> 1U)))) {
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                }
                            }
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                }
                            } else if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                }
                            }
                        }
                    } else if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Acc = 1U;
                                    }
                                }
                            }
                        }
                        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                }
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((6U == (7U 
                                                & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                   >> 3U)))) {
                                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                        }
                                    } else if ((2U 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                    }
                                }
                            } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((6U == (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                  >> 3U)))) {
                                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                        }
                                    }
                                } else {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                }
                            } else if ((6U == (7U & 
                                               ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                >> 3U)))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                    }
                                }
                            } else {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                            }
                        } else if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                             >> 1U)))) {
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                }
                            }
                        }
                    } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                            }
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                if ((6U == (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                  >> 3U)))) {
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                    }
                                } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                }
                            }
                        } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((6U == (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                              >> 3U)))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                    }
                                }
                            } else {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                            }
                        } else if ((6U == (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                 >> 3U)))) {
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                }
                            }
                        } else {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                        }
                    } else if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                         >> 1U)))) {
                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                            } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                            }
                        } else if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__NMICycle)))) {
                            if (vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IntCycle) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 2U)))) {
                                            if ((8U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                  >> 4U)))) {
                        if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                      >> 3U)))) {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 2U)))) {
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                        if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__NMICycle)))) {
                                            if (vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IntCycle) {
                                                if (
                                                    (1U 
                                                     & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDZ = 1U;
                                                } else if (
                                                           (1U 
                                                            & (~ 
                                                               ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                                >> 1U)))) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                             >> 2U)))) {
                                                        if (
                                                            (8U 
                                                             & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDZ = 1U;
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
            if ((0x40U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                if ((0x36U != (0x3fU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                    if ((6U == (7U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        }
                    } else if ((6U != (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                             >> 3U)))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                    }
                    if ((6U != (7U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                        if ((6U == (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 3U)))) {
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                            }
                        }
                    }
                }
            } else if ((0x20U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                if ((0x10U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((6U != (7U 
                                                & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                   >> 3U)))) {
                                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                        }
                                    }
                                    if ((6U == (7U 
                                                & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                   >> 3U)))) {
                                        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                        }
                                    }
                                }
                            } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((6U == (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                  >> 3U)))) {
                                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                        }
                                        if ((1U & (~ 
                                                   ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 1U)))) {
                                            if ((4U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                            }
                                        }
                                    }
                                } else {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                }
                            } else if ((6U == (7U & 
                                               ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                >> 3U)))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                    }
                                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                        }
                                    }
                                }
                            } else {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            }
                        } else if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                             >> 1U)))) {
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                }
                            }
                        }
                    } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                if ((6U != (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                  >> 3U)))) {
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                    }
                                }
                                if ((6U == (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                  >> 3U)))) {
                                    if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                    }
                                }
                            }
                        } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((6U == (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                              >> 3U)))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                    }
                                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                        }
                                    }
                                }
                            } else {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            }
                        } else if ((6U == (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                 >> 3U)))) {
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                }
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                    }
                                }
                            }
                        } else {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        }
                    } else {
                        if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                }
                            }
                        }
                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 2U)))) {
                                        if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                if ((6U != (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                  >> 3U)))) {
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                    }
                                }
                                if ((6U == (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                  >> 3U)))) {
                                    if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                    }
                                }
                            }
                        } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((6U == (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                              >> 3U)))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                    }
                                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                        }
                                    }
                                }
                            } else {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            }
                        } else if ((6U == (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                 >> 3U)))) {
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                }
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                    }
                                }
                            }
                        } else {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        }
                    } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 2U)))) {
                                    if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                    } else if ((0x10U 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                    }
                                }
                            }
                        }
                    } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        }
                    }
                } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        } else if ((6U != (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                 >> 3U)))) {
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            }
                        }
                        if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                            if ((6U == (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                              >> 3U)))) {
                                if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                }
                            }
                        }
                    } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((6U == (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 3U)))) {
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                }
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                    }
                                }
                            }
                        } else {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        }
                    } else if ((6U == (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                             >> 3U)))) {
                        if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            }
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                }
                            }
                        }
                    } else {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                    }
                } else {
                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                  >> 1U)))) {
                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            }
                        }
                    }
                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 2U)))) {
                                    if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                    } else if ((0x10U 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                    }
                                }
                            }
                        }
                    }
                }
            } else if ((0x10U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            } else if ((6U != (7U & 
                                               ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                >> 3U)))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                }
                            }
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                if ((6U == (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                  >> 3U)))) {
                                    if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                    }
                                }
                            }
                        } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((6U == (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                              >> 3U)))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                    }
                                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                        }
                                    }
                                }
                            } else {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            }
                        } else if ((6U == (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                 >> 3U)))) {
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                }
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                    }
                                }
                            }
                        } else {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        }
                    } else if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                         >> 1U)))) {
                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            }
                        }
                    }
                } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        } else if ((6U != (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                 >> 3U)))) {
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            }
                        }
                        if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                            if ((6U == (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                              >> 3U)))) {
                                if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                }
                            }
                        }
                    } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((6U == (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 3U)))) {
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                }
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                    }
                                }
                            }
                        } else {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        }
                    } else if ((6U == (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                             >> 3U)))) {
                        if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            }
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                }
                            }
                        }
                    } else {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                    }
                } else {
                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                  >> 1U)))) {
                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            }
                        } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        }
                    }
                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                }
                            }
                        }
                    }
                }
            } else if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        } else if ((6U != (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                 >> 3U)))) {
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            }
                        }
                        if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                            if ((6U == (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                              >> 3U)))) {
                                if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                }
                            }
                        }
                    } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((6U == (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 3U)))) {
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                }
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                    }
                                }
                            }
                        } else {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        }
                    } else if ((6U == (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                             >> 3U)))) {
                        if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            }
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                }
                            }
                        }
                    } else {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                    }
                } else if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                     >> 1U)))) {
                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        }
                    }
                }
            } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                    } else if ((6U != (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                             >> 3U)))) {
                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        }
                    }
                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                        if ((6U == (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 3U)))) {
                            if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                            }
                        }
                    }
                } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((6U == (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                      >> 3U)))) {
                        if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            }
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                }
                            }
                        }
                    } else {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                    }
                } else if ((6U == (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                         >> 3U)))) {
                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        }
                        if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                      >> 1U)))) {
                            if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                            }
                        }
                    }
                } else {
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                }
            } else {
                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                              >> 1U)))) {
                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        }
                    }
                }
                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                        }
                    }
                } else if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                    if (vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__NMICycle) {
                        if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                            } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                            }
                        }
                    } else if (vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IntCycle) {
                        if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                            } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                            }
                        }
                    }
                }
            }
        }
        if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                      >> 7U)))) {
            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                          >> 6U)))) {
                if ((0x20U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((0x10U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 2U)))) {
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Arith16 = 1U;
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__no_read = 1U;
                                        } else if (
                                                   (4U 
                                                    & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Arith16 = 1U;
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__no_read = 1U;
                                        }
                                    } else if ((1U 
                                                & (~ 
                                                   ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 1U)))) {
                                        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__no_read = 1U;
                                        }
                                    }
                                }
                            }
                            if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                        if ((6U == 
                                             (7U & 
                                              ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                               >> 3U)))) {
                                            if ((1U 
                                                 & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                                if (
                                                    (2U 
                                                     & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                                }
                                            }
                                        } else {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                        }
                                    } else if ((6U 
                                                == 
                                                (7U 
                                                 & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                    >> 3U)))) {
                                        if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                            if ((2U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 0U;
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                            }
                                        }
                                    } else {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 0U;
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                    }
                                }
                            } else if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                 >> 1U)))) {
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 0U;
                                    } else if ((4U 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 1U;
                                    }
                                }
                            }
                        } else {
                            if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                        if ((6U == 
                                             (7U & 
                                              ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                               >> 3U)))) {
                                            if ((1U 
                                                 & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                                if (
                                                    (2U 
                                                     & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                                }
                                            }
                                        } else {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                        }
                                    } else if ((6U 
                                                == 
                                                (7U 
                                                 & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                    >> 3U)))) {
                                        if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                            if ((2U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 0U;
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                            }
                                        }
                                    } else {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 0U;
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                    }
                                }
                            }
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 2U)))) {
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 1U)))) {
                                            if ((4U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__no_read = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Arith16 = 1U;
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__no_read = 1U;
                                    } else if ((4U 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Arith16 = 1U;
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__no_read = 1U;
                                    }
                                } else if ((1U & (~ 
                                                  ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                   >> 1U)))) {
                                    if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__no_read = 1U;
                                    }
                                }
                            }
                        }
                        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((6U == (7U 
                                                & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                   >> 3U)))) {
                                        if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                            if ((2U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                            }
                                        }
                                    } else {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                    }
                                } else if ((6U == (7U 
                                                   & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                      >> 3U)))) {
                                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 0U;
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                        }
                                    }
                                } else {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 0U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                }
                            }
                        } else if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                             >> 1U)))) {
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 0U;
                                } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 1U;
                                }
                            }
                        }
                    } else {
                        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 0xcU;
                                }
                            } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((6U == (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                  >> 3U)))) {
                                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                                        }
                                    }
                                } else {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                                }
                            } else if ((6U == (7U & 
                                               ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                >> 3U)))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 0U;
                                    }
                                }
                            } else {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 0U;
                            }
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((6U == (7U 
                                                & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                   >> 3U)))) {
                                        if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                            if ((2U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                            }
                                        }
                                    } else {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                    }
                                } else if ((6U == (7U 
                                                   & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                      >> 3U)))) {
                                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                        }
                                    }
                                } else {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                }
                            }
                        }
                        if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__no_read = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                  >> 4U)))) {
                        if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 2U)))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 1U)))) {
                                            if ((1U 
                                                 & (~ 
                                                    ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                     >> 2U)))) {
                                                if (
                                                    (8U 
                                                     & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_WZ = 1U;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        } else if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                             >> 2U)))) {
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 2U)))) {
                                            if ((8U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_WZ = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else if ((0x10U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Arith16 = 1U;
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__no_read = 1U;
                                    } else if ((4U 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Arith16 = 1U;
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__no_read = 1U;
                                    }
                                } else if ((1U & (~ 
                                                  ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                   >> 1U)))) {
                                    if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__no_read = 1U;
                                    }
                                }
                            }
                        }
                        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 8U;
                                }
                            } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((6U == (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                  >> 3U)))) {
                                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                                        }
                                    }
                                } else {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                                }
                            } else if ((6U == (7U & 
                                               ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                >> 3U)))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 0U;
                                    }
                                }
                            } else {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 0U;
                            }
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((6U == (7U 
                                                & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                   >> 3U)))) {
                                        if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                            if ((2U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                            }
                                        }
                                    } else {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                    }
                                } else if ((6U == (7U 
                                                   & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                      >> 3U)))) {
                                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                        }
                                    }
                                } else {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                }
                            }
                        } else if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                             >> 1U)))) {
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 0U;
                                } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 1U;
                                }
                            }
                        }
                    } else {
                        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 8U;
                                }
                            } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((6U == (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                  >> 3U)))) {
                                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                                        }
                                    }
                                } else {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                                }
                            } else if ((6U == (7U & 
                                               ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                >> 3U)))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 0U;
                                    }
                                }
                            } else {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 0U;
                            }
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((6U == (7U 
                                                & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                   >> 3U)))) {
                                        if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                            if ((2U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                            }
                                        }
                                    } else {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                    }
                                } else if ((6U == (7U 
                                                   & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                      >> 3U)))) {
                                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                        }
                                    }
                                } else {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                }
                            }
                        } else if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                             >> 1U)))) {
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                                }
                            }
                        }
                        if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 1U)))) {
                                            if ((4U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__no_read = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                  >> 2U)))) {
                        if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Arith16 = 1U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__no_read = 1U;
                                } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Arith16 = 1U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__no_read = 1U;
                                }
                            }
                        }
                    }
                    if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 8U;
                            }
                        } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((6U == (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                              >> 3U)))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                                    }
                                }
                            } else {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                            }
                        } else if ((6U == (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                 >> 3U)))) {
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 0U;
                                }
                            }
                        } else {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 0U;
                        }
                        if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((6U == (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                  >> 3U)))) {
                                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                        }
                                    }
                                } else {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                }
                            } else if ((6U == (7U & 
                                               ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                >> 3U)))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                    }
                                }
                            } else {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__PreserveC = 1U;
                            }
                        }
                    } else if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                         >> 1U)))) {
                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 0U;
                            } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 1U;
                            }
                        }
                    }
                } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 8U;
                        }
                    } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((6U == (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 3U)))) {
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                                }
                            }
                        } else {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                        }
                    } else if ((6U == (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                             >> 3U)))) {
                        if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 0U;
                            }
                        }
                    } else {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 0U;
                    }
                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                  >> 1U)))) {
                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((6U == (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                              >> 3U)))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                    }
                                }
                            } else {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__PreserveC = 1U;
                            }
                        } else if ((6U == (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                 >> 3U)))) {
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                }
                            }
                        } else {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__PreserveC = 1U;
                        }
                    }
                }
                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                              >> 5U)))) {
                    if ((0x10U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                      >> 3U)))) {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 2U)))) {
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I_DJNZ = 1U;
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__I_DJNZ = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    } else {
        if ((1U != (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ISet))) {
            if ((0x80U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                              >> 6U)))) {
                    if ((0x20U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 1U)))) {
                                            if ((4U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__iorq_i = 1U;
                                            }
                                            if ((1U 
                                                 & (~ 
                                                    ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                     >> 2U)))) {
                                                if (
                                                    (8U 
                                                     & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__no_read = 1U;
                                                }
                                            }
                                        }
                                    }
                                } else if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__iorq_i = 1U;
                                    }
                                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 2U)))) {
                                            if ((8U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__no_read = 1U;
                                            }
                                        }
                                    }
                                }
                            } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__no_read = 1U;
                                        } else if (
                                                   (8U 
                                                    & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__no_read = 1U;
                                        }
                                    }
                                }
                            } else if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 2U)))) {
                                        if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__no_read = 1U;
                                        }
                                    }
                                }
                            }
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            } else if ((0x40U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                if ((0x20U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((0x10U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 2U)))) {
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                        if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                            if ((2U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__iorq_i = 1U;
                                            }
                                        }
                                    } else if ((1U 
                                                & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__iorq_i = 1U;
                                        }
                                    }
                                }
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__no_read = 1U;
                                        } else if (
                                                   (4U 
                                                    & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__no_read = 1U;
                                        }
                                    }
                                }
                            }
                        } else if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                             >> 2U)))) {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__iorq_i = 1U;
                                        }
                                    }
                                } else if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__iorq_i = 1U;
                                    }
                                }
                            }
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__no_read = 1U;
                                    } else if ((4U 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__no_read = 1U;
                                    }
                                }
                            }
                        }
                    } else if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__iorq_i = 1U;
                                        }
                                    }
                                } else if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__iorq_i = 1U;
                                    }
                                }
                            }
                        }
                        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__no_read = 1U;
                                    }
                                }
                            }
                        } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__no_read = 1U;
                                } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__no_read = 1U;
                                }
                            }
                        }
                    } else if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                         >> 2U)))) {
                        if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__iorq_i = 1U;
                                    }
                                }
                            } else if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__iorq_i = 1U;
                                }
                            }
                        }
                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__no_read = 1U;
                                } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__no_read = 1U;
                                }
                            }
                        }
                    }
                } else if ((0x10U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__iorq_i = 1U;
                                        }
                                    }
                                } else if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__iorq_i = 1U;
                                    }
                                }
                            }
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__no_read = 1U;
                                    } else if ((4U 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__no_read = 1U;
                                    }
                                }
                            }
                        }
                    } else if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                         >> 2U)))) {
                        if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__iorq_i = 1U;
                                    }
                                }
                            } else if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__iorq_i = 1U;
                                }
                            }
                        }
                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__no_read = 1U;
                                } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__no_read = 1U;
                                }
                            }
                        }
                    }
                } else if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                  >> 2U)))) {
                        if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__iorq_i = 1U;
                                    }
                                }
                            } else if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__iorq_i = 1U;
                                }
                            }
                        }
                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__no_read = 1U;
                                } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__no_read = 1U;
                                }
                            }
                        }
                    }
                } else if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                     >> 2U)))) {
                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                  >> 1U)))) {
                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__iorq_i = 1U;
                                }
                            }
                        } else if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__iorq_i = 1U;
                            }
                        }
                    }
                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__no_read = 1U;
                            } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__no_read = 1U;
                            }
                        }
                    }
                }
            }
            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                          >> 7U)))) {
                if ((0x40U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((0x20U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((0x10U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                  >> 1U)))) {
                                        if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Acc = 1U;
                                        }
                                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                            if ((1U 
                                                 & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                                if (
                                                    (2U 
                                                     & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDZ = 1U;
                                                }
                                            }
                                        }
                                    }
                                } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDZ = 1U;
                                        }
                                    }
                                }
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                              >> 2U)))) {
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                            if ((1U 
                                                 & (~ 
                                                    ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                     >> 1U)))) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                         >> 2U)))) {
                                                    if (
                                                        (8U 
                                                         & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_WZ = 1U;
                                                    }
                                                }
                                                if (
                                                    (4U 
                                                     & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDW = 1U;
                                                }
                                            }
                                            if ((2U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                            } else if (
                                                       (4U 
                                                        & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                            }
                                        }
                                    }
                                }
                            } else {
                                if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                  >> 1U)))) {
                                        if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Acc = 1U;
                                        }
                                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                            if ((1U 
                                                 & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                                if (
                                                    (2U 
                                                     & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDZ = 1U;
                                                }
                                            }
                                        }
                                    }
                                } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDZ = 1U;
                                        }
                                    }
                                }
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                              >> 2U)))) {
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                            if ((1U 
                                                 & (~ 
                                                    ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                     >> 1U)))) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                         >> 2U)))) {
                                                    if (
                                                        (8U 
                                                         & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_WZ = 1U;
                                                    }
                                                }
                                                if (
                                                    (4U 
                                                     & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDW = 1U;
                                                }
                                            }
                                            if ((2U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                            } else if (
                                                       (4U 
                                                        & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        } else if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Acc = 1U;
                                    }
                                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                        if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                            if ((2U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDZ = 1U;
                                            }
                                        }
                                    }
                                }
                            } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDZ = 1U;
                                    }
                                }
                            }
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 2U)))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 1U)))) {
                                            if ((1U 
                                                 & (~ 
                                                    ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                     >> 2U)))) {
                                                if (
                                                    (8U 
                                                     & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_WZ = 1U;
                                                }
                                            }
                                            if ((4U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDW = 1U;
                                            }
                                        }
                                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                        } else if (
                                                   (4U 
                                                    & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                        }
                                    }
                                }
                            }
                        } else {
                            if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Acc = 1U;
                                    }
                                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                        if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                            if ((2U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDZ = 1U;
                                            }
                                        }
                                    }
                                }
                            } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDZ = 1U;
                                    }
                                }
                            }
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 2U)))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 1U)))) {
                                            if ((1U 
                                                 & (~ 
                                                    ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                     >> 2U)))) {
                                                if (
                                                    (8U 
                                                     & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_WZ = 1U;
                                                }
                                            }
                                            if ((4U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDW = 1U;
                                            }
                                        }
                                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                        } else if (
                                                   (4U 
                                                    & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((0x10U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Acc = 1U;
                                    }
                                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                        if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                            if ((2U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDZ = 1U;
                                            }
                                        }
                                    }
                                }
                            } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDZ = 1U;
                                    }
                                }
                            }
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 2U)))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 1U)))) {
                                            if ((1U 
                                                 & (~ 
                                                    ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                     >> 2U)))) {
                                                if (
                                                    (8U 
                                                     & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_WZ = 1U;
                                                }
                                            }
                                            if ((4U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDW = 1U;
                                            }
                                        }
                                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                        } else if (
                                                   (4U 
                                                    & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                        }
                                    }
                                }
                            }
                        } else {
                            if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Acc = 1U;
                                    }
                                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                        if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                            if ((2U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDZ = 1U;
                                            }
                                        }
                                    }
                                }
                            } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDZ = 1U;
                                    }
                                }
                            }
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 2U)))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 1U)))) {
                                            if ((1U 
                                                 & (~ 
                                                    ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                     >> 2U)))) {
                                                if (
                                                    (8U 
                                                     & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_WZ = 1U;
                                                }
                                            }
                                            if ((4U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDW = 1U;
                                            }
                                        }
                                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                        } else if (
                                                   (4U 
                                                    & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Acc = 1U;
                                }
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDZ = 1U;
                                        }
                                    }
                                }
                            }
                        } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDZ = 1U;
                                }
                            }
                        }
                        if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 2U)))) {
                                            if ((8U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_WZ = 1U;
                                            }
                                        }
                                        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDW = 1U;
                                        }
                                    }
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                    } else if ((4U 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                    }
                                }
                            }
                        }
                    } else {
                        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Acc = 1U;
                                }
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDZ = 1U;
                                        }
                                    }
                                }
                            }
                        } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDZ = 1U;
                                }
                            }
                        }
                        if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 2U)))) {
                                            if ((8U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_WZ = 1U;
                                            }
                                        }
                                        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__LDW = 1U;
                                        }
                                    }
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                    } else if ((4U 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if ((1U == (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ISet))) {
            if ((0x80U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                if ((0x40U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 0xaU;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                }
                            } else if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                 | ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 6U))))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 0xaU;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                }
                            }
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                              | ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                 >> 6U))))) {
                                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                        }
                                    }
                                }
                            }
                        } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 0xaU;
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        }
                    } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 0xaU;
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                    }
                } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 0xbU;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            }
                        } else if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                             | ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                >> 6U))))) {
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 0xbU;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            }
                        }
                        if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                          | ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                             >> 6U))))) {
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                    }
                                }
                            }
                        }
                    } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 0xbU;
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                    }
                } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 0xbU;
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                }
            } else {
                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                              >> 6U)))) {
                    if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                }
                            } else if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                 | ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 6U))))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                }
                            }
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                              | ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                 >> 6U))))) {
                                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                        }
                                    }
                                }
                            }
                        } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        }
                    } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                    }
                }
                if ((0x40U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 9U;
                                }
                            } else if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                 | ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 6U))))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 9U;
                                }
                            }
                        } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 9U;
                        }
                    } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 9U;
                    }
                } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 8U;
                            }
                        } else if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                             | ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                >> 6U))))) {
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 8U;
                            }
                        }
                    } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 8U;
                    }
                } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 8U;
                }
            }
        } else if ((0x80U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                          >> 6U)))) {
                if ((0x20U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                }
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                        }
                                    }
                                }
                            } else {
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                }
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                        }
                                    }
                                }
                            }
                        } else {
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 7U;
                                    }
                                }
                            } else if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 0U;
                                }
                            }
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else if ((0x40U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
            if ((0x20U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                if ((0x10U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                                }
                            }
                        } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 1U;
                                } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 1U;
                                }
                            }
                        }
                        if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 2U)))) {
                                            if ((8U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                            } else if (
                                                       (0x10U 
                                                        & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                            }
                                        }
                                    }
                                } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                }
                            } else if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        if ((6U != 
                                             (7U & 
                                              ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                               >> 3U)))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                        }
                                    }
                                }
                            }
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    } else {
                        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                                }
                            }
                        } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 3U;
                                } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 3U;
                                }
                            }
                        }
                        if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                    } else if ((4U 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                    }
                                }
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 2U)))) {
                                            if ((8U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                            } else if (
                                                       (0x10U 
                                                        & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                            }
                                        }
                                    }
                                }
                            } else {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            if ((6U 
                                                 != 
                                                 (7U 
                                                  & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                     >> 3U)))) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                            }
                                        }
                                    }
                                }
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 0xdU;
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                    }
                                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 2U)))) {
                                        if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                        }
                                    }
                                }
                            }
                        } else if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                        }
                    } else {
                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 1U;
                                } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 1U;
                                }
                            }
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 2U)))) {
                                        if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                        } else if (
                                                   (0x10U 
                                                    & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                        }
                                    }
                                }
                            } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            }
                        } else if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    if ((6U != (7U 
                                                & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                   >> 3U)))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                    }
                                }
                            }
                        }
                        if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                    }
                                }
                            }
                        }
                    }
                } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 0xeU;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                }
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 2U)))) {
                                    if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                    }
                                }
                            }
                        }
                    } else if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                    }
                } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 3U;
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 3U;
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        }
                    }
                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                      >> 1U)))) {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 2U)))) {
                                if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                } else if ((0x10U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                }
                            }
                        }
                    }
                } else {
                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                        if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                if ((6U != (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                  >> 3U)))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                }
                            }
                        }
                    }
                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                            }
                        }
                    }
                }
            } else if ((0x10U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                            }
                        }
                    } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 1U;
                            } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 1U;
                            }
                        }
                    }
                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 2U)))) {
                                        if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                        } else if (
                                                   (0x10U 
                                                    & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                        }
                                    }
                                }
                            } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            }
                        } else if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    if ((6U != (7U 
                                                & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                   >> 3U)))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                    }
                                }
                            }
                        }
                        if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                    }
                                }
                            }
                        }
                    }
                } else {
                    if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                            }
                        }
                    } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 3U;
                            } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 3U;
                            }
                        }
                    }
                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                }
                            }
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 2U)))) {
                                        if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                        } else if (
                                                   (0x10U 
                                                    & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                        }
                                    }
                                }
                            }
                        } else {
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        if ((6U != 
                                             (7U & 
                                              ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                               >> 3U)))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                        }
                                    }
                                }
                            }
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                    }
                                }
                            }
                        }
                    }
                }
            } else if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                  >> 1U)))) {
                        if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                        }
                    }
                } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 1U;
                        } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 1U;
                        }
                    }
                }
                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                              >> 2U)))) {
                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 2U)))) {
                                    if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                    } else if ((0x10U 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                    }
                                }
                            }
                        } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        }
                    } else if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                        if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                if ((6U != (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                  >> 3U)))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                }
                            }
                        }
                    }
                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                  >> 1U)))) {
                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                }
                            }
                        }
                    }
                }
            } else {
                if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                  >> 1U)))) {
                        if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                        }
                    }
                } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 3U;
                        } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ALU_Op = 3U;
                        }
                    }
                }
                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                              >> 2U)))) {
                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            }
                        }
                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 2U)))) {
                                    if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                    } else if ((0x10U 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                    }
                                }
                            }
                        }
                    } else {
                        if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    if ((6U != (7U 
                                                & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                   >> 3U)))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                    }
                                }
                            }
                        }
                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__write = 1U;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x20U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
    }
    if ((0x40U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
        if ((1U & (~ ((0x36U == (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)) 
                      | (1U == (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ISet)))))) {
            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__no_read = 1U;
        }
        if (((0x36U == (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)) 
             | (1U == (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ISet)))) {
            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Inc_PC = 1U;
        }
    }
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__JumpE = 0U;
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Jump = 0U;
    sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD 
        = (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                 >> 3U));
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__SSS 
        = (7U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR));
    sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR 
        = (3U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                 >> 4U));
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 1U;
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates 
        = ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))
            ? 4U : 3U);
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 0U;
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 0U;
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To = 0U;
    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 7U;
    if ((0U == (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ISet))) {
        if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                      >> 7U)))) {
            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                          >> 6U)))) {
                if ((0x20U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((0x10U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 2U)))) {
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 1U)))) {
                                            if ((4U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__JumpE = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        } else if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                             >> 2U)))) {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__JumpE = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__JumpE = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                         >> 2U)))) {
                        if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__JumpE = 1U;
                                    }
                                }
                            }
                        }
                    }
                } else if ((0x10U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__JumpE = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                         >> 2U)))) {
                        if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__JumpE = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if ((0x80U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
            if ((0x40U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                if ((0x20U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((0x10U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 2U)))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 1U)))) {
                                            if ((4U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__77__cc 
                                                    = 
                                                    (7U 
                                                     & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                        >> 3U));
                                                vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__77__FF 
                                                    = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F;
                                                vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__77__Vfuncout 
                                                    = 
                                                    (1U 
                                                     & ((4U 
                                                         & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__77__cc))
                                                         ? 
                                                        ((2U 
                                                          & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__77__cc))
                                                          ? 
                                                         ((1U 
                                                           & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__77__cc))
                                                           ? 
                                                          ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__77__FF) 
                                                           >> 7U)
                                                           : 
                                                          (~ 
                                                           ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__77__FF) 
                                                            >> 7U)))
                                                          : 
                                                         ((1U 
                                                           & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__77__cc))
                                                           ? 
                                                          ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__77__FF) 
                                                           >> 2U)
                                                           : 
                                                          (~ 
                                                           ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__77__FF) 
                                                            >> 2U))))
                                                         : 
                                                        ((2U 
                                                          & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__77__cc))
                                                          ? 
                                                         ((1U 
                                                           & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__77__cc))
                                                           ? (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__77__FF)
                                                           : 
                                                          (~ (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__77__FF)))
                                                          : 
                                                         ((1U 
                                                           & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__77__cc))
                                                           ? 
                                                          ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__77__FF) 
                                                           >> 6U)
                                                           : 
                                                          (~ 
                                                           ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__77__FF) 
                                                            >> 6U))))));
                                                if (vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__77__Vfuncout) {
                                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Jump = 1U;
                                                }
                                            }
                                        }
                                    }
                                } else if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 1U)))) {
                                            if ((4U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Jump = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                            if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 5U;
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 0xdU;
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 0xcU;
                                        }
                                    } else {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                                                = (
                                                   (8U 
                                                    & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                                                   | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__SSS));
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                                = (7U 
                                                   | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To));
                                        }
                                    }
                                } else if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 5U;
                                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__76__cc 
                                                = (7U 
                                                   & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                      >> 3U));
                                            vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__76__FF 
                                                = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F;
                                            vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__76__Vfuncout 
                                                = (1U 
                                                   & ((4U 
                                                       & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__76__cc))
                                                       ? 
                                                      ((2U 
                                                        & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__76__cc))
                                                        ? 
                                                       ((1U 
                                                         & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__76__cc))
                                                         ? 
                                                        ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__76__FF) 
                                                         >> 7U)
                                                         : 
                                                        (~ 
                                                         ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__76__FF) 
                                                          >> 7U)))
                                                        : 
                                                       ((1U 
                                                         & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__76__cc))
                                                         ? 
                                                        ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__76__FF) 
                                                         >> 2U)
                                                         : 
                                                        (~ 
                                                         ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__76__FF) 
                                                          >> 2U))))
                                                       : 
                                                      ((2U 
                                                        & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__76__cc))
                                                        ? 
                                                       ((1U 
                                                         & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__76__cc))
                                                         ? (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__76__FF)
                                                         : 
                                                        (~ (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__76__FF)))
                                                        : 
                                                       ((1U 
                                                         & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__76__cc))
                                                         ? 
                                                        ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__76__FF) 
                                                         >> 6U)
                                                         : 
                                                        (~ 
                                                         ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__76__FF) 
                                                          >> 6U))))));
                                            if (vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__76__Vfuncout) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 4U;
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 0xdU;
                                            } else {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                                            }
                                        } else if (
                                                   (8U 
                                                    & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 0xcU;
                                        }
                                    }
                                }
                            } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                                }
                            } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 6U;
                            } else {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__78__cc 
                                        = (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                 >> 3U));
                                    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__78__FF 
                                        = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 5U;
                                    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__78__Vfuncout 
                                        = (1U & ((4U 
                                                  & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__78__cc))
                                                  ? 
                                                 ((2U 
                                                   & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__78__cc))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__78__cc))
                                                    ? 
                                                   ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__78__FF) 
                                                    >> 7U)
                                                    : 
                                                   (~ 
                                                    ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__78__FF) 
                                                     >> 7U)))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__78__cc))
                                                    ? 
                                                   ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__78__FF) 
                                                    >> 2U)
                                                    : 
                                                   (~ 
                                                    ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__78__FF) 
                                                     >> 2U))))
                                                  : 
                                                 ((2U 
                                                   & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__78__cc))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__78__cc))
                                                    ? (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__78__FF)
                                                    : 
                                                   (~ (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__78__FF)))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__78__cc))
                                                    ? 
                                                   ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__78__FF) 
                                                    >> 6U)
                                                    : 
                                                   (~ 
                                                    ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__78__FF) 
                                                     >> 6U))))));
                                    if (vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__78__Vfuncout) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                    } else {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 1U;
                                    }
                                } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                                }
                            }
                        } else {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 2U)))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 1U)))) {
                                            if ((4U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__80__cc 
                                                    = 
                                                    (7U 
                                                     & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                        >> 3U));
                                                vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__80__FF 
                                                    = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F;
                                                vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__80__Vfuncout 
                                                    = 
                                                    (1U 
                                                     & ((4U 
                                                         & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__80__cc))
                                                         ? 
                                                        ((2U 
                                                          & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__80__cc))
                                                          ? 
                                                         ((1U 
                                                           & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__80__cc))
                                                           ? 
                                                          ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__80__FF) 
                                                           >> 7U)
                                                           : 
                                                          (~ 
                                                           ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__80__FF) 
                                                            >> 7U)))
                                                          : 
                                                         ((1U 
                                                           & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__80__cc))
                                                           ? 
                                                          ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__80__FF) 
                                                           >> 2U)
                                                           : 
                                                          (~ 
                                                           ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__80__FF) 
                                                            >> 2U))))
                                                         : 
                                                        ((2U 
                                                          & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__80__cc))
                                                          ? 
                                                         ((1U 
                                                           & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__80__cc))
                                                           ? (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__80__FF)
                                                           : 
                                                          (~ (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__80__FF)))
                                                          : 
                                                         ((1U 
                                                           & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__80__cc))
                                                           ? 
                                                          ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__80__FF) 
                                                           >> 6U)
                                                           : 
                                                          (~ 
                                                           ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__80__FF) 
                                                            >> 6U))))));
                                                if (vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__80__Vfuncout) {
                                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Jump = 1U;
                                                }
                                            }
                                        }
                                    }
                                } else if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 1U)))) {
                                            if ((4U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Jump = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                            if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 5U;
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 0xdU;
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 0xcU;
                                        }
                                    } else {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                                                = (
                                                   (8U 
                                                    & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                                                   | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__SSS));
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                                = (7U 
                                                   | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To));
                                        }
                                    }
                                } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 5U;
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                                            = ((3U 
                                                == (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR))
                                                ? 7U
                                                : ((IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR) 
                                                   << 1U));
                                    } else if ((2U 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                                            = ((3U 
                                                == (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR))
                                                ? 0xbU
                                                : (1U 
                                                   | ((IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR) 
                                                      << 1U)));
                                    }
                                } else {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 5U;
                                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__79__cc 
                                                = (7U 
                                                   & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                      >> 3U));
                                            vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__79__FF 
                                                = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F;
                                            vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__79__Vfuncout 
                                                = (1U 
                                                   & ((4U 
                                                       & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__79__cc))
                                                       ? 
                                                      ((2U 
                                                        & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__79__cc))
                                                        ? 
                                                       ((1U 
                                                         & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__79__cc))
                                                         ? 
                                                        ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__79__FF) 
                                                         >> 7U)
                                                         : 
                                                        (~ 
                                                         ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__79__FF) 
                                                          >> 7U)))
                                                        : 
                                                       ((1U 
                                                         & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__79__cc))
                                                         ? 
                                                        ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__79__FF) 
                                                         >> 2U)
                                                         : 
                                                        (~ 
                                                         ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__79__FF) 
                                                          >> 2U))))
                                                       : 
                                                      ((2U 
                                                        & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__79__cc))
                                                        ? 
                                                       ((1U 
                                                         & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__79__cc))
                                                         ? (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__79__FF)
                                                         : 
                                                        (~ (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__79__FF)))
                                                        : 
                                                       ((1U 
                                                         & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__79__cc))
                                                         ? 
                                                        ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__79__FF) 
                                                         >> 6U)
                                                         : 
                                                        (~ 
                                                         ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__79__FF) 
                                                          >> 6U))))));
                                            if (vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__79__Vfuncout) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 4U;
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 0xdU;
                                            } else {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                                            }
                                        } else if (
                                                   (8U 
                                                    & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 0xcU;
                                        }
                                    }
                                }
                            } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                                }
                            } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                        = ((3U == (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR))
                                            ? 0xbU : 
                                           ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                            | (1U | 
                                               ((IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR) 
                                                << 1U))));
                                } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                        = ((3U == (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR))
                                            ? 7U : 
                                           ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                            | ((IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR) 
                                               << 1U)));
                                }
                            } else {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__81__cc 
                                        = (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                 >> 3U));
                                    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__81__FF 
                                        = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 5U;
                                    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__81__Vfuncout 
                                        = (1U & ((4U 
                                                  & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__81__cc))
                                                  ? 
                                                 ((2U 
                                                   & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__81__cc))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__81__cc))
                                                    ? 
                                                   ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__81__FF) 
                                                    >> 7U)
                                                    : 
                                                   (~ 
                                                    ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__81__FF) 
                                                     >> 7U)))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__81__cc))
                                                    ? 
                                                   ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__81__FF) 
                                                    >> 2U)
                                                    : 
                                                   (~ 
                                                    ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__81__FF) 
                                                     >> 2U))))
                                                  : 
                                                 ((2U 
                                                   & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__81__cc))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__81__cc))
                                                    ? (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__81__FF)
                                                    : 
                                                   (~ (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__81__FF)))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__81__cc))
                                                    ? 
                                                   ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__81__FF) 
                                                    >> 6U)
                                                    : 
                                                   (~ 
                                                    ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__81__FF) 
                                                     >> 6U))))));
                                    if (vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__81__Vfuncout) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                    } else {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 1U;
                                    }
                                } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                                }
                            }
                        }
                    } else if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__83__cc 
                                                = (7U 
                                                   & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                      >> 3U));
                                            vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__83__FF 
                                                = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F;
                                            vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__83__Vfuncout 
                                                = (1U 
                                                   & ((4U 
                                                       & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__83__cc))
                                                       ? 
                                                      ((2U 
                                                        & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__83__cc))
                                                        ? 
                                                       ((1U 
                                                         & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__83__cc))
                                                         ? 
                                                        ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__83__FF) 
                                                         >> 7U)
                                                         : 
                                                        (~ 
                                                         ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__83__FF) 
                                                          >> 7U)))
                                                        : 
                                                       ((1U 
                                                         & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__83__cc))
                                                         ? 
                                                        ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__83__FF) 
                                                         >> 2U)
                                                         : 
                                                        (~ 
                                                         ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__83__FF) 
                                                          >> 2U))))
                                                       : 
                                                      ((2U 
                                                        & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__83__cc))
                                                        ? 
                                                       ((1U 
                                                         & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__83__cc))
                                                         ? (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__83__FF)
                                                         : 
                                                        (~ (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__83__FF)))
                                                        : 
                                                       ((1U 
                                                         & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__83__cc))
                                                         ? 
                                                        ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__83__FF) 
                                                         >> 6U)
                                                         : 
                                                        (~ 
                                                         ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__83__FF) 
                                                          >> 6U))))));
                                            if (vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__83__Vfuncout) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Jump = 1U;
                                            }
                                        }
                                    }
                                }
                            } else if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Jump = 1U;
                                        }
                                    }
                                }
                            }
                        }
                        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 5U;
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 0xdU;
                                    } else if ((2U 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 0xcU;
                                    }
                                } else {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                                            = ((8U 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                                               | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__SSS));
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                            = (7U | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To));
                                    }
                                }
                            } else if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 5U;
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__82__cc 
                                            = (7U & 
                                               ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                >> 3U));
                                        vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__82__FF 
                                            = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F;
                                        vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__82__Vfuncout 
                                            = (1U & 
                                               ((4U 
                                                 & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__82__cc))
                                                 ? 
                                                ((2U 
                                                  & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__82__cc))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__82__cc))
                                                   ? 
                                                  ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__82__FF) 
                                                   >> 7U)
                                                   : 
                                                  (~ 
                                                   ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__82__FF) 
                                                    >> 7U)))
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__82__cc))
                                                   ? 
                                                  ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__82__FF) 
                                                   >> 2U)
                                                   : 
                                                  (~ 
                                                   ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__82__FF) 
                                                    >> 2U))))
                                                 : 
                                                ((2U 
                                                  & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__82__cc))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__82__cc))
                                                   ? (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__82__FF)
                                                   : 
                                                  (~ (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__82__FF)))
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__82__cc))
                                                   ? 
                                                  ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__82__FF) 
                                                   >> 6U)
                                                   : 
                                                  (~ 
                                                   ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__82__FF) 
                                                    >> 6U))))));
                                        if (vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__82__Vfuncout) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 4U;
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 0xdU;
                                        } else {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                                        }
                                    } else if ((8U 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 0xcU;
                                    }
                                }
                            }
                        } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                            }
                        } else if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__84__cc 
                                    = (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                             >> 3U));
                                vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__84__FF 
                                    = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 5U;
                                vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__84__Vfuncout 
                                    = (1U & ((4U & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__84__cc))
                                              ? ((2U 
                                                  & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__84__cc))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__84__cc))
                                                   ? 
                                                  ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__84__FF) 
                                                   >> 7U)
                                                   : 
                                                  (~ 
                                                   ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__84__FF) 
                                                    >> 7U)))
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__84__cc))
                                                   ? 
                                                  ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__84__FF) 
                                                   >> 2U)
                                                   : 
                                                  (~ 
                                                   ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__84__FF) 
                                                    >> 2U))))
                                              : ((2U 
                                                  & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__84__cc))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__84__cc))
                                                   ? (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__84__FF)
                                                   : 
                                                  (~ (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__84__FF)))
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__84__cc))
                                                   ? 
                                                  ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__84__FF) 
                                                   >> 6U)
                                                   : 
                                                  (~ 
                                                   ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__84__FF) 
                                                    >> 6U))))));
                                if (vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__84__Vfuncout) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                } else {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 1U;
                                }
                            } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                            } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                            }
                        }
                    } else {
                        if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__86__cc 
                                                = (7U 
                                                   & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                      >> 3U));
                                            vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__86__FF 
                                                = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F;
                                            vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__86__Vfuncout 
                                                = (1U 
                                                   & ((4U 
                                                       & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__86__cc))
                                                       ? 
                                                      ((2U 
                                                        & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__86__cc))
                                                        ? 
                                                       ((1U 
                                                         & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__86__cc))
                                                         ? 
                                                        ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__86__FF) 
                                                         >> 7U)
                                                         : 
                                                        (~ 
                                                         ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__86__FF) 
                                                          >> 7U)))
                                                        : 
                                                       ((1U 
                                                         & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__86__cc))
                                                         ? 
                                                        ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__86__FF) 
                                                         >> 2U)
                                                         : 
                                                        (~ 
                                                         ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__86__FF) 
                                                          >> 2U))))
                                                       : 
                                                      ((2U 
                                                        & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__86__cc))
                                                        ? 
                                                       ((1U 
                                                         & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__86__cc))
                                                         ? (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__86__FF)
                                                         : 
                                                        (~ (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__86__FF)))
                                                        : 
                                                       ((1U 
                                                         & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__86__cc))
                                                         ? 
                                                        ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__86__FF) 
                                                         >> 6U)
                                                         : 
                                                        (~ 
                                                         ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__86__FF) 
                                                          >> 6U))))));
                                            if (vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__86__Vfuncout) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Jump = 1U;
                                            }
                                        }
                                    }
                                }
                            } else if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Jump = 1U;
                                        }
                                    }
                                }
                            }
                        }
                        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 5U;
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 0xdU;
                                    } else if ((2U 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 0xcU;
                                    }
                                } else {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                                            = ((8U 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                                               | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__SSS));
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                            = (7U | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To));
                                    }
                                }
                            } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 5U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                                        = ((3U == (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR))
                                            ? 7U : 
                                           ((IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR) 
                                            << 1U));
                                } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                                        = ((3U == (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR))
                                            ? 0xbU : 
                                           (1U | ((IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR) 
                                                  << 1U)));
                                }
                            } else {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 5U;
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__85__cc 
                                            = (7U & 
                                               ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                >> 3U));
                                        vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__85__FF 
                                            = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F;
                                        vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__85__Vfuncout 
                                            = (1U & 
                                               ((4U 
                                                 & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__85__cc))
                                                 ? 
                                                ((2U 
                                                  & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__85__cc))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__85__cc))
                                                   ? 
                                                  ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__85__FF) 
                                                   >> 7U)
                                                   : 
                                                  (~ 
                                                   ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__85__FF) 
                                                    >> 7U)))
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__85__cc))
                                                   ? 
                                                  ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__85__FF) 
                                                   >> 2U)
                                                   : 
                                                  (~ 
                                                   ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__85__FF) 
                                                    >> 2U))))
                                                 : 
                                                ((2U 
                                                  & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__85__cc))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__85__cc))
                                                   ? (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__85__FF)
                                                   : 
                                                  (~ (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__85__FF)))
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__85__cc))
                                                   ? 
                                                  ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__85__FF) 
                                                   >> 6U)
                                                   : 
                                                  (~ 
                                                   ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__85__FF) 
                                                    >> 6U))))));
                                        if (vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__85__Vfuncout) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 4U;
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 0xdU;
                                        } else {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                                        }
                                    } else if ((8U 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 0xcU;
                                    }
                                }
                            }
                        } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 5U;
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To = 5U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 5U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 4U;
                                } else if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To = 4U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 4U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                } else if ((0x10U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 5U;
                                }
                            } else {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                            }
                        } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                            } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                    = ((3U == (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR))
                                        ? 0xbU : ((8U 
                                                   & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                                  | (1U 
                                                     | ((IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR) 
                                                        << 1U))));
                            } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                    = ((3U == (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR))
                                        ? 7U : ((8U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                                | ((IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR) 
                                                   << 1U)));
                            }
                        } else {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__87__cc 
                                    = (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                             >> 3U));
                                vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__87__FF 
                                    = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 5U;
                                vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__87__Vfuncout 
                                    = (1U & ((4U & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__87__cc))
                                              ? ((2U 
                                                  & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__87__cc))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__87__cc))
                                                   ? 
                                                  ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__87__FF) 
                                                   >> 7U)
                                                   : 
                                                  (~ 
                                                   ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__87__FF) 
                                                    >> 7U)))
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__87__cc))
                                                   ? 
                                                  ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__87__FF) 
                                                   >> 2U)
                                                   : 
                                                  (~ 
                                                   ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__87__FF) 
                                                    >> 2U))))
                                              : ((2U 
                                                  & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__87__cc))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__87__cc))
                                                   ? (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__87__FF)
                                                   : 
                                                  (~ (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__87__FF)))
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__87__cc))
                                                   ? 
                                                  ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__87__FF) 
                                                   >> 6U)
                                                   : 
                                                  (~ 
                                                   ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__87__FF) 
                                                    >> 6U))))));
                                if (vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__87__Vfuncout) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                } else {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 1U;
                                }
                            } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                            } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                            }
                        }
                    }
                } else if ((0x10U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__89__cc 
                                                = (7U 
                                                   & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                      >> 3U));
                                            vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__89__FF 
                                                = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F;
                                            vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__89__Vfuncout 
                                                = (1U 
                                                   & ((4U 
                                                       & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__89__cc))
                                                       ? 
                                                      ((2U 
                                                        & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__89__cc))
                                                        ? 
                                                       ((1U 
                                                         & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__89__cc))
                                                         ? 
                                                        ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__89__FF) 
                                                         >> 7U)
                                                         : 
                                                        (~ 
                                                         ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__89__FF) 
                                                          >> 7U)))
                                                        : 
                                                       ((1U 
                                                         & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__89__cc))
                                                         ? 
                                                        ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__89__FF) 
                                                         >> 2U)
                                                         : 
                                                        (~ 
                                                         ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__89__FF) 
                                                          >> 2U))))
                                                       : 
                                                      ((2U 
                                                        & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__89__cc))
                                                        ? 
                                                       ((1U 
                                                         & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__89__cc))
                                                         ? (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__89__FF)
                                                         : 
                                                        (~ (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__89__FF)))
                                                        : 
                                                       ((1U 
                                                         & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__89__cc))
                                                         ? 
                                                        ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__89__FF) 
                                                         >> 6U)
                                                         : 
                                                        (~ 
                                                         ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__89__FF) 
                                                          >> 6U))))));
                                            if (vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__89__Vfuncout) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Jump = 1U;
                                            }
                                        }
                                    }
                                }
                            } else if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Jump = 1U;
                                        }
                                    }
                                }
                            }
                        }
                        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 5U;
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 0xdU;
                                    } else if ((2U 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 0xcU;
                                    }
                                } else {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                                            = ((8U 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                                               | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__SSS));
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                            = (7U | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To));
                                    }
                                }
                            } else if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 5U;
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__88__cc 
                                            = (7U & 
                                               ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                >> 3U));
                                        vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__88__FF 
                                            = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F;
                                        vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__88__Vfuncout 
                                            = (1U & 
                                               ((4U 
                                                 & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__88__cc))
                                                 ? 
                                                ((2U 
                                                  & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__88__cc))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__88__cc))
                                                   ? 
                                                  ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__88__FF) 
                                                   >> 7U)
                                                   : 
                                                  (~ 
                                                   ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__88__FF) 
                                                    >> 7U)))
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__88__cc))
                                                   ? 
                                                  ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__88__FF) 
                                                   >> 2U)
                                                   : 
                                                  (~ 
                                                   ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__88__FF) 
                                                    >> 2U))))
                                                 : 
                                                ((2U 
                                                  & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__88__cc))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__88__cc))
                                                   ? (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__88__FF)
                                                   : 
                                                  (~ (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__88__FF)))
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__88__cc))
                                                   ? 
                                                  ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__88__FF) 
                                                   >> 6U)
                                                   : 
                                                  (~ 
                                                   ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__88__FF) 
                                                    >> 6U))))));
                                        if (vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__88__Vfuncout) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 4U;
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 0xdU;
                                        } else {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                                        }
                                    } else if ((8U 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 0xcU;
                                    }
                                }
                            }
                        } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 4U;
                                }
                            } else {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                            }
                        } else if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__90__cc 
                                    = (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                             >> 3U));
                                vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__90__FF 
                                    = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 5U;
                                vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__90__Vfuncout 
                                    = (1U & ((4U & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__90__cc))
                                              ? ((2U 
                                                  & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__90__cc))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__90__cc))
                                                   ? 
                                                  ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__90__FF) 
                                                   >> 7U)
                                                   : 
                                                  (~ 
                                                   ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__90__FF) 
                                                    >> 7U)))
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__90__cc))
                                                   ? 
                                                  ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__90__FF) 
                                                   >> 2U)
                                                   : 
                                                  (~ 
                                                   ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__90__FF) 
                                                    >> 2U))))
                                              : ((2U 
                                                  & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__90__cc))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__90__cc))
                                                   ? (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__90__FF)
                                                   : 
                                                  (~ (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__90__FF)))
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__90__cc))
                                                   ? 
                                                  ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__90__FF) 
                                                   >> 6U)
                                                   : 
                                                  (~ 
                                                   ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__90__FF) 
                                                    >> 6U))))));
                                if (vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__90__Vfuncout) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                } else {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 1U;
                                }
                            } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                            } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                            }
                        }
                    } else {
                        if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__92__cc 
                                                = (7U 
                                                   & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                      >> 3U));
                                            vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__92__FF 
                                                = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F;
                                            vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__92__Vfuncout 
                                                = (1U 
                                                   & ((4U 
                                                       & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__92__cc))
                                                       ? 
                                                      ((2U 
                                                        & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__92__cc))
                                                        ? 
                                                       ((1U 
                                                         & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__92__cc))
                                                         ? 
                                                        ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__92__FF) 
                                                         >> 7U)
                                                         : 
                                                        (~ 
                                                         ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__92__FF) 
                                                          >> 7U)))
                                                        : 
                                                       ((1U 
                                                         & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__92__cc))
                                                         ? 
                                                        ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__92__FF) 
                                                         >> 2U)
                                                         : 
                                                        (~ 
                                                         ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__92__FF) 
                                                          >> 2U))))
                                                       : 
                                                      ((2U 
                                                        & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__92__cc))
                                                        ? 
                                                       ((1U 
                                                         & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__92__cc))
                                                         ? (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__92__FF)
                                                         : 
                                                        (~ (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__92__FF)))
                                                        : 
                                                       ((1U 
                                                         & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__92__cc))
                                                         ? 
                                                        ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__92__FF) 
                                                         >> 6U)
                                                         : 
                                                        (~ 
                                                         ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__92__FF) 
                                                          >> 6U))))));
                                            if (vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__92__Vfuncout) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Jump = 1U;
                                            }
                                        }
                                    }
                                }
                            } else if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Jump = 1U;
                                        }
                                    }
                                }
                            }
                        }
                        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 5U;
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 0xdU;
                                    } else if ((2U 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 0xcU;
                                    }
                                } else {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                                            = ((8U 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                                               | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__SSS));
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                            = (7U | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To));
                                    }
                                }
                            } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 5U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                                        = ((3U == (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR))
                                            ? 7U : 
                                           ((IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR) 
                                            << 1U));
                                } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                                        = ((3U == (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR))
                                            ? 0xbU : 
                                           (1U | ((IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR) 
                                                  << 1U)));
                                }
                            } else {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 5U;
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__91__cc 
                                            = (7U & 
                                               ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                >> 3U));
                                        vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__91__FF 
                                            = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F;
                                        vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__91__Vfuncout 
                                            = (1U & 
                                               ((4U 
                                                 & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__91__cc))
                                                 ? 
                                                ((2U 
                                                  & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__91__cc))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__91__cc))
                                                   ? 
                                                  ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__91__FF) 
                                                   >> 7U)
                                                   : 
                                                  (~ 
                                                   ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__91__FF) 
                                                    >> 7U)))
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__91__cc))
                                                   ? 
                                                  ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__91__FF) 
                                                   >> 2U)
                                                   : 
                                                  (~ 
                                                   ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__91__FF) 
                                                    >> 2U))))
                                                 : 
                                                ((2U 
                                                  & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__91__cc))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__91__cc))
                                                   ? (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__91__FF)
                                                   : 
                                                  (~ (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__91__FF)))
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__91__cc))
                                                   ? 
                                                  ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__91__FF) 
                                                   >> 6U)
                                                   : 
                                                  (~ 
                                                   ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__91__FF) 
                                                    >> 6U))))));
                                        if (vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__91__Vfuncout) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 4U;
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 0xdU;
                                        } else {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                                        }
                                    } else if ((8U 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 0xcU;
                                    }
                                }
                            }
                        } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 4U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 7U;
                                }
                            } else {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                            }
                        } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                            } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                    = ((3U == (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR))
                                        ? 0xbU : ((8U 
                                                   & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                                  | (1U 
                                                     | ((IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR) 
                                                        << 1U))));
                            } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                    = ((3U == (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR))
                                        ? 7U : ((8U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                                | ((IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR) 
                                                   << 1U)));
                            }
                        } else {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__93__cc 
                                    = (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                             >> 3U));
                                vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__93__FF 
                                    = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 5U;
                                vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__93__Vfuncout 
                                    = (1U & ((4U & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__93__cc))
                                              ? ((2U 
                                                  & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__93__cc))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__93__cc))
                                                   ? 
                                                  ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__93__FF) 
                                                   >> 7U)
                                                   : 
                                                  (~ 
                                                   ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__93__FF) 
                                                    >> 7U)))
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__93__cc))
                                                   ? 
                                                  ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__93__FF) 
                                                   >> 2U)
                                                   : 
                                                  (~ 
                                                   ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__93__FF) 
                                                    >> 2U))))
                                              : ((2U 
                                                  & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__93__cc))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__93__cc))
                                                   ? (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__93__FF)
                                                   : 
                                                  (~ (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__93__FF)))
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__93__cc))
                                                   ? 
                                                  ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__93__FF) 
                                                   >> 6U)
                                                   : 
                                                  (~ 
                                                   ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__93__FF) 
                                                    >> 6U))))));
                                if (vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__93__Vfuncout) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                } else {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 1U;
                                }
                            } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                            } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                            }
                        }
                    }
                } else if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__95__cc 
                                            = (7U & 
                                               ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                >> 3U));
                                        vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__95__FF 
                                            = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F;
                                        vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__95__Vfuncout 
                                            = (1U & 
                                               ((4U 
                                                 & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__95__cc))
                                                 ? 
                                                ((2U 
                                                  & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__95__cc))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__95__cc))
                                                   ? 
                                                  ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__95__FF) 
                                                   >> 7U)
                                                   : 
                                                  (~ 
                                                   ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__95__FF) 
                                                    >> 7U)))
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__95__cc))
                                                   ? 
                                                  ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__95__FF) 
                                                   >> 2U)
                                                   : 
                                                  (~ 
                                                   ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__95__FF) 
                                                    >> 2U))))
                                                 : 
                                                ((2U 
                                                  & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__95__cc))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__95__cc))
                                                   ? (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__95__FF)
                                                   : 
                                                  (~ (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__95__FF)))
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__95__cc))
                                                   ? 
                                                  ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__95__FF) 
                                                   >> 6U)
                                                   : 
                                                  (~ 
                                                   ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__95__FF) 
                                                    >> 6U))))));
                                        if (vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__95__Vfuncout) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Jump = 1U;
                                        }
                                    }
                                }
                            }
                        } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Jump = 1U;
                                    }
                                }
                            }
                        } else if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Jump = 1U;
                                }
                            }
                        }
                    }
                    if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 5U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 0xdU;
                                } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 0xcU;
                                }
                            } else {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                                        = ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                                           | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__SSS));
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                        = (7U | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To));
                                }
                            }
                        } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 5U;
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 4U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 0xdU;
                                } else if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 0xcU;
                                }
                            }
                        } else {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 5U;
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__94__cc 
                                        = (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                 >> 3U));
                                    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__94__FF 
                                        = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F;
                                    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__94__Vfuncout 
                                        = (1U & ((4U 
                                                  & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__94__cc))
                                                  ? 
                                                 ((2U 
                                                   & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__94__cc))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__94__cc))
                                                    ? 
                                                   ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__94__FF) 
                                                    >> 7U)
                                                    : 
                                                   (~ 
                                                    ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__94__FF) 
                                                     >> 7U)))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__94__cc))
                                                    ? 
                                                   ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__94__FF) 
                                                    >> 2U)
                                                    : 
                                                   (~ 
                                                    ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__94__FF) 
                                                     >> 2U))))
                                                  : 
                                                 ((2U 
                                                   & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__94__cc))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__94__cc))
                                                    ? (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__94__FF)
                                                    : 
                                                   (~ (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__94__FF)))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__94__cc))
                                                    ? 
                                                   ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__94__FF) 
                                                    >> 6U)
                                                    : 
                                                   (~ 
                                                    ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__94__FF) 
                                                     >> 6U))))));
                                    if (vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__94__Vfuncout) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 4U;
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 0xdU;
                                    } else {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                                    }
                                } else if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 0xcU;
                                }
                            }
                        }
                    } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                        }
                    } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                        } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                        } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                        }
                    } else {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__96__cc 
                                = (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                         >> 3U));
                            vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__96__FF 
                                = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F;
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 5U;
                            vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__96__Vfuncout 
                                = (1U & ((4U & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__96__cc))
                                          ? ((2U & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__96__cc))
                                              ? ((1U 
                                                  & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__96__cc))
                                                  ? 
                                                 ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__96__FF) 
                                                  >> 7U)
                                                  : 
                                                 (~ 
                                                  ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__96__FF) 
                                                   >> 7U)))
                                              : ((1U 
                                                  & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__96__cc))
                                                  ? 
                                                 ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__96__FF) 
                                                  >> 2U)
                                                  : 
                                                 (~ 
                                                  ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__96__FF) 
                                                   >> 2U))))
                                          : ((2U & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__96__cc))
                                              ? ((1U 
                                                  & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__96__cc))
                                                  ? (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__96__FF)
                                                  : 
                                                 (~ (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__96__FF)))
                                              : ((1U 
                                                  & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__96__cc))
                                                  ? 
                                                 ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__96__FF) 
                                                  >> 6U)
                                                  : 
                                                 (~ 
                                                  ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__96__FF) 
                                                   >> 6U))))));
                            if (vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__96__Vfuncout) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                            } else {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 1U;
                            }
                        } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                        } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                        }
                    }
                } else {
                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Jump = 1U;
                                }
                            } else if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                 >> 1U)))) {
                                if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__98__cc 
                                        = (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                 >> 3U));
                                    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__98__FF 
                                        = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F;
                                    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__98__Vfuncout 
                                        = (1U & ((4U 
                                                  & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__98__cc))
                                                  ? 
                                                 ((2U 
                                                   & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__98__cc))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__98__cc))
                                                    ? 
                                                   ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__98__FF) 
                                                    >> 7U)
                                                    : 
                                                   (~ 
                                                    ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__98__FF) 
                                                     >> 7U)))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__98__cc))
                                                    ? 
                                                   ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__98__FF) 
                                                    >> 2U)
                                                    : 
                                                   (~ 
                                                    ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__98__FF) 
                                                     >> 2U))))
                                                  : 
                                                 ((2U 
                                                   & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__98__cc))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__98__cc))
                                                    ? (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__98__FF)
                                                    : 
                                                   (~ (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__98__FF)))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__98__cc))
                                                    ? 
                                                   ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__98__FF) 
                                                    >> 6U)
                                                    : 
                                                   (~ 
                                                    ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__98__FF) 
                                                     >> 6U))))));
                                    if (vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__98__Vfuncout) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Jump = 1U;
                                    }
                                }
                            }
                        } else if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Jump = 1U;
                                    }
                                }
                            }
                        }
                    }
                    if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 5U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 0xdU;
                                } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 0xcU;
                                }
                            } else {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                                        = ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                                           | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__SSS));
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                        = (7U | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To));
                                }
                            }
                        } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 5U;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                                    = ((3U == (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR))
                                        ? 7U : ((IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR) 
                                                << 1U));
                            } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                                    = ((3U == (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR))
                                        ? 0xbU : (1U 
                                                  | ((IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR) 
                                                     << 1U)));
                            }
                        } else {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 5U;
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__97__cc 
                                        = (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                 >> 3U));
                                    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__97__FF 
                                        = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F;
                                    vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__97__Vfuncout 
                                        = (1U & ((4U 
                                                  & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__97__cc))
                                                  ? 
                                                 ((2U 
                                                   & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__97__cc))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__97__cc))
                                                    ? 
                                                   ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__97__FF) 
                                                    >> 7U)
                                                    : 
                                                   (~ 
                                                    ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__97__FF) 
                                                     >> 7U)))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__97__cc))
                                                    ? 
                                                   ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__97__FF) 
                                                    >> 2U)
                                                    : 
                                                   (~ 
                                                    ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__97__FF) 
                                                     >> 2U))))
                                                  : 
                                                 ((2U 
                                                   & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__97__cc))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__97__cc))
                                                    ? (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__97__FF)
                                                    : 
                                                   (~ (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__97__FF)))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__97__cc))
                                                    ? 
                                                   ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__97__FF) 
                                                    >> 6U)
                                                    : 
                                                   (~ 
                                                    ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__97__FF) 
                                                     >> 6U))))));
                                    if (vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__97__Vfuncout) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 4U;
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 0xdU;
                                    } else {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                                    }
                                } else if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 0xcU;
                                }
                            }
                        }
                    } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                    } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                        } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                = ((3U == (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR))
                                    ? 0xbU : ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                              | (1U 
                                                 | ((IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR) 
                                                    << 1U))));
                        } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                = ((3U == (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR))
                                    ? 7U : ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                            | ((IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR) 
                                               << 1U)));
                        }
                    } else {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__99__cc 
                                = (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                         >> 3U));
                            vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__99__FF 
                                = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F;
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 5U;
                            vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__99__Vfuncout 
                                = (1U & ((4U & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__99__cc))
                                          ? ((2U & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__99__cc))
                                              ? ((1U 
                                                  & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__99__cc))
                                                  ? 
                                                 ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__99__FF) 
                                                  >> 7U)
                                                  : 
                                                 (~ 
                                                  ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__99__FF) 
                                                   >> 7U)))
                                              : ((1U 
                                                  & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__99__cc))
                                                  ? 
                                                 ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__99__FF) 
                                                  >> 2U)
                                                  : 
                                                 (~ 
                                                  ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__99__FF) 
                                                   >> 2U))))
                                          : ((2U & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__99__cc))
                                              ? ((1U 
                                                  & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__99__cc))
                                                  ? (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__99__FF)
                                                  : 
                                                 (~ (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__99__FF)))
                                              : ((1U 
                                                  & (IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__99__cc))
                                                  ? 
                                                 ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__99__FF) 
                                                  >> 6U)
                                                  : 
                                                 (~ 
                                                  ((IData)(vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__99__FF) 
                                                   >> 6U))))));
                            if (vlSelf->__Vfunc_sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__99__Vfuncout) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                            } else {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 1U;
                            }
                        } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                        } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                        }
                    }
                }
            } else if ((6U == (7U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                        = ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                           | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__SSS));
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                        = (7U | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To));
                }
            } else {
                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                    = ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                       | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__SSS));
                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                    = (7U | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To));
            }
        } else {
            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                          >> 6U)))) {
                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                              >> 5U)))) {
                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                  >> 4U)))) {
                        if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                      >> 3U)))) {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 2U)))) {
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                        if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__NMICycle)))) {
                                            if (vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IntCycle) {
                                                if (
                                                    (1U 
                                                     & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                             >> 1U)))) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                                 >> 2U)))) {
                                                            if (
                                                                (1U 
                                                                 & (~ 
                                                                    ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                                     >> 3U)))) {
                                                                if (
                                                                    (0x10U 
                                                                     & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Jump = 1U;
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
            if ((0x40U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                if ((0x36U != (0x3fU & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                    if ((6U == (7U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                        }
                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                = ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                   | (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                        }
                    } else if ((6U == (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                             >> 3U)))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                                = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__SSS;
                        }
                    } else {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                            = ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                               | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__SSS));
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                            = ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                               | (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                    }
                }
            } else if ((0x20U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                if ((0x10U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((6U == (7U 
                                                & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                   >> 3U)))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                                                = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__SSS;
                                        }
                                    } else {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                                = (
                                                   (8U 
                                                    & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                                   | (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                                        }
                                    }
                                }
                            } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((6U == (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                  >> 3U)))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                                    } else if ((2U 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 4U;
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 0xaU;
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                            = ((8U 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                               | (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                                    }
                                } else {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 0xaU;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                        = ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                           | (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                                }
                            } else if ((6U == (7U & 
                                               ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                >> 3U)))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                                } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 4U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 0xaU;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                        = ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                           | (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                                }
                            } else {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 0xaU;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                    = ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                       | (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                            }
                        } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 6U;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 
                                    = (0xcU | (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR));
                            } else {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 4U;
                                if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 6U;
                                }
                            }
                        } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                    = (5U | (8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)));
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                                    = ((((0U == (3U 
                                                 & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                    >> 4U))) 
                                         | (1U == (3U 
                                                   & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                      >> 4U)))) 
                                        | (2U == (3U 
                                                  & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                     >> 4U))))
                                        ? ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                                           | (1U | 
                                              (6U & 
                                               ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                >> 3U))))
                                        : 8U);
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 4U;
                            } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                    = (4U | (8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)));
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                                    = ((((0U == (3U 
                                                 & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                    >> 4U))) 
                                         | (1U == (3U 
                                                   & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                      >> 4U)))) 
                                        | (2U == (3U 
                                                  & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                     >> 4U))))
                                        ? ((9U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                                           | (6U & 
                                              ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                               >> 3U)))
                                        : 9U);
                            }
                        } else {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                if ((0U == (3U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                  >> 3U)))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d 
                                        = ((0x40U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F))
                                            ? 2U : 3U);
                                } else if ((1U == (3U 
                                                   & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                      >> 3U)))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d 
                                        = ((0x40U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F))
                                            ? 3U : 2U);
                                } else if ((2U == (3U 
                                                   & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                      >> 3U)))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d 
                                        = ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F))
                                            ? 2U : 3U);
                                } else if ((3U == (3U 
                                                   & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                      >> 3U)))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d 
                                        = ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F))
                                            ? 3U : 2U);
                                }
                            } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 5U;
                            }
                        }
                    } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                if ((6U == (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                  >> 3U)))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                                            = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__SSS;
                                    }
                                } else {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                            = ((8U 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                               | (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                                    }
                                }
                            }
                        } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((6U == (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                              >> 3U)))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                                } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 4U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 0xaU;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                        = ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                           | (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                                }
                            } else {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 0xaU;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                    = ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                       | (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                            }
                        } else if ((6U == (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                 >> 3U)))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                            } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 4U;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 0xaU;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                    = ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                       | (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                            }
                        } else {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 0xaU;
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                = ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                   | (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                        }
                    } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 6U;
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 
                                = (4U | (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR));
                        } else {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 4U;
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 6U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 7U;
                                }
                            }
                        }
                    } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                = ((3U == (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR))
                                    ? 8U : ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                            | (1U | 
                                               ((IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR) 
                                                << 1U))));
                        } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                = ((3U == (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR))
                                    ? 9U : ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                            | ((IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR) 
                                               << 1U)));
                        }
                    } else {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            if ((0U == (3U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                              >> 3U)))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d 
                                    = ((0x40U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F))
                                        ? 2U : 3U);
                            } else if ((1U == (3U & 
                                               ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                >> 3U)))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d 
                                    = ((0x40U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F))
                                        ? 3U : 2U);
                            } else if ((2U == (3U & 
                                               ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                >> 3U)))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d 
                                    = ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F))
                                        ? 2U : 3U);
                            } else if ((3U == (3U & 
                                               ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                >> 3U)))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d 
                                    = ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F))
                                        ? 3U : 2U);
                            }
                        } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 5U;
                        }
                    }
                } else if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                if ((6U == (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                  >> 3U)))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                                            = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__SSS;
                                    }
                                } else {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                            = ((8U 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                               | (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                                    }
                                }
                            }
                        } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((6U == (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                              >> 3U)))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                                } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 4U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 0xaU;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                        = ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                           | (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                                }
                            } else {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 0xaU;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                    = ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                       | (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                            }
                        } else if ((6U == (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                 >> 3U)))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                            } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 4U;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 0xaU;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                    = ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                       | (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                            }
                        } else {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 0xaU;
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                = ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                   | (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                        }
                    } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 6U;
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 
                                = (0xcU | (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR));
                        } else {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 5U;
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 6U;
                                } else if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                        = (5U | (8U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)));
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 6U;
                                } else if ((0x10U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                        = (4U | (8U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)));
                                }
                            }
                        }
                    } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                = (5U | (8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)));
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                                = ((((0U == (3U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                   >> 4U))) 
                                     | (1U == (3U & 
                                               ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                >> 4U)))) 
                                    | (2U == (3U & 
                                              ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                               >> 4U))))
                                    ? ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                                       | (1U | (6U 
                                                & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                   >> 3U))))
                                    : 8U);
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 4U;
                        } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                = (4U | (8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)));
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                                = ((((0U == (3U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                   >> 4U))) 
                                     | (1U == (3U & 
                                               ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                >> 4U)))) 
                                    | (2U == (3U & 
                                              ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                               >> 4U))))
                                    ? ((9U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                                       | (6U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                >> 3U)))
                                    : 9U);
                        }
                    } else {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            if ((0U == (3U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                              >> 3U)))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d 
                                    = ((0x40U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F))
                                        ? 2U : 3U);
                            } else if ((1U == (3U & 
                                               ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                >> 3U)))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d 
                                    = ((0x40U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F))
                                        ? 3U : 2U);
                            } else if ((2U == (3U & 
                                               ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                >> 3U)))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d 
                                    = ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F))
                                        ? 2U : 3U);
                            } else if ((3U == (3U & 
                                               ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                >> 3U)))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d 
                                    = ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F))
                                        ? 3U : 2U);
                            }
                        } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 5U;
                        }
                    }
                } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                = (7U | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To));
                        } else if ((6U == (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                 >> 3U)))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                                    = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__SSS;
                            }
                        } else {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                    = ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                       | (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                            }
                        }
                    } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((6U == (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 3U)))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                            } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 4U;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 0xaU;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                    = ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                       | (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                            }
                        } else {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 0xaU;
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                = ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                   | (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                        }
                    } else if ((6U == (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                             >> 3U)))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                        } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 4U;
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 0xaU;
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                = ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                   | (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                        }
                    } else {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 0xaU;
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                            = ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                               | (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                    }
                } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 6U;
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 
                            = (4U | (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR));
                    } else {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 5U;
                        if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                      >> 1U)))) {
                            if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 6U;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 5U;
                            } else if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 6U;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 4U;
                            }
                        }
                    }
                } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                            = ((3U == (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR))
                                ? 8U : ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                        | (1U | ((IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR) 
                                                 << 1U))));
                    } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                            = ((3U == (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR))
                                ? 9U : ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                        | ((IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR) 
                                           << 1U)));
                    }
                } else {
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                        if ((0U == (3U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 3U)))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d 
                                = ((0x40U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F))
                                    ? 2U : 3U);
                        } else if ((1U == (3U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                 >> 3U)))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d 
                                = ((0x40U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F))
                                    ? 3U : 2U);
                        } else if ((2U == (3U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                 >> 3U)))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d 
                                = ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F))
                                    ? 2U : 3U);
                        } else if ((3U == (3U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                 >> 3U)))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d 
                                = ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__F))
                                    ? 3U : 2U);
                        }
                    } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 5U;
                    }
                }
            } else if ((0x10U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                    = (7U | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To));
                            } else if ((6U == (7U & 
                                               ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                >> 3U)))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                                        = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__SSS;
                                }
                            } else {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                        = ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                           | (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                                }
                            }
                        } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((6U == (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                              >> 3U)))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                                } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 4U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 0xaU;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                        = ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                           | (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                                }
                            } else {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 0xaU;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                    = ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                       | (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                            }
                        } else if ((6U == (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                 >> 3U)))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                            } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 4U;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 0xaU;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                    = ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                       | (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                            }
                        } else {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 0xaU;
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                = ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                   | (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                        }
                    } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 6U;
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 
                                = (0xcU | (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR));
                        } else {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 1U;
                            }
                        }
                    } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                = (5U | (8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)));
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                                = ((((0U == (3U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                   >> 4U))) 
                                     | (1U == (3U & 
                                               ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                >> 4U)))) 
                                    | (2U == (3U & 
                                              ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                               >> 4U))))
                                    ? ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                                       | (1U | (6U 
                                                & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                   >> 3U))))
                                    : 8U);
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 4U;
                        } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                = (4U | (8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)));
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                                = ((((0U == (3U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                   >> 4U))) 
                                     | (1U == (3U & 
                                               ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                >> 4U)))) 
                                    | (2U == (3U & 
                                              ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                               >> 4U))))
                                    ? ((9U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                                       | (6U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                >> 3U)))
                                    : 9U);
                        }
                    } else {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                        if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                      >> 1U)))) {
                            if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 5U;
                            }
                        }
                    }
                } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                = (7U | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To));
                        } else if ((6U == (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                 >> 3U)))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                                    = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__SSS;
                            }
                        } else {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                    = ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                       | (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                            }
                        }
                    } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((6U == (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 3U)))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                            } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 4U;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 0xaU;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                    = ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                       | (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                            }
                        } else {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 0xaU;
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                = ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                   | (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                        }
                    } else if ((6U == (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                             >> 3U)))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                        } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 4U;
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 0xaU;
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                = ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                   | (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                        }
                    } else {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 0xaU;
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                            = ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                               | (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                    }
                } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 6U;
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 
                            = (4U | (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR));
                    } else {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 1U;
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 7U;
                        }
                    }
                } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                            = ((3U == (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR))
                                ? 8U : ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                        | (1U | ((IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR) 
                                                 << 1U))));
                    } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                            = ((3U == (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR))
                                ? 9U : ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                        | ((IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR) 
                                           << 1U)));
                    }
                } else {
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 5U;
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 0xaU;
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                            = (8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To));
                    } else if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                         >> 1U)))) {
                        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 5U;
                        }
                    }
                }
            } else if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                = (7U | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To));
                        } else if ((6U == (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                 >> 3U)))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                                    = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__SSS;
                            }
                        } else {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                    = ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                       | (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                            }
                        }
                    } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((6U == (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 3U)))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                            } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 4U;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 0xaU;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                    = ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                       | (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                            }
                        } else {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 0xaU;
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                = ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                   | (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                        }
                    } else if ((6U == (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                             >> 3U)))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                        } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 4U;
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 0xaU;
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                = ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                   | (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                        }
                    } else {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 0xaU;
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                            = ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                               | (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                    }
                } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 6U;
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 
                            = (0xcU | (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR));
                    } else {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 0U;
                        }
                    }
                } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                            = (5U | (8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)));
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                            = ((((0U == (3U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                               >> 4U))) 
                                 | (1U == (3U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                 >> 4U)))) 
                                | (2U == (3U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                >> 4U))))
                                ? ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                                   | (1U | (6U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                  >> 3U))))
                                : 8U);
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 4U;
                    } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                            = (4U | (8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)));
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                            = ((((0U == (3U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                               >> 4U))) 
                                 | (1U == (3U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                 >> 4U)))) 
                                | (2U == (3U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                >> 4U))))
                                ? ((9U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                                   | (6U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                            >> 3U)))
                                : 9U);
                    }
                }
            } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                            = (7U | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To));
                    } else if ((6U == (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                             >> 3U)))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                                = vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__SSS;
                        }
                    } else {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                = ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                   | (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                        }
                    }
                } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((6U == (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                      >> 3U)))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                        } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 4U;
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 0xaU;
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                = ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                   | (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                        }
                    } else {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 0xaU;
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                            = ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                               | (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                    }
                } else if ((6U == (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                         >> 3U)))) {
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                    } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 4U;
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 0xaU;
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                            = ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                               | (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                    }
                } else {
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 0xaU;
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                        = ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                           | (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                }
            } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 6U;
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 
                        = (4U | (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR));
                } else {
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 0U;
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 7U;
                    }
                }
            } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                        = ((3U == (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR))
                            ? 8U : ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                    | (1U | ((IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR) 
                                             << 1U))));
                } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                        = ((3U == (IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR))
                            ? 9U : ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                    | ((IData)(sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR) 
                                       << 1U)));
                }
            } else if (vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__NMICycle) {
                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 5U;
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 0xdU;
                } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 4U;
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 0xcU;
                } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 4U;
                }
            } else if (vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IntCycle) {
                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 5U;
                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 5U;
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 0xdU;
                } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 4U;
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 0xcU;
                } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 4U;
                }
            }
        }
    } else {
        if ((1U != (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ISet))) {
            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                          >> 7U)))) {
                if ((0x40U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((0x20U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((0x10U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                  >> 1U)))) {
                                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                            if ((1U 
                                                 & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                         >> 1U)))) {
                                                    if (
                                                        (4U 
                                                         & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Jump = 1U;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                        if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                            if ((1U 
                                                 & (~ 
                                                    ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                     >> 1U)))) {
                                                if (
                                                    (4U 
                                                     & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Jump = 1U;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        } else if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                        if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                            if ((1U 
                                                 & (~ 
                                                    ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                     >> 1U)))) {
                                                if (
                                                    (4U 
                                                     & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Jump = 1U;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 1U)))) {
                                            if ((4U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Jump = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((0x10U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                        if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                            if ((1U 
                                                 & (~ 
                                                    ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                     >> 1U)))) {
                                                if (
                                                    (4U 
                                                     & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Jump = 1U;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 1U)))) {
                                            if ((4U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Jump = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 1U)))) {
                                            if ((4U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Jump = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Jump = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if ((1U == (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__ISet))) {
            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                = ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                   | (7U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)));
            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                = ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                   | (7U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)));
            if ((0x80U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                if ((0x40U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                                if ((IData)((0U != 
                                             (0x41U 
                                              & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                                } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 4U;
                                }
                            }
                        }
                    }
                } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                            if ((IData)((0U != (0x41U 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                            } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 4U;
                            }
                        }
                    }
                }
            } else if ((0x40U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                                    = ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                                       | (7U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)));
                            }
                        } else {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                            if ((IData)((0U != (0x41U 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                            } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 4U;
                            }
                        }
                    } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                            = ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                               | (7U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)));
                    }
                } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                        = ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                           | (7U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)));
                }
            } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR)))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                        if ((IData)((0U != (0x41U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                        } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 4U;
                        }
                    }
                }
            }
        } else if ((0x80U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                          >> 6U)))) {
                if ((0x20U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 4U;
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 5U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 0xaU;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To = 0U;
                                } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 6U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 0U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 
                                        = ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))
                                            ? 0xeU : 6U);
                                } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 
                                        = ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))
                                            ? 0xaU : 2U);
                                } else if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 5U;
                                }
                            } else {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 4U;
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 0U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 0xaU;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To = 0U;
                                } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 6U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                                } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 
                                        = ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))
                                            ? 0xeU : 6U);
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 4U;
                                } else if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 5U;
                                }
                            }
                        } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 4U;
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 0xcU;
                            } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 6U;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                    = (7U | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To));
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 
                                    = ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))
                                        ? 0xeU : 6U);
                            } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 5U;
                            } else if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 5U;
                            }
                        } else {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 4U;
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 0xcU;
                            } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 6U;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                    = (7U | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To));
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 1U;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 
                                    = ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))
                                        ? 0xeU : 6U);
                            } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 5U;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 
                                    = ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))
                                        ? 0xdU : 5U);
                            } else if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 5U;
                            }
                        }
                    }
                }
            }
        } else if ((0x40U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
            if ((0x20U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                if ((0x10U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                    } else if ((2U 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                    } else if ((4U 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                                    }
                                } else {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 7U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To = 0xaU;
                                }
                            }
                        } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 5U;
                                if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 6U;
                                    } else if ((8U 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                            = ((3U 
                                                == 
                                                (3U 
                                                 & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                    >> 4U)))
                                                ? 8U
                                                : (
                                                   (8U 
                                                    & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                                   | (1U 
                                                      | (6U 
                                                         & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                            >> 3U)))));
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 6U;
                                    } else if ((0x10U 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                            = ((3U 
                                                == 
                                                (3U 
                                                 & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                    >> 4U)))
                                                ? 9U
                                                : (
                                                   (8U 
                                                    & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                                   | (6U 
                                                      & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                         >> 3U))));
                                    }
                                }
                            } else {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                        = (5U | (8U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)));
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                                        = ((((0U == 
                                              (3U & 
                                               ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                >> 4U))) 
                                             | (1U 
                                                == 
                                                (3U 
                                                 & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                    >> 4U)))) 
                                            | (2U == 
                                               (3U 
                                                & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                   >> 4U))))
                                            ? ((8U 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                                               | (1U 
                                                  | (6U 
                                                     & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                        >> 3U))))
                                            : 8U);
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 4U;
                                } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                        = (4U | (8U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)));
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                                        = ((((0U == 
                                              (3U & 
                                               ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                >> 4U))) 
                                             | (1U 
                                                == 
                                                (3U 
                                                 & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                    >> 4U)))) 
                                            | (2U == 
                                               (3U 
                                                & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                   >> 4U))))
                                            ? ((8U 
                                                & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                                               | (6U 
                                                  & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                     >> 3U)))
                                            : 9U);
                                }
                            }
                        } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 0U;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                                    = ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                                       | (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                >> 3U)));
                                if ((6U == (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                  >> 3U)))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                                        = (8U | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To));
                                }
                            }
                        } else {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 0U;
                            } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                if ((6U != (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                  >> 3U)))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                        = ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                           | (7U & 
                                              ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                               >> 3U)));
                                }
                            }
                        }
                    } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                                }
                            } else {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 7U;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To = 0xaU;
                            }
                        }
                    } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 5U;
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 6U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                                        = ((3U == (3U 
                                                   & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                      >> 4U)))
                                            ? 8U : 
                                           (1U | (6U 
                                                  & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                     >> 3U))));
                                } else if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 6U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                                        = ((3U == (3U 
                                                   & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                      >> 4U)))
                                            ? 9U : 
                                           (6U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                  >> 3U)));
                                }
                            }
                        } else {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                    = (5U | (8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)));
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                                    = ((((0U == (3U 
                                                 & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                    >> 4U))) 
                                         | (1U == (3U 
                                                   & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                      >> 4U)))) 
                                        | (2U == (3U 
                                                  & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                     >> 4U))))
                                        ? ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                                           | (1U | 
                                              (6U & 
                                               ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                >> 3U))))
                                        : 8U);
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 4U;
                            } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                    = (4U | (8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)));
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                                    = ((((0U == (3U 
                                                 & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                    >> 4U))) 
                                         | (1U == (3U 
                                                   & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                      >> 4U)))) 
                                        | (2U == (3U 
                                                  & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                     >> 4U))))
                                        ? ((9U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                                           | (6U & 
                                              ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                               >> 3U)))
                                        : 9U);
                            }
                        }
                    } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 0U;
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                                = ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                                   | (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                            >> 3U)));
                            if ((6U == (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                              >> 3U)))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                                    = (8U | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To));
                            }
                        }
                    } else {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 0U;
                        } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            if ((6U != (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                              >> 3U)))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                    = ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                       | (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                >> 3U)));
                            }
                        }
                    }
                } else if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 4U;
                                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                                } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                                        = (6U | (8U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To)));
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                        = (7U | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To));
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 4U;
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                                }
                            }
                        } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                            } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                            } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                            }
                        } else {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 7U;
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To = 0xaU;
                        }
                    } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 5U;
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 6U;
                                } else if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                        = ((3U == (3U 
                                                   & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                      >> 4U)))
                                            ? 8U : 
                                           ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                            | (1U | 
                                               (6U 
                                                & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                   >> 3U)))));
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 6U;
                                } else if ((0x10U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                        = ((3U == (3U 
                                                   & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                      >> 4U)))
                                            ? 9U : 
                                           ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                            | (6U & 
                                               ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                >> 3U))));
                                }
                            }
                        } else {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                    = (5U | (8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)));
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                                    = ((((0U == (3U 
                                                 & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                    >> 4U))) 
                                         | (1U == (3U 
                                                   & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                      >> 4U)))) 
                                        | (2U == (3U 
                                                  & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                     >> 4U))))
                                        ? ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                                           | (1U | 
                                              (6U & 
                                               ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                >> 3U))))
                                        : 8U);
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 4U;
                            } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                    = (4U | (8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)));
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                                    = ((((0U == (3U 
                                                 & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                    >> 4U))) 
                                         | (1U == (3U 
                                                   & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                      >> 4U)))) 
                                        | (2U == (3U 
                                                  & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                     >> 4U))))
                                        ? ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                                           | (6U & 
                                              ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                               >> 3U)))
                                        : 9U);
                            }
                        }
                    } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 0U;
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                                = ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                                   | (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                            >> 3U)));
                            if ((6U == (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                              >> 3U)))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                                    = (8U | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To));
                            }
                        }
                    } else {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 0U;
                        } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            if ((6U != (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                              >> 3U)))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                    = ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                       | (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                >> 3U)));
                            }
                        }
                    }
                } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 4U;
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                            } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                                    = (6U | (8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To)));
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                    = (7U | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To));
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 4U;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                            }
                        }
                    } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                        } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                        } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                        }
                    } else {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 7U;
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To = 0xaU;
                    }
                } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 5U;
                        if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                      >> 1U)))) {
                            if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 6U;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                                    = ((3U == (3U & 
                                               ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                >> 4U)))
                                        ? 8U : (1U 
                                                | (6U 
                                                   & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                      >> 3U))));
                            } else if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 6U;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                                    = ((3U == (3U & 
                                               ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                >> 4U)))
                                        ? 9U : (6U 
                                                & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                   >> 3U)));
                            }
                        }
                    } else {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                = (5U | (8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)));
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                                = ((((0U == (3U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                   >> 4U))) 
                                     | (1U == (3U & 
                                               ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                >> 4U)))) 
                                    | (2U == (3U & 
                                              ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                               >> 4U))))
                                    ? ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                                       | (1U | (6U 
                                                & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                   >> 3U))))
                                    : 8U);
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 4U;
                        } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                = (4U | (8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)));
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                                = ((((0U == (3U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                   >> 4U))) 
                                     | (1U == (3U & 
                                               ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                >> 4U)))) 
                                    | (2U == (3U & 
                                              ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                               >> 4U))))
                                    ? ((9U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                                       | (6U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                >> 3U)))
                                    : 9U);
                        }
                    }
                } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 0U;
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                            = ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                               | (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                        >> 3U)));
                        if ((6U == (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 3U)))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                                = (8U | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To));
                        }
                    }
                } else {
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 0U;
                    } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                        if ((6U != (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 3U)))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                = ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                   | (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                            >> 3U)));
                        }
                    }
                }
            } else if ((0x10U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 5U;
                            }
                        } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                            if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                            } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                            } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                            }
                        } else {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 7U;
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To = 0xaU;
                        }
                    } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 5U;
                            if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 6U;
                                } else if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                        = ((3U == (3U 
                                                   & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                      >> 4U)))
                                            ? 8U : 
                                           ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                            | (1U | 
                                               (6U 
                                                & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                   >> 3U)))));
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 6U;
                                } else if ((0x10U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                        = ((3U == (3U 
                                                   & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                      >> 4U)))
                                            ? 9U : 
                                           ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                            | (6U & 
                                               ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                >> 3U))));
                                }
                            }
                        } else {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                            if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                    = (5U | (8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)));
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                                    = ((((0U == (3U 
                                                 & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                    >> 4U))) 
                                         | (1U == (3U 
                                                   & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                      >> 4U)))) 
                                        | (2U == (3U 
                                                  & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                     >> 4U))))
                                        ? ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                                           | (1U | 
                                              (6U & 
                                               ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                >> 3U))))
                                        : 8U);
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 4U;
                            } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                    = (4U | (8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)));
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                                    = ((((0U == (3U 
                                                 & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                    >> 4U))) 
                                         | (1U == (3U 
                                                   & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                      >> 4U)))) 
                                        | (2U == (3U 
                                                  & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                     >> 4U))))
                                        ? ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                                           | (6U & 
                                              ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                               >> 3U)))
                                        : 9U);
                            }
                        }
                    } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 0U;
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                                = ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                                   | (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                            >> 3U)));
                            if ((6U == (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                              >> 3U)))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                                    = (8U | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To));
                            }
                        }
                    } else {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 0U;
                        } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            if ((6U != (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                              >> 3U)))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                    = ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                       | (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                >> 3U)));
                            }
                        }
                    }
                } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 5U;
                        }
                    } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                        } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                        } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                        }
                    } else {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 7U;
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To = 0xaU;
                    }
                } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 5U;
                        if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                      >> 1U)))) {
                            if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 6U;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                                    = ((3U == (3U & 
                                               ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                >> 4U)))
                                        ? 8U : (1U 
                                                | (6U 
                                                   & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                      >> 3U))));
                            } else if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 6U;
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                                    = ((3U == (3U & 
                                               ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                >> 4U)))
                                        ? 9U : (6U 
                                                & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                   >> 3U)));
                            }
                        }
                    } else {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                = (5U | (8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)));
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                                = ((((0U == (3U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                   >> 4U))) 
                                     | (1U == (3U & 
                                               ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                >> 4U)))) 
                                    | (2U == (3U & 
                                              ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                               >> 4U))))
                                    ? ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                                       | (1U | (6U 
                                                & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                   >> 3U))))
                                    : 8U);
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 4U;
                        } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                = (4U | (8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)));
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                                = ((((0U == (3U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                   >> 4U))) 
                                     | (1U == (3U & 
                                               ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                >> 4U)))) 
                                    | (2U == (3U & 
                                              ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                               >> 4U))))
                                    ? ((9U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                                       | (6U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                >> 3U)))
                                    : 9U);
                        }
                    }
                } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 0U;
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                            = ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                               | (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                        >> 3U)));
                        if ((6U == (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 3U)))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                                = (8U | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To));
                        }
                    }
                } else {
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 0U;
                    } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                        if ((6U != (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 3U)))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                = ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                   | (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                            >> 3U)));
                        }
                    }
                }
            } else if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 5U;
                        }
                    } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                        if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                        } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                        } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                        }
                    } else {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 7U;
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To = 0xaU;
                    }
                } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 5U;
                        if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                      >> 1U)))) {
                            if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 6U;
                            } else if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                    = ((3U == (3U & 
                                               ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                >> 4U)))
                                        ? 8U : ((8U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                                | (1U 
                                                   | (6U 
                                                      & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                         >> 3U)))));
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 6U;
                            } else if ((0x10U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                    = ((3U == (3U & 
                                               ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                >> 4U)))
                                        ? 9U : ((8U 
                                                 & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                                | (6U 
                                                   & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                      >> 3U))));
                            }
                        }
                    } else {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                        if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                = (5U | (8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)));
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                                = ((((0U == (3U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                   >> 4U))) 
                                     | (1U == (3U & 
                                               ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                >> 4U)))) 
                                    | (2U == (3U & 
                                              ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                               >> 4U))))
                                    ? ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                                       | (1U | (6U 
                                                & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                   >> 3U))))
                                    : 8U);
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 4U;
                        } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                = (4U | (8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)));
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                                = ((((0U == (3U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                   >> 4U))) 
                                     | (1U == (3U & 
                                               ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                >> 4U)))) 
                                    | (2U == (3U & 
                                              ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                               >> 4U))))
                                    ? ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                                       | (6U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                >> 3U)))
                                    : 9U);
                        }
                    }
                } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 0U;
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                            = ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                               | (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                        >> 3U)));
                        if ((6U == (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 3U)))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                                = (8U | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To));
                        }
                    }
                } else {
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 0U;
                    } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                        if ((6U != (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                          >> 3U)))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                                = ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                   | (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                            >> 3U)));
                        }
                    }
                }
            } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 5U;
                    }
                } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                    if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                    } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                    } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                    }
                } else {
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To = 7U;
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To = 0xaU;
                }
            } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 5U;
                    if ((1U & (~ ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle) 
                                  >> 1U)))) {
                        if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 6U;
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                                = ((3U == (3U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                 >> 4U)))
                                    ? 8U : (1U | (6U 
                                                  & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                     >> 3U))));
                        } else if ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 6U;
                            vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                                = ((3U == (3U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                 >> 4U)))
                                    ? 9U : (6U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                  >> 3U)));
                        }
                    }
                } else {
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                    if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                            = (5U | (8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)));
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                            = ((((0U == (3U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                               >> 4U))) 
                                 | (1U == (3U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                 >> 4U)))) 
                                | (2U == (3U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                >> 4U))))
                                ? ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                                   | (1U | (6U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                  >> 3U))))
                                : 8U);
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__tstates = 4U;
                    } else if ((4U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                            = (4U | (8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)));
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                            = ((((0U == (3U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                               >> 4U))) 
                                 | (1U == (3U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                 >> 4U)))) 
                                | (2U == (3U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                                >> 4U))))
                                ? ((9U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                                   | (6U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                            >> 3U)))
                                : 9U);
                    }
                }
            } else if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR))) {
                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 0U;
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                        = ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                           | (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                    >> 3U)));
                    if ((6U == (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                      >> 3U)))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To 
                            = (8U | (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusB_To));
                    }
                }
            } else {
                vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                if ((1U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                    vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_Addr_To = 0U;
                } else if ((2U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__mcycle))) {
                    if ((6U != (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                      >> 3U)))) {
                        vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To 
                            = ((8U & (IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                               | (7U & ((IData)(vlSelf->sim_top__DOT__soc__DOT__sub__DOT__cpu__DOT__i_tv80_core__DOT__IR) 
                                        >> 3U)));
                    }
                }
            }
        }
    }
}
