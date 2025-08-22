# CSE102 - Homework #12: Linked List Serialization with Heterogeneous Data

## Description

This project demonstrates advanced data handling in C by creating a linked list composed of heterogeneous data types. The program dynamically generates a linked list containing four different types of `Asset` structures, serializes this in-memory data into a raw binary file, and then deserializes the binary data to perfectly reconstruct the original linked list. The core challenge lies in using a generic `Node` structure with a `void*` pointer to store different asset types and rebuilding the list from the binary file without any explicit ordering hints or metadata tricks.

## Program Structure and Features

The application is architected around a set of distinct functions, each responsible for a critical part of the data lifecycle: generation, serialization, and deserialization.

*   **Part 1: `fillLinkedList()` - Dynamic and Random List Generation**
    *   **Functionality:** Creates a linked list of a random length (between 10 and 20 nodes). Each node in the list contains one of four different `Asset` struct types, also chosen randomly.
    *   **Technical Implementation:**
        *   A generic `Node` struct (`void* data`, `struct Node* next`) is used as the backbone of the linked list.
        *   For each node, the function dynamically allocates memory for one of the four specific asset types (`Asset1`, `Asset2`, `Asset3`, `Asset4`) using `malloc`.
        *   The `void* data` pointer of the `Node` is then assigned the address of the newly created asset struct. This allows the single linked list structure to hold multiple, differently-sized data types.

*   **Part 2: `serializeLinkedList()` - Writing to a Binary File**
    *   **Functionality:** Traverses the entire in-memory linked list and writes its contents into a single binary file named `linkedlist.bin`.
    *   **Technical Implementation:**
        *   The file is opened in binary write mode (`"wb"`).
        *   A specific serialization strategy is used to enable reconstruction: for each node, the function first writes the fixed-length `type` string (20 bytes) to the file. Immediately after, it writes the complete binary data of the corresponding asset struct using `fwrite`.
        *   This process is repeated for every node, creating a continuous stream of `[type_string][asset_data]` blocks in the binary file.

*   **Part 3: `deserializeLinkedList()` - Reconstructing from a Binary File**
    *   **Functionality:** Reads the `linkedlist.bin` file and perfectly reconstructs the original, randomly generated linked list in memory.
    *   **Technical Implementation:**
        *   The file is opened in binary read mode (`"rb"`).
        *   The function enters a loop, first attempting to read the 20-byte `type` string using `fread`.
        *   It then uses `strcmp` to identify which of the four asset types this string corresponds to.
        *   Based on the identified type, it dynamically allocates the correct amount of memory for that specific asset struct (`sizeof(Asset1)`, `sizeof(Asset2)`, etc.).
        *   It then reads the subsequent block of binary data from the file directly into this newly allocated memory.
        *   A new `Node` is created, its `void* data` pointer is set to the reconstructed asset, and the node is appended to the tail of the new linked list.
        *   This process continues until the end of the file is reached.

## Learning Objectives

*   **Generic Data Structures with `void*`:** Mastering the use of void pointers to create flexible, heterogeneous data structures like a linked list that can store any data type.
*   **Binary File I/O:** Gaining proficiency in reading from and writing to binary files using `fopen`, `fread`, and `fwrite`, which is essential for performance and data integrity.
*   **Serialization and Deserialization:** Understanding and implementing the concepts of serialization (converting in-memory data structures to a storable format) and deserialization (reconstructing them).
*   **Type Casting and Memory Management:** Extensively using type casting to correctly interpret the data pointed to by `void*` and meticulously managing memory with `malloc` and `free` to prevent leaks.
*   **Algorithmic Problem-Solving:** Devising a robust strategy to serialize and deserialize data without relying on metadata or "tricks," ensuring the reconstruction is based solely on the raw data stream.

## How to Compile and Run

The project includes a `Makefile` that automates the entire process.

1.  **Prerequisites:** You need `GCC` (GNU Compiler Collection) and `make` installed.

2.  **Navigate to the project directory.**

3.  **Compile and Run using the `Makefile`:**
    *This single command will clean previous builds, compile the source files, and run the program. The output will show the initially generated list, a confirmation of serialization, and the final reconstructed list.*
    ```bash
    make
    ```

[Details](https://github.com/emirgit/GTU-UNIVERSITYASSIGNMENTS/)