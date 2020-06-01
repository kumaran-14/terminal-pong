/*
 * game.h
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
  void gameLoop();

  void update();

  void render();

  void processInputs();


  bool isRunning = true;
  std::unique_ptr<game::World> world;
  std::unique_ptr<game::Screen> screen;
  std::unique_ptr<game::InputHandler> playerController;
  int score = 0;
};
} // namespace game