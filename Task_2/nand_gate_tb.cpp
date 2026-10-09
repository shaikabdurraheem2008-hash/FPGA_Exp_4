#include <iostream>
#include "nand_gate.h.h"

using namespace std;

int main()
{
    ap_uint<1> a;
    ap_uint<1> b;
    ap_uint<1> c;

    data_t w1;
    data_t w2;
    data_t bias;

    cout << "NAND Perceptron Test" << endl;
    cout << "--------------------" << endl;

    a = 0;
    b = 0;

    nand_gate(a, b, c, w1, w2, bias);

    cout << "A = " << a
         << " B = " << b
         << " Output = " << c << endl;


    a = 0;
    b = 1;

    nand_gate(a, b, c, w1, w2, bias);

    cout << "A = " << a
         << " B = " << b
         << " Output = " << c << endl;


    a = 1;
    b = 0;

    nand_gate(a, b, c, w1, w2, bias);

    cout << "A = " << a
         << " B = " << b
         << " Output = " << c << endl;


    a = 1;
    b = 1;

    nand_gate(a, b, c, w1, w2, bias);

    cout << "A = " << a
         << " B = " << b
         << " Output = " << c << endl;


    cout << endl;

    cout << "Final trained parameters:" << endl;
    cout << "w1   = " << w1 << endl;
    cout << "w2   = " << w2 << endl;
    cout << "bias = " << bias << endl;

    return 0;
}
