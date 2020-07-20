# Sudoku Validator

A multi-threaded C program to test Sudoku solutions.

[Author: Bill Zhao](https://www.iambillzhao.com/)

## Program Usage

This program can process the given Sudoku solution
and determine if it is valid (1-9 each row/column/
square) using multi-Pthreads in the UNIX operating system
with the support of the C language.

Please input your Sudoku solution to `Sudoku.h` before
using this program.

## Included Files

- `Sudoku.c`: Pthreads computational functions with processing instructions

- `Sudoku.h`: A supporting file to `Sudoku.c` with the given solution to be
validated

## Rules and Instructions

You may find the rules of Sudoku here:
https://sudoku.com/how-to-play/sudoku-rules-for-complete-beginners/

## Dependencies

C, which could be installed with `Cygwin` and `GCC/Clang` on Windows, 
or use `brew install gcc` on macOS.
