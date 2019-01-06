#pragma once

// avoid ciclic compilation error
class Component;
//#include <GameObject.hpp>

class Component {

private:

    //GameObject *gameObject;

    static int getNewID(){
        static int id = 0;
        return id++;
    }

public:
    Component(){};

    template <typename T>
    static int getComponentID(){
        static int compId = getNewID();
        return compId;
    }   

    virtual void render();
    virtual void update();
    virtual void handleEvents();

};