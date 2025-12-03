/*

Advent of Code 2025, day 3, part 2

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1

#define COLS 100
#define ROWS 200

#define TO_INT(ones) (ones - '0')

typedef char table_t[ROWS][COLS];
typedef unsigned long uint64;

int main() {
  table_t buf;
  char in;
  int cols = 0;
  int rows = 0;
  char removed[COLS];
  uint64 result = 0;

  FILE *file = fopen("input.txt", "r");

  // Read the data
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

  // Process the data
  for (int row = 0; row < rows; row++) {
    memset(removed, 0, COLS);
    uint64 value = 0;

    // Remove the smallest digits. Start from the most significant ones.
    // Try to remove smaller digits from the left side of the bigger ones.
    for (int i = 0; i < cols-12; i++) {
      int min_col = -1;

      for (int col = 0; col < cols; col++) {
        if (removed[col]) continue;  // Skip removed
        if (min_col < 0 || buf[row][col] < buf[row][min_col]) min_col = col;  // 1st available or smaller than previous
        if (min_col < col && buf[row][col] > buf[row][min_col]) break;  // Bigger than previous, remove previous
      }

      removed[min_col] = TRUE;
    }

    // Make number from the left character digits.
    for (int i = 0; i < cols; i++) {
      if (!removed[i]) value = value * 10 + TO_INT(buf[row][i]);
    }

    result += value;
  }

  printf("Result is %lu\n", result);
  result == 167526011932478 && printf("Result is correct\n");

  return 0;
}