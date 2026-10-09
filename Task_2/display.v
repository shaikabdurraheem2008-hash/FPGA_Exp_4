`timescale 1ns / 1ps
module perceptron_display(
    input clk,
    input rst,

    input A,
    input B,

    input select_w1,
    input select_w2,
    input select_bias,
    output nand_led,
    output reg [7:0] led
);

    // Outputs from HLS perceptron
    wire nand_out;
    wire [7:0] w1_out;
    wire [7:0] w2_out;
    wire [7:0] bias_out;

    // HLS-generated perceptron
    nand_gate (
        .ap_clk(clk),
        .ap_rst(rst),

        .a(A),
        .b(B),
        .c(nand_out),

        .w1_out(w1_out),
        .w2_out(w2_out),
        .bias_out(bias_out)
    );

    // NAND output LED
    assign nand_led = nand_out;

    // Select which parameter is displayed
    always @(*) begin

        if (select_w1)
            led = w1_out;

        else if (select_w2)
            led = w2_out;

        else if (select_bias)
            led = bias_out;

        else
            led = 8'b00000000;

    end

endmodule
