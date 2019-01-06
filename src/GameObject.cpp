#include "GameObject.hpp"
#include <TransformComponent.hpp>
#include <utility>

GameObject::GameObject(){
    m_componnents.resize(max_componnets);
    addComponent<TransformComponent>();
}

void GameObject::render(){

}
