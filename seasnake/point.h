#include <stdio.h>
#include <stdlib.h>

#ifndef __POINT_H
#define __POINT_H

typedef struct {
  int x, y;
} Point;

Point *newPoint(int x, int y);
void freePoint(Point *p);

#endif
