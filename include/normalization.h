#ifndef NORMALIZATION_H
#define NORMALIZATION_H

#include <systemc>
#include "config.h"

SC_MODULE(Normalization) {
    sc_in<bool> clk;
    sc_in<bool> reset;
    sc_in<sc_uint<32>> input_data;
    sc_out<sc_uint<32>> normalized_data;

    void normalize();

    SC_CTOR(Normalization) {
        SC_METHOD(normalize);
        sensitive << clk.pos();
        dont_initialize();
    }
};

#endif // NORMALIZATION_H
