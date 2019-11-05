#include "components/Component.hpp"

void Component::render(){}

void Component::update(){}

void Component::handleEvents(SDL_Event){}

GameObject* Component::getGameObject(){
    return gameObject;
}

void Component::setGameObject(GameObject *gO){
    gameObject = gO;
}