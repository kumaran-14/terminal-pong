/*
 * i_command.h
 * Interface for game commands
 */

#pragma once
#include "interfaces/i_entity.h"

namespace game {
class ICommand {
public:
  virtual ~ICommand() = default;
  virtual void execute(world::IEntity*) = 0;
};
}