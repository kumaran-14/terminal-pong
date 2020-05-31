/*
 * game.cpp
 * Implment Game class
 */

#include "game.h"
#include "constants.h"
#include <memory>
#include <chrono>

namespace game {

void Game::start() {
  this->gameLoop();
}
void Game::end() { this->isRunning = false; }
Game::Game(std::unique_ptr<game::World> &world,
           std::unique_ptr<game::Screen> &screen,
           std::unique_ptr<game::InputHandler> &keyBoardHandler)
    : world(std::move(world)), screen(std::move(screen)),
      keyBoardHandler(std::move(keyBoardHandler)) {}

void Game::gameLoop() {
  using namespace std::chrono;
  auto previousFST = high_resolution_clock::now();
  auto frameLag = nanoseconds::zero();
  while(this->isRunning) {
    auto currentFST = high_resolution_clock::now();
    auto timeElapsed = currentFST - previousFST;
    previousFST = currentFST;

    frameLag += timeElapsed;
    while (frameLag >= constants::MS_PER_FRAME) {
      this->processInput();
//      this->processAI();
      this->update();
      frameLag -= constants::MS_PER_FRAME;
    }
    this->render();
  }
}

void Game::processInput() {
  ICommand* command = this->keyBoardHandler->handleInput();
  if(command) {
    command->execute(this->world->getPaddle1());
    command->execute(this->world->getPaddle2());

  }
}

void Game::update() {
  this->world->update(this);
}
void Game::render() {
  auto arena = this->screen->getArena();
  arena->erase();
  arena->drawBorder();
  this->world->render(this->screen.get());
  arena->refresh();
}

} // namespace game