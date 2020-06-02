/*
 * screen.h
 * Game graphics interface using ncurses API
 */

#pragma once

#include "window.h"
#include <cstdint>
#include <memory>
#include <tuple>

namespace game {

/*
 * Interface for ncurses stdscr
 */
class Screen {
public:
  Screen();

  void setDimensions();

  std::tuple<uint32_t, uint32_t> getDimensions();

  void drawAtPosition(uint32_t y, uint32_t x, const std::string &str);

  /*
   * Update objects position in screen memory
   */
  void refresh();

  display::Window *getArena();

  void setArena(std::unique_ptr<display::Window> &arena_window);

  /*
   * call terminate and clear screen
   */
  ~Screen();

private:
  /*
   * Main Screen dimensions
   */
  uint32_t height, width;

  /*
   * Main screen window where game is rendered.
   */
  std::unique_ptr<display::Window> arena;
};

} // namespace game