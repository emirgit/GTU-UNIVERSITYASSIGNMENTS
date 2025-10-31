# CSE241 - Assignment #1: Mastermind Game

## Description

This project is a C++ implementation of the classic code-breaking game, Mastermind. The program generates a secret code, and the player has to guess it. After each guess, the program provides feedback on how many digits are correct in both value and position, and how many are correct in value but in the wrong position.

## Program Structure and Features

*   **Secret Code Generation:**
    *   The program can generate a random secret code of a specified length (`-r N`), where N is between 1 and 15.
    *   Alternatively, the user can provide a secret code directly using the `-u <secret_code>` flag.
    *   The secret code consists of unique digits, which can be any character from `0-9` and `a-e`. The first digit cannot be '0'.

*   **Gameplay Logic:**
    *   The player makes guesses to figure out the secret code.
    *   The game provides two pieces of feedback after each guess:
        *   **Cexact:** The number of digits that are correct in both value and position.
        *   **Cmisplaced:** The number of digits that are correct in value but are in the wrong position.
    *   The game ends when the player guesses the secret code correctly (`Cexact` equals the code length) or after 100 attempts.

*   **Input Handling and Error Checking:**
    *   The program validates command-line arguments to ensure they are correct.
    *   It checks the user's guesses for correct length, valid characters, and unique digits.
    *   The program provides specific error codes for different types of invalid input:
        *   **E0:** Invalid command-line parameters or an invalid secret code provided with the `-u` flag.
        *   **E1:** The user's guess has a different number of digits than the secret code.
        *   **E2:** The user's guess contains invalid characters or non-unique digits.

## Learning Objectives

*   **C++ Fundamentals:** Mastering basic C++ concepts such as variables, I/O operations, loops, and functions.
*   **Command-Line Arguments:** Parsing and validating command-line arguments to control program behavior.
*   **String Manipulation:** Implementing custom functions for string comparison (`f_strcmp`), length calculation (`f_strlen`), and copying (`f_strcp`).
*   **Algorithmic Thinking:** Designing and implementing the core logic of the Mastermind game, including feedback generation.
*   **Error Handling:** Implementing robust error checking to handle invalid user input and command-line arguments.

## How to Compile and Run

1.  **Prerequisites:** You need to have `g++` installed.

2.  **Navigate to the project directory:**
    ```bash
    cd CSE241/mastermind-game
    ```

3.  **Compile the source code:**
    ```bash
    g++ -std=c++11 mastermind.cpp -o mastermind
    ```

4.  **Run the program with a random secret code:**
    ```bash
    ./mastermind -r <N>
    ```
    Replace `<N>` with the desired length of the secret code (e.g., `./mastermind -r 6`).

5.  **Run the program with a user-defined secret code:**
    ```bash
    ./mastermind -u <secret_code>
    ```
    Replace `<secret_code>` with your desired secret code (e.g., `./mastermind -u 1a2b3c`).

## Link to Details

[PA1.pdf](https://github.com/emirgit/GTU-UNIVERSITYASSIGNMENTS/blob/main/CSE241/mastermind-game/PA1.pdf)