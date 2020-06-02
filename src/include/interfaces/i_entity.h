/*
 * i_entity.h
 * Defines entity interface
 */

#pragma once
#include "fwd/game.fwd.h"
#include "fwd/world.fwd.h"
#include "screen.h"

namespace world {

/*
 * Abstract class for all game characters
 */
class IEntity {
public:
  virtual ~IEntity() = default;

  /*
   * Update position/dimension using some logic
   */
  virtual void update(game::World *world, game::Game *pongGame) = 0;

  /*
   *  Display entity on screen
   */
  virtual void render(game::Screen *screen) = 0;
};

} // namespace world