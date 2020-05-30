/*
 * inputHandler.cpp
 */

#include "inputHandler.h"

namespace game {
InputHandler::InputHandler(std::unique_ptr<game::ICommand> moveLeft,
                           std::unique_ptr<game::ICommand> moveRight)
    : leftArrow(std::move(moveLeft)), rightArrow(std::move(moveRight)) {}

ICommand *InputHandler::handleInput() {
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
} // namespace game