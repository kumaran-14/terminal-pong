/*
 * commands.h
 * Defines all commands class
 */
#pragma once
#include "interfaces/i_command.h"

namespace game {

class MoveRightCommand : public ICommand {
public:
  void execute(world::IEntity *entity) override;
};

class MoveLeftCommand : public ICommand {
public:
  void execute(world::IEntity *entity) override;
};

class MoveDownCommand : public ICommand {
public:
  void execute(world::IEntity *entity) override;
};

class MoveUpCommand : public ICommand {
public:
  void execute(world::IEntity *entity) override;
};

} // namespace game