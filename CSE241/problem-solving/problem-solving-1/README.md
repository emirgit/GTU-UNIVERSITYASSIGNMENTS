# CSE241 - Problem Solving #1

This project contains solutions for two programming problems as part of the first problem-solving assignment.

## Problem 1: Prime Number Finder

### Description

This program finds and prints all prime numbers between 3 and 100. A prime number is a number greater than 1 that has no positive divisors other than 1 and itself.

### Implementation

The solution uses a nested loop approach. The outer loop iterates through numbers from 3 to 100, and an inner loop checks if each number is prime. A number `n` is determined to be prime if it is not evenly divisible by any number from 2 up to the square root of `n`.

### How to Compile and Run

```bash
g++ q1.cpp -o q1
./q1
```

### Output

![Question 1 Output](q1.png)

---

## Problem 2: Game of Pig

### Description

This program implements the game of Pig, a simple two-player dice game where the first player to reach 100 or more points wins. The game is played between a human player and the computer.

### Game Rules

*   Players take turns rolling a six-sided die.
*   On each turn, a player can:
    *   **Roll:** If the player rolls a 2-6, the number is added to their turn total, and they can choose to roll again or hold.
    *   **Hold:** The turn total is added to the player's overall score, and it becomes the other player's turn.
*   If a player rolls a 1, their turn ends, they lose all points accumulated in that turn, and it becomes the other player's turn.
*   The first player to reach 100 or more points wins.

### Computer Player Logic

The computer player follows a simple rule: it keeps rolling until it has accumulated 20 or more points in its turn, at which point it holds.

### How to Compile and Run

```bash
g++ q2.cpp -o q2
./q2
```

### Output

**Game Start:**

![Game of Pig - Start](q2_start.png)

**Game End:**

![Game of Pig - End](q2_end.png)

## Link to Details

[PS1.pdf](https://github.com/emirgit/GTU-UNIVERSITYASSIGNMENTS/blob/main/CSE241/problem-solving/Muhammed_Emir_Kara_PS1/PS1.pdf)