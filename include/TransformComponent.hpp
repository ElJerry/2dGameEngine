#pragma once
#include <Component.hpp>
#include <iostream>

class TransformComponent: public Component {
private:
    int xPos, yPos;

public:
    TransformComponent(){
        xPos = yPos = 0;
    }

    void render() ;
    void update() ;
    void handleEvents() ;
    void info();
    void setPos(int x, int y);
    void addX(int x);
    void addY(int y);
    int getX();
    int getY();
};