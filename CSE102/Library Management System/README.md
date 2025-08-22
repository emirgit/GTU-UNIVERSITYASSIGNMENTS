# CSE102 - Homework #10: Library Management System with Linked Lists

## Description

This project is a complete library book management system developed in C. The core of the application is built using **singly linked lists** to manage dynamic collections of books and students. The system features robust data persistence, reading all initial data from `books.txt` and `students.txt` at startup and saving any modifications back to these files in real-time. It provides a full-featured, menu-driven interface for managing the library's inventory, including full CRUD (Create, Read, Update, Delete) operations, advanced filtering and sorting, and a mechanism for borrowing and returning books.

## Program Structure and Features

The application's architecture is centered around two primary data structures, `Book` and `Student`, each managed as a separate global linked list.

*   **Core Data Structures:**
    *   **`Book` Struct:** A node in a linked list containing the book's ISBN, title, author, publication year, and a `reserved_status` flag.
    *   **`Student` Struct:** A node in a linked list containing the student's name, ID, and an array of borrowed book ISBNs.

*   **Data Persistence with File I/O:**
    *   The system achieves persistence by reading the contents of `books.txt` and `students.txt` upon launch, dynamically building the `Book` and `Student` linked lists in memory.
    *   Every operation that modifies data (add, delete, update, borrow, return) immediately triggers a function to save the entire current state of the linked list back to the corresponding text file, ensuring no data is lost between sessions.

*   **Book Management (CRUD):**
    *   **Add Book:** Dynamically allocates and adds a new `Book` node to the list. Supports both **FIFO** (add to tail) and **LIFO** (add to head) insertion methods based on user choice.
    *   **Delete Book:** Searches for a book by its unique ISBN and removes the corresponding node from the linked list, freeing its memory.
    *   **Update Book:** Finds a book by ISBN and allows the user to modify its title, author, or publication year.

*   **Advanced Query and Organization:**
    *   **Filter and Sort:** A powerful feature that first filters the entire book collection by a chosen criterion (author or publication year) and then sorts the filtered results. It uses **Selection Sort** for string-based sorting (title, author) and **Insertion Sort** for integer-based sorting (publication year).
    *   **Search Books:** Allows the user to perform a targeted search for books by ISBN, author, or title, displaying all matching entries.
    *   **Reverse List:** Traverses the existing book list and displays its contents in reverse order without permanently modifying the original list structure.

*   **Circulation Management:**
    *   **Borrow and Return Books:** Allows for borrowing and returning a book by its ISBN. The function toggles the `reserved_status` flag in the book's node (1 for borrowed, 0 for available) to manage its availability.

## Learning Objectives

*   **Linked List Mastery:** Demonstrating a deep understanding of linked lists, including node creation, traversal, searching, and memory management (`malloc`, `free`).
*   **Advanced Insertion Techniques:** Implementing both FIFO (tail-end insertion) and LIFO (head-end insertion) for adding new nodes to a linked list.
*   **Data Persistence and File I/O:** Mastering reading from and writing to formatted text files to load and save the state of a dynamic data structure.
*   **Data Structures and Algorithms:** Applying classic sorting algorithms (Selection Sort, Insertion Sort) to data stored within a linked list structure.
*   **Modular Programming:** Structuring a complex application with header files (`.h`) and implementation files (`.c`) to manage globals, function prototypes, and logic cleanly.
*   **Building a Full-Scale Application:** Developing a complete, interactive, and robust console application that simulates a real-world system.

## How to Compile and Run

The project includes a `Makefile` that handles the compilation and execution of the program.

1.  **Prerequisites:** You need to have `GCC` (GNU Compiler Collection) and `make` installed.

2.  **Navigate to the project directory.**
    *(Ensure you are in the directory containing `main.c`, `util.c`, `util.h`, and the `Makefile`)*

3.  **Compile and Run using the `Makefile`:**
    *This single command will clean previous builds, compile the source files, and launch the library management menu.*
    ```bash
    make
    ```
    
[Details](https://github.com/emirgit/GTU-UNIVERSITYASSIGNMENTS/)