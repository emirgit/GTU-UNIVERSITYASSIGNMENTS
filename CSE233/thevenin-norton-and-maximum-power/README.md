# CSE233 - Lab 4: Thevenin, Norton, and Maximum Power Transfer Theorems

## Description

This lab reduces a resistive network to its Thevenin and Norton equivalent circuits and examines the maximum power transfer theorem. The Thevenin voltage, Thevenin resistance, and Norton current are measured at the a-b terminals of the circuit. The circuit is then loaded with `RL = 0.1·RTh`, `RL = RTh`, and `RL = 10·RTh` to show that the load receives the most power when `RL = RTh`. In the simulations, both the original circuit and its Thevenin equivalent are loaded to compare them.

## Experiment Structure and Simulations

### The Circuit (Figure 3)

`VK1 = 12V`, R1=5.6kΩ, R2=2.2kΩ, R3=10kΩ, R4=5.6kΩ, and R5=12kΩ connected between terminals a and b.

### Steps

1.  **Thevenin Voltage (`VTh`):** R5 is removed and the open-circuit voltage between a and b is measured.
2.  **Thevenin Resistance (`RTh`):** The source is replaced with a short circuit and the resistance between a and b is measured with an ohmmeter.
3.  **Equivalent Circuits:** The Thevenin equivalent is drawn from the measured values, and the Norton equivalent is derived by source transformation.
4.  **Norton Current (`IN`):** The short-circuit current between a and b is measured and compared with the Norton circuit.
5.  **Maximum Power Transfer:** The load current, load voltage, load power `PRL`, and the power on `RTh` are measured and calculated for the three load values (330Ω, 3.3kΩ, and 33kΩ ≈ 0.1, 1, and 10 × `RTh`).

### Simulation Files

| File | Circuit |
| :--- | :--- |
| `circuitjs-lab04-section01-circuit01.txt` | Original circuit with R5 removed, voltmeter across a-b (`VTh`) |
| `circuitjs-lab04-section01-circuit02.txt` | Source replaced with a short circuit, ohmmeter across a-b (`RTh`) |
| `circuitjs-lab04-section01-circuit03.txt` | Ammeter shorting a-b (Norton current `IN`) |
| `circuitjs-lab04-section01-circuit04.txt` | Original circuit loaded with 330Ω (`RL ≈ 0.1·RTh`) |
| `circuitjs-lab04-section01-circuit05-v1.txt` | Thevenin equivalent (8V, 3.33kΩ) loaded with 330Ω (`RL ≈ 0.1·RTh`) |
| `circuitjs-lab04-section01-circuit05-v2.txt` | Original circuit loaded with 330Ω, without the R3 ammeter |
| `circuitjs-lab04-section01-circuit06-v1.txt` | Thevenin equivalent loaded with 3.33kΩ (`RL = RTh`) |
| `circuitjs-lab04-section01-circuit07-v1.txt` | Thevenin equivalent loaded with 33kΩ (`RL ≈ 10·RTh`) |

## Learning Objectives

*   Simplifying a linear circuit into its Thevenin and Norton equivalents.
*   Measuring open-circuit voltage, short-circuit current, and input resistance.
*   Converting between Thevenin and Norton forms with source transformation.
*   Verifying the maximum power transfer theorem (`RL = RTh`).
*   Checking that the original circuit and its Thevenin equivalent behave identically at the load.

## How to Open the Simulations

1.  Open the Falstad circuit simulator: [https://www.falstad.com/circuit/circuitjs.html](https://www.falstad.com/circuit/circuitjs.html)
2.  Select **File → Open File...** and choose one of the `.txt` files in this folder.
    *   Alternatively, copy the content of the file and paste it into **File → Import From Text...**

## Link to Details

[experiment-4.pdf](https://github.com/emirgit/GTU-UNIVERSITYASSIGNMENTS/blob/main/CSE233/thevenin-norton-and-maximum-power/experiment-4.pdf)
