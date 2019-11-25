#include "components/TransformComponent.hpp"


void TransformComponent::render(){
    // std::cout << "render from transfomComponent\n";
}

void TransformComponent::update(){
    speed.addVector(acceleration);
    position.addVector(speed);
}

void TransformComponent::handleEvents(){

}

void TransformComponent::info(){
    std::cout << "Transform component: position(" << position.toString() << ")\n";
}