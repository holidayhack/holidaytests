#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

#include "point.h"
#include "engine.h"


int
main() {
  initEngine();
  engineStart();
  deInitEngine();
  return 0;
}
