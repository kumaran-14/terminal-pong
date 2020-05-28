//
// Created by kumaran on 6/1/20.
//

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
const std::unique_ptr<world::IEntity> &World::getPaddle1() const {
//  return paddle_1;
}
const std::unique_ptr<world::IEntity> &World::getPaddle2() const {
//  return paddle_2;
}
const std::unique_ptr<world::IEntity> &World::getBall() const { return ball; }
void World::render() { ; }
void World::update() { ; }
} // namespace game