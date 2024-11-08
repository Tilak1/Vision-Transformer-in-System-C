#include "embedding.h"

void Embedding::compute_embedding() {
    if (reset.read()) {
        embedded_data.write(0);  // Clear data on reset
    } else {
        // Perform embedding computations (simplified)
        sc_uint<32> result = input_data.read() * EMBEDDING_SCALE;  // Example scaling
        embedded_data.write(result);
    }
}
