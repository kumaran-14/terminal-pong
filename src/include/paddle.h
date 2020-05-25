/*
 * paddle.h
 * Defines Paddle class
 */

#pragma once

#include "i_entity.h"

namespace world {

class Paddle: public IEntity {

public:
    Paddle();

    void moveRight();

    void moveLeft();

    void update() override;

    void render() override;

private:

    double y, x, dx, dy;

    int length;

    string body;

};

} // world