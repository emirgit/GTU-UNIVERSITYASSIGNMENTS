# CSE102 - Homework #8: 8-Puzzle Game Simulation in C

## Description

This project is a complete 8-Puzzle game simulation developed in C. The application demonstrates core programming principles including **data structuring with `structs`**, **recursion**, **advanced file I/O**, and **algorithmic game logic**. The program provides a menu-driven interface allowing a user to play the game manually, have the computer solve it automatically, or view the standing high score. All game states and high scores are saved to external text files for data persistence.

## Program Structure and Features

The application is built around a central `puzzle` struct, which holds the game board state and the current move count. The main menu provides access to the following features:

*   **1. Play Game as a User**
    *   **Solvable Board Generation:** The game begins by creating a randomized 3x3 puzzle board. Crucially, it uses an **inversion count algorithm** (`is_solvable`) to guarantee that every generated puzzle is mathematically solvable.
    *   **Interactive Gameplay:** The user inputs moves in a `number-direction` format (e.g., `2-R` to move the number 2 to the Right). The system includes robust move validation to prevent illegal moves (e.g., moving a tile off the board or into an occupied space).
    *   **Scoring System:** Upon successfully solving the puzzle, the user's score is calculated using the formula: `Score = 1000 - (10 * number_of_moves)`.
    *   **Best Score Tracking:** If the user's score is higher than the current best, it is saved to `best_score.txt`, and the entire move history of the record-breaking game is saved to `best_game.txt`.

*   **2. Finish the Game with PC**
    *   **Recursive Auto-Solver:** This mode utilizes a recursive function, `auto_finish`, to solve the puzzle automatically. The function works by making a series of **random, legal moves** until it reaches the solved state.
    *   **State Logging:** Just like in user mode, the initial board and every subsequent move made by the computer are logged to `last_game.txt`, providing a complete transcript of the solution process.
    *   **Performance Tracking:** Once solved, the program prints the total number of moves the computer took to finish the puzzle.

*   **3. Show the Best Score**
    *   This option reads the current highest score from the `best_score.txt` file and displays it to the user.

*   **4. Persistent File I/O**
    *   **`last_game.txt`:** Records the initial state and every single move of the most recently played game, whether by the user or the PC.
    *   **`best_score.txt`:** Stores the single highest score achieved by a user.
    *   **`best_game.txt`:** A log file that saves the complete move history of the game that achieved the current best score.

## Learning Objectives

*   **Data Structuring with `struct`:** Effectively using `structs` to encapsulate and manage related data, such as the game board and move count.
*   **Recursion:** Implementing a recursive algorithm (`auto_finish`) to perform a complex, repetitive task like solving the puzzle.
*   **Advanced File I/O:** Mastering file operations for persistent data storage, including logging game states and managing a high score system.
*   **Algorithmic Problem-Solving:** Designing and implementing logic for game rules, input validation, win-state checking, and ensuring puzzle solvability (inversion count).
*   **Modular Programming:** Organizing the codebase into separate header (`.h`) and implementation (`.c`) files to create a clean, maintainable, and reusable code structure.
*   **Process Memory Management:** Understanding and managing program stack size to support deep recursion without causing a stack overflow.

## How to Compile and Run

The project includes a `Makefile` for streamlined compilation and execution.

1.  **Prerequisites:** You need to have `GCC` (GNU Compiler Collection) and `make` installed.

2.  **Navigate to the project directory.**
    *(Ensure you are in the directory containing `main.c`, `util.c`, `util.h`, and the `Makefile`)*

3.  **Compile and Run using the `Makefile`:**
    *This single command will clean previous builds, compile the source files, and run the program.*
    ```bash
    make
    ```

    **Important Note:** The `Makefile`'s run command is `ulimit -s 65536 && ./test`. The `ulimit -s 65536` part increases the program's stack size before execution. This is **essential** for the "Finish the game with PC" feature, as the recursive `auto_finish` function can make a very large number of calls, which may lead to a stack overflow error on the default stack size.


[Details](https://github.com/emirgit/GTU-UNIVERSITYASSIGNMENTS/blob/main/CSE102/8-Puzzle%20Game/CSE%20102%20-%20HW8.pdf)