/*
 * world.h
 * Defines the game world
 */

#pragma once

#include "interfaces/i_entity.h"
#include <utility>

namespace game {
/*
 * Defines the physics of the game and interactions of game enities
 */
class World {
public:
  World(uint32_t height, uint32_t width,
        std::unique_ptr<world::IEntity> &paddle_1,
        std::unique_ptr<world::IEntity> &paddle_2,
        std::unique_ptr<world::IEntity> &ball);

  void update();

  void render();
  [[nodiscard]] uint32_t getHeight() const;
  [[nodiscard]] uint32_t getWidth() const;
  [[nodiscard]] const std::unique_ptr<world::IEntity> &getPaddle1() const;
  [[nodiscard]] const std::unique_ptr<world::IEntity> &getPaddle2() const;
  [[nodiscard]] const std::unique_ptr<world::IEntity> &getBall() const;

private:
  uint32_t height{}, width{};
  std::unique_ptr<world::IEntity> paddle_1, paddle_2, ball;
};
} // namespace game