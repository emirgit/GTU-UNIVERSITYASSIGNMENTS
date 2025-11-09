module lab01 (
    input [3:0] sw,
    output led
);

// This is the trivial solution, created as a beginner.
// It uses the Sum of Products form directly from the truth table,
// listing all input combinations that result in an odd number of 1s.
assign led = (~sw[3] & ~sw[2] & ~sw[1] & sw[0]) | // 0001
             (~sw[3] & ~sw[2] & sw[1] & ~sw[0]) | // 0010
             (~sw[3] & sw[2] & ~sw[1] & ~sw[0]) | // 0100
             (sw[3] & ~sw[2] & ~sw[1] & ~sw[0]) | // 1000
             (~sw[3] & sw[2] & sw[1] & sw[0]) |   // 0111
             (sw[3] & ~sw[2] & sw[1] & sw[0]) |   // 1011
             (sw[3] & sw[2] & ~sw[1] & sw[0]) |   // 1101
             (sw[3] & sw[2] & sw[1] & ~sw[0]);    // 1110

// A much more efficient and elegant solution is to use the reduction XOR
// operator (^), which performs a bitwise XOR on all bits of the vector.
// assign led = ^sw;

endmodule
