# Sparse Matrix and Vector Operations in C++

This project provides a C++ implementation of sparse vectors and matrices, designed to efficiently handle mathematical operations on data with a large number of zero-valued elements. By storing only the non-zero elements, this approach significantly reduces memory consumption and can speed up computations compared to using traditional dense data structures.

## Project Overview

The core of this project consists of two main classes: `SparseVector` and `SparseMatrix`. These classes are built to mimic the behavior of standard vectors and matrices, supporting a range of arithmetic operations through operator overloading. The program is capable of parsing text files to construct these sparse objects, performing calculations, and outputting the results.

## Core Data Structures

The efficiency of this project stems from its underlying data structures:

- **`struct data`**: A simple structure that holds a non-zero element's `index` and its `double` value `d`. This is the fundamental unit for storing sparse data.

- **`SparseVector`**: This class uses a `std::vector<struct data>` to store only the non-zero elements of a vector. It also maintains a `maxIndex` to keep track of the vector's logical size.

- **`struct SpVector`**: A helper structure that contains a `row` index and a `SparseVector` object `v`. This is used by the `SparseMatrix` class.

- **`SparseMatrix`**: This class is implemented as a `std::vector<struct SpVector>`, where each element represents a non-zero row in the matrix. It also stores `maxRow` to define the matrix's row dimension.

## Implementation Details

### File Parsing

The `SparseVector` and `SparseMatrix` classes can be constructed directly from a text file. The constructors parse files with a specific format:

- For a `SparseVector`, each line is expected to contain an index and a value, separated by a colon (e.g., `4:1.15`).
- For a `SparseMatrix`, each line represents a row, starting with the row index followed by the non-zero elements of that row (e.g., `3 3:24.6 4:5.5`).

### Operator Overloading and Algorithms

The project heavily utilizes operator overloading to provide an intuitive API.

- **Addition (`+`) and Subtraction (`-`)**: These operations are implemented using an efficient two-pointer algorithm. By iterating through two sparse vectors simultaneously, the corresponding non-zero elements can be added or subtracted in a single pass (linear time complexity relative to the number of non-zero elements).

- **Negation (`-`)**: The unary negation operator iterates through the non-zero elements and flips their signs.

- **Matrix Multiplication (`*`)**: The multiplication of two sparse matrices is implemented by first transposing the second matrix. Then, the dot product of each row of the first matrix with each row of the transposed second matrix is calculated. This results in the corresponding element of the output matrix. If the dot product is zero, no element is stored.

- **Dot Product**: The `dot()` function also uses the two-pointer technique to efficiently calculate the dot product of two `SparseVector`s, only performing multiplications for indices that are present in both vectors.

- **Transpose**: The `transpose()` method creates a new `SparseMatrix` where the rows and columns are swapped. It iterates through the columns of the original matrix to construct the new rows.

## Code Example

Here is a brief example from `main.cpp` demonstrating how to use the classes:

```cpp
#include "SparseVector.h"
#include "SparseMatrix.h"

int main() {
    // Create sparse vectors from files
    SparseVector a1("a1.txt");
    SparseVector a2("a2.txt");

    // Perform and print vector operations
    cout << "a1 + a2" << endl << (a1 + a2) << endl;
    cout << "dot(a1, a2): " << dot(a1, a2) << endl;

    // Create sparse matrices from files
    SparseMatrix m1("m1.txt");
    SparseMatrix m2("m2.txt");

    // Perform and print matrix operations
    cout << "m1 * m2" << endl << (m1 * m2) << endl;
    cout << "m1 transpose" << endl << m1.transpose() << endl;

    return 0;
}
```

## Building and Running

This project uses a `makefile` for easy compilation and execution.

1.  **Build the project:**

    ```bash
    make
    ```

    This will compile the source files and create an executable named `main.out`.

2.  **Run the program:**

    ```bash
    make run
    ```

    This will execute `main.out`. The program will read the data from the `.txt` files, perform the operations defined in `main.cpp`, and write all output to a file named `output.txt`.

3.  **Clean the directory:**

    ```bash
    make clean
    ```

    This command will remove the executable, all object files (`.o`), dependency files (`.d`), and the `output.txt` file.

## Suggested Folder Name

A more descriptive and professional name for the project folder would be:

**`SparseMatrixVectorOperations`**