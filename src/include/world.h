/*
 * world.h
 * Defines the game world
 */

#pragma once

#include "i_entity.h"
#include <utility>
#include <vector>

namespace world {
class World {
public:
    World();

    void update();

    void render();

    std::pair<IEntity*, IEntity*> detectCollisions();

    ~World();

private:
    int height, width;
    std::vector<IEntity*> entities;
};
}