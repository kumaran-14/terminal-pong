/*
 * paddle.h
 * Defines Paddle class
 */

#pragma once

#include "interfaces/i_entity.h"
#include "screen.h"
#include <string>

namespace world {

class Paddle : public IEntity {

public:
  Paddle(double y, double x, double dy, double dx, int32_t length,
         const std::string &body_str);

  void moveRight();

  void moveLeft();

  [[nodiscard]] double getX() const;

  [[nodiscard]] double getY() const;

  [[nodiscard]] int getLength() const;

  /*
   * see @IEntity
   */
  void update(game::World *world, game::Game *pongGame) override;

  /*
   * see @IEntity
   */
  void render(game::Screen *screen) override;

private:
  double y, x, dx, dy;

  int length;

  std::string body = "";
};

} // namespace world