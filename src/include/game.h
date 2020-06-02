/*
 * game.h
 * Defines the main game class
 */

#pragma once

#include "inputHandler.h"
#include "screen.h"
#include "world.h"
#include <memory>

namespace game {

class Game {
public:
  Game(std::unique_ptr<game::World> &world,
       std::unique_ptr<game::Screen> &screen,
       std::unique_ptr<game::InputHandler> &playerController);
  void start();

  void end();

private:
  /*
   * Main game loop with frame calcuations
   */
  void gameLoop();

  void update();

  void render();

  /*
   * returns commands for entities to act upon.
   */
  void processInputs();

  /*
   * Game status.
   */
  bool isRunning = true;

  /*
   * Object containing the physics logic and game entities
   */
  std::unique_ptr<game::World> world;

  /*
   * Object which controls the graphics part
   */
  std::unique_ptr<game::Screen> screen;

  /*
   * Object which handles player input and aiEngine inputs
   */
  std::unique_ptr<game::InputHandler> playerController;

  /*
   * game score which updates every turn
   */
  int score = 0;
};
} // namespace game