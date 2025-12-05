/*

Advent of Code 2025, day 5, part 2

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(a,b) (a<b ? a : b)
#define MAX(a,b) (a>b ? a : b)
#define IS_MERGED(r) (ranges[r].start == 0 && ranges[r].end == 0)

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
  uint64 result = 0;

  FILE *file = fopen(DATA_FILE, "r");

  // Read ranges
  while (fscanf(file, "%lu-%lu\n", &ranges[len].start, &ranges[len].end) == 2) {
    len++;
  }

  // Merge the ranges in very suboptimal way
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < len; j++) {
      if (i == j || IS_MERGED(i) || IS_MERGED(j)) continue;
      if ((ranges[i].start >= ranges[j].start && 
           ranges[i].start + 1 <= ranges[j].end) ||  // Note start range's inclusiveness
          (ranges[i].end + 1 >= ranges[j].start &&   // Note end range's inclusiveness
           ranges[i].end <= ranges[j].end)) {
        // Ranges overlap -- merge them
        ranges[i].start = MIN(ranges[i].start, ranges[j].start);
        ranges[i].end = MAX(ranges[i].end, ranges[j].end);
        // Mark the other range as merged
        ranges[j].start = 0;
        ranges[j].end = 0;
        // Start from beginning
        i = 0;
        break;
      }
    }
  }

  // Sum the ranges
  for (int i = 0; i < len; i++) {
    if (IS_MERGED(i)) continue;
    result += ranges[i].end - ranges[i].start + 1; // Ranges are inclusive, add one
  }

  printf("Result is %lu\n", result);
  DATA_FILE == TEST_FILE && result == 14 && printf("Result is correct\n");
  DATA_FILE == INPUT_FILE && result == 344813017450467 && printf("Result is correct\n");

}
