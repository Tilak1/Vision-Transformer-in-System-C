#include "sram.h"

void SRAM::read() {
    if (read_enable.read()) {
        data_out.write(memory[address.read()]);
    }
}

void SRAM::write() {
    if (write_enable.read()) {
        memory[address.read()] = data_in.read();
    }
}
