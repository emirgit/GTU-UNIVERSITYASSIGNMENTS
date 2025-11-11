# CSE108 - Lab 8: Advanced Mathematical Operations

This lab delves into advanced mathematical operations using C programming, focusing on matrices, vectors, and polynomials. It involves implementing custom data structures and functions to perform calculations such as matrix inversion, vector cross products, and polynomial integration.

## Program Structure and Features

The `main.c` file contains the implementations for all three parts of the lab, utilizing custom `struct` definitions for mathematical entities.

### Part 1: Matrix Operations

*   **`matrix` Struct:** A structure defined to represent a 3x3 matrix, containing a `double` 2D array for its `elements` and a `double` for its `det`erminant.
*   **`print_matrix` Function:** Takes a `matrix` as input and prints its 3x3 elements in a formatted manner, along with its calculated determinant.
*   **`determinant_of_matrix` Function:** Calculates the determinant of a given 3x3 matrix and updates the `det` member of the `matrix` structure.
*   **`invert_matrix` Function:** Computes the inverse of a 3x3 matrix. It first calls `determinant_of_matrix`. If the determinant is zero, it indicates that the matrix is not invertible. Otherwise, it calculates the inverse matrix and stores it in a provided `inverted_matrix` struct, which is then printed.
*   **Main Function Integration:** The `main` function initializes a sample matrix, prints it, and then attempts to invert it, demonstrating the functionality.

### Part 2: Vector Operations

*   **`vector` Struct:** A structure defined to represent a 3D vector with `double` components `x`, `y`, and `z`.
*   **`find_orthogonal` Function:** Accepts two `vector`s and a pointer to an `output_vec`. It calculates the cross product of the two input vectors, storing the result in `output_vec`. Additionally, it computes the angle (in degrees) between the two input vectors and returns this angle.
*   **Main Function Integration:** The `main` function initializes two example vectors, calls `find_orthogonal` to perform the calculations, and then prints the angle between them and the resulting orthogonal vector.

### Part 3: Polynomial Operations

*   **`third_order_polynomial` Struct:** A structure to represent a third-order polynomial with four `double` coefficients (`a`, `b`, `c`, `d`).
*   **`polynomial` Struct:** A structure designed to store the coefficients of a higher-order polynomial (up to 7th degree), a `char constant`, and a `double value_at_interval` representing the definite integral's value. This struct is used to hold the result of polynomial integration.
*   **`integrate` Function:** A helper function that evaluates a 7th-order polynomial at a given `x` value.
*   **`get_integral` Function:** Takes two `third_order_polynomial`s and an integration interval `[a, b]`. It first calculates the coefficients of the polynomial obtained by multiplying the two input polynomials. Then, it integrates this resulting polynomial. The coefficients of the integrated polynomial are stored in a `polynomial` struct. Finally, it calculates the definite integral over the specified interval `[a, b]` using the `integrate` helper function and stores this value in the `polynomial` struct, which is then returned.
*   **Main Function Integration:** The `main` function prompts the user to input coefficients for two third-order polynomials and the integration interval. It then calls `get_integral` and displays the integrated polynomial's coefficients and its definite integral value over the given interval.

## Learning Objectives

*   Designing and implementing custom `struct` data types for complex mathematical entities.
*   Performing matrix operations (determinant, inverse) using C.
*   Implementing vector algebra (cross product, angle calculation) in C.
*   Developing functions for polynomial manipulation, including multiplication and integration.
*   Utilizing mathematical functions from `<math.h>` (e.g., `sqrt`, `acos`, `pow`).
*   Handling formatted input and output for complex data structures.

## How to Compile and Run

1.  **Navigate to the source directory:**
    ```bash
    cd CSE108/lab08/src
    ```

2.  **Compile the source code:**
    ```bash
    gcc -o main main.c -lm
    ```
    (The `-lm` flag is necessary to link the math library for functions like `sqrt`, `acos`, `pow`).

3.  **Run the executable:**
    ```bash
    ./main
    ```

## Output Example

![Output Example](./src/output-example.png)

[Details](./lab8.pdf)
