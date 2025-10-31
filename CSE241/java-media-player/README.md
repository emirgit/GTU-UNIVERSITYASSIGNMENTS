# CSE241 - Assignment #6: Java Media Player with Observer Pattern

## Description

This project is a Java-based media player application that demonstrates the implementation of the Observer design pattern. The application manages a dataset of various media types (Audio, Video, Image, Text) and allows `Player` and `Viewer` objects to observe and react to changes in the dataset.

## Program Structure and Features

*   **Observer Design Pattern:**
    *   **`Subject` (Interface):** Defines the methods for registering, unregistering, and notifying observers.
    *   **`Dataset` (Concrete Subject):** Implements the `Subject` interface and maintains a list of `Media` objects. It notifies registered observers when a media object is added or removed.
    *   **`Observer` (Interface):** Defines the `update` method that is called by the subject when a change occurs.
    *   **`Player` and `Viewer` (Concrete Observers):** Implement the `Observer` interface. `Player` objects observe `Playable` media, while `Viewer` objects observe `Non_playable` media.

*   **Media Hierarchy:**
    *   **`Media` (Abstract Base Class):** A base class for all media types, containing common properties like `name` and `info`.
    *   **Interfaces for Categorization:**
        *   `Playable`: For media that can be played (e.g., `Audio`, `Video`).
        *   `Non_playable`: For media that can be viewed (e.g., `Image`, `Text`).
        *   `Visual`: For media with a visual component (e.g., `Video`, `Image`).
        *   `Non_visual`: For media without a visual component (e.g., `Audio`, `Text`).
    *   **Concrete Media Classes:**
        *   `Audio`: Extends `Media`, implements `Playable` and `Non_visual`.
        *   `Video`: Extends `Media`, implements `Playable` and `Visual`.
        *   `Image`: Extends `Media`, implements `Non_playable` and `Visual`.
        *   `Text`: Extends `Media`, implements `Non_playable` and `Non_visual`.

*   **Player and Viewer Functionality:**
    *   `Player` objects maintain a playlist of `Playable` items and can play, navigate to the next/previous item of a specific type, and show the current playlist.
    *   `Viewer` objects maintain a view list of `Non_playable` items and can view, navigate to the next/previous item of a specific type, and show the current view list.

## Learning Objectives

*   **Design Patterns:** Implementing the Observer design pattern to create a decoupled system where subjects and observers can interact without having tight dependencies.
*   **Object-Oriented Programming (OOP) in Java:** Using abstract classes, interfaces, and inheritance to create a flexible and extensible class hierarchy.
*   **Polymorphism:** Leveraging polymorphism to treat different media types uniformly through their common base class and interfaces.
*   **Java Collections Framework:** Using `ArrayList` to manage lists of media objects and observers.

## How to Compile and Run

This project uses a `makefile` for easy compilation and execution.

1.  **Prerequisites:** You need to have a Java Development Kit (JDK) and `make` installed.

2.  **Navigate to the project directory:**
    ```bash
    cd CSE241/java-media-player
    ```

3.  **Compile the source code:**
    ```bash
    make
    ```
    This will compile all the `.java` files.

4.  **Run the program:**
    ```bash
    make run
    ```
    This will execute the `main` method in the `Main` class.

5.  **Clean the build files:**
    ```bash
    make clean
    ```
    This will remove all the compiled `.class` files.

## Link to Details

[PA6.pdf](https://github.com/emirgit/GTU-UNIVERSITYASSIGNMENTS/blob/main/CSE241/java-media-player/PA6.pdf)