/*
 * ncurses.h
 * Namespace wrapper for ncurses API.
 * Making it .hpp will not be useful for #including
 * http://www.cs.ukzn.ac.za/~hughm/os/notes/ncurses.html
 */

#pragma once

#include <cstdint>
#include <curses.h>
#include <string>
#include <unitypes.h>

namespace ncurses {

typedef WINDOW window_t;

// ncurses stdscr options

void setlocale();

void init();

void cbreak();

void noecho();

void keypad();

void meta();

void nodelay();

void curs_set(const int option);

void setScreenDimensions(uint32_t &height,uint32_t &width);

void drawBox();

void draw(uint32_t y, uint32_t x, const std::string &str);

void refresh();

void refresh(window_t *win);

void clear();

void terminate();

void typeahead();

// window related functions

window_t* createWindow(uint32_t height, uint32_t width, uint32_t y, uint32_t x);

void drawBox(window_t *win);

void draw(window_t *win, uint32_t y, uint32_t x, const std::string &str);

void destroyWindow(window_t* win);


} // namespace ncurses
