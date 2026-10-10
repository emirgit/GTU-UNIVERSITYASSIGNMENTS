# CSE233 - Lab 3: Superposition and Multiplicativity Theorems

## Description

This lab demonstrates the linearity of resistive circuits through two theorems. The multiplicativity theorem is verified by scaling a source voltage and observing that the current scales by the same factor. The superposition theorem is verified in circuits with two voltage sources by measuring the response to each source alone (the other source short-circuited) and showing that their sum equals the response with both sources active.

## Experiment Structure and Simulations

All circuits use R1=1.8kΩ, R2=4.7kΩ, R3=3.9kΩ, and two 7V sources `VK1` and `VK2`.

### Section 1: Circuit 1 (Figure 1)

*   **Multiplicativity:** `VK2` is short-circuited (0V) and `VK1` is set to 1V, 2V, and 4V. `IR2` is measured for each value to show that it scales with the source (Table 1).
*   **Superposition:** `IR2` is measured with only `VK1` active, with only `VK2` active, and with both active, to show that `I'R2 + I"R2 = IR2` (Table 2).

### Section 2: Circuits 2 and 3 (Figures 2 and 3)

*   A fourth resistor, R4=10kΩ, is connected across the top of the circuit, between the upper terminals of `VK1` and `VK2`.
*   **Circuit 2:** `VK2` is connected with reversed polarity. Superposition is verified for both `IR2` and `IR4` (Table 3).
*   **Circuit 3:** `VK2` is connected with normal polarity. `IR4` is first calculated and then measured to verify superposition (Table 4).

### Simulation Files

| File | Circuit |
| :--- | :--- |
| `circuitjs-lab03-section01.txt` | Circuit 1 (Figure 1) with ammeters on R1, R2, R3 and voltmeters across them |
| `circuitjs-lab03-section02-circuit01.txt` | Circuit 2 (Figure 2): R4 added, `VK2` reversed |
| `circuitjs-lab03-section02-circuit02.txt` | Circuit 3 (Figure 3): R4 added, `VK2` in normal polarity |

## Learning Objectives

*   Understanding the linearity property of resistive circuits.
*   Applying the superposition theorem to circuits with multiple independent sources.
*   Deactivating sources correctly: a voltage source becomes a short circuit, a current source becomes an open circuit.
*   Verifying the multiplicativity (homogeneity) theorem experimentally.
*   Understanding open and short circuits, and why ammeters must be connected in series.

## How to Open the Simulations

1.  Open the Falstad circuit simulator: [https://www.falstad.com/circuit/circuitjs.html](https://www.falstad.com/circuit/circuitjs.html)
2.  Select **File → Open File...** and choose one of the `.txt` files in this folder.
    *   Alternatively, copy the content of the file and paste it into **File → Import From Text...**
3.  To test a single source, set the other source's voltage to 0V by double-clicking it.

## Link to Details

[experiment-3.pdf](https://github.com/emirgit/GTU-UNIVERSITYASSIGNMENTS/blob/main/CSE233/superposition-and-multiplicativity/experiment-3.pdf)
