
#include <gameObject/Floor.h>
#include <components/TextureComponent.hpp>
#include <components/RendererComponent.hpp>
#include <collision/CollisionManager.h>
#include <sstream>

Floor::Floor(char *name, int posX, int posY) : GameObject(name) {


    for(int x=0 ; x < 4 ; x++){
        stringstream ss;
        ss << name << "FloorTile";
        string s = ss.str();
        char *arrName = new char[s.size()+1];
        strcpy(arrName, s.c_str());
        cout << arrName << endl;

        GameObject* floorTile = new GameObject(arrName);
        floorTile->addComponent<TextureComponent>("assets/floor.png");
        floorTile->addComponent<RendererComponent>();
        auto transform = floorTile->getComponent<TransformComponent>();

        transform->position.setX((32*x) + posX);
        transform->position.setY(posY);
        // TODO: this should not be calling the update function directly
        floorTile->update();
        objects.push_back(floorTile);
    }

    this->getComponent<TransformComponent>()->position = Vector2D(posX, posY);
}

void Floor::update() {
    /*
    // Update position of the floor - should be static anyways
    float posX = this->getComponent<TransformComponent>()->position.getX();
    float posY = this->getComponent<TransformComponent>()->position.getY();
    for(int i = 0; i < objects.size(); i++){
        auto objectPos = objects[i]->getComponent<TransformComponent>();
        objectPos->position.setX((32*i) + posX);
        objectPos->position.setY(posY);
    }*/

    // check if colliding
    auto player = GameObject::find("Player");
    auto playerPosition = &player->getComponent<TransformComponent>()->position;
    auto playerRendererComp = player->getComponent<RendererComponent>();
    if(!playerRendererComp){
        cout << "no player found" << endl;
        exit(1);
    }

    for(int i=0 ; i < objects.size(); i++){
        auto tile = objects[i];
        auto tileRenderer = tile->getComponent<RendererComponent>();
        auto tilePosition = tile->getComponent<TransformComponent>()->position;

        if (areColliding(&playerRendererComp->destRect, &tileRenderer->destRect)){
            cout << "Collided!!!!!!!" << endl;

            int deltaY = playerPosition->getY() - tilePosition.getY();
            int toPos = (playerPosition->getY() - deltaY) - playerRendererComp->destRect.h + 1;
            playerPosition->setY(toPos);
            auto playerTransform = player->getComponent<TransformComponent>();
            playerTransform->acceleration.setY(0);
            playerTransform->speed.setY(0);
        }
        else {
            cout << "Not colliding" << endl;
        }
    }
}