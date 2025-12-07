/*

Advent of Code 2025, day 6, part 2

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#define TEST_FILE  "test.txt"
#define INPUT_FILE "input.txt"
#define DATA_FILE  INPUT_FILE

#define COLS 4000
#define ROWS 5

#define ADD_DIGIT(value, ones) (value * 10 + (ones - '0'))

typedef unsigned long uint64;
typedef char table_t[ROWS][COLS];

int col_to_int(table_t tbl, int col, int rows) {
  int number = 0;
  for (int row = 0; row < rows; row++) {
    if (tbl[row][col] >= '0' && tbl[row][col] <= '9') {
      number = ADD_DIGIT(number, tbl[row][col]);
    }
  }
  return number;
}

int main() {

  table_t tbl;
  char chr;
  int cols = 0;
  int rows = 0;
  char op = ' ';
  uint64 value = 0;
  uint64 result = 0;

  FILE *file = fopen(DATA_FILE, "r");

  memset(tbl, 0, ROWS * COLS);

  // Read input one char at time to table
  while (fscanf(file, "%c", &chr) >= 1) {
    tbl[rows][cols] = chr;
    cols++;

    // Next row
    if (chr == '\n') {
      rows++;
      cols = 0;
      continue;
    }
  }

  // Go through the last row and calculate numbers
  for (int col = 0; col < cols; col++) {
    if (tbl[rows][col] != ' ') {
      result += value;
      op = tbl[rows][col];
      value = 0;
    }

    if (op == '+' || op == '*') {
      int number = col_to_int(tbl, col, rows);
      if (number > 0) {
        if (op == '+') value += number;
        if (op == '*') value = value == 0 ? number : value * number;
      }
    }

  }
  result += value;

  printf("Result is %lu\n", result);
  DATA_FILE == TEST_FILE && result == 3263827 && printf("Result is correct\n");
  DATA_FILE == INPUT_FILE && result == 9194682052782 && printf("Result is correct\n");

}