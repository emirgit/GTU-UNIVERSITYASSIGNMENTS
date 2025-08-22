# CSE102 - Assignment #2: Functions and Selection in C

## Description

This project is the second assignment for the CSE102 Computer Programming course, focusing on the implementation of complex conditional logic using **selection statements** (`if-else`, `switch`) in C. The program is a menu-driven application that allows the user to choose one of three distinct tasks: a leap year calculator, a student grade evaluator, and an enhanced calculator.

This approach demonstrates the ability to manage different program functionalities within a single, cohesive application and handle various user inputs to produce specific outcomes.

## Program Structure and Features

The program prompts the user to select a part to execute. The logic for each part is contained within a main selection block in the `main` function.

*   **Part 1: Leap Year Calculator**
    *   **Functionality:** Prompts the user to enter a year and determines whether it is a leap year.
    *   **Technical Implementation:** Uses nested `if-else` statements to implement the leap year conditions (a year is a leap year if it is divisible by 4, unless it is a century year, in which case it must also be divisible by 400).

*   **Part 2: Student Grade Calculator**
    *   **Functionality:** Takes three exam scores and two assignment scores as input, calculates a final weighted score, and outputs the corresponding letter grade (A, B, C, D, or F).
    *   **Technical Implementation:** Employs an `if-else if-else` ladder to map the final numerical score to the correct letter grade based on predefined ranges.

*   **Part 3: Enhanced Calculator**
    *   **Functionality:** Performs a basic arithmetic operation (`+`, `-`, `*`, `/`) on two numbers. It also includes a "mode" selection that allows the user to display the result as either an integer or a double.
    *   **Technical Implementation:** Utilizes a `switch` statement to efficiently select and execute the correct arithmetic operation based on the user's input. It also demonstrates type casting to handle the different output modes.


## Learning Objectives

*   **Conditional Control Flow:** Mastery of `if-else`, nested `if-else`, and `switch` statements to control the program's logic.
*   **Menu-Driven Applications:** Structuring a program to offer multiple functionalities based on user choice.
*   **Input/Output Handling:** Managing different types of user input (`int`, `double`, `char`) for various calculations.
*   **Type Casting:** Converting between data types to meet specific output requirements (as seen in the calculator's integer/double modes).
*   **Problem Decomposition:** Separating a multi-part assignment into logical blocks within the code.

## How to Compile and Run

1.  **Prerequisites:** You need to have `GCC` (GNU Compiler Collection) installed.

2.  **Navigate to the project directory:**
    ```bash
    cd GTU-UNIVERSITYASSIGNMENTS/CSE102/Functions\ and\ Selection
    ```
3.  **Compile and run the source code:**
    ```bash
    make
    ```

[Details](https://github.com/emirgit/GTU-UNIVERSITYASSIGNMENTS/blob/main/CSE102/Functions%20and%20Selection/CSE%20102_HW2.pdf)