/*
 * i_entity.h
 * Defines entity interface
 */

#pragma once
#include "screen.h"
#include "world.fwd.h"

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
    virtual void update(game::World* hello) = 0;

    /*
     *  Display entity on screen
     */
    virtual void render(game::Screen* screen) = 0;
};

}