/*
 * ball.cpp
 */

#include "include/ball.h"
#include "include/ncurses.h"
#include "world.h"
#include <paddle.h>

namespace world {

Ball::Ball(double y, double x, double dy, double dx, int32_t length,
           const std::string &body_str)
    : y(y), x(x), dx(dx), dy(dy), length(length) {
  for (int i = 0; i < length; i++)
    this->body += body_str;
}

void Ball::moveRight() { ; };

void Ball::moveLeft() {}

void Ball::moveDown() {}

void Ball::moveUp() {}

void Ball::update(game::World *world, game::Game* pongGame) {
  this->x += this->dx;
  this->y += this->dy;

  // check collision
  auto paddle_1 = dynamic_cast<world::Paddle*>(world->getPaddle1());
  auto paddle_2 = dynamic_cast<world::Paddle*>(world->getPaddle2());

  if(this->x >= paddle_1->getX() && this->x <= paddle_1->getX() + paddle_1->getLength() && this->y >= paddle_1->getY()) {
    this->dy = -this->dy;
  }

  if(this->x >= paddle_2->getX() && this->x <= paddle_2->getX() + paddle_2->getLength() && this->y <= paddle_2->getY()) {
    this->dy = -this->dy;
  }

  // check for end of world collisions
  if (this->x <= 1 || this->x >= world->getWidth()-2) {
    this->dx = -this->dx;
  }

  if (this->y <= 0 || this->y >= world->getHeight()-1) {
    pongGame->end();
  }
}

void Ball::render(game::Screen *screen) {
  screen->getArena()->drawAtPosition(this->y, this->x, this->body);
}

} // namespace world
