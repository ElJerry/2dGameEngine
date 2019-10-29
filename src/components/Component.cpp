#include "components/Component.hpp"

void Component::render(){}

void Component::update(){}

void Component::handleEvents(){}

GameObject* Component::getGameObject(){
    return gameObject;
}

void Component::setGameObject(GameObject *gO){
    gameObject = gO;
}