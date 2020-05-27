/*
 * ball.cpp
 */

#pragma once

#include "include/ball.h"
#include "include/ncurses.h"
#include "world.h"

namespace world {

Ball::Ball(double y, double x, double dy, double dx, int32_t length,
           const std::string &body_str)
    : y(y), x(x), dx(dx), dy(dy), length(length) {
  for (int i = 0; i < length; i++)
    this->body += body_str;
}

void Ball::update(game::World *world) {
  // how ball updates;
  this->x += this->dx;
  this->y += this->dy;

  // check for end of world collisions
  if (this->x <= 1) {
    this->x = 1;
    this->dx = -this->dx;
  } else if (this->x >= world->getWidth() - 1) {
    this->x = world->getWidth() - 1;
    this->dx = -this->dx;
  }
  // check collision

  if (this->y <= 1 || this->y >= world->getHeight() - 1) {
    // call it quits
  }
}

void Ball::render(game::Screen *screen) {
  screen->getArena()->drawAtPosition(this->y, this->x, this->body);
};

} // namespace world
