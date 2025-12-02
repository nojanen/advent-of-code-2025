/*

Advent of Code 2025, day 2, part 2

*/
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef unsigned long uint64;
static uint64 pow10[11] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000};

int length(uint64 number) {
  int digits = 1;
  while (number > 9) {
    number /= 10;
    digits++;
  }
  return digits;
}

uint64 repeat(uint64 part, int part_length, int repetitions) {
  uint64 result = 0;
  while (repetitions-- > 0) {
    result = result * pow10[part_length] + part;
  }
  return result;
}

int main() {
  uint64 start;
  uint64 end;
  uint64 result = 0;

  FILE *file = fopen("input.txt", "r");

  while (fscanf(file, "%lu-%lu,", &start, &end) >= 0) {
    for (uint64 id = start; id <= end; id++) {
      int id_len = length(id);

      for (int part_len = 1; part_len <= id_len / 2; part_len++) {
        uint64 invalid_id = repeat(id % pow10[part_len], part_len, id_len / part_len);
        if (id_len % part_len == 0 && id == invalid_id) {
          result += id;
          break;
        }
      }
    }
  }

  printf("Result is %lu\n", result);
  result == 31680313976 && printf("Result is correct\n");

  return 0;
}