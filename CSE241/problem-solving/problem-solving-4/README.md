# CSE241 - Problem Solving #4: Vector2D and MyInteger Classes

## Description
This project features two C++ programs demonstrating advanced class functionalities: operator overloading and friend functions. The first program (`q1.cpp`) defines a `Vector2D` class with an overloaded multiplication operator for dot product calculation. The second program (`q2.cpp`) introduces a `MyInteger` class that allows digit access via an overloaded subscript operator.

## Program Structure and Features

### `q1.cpp` - Vector2D Class with Operator Overloading
This program defines a `Vector2D` class to represent two-dimensional vectors. Key features include:
- **Private Members**: `x` and `y` integers to store vector components.
- **Constructors**: Default constructor initializes `x` and `y` to 0; a parameterized constructor sets `x` and `y` to specified values.
- **Accessor Methods**: `GetX()` and `GetY()` to retrieve the `x` and `y` components, respectively.
- **Mutator Methods**: `setX()` and `setY()` to modify the `x` and `y` components.
- **Operator Overloading**: The multiplication operator (`*`) is overloaded as a `friend` function to compute the dot product of two `Vector2D` objects.

The `main` function demonstrates the creation of `Vector2D` objects and the usage of the overloaded `*` operator to calculate dot products.

### `q2.cpp` - MyInteger Class with Subscript Operator Overloading
This program defines a `MyInteger` class that encapsulates an integer and provides a way to access its individual digits. Key features include:
- **Private Member**: An integer `x` to store the number.
- **Constructors**: Default constructor initializes `x` to 0; a parameterized constructor sets `x` to a specified value.
- **Accessor Method**: `GetInt()` to retrieve the encapsulated integer.
- **Mutator Method**: `SetInt()` to modify the encapsulated integer.
- **Operator Overloading**: The subscript operator (`[]`) is overloaded to allow access to individual digits of the integer. For example, `num[0]` returns the least significant digit, `num[1]` the next, and so on. It also includes error handling for illegal index values.

The `main` function demonstrates the creation of a `MyInteger` object and accessing its digits using the overloaded `[]` operator, including a test for an illegal index.

## Learning Objectives
- Deepening understanding of C++ classes, objects, and encapsulation.
- Mastering operator overloading for enhanced class functionality.
- Utilizing `friend` functions for specific access permissions.
- Implementing custom data access mechanisms using the subscript operator.
- Handling edge cases and error conditions in class methods.

## How to Compile and Run

To compile and run `q1.cpp`:
```bash
g++ q1.cpp -o q1
./q1
```

### Output

![Question 1 Output](q1.png)

To compile and run `q2.cpp`:
```bash
g++ q2.cpp -o q2
./q2
```

### Output

![Question 2 Output](q2.png)