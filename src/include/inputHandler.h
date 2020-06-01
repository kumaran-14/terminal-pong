/*
 * inputHandler.h
 */

#pragma once

#include "interfaces/i_command.h"
#include <memory>
namespace game {
class InputHandler {
public:
  InputHandler(std::unique_ptr<game::ICommand> LeftArrow,
               std::unique_ptr<game::ICommand> RightArrow);

  ICommand *handlePlayerInput();

  ICommand *handleAiInput(game::World* world);

private:
  std::unique_ptr<game::ICommand> leftArrow, rightArrow;
};
} // namespace game