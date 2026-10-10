# CSE233 - Lab 1: Kirchhoff's Voltage Law

## Description

This lab introduces building circuits on a breadboard, reading resistor color codes, and measuring with a voltmeter. Equivalent resistances of series, parallel, and mixed resistor networks are measured with an ohmmeter, and node and component voltages of a ladder network are measured to verify Kirchhoff's Voltage Law (KVL). The measured values are compared with hand calculations using absolute and relative error, and the circuits are simulated in Falstad before the lab.

## Experiment Structure and Simulations

### Preparation

*   Writing the color bands of given resistor values (Table 1), and decoding resistor values from given color bands (Table 2).
*   Filling the calculated columns of Tables 3, 4, and 5 by hand, then simulating the circuits to check the calculations.

### Section 1, Step 1: Equivalent Resistance

Three resistor networks are built and their equivalent resistance `Rab` is measured with an ohmmeter (Table 3):

*   **Circuit 1 (Series):** R1=1kΩ, R2=4.7kΩ, R3=1kΩ, R4=1kΩ, R5=330Ω connected end to end.
*   **Circuit 2 (Parallel):** R1=10kΩ, R2=1kΩ, R3=330Ω, R4=4.7kΩ connected across the same two terminals.
*   **Circuit 3 (Mixed):** A series-parallel combination of R1=330Ω, R2=10kΩ, R3=1.2kΩ, R4=1kΩ, R5=4.7kΩ.

### Section 1, Step 2: Node and Component Voltages

A ladder network driven by `VK1 = 5V` (R1=330Ω, R2=2.2kΩ, R3=2.7kΩ, R4=100kΩ, R5=1.8kΩ, R6=6.8kΩ) is built. The node voltages `Vd1`–`Vd4` are measured against the reference node (Table 4), and the voltage across every component is measured (Table 5).

### Simulation Files

| File | Circuit |
| :--- | :--- |
| `circuitjs-lab01-section01-circuit01.txt` | Circuit 1 (series) with an ohmmeter across a-b |
| `circuitjs-lab01-section01-circuit02.txt` | Circuit 2 (parallel) with an ohmmeter across a-b |
| `circuitjs-lab01-section01-circuit03.txt` | Circuit 3 (mixed) with an ohmmeter across a-b |
| `circuitjs-lab01-section02-circuit01.txt` | The 5V ladder network from Figure 3 |

## Learning Objectives

*   Building circuits on a breadboard.
*   Reading resistor values and tolerances from color codes.
*   Calculating the equivalent resistance of series, parallel, and mixed networks.
*   Measuring node and component voltages correctly with a voltmeter (parallel connection, range selection).
*   Verifying Kirchhoff's Voltage Law and Ohm's Law experimentally.
*   Quantifying measurement accuracy with absolute and relative error.

## How to Open the Simulations

1.  Open the Falstad circuit simulator: [https://www.falstad.com/circuit/circuitjs.html](https://www.falstad.com/circuit/circuitjs.html)
2.  Select **File → Open File...** and choose one of the `.txt` files in this folder.
    *   Alternatively, copy the content of the file and paste it into **File → Import From Text...**

## Link to Details

[experiment-1.pdf](https://github.com/emirgit/GTU-UNIVERSITYASSIGNMENTS/blob/main/CSE233/kirchhoffs-voltage-law/experiment-1.pdf)
