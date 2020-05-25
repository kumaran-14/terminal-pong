/*
 * ncurses.cpp
 * Wrapper implementation for ncurses API
 */

#include "ncurses.h"

void ncurses::setlocale() { ::setlocale(LC_ALL, "en_US.UTF-8"); };

void ncurses::init() { ::initscr(); };

void ncurses::cbreak() { ::cbreak(); }

void ncurses::noecho() { ::noecho(); };

void ncurses::keypad() { ::keypad(stdscr, TRUE); };

void ncurses::meta() { ::meta(stdscr, TRUE); };

void ncurses::nodelay() {
  ::nodelay(stdscr, TRUE); // non-blocking getch()
}

void ncurses::curs_set(int option) { ::curs_set(option); }

void ncurses::setScreenDimensions(int &height, int &width) {
  getmaxyx(stdscr, height, width);
}

void ncurses::drawBox() { box(stdscr, 0, 0); };

void ncurses::drawBox(ncurses::window_t *win) { box(win, 0, 0); };

void ncurses::draw(uint32_t y, uint32_t x, const std::string &str) {
  mvprintw(y, x, str.c_str());
}

void ncurses::draw(ncurses::window_t *win, uint32_t y, uint32_t x, const std::string &str) {
  mvwprintw(win, y, x, str.c_str());
}

void ncurses::refresh() { ::refresh(); }

void ncurses::refresh(WINDOW *win) { wrefresh(win); }

void ncurses::terminate() { endwin(); }

void ncurses::clear() {
  clear();
}

void ncurses::typeahead() {
  ::typeahead(-1);
}
