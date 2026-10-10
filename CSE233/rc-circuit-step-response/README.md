# CSE233 - Lab 5: RC Circuit Step Response

## Description

This lab examines the step response of a first-order RC circuit. A 1kHz square wave from a function generator repeatedly charges and discharges a capacitor through a resistor. The capacitor voltage is observed on an oscilloscope and compared with the theoretical charge `VC = VS·(1 − e^(−t/RC))` and discharge `VC = VS·e^(−t/RC)` curves. The effect of the time constant `τ = R·C` is studied by changing the resistor and the capacitor.

## Experiment Structure and Simulations

### Section 1: R = 1kΩ, C = 47nF

*   The RC circuit in Figure 1 is built and driven by a −5V to 5V, 1kHz square wave.
*   The oscilloscope is connected across the capacitor, the time constant `τ` is calculated, and one period of `VC` is plotted from the experimental data (Table 1).
*   In the preparation, the resistor is also changed to 10kΩ to compare how a larger time constant changes the capacitor waveform.

### Section 2: R = 1kΩ, C = 100nF

*   The 47nF capacitor is replaced with 100nF and the measurement is repeated (Table 2).
*   The two circuits are compared in terms of their time constants and capacitor waveforms.

### Simulation Files

Each simulation shows the source, capacitor, and resistor voltages on scope traces.

| File | Circuit |
| :--- | :--- |
| `circuitjs-lab05-section01-circuit01.txt` | R=1kΩ, C=47nF, 0–10V square wave (5V amplitude, 5V offset), as in Figure 1 |
| `circuitjs-lab05-section01-circuit02.txt` | R=10kΩ, C=47nF, 0–10V square wave (larger time constant comparison) |
| `circuitjs-lab05-section01-circuit03.txt` | R=1kΩ, C=47nF, −5V to 5V square wave, as used in the experiment |
| `circuitjs-lab05-section02-circuit01.txt` | R=1kΩ, C=100nF, −5V to 5V square wave |

## Learning Objectives

*   Understanding first-order RC circuits and their transient behavior.
*   Calculating the time constant `τ = R·C` and interpreting what it means.
*   Explaining the capacitor and resistor voltage waveforms during charging and discharging.
*   Using a function generator and an oscilloscope.
*   Observing how changing R or C affects the circuit response.

## How to Open the Simulations

1.  Open the Falstad circuit simulator: [https://www.falstad.com/circuit/circuitjs.html](https://www.falstad.com/circuit/circuitjs.html)
2.  Select **File → Open File...** and choose one of the `.txt` files in this folder.
    *   Alternatively, copy the content of the file and paste it into **File → Import From Text...**
3.  The scope traces at the bottom of the screen show the waveforms. To change the resistor or capacitor value, double-click the component.

## Link to Details

[experiment-5.pdf](https://github.com/emirgit/GTU-UNIVERSITYASSIGNMENTS/blob/main/CSE233/rc-circuit-step-response/experiment-5.pdf)
