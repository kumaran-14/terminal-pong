/*
 * inputHandler.cpp
 */

#include "inputHandler.h"
#include "ball.h"
#include "paddle.h"
#include "world.h"
#include <constants.h>

namespace game {
InputHandler::InputHandler(std::unique_ptr<game::ICommand> moveLeft,
                           std::unique_ptr<game::ICommand> moveRight)
    : leftArrow(std::move(moveLeft)), rightArrow(std::move(moveRight)) {}

ICommand *InputHandler::handlePlayerInput() {
  int input = getch();
  switch (input) {
  case KEY_RIGHT:
    return this->rightArrow.get();
    break;
  case KEY_LEFT:
    return this->leftArrow.get();
    break;
  default:
    break;
  }
  return nullptr;
}

ICommand *InputHandler::handleAiInput(game::World *world) {
  auto paddle = dynamic_cast<world::Paddle *>(world->getPaddle2());
  auto ball = dynamic_cast<world::Ball *>(world->getBall());
  // calculate distance from ball to paddle center;
  double dx = -(paddle->getX() + (paddle->getLength() / 2.0) - ball->getX());

  if (dx <= -constants::MAX_PADDLE_X_VELOCITY)
    dx = -constants::MAX_PADDLE_X_VELOCITY;
  if (dx >= constants::MAX_PADDLE_X_VELOCITY)
    dx = constants::MAX_PADDLE_X_VELOCITY;

  if (dx < 0)
    return this->leftArrow.get();
  if (dx > 0)
    return this->rightArrow.get();
  return nullptr;
}
} // namespace game