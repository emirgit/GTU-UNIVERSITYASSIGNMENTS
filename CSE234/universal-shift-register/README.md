# CSE234 - Final Lab: 4-Bit Universal Shift Register

This project implements a 4-bit universal shift register in Verilog on a FPGA. The register supports holding its state, parallel loading, and both left and right logical shifts.

## Program Structure and Features

The design is hierarchical and consists of a main register and several control and logic modules.

### Core Components

1.  **`counter`**: A 32-bit counter is used as a clock divider. The 26th bit of the counter output is used to generate a slow clock signal, making the register's state changes visible on the LEDs.

2.  **`register_4bit`**: This is the main 4-bit register. Its behavior is controlled by two select inputs, `s1` and `s0`.

3.  **`shift_l` & `shift_r`**: These modules provide the logic for logical left and right shifts, respectively. They take the current 4-bit register value and output the shifted result.
1
4.  **`MUX`**: A 4-to-1 4-bit multiplexer that selects the next state for the register based on the control signals `s1` and `s0`.

### Operations

The functionality of the shift register is controlled by two push-buttons, `KEY[1]` and `KEY[0]`, which are active-low. The 4-bit input for the parallel load operation is provided by `SW[9:6]`, and the register's output is displayed on `LEDR[3:0]`.

The four operations are:

| `KEY[1]` (s1) | `KEY[0]` (s0) | Operation          | Description                                                                 |
| :-----------: | :-----------: | :----------------- | :-------------------------------------------------------------------------- |
|  Not Pressed  |  Not Pressed  | **Hold State**     | The register reloads its current value, effectively holding the state.      |
|  Not Pressed  |    Pressed    | **Parallel Load**  | The register is loaded with the 4-bit value from switches `SW[9:6]`.        |
|    Pressed    |  Not Pressed  | **Shift Left**     | The register's value is shifted one position to the left (logical shift).   |
|    Pressed    |    Pressed    | **Shift Right**    | The register's value is shifted one position to the right (logical shift).  |

## Learning Objectives

-   Designing a universal shift register with multiple functions.
-   Using multiplexers to implement control logic for selecting operations.
-   Implementing sequential logic with synchronous control signals.
-   Using a clock divider to control the speed of a digital circuit for observation.
-   Mapping control inputs to FPGA push-buttons.
