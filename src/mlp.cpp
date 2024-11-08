#include "include/mlp.h"

void MLP::compute_mlp() {
    if (reset.read()) {
        mlp_out.write(0);  // Clear output on reset
    } else {
        // Simple MLP computation with non-linearity (ReLU)
        sc_uint<32> intermediate = input_data.read() * 2;  // Example transformation
        sc_uint<32> result = (intermediate > 0) ? intermediate : 0;  // ReLU activation
        mlp_out.write(result);
    }
}
