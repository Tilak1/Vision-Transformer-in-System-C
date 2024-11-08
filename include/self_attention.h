#ifndef SELF_ATTENTION_H
#define SELF_ATTENTION_H

#include <systemc>
#include "config.h"

SC_MODULE(SelfAttention) {
    sc_in<bool> clk;
    sc_in<bool> reset;
    sc_in<sc_uint<32>> query_in, key_in, value_in;
    sc_out<sc_uint<32>> attention_out;

    void compute_attention();

    SC_CTOR(SelfAttention) {
        SC_METHOD(compute_attention);
        sensitive << clk.pos();
        dont_initialize();
    }
};

#endif // SELF_ATTENTION_H
