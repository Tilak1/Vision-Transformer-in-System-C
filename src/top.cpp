#include "../include/top.h"

void Top::control() {
    if (reset.read()) {
        sram_write_enable.write(false);
        sram_read_enable.write(false);
    } else {
        // Embedding and store in SRAM
        sram_address.write(0);
        sram_data_in.write(embedded_data.read());
        sram_write_enable.write(true);
        wait();
        sram_write_enable.write(false);

        // Self-Attention processing
        sram_address.write(1);
        sram_data_in.write(attention_data.read());
        sram_write_enable.write(true);
        wait();
        sram_write_enable.write(false);

        // MLP processing
        sram_address.write(2);
        sram_data_in.write(mlp_data.read());
        sram_write_enable.write(true);
        wait();
        sram_write_enable.write(false);

        // Normalization processing
        sram_address.write(3);
        sram_data_in.write(norm_data.read());
        sram_write_enable.write(true);
        wait();
        sram_write_enable.write(false);

        // Reading normalized data back from SRAM (example)
        sram_address.write(3);
        sram_read_enable.write(true);
        wait();
        sram_read_enable.write(false);
    }
}
