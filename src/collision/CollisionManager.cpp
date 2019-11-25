//
// Created by jerry on 24/11/19.
//

#include <collision/CollisionManager.h>
#include <iostream>

bool areColliding(SDL_Rect* rectA, SDL_Rect* rectB){
    // sides of a
    int leftA = rectA->x;
    int rightA = rectA->x + rectA->w;
    int topA = rectA->y;
    int bottomA = rectA->y + rectA->h;

    // sides of b
    int leftB = rectB->x;
    int rightB = rectB->x + rectB->w;
    int topB = rectB->y;
    int bottomB = rectB->y + rectB->h;

    // check if sides are colliding
    if (rightB <= leftA){
        return false;
    }

    if (rightA <= leftB){
        return false;
    }

    if (bottomB <= topA){
        return false;
    }

    if (bottomA <= topB){
        return false;
    }

    return true;
}