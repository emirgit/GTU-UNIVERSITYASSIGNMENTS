# CSE102 – Spring 2023 Assignment #3

## Overview

This project involves developing a 2D puzzle game in C, focusing on variables, input/output operations, selections, loops, and functions. The game is set in a dynamically sized NxN room where the player must navigate a character to a door using directional inputs.

## Project Details

### Part 1: Drawing the Room
- The room's size is specified by the user (5 ≤ N ≤ 10).
- The room is displayed with the character (`C`) and the door (`D`) at random locations.
- Coordinates are indicated for better understanding.

### Part 2: Gameplay
- The character can move using the following controls:
  - `a` - left
  - `d` - right
  - `w` - up
  - `s` - down
- The game prompts for new moves and prints the room state after each move.
- Invalid moves or wall collisions are handled with appropriate messages.
- The game ends when the character reaches the door, and the total number of moves is displayed.

### Part 3: Control of Status
- A control function checks if the character's location matches the door's location.
- Returns `1` if the game is over, otherwise `0`.

### Part 4: The Game Menu
- The program starts automatically with a menu:
  - **New Game (1)**: Starts a new game with random positions for the character and door.
  - **Help (2)**: Displays game instructions and rules.
  - **Exit (3)**: Exits the game with a goodbye message.

## Notes
- Arrays are not used in the implementation.
- Proper use of if-else and switch-case statements is required.
- A Makefile is provided for compilation.

## Compilation and Execution
To compile the program, use:
```bash
make

[Details](https://github.com/emirgit/GTU-UNIVERSITYASSIGNMENTS/blob/main/CSE102/HW02/CSE%20102_HW2.pdf)