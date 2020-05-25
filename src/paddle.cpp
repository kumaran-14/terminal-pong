/*
 * paddle.cpp
 */


#pragma once

#include "include/paddle.h"
#include "include/ncurses.h"

namespace world {
    void Paddle::Paddle();

    void Paddle::moveRight() {
        this.x += this.dx;
    };

    void Paddle::moveLeft() {
        this.x -= this.dx;
    };

    // should take world
    void Paddle::update() {
        if(this.x <= world.getStartX()) this.x = world.getStartX();
        if(this.x >= world.getEndX()) this.x = world.getEndX();
    }

    void Paddle::render(screen) {
        ncurses::draw(screen.draw(this.y, this.x, this.body));
    };
}