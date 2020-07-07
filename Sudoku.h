/*
 * Sudoku.h is a validator for Sudoku solutions of a 9 * 9 grid.
 *          Supplemental to Sudoku.c and must be compiled together.
 *          This program can process the given Sudoku solution
 *          and determine if it is valid (1-9 each row/column/
 *          square) using Pthreads in the UNIX operating system
 *          with the support of the C language.
 *          Please input your Sudoku solution to Sudoku.h before
 *          using this program. You may find the rules here:
 *          https://sudoku.com/how-to-play/sudoku-rules-for-complete-beginners/
 * 
 * @author Bill Zhao
 * @date 04/28/2020 7:11pm
 */

#ifndef SUDOKU_H
#define SUDOKU_H

#include <pthread.h>

// structure for passing data to threads
typedef struct {
  int row;
  int column;
} parameters;

// solution to the Sudoku problem
// ENTER YOUR SOLUTION HERE
int grid[9][9] = {
    {6, 2, 4, 5, 3, 9, 1, 8, 7},
    {5, 1, 9, 7, 2, 8, 6, 3, 4},
    {8, 3, 7, 6, 1, 4, 2, 9, 5},
    {1, 4, 3, 8, 6, 5, 7, 2, 9},
    {9, 5, 8, 2, 4, 7, 3, 6, 1},
    {7, 6, 2, 3, 9, 1, 4, 5, 8},
    {3, 7, 1, 9, 5, 6, 8, 4, 2},
    {4, 9, 6, 1, 8, 2, 5, 7, 3},
    {2, 8, 5, 4, 7, 3, 9, 1, 6}
};

//// A messed-up grid for debugging
//int grid[9][9] = {
//    {6, 2, 4, 5, 3, 9, 1, 8, 7},
//    {5, 0, 9, 7, 2, 8, 6, 3, 4},
//    {8, 3, 7, 6, 1, 4, 2, 9, 5},
//    {1, 4, 3, 6, 6, 5, 7, 2, 9},
//    {9, 5, 8, 2, 4, 7, 3, 6, 1},
//    {7, 6, 2, 3, 9, 1, 4, 5, 8},
//    {3, 7, 1, 9, 5, 6, 8, 2, 9},
//    {4, 9, 6, 1, 8, 2, 5, 7, 3},
//    {2, 8, 5, 4, 7, 3, 9, 1, 0}
//};

// Checks row/column
void *RC(void *val);

// Checks square
void *SQ(void *val);

#endif
