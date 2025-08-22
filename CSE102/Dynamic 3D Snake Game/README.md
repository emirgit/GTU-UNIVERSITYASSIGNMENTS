# CSE102 - Homework #9: Dynamic 3D Snake Game in C

## Description

This project is an advanced implementation of the classic Snake game in C, with a unique twist: the game is played on a **dynamic 3D board**. This assignment focuses heavily on **dynamic memory management**, pointer manipulation, and complex game logic. The player controls a snake on a 10x10 grid, aiming to grow as long as possible by eating baits. The environment is hazardous, featuring walls and dynamic obstacles represented as nested blocks, creating a third dimension of height. The game ends if the snake collides with itself, a wall, or an obstacle taller than its current length.

## Program Structure and Features

The game is built using a set of strictly defined functions that manage the entire lifecycle of the game, from board initialization to memory deallocation.

*   **`init_board()` - Dynamic Board Generation:**
    *   The game world is a 10x10x`m` board, implemented as a 3D dynamic array (`BLOCK***`). This structure is created entirely at runtime using `malloc`.
    *   Each cell is a `BLOCK` struct, which can be an empty space (`'e'`), a bait (`'b'`), or part of an obstacle (`'o'`).
    *   The board is initialized with two randomly placed obstacles and one bait, ensuring the snake's starting position (0,0) is clear.

*   **`draw_board()` - Console Rendering:**
    *   This function visualizes the current state of the game in the console.
    *   The snake's head is represented by `'O'` and its body by `'X'`.
    *   Baits are shown as `.` and walls are drawn with `-` and `|`.
    *   Obstacles are uniquely represented by a digit corresponding to their height (number of nested blocks).

*   **`play()` - Main Game Loop:**
    *   This is the central engine of the game. It initializes the snake at the top-left corner with a length of 1.
    *   It manages the core game loop: **draw → get input → move → check status → update**.
    *   This loop continues until a game-over condition is met.
    *   Crucially, this function is also responsible for **freeing all dynamically allocated memory** (the 3D board and the snake array) upon game completion to prevent memory leaks.

*   **`move()` - Snake Movement:**
    *   This function handles the snake's movement based on user input (`w`/`a`/`s`/`d`).
    *   It implements the "follow-the-leader" mechanic, where each segment of the snake's body moves into the previous position of the segment in front of it.
    *   The function includes logic to prevent the snake from immediately reversing its direction (e.g., moving down if its last move was up).

*   **`update()` - Game State and Environment Dynamics:**
    *   **Eating and Growth:** When the snake's head moves onto a bait, its length increases by one. The snake's underlying `Point` array is resized using `realloc` to accommodate the new segment. A new bait is then spawned at a random, valid location.
    *   **Obstacle Interaction:** If the snake's head lands on an obstacle shorter than or equal to its length, the obstacle is destroyed.
    *   **Dynamic Obstacles:** To increase the challenge, the environment changes every 5 moves. If there are fewer than 3 obstacles on the board, a new one is created. Otherwise, an existing obstacle's height is randomly increased.

*   **`check_status()` - Collision and Game-Over Logic:**
    *   This function is called after every move to determine if the game should end. It checks for three fatal conditions:
        1.  The snake's head collides with any part of its own body.
        2.  The snake's head moves outside the 10x10 grid (colliding with a wall).
        3.  The snake's head encounters an obstacle with a height greater than the snake's current length.

## Learning Objectives

*   **Advanced Dynamic Memory Management:** Gaining deep experience with `malloc`, `realloc`, and `free` to manage complex, multi-dimensional data structures created entirely at runtime.
*   **Complex Pointer Manipulation:** Working extensively with pointers, including triple pointers (`BLOCK***`), to access and modify data in a dynamically allocated 3D array.
*   **Data Modeling with Structs:** Using `structs` (`BLOCK`, `Point`) to effectively model the game's entities and their properties.
*   **Algorithmic Game Logic:** Implementing the complete logic for a dynamic game, including player movement, collision detection, scoring/growth mechanics, and a dynamically evolving environment.
*   **Adherence to a Strict API:** Developing a solution by implementing a predefined set of functions, demonstrating the ability to work within specified software design constraints.

## How to Compile and Run

The project includes a `Makefile` for easy compilation and execution.

1.  **Prerequisites:** You need to have `GCC` (GNU Compiler Collection) and `make` installed.

2.  **Navigate to the project directory.**

3.  **Compile and Run using the `Makefile`:**
    *This single command will clean previous builds, compile the source files into an executable named `test`, and start the game immediately.*
    ```bash
    make
    ```

[Details](https://github.com/emirgit/GTU-UNIVERSITYASSIGNMENTS)