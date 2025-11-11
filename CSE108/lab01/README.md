# CSE108 - Lab 1: Basic IO Operations and Expressions

This lab is the first in the CSE108 Computer Programming Lab series, designed to build foundational skills in C programming. The lab focuses on basic input/output (IO) operations, mathematical expressions, and conditional logic using `if-else` statements.

The lab is divided into three distinct parts, each targeting a different aspect of fundamental programming.

## Part 1: FizzBuzz

This part is a classic programming challenge that tests basic conditional logic.

*   **Functionality:** The program prompts the user to enter an integer between 1 and 100. It then prints "Fizz" if the number is divisible by 3, "Buzz" if it is between 5 and 50, and "FizzBuzz" if both conditions are true.
*   **Learning Objectives:**
    *   Mastering the use of `if-else` statements for conditional execution.
    *   Implementing logic with multiple, overlapping conditions.
    *   Handling basic user input and producing formatted output.

## Part 2: Mathematical Formula Calculation

This part focuses on implementing a mathematical formula and handling decimal numbers, with a constraint that prevents the use of standard library functions for finding a maximum value.

*   **Functionality:** The program takes two integer numbers, `X` and `Y`, as input and calculates the value of `Z` using the formula:
    `Z = (X / Y) + (max(X, Y) / (X + Y))`
*   **Learning Objectives:**
    *   Working with floating-point numbers (`double`).
    *   Implementing mathematical expressions in C.
    *   Devising a way to find the maximum of two numbers using only basic conditional logic, without relying on built-in functions.

## Part 3: Salary Calculation with a Lookup Table

This part involves implementing a more complex set of nested conditions to determine an employee's salary based on their age and years of experience.

*   **Functionality:** The program prompts the user for their age and years of experience and calculates their salary based on a predefined lookup table. For example, an employee between 20 and 50 years old with 0-10 years of experience earns 15,000, while one with over 10 years of experience earns 20,000.
*   **Learning Objectives:**
    *   Building complex, multi-level conditional logic to handle a variety of cases.
    *   Translating a business rule or a lookup table into a functional `if-else` structure.
    *   Managing multiple inputs to produce a single, specific output.

## How to Compile and Run

Each part is contained in its own sub-folder within the `src` directory. To compile and run any of the parts:

1.  **Navigate to the specific part's directory:**
    ```bash
    cd CSE108/lab01/src/part<N> 
    ```
    (Replace `<N>` with 1, 2, or 3)

2.  **Compile the source code:**
    ```bash
    gcc -o main main.c
    ```

3.  **Run the executable:**
    ```bash
    ./main
    ```

[Details](./lab1.pdf)