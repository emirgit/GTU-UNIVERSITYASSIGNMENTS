# CSE241 - Problem Solving #3: Hot Dog Stand and Josephus Problem

## Description
This project consists of two C++ programs that demonstrate different programming concepts. The first program (`q1.cpp`) implements a `HotDogStand` class to manage hot dog sales, showcasing the use of static class members. The second program (`q2.cpp`) solves the classic Josephus problem using `std::vector` and iterators to simulate a suitor elimination process.

## Program Structure and Features

### `q1.cpp` - Hot Dog Stand Simulation
This program defines a `HotDogStand` class with the following features:
- **`ID`**: An integer to uniquely identify each hot dog stand.
- **`soldStand`**: An integer to keep track of the number of hot dogs sold by a specific stand.
- **`totalSold`**: A `static` integer member that keeps a running total of all hot dogs sold across all `HotDogStand` instances.
- **Constructors**: Default and parameterized constructors to initialize `ID` and `soldStand`.
- **`JustSold()`**: A method to increment both the individual stand's `soldStand` count and the global `totalSold` count.
- **`getNumSold()`**: Returns the number of hot dogs sold by a specific stand.
- **`getTotalSold()`**: A `static` method that returns the total number of hot dogs sold by all stands.

The `main` function demonstrates the creation of multiple `HotDogStand` objects, simulates sales, and prints the individual and total sales figures.

### `q2.cpp` - Josephus Problem Solver
This program implements a solution to the Josephus problem. Given `n` suitors arranged in a circle, every third suitor is eliminated until only two remain. The program uses a `std::vector` to represent the suitors and `std::vector` iterators to simulate the elimination process.

## Learning Objectives
- Understanding and implementing C++ classes and objects.
- Utilizing static members in C++ classes for shared data.
- Working with `std::vector` and iterators for dynamic data structures.
- Solving algorithmic problems like the Josephus problem.
- Basic input/output operations in C++.

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