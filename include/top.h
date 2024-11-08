#ifndef TOP_H
#define TOP_H

#include <systemc>
#include "include/embedding.h"
#include "include/self_attention.h"
#include "include/mlp.h"
#include "include/normalization.h"
#include "include/sram.h"

SC_MODULE(Top) {
    // Module instances
    Embedding embedding_inst;
    SelfAttention self_attention_inst;
    MLP mlp_inst;
    Normalization normalization_inst;
    SRAM sram_inst;

    // Signals
    sc_signal<bool> clk, reset;
    sc_signal<sc_uint<32>> data_in, embedded_data, attention_data, mlp_data, norm_data;
    sc_signal<bool> sram_read_enable, sram_write_enable;
    sc_signal<sc_uint<32>> sram_address, sram_data_in, sram_data_out;

    // Constructor to instantiate and connect modules
    SC_CTOR(Top)
        : embedding_inst("Embedding"),
          self_attention_inst("SelfAttention"),
          mlp_inst("MLP"),
          normalization_inst("Normalization"),
          sram_inst("SRAM")
    {
        // Connect Embedding module
        embedding_inst.clk(clk);
        embedding_inst.reset(reset);
        embedding_inst.input_data(data_in);
        embedding_inst.embedded_data(embedded_data);

        // Connect Self-Attention module
        self_attention_inst.clk(clk);
        self_attention_inst.reset(reset);
        self_attention_inst.query_in(embedded_data);
        self_attention_inst.key_in(embedded_data);  // Simplified example
        self_attention_inst.value_in(embedded_data);  // Simplified example
        self_attention_inst.attention_out(attention_data);

        // Connect MLP module
        mlp_inst.clk(clk);
        mlp_inst.reset(reset);
        mlp_inst.input_data(attention_data);
        mlp_inst.mlp_out(mlp_data);

        // Connect Normalization module
        normalization_inst.clk(clk);
        normalization_inst.reset(reset);
        normalization_inst.input_data(mlp_data);
        normalization_inst.normalized_data(norm_data);

        // Connect SRAM for intermediate storage
        sram_inst.clk(clk);
        sram_inst.read_enable(sram_read_enable);
        sram_inst.write_enable(sram_write_enable);
        sram_inst.address(sram_address);
        sram_inst.data_in(sram_data_in);
        sram_inst.data_out(sram_data_out);

        SC_METHOD(control);
        sensitive << clk.pos();
    }

    void control();
};

#endif // TOP_H
