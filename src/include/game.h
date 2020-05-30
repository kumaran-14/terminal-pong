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
       std::unique_ptr<game::InputHandler> &keyBoardHandler);
  void start();

  void end();


private:
  void gameLoop();

  void update();

  void render();

  void processInput();

  bool isRunning = true;
  std::unique_ptr<game::World> world;
  std::unique_ptr<game::Screen> screen;
  std::unique_ptr<game::InputHandler> keyBoardHandler;
  int score = 0;
};
} // namespace game