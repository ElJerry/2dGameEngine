#include "GameObject.hpp"
#include <TransformComponent.hpp>
#include <utility>

std::vector<GameObject*> GameObject::gameObjects;

GameObject::GameObject(char* name){
    m_name = name;
    m_componnents.resize(max_componnets);
    // all gameobjects must have a transform component
    addComponent<TransformComponent>();   

    gameObjects.push_back(this);
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
    for(GameObject* g : gameObjects){
        if(strcmp(name, g->m_name)==0){
            return g;
        }
    }
    return NULL;
}