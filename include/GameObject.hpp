#pragma once
#include <vector>
#include <ComponentIdentifier.hpp>

// avoid ciclic compilation error
class Component;

#include <Component.hpp>

class GameObject {

private:
std::vector<Component*> m_componnents;
int max_componnets = 35;

public:

   GameObject();

   void update();
   void render();

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