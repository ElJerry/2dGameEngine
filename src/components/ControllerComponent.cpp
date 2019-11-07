#include <components/ControllerComponent.h>
#include <components/TransformComponent.hpp>
#include <components/SpriteAnimatorComponent.hpp>

ControllerComponent::ControllerComponent() {
}

ControllerComponent::~ControllerComponent() {}

void ControllerComponent::handleEvents(SDL_Event event) {
    auto animator = gameObject->getComponent<SpriteAnimatorComponent>();
    switch(event.type){
        case SDL_KEYDOWN:
        {
            int speedDelta = 2;
            switch(event.key.keysym.sym) {
                case SDLK_d:
                    m_speed->setX(speedDelta);
                    // set character facing left
                    animator->setRow(2);
                    animator->setBounce(false);
                    break;
                case SDLK_a:
                    m_speed->setX(-speedDelta);
                    // set character facing right
                    animator->setRow(3);
                    animator->setBounce(false);
                    break;
                case SDLK_w:
                    m_speed->setY(-speedDelta);
                    // set character facing up
                    animator->setRow(0);
                    animator->setBounce(true);
                    break;
                case SDLK_s:
                    m_speed->setY(+speedDelta);
                    // set character facing down
                    animator->setRow(1);
                    animator->setBounce(true);
                    break;
            }
            animator->animate(true);
            break;
        }
        case SDL_KEYUP:
        {
            switch(event.key.keysym.sym) {
                case SDLK_d:
                    m_speed->setX(0);
                    break;
                case SDLK_a:
                    m_speed->setX(0);
                    break;
                case SDLK_w:
                    m_speed->setY(0);
                    break;
                case SDLK_s:
                    m_speed->setY(0);
                    break;
            }
            animator->animate(false);
            break;
        }
    }
}

void ControllerComponent::update() {
    if(!m_speed){
        std::cout << "setting speed" << std::endl;
        m_speed = &gameObject->getComponent<TransformComponent>()->speed;
    }
}

void ControllerComponent::render() {}



