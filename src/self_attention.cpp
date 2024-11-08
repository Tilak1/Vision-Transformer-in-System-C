#include "include/self_attention.h"

void SelfAttention::compute_attention() {
    if (reset.read()) {
        attention_out.write(0);  // Clear output on reset
    } else {
        // Simplified dot-product attention calculation
        sc_uint<32> dot_product = query_in.read() * key_in.read();  // Q * K
        sc_uint<32> attention_result = dot_product * value_in.read();  // Apply V
        
        // Normalize the attention output (simplified softmax scaling)
        attention_out.write(attention_result / EMBEDDING_DIM);  // Scaling for simplicity
    }
}