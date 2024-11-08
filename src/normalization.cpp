#include "normalization.h"

void Normalization::normalize() {
    if (reset.read()) {
        normalized_data.write(0);  // Clear output on reset
    } else {
        // Perform simple normalization (mean normalization for illustration)
        sc_uint<32> mean_value = input_data.read() / 2;  // Simplified mean calculation
        sc_uint<32> result = input_data.read() - mean_value;
        normalized_data.write(result);
    }
}
