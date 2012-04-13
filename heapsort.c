#include <stdio.h>
#include <stdbool.h>

#define HEAP_EMPTY  (-1)
#define DATA_SIZE   (100)


void
swap(int *ref1, int *ref2) {
  int tmp = *ref1;
  *ref1 = *ref2;
  *ref2 = tmp;
}


// vector --------------------------------
typedef struct {
  int *const items;
  const int capacity;
} Vector;

Vector*
vector_alloc(const int capacity) {
  Vector v = {
    .items = malloc(sizeof(int) * capacity),
    .capacity = capacity
  };

  return memcpy(malloc(sizeof(Vector)), &v, sizeof(v));
}

void
vector_free(Vector *vec) {
  free((void *)(vec->items));
  free(vec);
}


// heap ----------------------------------
void
heap_bubble(Vector *vec, int index) {
  if (index == 0) return;

  int parent = (index - 1) >> 1;
  if (vec->items[index] > vec->items[parent]) {
    swap(vec->items + index, vec->items + parent);
    heap_bubble(vec, parent);
  }
}

void
heap_sink(Vector *vec, int index) {
  int leftIndex = index * 2 + 1;
  int rightIndex = index * 2 + 2;

  int compareIndex = -1;

  // determine branch to sink
  if (leftIndex >= vec->capacity)
    return; // end of buffer

  if (rightIndex >= vec->capacity ||
      vec->items[leftIndex] >= vec->items[rightIndex]) {
    compareIndex = leftIndex;
  } else {
    compareIndex = rightIndex;
  }

  // sink
  if (vec->items[compareIndex] > vec->items[index]) {
    swap(vec->items + compareIndex, vec->items + index);
    heap_sink(vec, compareIndex);
  }
}

void
heap_init(Vector *vec) {
  int i;
  for (i = 0; i < vec->capacity; i++)
    vec->items[i] = HEAP_EMPTY;
}

bool
heap_insert(Vector *vec, int item) {
  int i;
  for (i = 0; i < vec->capacity; i++) {
    if (vec->items[i] != HEAP_EMPTY) continue;

    vec->items[i] = item;
    heap_bubble(vec, i);
    return true;
  }

  return false;
}

int
heap_remove(Vector *vec) {
  int result = vec->items[0];
  vec->items[0] = HEAP_EMPTY;
  heap_sink(vec, 0);

  return result;
}


// main ----------------------------------
int
main() {
  int i;

  // read input
  FILE *inputFile = fopen("input.txt", "r");
  if (!inputFile) {
    printf("input.txt not found.");
    return 1;
  }

  Vector *vec = vector_alloc(DATA_SIZE);
  int buffer, index = 0;
  while (index < vec->capacity &&
      fscanf(inputFile, "%d", &buffer) != EOF)
    vec->items[index++] = buffer;

  fclose(inputFile); inputFile = NULL;

  // prepare heap
  Vector *heap = vector_alloc(DATA_SIZE);
  heap_init(heap);

  for (i = 0; i < DATA_SIZE; i++) {
    printf("Adding: %d\r\n", vec->items[i]);
    heap_insert(heap, vec->items[i]);
  }
  printf("Done.\r\n");

  // write output
  FILE *outputFile = fopen("output.txt", "w");
  for (i = 0; i < DATA_SIZE; i++) {
    int next = heap_remove(heap);
    printf("Removing: %d\r\n", next);
    fprintf(outputFile, "%d\r\n", next);
  }

  fclose(outputFile); outputFile = NULL;
  printf("Done.\r\n");

  // cleanpu
  vector_free(vec); vec = NULL;
  vector_free(heap); heap = NULL;

  return 0;
}
