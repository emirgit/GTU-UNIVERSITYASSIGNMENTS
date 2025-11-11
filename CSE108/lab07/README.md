# CSE108 - Lab 7: Loop, Functions, File Operations

This lab explores advanced C programming concepts including string manipulation, wildcard pattern matching, and array processing with specific constraints on loop usage and variable declaration. The lab is divided into three distinct parts, each implemented within a single `main.c` file.

## Program Structure and Features

The `main.c` file contains the implementations for all three parts of the lab, with each part encapsulated in its own function.

### `part1` Function: Empty String Operations

*   **Functionality:** This function takes a string `s` consisting of lowercase letters. It calculates the minimum number of operations required to transform the string into an empty string. An operation involves removing any substring composed of identical consecutive characters.
*   **Technical Implementation:** The function iterates through the string, identifying consecutive runs of identical characters. For each run, it calculates `count / 3` and adds it to a total, effectively counting operations based on groups of three identical characters.

### `part2` Function (calling `filter`): String Filtering with Wildcards

*   **Functionality:** This part demonstrates string filtering. It takes an input string containing words separated by spaces and a `rule` string. The `rule` string can include literal characters, `*` (intended to match any sequence of characters), and `?` (intended to match any single character). Words from the input string that match the rule are intended to be filtered out.
*   **Technical Implementation:** The `filter` function tokenizes the input string by spaces. For each word, it attempts to match it against the `rule`. The current implementation uses `strstr` for substring checks and includes logic for `*` and `?`, though the full wildcard pattern matching as typically understood might not be completely implemented. Words that do not match the rule are printed.

### `part3` Function (calling `foo_min_max`): Min/Max in Array

*   **Functionality:** This part focuses on finding the minimum and maximum elements within an integer array. The user first specifies the number of items in the array and then enters the elements.
*   **Technical Implementation:** The `foo_min_max` function takes an integer array `arr` and its size `n`. It initializes `min` and `max` with the first element of the array. It then iterates through the rest of the array using a `while` loop to update `min` and `max` if a smaller or larger element is found. This implementation adheres to the constraint of not using any extra variables beyond `min`, `max`, and the loop counter.

## Learning Objectives

*   Implementing string manipulation algorithms, including character counting and substring processing.
*   Developing functions for string tokenization and basic pattern matching.
*   Working with arrays to find statistical properties (minimum, maximum) under specific algorithmic constraints.
*   Understanding and applying loop structures (`while` loops) for array traversal.
*   Managing memory and data flow between functions.

## How to Compile and Run

1.  **Navigate to the source directory:**
    ```bash
    cd CSE108/lab07/src
    ```

2.  **Compile the source code:**
    ```bash
    gcc -o main main.c
    ```

3.  **Run the executable:**
    ```bash
    ./main
    ```

[Details](./lab7.pdf)
