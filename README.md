# Maze Solver Using Backtracking in C++

This project was originally developed as a course project for the Data Structures and Algorithms class. It implements a console-based maze solver using a custom stack data structure and a backtracking approach.

The program reads a maze from `Harita.txt`, starts from a defined position, and searches for the exit. When it reaches a dead end, it returns to a previous position by using the stack structure.

## Concepts Used

- C++ classes and header/source file organization
- Custom stack implementation using templates
- File reading
- Backtracking algorithm
- Console-based visualization

## Project Structure

```text
include/
  Konum.hpp
  Labirent.hpp
  Stack.hpp

src/
  Konum.cpp
  Labirent.cpp
  Test.cpp

Harita.txt
makefile
```

## How to Run

The project was tested on Windows using MSYS2/MinGW-w64. It can be compiled with mingw32-make and run with mingw32-make run.