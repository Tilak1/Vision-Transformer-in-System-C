#ifndef SRAM_H
#define SRAM_H

#include <systemc>
#include <vector>
#include "config.h"

SC_MODULE(SRAM) {
    sc_in<bool> clk;
    sc_in<bool> read_enable, write_enable;
    sc_in<sc_uint<32>> address;
    sc_in<sc_uint<32>> data_in;
    sc_out<sc_uint<32>> data_out;

    std::vector<sc_uint<32>> memory;

    void read();
    void write();

    SC_CTOR(SRAM) {
        memory.resize(SRAM_SIZE);  // Define SRAM size in config.h
        SC_METHOD(read);
        sensitive << clk.pos();
        SC_METHOD(write);
        sensitive << clk.pos();
    }
};

#endif // SRAM_H
