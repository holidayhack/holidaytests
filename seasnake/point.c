#include "point.h"

Point *newPoint(int x, int y) {
  Point *p = malloc(sizeof(Point));
  p->x = x;
  p->y = y;
  return p;
}

void freePoint(Point *p) { free(p); }
