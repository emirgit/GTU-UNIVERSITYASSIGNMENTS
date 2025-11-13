# CSE108 - Lab #12: Bank Customer Priority Queue

## Description

This project implements a priority queue system for a bank's customer management using a doubly linked list in C. The system allows for the creation, storage, and manipulation of customer data, prioritizing customers based on predefined categories. All data is persistently stored in a text file.

## Program Structure and Features

The program is built around a `Customer` struct and a doubly linked list that functions as a priority queue.

*   **`Customer` Struct:**
    *   `name` (char array)
    *   `age` (int)
    *   `priority_group_name` (char array)
    *   `priority_level` (int)
    *   `prev` and `next` pointers for the doubly linked list.

*   **Priority Queue Logic:**
    The program maintains a sorted list of customers based on their priority level. The levels are:
    *   **VIP:** Level 4 (Highest)
    *   **OD (Old or Disabled):** Level 3
    *   **VETERAN:** Level 2
    *   **NORMAL:** Level 1 (Lowest)

*   **Core Functions:**
    *   **`insert_Customer`:** Adds a new customer to the list, inserting them in the correct position according to their priority level.
    *   **`remove_Customer`:** Searches for and removes a customer from the list by name.
    *   **`display_Customers`:** Traverses the list and prints the details of all customers in order of priority.
    *   **`search_Customer`:** A recursive function to find a customer by name and display their details.
    *   **`changePriority`:** Modifies the priority level of an existing customer and repositions them in the queue.
    *   **`print_file`:** Writes the current state of the customer queue to the `customer.txt` file, ensuring data persistence.

## Learning Objectives

*   Implementing a priority queue using a doubly linked list.
*   Managing dynamic data structures in C.
*   Using `struct` to model complex data.
*   Performing file I/O operations for data persistence (`fopen`, `fprintf`, `fclose`).
*   Implementing recursive functions for searching.
*   Handling dynamic memory allocation and pointers.

## How to Compile and Run

1.  **Navigate to the source directory:**
    ```bash
    cd CSE108/lab12/src
    ```

2.  **Compile the source code using GCC:**
    ```bash
    gcc main.c -o bank_system
    ```

3.  **Run the executable:**
    ```bash
    ./bank_system
    ```

## Output Example

Here are examples of the program's output:

![Output Example 1](./src/output1-1.png)
![Output Example 2](./src/output1-2.png)
![Output Example 3](./src/output1-3.png)

[Details](./lab12.pdf)
