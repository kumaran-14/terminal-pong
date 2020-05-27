/*
 * world.h
 * Defines the game world
 */

#pragma once

#include "i_entity.h"
#include <utility>

namespace game {
/*
 * Defines the physics of the game and interactions of game enities
 */
class World {
public:
    World();

    void update();

    void render();
    uint32_t getHeight() const;
    uint32_t getWidth() const;
    const std::unique_ptr<world::IEntity> &getPaddle1() const;
    const std::unique_ptr<world::IEntity> &getPaddle2() const;
    const std::unique_ptr<world::IEntity> &getBall() const;

    std::pair<world::IEntity*, world::IEntity*> detectCollisions();

    ~World();

private:
    uint32_t height, width;
    std::unique_ptr<world::IEntity> paddle_1, paddle_2, ball;
};
} // game