/*
 * game.cpp
 * Implment Game class
 */

#include <bits/unique_ptr.h>
#include <game.h>
namespace game {

void Game::start() {}
void Game::end() { this->isRunning = false; }
Game::Game(std::unique_ptr<game::World> &world,
           std::unique_ptr<game::Screen> &screen,
           std::unique_ptr<game::InputHandler> &keyBoardHandler)
    : world(std::move(world)), screen(std::move(screen)),
      keyBoardHandler(std::move(keyBoardHandler)) {}
void Game::gameLoop() {
  // main game goes here.
}
} // namespace game