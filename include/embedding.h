#ifndef EMBEDDING_H
#define EMBEDDING_H

#include <systemc>
#include "config.h"

SC_MODULE(Embedding) {
    sc_in<bool> clk;
    sc_in<bool> reset;
    sc_in<sc_uint<32>> input_data;
    sc_out<sc_uint<32>> embedded_data;

    void compute_embedding();

    SC_CTOR(Embedding) {
        SC_METHOD(compute_embedding);
        sensitive << clk.pos();
        dont_initialize();
    }
};

#endif // EMBEDDING_H
