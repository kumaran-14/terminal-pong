/*
 * world.cpp
 */
#include "world.h"
namespace game {
World::World(uint32_t height, uint32_t width,
             std::unique_ptr<world::IEntity> &paddle_1,
             std::unique_ptr<world::IEntity> &paddle_2,
             std::unique_ptr<world::IEntity> &ball)
    : height(height), width(width), paddle_1(std::move(paddle_1)),
      paddle_2(std::move(paddle_2)), ball(std::move(ball)) {}

uint32_t World::getHeight() const { return height; }

uint32_t World::getWidth() const { return width; }

world::IEntity *World::getPaddle1() { return this->paddle_1.get(); }

world::IEntity *World::getPaddle2() { return this->paddle_2.get(); }

world::IEntity *World::getBall() { return this->ball.get(); }

void World::update(game::Game *pongGame) {
  this->paddle_1->update(this, pongGame);
  this->paddle_2->update(this, pongGame);
  this->ball->update(this, pongGame);
}

void World::render(game::Screen *screen) {
  this->paddle_1->render(screen);
  this->paddle_2->render(screen);
  this->ball->render(screen);
}

} // namespace game