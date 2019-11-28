#ifndef INC_2DGAMETEST_COLLIDERCOMPONENT_H
#define INC_2DGAMETEST_COLLIDERCOMPONENT_H

#include "Component.hpp"
#include "TransformComponent.hpp"
#include <SDL.h>
#include <unordered_set>

typedef void(*onCollisionCallback)(GameObject* other);

class ColliderComponent : public Component{
private:
    static std::unordered_set<ColliderComponent*> colliders;
    TransformComponent* m_transform = nullptr;

public:
    ColliderComponent(int w, int h, onCollisionCallback callback);
    ~ColliderComponent();

    SDL_Rect colliderRect;

    void update() override;

    // callback for collisions
    onCollisionCallback onCollision = nullptr;
};

#endif //INC_2DGAMETEST_COLLIDERCOMPONENT_H
