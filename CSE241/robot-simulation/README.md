# CSE241 - Assignment #4: Robot Simulation

## Description

This project implements a robot simulation on a grid, where different types of robots engage in combat. The simulation showcases object-oriented programming principles, including inheritance and polymorphism, to model various robot behaviors and interactions. Robots are randomly placed on a grid, move, and fight until only one or no robots remain.

## Program Structure and Features

*   **Object-Oriented Hierarchy:**
    *   **`Robot` (Base Class):** Provides fundamental attributes (strength, hit points, name, type) and behaviors (getting damage, fighting). It defines virtual functions for `getDamage()` and `getType()` to allow for polymorphic behavior.
    *   **`Humanic` (Derived from `Robot`):** An intermediate base class for human-like robots, introducing a 10% chance of a "tactical nuke" attack (additional 50 damage points).
    *   **Specific Robot Types:**
        *   `Optimusprime` (Derived from `Humanic`): Inflicts double damage with a 15% chance.
        *   `Robocop` (Derived from `Humanic`): Standard humanic damage.
        *   `Roomba` (Derived from `Robot`): Attacks twice per turn.
        *   `Bulldozer` (Derived from `Robot`): Standard robot damage.
        *   `Kamikaze` (Derived from `Robot`): Inflicts damage equal to its current hit points and then dies.

*   **World Simulation:**
    *   **`World` Class:** Manages a `GRID_SIZE` x `GRID_SIZE` grid where robots are placed.
    *   **Robot Placement:** Robots of different types are randomly placed on the grid at the start of the simulation.
    *   **Movement and Combat:** In each round, robots attempt to move. If a robot encounters another robot, they engage in combat. The `fight()` method handles the combat logic, applying specific damage rules for each robot type.
    *   **Game End Conditions:** The simulation continues until only one robot remains (winner) or all robots are eliminated (e.g., two Kamikaze robots destroy each other).

*   **Polymorphism and Virtual Functions:** The project extensively uses virtual functions (`getDamage()`, `getType()`) to allow for dynamic method dispatch, enabling different robot types to implement their unique combat mechanics.

*   **Dynamic Memory Management:** Robots are dynamically allocated on the heap, and the `World` class is responsible for their proper deallocation to prevent memory leaks.

## Learning Objectives

*   **Object-Oriented Programming (OOP):** Deep understanding and application of inheritance, polymorphism, and virtual functions in C++.
*   **Class Design:** Designing a class hierarchy with a base class and multiple levels of derived classes.
*   **Dynamic Memory Management:** Implementing `new` and `delete` for objects, including virtual destructors to ensure proper cleanup in inheritance hierarchies.
*   **Game Simulation Logic:** Developing complex simulation logic involving movement, interaction, and state changes on a grid.
*   **Random Number Generation:** Utilizing `rand()` and `srand()` for random robot placement and combat outcomes.

## How to Compile and Run

This project uses a `makefile` for easy compilation and execution.

1.  **Prerequisites:** You need to have `make` and `g++` installed.

2.  **Navigate to the project directory:**
    ```bash
    cd CSE241/robot-simulation
    ```

3.  **Compile the source code:**
    ```bash
    make
    ```
    This will compile the source files and create an executable named `main.out`.

4.  **Run the program:**
    ```bash
    make run
    ```
    This will execute `main.out` and start the robot simulation.

5.  **Clean the build files:**
    ```bash
    make clean
    ```
    This will remove the executable and all object files.

## Link to Details

[PA4.pdf](https://github.com/emirgit/GTU-UNIVERSITYASSIGNMENTS/blob/main/CSE241/robot-simulation/PA4.pdf)