
# CSE102 - Assignment #7: Text Analysis with Word Vectors

## Description

This project is an advanced C program designed for text analysis and string manipulation. The application processes a large text file (`input.txt`) to determine the frequency of user-specified words. A key feature of this program is its ability to handle words not found in the text by identifying the most semantically similar word from a dictionary file (`dictionary.txt`). This similarity is calculated using numeric word vector representations, demonstrating a practical application of vector space models in natural language processing. The program also filters out common words specified in an `ignore.txt` file.

## Program Structure and Features

The application operates as a command-line tool that takes user input and performs analysis based on a set of external data files.

*   **File-Based Data Processing:**
    *   **`dictionary.txt`:** Contains words and their corresponding high-dimensional floating-point vectors. The program parses this file to build an in-memory dictionary for similarity calculations.
    *   **`input.txt`:** The primary source text (e.g., an article, a novel) from which word frequencies are calculated.
    *   **`ignore.txt`:** A list of common words (stopwords) that are ignored during the text parsing phase.

*   **Core Functionality (User Interaction):**
    *   **Single Word Analysis:**
        *   If the user enters a single word, the program calculates and prints its exact frequency in `input.txt`.
        *   If the word is not found, it computes the **dissimilarity** (`|v_i - v_j|^2`) between the input word's vector and all vectors in the dictionary. It then identifies the closest match that meets a predefined similarity threshold. The frequency of this closest match is then displayed.
    *   **Multi-Word Analysis & Histogram Generation:**
        *   If the user enters multiple words, the program generates a histogram visualizing the frequency of each word.
        *   Exact matches are represented by `*` characters.
        *   Closest-match words (for inputs not found in the text) are represented by `+` characters.
        *   The histogram's scale is dynamically adjusted based on the maximum frequency to ensure the output is always well-formatted and fits within a 20-character limit.

*   **Custom String Utilities:**
    *   In adherence with assignment rules, the program avoids most standard `<string.h>` library functions. It utilizes a custom-built set of string manipulation functions (`f_strlen`, `f_strcp`, `f_strcat`, etc.) for all core string operations.

## Learning Objectives

*   **Advanced String Manipulation:** Mastering the parsing, tokenization, and manipulation of strings from files and user input with minimal reliance on standard libraries.
*   **Complex File I/O:** Efficiently reading and parsing multiple data files with different structures to build a cohesive data model in memory.
*   **Data Structures and Management:** Using 2D arrays and sentinel values to handle large collections of words and their associated data.
*   **Algorithmic Implementation:** Implementing a vector-based dissimilarity algorithm to quantify the semantic relationship between words.
*   **Modular Programming:** Structuring the codebase into separate header (`.h`) and implementation (`.c`) files, promoting code reusability and maintainability.
*   **Dynamic Console Output:** Designing and generating formatted, scaled, and data-driven output (the histogram) to present information clearly to the user.

## How to Compile and Run

The project includes a `Makefile` that automates the compilation and execution process.

1.  **Prerequisites:** You need `GCC` (GNU Compiler Collection) and `make` installed on your system.

2.  **Navigate to the project directory:**
    *(Ensure you are in the directory containing `main.c`, `util.c`, `util.h`, and the `Makefile`)*
    ```bash
    cd CSE102/text-analysis-with-word-vectors/src
    ```

3.  **Compile and Run using the `Makefile`:**
    *This single command will clean any previous builds, compile the source code into an executable named `test`, and run it. The program will then prompt you for input.*
    ```bash
    make
    ```

[Details](./hw7.pdf)