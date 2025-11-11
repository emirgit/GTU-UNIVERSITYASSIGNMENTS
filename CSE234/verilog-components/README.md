# Verilog Components

This directory contains a collection of basic Verilog modules that implement fundamental digital logic components. These components are used in various labs and projects within the CSE234 course.

## Components

### 1. `Decoder2_4.v`

*   **Description:** Implements a 2-to-4 decoder. It takes a 2-bit input and activates one of its four outputs.
*   **Inputs:** `A1`, `A0` (2-bit input)
*   **Outputs:** `I0`, `I1`, `I2`, `I3` (4-bit output)

### 2. `Encoder2_4.v`

*   **Description:** Implements a 4-to-2 priority encoder. It takes a 4-bit input and produces a 2-bit binary code representing the highest-priority active input.
*   **Inputs:** `I0`, `I1`, `I2`, `I3` (4-bit input)
*   **Outputs:** `A1`, `A0` (2-bit output)

### 3. `fullAdder.v`

*   **Description:** Implements a 4-bit full adder. It performs binary addition on two 4-bit numbers.
*   **Inputs:** `A` (4-bit input), `B` (4-bit input)
*   **Outputs:** `SUM` (4-bit sum), `cout` (carry out)

### 4. `fullSubtractor.v`

*   **Description:** Implements a 4-bit full subtractor. It performs binary subtraction on two 4-bit numbers using a 4-bit full adder and XOR gates.
*   **Inputs:** `A` (4-bit input), `B` (4-bit input), `S` (subtraction control)
*   **Outputs:** `SUB` (4-bit difference), `cout` (borrow out)

### 5. `halfAdder.v`

*   **Description:** Implements a 4-bit adder using half adders as building blocks.
*   **Inputs:** `A` (4-bit input), `B` (4-bit input)
*   **Outputs:** `SUM` (4-bit sum), `cout` (carry out)

### 6. `MUX2_1.v`

*   **Description:** Implements a 2-to-1 multiplexer. It selects one of two input signals based on a control signal.
*   **Inputs:** `A0`, `A1` (data inputs), `S` (select input)
*   **Output:** `Y` (selected output)

### 7. `MUX4_1.v`

*   **Description:** Implements a 4-to-1 multiplexer using a 2-to-4 decoder. It selects one of four input signals based on a 2-bit control signal.
*   **Inputs:** `I0`, `I1`, `I2`, `I3` (data inputs), `S0`, `S1` (select inputs)
*   **Output:** `Y` (selected output)

### 8. `MUX4_1using2_1.v`

*   **Description:** Implements a 4-to-1 multiplexer using three 2-to-1 multiplexers.
*   **Inputs:** `A0`, `A1`, `A2`, `A3` (data inputs), `S0`, `S1` (select inputs)
*   **Output:** `Y` (selected output)

### 9. `register_4bit.v`

*   **Description:** Implements a 4-bit register with a load signal. The register loads new data on the positive edge of the clock or when the load signal is high.
*   **Inputs:** `clk` (clock), `load` (load control), `I` (4-bit data input)
*   **Output:** `Q` (4-bit registered output)
