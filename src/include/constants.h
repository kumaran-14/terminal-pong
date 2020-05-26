/*
 * constants.h
 * Defines all game constants
 */

#pragma once

#include <cstdint>

namespace constants {
  uint32_t MIN_SCREEN_WIDTH = 80;
  uint32_t MIN_SCREEN_HEIGHT = 30;
  uint32_t MIN_PADDLE_WIDTH = 16;
  std::string PADDLE_BODY_CHARACTER = "■";
  uint32_t BALL_WIDTH = 1;
  std::string BALL_BODY_CHARACTER = "■";
}