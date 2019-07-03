#include "GameObject.hpp"
#include <TransformComponent.hpp>
#include <utility>

std::vector<GameObject*> GameObject::gameObjects;
std::map<char*, GameObject*> GameObject::gameObjectsMap;
GameObject::GameObject(char* name){
    m_name = name;
    m_componnents.resize(max_componnets);
    // all gameobjects must have a transform component
    addComponent<TransformComponent>();   

    gameObjects.push_back(this);
    gameObjectsMap[name] = this;
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

void GameObject::listComponents(){
    int cnt = 0;

    for (Component* c : m_componnents)
        if(c != NULL) cnt++;

    std::cout << "GameObject contains " << cnt << " components\n";    
}

char* GameObject::getName(){
    return m_name;
}

GameObject* GameObject::find(char* name){
    return gameObjectsMap[name];
}

GameObject* GameObject::addGameObject(char* name){
    GameObject* go = new GameObject(name);
    return go;
}

std::vector<GameObject*> GameObject::getGameObjects(){
    return gameObjects;
}