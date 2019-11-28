//
// Created by jerry on 06/11/19.
//

#include <gameObject/Player.h>
#include <components/TextureComponent.hpp>
#include <components/ControllerComponent.h>
#include <components/RigidBodyComponent.h>
#include <components/SpriteAnimatorComponent.hpp>
#include <components/ColliderComponent.h>

void onCollision(GameObject* other){
    std::cout << "THE CALLBACK IS WORKING!!\n";
}

Player::Player(char *name) : GameObject(name) {
    this->addComponent<TextureComponent>("assets/male.png");
    this->addComponent<RendererComponent>();
    this->addComponent<SpriteAnimatorComponent>(4,8,32,64);
    auto animator = this->getComponent<SpriteAnimatorComponent>();
    animator->setRow(1);
    animator->setColumnsInRow(0, 5);
    animator->setColumnsInRow(1, 5);
    animator->animate(false);
    this->addComponent<ControllerComponent>();
//    this->addComponent<RigidBodyComponent>(this);

    this->addComponent<ColliderComponent>(32,60, onCollision);
}

Player::~Player() {
    for (auto component : this->m_componnents){
        delete component;
    }
}
