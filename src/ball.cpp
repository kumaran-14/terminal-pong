/*
 * ball.cpp
 */

#pragma once

#include "include/ball.h"
#include "include/ncurses.h"

namespace world {
    void Ball::Ball();


    // should take world as dependency
    void Ball::update() {
        // move ball
        this.x += this.dx;
        this.y += this.dy;

        // check for end of world collisions.
        if(this.x <= world.getStartX()) {
            this.x = world.getStartX();
            this.dx = -this.dx;
        } else if(this.x >= world.getEndX()) {
            this.x = world.getEndX();
            this.dx = -this.dx;
        }
        if(this.y <= world.getStartY()) {
            this.y = world.getStartY();
            this.dy = -this.dy;
        } else if(this.y >= world.getEndY()) {
            this.y = world.getEndY();
            this.dy = -this.dy;
        }

         world.resolveCollisions(ball.x, ball.y)

    }

    void Ball::render(screen) {
        ncurses::draw(screen.draw(this.y, this.x, this.body));
    };
}