/*
 * ball.h
 * Defines Ball class
 */

#pragma once

#include "game.h"
#include "interfaces/i_entity.h"
#include "screen.h"
#include <string>

namespace world {

class Ball : public IEntity {

public:
  Ball(double y, double x, double dy, double dx, int32_t length,
       const std::string &body_str);

  /*
   * @see IEntity
   */
  void update(game::World *world, game::Game *pongGame) override;

  /*
   * @see IEntity
   */
  void render(game::Screen *screen) override;

  void setXVel(double);

  void setYVel(double);

  [[nodiscard]] double getX() const;

  [[nodiscard]] double getY() const;

  [[nodiscard]] int getLength() const;

private:

  double y, x;

  double dx, dy;

  int length;

  std::string body = "";
};

} // namespace world