#include <stdio.h>
#include <stdbool.h>


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

  if (buffer[0] == '-') return kEmpty;
  if (buffer[0] == 'B') return kBuzz;
  if (buffer[4] == 'B') return kFizzBuzz;
  if (buffer[0] == 'F') return kFizz;
  return kEmpty;
}

FizzBuzz
fizzBuzzFromNumber(int num) {
  bool mod3 = (num % 3 == 0);
  bool mod5 = (num % 5 == 0);

  if (mod3 && mod5) return kFizzBuzz;
  if (mod3) return kFizz;
  if (mod5) return kBuzz;
  return kEmpty;
}


// ________________________________________
bool
solve(FizzBuzz *pattern, int *output, int count) {
  int diff = 1, num = 0;
  while (diff > 0) {
    num += diff;
    output[0] = num;
    diff = fillOutput(pattern, output, count);
  }

  return true;
}

int
fillOutput(FizzBuzz *pattern, int *output, int count) {
  FizzBuzz fb = kEmpty;
  int i, num;

  for (i = 0, num = output[0]; i < count; i++, num++) {
    if (fizzBuzzFromNumber(num) != (fb = pattern[i])) {
      // fast-forward to next possible cases
      // i.e. advance 1 to 3 if it's a fizz (skipping 2)
      switch(fb) {
        case kEmpty: return 1;
        case kFizz: return 3 - (num % 3);
        case kBuzz: return 5 - (num % 5);
        case kFizzBuzz: return 15 - (num % 15);
      }
    }

    output[i] = num;
  }

  return 0;
}


// ________________________________________
int
main() {
  int i = 0;
  buffer = malloc(sizeof(char) * 9); // 9 chars for FizzBuzz\0

  // read input fizzbuzz pattern
  FILE *in = fopen("./input.txt", "r");
  int count = 0;
  FizzBuzz *pattern = NULL;

  fscanf(in, "%d", &count);
  pattern = malloc(sizeof(FizzBuzz) * count);
  for (i = 0; i < count; i++)
    pattern[i] = readFizzBuzzLine(in);

  fclose(in); in = NULL;

  // figure out original sequence
  int *result = malloc(sizeof(int) * count);
  solve(pattern, result, count);

  FILE *out = fopen("./output.txt", "w");
  for (i = 0; i < count; i++)
    fprintf(out, "%d\r\n", result[i]);

  fclose(out); out = NULL;

  // cleanup
  free(result); result = NULL;
  free(pattern); pattern = NULL;
  free(buffer); buffer = NULL;
  return 0;
}

