#pragma once
#include <vector>

// avoid ciclic compilation error
class GameObject;
#include <Component.hpp>

class GameObject {

private:
std::vector<Component*> m_componnents;
int max_componnets = 35;

public:

   GameObject();

   void update();
   void render();

   template <typename T>
   bool addComponent();

   /*template <typename T>
   T* getComponent();
   */
   
   template <typename T>
   inline T* getComponent(){
      int compId = Component::getComponentID<T>();
      auto *comp = m_componnents[compId];
      return static_cast<T*>(comp);
   }
};