# CSE241 - Assignment #5: Data Catalog Parser

## Description

This project is a C++ application designed to parse, manage, and query a catalog of data from text files. It reads a data file to understand the catalog's structure and content, and then processes a command file to perform search and sort operations. The project emphasizes object-oriented design, exception handling, and the use of the C++ Standard Template Library (STL).

## Program Structure and Features

*   **Catalog Management:**
    *   **`Catalog` Class:** The central class that manages the entire catalog. It reads the data and command files, processes the commands, and handles exceptions.
    *   **Data Parsing:** The `Parse` class is used to parse lines from the input files based on a specified delimiter.
    *   **Dynamic Data Representation:** The project uses a hierarchy of `Field` classes to dynamically represent different data types (integer, double, string, and their vector counterparts), allowing for flexible data handling.

*   **File I/O and Command Processing:**
    *   **`data.txt`:** Defines the structure of the catalog on the first line and contains the catalog entries on subsequent lines.
    *   **`commands.txt`:** Contains a series of commands to be executed on the catalog, such as `search` and `sort`.
    *   **`output.txt`:** A log file where the program writes the results of the operations and any exceptions encountered.

*   **Exception Handling:**
    *   The program implements a robust exception handling mechanism to deal with various errors:
        *   `FileOpenError`: Thrown if an input file cannot be opened.
        *   `MissingFieldException`: Thrown if a data entry is missing a field.
        *   `DuplicateEntryException`: Thrown if a duplicate entry is found in the data file.
        *   `WrongCommandException`: Thrown if a command in the command file is malformed.

*   **Search and Sort Functionality:**
    *   **`search` command:** Searches for a specific value within a specified field of the catalog and outputs the matching entries.
    *   **`sort` command:** Sorts the entire catalog based on a specified field in ascending order.

## Learning Objectives

*   **Object-Oriented Programming (OOP):** Designing a system with multiple interacting classes, including the use of inheritance and polymorphism with the `Field` class hierarchy.
*   **C++ Standard Template Library (STL):** Extensive use of STL containers (e.g., `std::vector`) and algorithms (e.g., `std::sort`).
*   **Exception Handling:** Implementing and using custom exception classes to handle various error conditions gracefully.
*   **File I/O and String Parsing:** Reading from and writing to files, and parsing string data using `ifstream`, `ofstream`, and `istringstream`.
*   **Dynamic Memory Management:** Using `new` and `delete` to manage the lifecycle of `Field` objects.

## How to Compile and Run

This project uses a `makefile` for easy compilation and execution.

1.  **Prerequisites:** You need to have `make` and `g++` installed.

2.  **Navigate to the project directory:**
    ```bash
    cd CSE241/data-catalog-parser
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
    This will execute `main.out`. The program will read `data.txt` and `commands.txt`, and write the output to `output.txt`.

5.  **Clean the build files:**
    ```bash
    make clean
    ```
    This will remove the executable and all object files.

## Link to Details

[PA5.pdf](https://github.com/emirgit/GTU-UNIVERSITYASSIGNMENTS/blob/main/CSE241/data-catalog-parser/PA5.pdf)