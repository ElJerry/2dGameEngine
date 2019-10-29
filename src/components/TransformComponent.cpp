#include "components/TransformComponent.hpp"


void TransformComponent::render(){
    // std::cout << "render from transfomComponent\n";
}

void TransformComponent::update(){
    // std::cout << "update from transfomComponent\n";
    int ticks = SDL_GetTicks();
    
    speed.addVector(acceleration);
    position.addVector(speed);
}

void TransformComponent::handleEvents(){

}

void TransformComponent::info(){
    std::cout << "Transform component: position(" << position.toString() << ")\n";
}