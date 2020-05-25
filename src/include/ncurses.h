/*
 * ncurses.h
 * Namespace wrapper for ncurses API
 * http://www.cs.ukzn.ac.za/~hughm/os/notes/ncurses.html
 */

#pragma once

#include <cstdint>
#include <curses.h>
#include <string>
#include <unitypes.h>

namespace ncurses {

typedef WINDOW window_t;

void setlocale();

void init();

void cbreak();

void noecho();

void keypad();

void meta();

void nodelay();

void curs_set(const int option);

void setScreenDimensions(int &height, int &width);

void drawBox();

void drawBox(WINDOW *win);

void draw(uint32_t y, uint32_t x, const std::string &str);

void draw(window_t *win, uint32_t y, uint32_t x, const std::string &str);

void refresh();

void refresh(window_t *win);

void clear();

void terminate();

void typeahead();
} // namespace ncurses
