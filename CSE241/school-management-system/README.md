# CSE241 - Assignment #3: School Management System

## Description

This project is a command-line based School Management System implemented in C++. It provides functionalities to manage students and courses, including adding, deleting, and enrolling students in courses. The system is designed with a focus on manual dynamic memory management, using dynamic arrays to store and manage data.

## Program Structure and Features

*   **Object-Oriented Design:** The system is built around three main classes:
    *   `Student`: Represents a student with a name and an ID. Each student object maintains a dynamic array of pointers to the `Course` objects they are enrolled in.
    *   `Course`: Represents a course with a name and a code. Each course object maintains a dynamic array of pointers to the `Student` objects enrolled in it.
    *   `SchoolManagerSystem`: The main class that orchestrates the entire system. It holds dynamic arrays of pointers to all `Student` and `Course` objects and manages the main menu and user interactions.

*   **Dynamic Memory Management:**
    *   The project uses dynamically allocated arrays (`new` and `delete[]`) to store lists of students and courses, instead of `std::vector`.
    *   The capacity of these arrays automatically doubles when the number of elements exceeds the current capacity, preventing overflow.
    *   Destructors are implemented in each class to properly deallocate memory and prevent memory leaks.

*   **Interactive Menu System:**
    *   The user interacts with the system through a recursive menu function, `SchoolManagerSystem::menu()`.
    *   The menu guides the user through various options, such as adding a new student, selecting a course, or listing all students.
    *   Input validation is performed to ensure that the user's input is valid for the current menu.

## Learning Objectives

*   **Object-Oriented Programming (OOP):** Designing and implementing a system using classes and objects, including constructors, destructors, and member functions.
*   **Dynamic Memory Management:** Mastering the use of `new` and `delete[]` for manual memory allocation and deallocation of arrays.
*   **Pointers and References:** Using pointers to manage relationships between objects (e.g., a `Student` having a list of `Course` pointers).
*   **Data Structures:** Implementing and managing dynamic arrays, including resizing them as needed.
*   **Modular Programming:** Organizing code into separate header (`.h`) and implementation (`.cpp`) files for better readability and maintainability.

## How to Compile and Run

This project includes a `makefile` for easy compilation and execution.

1.  **Prerequisites:** You need to have `make` and `g++` installed.

2.  **Navigate to the project directory:**
    ```bash
    cd CSE241/school-management-system
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
    This will execute `main.out` and start the interactive menu.

5.  **Clean the build files:**
    ```bash
    make clean
    ```
    This will remove the executable and all object files.

## Link to Details

[PA3.pdf](https://github.com/emirgit/GTU-UNIVERSITYASSIGNMENTS/blob/main/CSE241/school-management-system/PA3.pdf)