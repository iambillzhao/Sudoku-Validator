/*
 * Sudoku.c is a validator for Sudoku solutions of a 9 * 9 grid.
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

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include "Sudoku.h"

// The number of squares in a grid
#define SIZE 9

/**
 * Checks if the given Sudoku solution is valid and output the message.
 *
 * @param       none
 * @return      none
 **/
int main() {
  printf("\n|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
  printf("     Welcome to Sudoku Solution Validator, by Bill Zhao\n");
  printf("    Enter your solution to Sudoku.h within a grid of 9 * 9\n");
  printf("             Use \"gcc -pthread *.c\" to compile\n");
  printf("            Use \"CMakeLists.txt\" if using CLion\n");
  printf("||||||||||     Computing your Sudoku solution...   ||||||||||\n\n");

  parameters *data = (parameters *) malloc(sizeof(parameters));
  pthread_t tid[SIZE + 2]; // 11 threads total
  int id = 0;              // start tid is 0
  int count = 0;           // initialize count to 0

  // 2 threads to check rows & columns
  for (id = 0; id < 2; ++id) {
    int created = pthread_create(&tid[id], NULL, RC, (void *) id);
    if (created) exit(1);
  }

  // 9 threads to check each square
  for (int i = 0; i <= 6; i += 3) {
    for (int j = 0; j <= 6; j += 3) {
      (*data).row = i;
      (*data).column = j;
      int created = pthread_create(&tid[id++], NULL, SQ, (void *) data);
      if (created) exit(1);
    }
  }

  // check if return values are valid
  void *retVal;
  for (id = 0; id < SIZE + 2; id++) {
    pthread_join(tid[id], &retVal);
    count += (int)retVal;
  }

  // no all thread passed the test, prompt error
  if (count != SIZE + 2)
    printf("Your solution is wrong, please try again!");
  else // all tests passed, prompt success message
    printf("Congratulations, your solution is correct!");
  printf("\nThank you for using the Sudoku Solution Validator, bye!");
  pthread_exit(NULL);
}

/**
 * Checks if each row or each column is valid.
 *
 * @param *val  the pointer to the location
 * @return      none
 **/
void *RC(void *val) {
  int count = 0; // initialize count to 0

  for (int i = 0; i < SIZE; ++i) {
    for (int j = 1; j < SIZE + 1; ++j) {
      for (int k = 0; k < SIZE; ++k) {
        if (grid[i][k] == j) { // if value at grind[i][k] is j
                               // and the desired value is 0 or
                               // 1, increment count
          if ((int) val == 0 || (int) val == 1) {
            count++;
            break; // break out of the loop if found
          }
        }
      }
    }
  }

  if (count != 81) // if value of numbers is invalid, exit with -1
    pthread_exit((void *) -1);
  else
    pthread_exit((void *) 1); // otherwise, exit with 1
}

/**
 * Checks if each square in the Sudoku grid is valid.
 *
 * @param *val  the pointer to the location
 * @return      none
 **/
void *SQ(void *val) {
  parameters *data = (parameters *) malloc(sizeof(parameters));
  int count = 0; // initialize count to 0

  for (int i = 1; i < SIZE + 1; ++i) {
    for (int j = 0; j < (*data).row + 3; ++j) {
      for (int k = 0; k < (*data).column + 3; ++k) {
        if (grid[j][k] == i) {  // if value at grind[j][k] is i,
                                // define j and k to the next
                                // square, increment count
          j = (*data).row + 3;
          k = (*data).column + 3;
          count++;
        }
      }
    }
  }

  if (count != SIZE) // if not all square passed the test, exit with -1
    pthread_exit((void *) -1);
  else
    pthread_exit((void *) 1); // otherwise, exit with 1
}
