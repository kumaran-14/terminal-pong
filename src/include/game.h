/*
 * game.h
 */

#pragma once

#include "world.h"
#include "screen.h"
#include <memory>

namespace game {
class Game {
public:

  Game(const std::unique_ptr<game::World> &World,
       const std::unique_ptr<Screen> &Screen);

  void start();

  void end();

private:
    void gameLoop();

    bool isRunning;
    std::unique_ptr<game::World> world;
    std::unique_ptr<Screen> screen;
    int score;
};
}