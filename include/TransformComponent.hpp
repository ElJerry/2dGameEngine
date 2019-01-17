#pragma once
#include <Component.hpp>
#include <iostream>
#include <SDL.h>
#include <Vector2D.hpp>

class TransformComponent: public Component {
private:
public:
    Vector2D position;
    Vector2D acceleration;
    Vector2D speed;

    TransformComponent(){}

    void render() ;
    void update() ;
    void handleEvents() ;
    void info();
};