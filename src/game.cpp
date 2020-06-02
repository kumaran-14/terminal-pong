/*
 * game.cpp
 * Implement Game class
 */

#include "game.h"
#include "constants.h"
#include <chrono>
#include <memory>

namespace game {

void Game::start() { this->gameLoop(); }
void Game::end() { this->isRunning = false; }
Game::Game(std::unique_ptr<game::World> &world,
           std::unique_ptr<game::Screen> &screen,
           std::unique_ptr<game::InputHandler> &playerController)
    : world(std::move(world)), screen(std::move(screen)),
      playerController(std::move(playerController)) {}

void Game::gameLoop() {
  using namespace std::chrono;
  auto previousFST = high_resolution_clock::now();
  auto frameLag = nanoseconds::zero();
  while (this->isRunning) {
    auto currentFST = high_resolution_clock::now();
    auto timeElapsed = currentFST - previousFST;
    previousFST = currentFST;

    frameLag += timeElapsed;
    while (frameLag >= constants::MS_PER_FRAME) {
      this->processInputs();
      this->update();
      frameLag -= constants::MS_PER_FRAME;
    }
    this->render();
  }
}

void Game::processInputs() {
  ICommand *command = this->playerController->handlePlayerInput();
  if (command) {
    command->execute(this->world->getPaddle1());
  }
  command = this->playerController->handleAiInput(this->world.get());
  if (command) {
    command->execute(this->world->getPaddle2());
  }
}

void Game::update() { this->world->update(this); }
void Game::render() {
  auto arena = this->screen->getArena();
  arena->erase();
  arena->drawBorder();
  this->world->render(this->screen.get());
  arena->refresh();
}

} // namespace game