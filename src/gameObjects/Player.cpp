//
// Created by jerry on 06/11/19.
//

#include <gameObject/Player.h>
#include <components/TextureComponent.hpp>
#include <components/ControllerComponent.h>
#include <components/SpriteAnimatorComponent.hpp>

Player::Player(char *name) : GameObject(name) {
    this->addComponent<TextureComponent>("assets/male_sprite_model.png");
    this->addComponent<RendererComponent>();
    this->addComponent<SpriteAnimatorComponent>(4,8,32,64);
    auto animator = this->getComponent<SpriteAnimatorComponent>();
    animator->setRow(1);
    animator->setColumnsInRow(0, 5);
    animator->setColumnsInRow(1, 5);
    animator->animate(false);
    this->addComponent<ControllerComponent>();
}

Player::~Player() {
    for (auto component : this->m_componnents){
        delete component;
    }
}
