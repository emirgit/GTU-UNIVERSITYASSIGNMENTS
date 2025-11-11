# CSE102 - Assignment #3: 2D Puzzle Game in C

## Description

This project is a 2D puzzle game developed in C, focusing on core programming concepts such as variables, I/O operations, selection statements, loops, and functions. The game challenges the player to navigate a character across a dynamically sized grid to reach an exit door. This assignment emphasizes procedural generation and state management without the use of arrays, requiring a deeper understanding of loops and conditional logic to render the game world and handle player movement.

## Program Structure and Features

The application is a menu-driven console game with the following key features:

*   **Part 1: Dynamic Room Generation**
    *   **Functionality:** The game prompts the user to define the size of the room (an NxN grid, where N is between 5 and 10).
    *   **Technical Implementation:** The room, player character (`C`), and exit door (`D`) are drawn using nested loops. The starting positions for the character and door are randomized for each new game.

*   **Part 2: Interactive Gameplay and Movement**
    *   **Functionality:** The player controls the character using `w` (up), `a` (left), `s` (down), and `d` (right). The game board is reprinted after every move, showing the updated character position.
    *   **Technical Implementation:** A central game loop continuously prompts the user for input. The program validates each move to prevent the character from moving outside the room boundaries. If the move is invalid, an error message is displayed.

*   **Part 3: Game State Control**
    *   **Functionality:** A dedicated control function checks whether the player's coordinates match the door's coordinates.
    *   **Technical Implementation:** This function returns a status code (`1` or `0`) to determine if the win condition has been met, which then terminates the game loop and displays the total number of moves.

*   **Part 4: Main Game Menu**
    *   **Functionality:** A user-friendly menu is presented at launch, offering three choices:
        1.  **New Game:** Starts a new round by generating a new room.
        2.  **Help:** Displays the rules and movement controls.
        3.  **Exit:** Terminates the program.
    *   **Technical Implementation:** A `switch` statement is used to handle menu navigation, calling the appropriate functions based on user selection.

## Learning Objectives

*   **Procedural Generation:** Mastering the use of nested loops to create and render a 2D grid-based environment without relying on arrays.
*   **State Management:** Tracking game state (like player position and move count) using variables and updating them based on user input.
*   **Modular Programming:** Structuring the code with functions for distinct tasks such as drawing the room, handling player movement, and checking the win condition.
*   **Advanced Conditional Logic:** Implementing complex game rules and input validation using `if-else` and `switch-case` statements.
*   **Randomization:** Utilizing `rand()` and `srand()` to introduce variability and replayability in the game setup.
*   **Menu-Driven Applications:** Building an interactive, user-friendly application that provides clear choices and feedback.

## How to Compile and Run

1.  **Prerequisites:** You need to have `GCC` (GNU Compiler Collection) and `make` installed.

2.  **Clone the repository and navigate to the project directory:**
    ```bash
    git clone https://github.com/emirgit/GTU-UNIVERSITYASSIGNMENTS.git
    cd GTU-UNIVERSITYASSIGNMENTS/CSE102/2d-puzzle-game/src
    ```

3.  **Compile and run the source code:**
    ```bash
    make
    ```

[Details](./hw3.pdf)