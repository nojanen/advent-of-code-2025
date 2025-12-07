/*

Advent of Code 2025, day 6, part 1

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEST_FILE  "test.txt"
#define INPUT_FILE "input.txt"
#define DATA_FILE  INPUT_FILE

#define COLS 1000
#define ROWS 5

#define ADD_DIGIT(value, ones) (value * 10 + (ones - '0'))

typedef unsigned long uint64;
typedef int table_t[ROWS][COLS];

int main() {

  table_t tbl;
  char chr;
  int cols = 0;
  int rows = 0;
  uint64 result = 0;

  FILE *file = fopen(DATA_FILE, "r");

  memset(tbl, 0, ROWS * COLS * sizeof(int));

  // Read input one char at time
  while (fscanf(file, "%c", &chr) >= 1) {
 
    // Number read, skip whitespaces
    if (chr == ' ') {
      while (chr == ' ' && fscanf(file, "%c", &chr) > 0) {}
      if (tbl[rows][cols] > 0) cols++;  // If spaces were before number, don't change reading next
    };

    // Update current number
    if (chr >= '0' && chr <= '9') {
      tbl[rows][cols] = ADD_DIGIT(tbl[rows][cols], chr);
      continue;
    }

    // Next row
    if (chr == '\n') {
      rows++;
      cols = 0;
      continue;
    }

    // Sum or multiply column values
    if (chr == '+' || chr == '*') {
      uint64 value = tbl[0][cols];
      for (int row = 1; row < rows; row++) {
        if (chr == '+') value += tbl[row][cols];
        if (chr == '*') value *= tbl[row][cols];
      }
      result += value;
      cols++;
    }

  }

  printf("Result is %lu\n", result);
  DATA_FILE == TEST_FILE && result == 4277556 && printf("Result is correct\n");
  DATA_FILE == INPUT_FILE && result == 6295830249262 && printf("Result is correct\n");

}