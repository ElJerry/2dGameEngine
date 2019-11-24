
#include <gameObject/Floor.h>
#include <components/TextureComponent.hpp>
#include <components/RendererComponent.hpp>
#include <collision/CollisionManager.h>
#include <sstream>

Floor::Floor(char *name) : GameObject(name) {
    int x = 4;
    while(x--){
        stringstream ss;
        ss << name << "FloorTile";
        string s = ss.str();
        char *arrName = new char[s.size()+1];
        strcpy(arrName, s.c_str());
        cout << arrName << endl;

        GameObject* f1 = new GameObject(arrName);
        f1->addComponent<TextureComponent>("assets/floor.png");
        f1->addComponent<RendererComponent>();
        objects.push_back(f1);
    }
}

void Floor::update() {
    // Update position of the floor - should be static anyways
    float posX = this->getComponent<TransformComponent>()->position.getX();
    float posY = this->getComponent<TransformComponent>()->position.getY();
    for(int i = 0; i < objects.size(); i++){
        auto objectPos = objects[i]->getComponent<TransformComponent>();
        objectPos->position.setX((32*i) + posX);
        objectPos->position.setY(posY);
    }
}