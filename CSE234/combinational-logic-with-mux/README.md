# CSE234 - Lab 3: Combinational Logic with a Multiplexer

This project demonstrates the implementation of a combinational logic circuit in Verilog that combines basic logic gates (NAND, NOR) with a 2-to-1 multiplexer to control the output.

## Program Structure and Features

The implementation consists of two main modules:

1.  **2-to-1 Multiplexer (`MUX`)**
2.  **Main Logic Circuit (`LAB3`)**

### 1. 2-to-1 Multiplexer (`MUX`)

This is a standard 2-to-1 multiplexer. It has two data inputs (`mux0`, `mux1`), one select input (`s`), and one output (`o`). The select line determines which of the data inputs is passed to the output.

-   If `s` = 0, `o` = `mux0`
-   If `s` = 1, `o` = `mux1`

### 2. Main Logic Circuit (`LAB3`)

This is the top-level module that defines the main functionality.

-   **Inputs:** 6 data inputs (`I0` to `I5`) and 1 select input (`SEL0`).
-   **Outputs:** 3 outputs (`O0`, `O1`, `O2`).

The circuit performs the following operations:

1.  **NAND Operation:** A 3-input NAND gate takes `I0`, `I1`, and `I2` as input.
    -   The result is assigned to an internal wire `outs[0]`.
    -   This result is also directly provided as the main output `O0`.
    -   `O0 = ~(I0 & I1 & I2)`

2.  **NOR Operation:** A 3-input NOR gate takes `I3`, `I4`, and `I5` as input.
    -   The result is assigned to an internal wire `outs[1]`.
    -   This result is also directly provided as the main output `O1`.
    -   `O1 = ~(I3 | I4 | I5)`

3.  **Multiplexer Selection:** The `MUX` module is used to select between the results of the NAND and NOR operations.
    -   The NAND result (`outs[0]`) and the NOR result (`outs[1]`) are fed into the multiplexer's data inputs.
    -   The `SEL0` input is used as the select line.
    -   The multiplexer's output is assigned to the main output `O2`.
    -   `O2 = (SEL0 == 0) ? O0 : O1;`

In summary, the circuit calculates a 3-input NAND and a 3-input NOR in parallel, provides their results on `O0` and `O1`, and allows the user to select which of these two results is routed to output `O2` using the `SEL0` switch.

## Learning Objectives

-   Implementing basic logic gates (NAND, NOR) in Verilog.
-   Designing and using a multiplexer to control data flow.
-   Creating hierarchical designs by instantiating sub-modules.
-   Understanding how to combine multiple combinational logic functions into a single circuit.
