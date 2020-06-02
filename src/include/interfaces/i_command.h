/*
 * i_command.h
 * Interface for game commands
 */

#pragma once
#include "interfaces/i_entity.h"

namespace game {

/*
 * Abstract class for all common commands
 */
class ICommand {
public:
  virtual ~ICommand() = default;
  /*
   * Implementation for every command
   */
  virtual void execute(world::IEntity *) = 0;
};
} // namespace game