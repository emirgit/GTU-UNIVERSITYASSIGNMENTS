# CSE108 - Lab 10: Dynamic Memory Allocation

This lab focuses on the principles of dynamic memory allocation in C, using `malloc`, `calloc`, and `free`. The lab is divided into three parts, each building upon the concept of creating and managing arrays whose sizes are determined at runtime.

## Program Structure and Features

The program is implemented in a single `main.c` file, with distinct sections and functions for each part of the lab.

### Part 1: Dynamic Array Generation and Minimum Value

*   **Functionality:** This part involves creating a function that generates a dynamically allocated array of integers. The size of the array is provided by the user. After the array is created and populated with user-provided values, the program finds and prints the minimum value among its elements.
*   **Technical Implementation:**
    *   **`cre_dyn_arr(int size)`:** A function that takes an integer `size`, allocates memory for an array of that size using `malloc`, prompts the user to enter the elements, and returns a pointer to the newly created array.
    *   The `main` function orchestrates the process: it gets the size, calls `cre_dyn_arr`, finds the minimum element by iterating through the array, prints the result, and then deallocates the memory using `free`.

### Part 2: Cumulative Sum Array

*   **Functionality:** This part extends the first by creating a second dynamically allocated array to store the cumulative sum of the first. The program first generates an array using the function from Part 1. It then calculates the cumulative sum and prints both the original and the cumulative sum arrays.
*   **Technical Implementation:**
    *   **`cumulative_sum_calculator(int* array, int size)`:** This function takes the original array and its size as input. It allocates memory for a new array of the same size using `calloc`. It then iterates through the original array, calculating the cumulative sum at each index and storing it in the new array, which is then returned.
    *   The `main` function handles getting user input, calling the creation and calculation functions, printing both arrays, and finally deallocating memory for both arrays.

### Part 3: Student GPA Calculation

*   **Functionality:** This part simulates a large-scale data processing task. It involves a `Student` struct (`ID`, `age`, `gpa`) and a function that dynamically creates an array of 10,000 `Student` structures, fills it with randomly generated data, and calculates the average GPA. This process is repeated 10,000 times to find the average of all the average GPAs.
*   **Technical Implementation:**
    *   **`Student` Struct:** A simple structure to hold student data.
    *   **`cre_Student_array(int size)`:** A self-contained function that performs a full cycle of operations:
        1.  Dynamically allocates an array of `Student` structs of the given `size` using `malloc`.
        2.  Populates the array with random data for `ID`, `age`, and `gpa`. The GPA is a float between 0.0 and 4.0.
        3.  Calculates the average GPA of all students in *this specific array*.
        4.  Deallocates the array's memory using `free` to prevent memory leaks.
        5.  Returns the calculated average GPA (a `float`).
    *   The `main` function calls `cre_Student_array` in a loop 10,000 times, summing up the returned average GPAs. It then computes the final average of these averages and prints it. This approach is memory-efficient as it avoids holding all 10,000 x 10,000 students in memory at once.

## Learning Objectives

*   Understanding and using dynamic memory allocation functions: `malloc`, `calloc`, and `free`.
*   Creating functions that return pointers to dynamically allocated memory.
*   Managing memory effectively to prevent memory leaks.
*   Working with arrays of structs in dynamically allocated memory.
*   Generating random data using `srand` and `rand`.
*   Implementing algorithms for array manipulation (finding minimum, cumulative sum) on dynamic arrays.

## How to Compile and Run

1.  **Navigate to the source directory:**
    ```bash
    cd CSE108/lab10/src
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

[Details](./lab10.pdf)
