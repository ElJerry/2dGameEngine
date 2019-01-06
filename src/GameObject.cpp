#include "GameObject.hpp"
#include <TransformComponent.hpp>

GameObject::GameObject(){
    m_componnents.resize(max_componnets);
    addComponent<TransformComponent>();
}


template <typename T>
bool GameObject::addComponent(){
    T *comp = new T();

    m_componnents[Component::getComponentID<T>()] = comp;
    
    return 1;
}



