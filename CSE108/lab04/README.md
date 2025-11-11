# CSE108 - Lab 4: Loop, Functions, File Operations

This lab focuses on implementing a menu-driven C program that utilizes loops, functions, and file operations to generate, read, and draw basic geometric shapes (squares and triangles) on the console.

## Program Structure and Features

The program provides a user-friendly menu to interact with shape data and drawing functionalities.

### Main Menu

The `main` function presents the user with the following options:
1.  **Generate a shape file:** Allows the user to create a new `shapes.txt` file by defining shapes and their sizes.
2.  **Read and draw a shape file:** Reads shapes from `shapes.txt` and draws them on the console.
3.  **Terminate the program:** Exits the application.

### `write_seq_to_txt` Function

*   **Functionality:** Prompts the user to input a shape type ('s' for square, 't' for triangle) and its size. This data is then written to `shapes.txt`. The process continues until the user enters 'e' to exit.
*   **Input Validation:** Ensures that the entered size for a shape is between 3 and 10.
*   **Automation:** After the `shapes.txt` file is generated, this function automatically triggers the `draw_byreading` function to display the newly defined shapes.

### `draw_square` Function

*   **Functionality:** Takes an integer `side` as input and draws a hollow square of that size on the console using `*` characters.

### `draw_triang` Function

*   **Functionality:** Takes an integer `side` as input and draws a hollow equilateral triangle of that size on the console using `*` characters.

### `draw_byreading` Function

*   **Functionality:** Reads the `shapes.txt` file line by line, parsing the shape type and size. Based on the parsed data, it calls either `draw_square` or `draw_triang` to render the respective shape on the console.

## Learning Objectives

*   Implementing menu-driven programs using loops and `switch` statements.
*   Utilizing functions for modular programming and code reusability.
*   Performing file input/output operations (`fopen`, `fclose`, `fprintf`, `fscanf`, `fgetc`).
*   Implementing input validation for user-provided data.
*   Developing algorithms for drawing basic geometric shapes using character output.

## How to Compile and Run

1.  **Navigate to the source directory:**
    ```bash
    cd CSE108/lab04/src
    ```

2.  **Compile the source code:**
    ```bash
    gcc -o main main.c
    ```

3.  **Run the executable:**
    ```bash
    ./main
    ```

## Output Example

![Output Example](./src/output-example.png)

[Details](./lab4.pdf)
