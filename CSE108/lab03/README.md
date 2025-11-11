# CSE108 - Lab 3: Selection Operations

This lab focuses on implementing various selection operations in C programming, including finding the median of three numbers, calculating grades using switch statements, and creating a simple arithmetic quiz.

## Program Structure and Features

The program is divided into three distinct parts, each demonstrating different aspects of conditional logic and input/output operations.

### Part 1: Median of Three Integers

*   **Functionality:** This part prompts the user to enter three integers and then determines and prints the median of these numbers.
*   **Technical Implementation:** The solution uses nested `if-else` statements to compare the numbers and find the median, adhering to the constraint of not using logical operators (`&&`, `||`, `!`).

### Part 2: Grade Calculator

*   **Functionality:** This section takes three exam scores as input from the user. It validates the scores to ensure they are within the 0-100 range. For each valid score, it assigns a letter grade based on a predefined grading system and then calculates and displays the average score.
*   **Technical Implementation:** `switch` statements are used to efficiently determine the letter grade for each score based on score ranges.

### Part 3: Arithmetic Quiz

*   **Functionality:** This part presents a simple arithmetic quiz. The user is asked to choose an arithmetic operation (+, -, *, /), enter two numbers, and then provide their expected result. The program performs the calculation and checks if the user's answer is correct, providing appropriate feedback.
*   **Technical Implementation:** A `switch` statement is used to perform the selected arithmetic operation. The program then compares the user's input result with the actual calculated result.

## Learning Objectives

*   Mastering the use of `if-else` and nested `if-else` statements for complex conditional logic.
*   Implementing `switch` statements for multi-way branching based on different conditions.
*   Handling user input and providing structured output.
*   Performing basic arithmetic operations and comparisons.
*   Understanding and applying input validation.

## How to Compile and Run

1.  **Navigate to the source directory:**
    ```bash
    cd CSE108/lab03/src
    ```

2.  **Compile the source code:**
    ```bash
    gcc -o main main.c
    ```

3.  **Run the executable:**
    ```bash
    ./main
    ```

## Output Example

![Output Example](./src/output.pdf)

[Details](./lab3.pdf)
