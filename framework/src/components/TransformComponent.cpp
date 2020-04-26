#include "components/TransformComponent.hpp"

void TransformComponent::update(){
    speed.addVector(acceleration);
    position.addVector(speed);
}

void TransformComponent::info(){
    std::cout << "Transform component: position(" << position.toString() << ")\n";
}