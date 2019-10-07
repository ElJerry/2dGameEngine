#pragma once
#include <sstream>
#include <string.h>
#include <iostream>

class Vector2D{
private:
    int xPos, yPos;

public:

    Vector2D(){
        xPos = yPos = 0;
    }

    Vector2D(int x, int y){
        xPos = x;
        yPos = y;
    }

    void setX(int x);
    void setY(int y);
    void setPos(int x, int y);
    int getX();
    int getY();

    float length();
    void addVector(Vector2D v);

    void printVector();
    std::string toString();
};