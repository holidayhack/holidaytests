#include <curses.h>
#include <stdio.h>
#include <stdlib.h>

#include "engine.h"
#include "point.h"

int main() {
  initEngine();
  engineStart();
  deInitEngine();
  return 0;
}
