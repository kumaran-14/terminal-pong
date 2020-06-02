/*
 * ball.cpp
 */

#include "include/ball.h"
#include "constants.h"
#include "include/ncurses.h"
#include "paddle.h"
#include "world.h"

namespace world {

Ball::Ball(double y, double x, double dy, double dx, int32_t length,
           const std::string &body_str)
    : y(y), x(x), dx(dx), dy(dy), length(length) {
  for (int i = 0; i < length; i++)
    this->body += body_str;
}

void Ball::setXVel(double dx) {
  using namespace constants;
  if (dx > MAX_BALL_X_VELOCITY)
    dx = MAX_BALL_X_VELOCITY;
  if (dx < -MAX_BALL_X_VELOCITY)
    dx = -MAX_BALL_X_VELOCITY;
  this->dx = dx;
}

void Ball::setYVel(double dy) {
  using namespace constants;
  if (dy > MAX_BALL_Y_VELOCITY)
    dy = MAX_BALL_Y_VELOCITY;
  if (dy < -MAX_BALL_Y_VELOCITY)
    dy = -MAX_BALL_Y_VELOCITY;
  this->dy = dy;
}

void Ball::update(game::World *world, game::Game *pongGame) {
  this->x += this->dx;
  this->y += this->dy;

  auto paddle_1 = dynamic_cast<world::Paddle *>(world->getPaddle1());
  auto paddle_2 = dynamic_cast<world::Paddle *>(world->getPaddle2());
  auto ball = dynamic_cast<world::Ball *>(world->getBall());

  auto randomizeBallSpeed = [ball]() {
    auto newdx = rand() % (int)(2 * constants::MAX_BALL_X_VELOCITY + 1) -
                 constants::MAX_BALL_X_VELOCITY;
    ball->setXVel(newdx);
  };

  // collision with player_1
  if (this->x >= paddle_1->getX() &&
      this->x <= paddle_1->getX() + paddle_1->getLength() &&
      this->y >= paddle_1->getY()) {
    this->dy = -this->dy;
    randomizeBallSpeed();
  }

  // collision with player_1
  if (this->x >= paddle_2->getX() &&
      this->x <= paddle_2->getX() + paddle_2->getLength() &&
      this->y <= paddle_2->getY()) {
    this->dy = -this->dy;
    randomizeBallSpeed();
  }

  // check for end of world collisions
  if (this->x <= 1 || this->x >= world->getWidth() - 2) {
    this->dx = -this->dx;
  }

  if (this->y <= 0 || this->y >= world->getHeight() - 1) {
    pongGame->end();
  }
}

double Ball::getX() const { return this->x; }

double Ball::getY() const { return this->y; }

int Ball::getLength() const { return this->length; };

void Ball::render(game::Screen *screen) {
  screen->getArena()->drawAtPosition(this->y, this->x, this->body);
}

} // namespace world
