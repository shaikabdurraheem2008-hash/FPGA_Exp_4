#include "nand_gate.h.h"

void nand_gate(
    ap_uint<1> a,
    ap_uint<1> b,
    ap_uint<1> &c,
    data_t &w1_out,
    data_t &w2_out,
    data_t &bias_out
)
{
#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS INTERFACE ap_none port=a
#pragma HLS INTERFACE ap_none port=b
#pragma HLS INTERFACE ap_none port=c
#pragma HLS INTERFACE ap_none port=w1_out
#pragma HLS INTERFACE ap_none port=w2_out
#pragma HLS INTERFACE ap_none port=bias_out

    data_t w1 = 0;
    data_t w2 = 0;
    data_t bias = 0;

    data_t eta = 0.1;

    int epochs = 20;

    ap_uint<1> x1[4] = {0, 0, 1, 1};
    ap_uint<1> x2[4] = {0, 1, 0, 1};
    ap_uint<1> y[4]  = {1, 1, 1, 0};

    // Training
    for (int epoch = 0; epoch < epochs; epoch++)
    {
        for (int i = 0; i < 4; i++)
        {
            data_t z;
            ap_uint<1> y_pred;

            z = w1 * x1[i] + w2 * x2[i] + bias;

            if (z >= 0)
                y_pred = 1;
            else
                y_pred = 0;

            data_t error = y[i] - y_pred;

            w1 = w1 + eta * error * x1[i];
            w2 = w2 + eta * error * x2[i];
            bias = bias + eta * error;
        }
    }

    // Output trained parameters
    w1_out = w1;
    w2_out = w2;
    bias_out = bias;

    // NAND classification
    data_t z_final;

    z_final = w1 * a + w2 * b + bias;

    if (z_final >= 0)
        c = 1;
    else
        c = 0;
}
