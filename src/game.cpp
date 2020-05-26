/*
 * game.cpp
 * Implment Game class
 */

#include <bits/unique_ptr.h>
#include <game.h>
namespace game {

game::Game::Game(const std::unique_ptr<world::World> &world,
                 const std::unique_ptr<Screen> &screen)
    : world(std::move(world)), screen(std::move(world)) {}
} // game