#include "engine.h"
#include "point.h"
#include <curses.h>

void initCurses() {
  initscr(); // standard curses init
  cbreak();  // turns-off console buffering
  noecho();  // echo-less input
}

void deInitCurses() { endwin(); }

void initEngine() { initCurses(); }

void deInitEngine() { deInitCurses(); }

void engineStart() {
  Point *p = newPoint(7, 7);
  char ch;

  while ((ch = getch()) != 'x') {
    mvaddch(0, 0, ch);
    mvaddch(p->y, p->x, ' ');

    switch (ch) {
    case 'i':
      p->y--;
      break;
    case 'j':
      p->x--;
      break;
    case 'k':
      p->y++;
      break;
    case 'l':
      p->x++;
      break;
    }

    mvaddch(p->y, p->x, 'x');
  }

  freePoint(p);
}
