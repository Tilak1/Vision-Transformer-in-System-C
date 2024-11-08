#ifndef MLP_H
#define MLP_H

#include <systemc>
#include "config.h"

SC_MODULE(MLP) {
    sc_in<bool> clk;
    sc_in<bool> reset;
    sc_in<sc_uint<32>> input_data;
    sc_out<sc_uint<32>> mlp_out;

    void compute_mlp();

    SC_CTOR(MLP) {
        SC_METHOD(compute_mlp);
        sensitive << clk.pos();
        dont_initialize();
    }
};

#endif // MLP_H
