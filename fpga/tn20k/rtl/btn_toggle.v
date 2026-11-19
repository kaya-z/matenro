// Tang Nano 20K copy: made from fpga/tn9k/rtl/btn_toggle.v (as of commit d56829d, 2026-11-19).  From here on this file belongs to the 20K only; the 9K keeps its own (frozen) one.
// SPDX-License-Identifier: MIT
// btn_toggle.v - a push button (active low) that toggles a state: synchronised, debounced, one toggle per press.
// The state is cleared by the reset.  DEB_BITS: the button must be stable for 2**DEB_BITS clocks
// (20 bits at 67.5 MHz = 15.5 ms; the test bench uses a few bits).
module btn_toggle #(
    parameter DEB_BITS = 20
) (
    input  wire clk,
    input  wire rst_n,                 // low: the state is cleared
    input  wire btn_n,                 // the button, low while it is pressed
    output reg  state
);
    reg [2:0]        sync;
    reg              stable;           // the debounced level of the button (1 = released)
    reg [DEB_BITS-1:0] cnt;

    always @(posedge clk) begin
        sync <= {sync[1:0], btn_n};
        if (!rst_n) begin
            state  <= 1'b0;
            stable <= 1'b1;
            cnt    <= 0;
        end else if (sync[2] == stable) begin
            cnt <= 0;                  // nothing new, or a bounce back to the stable level
        end else begin
            cnt <= cnt + 1'b1;
            if (&cnt) begin            // the new level has been there long enough
                stable <= sync[2];
                if (!sync[2]) state <= ~state;      // a press (not the release) toggles
            end
        end
    end
endmodule
