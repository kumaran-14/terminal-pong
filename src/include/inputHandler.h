/*
 * inputHandler.h
 * Defines InputHandler class
 */

#pragma once

#include "interfaces/i_command.h"
#include <memory>
namespace game {
/*
 * Interface for player and aiEngine to control entities
 */
class InputHandler {
public:
  InputHandler(std::unique_ptr<game::ICommand> LeftArrow,
               std::unique_ptr<game::ICommand> RightArrow);

  /*
   * Process input from player
   */
  ICommand *handlePlayerInput();

  /*
   * process input from ai engine
   */
  ICommand *handleAiInput(game::World* world);

private:
  /*
   * Movement commands for entities to act upon
   */
  std::unique_ptr<game::ICommand> leftArrow, rightArrow;
};
} // namespace game