# CSE241 - Assignment #2: Sparse Matrix and Vector Operations

## Description

This project provides a C++ implementation of sparse vectors and matrices, designed to efficiently handle mathematical operations on data with a large number of zero-valued elements. By storing only the non-zero elements, this approach significantly reduces memory consumption and can speed up computations compared to using traditional dense data structures.

## Program Structure and Features

*   **Core Data Structures:**
    *   `struct data`: A simple structure holding a non-zero element's `index` and its `double` value `d`.
    *   `SparseVector`: Uses `std::vector<struct data>` to store non-zero elements, maintaining `maxIndex` for logical size.
    *   `struct SpVector`: A helper structure for `SparseMatrix`, containing a `row` index and a `SparseVector` object.
    *   `SparseMatrix`: Implemented as `std::vector<struct SpVector>`, where each element represents a non-zero row, and `maxRow` defines the matrix's row dimension.

*   **File Parsing:**
    *   `SparseVector` and `SparseMatrix` can be constructed from text files with specific formats:
        *   `SparseVector`: Each line contains an index and a value (e.g., `4:1.15`).
        *   `SparseMatrix`: Each line represents a row, starting with the row index followed by non-zero elements (e.g., `3 3:24.6 4:5.5`).

*   **Operator Overloading and Algorithms:**
    *   **Addition (`+`) and Subtraction (`-`):** Implemented using an efficient two-pointer algorithm for linear time complexity.
    *   **Negation (`-`):** Unary negation operator flips the signs of non-zero elements.
    *   **Matrix Multiplication (`*`):** Achieved by transposing the second matrix and calculating the dot product of rows.
    *   **Dot Product (`dot()`):** Uses a two-pointer technique for efficient calculation, multiplying only common indexed elements.
    *   **Transpose (`transpose()`):** Creates a new `SparseMatrix` by swapping rows and columns.

## Learning Objectives

*   **Data Structures for Sparse Data:** Understanding and implementing efficient data structures for sparse vectors and matrices.
*   **Operator Overloading:** Mastering operator overloading in C++ to provide an intuitive API for mathematical operations.
*   **Algorithmic Efficiency:** Implementing algorithms (e.g., two-pointer technique) to optimize operations on sparse data.
*   **File I/O and Parsing:** Reading and parsing structured data from text files to populate custom data structures.
*   **Object-Oriented Design:** Designing and implementing classes (`SparseVector`, `SparseMatrix`) with appropriate constructors, member functions, and friend functions.

## How to Compile and Run

This project uses a `makefile` for easy compilation and execution.

1.  **Prerequisites:** You need to have `make` and `g++` installed.

2.  **Navigate to the project directory:**
    ```bash
    cd CSE241/sparse-matrix-vector-operations
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
    This will execute `main.out`. The program will read data from `a1.txt`, `a2.txt`, `m1.txt`, and `m2.txt`, perform the operations defined in `main.cpp`, and write all output to a file named `output.txt`.

5.  **Clean the build files:**
    ```bash
    make clean
    ```
    This will remove the executable, all object files, dependency files, and `output.txt`.

## Link to Details

[PA2.pdf](https://github.com/emirgit/GTU-UNIVERSITYASSIGNMENTS/blob/main/CSE241/sparse-matrix-vector-operations/PA2.pdf)