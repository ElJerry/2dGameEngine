#pragma once

#include <vector>
#include <components/ComponentIdentifier.hpp>
#include <string.h>
#include <map>
#include <string>
#include <SDL.h>

// avoid cyclic compilation error
class Component;

#include <components/Component.hpp>

class GameObject {
protected:
    std::vector<Component*> m_componnents;
private:
    int max_componnets = 35;

    static std::vector<GameObject*> gameObjects;
    static std::map<char*, GameObject*> gameObjectsMap;
    char* m_name = NULL;

public:

    GameObject(char* name);


    virtual void update();
    void render();
    void handleEvents(SDL_Event);
    void listComponents();
    char* getName();

    // static methods
    static GameObject* find(char* name);

    static std::vector<GameObject*> getGameObjects();
    static GameObject* addGameObject(char* name);
    static bool removeGameObject(char* name);



    // Template Zone - adding implementation in header file for templates

    /*
      Each time you add a component of a certain type, if other one already
      exists, it will be overwritten and the older data will be lost
    */
    template <typename T, typename... TArgs>
    bool addComponent(TArgs&&... mArgs){
      T *comp = new T(std::forward<TArgs>(mArgs)...);
      Component *c = static_cast<Component*>(comp);
      c->setGameObject(this);

      m_componnents[ComponentIdentifier::getComponentID<T>()] = comp;

      return 1;
    }

    template <typename T>
    inline T* getComponent(){
      int compId = ComponentIdentifier::getComponentID<T>();
      auto *comp = m_componnents[compId];
      return static_cast<T*>(comp);
    }
};