# 🌊 get_next_line - 42 Project 🌊

[![Language](https://img.shields.io/badge/Language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))

## 📝 Table of Contents
- [About the Project](#about-the-project)
- [Features](#features)
- [Requirements](#requirements)
- [Design Suggestions](#design-suggestions)
- [Code Structure](#code-structure)
- [Installation](#installation)
- [Examples](#examples)

---

## 🎯 About the Project

`42_get_next_line` is a custom implementation of a line-by-line file reading function. Created as part of the 42 School curriculum, this project aims to provide a deep understanding of file descriptors, memory management, and buffer handling in C. It is designed to retrieve one line at a time from a file or standard input, making it suitable for file parsing and interactive input.

## ✨ Features

- **Efficient Line Reading:** Reads files line-by-line to minimize memory usage and improve performance.
- **Buffer Management:** Uses a custom buffer to handle partial line reads and preserve data between function calls.
- **File Descriptor Management:** Supports reading from multiple file descriptors simultaneously.
- **Memory Safety:** Carefully handles memory allocation and deallocation to prevent leaks.

## ✅ Requirements

The main requirements for the 42_get_next_line project typically include:

- Implement a function `get_next_line` that reads and returns a line from a file descriptor.
- The function should return the line read, or `NULL` on error or end of file.
- Handle both `\n` (new line) and end-of-file conditions properly.
- Memory management must be implemented carefully to avoid leaks.
- Must be implemented in C, adhering to the 42 coding standards.
- Should support different buffer sizes, configurable with the `BUFFER_SIZE` macro.

## 💡 Design Suggestions

When approaching this project, consider the following design suggestions:

- **Modular Structure:** Separate the functionality into smaller functions to handle tasks like buffer handling, memory management, and line retrieval.
- **Efficient Buffer Management:** Use the buffer to minimize the number of system calls and only read what is necessary to retrieve each line.
- **Edge Case Handling:** Pay special attention to edge cases, such as an empty file, lines with no newline character, or very large files.
- **Readability and Maintainability:** Write clear, well-documented code that is easy to debug and modify in the future.
- **Test Coverage:** Test with different files, buffer sizes, and file descriptors to ensure consistent performance.

## 📂 Code Structure

| File                  | Description                                       |
|-----------------------|---------------------------------------------------|
| `get_next_line.c`     | Main function to retrieve the next line           |
| `get_next_line_utils.c`| Helper functions for buffer management            |
| `Makefile`            | Automated build script                            |

## 📥 Installation

To include `42_get_next_line` in your project, follow these steps:

```bash
git clone https://github.com/HoudaChairi/42_get_next_line.git

```
```
cd 42_get_next_line
```
```
gcc get_next_line.c get_next_line_utils.c -o get_next_line
```

## 📌 Examples
Here's how `get_next_line` behaves when reading from a file:

Assume the content of test.txt:

Hello, world!

This is a test file.

End of the file.
