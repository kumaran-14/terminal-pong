/*
 * ball.h
 * Defines Ball class
 */

#pragma once

#include "i_entity.h"

namespace world {

    class Ball: public IEntity {

    public:
        Ball();

        void update() override;

        void render() override;

    private:

        double y, x, dx, dy;

        int length;

        string body;

    };

} // world