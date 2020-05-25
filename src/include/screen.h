/*
 * screen.h
 * Game Screen using ncurses API
 */

#pragma once

#include "window.h"
#include <tuple>
#include <cstdint>

namespace game {

class Screen {
public:

  Screen();

  void setDimensions();

  std::tuple<uint32_t, uint32_t > getDimensions();

  void drawAtPosition(const uint32_t y, const uint32_t x, const std::string &str);


  ~Screen();

private:
    int height, width;
    // std::unique_ptr<Window> arena;
    // std::unique_ptr<Window> menu;
};


} // game