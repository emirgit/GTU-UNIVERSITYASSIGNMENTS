# CSE234 - Lab 5: Simple 5-Bit ALU

This project implements a simple 5-bit Arithmetic Logic Unit (ALU) in Verilog on an FPGA. The ALU can perform four basic operations on a 5-bit value stored in a register.

## Program Structure and Features

The design is modular and consists of several components that form a simple ALU controlled by switches.

### Core Components

1.  **5-Bit Register (`register_5bit`)**: Stores the current 5-bit result (`cur`). The register is updated on the rising edge of the clock when the load signal (`KEY[0]`) is active.

2.  **5-Bit Adder (`Add`)**: A combinational circuit that takes two 5-bit numbers and outputs their sum. It is used for the ALU's "add" operation.

3.  **Shift Register (`shift_reg`)**: A 5-bit register capable of performing a shift operation. The behavior is controlled by `SW[4]`.

4.  **4-to-1 Multiplexer (`MUX_5bit`)**: This is the core of the ALU's control logic. It selects which operation's result will be sent to the main register. The selection is controlled by `SW[1:0]`.

### ALU Operations

The ALU operates on a 5-bit value held in the main register. The operation to be performed is selected using `SW[1:0]`, and the result is loaded into the register by pressing `KEY[0]`. The 5-bit output is displayed on `LEDR[4:0]`.

The four supported operations are:

| SW[1] | SW[0] | Operation | Description                                                                 |
| :---: | :---: | :-------- | :-------------------------------------------------------------------------- |
|   0   |   0   | **Hold**  | The multiplexer selects the current register value, effectively holding it. |
|   0   |   1   | **Add**   | Adds the value from switches `SW[9:5]` to the current register value.         |
|   1   |   0   | **Shift** | Selects the output of the shift register.                                   |
|   1   |   1   | **Load**  | Loads the value from switches `SW[9:5]` directly into the register.         |

## Learning Objectives

-   Designing a simple ALU with basic arithmetic and logical operations.
-   Using multiplexers to control data flow and select operations.
-   Implementing and controlling registers with load signals.
-   Combining multiple modules to create a larger, functional digital system.
-   Mapping system controls to FPGA switches and keys.
