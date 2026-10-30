// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary model header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef VERILATED_VSIM_TOP_H_
#define VERILATED_VSIM_TOP_H_  // guard

#include "verilated.h"

class Vsim_top__Syms;
class Vsim_top___024root;

// This class is the main interface to the Verilated model
class Vsim_top VL_NOT_FINAL : public VerilatedModel {
  private:
    // Symbol table holding complete model state (owned by this class)
    Vsim_top__Syms* const vlSymsp;

  public:

    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(&clk,0,0);
    VL_IN8(&resetn,0,0);
    VL_IN8(&rxd,0,0);
    VL_OUT8(&txd,0,0);
    VL_OUT8(&sd_clk,0,0);
    VL_OUT8(&sd_mosi,0,0);
    VL_IN8(&sd_miso,0,0);
    VL_OUT8(&sd_cs,0,0);
    VL_OUT8(&led,5,0);
    VL_OUT8(&fl_cs,0,0);
    VL_OUT8(&fl_clk,0,0);
    VL_OUT8(&fl_mosi,0,0);
    VL_IN8(&fl_miso,0,0);
    VL_OUT8(&kanji_ok,0,0);
    VL_OUT8(&term_stb,0,0);
    VL_OUT8(&term_byte,7,0);
    VL_OUT8(&dbg_lic,0,0);
    VL_OUT8(&dbg_acc,0,0);
    VL_OUT8(&dbg_din,7,0);
    VL_OUT8(&dbg_rnw,0,0);
    VL_OUT8(&dbg_vma,0,0);
    VL_OUT8(&dbg_ps_rd,0,0);
    VL_OUT8(&dbg_ps_wr,0,0);
    VL_OUT16(&dbg_addr,15,0);
    VL_OUTW(&dbg_regs,111,0,4);
    VL_OUT(&dbg_ps_addr,21,0);

    // CELLS
    // Public to allow access to /* verilator public */ items.
    // Otherwise the application code can consider these internals.

    // Root instance pointer to allow access to model internals,
    // including inlined /* verilator public_flat_* */ items.
    Vsim_top___024root* const rootp;

    // CONSTRUCTORS
    /// Construct the model; called by application code
    /// If contextp is null, then the model will use the default global context
    /// If name is "", then makes a wrapper with a
    /// single model invisible with respect to DPI scope names.
    explicit Vsim_top(VerilatedContext* contextp, const char* name = "TOP");
    explicit Vsim_top(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    virtual ~Vsim_top();
  private:
    VL_UNCOPYABLE(Vsim_top);  ///< Copying not allowed

  public:
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    /// Are there scheduled events to handle?
    bool eventsPending();
    /// Returns time at next time slot. Aborts if !eventsPending()
    uint64_t nextTimeSlot();
    /// Retrieve name of this model instance (as passed to constructor).
    const char* name() const;

    // Abstract methods from VerilatedModel
    const char* hierName() const override final;
    const char* modelName() const override final;
    unsigned threads() const override final;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
