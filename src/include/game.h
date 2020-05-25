/*
 * game.h
 */

#pragma once

#include "world.h"
#include "screen.h"

namespace game {
class Game {
public:

    Game();

    void start();

    void end();


    ~Game();

private:
    void gameLoop();

    bool isRunning;
    world::World* world;
    Screen* screen;
    int score;
};
}