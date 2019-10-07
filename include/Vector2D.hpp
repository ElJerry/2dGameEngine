#pragma once
#include <sstream>
#include <string.h>
#include <iostream>

class Vector2D{
private:
    float xPos, yPos;

public:

    Vector2D(){
        xPos = yPos = 0;
    }

    Vector2D(float x, float y){
        xPos = x;
        yPos = y;
    }

    void setX(float x);
    void setY(float y);
    void setPos(float x, float y);
    float getX();
    float getY();

    float length();

    void normalize();
    void addVector(const Vector2D &v);
    void subtractVector(const Vector2D &v);
    void multiplyVector(float val);
    void divideVector(float val);


    void printVector();
    std::string toString();
};