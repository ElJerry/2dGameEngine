#include <Vector2D.hpp>
#include <sstream>

void Vector2D::setX(int x){
    xPos = x;
}

void Vector2D::setY(int y){
    yPos = y;
}

void Vector2D::setPos(int x, int y){
    xPos = x;
    yPos = y;
}

void Vector2D::addVector(Vector2D v){
    xPos += v.getX();
    yPos += v.getY();
}

int Vector2D::getX(){
    return xPos;
}

int Vector2D::getY(){
    return yPos;
}

void Vector2D::printVector(){
    std::cout << toString() << std::endl;
}

std::string Vector2D::toString(){

    std::stringstream str;
    str << "[" << xPos << "," << yPos << "]";
    return str.str();
}