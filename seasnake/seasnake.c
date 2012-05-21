#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

#include "point.h"
#include "engine.h"


void
initCurses() {
  initscr();  // standard curses init
  cbreak();   // turns-off console buffering
  noecho();   // echo-less input
}

void
deInitCurses() {
  endwin();
}


int
main() {
  Point *p = newPoint(7, 7);
  char ch;

  initCurses();

  while ((ch = getch()) != 'x') {
    mvaddch(0, 0, ch);
    mvaddch(p->y, p->x, ' ');

    switch (ch) {
      case 'i': p->y--; break;
      case 'j': p->x--; break;
      case 'k': p->y++; break;
      case 'l': p->x++; break;
    }

    mvaddch(p->y, p->x, 'x');
  }

  freePoint(p);
  deInitCurses();
  return 0;
}
