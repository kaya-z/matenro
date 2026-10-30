// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vsim_top.h"
#include "Vsim_top__Syms.h"

//============================================================
// Constructors

Vsim_top::Vsim_top(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vsim_top__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , resetn{vlSymsp->TOP.resetn}
    , rxd{vlSymsp->TOP.rxd}
    , txd{vlSymsp->TOP.txd}
    , sd_clk{vlSymsp->TOP.sd_clk}
    , sd_mosi{vlSymsp->TOP.sd_mosi}
    , sd_miso{vlSymsp->TOP.sd_miso}
    , sd_cs{vlSymsp->TOP.sd_cs}
    , led{vlSymsp->TOP.led}
    , fl_cs{vlSymsp->TOP.fl_cs}
    , fl_clk{vlSymsp->TOP.fl_clk}
    , fl_mosi{vlSymsp->TOP.fl_mosi}
    , fl_miso{vlSymsp->TOP.fl_miso}
    , kanji_ok{vlSymsp->TOP.kanji_ok}
    , term_stb{vlSymsp->TOP.term_stb}
    , term_byte{vlSymsp->TOP.term_byte}
    , dbg_lic{vlSymsp->TOP.dbg_lic}
    , dbg_acc{vlSymsp->TOP.dbg_acc}
    , dbg_din{vlSymsp->TOP.dbg_din}
    , dbg_rnw{vlSymsp->TOP.dbg_rnw}
    , dbg_vma{vlSymsp->TOP.dbg_vma}
    , dbg_ps_rd{vlSymsp->TOP.dbg_ps_rd}
    , dbg_ps_wr{vlSymsp->TOP.dbg_ps_wr}
    , dbg_addr{vlSymsp->TOP.dbg_addr}
    , dbg_regs{vlSymsp->TOP.dbg_regs}
    , dbg_ps_addr{vlSymsp->TOP.dbg_ps_addr}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vsim_top::Vsim_top(const char* _vcname__)
    : Vsim_top(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vsim_top::~Vsim_top() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vsim_top___024root___eval_debug_assertions(Vsim_top___024root* vlSelf);
#endif  // VL_DEBUG
void Vsim_top___024root___eval_static(Vsim_top___024root* vlSelf);
void Vsim_top___024root___eval_initial(Vsim_top___024root* vlSelf);
void Vsim_top___024root___eval_settle(Vsim_top___024root* vlSelf);
void Vsim_top___024root___eval(Vsim_top___024root* vlSelf);

void Vsim_top::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vsim_top::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vsim_top___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vsim_top___024root___eval_static(&(vlSymsp->TOP));
        Vsim_top___024root___eval_initial(&(vlSymsp->TOP));
        Vsim_top___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vsim_top___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vsim_top::eventsPending() { return false; }

uint64_t Vsim_top::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vsim_top::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vsim_top___024root___eval_final(Vsim_top___024root* vlSelf);

VL_ATTR_COLD void Vsim_top::final() {
    Vsim_top___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vsim_top::hierName() const { return vlSymsp->name(); }
const char* Vsim_top::modelName() const { return "Vsim_top"; }
unsigned Vsim_top::threads() const { return 1; }
