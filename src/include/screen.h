/*
 * screen.h
 * Game Screen using ncurses API
 */

#pragma once

#include "window.h"
#include <cstdint>
#include <memory>
#include <tuple>

namespace game {

class Screen {
public:

  Screen();

  void setDimensions();

  std::tuple<uint32_t, uint32_t > getDimensions();

  void drawAtPosition(uint32_t y, uint32_t x, const std::string &str);

  void refresh();

  display::Window* getArena();

  void setArena(std::unique_ptr<display::Window> &arena_window);

  /*
   * call terminate and clear screen
   */
  ~Screen();

private:
    uint32_t height, width;
    std::unique_ptr<display::Window> arena;
};


} // game