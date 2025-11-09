# CSE234 - Lab 2: 5-Bit Subtractor

This project implements a 5-bit subtractor on an FPGA using Verilog. The subtraction is achieved by performing addition with the two's complement of the subtrahend.

## Program Structure and Features

The implementation is modular and hierarchical, consisting of three main components:

1.  **Half Adder (`HA`)**
2.  **Full Adder (`FA`)**
3.  **5-Bit Subtractor (`lab2`)**

### 1. Half Adder (`HA`)

This is the most basic module. It takes two single-bit inputs (`A`, `B`) and produces their sum (`SUM`) and a carry-out (`cout`).

-   `SUM = A ^ B`
-   `cout = A & B`

#### Truth Table

| A | B | SUM | cout |
|---|---|-----|------|
| 0 | 0 | 0   | 0    |
| 0 | 1 | 1   | 0    |
| 1 | 0 | 1   | 0    |
| 1 | 1 | 0   | 1    |

### 2. Full Adder (`FA`)

The Full Adder is built using two Half Adder modules. It adds three single-bit inputs (`a`, `b`, `cin`) and produces a sum (`sum`) and a carry-out (`cout`). This allows for chaining adders together by passing the carry from one to the next.

#### Truth Table

| a | b | cin | sum | cout |
|---|---|-----|-----|------|
| 0 | 0 | 0   | 0   | 0    |
| 0 | 0 | 1   | 1   | 0    |
| 0 | 1 | 0   | 1   | 0    |
| 0 | 1 | 1   | 0   | 1    |
| 1 | 0 | 0   | 1   | 0    |
| 1 | 0 | 1   | 0   | 1    |
| 1 | 1 | 0   | 0   | 1    |
| 1 | 1 | 1   | 1   | 1    |

### 3. 5-Bit Subtractor (`lab2`)

This is the top-level module that performs the subtraction of two 5-bit numbers, `A` and `B`. The operation is `Result = A - B`.

This is implemented by converting the subtraction into an addition problem using the two's complement method: `A - B = A + (-B)`. In binary, the two's complement of `B` is `~B + 1`.

The circuit consists of five Full Adders connected in a ripple-carry configuration:
-   The inputs to the adder are `A` and the bitwise inverse of `B` (`~B`).
-   A `1` is fed into the carry-in (`cin`) of the first Full Adder (for the least significant bit) to complete the `+ 1` part of the two's complement operation.
-   The carry-out of each adder is connected to the carry-in of the next, forming a ripple-carry chain.
-   The final output is the 5-bit `Result` and a final carry-out (`cout1`), which can be used to determine overflow or borrow in certain contexts.

## Learning Objectives

-   Understanding and implementing basic arithmetic circuits (Half and Full Adders).
-   Building complex combinational circuits from smaller, modular components.
-   Grasping the concept of two's complement subtraction.
-   Designing a multi-bit ripple-carry adder/subtractor in Verilog.
