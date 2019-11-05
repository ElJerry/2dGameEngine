#include <components/ControllerComponent.h>
#include <components/TransformComponent.hpp>

ControllerComponent::ControllerComponent() {
}

ControllerComponent::~ControllerComponent() {}

void ControllerComponent::handleEvents(SDL_Event event) {
    switch(event.type){
        case SDL_KEYDOWN:
        {
            int speedDelta = 2;
            switch(event.key.keysym.sym) {
                case SDLK_d:
                    m_speed->setX(speedDelta);
                    break;
                case SDLK_a:
                    m_speed->setX(-speedDelta);
                    break;
                case SDLK_w:
                    m_speed->setY(-speedDelta);
                    break;
                case SDLK_s:
                    m_speed->setY(+speedDelta);
                    break;
            }
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



