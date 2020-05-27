//
// Created by kumaran on 6/1/20.
//

#include "world.h"
namespace game {
World::World() {}
uint32_t World::getHeight() const { return height; }
uint32_t World::getWidth() const { return width; }
const std::unique_ptr<world::IEntity> &World::getPaddle1() const {
  return paddle_1;
}
const std::unique_ptr<world::IEntity> &World::getPaddle2() const {
  return paddle_2;
}
const std::unique_ptr<world::IEntity> &World::getBall() const { return ball; };
}