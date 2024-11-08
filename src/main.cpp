#include <systemc>
#include "top.h"

int sc_main(int argc, char* argv[]) {
    Top top("Top");

    sc_clock clk("clk", 10, SC_NS);
    sc_signal<bool> reset;

    top.clk(clk);
    top.reset(reset);

    sc_signal<sc_uint<32>> data_in;
    top.data_in(data_in);

    // Initializing signals and running simulation
    sc_start(5, SC_NS);
    reset.write(true);  // Reset active
    sc_start(20, SC_NS);
    reset.write(false);  // Release reset

    // Provide input data and run simulation
    data_in.write(42);  // Example input
    sc_start(100, SC_NS);  // Run simulation for 100 ns

    return 0;
}
