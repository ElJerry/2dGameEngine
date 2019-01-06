#pragma once

// avoid ciclic compilation error
class GameObject;
#include <GameObject.hpp>


class Component {

private:

    GameObject* gameObject;

public:
    Component(){};

    virtual void render();
    virtual void update();
    virtual void handleEvents();

    void setGameObject(GameObject* gO){
        gameObject = gO;
    }

    GameObject* getGameObject(){
        return gameObject;
    }
};