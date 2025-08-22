# CSE102 - Assignment #4: File I/O and Interactive Programming in C

## Description

This project, the fourth assignment for the CSE102 course, focuses on advanced C programming concepts including **file I/O**, **function decomposition**, and building interactive console applications. The assignment is divided into two distinct parts: a restaurant receipt generator that processes data from an external file, and a classic Rock, Paper, Scissors game. A primary challenge and learning objective of this assignment is to perform all operations, including text parsing and formatting, **without the use of arrays**.

## Program Structure and Features

### Part 1: Restaurant Receipt Calculator

This program simulates a restaurant ordering system that reads a menu from `menu.txt`, processes user orders, calculates costs with discounts and taxes, and generates a formatted receipt.

*   **Functionality:**
    *   **Dynamic Menu Display:** Reads and displays the food items and prices from `menu.txt`.
    *   **Interactive Ordering:** Prompts the user to select products and specify quantities in a loop.
    *   **Complex Calculations:** Computes the total cost and applies conditional discounts:
        *   A **12.5% student discount**.
        *   An additional **10% discount** if the post-student-discount total is 150 TL or more.
    *   **VAT Calculation:** Adds an 18% VAT to the final price.
    *   **Receipt Generation:** Writes a fully formatted receipt, including the timestamp, ordered items, discounts, and final price, to `receipt.txt` and then prints it to the console.

*   **Technical Implementation:**
    *   **File I/O:** Utilizes `fopen()`, `fgetc()`, `fscanf()`, and `fprintf()` for all file operations.
    *   **Array-less Programming:** All text alignment and data parsing are handled by manually processing character and line counts from the file stream, showcasing precise control over I/O.
    *   **Modular Design:** The logic is cleanly separated into functions (`menu`, `receipt`, `print_receipt`, `ctdigit`) for improved readability and maintenance.

### Part 2: Rock, Paper, Scissors Game

A classic interactive console game where the user plays against the computer.

*   **Functionality:**
    *   Prompts the user to choose between Stone, Paper, or Scissors.
    *   The computer makes a random choice.
    *   The program determines and announces the winner of the round.
    *   Asks the user if they want to play again, looping until they decline.

*   **Technical Implementation:**
    *   **Random Number Generation:** Employs `srand(time(NULL))` to ensure the computer's choice is different each time the program is run.
    *   **Game Loop:** A `while` loop controls the game flow, allowing for continuous play.
    *   **Conditional Logic:** A `switch-case` block combined with `if-else` statements efficiently determines the outcome of each round.

## Learning Objectives

*   **File Handling in C:** Mastering reading from and writing to external text files.
*   **Data Parsing without Arrays:** Developing algorithms to process and format text data directly from file streams.
*   **Function Decomposition:** Structuring a complex program into small, reusable, and single-purpose functions.
*   **State Management:** Tracking user input and calculating a running total across multiple interactions.
*   **Advanced Conditional Logic:** Implementing complex business rules (discounts, VAT) and game logic using nested conditionals.
*   **Interactive Console Applications:** Building programs that effectively engage with the user, handle various inputs, and provide clear, formatted output.

## How to Compile and Run

This repository contains two separate programs. The provided `Makefile` is configured for **Part 1 (Restaurant Receipt Calculator)**.

### Part 1: Restaurant Receipt Calculator

*   **Using the `Makefile` (Recommended):**
    1.  Navigate to the project directory:
        ```bash
        cd GTU-UNIVERSITYASSIGNMENTS/CSE102/Advanced\ Functions\ and\ Selection/Advanced\ Functions\ and\ Selection/Basic\ Ecommerce\ Program
        ```
    2.  Simply run the `make` command. This will automatically clean previous builds, compile `main.c`, and run the executable.
        ```bash
        make
        ```

### Part 2: Rock, Paper, Scissors Game

*   **Using the `Makefile` (Recommended):**
    1.  Navigate to the project directory:
        ```bash
        cd GTU-UNIVERSITYASSIGNMENTS/CSE102/Advanced\ Functions\ and\ Selection/Advanced\ Functions\ and\ Selection/Rock\ Paper\ Scissors\ Game
        ```
    2.  Simply run the `make` command. This will automatically clean previous builds, compile `main.c`, and run the executable.
        ```bash
        make
        `

[Details](https://github.com/emirgit/GTU-UNIVERSITYASSIGNMENTS/blob/main/CSE102/Advanced%20Functions%20and%20Selection/HM4_v2.pdf)