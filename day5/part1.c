/*

Advent of Code 2025, day 5, part 1

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEST_FILE  "test.txt"
#define INPUT_FILE "input.txt"
#define DATA_FILE  INPUT_FILE

typedef unsigned long uint64;
typedef struct {
  uint64 start;
  uint64 end;
} range_t;

int main() {
  range_t ranges[200];
  int len = 0;
  int result = 0;
  uint64 ingridient;

  FILE *file = fopen(DATA_FILE, "r");

  // Read ranges
  while (fscanf(file, "%lu-%lu\n", &ranges[len].start, &ranges[len].end) == 2) {
    len++;
  }

  // When last range is been read, and fscanf returns 1,
  // the 1st ingridient is already read from file
  ingridient = ranges[len].start;

  // While reading ingridient ids, check does ingridient
  // match any of the ranges
  do {
    for(int range = 0; range < len; range++) {
      if (ingridient >= ranges[range].start && ingridient <= ranges[range].end) {
        result++;
        break;
      }
    }
  } while (fscanf(file, "%lu", &ingridient) >= 0);

  printf("Result is %d\n", result);
  DATA_FILE == TEST_FILE && result == 3 && printf("Result is correct\n");
  DATA_FILE == INPUT_FILE && result == 558 && printf("Result is correct\n");

}