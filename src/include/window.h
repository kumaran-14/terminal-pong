/*
 * window.h
 * Defines main screen window class using ncurses API
 */

#pragma once
#include "ncurses.h"
#include <curses.h>
#include <memory>

namespace display {

/*
 * Interface for ncurses window
 */
class Window {
public:
  Window(uint32_t height, uint32_t width, uint32_t y, uint32_t x);

  void drawAtPosition(uint32_t y, uint32_t x, std::string &str);

  void refresh();

  void erase();

  void drawBorder();

  ~Window();

private:
  uint32_t height, width, y, x;
  ncurses::window_t *_win;
};
} // namespace display