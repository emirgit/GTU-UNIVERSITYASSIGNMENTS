# CSE234 - Lab 1: Logic Gates and Introduction to Verilog

This lab serves as an introduction to logic design using Verilog and FPGAs.

## Question 1: Odd Number of 1s Detector

### Description

The problem is to determine if a given 4-bit binary number contains an odd number of ones (1s). The 4-bit number is provided as input through switches on an FPGA.

### Implementation

-   **Input:** A 4-bit number from the FPGA switches (`sw[3:0]`).
-   **Output:** An LED on the FPGA (`led`).
-   **Logic:** The goal is to turn on an LED if the input number contains an odd number of `1`s.

#### Karnaugh Map Analysis

To determine the logic, a Karnaugh map (K-map) is used. The 4-bit input is represented by `A, B, C, D`. The output is 1 when the count of `1`s is odd.

The resulting K-map is as follows:

```
        CD
      00  01  11  10
AB   +---+---+---+---+
00   | 0 | 1 | 0 | 1 |
     +---+---+---+---+
01   | 1 | 0 | 1 | 0 |
     +---+---+---+---+
11   | 0 | 1 | 0 | 1 |
     +---+---+---+---+
10   | 1 | 0 | 1 | 0 |
     +---+---+---+---+
```

The K-map shows a checkerboard pattern, which indicates that the Boolean expression cannot be simplified using standard SOP minimization. This pattern is characteristic of an XOR function.

### Solution Approaches

#### Initial (Trivial) Solution

As a beginner, the most straightforward approach is to derive the Sum of Products (SOP) expression directly from the truth table or K-map. This involves listing all the minterms (input combinations) for which the output is 1.

`led = (~sw[3] & ~sw[2] & ~sw[1] & sw[0]) | (~sw[3] & ~sw[2] & sw[1] & ~sw[0]) | (~sw[3] & sw[2] & ~sw[1] & ~sw[0]) | (sw[3] & ~sw[2] & ~sw[1] & ~sw[0]) | (~sw[3] & sw[2] & sw[1] & sw[0]) | (sw[3] & ~sw[2] & sw[1] & sw[0]) | (sw[3] & sw[2] & ~sw[1] & sw[0]) | (sw[3] & sw[2] & sw[1] & ~sw[0]);`

This solution is functionally correct but is verbose and can be inefficient to implement.

#### Optimized (XOR) Solution

After the lab, a deeper understanding revealed that the problem is a classic application of the XOR function. The K-map's checkerboard pattern is a strong indicator of this. The XOR function naturally outputs a 1 when there is an odd number of 1s in the input.

In Verilog, this can be implemented very concisely using the reduction XOR operator (`^`):

`assign led = ^sw;`

This solution is far more elegant, readable, and efficient.

### Examples

-   **Input:** `0010` (contains one `1`)
    -   **Output:** LED is ON.
-   **Input:** `0011` (contains two `1`s`)
    -   **Output:** LED is OFF.

### Learning Objectives

-   Understanding basic logic gates.
-   Implementing a simple combinational logic circuit in Verilog.
-   Mapping inputs and outputs to FPGA hardware (switches and LEDs).
