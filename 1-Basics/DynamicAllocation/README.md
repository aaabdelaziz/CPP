
# Dynamic Memory Allocation in C and C++

## Memory Allocation in C

C uses the functions `malloc()` and `calloc()` to allocate memory dynamically at runtime. To free the allocated memory, C uses the `free()` function.

## Memory Allocation in C++

C++ supports the same memory functions as C (`malloc()`, `calloc()`, and `free()`), but also introduces two powerful operators for dynamic memory management:

- `new` — for memory allocation
- `delete` — for memory deallocation

These operators provide a more convenient and safer approach to dynamic memory handling in C++.

## How `new` Works in C++

The `new` operator requests memory allocation on the **heap**. If sufficient memory is available:

- It initializes the memory
- Returns the address of the newly allocated and initialized memory to the pointer variable

## Difference Between `malloc()` and `new`

For a detailed comparison, refer to this article: [Difference Between `new` and `malloc()`](https://www.includehelp.com/cpp-tutorial/difference-between-new-and-malloc.aspx)

## Key Differences

| Feature                | `malloc()` (C)                        | `new` (C++)                          |
|------------------------|---------------------------------------|--------------------------------------|
| Type                   | Library function (`stdlib.h`)         | Operator                              |
| Language               | Primarily used in C                   | Used in C++                           |
| Object Initialization  | Does **not** call constructor         | Calls constructor                     |
| Return Type            | Returns `void*`                       | Returns exact data type               |
| Speed                  | Slower (function call overhead)       | Faster (operator level)               |
| Memory Allocation      | Manual                                | More intuitive and safer              |


## Additional Notes

- `malloc()` is a library function declared in `stdlib.h`. It was originally used in the C programming language to allocate memory for **N blocks** at runtime. However, it can also be used in C++.
- Whenever a program needs memory to be declared dynamically at runtime, this function can be utilized.

- `new` is an **operator** introduced in C++ for the same purpose—allocating memory for **N blocks** at runtime.

While both `malloc()` and `new` serve the same fundamental purpose, there are several key differences:

- `new` is an operator, whereas `malloc()` is a library function.
- `new` not only allocates memory but also calls the constructor for object initialization.
- `malloc()` only allocates memory and does **not** call any constructor.
- The return type of `new` is the exact data type requested, whereas `malloc()` returns a `void*`, requiring explicit typecasting.
- `new` is generally faster than `malloc()` because operators are typically faster than function calls.


## Extra Notes: `malloc()` vs. `calloc()` in C

C provides two standard functions for dynamic memory allocation at runtime:

- `malloc()` — Allocates a single block of memory of a specified size.
- `calloc()` — Allocates multiple blocks (an array) of memory and initializes all bytes to zero.

To deallocate memory, both should be paired with the `free()` function.

## Key Differences Between `malloc()` and `calloc()`:

| Feature            | `malloc()`                         | `calloc()`                                |
|--------------------|-------------------------------------|--------------------------------------------|
| Initialization     | Does **not** initialize memory      | Initializes allocated memory to **zero**   |
| Parameters         | Takes a single argument (total size)| Takes two arguments (number of elements, size of each) |
| Use Case           | When initialization isn't needed    | When zero-initialized memory is needed     |
| Syntax Example     | `int *arr = (int *)malloc(5 * sizeof(int));`             | `int *arr = (int *)calloc(5, sizeof(int));`                        |

> **Note**: While C++ supports both `malloc()` and `calloc()`, it is generally preferred to use `new` and `delete` in C++ as they integrate with constructors/destructors and offer safer, more idiomatic memory management.
