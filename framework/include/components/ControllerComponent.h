#ifndef CONTROLLERCOMPONENT_H
#define CONTROLLERCOMPONENT_H

#include "Component.hpp"
#include <Vector2D.hpp>

class ControllerComponent : public Component {
private:
    // this component requires transform component
    Vector2D* m_speed = nullptr;
public:
    ControllerComponent();
    ~ControllerComponent();

    void update() override;
    void handleEvents(SDL_Event) override;
};
#endif
