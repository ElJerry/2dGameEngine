#include "GameObject.hpp"
#include <components/TransformComponent.hpp>
#include <utility>

std::vector<GameObject*> GameObject::gameObjects;
std::map<char*, GameObject*> GameObject::gameObjectsMap;

GameObject::GameObject(char* name){
    m_name = name;
    m_componnents.resize(max_componnets);

    // make component array filled with nullptr
    for(int i=0 ; i < max_componnets ; i++){
        m_componnents[i] = nullptr;
    }
    // all game objects must have a transform component
    addComponent<TransformComponent>();   

    gameObjects.push_back(this);
    gameObjectsMap[name] = this;
}

void GameObject::render(){
    for(Component* c : m_componnents){
        if(c) c->render();
    }
}

void GameObject::update(){
    for(Component* c : m_componnents){
        if(c) c->update();
    }
}

void GameObject::listComponents(){
    int cnt = 0;

    for (Component* c : m_componnents)
        if(c) cnt++;

    std::cout << "GameObject contains " << cnt << " components\n";    
}

char* GameObject::getName(){
    return m_name;
}

GameObject* GameObject::find(char* name){
    return gameObjectsMap[name];
}

GameObject* GameObject::addGameObject(char* name){
    return new GameObject(name);
}

std::vector<GameObject*> GameObject::getGameObjects(){
    return gameObjects;
}