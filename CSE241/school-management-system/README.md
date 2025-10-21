# School Management System in C++

This project is a command-line based School Management System implemented in C++. It provides functionalities to manage students and courses, including adding, deleting, and enrolling students in courses. The system is designed with a focus on manual dynamic memory management, using dynamic arrays to store and manage data.

## Project Overview

The system is operated through an interactive menu in the console. Users can navigate through different options to perform various actions. The core functionalities are encapsulated within three main classes: `SchoolManagerSystem`, `Student`, and `Course`. All classes and functions are organized within the `PA3` namespace.

## Core Data Structures

- **`Student`**: Represents a student with a name and an ID. Each student object maintains a dynamic array of pointers to the `Course` objects they are enrolled in.

- **`Course`**: Represents a course with a name and a code. Each course object maintains a dynamic array of pointers to the `Student` objects enrolled in it.

- **`SchoolManagerSystem`**: The main class that orchestrates the entire system. It holds dynamic arrays of pointers to all `Student` and `Course` objects. It also manages the main menu and user interactions.

## Implementation Details

### Dynamic Memory Management

A key aspect of this project is the manual management of dynamic memory. Instead of using `std::vector`, the project uses dynamically allocated arrays (`new` and `delete[]`) to store lists of students and courses. The capacity of these arrays is automatically doubled when the number of elements exceeds the current capacity. Destructors are implemented in each class to properly deallocate memory and prevent memory leaks.

### Menu System

The user interacts with the system through a recursive menu function, `SchoolManagerSystem::menu()`. The menu is designed to guide the user through various options, such as adding a new student, selecting a course, or listing all students. User input is handled by the `checkInput` function, which ensures that the input is valid for the current menu.

## Code Example

Here is the `main.cpp` file, which serves as the entry point for the program:

```cpp
#include "SchoolManagerSystem.h"

using namespace PA3;

int main(){
    SchoolManagerSystem system;
    string userInput;
    system.menu(1, userInput);



    return (0);
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

    This will execute `main.out`, starting the interactive menu.

3.  **Clean the directory:**

    ```bash
    make clean
    ```

    This command will remove the executable and all object files (`.o`).
