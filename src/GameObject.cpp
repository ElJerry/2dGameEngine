#include "GameObject.hpp"
#include <TransformComponent.hpp>
#include <utility>

GameObject::GameObject(){
    m_componnents.resize(max_componnets);
    addComponent<TransformComponent>();
}

void GameObject::render(){
    for(Component* c : m_componnents){
        if(c!=NULL) c->render();
    }
}

void GameObject::update(){
    for(Component* c : m_componnents){
        if(c!=NULL) c->update();
    }
}
