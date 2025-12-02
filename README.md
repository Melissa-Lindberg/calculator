# Calculator

A lightweight console-based calculator that performs basic and advanced arithmetic operations on two numbers. The utility is designed for simplicity, clarity, and ease of integration into other workflows.

## Features

* Addition
* Subtraction
* Multiplication
* Division
* Exponentiation
* Factorial

## Usage

Run the executable and follow the prompts to enter two numbers (or one number for unary operations such as factorial) and select the desired operation.

Example operations:

* `3 + 7`
* `12 / 4`
* `5 !`
* `2 ^ 10`

## Build Instructions

This project uses CMake for configuration and build orchestration.

```bash
cmake -S . -B build
cmake --build build
```

The compiled binary will be located in the `build` directory.

## Requirements

* C++17 or later
* CMake 3.15+
* A C++ compiler supported by your platform (GCC, Clang, MSVC, etc.)

## License

This project is licensed under the GNU general public license. See `LICENSE` for details.