/*

Advent of Code 2025, day 2, part 1

*/
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef unsigned long uint64;
static uint64 pow10[6] = {1, 10, 100, 1000, 10000, 100000};

int length(uint64 number) {
  int digits = 1;
  while (number > 9) {
    number /= 10;
    digits++;
  }
  return digits;
}

int main() {
  uint64 start;
  uint64 end;
  uint64 result = 0;

  FILE *file = fopen("input.txt", "r");

  while(fscanf(file, "%lu-%lu,", &start, &end) >= 0) {
    for(uint64 id=start; id<=end; id++) {
      int id_len = length(id);
      uint64 half = id / pow10[id_len/2];
      uint64 invalid_id = half * pow10[id_len/2] + half;

      if (id_len%2 == 0 && id == invalid_id) result += id;
    }
  }

  printf("Result is %lu\n", result);
  result == 26255179562 && printf("Result is correct\n");

  return 0;
}