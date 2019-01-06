#include "GameObject.hpp"
#include <TransformComponent.hpp>

GameObject::GameObject(){
    m_componnents.resize(max_componnets);
    addComponent<TransformComponent>();
}

template <typename T>
bool GameObject::addComponent(){
    T *comp = new T();
    Component *c = static_cast<Component*>(comp);

    c->setGameObject(this);

    m_componnents[ComponentIdentifier::getComponentID<T>()] = comp;
    
    return 1;
}


void GameObject::render(){

}
