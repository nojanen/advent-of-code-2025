/*

Advent of Code 2025, day 4, part 1

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEST_FILE  "test.txt"
#define INPUT_FILE "input.txt"
#define DATA_FILE  INPUT_FILE

#define COLS 150
#define ROWS 150

typedef char table_t[ROWS][COLS];

int main() {
  table_t tbl;
  char in;
  int rows = 0;
  int cols = 0;
  int result = 0;

  FILE *file = fopen(DATA_FILE, "r");

  // Init table
  memset(tbl, '.', COLS * ROWS);

  // Read the data to offset (1,1) to get rid of a lot of bounbary checking
  while(fscanf(file, "%c", &in) >= 0) {
    if (in == '\n') {
      rows++;
      cols = 0;
      continue;
    }
    tbl[rows+1][cols+1] = in;
    cols++;
  }
  rows++;
  
  // Do simple check for each item's surroundings.
  // Note that the data starts coords (1,1).
  for(int y = 1; y < rows+1; y++) {
    for(int x = 1; x < cols+1; x++) {
      if (tbl[y][x] == '@') {
        int rolls = 0;
        if (tbl[y-1][x-1] == '@') rolls++;
        if (tbl[y-1][ x ] == '@') rolls++;
        if (tbl[y-1][x+1] == '@') rolls++;
        if (tbl[ y ][x-1] == '@') rolls++;
        if (tbl[ y ][x+1] == '@') rolls++;
        if (tbl[y+1][x-1] == '@') rolls++;
        if (tbl[y+1][ x ] == '@') rolls++;
        if (tbl[y+1][x+1] == '@') rolls++;

        if (rolls < 4) result++;
      }
    }
  }

  printf("Result is %d\n", result);
  DATA_FILE == TEST_FILE && result == 13 && printf("Result is correct\n");
  DATA_FILE == INPUT_FILE && result == 1437 && printf("Result is correct\n");

  return 0;
}