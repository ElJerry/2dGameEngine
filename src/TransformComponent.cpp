#include "TransformComponent.hpp"


void TransformComponent::render(){
    // std::cout << "render from transfomComponent\n";
}

void TransformComponent::update(){
    // std::cout << "update from transfomComponent\n";
}

void TransformComponent::handleEvents(){

}

void TransformComponent::info(){
    std::cout << "Transform component: " << xPos << "," << yPos << std::endl;
}

void TransformComponent::setPos(int x, int y){
    xPos = x;
    yPos = y;
}

int TransformComponent::getX(){
    return xPos;
}

int TransformComponent::getY(){
    return yPos;
}