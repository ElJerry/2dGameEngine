#include <Vector2D.hpp>
#include <sstream>
#include <cmath>

void Vector2D::setX(float x){
    xPos = x;
}

void Vector2D::setY(float y){
    yPos = y;
}

void Vector2D::setPos(float x, float y){
    xPos = x;
    yPos = y;
}

void Vector2D::addVector(const Vector2D &v){
    xPos += v.xPos;
    yPos += v.yPos;
}

void Vector2D::subtractVector(const Vector2D &v) {
    xPos -= v.xPos;
    yPos -= v.yPos;
}

void Vector2D::multiplyVector(float val) {
    xPos *= val;
    yPos *= val;
}

void Vector2D::divideVector(float val) {
    xPos /= val;
    yPos /= val;
}

float Vector2D::getX(){
    return xPos;
}

float Vector2D::getY(){
    return yPos;
}

float Vector2D::length() {
    return sqrt((xPos * xPos) + (yPos * yPos));
}

void Vector2D::normalize() {
    float l = length();
    if(l != 0) {
        xPos /= l;
        yPos /= l;
    }
}

void Vector2D::printVector(){
    std::cout << toString() << std::endl;
}

std::string Vector2D::toString(){

    std::stringstream str;
    str << "[" << xPos << "," << yPos << "]";
    return str.str();
}