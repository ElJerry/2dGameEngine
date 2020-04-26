#pragma once
#include <components/Component.hpp>
#include <iostream>
#include <SDL.h>
#include <Vector2D.hpp>

class TransformComponent: public Component {
private:
public:
    Vector2D position;
    Vector2D acceleration;
    Vector2D speed;

    TransformComponent()= default;

    void update() override;
    void info();
};