# CSE241 - Problem Solving #2

This project contains solutions for two programming problems as part of the second problem-solving assignment.

## Problem 1: Duel Simulation

### Description

This program simulates a three-person duel between Aaron, Bob, and Charlie, each with different shooting accuracies. The simulation runs for 10,000 rounds to determine the win probabilities for each participant.

### Implementation

The simulation is based on the following probabilities and strategies:
- **Aaron:** Has a 1/3 chance of hitting his target. He prioritizes shooting Charlie, then Bob.
- **Bob:** Has a 1/2 chance of hitting his target. He prioritizes shooting Charlie, then Aaron.
- **Charlie:** Never misses. He prioritizes shooting Bob, then Aaron.

The program records the winner of each round and, after 10,000 rounds, prints the total wins and win percentage for each duelist.

### How to Compile and Run

```bash
g++ q1.cpp -o q1
./q1
```

### Output

![Question 1 Output](q1.png)

---

## Problem 2: Large Number Addition

### Description

This program adds two large integer numbers that are entered by the user. It is designed to handle numbers that may exceed the limits of standard integer types by treating them as character arrays.

### Implementation

The program takes two integers as input and converts them into character arrays, with each character representing a digit. It then performs addition digit by digit, carrying over any overflow to the next digit, similar to how addition is done by hand. The program also includes a check for "Integer Overflow" if the result exceeds the defined buffer size.

A comment in the code indicates a misunderstanding of the original problem, leading to an implementation that uses integers as input but processes them like strings.

### How to Compile and Run

```bash
g++ q2.cpp -o q2
./q2
```

### Output

![Question 2 Output](q2.png)
