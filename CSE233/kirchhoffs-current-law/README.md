# CSE233 - Lab 2: Kirchhoff's Current Law

## Description

This lab focuses on measuring current with an ammeter and verifying Kirchhoff's Current Law (KCL). Branch currents of a parallel resistor network are measured at several source voltages, and a series-parallel network is analyzed by writing KCL equations for its nodes and KVL equations for its loops. The measurements are compared with hand calculations and Falstad simulations.

## Experiment Structure and Simulations

### Section 1, Step 1: Parallel Network and Total Current

*   **Figure 3:** Three resistors in parallel (R1=12kΩ, R2=15kΩ, R3=18kΩ) driven by `VK1`.
*   The source is set to 5V, 8V, and 12V with the help of a voltmeter. The branch currents `I1`, `I2`, `I3` and the total current `Ik` are measured with an ammeter and compared with the calculated `Ik` (Table 1).

### Section 1, Step 2: Series-Parallel Network

*   **Figure 4:** `R1 || R2` (18kΩ, 15kΩ) in series with `R3 || R4` (12kΩ, 2.2kΩ), driven by a 12V source.
*   All component currents are measured to show that `IR1 + IR2 = IR3 + IR4 = Ik` (Table 2), and all component voltages are measured (Table 3).

### Section 2: Writing the Circuit Equations

*   The three nodes of Figure 4 are identified and their KCL equations are written symbolically and numerically (Table 4).
*   The three loops of Figure 4 are identified and their KVL equations are written symbolically and numerically (Table 5).

### Simulation Files

| File | Circuit |
| :--- | :--- |
| `circuitjs-lab02-section01.txt` | Figure 3 parallel network at 12V with an ammeter on every branch and on the total current `Ik` |
| `circuitjs-lab02-section02.txt` | Figure 4 series-parallel network at 12V with ammeters and voltmeters on every component |

## Learning Objectives

*   Measuring current correctly with an ammeter (series connection, choosing the mA or A input).
*   Identifying the nodes and loops of a circuit.
*   Verifying Kirchhoff's Current Law experimentally.
*   Writing KCL and KVL equations in symbolic and numerical form.
*   Comparing measured, calculated, and simulated results.

## How to Open the Simulations

1.  Open the Falstad circuit simulator: [https://www.falstad.com/circuit/circuitjs.html](https://www.falstad.com/circuit/circuitjs.html)
2.  Select **File → Open File...** and choose one of the `.txt` files in this folder.
    *   Alternatively, copy the content of the file and paste it into **File → Import From Text...**

## Link to Details

[experiment-2.pdf](https://github.com/emirgit/GTU-UNIVERSITYASSIGNMENTS/blob/main/CSE233/kirchhoffs-current-law/experiment-2.pdf)
