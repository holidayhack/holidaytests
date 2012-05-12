#include <stdio.h>
#include <limits.h>

int
main() {
  long i = 0;

  while (i < LONG_MAX) {
    printf("%ld = ", i);

    if (!(i % 3)) printf("fizz");
    if (!(i % 5)) printf("buzz");
    printf("\r\n");

    i++;
  }

  printf("Done.\r\n");
}

