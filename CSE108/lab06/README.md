# CSE108 - Lab 6: One Dimensional Arrays

This lab focuses on the use of one-dimensional arrays in C programming to process and store data. It includes two main parts: processing user-entered integers to label them as odd or even, and reading structured data from a file to perform calculations based on user input.

## Program Structure and Features

The lab is implemented across two separate C files, each addressing a specific problem.

### `part1.c`: Odd/Even Number Labeling

*   **Functionality:** This program takes a list of integers as input from the user, terminated by a sentinel value (-100). It then processes these numbers, labeling each as 'e' for even or 'o' for odd. Finally, it prints each number along with its corresponding label.
*   **Technical Implementation:**
    *   Uses a `SENTINEL` macro to define the termination value for input.
    *   Employs three functions:
        *   `enter_input(int arr[], int *counter)`: Reads integers from the user and stores them in an array, updating a counter for the actual number of elements.
        *   `dec_label(int arr[], char charr[], int *counter)`: Iterates through the integer array and populates a character array with 'e' or 'o' labels.
        *   `print_arrs(int arr[], char charr[], int *counter)`: Prints the numbers and their labels.
    *   Utilizes a fixed-size array (`MAX_ARRSIZE`) and dynamically tracks the number of valid inputs using a pointer.

### `part2.c`: Team Salary Calculation

*   **Functionality:** This program reads structured data from an external text file (`example.txt`). The data includes age, occupation, salary, and favorite team for several individuals. After reading the data, the program prompts the user to select a team and then calculates and displays the average salary of all individuals who support that team. If no fans are found for the selected team, an appropriate message is displayed.
*   **Technical Implementation:**
    *   Reads the number of data rows from the first line of `example.txt`.
    *   Stores the data into four separate one-dimensional arrays: `ages` (int), `occupations` (char), `salaries` (float), and `fteams` (char).
    *   Uses file I/O functions (`fopen`, `fscanf`, `fclose`) to handle data reading.
    *   Includes error handling for file opening.
    *   Iterates through the `fteams` array to find matches for the user-selected team and calculates the average salary.

## Learning Objectives

*   Working with one-dimensional arrays for data storage and manipulation.
*   Implementing functions for modular program design.
*   Handling user input with sentinel values.
*   Performing file input/output operations to read structured data.
*   Implementing conditional logic for data processing and decision-making.
*   Calculating averages and handling edge cases (e.g., no matching data).

## How to Compile and Run

Each part is a separate C file. To compile and run a specific part:

1.  **Navigate to the source directory:**
    ```bash
    cd CSE108/lab06/src
    ```

2.  **Compile the desired source code file:**
    *   For Part 1: `gcc -o part1 part1.c`
    *   For Part 2: `gcc -o part2 part2.c`

3.  **Run the executable:**
    *   For Part 1: `./part1`
    *   For Part 2: `./part2`

## Output Example

![Output Example](./src/output-example.pdf)

[Details](./lab6.pdf)
