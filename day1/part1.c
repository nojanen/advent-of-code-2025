/*

Advent of Code 2025, day 1, part 1

*/
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 5

int main() {
  char direction;
  int ticks;
  int position = 50;
  int result = 0;

  FILE *file = fopen("input.txt", "r");

  while (fscanf(file, "%c%d\n", &direction, &ticks) >= 0) {
    if (direction == 'L') {
      position = (position - ticks) % 100;
    } else {
      position = (position + ticks) % 100;
    }

    if (position < 0) {
      position = 100 + position;
    }

    if (position == 0) {
      result++;
    }
  }

  printf("Result is %d\n", result);
  result == 1031 && printf("Result is correct\n");

  return 0;
}