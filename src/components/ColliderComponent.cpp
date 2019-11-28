#include <components/ColliderComponent.h>
#include <components/TransformComponent.hpp>
#include <collision/CollisionManager.h>

std::unordered_set<ColliderComponent*> ColliderComponent::colliders;

ColliderComponent::ColliderComponent(int w, int h, onCollisionCallback callback) {
    colliders.insert(this);
    colliderRect.w = w;
    colliderRect.h = h;
    onCollision = callback;
}

ColliderComponent::~ColliderComponent() {
    colliders.erase(this);
}

void ColliderComponent::update() {

    if (!m_transform) {
        // attempt to get the transform from the object
        m_transform = gameObject->getComponent<TransformComponent>();

        if (!m_transform) {
            // return if no transform was found
            return;
        }
    }

    // Update collider rect position
    colliderRect.x = m_transform->position.getX();
    colliderRect.y = m_transform->position.getY();

    // check if is colliding with another collider
    for ( auto c : colliders){

        // ignore self collider
        if (this == c)
            continue;

        if (areColliding(&colliderRect, &c->colliderRect)){
            std::cout << gameObject->getName() <<" colliding with " << c->gameObject->getName() << std::endl;
            // Execute callback if exists
            if (onCollision != nullptr){
                onCollision(gameObject, c->gameObject);
            }
        }
    }


}
