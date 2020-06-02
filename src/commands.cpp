/*
 * commands.cpp
 * Defines all commands that the entity can take
 */

#include "commands.h"
#include "ball.h"
#include "paddle.h"

namespace game {

void game::MoveRightCommand::execute(world::IEntity *entity) {
  auto paddlePtr = dynamic_cast<world::Paddle *>(entity);
  if (paddlePtr) {
    paddlePtr->moveRight();
  }
  //  auto ballPtr = dynamic_cast<world::Ball *>(entity);
  //  if (ballPtr) {
  //    ballPtr->moveRight();
  //  }
}

void MoveLeftCommand::execute(world::IEntity *entity) {
  auto paddlePtr = dynamic_cast<world::Paddle *>(entity);
  if (paddlePtr) {
    paddlePtr->moveLeft();
  }
  //  auto ballPtr = dynamic_cast<world::Ball *>(entity);
  //  if (ballPtr) {
  //    ballPtr->moveLeft();
  //  }
}

void game::MoveDownCommand::execute(world::IEntity *entity) {

  auto ballPtr = dynamic_cast<world::Ball *>(entity);
  if (ballPtr) {
    //    ballPtr->moveUp();
  }
}

void game::MoveUpCommand::execute(world::IEntity *entity) {
  auto ballPtr = dynamic_cast<world::Ball *>(entity);
  if (ballPtr) {
    //    ballPtr->moveDown();
  }
}

} // namespace game