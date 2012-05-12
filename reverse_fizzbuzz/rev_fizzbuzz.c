#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <strings.h>


char *buffer = NULL;

// ________________________________________
typedef enum {
  kEmpty = 0,
  kFizz = 3,
  kBuzz = 5,
  kFizzBuzz = 15
} FizzBuzz;

FizzBuzz
readFizzBuzzLine(FILE *fp) {
  fscanf(fp, "%s", buffer);

  if (buffer[0] == 'B') return kBuzz;
  if (buffer[4] == 'B') return kFizzBuzz;
  if (buffer[0] == 'F') return kFizz;
  return kEmpty;
}


// ________________________________________
bool
solve(FizzBuzz *pattern, int *output, int count) {
  int i = 0;
  for (i = 0; i < count; i++) {
    switch(pattern[i]) {
      case kEmpty: printf("Empty\r\n"); break;
      case kFizz: printf("Fizz\r\n"); break;
      case kBuzz: printf("Buzz\r\n"); break;
      case kFizzBuzz: printf("FizzBuzz\r\n"); break;
    }

    output[i] = i;
  }

  return true;
}


// ________________________________________
int
main() {
  int i = 0;
  buffer = malloc(sizeof(char) * 16);


  // read input fizzbuzz pattern
  FILE *in = fopen("./input.txt", "r");
  int count = 0;
  FizzBuzz *pattern = NULL;

  fscanf(in, "%d\r\n", &count);
  pattern = malloc(sizeof(FizzBuzz) * count);

  for (i = 0; i < count; i++) {
    pattern[i] = readFizzBuzzLine(in);
  }

  fclose(in); in = NULL;


  // figure out original sequence
  int *result = malloc(sizeof(int) * count);
  solve(pattern, result, count);

  FILE *out = fopen("./output.txt", "w");
  for (i = 0; i < count; i++)
    fprintf(out, "%d\r\n", result[i]);

  fclose(out); out = NULL;


  free(result); result = NULL;
  free(pattern); pattern = NULL;
  free(buffer); buffer = NULL;
  return 0;
}

