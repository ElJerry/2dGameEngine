#include "TransformComponent.hpp"


void TransformComponent::render(){

}

void TransformComponent::update(){

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