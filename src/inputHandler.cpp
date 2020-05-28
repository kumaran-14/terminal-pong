/*
 * inputHandler.cpp
 */

#include "inputHandler.h"

namespace game {
InputHandler::InputHandler(std::unique_ptr<game::ICommand> moveLeft,
                           std::unique_ptr<game::ICommand> moveRight)
    : leftArrow(std::move(moveLeft)), rightArrow(std::move(moveRight)) {}

ICommand* InputHandler::handleInput() {
  // getch();
  // switch();
  // possible return command ptr;
   return nullptr;
}
} // namespace game