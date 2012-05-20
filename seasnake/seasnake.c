#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

// _____________________________________________________________________________
typedef struct {
  int x, y;
} Point;

Point *newPoint(int x, int y) {
  Point *p = malloc(sizeof(Point));
  p->x = x;
  p->y = y;
  return p;
}

void freePoint(Point *point) { free(point); }


// _____________________________________________________________________________
int
main() {
  Point *p = newPoint(7, 7);
  char ch;

  initscr();
  cbreak();
  noecho();

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

  endwin();

  freePoint(p);
  return 0;
}
