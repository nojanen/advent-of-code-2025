/*

Advent of Code 2025, day 3, part 1

*/
#include <stdio.h>
#include <stdlib.h>

#define COLS 100
#define ROWS 200

#define TO_INT(tens,ones) (((tens - '0') * 10) + (ones - '0'))

typedef char table_t[ROWS][COLS];

// Find the index of the biggest value from the given range.
int find_max_col(char row[COLS], int start_col, int end_col) {
  int max_col = start_col;
  for (int col = start_col + 1; col < end_col; col++) {
    if (row[col] > row[max_col]) max_col = col;
  }
  return max_col;
}

int main() {
  table_t buf;
  char in;
  int cols = 0;
  int rows = 0;
  int result = 0;

  FILE *file = fopen("input.txt", "r");

  // Read the data as characters in
  while(fscanf(file, "%c", &in) >= 0) {
    if (in == '\n') {
      rows++;
      cols = 0;
      continue;
    }
    buf[rows][cols] = in;
    cols++;
  }
  rows++;

  for (int row = 0; row < rows; row++) {
    int tens = find_max_col(buf[row], 0, cols);  // Find the largest digit
    int ones;

    if (tens < cols-1) {
      // Find next largest digit from the right side of the largest
      ones = find_max_col(buf[row], tens+1, cols);
    } else {
      // The largest digit was the last, and it'll be ones
      // Find the next largest as new tens
      ones = tens;
      tens = find_max_col(buf[row], 0, cols-1);
    }
    
    result += TO_INT(buf[row][tens], buf[row][ones]);
  }

  printf("Result is %d\n", result);
  result == 16854 && printf("Result is correct\n");

  return 0;
}