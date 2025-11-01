# CSE241 - Problem Solving #5: Polynomial Class

## Description
This project implements a C++ `Polynomial` class that supports various polynomial operations, including construction, copy construction, assignment, addition, subtraction, multiplication, and evaluation. The class uses dynamic memory allocation to handle polynomials of varying degrees.

## Program Structure and Features

The `Polynomial` class is designed to perform essential polynomial arithmetic. Key features include:
- **Dynamic Memory Allocation**: The polynomial coefficients are stored in a dynamically allocated array, allowing for flexibility in the degree of the polynomial.
- **Constructors**: The class provides a default constructor, a copy constructor, and a constructor that takes an array of coefficients and the size of the array.
- **Destructor**: A destructor is implemented to deallocate the dynamic memory, preventing memory leaks.
- **Operator Overloading**: The following operators are overloaded to provide an intuitive interface for polynomial manipulation:
    - `[]`: Subscript operator to access the coefficient of a specific degree.
    - `=`: Assignment operator for deep copying.
    - `+`: Addition operator.
    - `-`: Subtraction operator.
    - `*`: Multiplication operator.
- **`evaluate` function**: A friend function to evaluate the polynomial for a given value of `x`.
- **`mySize` method**: Returns the size of the polynomial (degree + 1).

The `main` function provides a comprehensive test suite that demonstrates the creation of `Polynomial` objects and the use of the overloaded operators and the `evaluate` function.

## Learning Objectives
- Advanced C++ class design, including constructors, destructors, and operator overloading.
- Dynamic memory management in C++ using `new` and `delete`.
- Implementation of deep copy semantics for classes with dynamic memory.
- Overloading arithmetic and subscript operators for intuitive class usage.
- Understanding and using `friend` functions.

## How to Compile and Run

To compile and run the program:
```bash
g++ q1.cpp -o q1
./q1
```

## Output

![Output](q1.png)

## Link to Details

[PS5.pdf](https://github.com/emirgit/GTU-UNIVERSITYASSIGNMENTS/blob/main/CSE241/problem-solving/problem-solving-5/PS5.pdf)
