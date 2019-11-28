//
// Created by jerry on 06/11/19.
//

#include <gameObject/Player.h>
#include <components/TextureComponent.hpp>
#include <components/ControllerComponent.h>
#include <components/RigidBodyComponent.h>
#include <components/SpriteAnimatorComponent.hpp>
#include <components/ColliderComponent.h>

void onCollision(GameObject* me, GameObject* other){
    std::cout << "THE CALLBACK IS WORKING!! HIT " << other->getName() <<"\n";
    auto meTransform = me->getComponent<TransformComponent>();
    auto meCollider = me->getComponent<ColliderComponent>();

    auto otherTransform = other->getComponent<TransformComponent>();
    auto otherCollider = other->getComponent<ColliderComponent>();

    // check left
    if (meTransform->position.getX() < otherTransform->position.getX()) {
        int diff = (meCollider->colliderRect.x + meCollider->colliderRect.w) - otherCollider->colliderRect.x;
        if (diff < 3){
            meTransform->position.setX(
                    meCollider->colliderRect.x - (diff)
            );
        }
    }

    // check right
    if ((meTransform->position.getX() + meCollider->colliderRect.w ) > otherTransform->position.getX() + otherCollider->colliderRect.w) {
        int diff = (otherCollider->colliderRect.x + otherCollider->colliderRect.w) - (meCollider->colliderRect.x);
        if (diff < 3) {
            meTransform->position.setX(
                    meTransform->position.getX() + (diff)
            );
        }
    }

    // check top
    if (meTransform->position.getY() < otherTransform->position.getY()) {
        int diff = (meTransform->position.getY() + meCollider->colliderRect.h ) - (otherTransform->position.getY());
        if (diff < 3) {
            meTransform->position.setY(
                    (meTransform->position.getY()) - (diff)
            );
        }
    }

    // check bottom
    if ((meTransform->position.getY() + meCollider->colliderRect.h) > (otherTransform->position.getY() + otherCollider->colliderRect.h)){
        int diff = (otherTransform->position.getY() + otherCollider->colliderRect.h) - meTransform->position.getY();
        if (diff < 3) {
            meTransform->position.setY(
                    meTransform->position.getY() + (diff)
            );
        }
    }
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
