#pragma once

// avoid ciclic compilation error
class GameObject;
#include <GameObject.hpp>


class Component {

protected:

    GameObject* gameObject;

public:
    Component(){};
    ~Component(){};

    virtual void render();
    virtual void update();
    virtual void handleEvents();

    void setGameObject(GameObject* gO);

    GameObject* getGameObject();
};