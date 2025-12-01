/*

Advent of Code 2025, day 1, part 2

*/
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 5
#define SWAP(x) ((100 - x) % 100)

int main() {
  char direction;
  int ticks;
  int position = 50;
  int result = 0;

  FILE *file = fopen("input.txt", "r");

  while (fscanf(file, "%c%d\n", &direction, &ticks) >= 0) {
    position = (direction == 'L') ? SWAP(position) : position;
    result += (position + ticks) / 100;
    position = (position + ticks) % 100;
    position = (direction == 'L') ? SWAP(position) : position;
  }

  printf("Result is %d\n", result);
  result == 5831 && printf("Result is correct\n");

  return 0;
}