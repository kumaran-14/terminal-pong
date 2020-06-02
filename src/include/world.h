/*
 * world.h
 * Defines the game world
 */

#pragma once

#include "fwd/game.fwd.h"
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

  /*
   * Updates game entities according to defined physics
   */
  void update(game::Game *);

  /*
   * Display game entities
   */
  void render(game::Screen *);

  [[nodiscard]] uint32_t getHeight() const;
  [[nodiscard]] uint32_t getWidth() const;

  world::IEntity *getPaddle1();

  world::IEntity *getPaddle2();

  world::IEntity *getBall();

private:
  uint32_t height{}, width{};
  std::unique_ptr<world::IEntity> paddle_1, paddle_2, ball;
};
} // namespace game