# CSE102 - Assignment #6: Inventory Management System

## Description

This project is a sophisticated inventory management system designed for a supermarket with multiple branches. Developed in C, this application demonstrates practical experience with a wide range of core programming concepts, including **functions, multi-dimensional arrays, pointers, advanced file I/O, and data manipulation**. The system operates on two external comma-separated text files, `products.txt` and `stocks.txt`, to manage product information and branch-specific stock levels. It provides a menu-driven interface for an operator to perform complex CRUD (Create, Read, Update, Delete) operations, run queries, and generate reports.

## Program Structure and Features

The application is a robust, menu-driven command-line tool that allows for comprehensive management of product and stock data.

*   **Part 1: Main Menu**
    *   A centralized, user-friendly main menu that navigates to the system's core functionalities: File Operations, Product Queries, Stock Status Checks, Brand Control, and Report Exporting.

*   **Part 2: File Operations (CRUD)**
    *   A dedicated submenu for all file manipulation tasks, providing full control over the inventory database.
    *   **Product Management:**
        *   **Add:** Appends a new product to `products.txt` with auto-incrementing `pID`.
        *   **Delete:** Removes a product by `pID` and re-orders subsequent `pID`s.
        *   **Update:** Modifies a specific feature (e.g., price, name) of an existing product.
        *   **Add Feature:** Dynamically adds a new feature column to all existing products in `products.txt`, initializing new values to "NONE".
    *   **Stock Management:**
        *   **Add:** Appends a new stock entry to `stocks.txt` with auto-incrementing `sID`.
        *   **Delete:** Removes a stock record by `sID` and re-orders subsequent `sID`s.
        *   **Update:** Modifies a feature (e.g., current stock) of an existing stock entry.

*   **Part 3: Product Search and Filtering**
    *   **List All:** Displays all products from `products.txt` in a formatted table.
    *   **Advanced Filtering:** Allows the user to filter products based on multiple criteria (brand, type, price, etc.) in a single query. The program stores only the filtered results in memory, as required.

*   **Part 4: Stock Status Queries**
    *   Provides multiple ways to check stock levels for different branches.
    *   **Query by Product:** Checks the stock of a specific product (`pID`) in a given branch.
    *   **Query by Branch:** Lists all products and their current stock for a specified branch.
    *   **Out-of-Stock:** Identifies and lists all products that are out of stock in a specific branch.

*   **Part 5 & 6: Brand Stock Control and Reporting**
    *   **Brand Control:** Gathers and displays all products of a specific brand, storing their `pID`, `price`, and `current_stock` values from all branches into a 2D array.
    *   **Stock Report Generation:** Processes the 2D array from the brand control step to calculate statistics for each unique product. It then exports a formatted, comma-separated report to `report.txt`, detailing each product's `pID`, minimum, maximum, and median stock levels across all branches.

## Learning Objectives

*   **Advanced File I/O:** Mastering file read, write, and append operations (`fopen`, `fgets`, `fscanf`, `fprintf`) for persistent data storage and manipulation.
*   **Data Structures in C:** Effectively using single and multi-dimensional arrays to store, process, and manage complex datasets in memory.
*   **Pointers and Memory Management:** Using pointers for efficient data manipulation, particularly for passing array data and updating variables across functions.
*   **Modular Programming:** Decomposing a large, complex application into a well-structured system of header files (`.h`) and implementation files (`.c`) with clear, reusable functions.
*   **Algorithmic Thinking:** Designing and implementing algorithms for data filtering, sorting (Insertion Sort), searching, and statistical calculations (median).
*   **Building Robust Applications:** Creating a comprehensive, menu-driven application with clear user prompts, input validation, and logical workflow.

## How to Compile and Run

The project is structured with a `Makefile` for easy compilation of all necessary source files (`main.c` and `util.c`).

1.  **Prerequisites:** You need to have `GCC` (GNU Compiler Collection) and `make` installed.

2.  **Navigate to the project directory:**
    *(Ensure you are in the directory containing `main.c`, `util.c`, `util.h`, and the `Makefile`)*

3.  **Compile and Run using the `Makefile`:**
    *This single command will clean previous builds, compile the source files into an executable named `test`, and run the program.*
    ```bash
    make
    ```

[Details](https://github.com/emirgit/GTU-UNIVERSITYASSIGNMENTS/blob/main/CSE102/Inventory%20Management%20System/CSE%20102%20-%20HW6.pdf)