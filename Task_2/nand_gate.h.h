#ifndef NAND_GATE_H
#define NAND_GATE_H

#include <ap_int.h>
#include <ap_fixed.h>

typedef ap_fixed<8,4> data_t;

void nand_gate(
    ap_uint<1> a,
    ap_uint<1> b,
    ap_uint<1> &c,
    data_t &w1_out,
    data_t &w2_out,
    data_t &bias_out
);

#endif
