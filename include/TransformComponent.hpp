#pragma once
#include <Component.hpp>
#include <iostream>

class TransformComponent: public Component {
private:
    int xPos, yPos;

public:

    void render() ;
    void update() ;
    void handleEvents() ;

    void info();

    void setPos(int x, int y);
};