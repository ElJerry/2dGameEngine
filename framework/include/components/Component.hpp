#pragma once

// avoid ciclic compilation error
class GameObject;
#include <GameObject.hpp>
#include <SDL_events.h>

class Component {
protected:
    GameObject* gameObject = nullptr;

public:
    Component(){};
    ~Component(){};

    virtual void render();
    virtual void update();
    virtual void handleEvents(SDL_Event);

    void setGameObject(GameObject* gO);

    GameObject* getGameObject();

    // Events
    virtual void onCollisionEvent(GameObject* other);
};