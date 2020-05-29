/*
 * ball.h
 * Defines Ball class
 */

#pragma once

#include "interfaces/i_entity.h"
#include "screen.h"
#include <string>

namespace world {

class Ball : public IEntity {

public:
  Ball(double y, double x, double dy, double dx, int32_t length,
       const std::string &body_str);

  void moveRight();

  void moveLeft();

  void moveDown();

  void moveUp();

  void update(game::World *world) override;

  void render(game::Screen *screen) override;

private:
  double y, x, dx, dy;

  int length;

  std::string body = "";
};

} // namespace world