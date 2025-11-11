# CSE108 - Lab 5: Selections, Loops, and Functions

This lab focuses on developing C programs that utilize selections (if-else, switch), loops (do-while, for), and functions to solve various computational problems. The lab consists of three distinct parts: a temperature conversion utility, an integer reversal tool, and a number base converter.

## Program Structure and Features

The lab is implemented across three separate C files, each addressing a specific problem.

### `part1.c`: Temperature Conversion Program

*   **Functionality:** This program provides a menu-driven interface for converting temperatures between Celsius and Fahrenheit. Users can choose to convert Celsius to Fahrenheit, Fahrenheit to Celsius, or quit the program.
*   **Technical Implementation:**
    *   Uses a `do-while` loop to continuously display the menu and process user choices until the 'Quit' option is selected.
    *   Employs separate functions for displaying the menu (`display_menu`), prompting for temperature input (`prompt_input`), and performing the temperature conversion (`con_temp`).
    *   Formulas used:
        *   Celsius to Fahrenheit: `F = (C * 9 / 5) + 32`
        *   Fahrenheit to Celsius: `C = (F - 32) * 5 / 9`

### `part2.c`: Integer Reversal Program

*   **Functionality:** This program takes an integer as input from the user and reverses its digits. It includes validation to ensure the input number has between 3 and 5 digits.
*   **Technical Implementation:**
    *   Uses a `for` loop to count the number of digits in the input integer.
    *   If the digit count is within the valid range (3-5), another `for` loop is used to reverse the digits of the number.
    *   Provides feedback if the entered number does not meet the digit criteria.

### `part3.c`: Number Base Conversion Program

*   **Functionality:** This program offers a menu to convert a decimal number into its binary, octal, and hexadecimal equivalents.
*   **Technical Implementation:**
    *   Uses a `do-while` loop for the menu interface, allowing multiple conversions until the user chooses to quit.
    *   Employs dedicated functions for each conversion type:
        *   `dectobin(int num)`: Converts decimal to binary.
        *   `dectooct(int num)`: Converts decimal to octal.
        *   `dectohex(int num)`: Converts decimal to hexadecimal (utilizes `printf`'s `%X` format specifier).

## Learning Objectives

*   Implementing menu-driven applications using loops and `switch` statements.
*   Designing and using functions for modular code organization.
*   Applying conditional logic (`if-else`, `switch`) for decision-making and input validation.
*   Working with different data types and performing arithmetic operations.
*   Understanding and implementing algorithms for number manipulation (reversal, base conversion).

## How to Compile and Run

Each part is a separate C file. To compile and run a specific part:

1.  **Navigate to the source directory:**
    ```bash
    cd CSE108/lab05/src
    ```

2.  **Compile the desired source code file:**
    *   For Part 1: `gcc -o part1 part1.c`
    *   For Part 2: `gcc -o part2 part2.c`
    *   For Part 3: `gcc -o part3 part3.c`

3.  **Run the executable:**
    *   For Part 1: `./part1`
    *   For Part 2: `./part2`
    *   For Part 3: `./part3`

## Output Example

![Output Example](./src/output-example.pdf)

[Details](./lab5.pdf)
