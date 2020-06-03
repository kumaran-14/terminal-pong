/*
 * paddle.cpp
 */

#include "include/paddle.h"
#include "include/ncurses.h"
#include "world.h"

namespace world {

Paddle::Paddle(double y, double x, double dy, double dx, int32_t length,
               const std::string &body_str)
    : y(y), x(x), dx(dx), dy(dy), length(length) {
  for (int i = 0; i < length; i++)
    this->body += body_str;
}

void Paddle::moveRight() { this->x += this->dx; };

void Paddle::moveLeft() { this->x -= this->dx; };

void Paddle::update(game::World *world, game::Game *pongGame) {
  if (this->x <= 1)
    this->x = 1;
  if (this->x + this->length >= world->getWidth()-1)
    this->x = world->getWidth() - this->length - 1;
}

void Paddle::render(game::Screen *screen) {
  screen->getArena()->drawAtPosition(this->y, this->x, this->body);
}

double Paddle::getX() const { return this->x; }

double Paddle::getY() const { return this->y; }

int Paddle::getLength() const { return this->length; };
} // namespace world