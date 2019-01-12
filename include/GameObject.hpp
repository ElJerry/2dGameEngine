#pragma once
#include <vector>
#include <ComponentIdentifier.hpp>
#include <string.h>

// avoid ciclic compilation error
class Component;

#include <Component.hpp>

class GameObject {

private:
   std::vector<Component*> m_componnents;
   int max_componnets = 35;

   static std::vector<GameObject*> gameObjects;
   char* m_name = NULL;


public:


   void update();
   void render();
   void listComponents();
   char* getName();
   
   // static methods
   static GameObject* find(char* name);

   GameObject(char* name);


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