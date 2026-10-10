# CSE233 - Lab 6: Diodes and Rectifiers

## Description

This lab explores how diodes work and how they are used to convert AC to DC. In the first part, the current-voltage characteristic curve of a 4.7V Zener diode is obtained by sweeping the input voltage through both reverse breakdown and forward conduction. In the second part, a half-wave rectifier is built with a 1N4001 diode, and the effect of a smoothing capacitor on its output is observed on an oscilloscope.

## Experiment Structure and Simulations

### Section 1: Zener Diode Characteristic Curve

*   **Circuit 1:** A DC source `Vin`, R1=12kΩ, and a 4.7V Zener diode in series.
*   `Vin` is swept from −6V to −3.5V (reverse bias and breakdown region) and from 0V to 0.9V (forward bias region). The diode voltage `Vd` and current `Id` are calculated and measured at each step (Table 1).
*   The characteristic curve of the Zener diode is plotted from the measured data.

### Section 2: Half-Wave Rectifier

*   **Figure 3:** A 100Hz AC source, a 1N4001 diode, R1=12kΩ as the load, and an optional C1=220µF filter capacitor.
*   The input `V1` and the output `V2` are observed on two oscilloscope channels, first without and then with the capacitor, and both waveforms are plotted.
*   The effective (RMS) value of the input `V1` is calculated.

### Simulation Files

| File | Circuit |
| :--- | :--- |
| `circuitjs-lab06-section01-circuit01.txt` | Zener circuit with `Vin = −6V` |
| `circuitjs-lab06-section01-circuit02.txt` | Zener circuit with `Vin = −5V` |
| `circuitjs-lab06-section01-circuit03.txt` | Zener circuit with `Vin = −4V` |
| `circuitjs-lab06-section01-circuit04.txt` | Zener circuit with `Vin = 0.6V` |
| `circuitjs-lab06-section01-circuit05.txt` | Zener circuit with `Vin = 0.8V` |
| `circuitjs-lab06-section02-circuit01.txt` | Half-wave rectifier without the filter capacitor |
| `circuitjs-lab06-section02-circuit02.txt` | Half-wave rectifier with the 220µF filter capacitor |

## Learning Objectives

*   Understanding the difference between AC and DC.
*   Understanding diode behavior in forward bias, reverse bias, and Zener breakdown.
*   Obtaining a diode's characteristic (I-V) curve experimentally.
*   Building a half-wave rectifier and understanding how it converts AC to pulsating DC.
*   Understanding how a filter capacitor smooths the rectified output.
*   Calculating the effective (RMS) value of an AC signal.

## How to Open the Simulations

1.  Open the Falstad circuit simulator: [https://www.falstad.com/circuit/circuitjs.html](https://www.falstad.com/circuit/circuitjs.html)
2.  Select **File → Open File...** and choose one of the `.txt` files in this folder.
    *   Alternatively, copy the content of the file and paste it into **File → Import From Text...**
3.  For the other `Vin` values in Table 1, double-click the source in any Zener circuit and change its voltage.

## Link to Details

[experiment-6.pdf](https://github.com/emirgit/GTU-UNIVERSITYASSIGNMENTS/blob/main/CSE233/diodes-and-rectifiers/experiment-6.pdf)
