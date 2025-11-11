# CSE102 - Assignment #5: Advanced Functions and Selection 2

## Description

This assignment is a comprehensive project for the CSE102 course, designed to demonstrate mastery over several advanced C programming topics. The project is divided into three distinct, unrelated parts, each targeting a specific set of skills: **file I/O with arrays** for statistical analysis, the use of **enums and function pointers** for complex calculations, and **2D arrays with procedural logic** to create a fully functional, scalable tic-tac-toe game.

## Program Structure and Features

### Part 1: Letter Frequency Counter

This program analyzes a text file to count the frequency of each letter in the English alphabet, ignoring case.

*   **Functionality:**
    *   Prompts the user to enter the name of a text file.
    *   Reads the file character by character, converting all letters to uppercase.
    *   Counts the occurrences of each letter and stores the counts in an integer array.
    *   Handles file-not-found errors gracefully.
    *   Displays the final letter frequencies in a clean, tabular format.

*   **Technical Implementation:**
    *   **File I/O:** Uses `fopen()` and `fgetc()` to process the input file.
    *   **Arrays for Data Aggregation:** An integer array of size 26 serves as a frequency map, where each index corresponds to a letter of the alphabet.
    *   **Character Manipulation:** A helper function (`convert_case`) handles the logic for case conversion based on ASCII values.

### Part 2: Color Mixer Simulation

This program simulates the mixing of two primary colors to find the closest resulting standard color using vector mathematics.

*   **Functionality:**
    *   Prompts the user to enter two primary colors (Red, Green, Blue, Yellow, Orange).
    *   Represents each primary color as a 3D vector.
    *   Calculates the vector of the mixed color by averaging the components of the two input color vectors.
    *   Determines the "closest" resulting primary color by calculating the **Euclidean distance** between the mixed color vector and each of the standard color vectors.
    *   Prints the name and vector of the resulting color.

*   **Technical Implementation:**
    *   **Enums:** A `Color` enumeration (`typedef enum`) is used to provide a type-safe and readable way to represent the primary colors.
    *   **Function Pointers:** A `colorMixer` function accepts a pointer to another function (`mix_colors`) as an argument, demonstrating a powerful C feature for creating flexible and extensible code.
    *   **Mathematical Operations:** Leverages the `math.h` library for `pow()` and `sqrt()` to perform the Euclidean distance calculations.

### Part 3: Scalable Tic-Tac-Toe Game

A fully interactive, two-player tic-tac-toe game that can be scaled to any N x N board size by changing pre-processor directives.

*   **Functionality:**
    *   **Scalable Board:** The game board size is defined by a `ROW` macro (`#define`), allowing for easy expansion from the default 3x3 to an N x N grid.
    *   **Two-Player Gameplay:** Alternates turns between Player 1 ('X') and Player 2 ('O').
    *   **Input Validation:** Checks if player moves are within the board boundaries and if the chosen cell is already occupied.
    *   **Win Condition Logic:** Implements robust logic to check for a winner across all rows, columns, and both main diagonals.
    *   **Draw Detection:** Recognizes and declares a draw if the board becomes full with no winner.
    *   **Replayability:** Asks the players if they wish to start a new game after one concludes.

*   **Technical Implementation:**
    *   **2D Arrays:** A 2D character array (`char board[ROW][COLUMN]`) is used to represent the game state.
    *   **Modular Game Logic:** The code is well-structured with dedicated functions for clearing the board (`clear_board`), printing it (`print_board`), checking for a winner (`check_winner`), and detecting a full board (`is_board_full`).
    *   **Game Loop:** A nested `while` loop structure manages the game flow, turn alternation, and replay logic.

## How to Compile and Run

The provided `Makefile` will compile and run the single `main.c` file which contains all three parts of the assignment.

1.  **Prerequisites:** You need to have `GCC` (GNU Compiler Collection) and `make` installed. The program also requires the math library, which is linked automatically by the `Makefile`.

2.  **Navigate to the project directory:**
    ```bash
    cd CSE102/advanced-functions-and-selection-2/src
    ```

3.  **Compile and run using the `Makefile`:**
    *This single command will clean any previous builds, compile the source code, and execute the program.*
    ```bash
    make
    ```

[Details](./hw5.pdf)