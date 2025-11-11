# CSE108 - Lab 2: Basic IO Operations and Expressions

This lab is the second in the CSE108 Computer Programming Lab series, building upon foundational C programming skills. It focuses on basic input/output (IO) operations, mathematical calculations, and conditional logic.

The lab is divided into two main parts, each addressing different programming challenges.

## Part 1: Geometric Shape Calculator

This part requires writing a C program that calculates the surface area and volume of various user-defined geometric shapes.

*   **Functionality:** The program will sequentially request dimensions for a cube, rectangular prism, sphere, and cone. For each shape, it will calculate and print its surface area and volume.
*   **Technical Implementation:**
    *   The program must not use any conditional statements (`if-else`, `switch`) to choose between shapes. Instead, it should prompt for information for each shape and calculate all of them.
    *   The value of Pi should be taken as 3.14.
    *   Formulas for surface area (A) and volume (V) are provided:
        *   **Cube:** A = 6a², V = a³
        *   **Rectangular Prism:** A = 2(ab + bc + ac), V = abc
        *   **Cone:** A = πr(b + r), where 'b' is the slant height (calculated as `sqrt(r^2 + h^2)`), V = (1/3)πr²h
        *   **Sphere:** A = 4πr², V = (4/3)πr³
*   **Learning Objectives:**
    *   Implementing mathematical formulas in C.
    *   Handling floating-point arithmetic.
    *   Performing sequential input/output operations.

## Part 2: Body Mass Index (BMI) Calculator

This part involves creating a BMI calculator that also classifies the BMI into different categories.

*   **Functionality:** The program will obtain height and weight information from the user, calculate the BMI, and then classify it as "underweight," "average weight," "overweight," or "obese."
*   **Technical Implementation:**
    *   The formula for BMI is: `BMI = weight(kg) / height(m)^2`.
    *   BMI classification categories:
        *   Less than 18.5: underweight
        *   Between 18.5 and 24.9: average weight
        *   Between 25 and 29.9: overweight
        *   30 or greater: obese
*   **Learning Objectives:**
    *   Implementing mathematical calculations.
    *   Using conditional statements (`if-else if-else`) for classification.
    *   Handling user input for different data types.

## How to Compile and Run

Each part is contained in its own sub-folder within the `src` directory. To compile and run any of the parts:

1.  **Navigate to the specific part's directory:**
    ```bash
    cd CSE108/lab02/src
    ```

2.  **Compile the source code:**
    ```bash
    gcc -o main main.c -lm
    ```
    (The `-lm` flag is necessary to link the math library for functions like `pow()`)

3.  **Run the executable:**
    ```bash
    ./main
    ```

## Output Example

![Output Example](./src/output-example.png)

[Details](./lab2.pdf)