# CSE234 - Lab 4: Moore FSM Sequence Generator

This project implements a sequential circuit, specifically a Moore-type Finite State Machine (FSM), in Verilog. The FSM cycles through a predefined sequence of states, and each state corresponds to a specific 4-bit output that is displayed on LEDs.

## Program Structure and Features

The design is hierarchical and consists of three modules:

1.  **`counter`**: A clock divider to slow down the main clock.
2.  **`seqcir`**: The Moore FSM that contains the core sequence logic.
3.  **`lab4`**: The top-level module that connects the components.

### 1. Clock Divider (`counter`)

To make the LED sequence visible to the human eye, the fast 50 MHz clock of the FPGA must be slowed down. This module implements a simple 32-bit binary counter that increments on every positive edge of `CLOCK_50`.

The 26th bit of this counter (`cnt[25]`) is used as the clock signal for the FSM. This divides the 50 MHz clock by 2^26, resulting in a clock frequency of approximately 0.75 Hz, meaning the FSM state changes roughly every 1.3 seconds.

### 2. Moore FSM (`seqcir`)

This module implements the core logic of the sequence generator. It is a Moore FSM, which means its output is determined *only* by its current state.

-   **State Register:** A 3-bit register `s[2:0]` holds the current state of the machine. This allows for 2^3 = 8 unique states.
-   **Next State Logic:** A block of combinational logic calculates the *next state* (`n`) based on the *current state* (`s`). The equations are:
    -   `n[0] = (~s[0] & ~s[1]) | (~s[0] & ~s[2])`
    -   `n[1] = (s[0] & ~s[1] & ~s[2]) | (~s[0] & s[1] & ~s[2])`
    -   `n[2] = (s[0] & s[1] & ~s[2]) | (~s[0] & ~s[1] & s[2])`
-   **Output Logic:** Another block of combinational logic determines the 4-bit output `o` based on the *current state* (`s`). The equations are:
    -   `o[0] = (~s[0] & ~s[1] & s[2]) | (s[0] & ~s[1] & s[2])`
    -   `o[1] = (~s[0] & s[1] & ~s[2]) | (s[0] & ~s[1] & s[2]) | (s[0] & s[1] & ~s[2])`
    -   `o[2] = (~s[0] & ~s[1] & ~s[2]) | (s[0] & ~s[1] & ~s[2]) | (s[0] & s[1] & ~s[2]) | (~s[0] & ~s[1] & s[2])`
    -   `o[3] = s[0] | s[1] | s[2]`

### 3. Top-Level Module (`lab4`)

This module instantiates the `counter` and `seqcir` modules, connecting them together. It maps the 4-bit output of the FSM to the first four red LEDs (`LEDR[3:0]`) on the FPGA board. The `KEY` and `SW` inputs are included in the module definition but are not used in the logic.

## Learning Objectives

-   Understanding the difference between combinational and sequential logic.
-   Designing and implementing a Moore-type Finite State Machine.
-   Using a counter as a clock divider to control the speed of a sequential circuit.
-   Implementing state registers and defining next-state and output logic in Verilog.
-   Building a hierarchical design with multiple modules.
