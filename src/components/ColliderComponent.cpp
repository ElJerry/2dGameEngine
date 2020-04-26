#include <components/ColliderComponent.h>
#include <components/TransformComponent.hpp>
#include <collision/CollisionManager.h>

std::unordered_set<ColliderComponent*> ColliderComponent::colliders;

ColliderComponent::ColliderComponent(int w, int h, onCollisionCallback callback = nullptr) {
    colliders.insert(this);
    colliderRect.w = w;
    colliderRect.h = h;
    onCollision = callback;
}

ColliderComponent::~ColliderComponent() {
    // remove this collider from the list of colliders in the game
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
    for ( auto collider : colliders){

        // ignore self collider
        if (this == collider)
            continue;

        if (areColliding(&colliderRect, &collider->colliderRect)){
            std::cout << gameObject->getName() << " colliding with " << collider->gameObject->getName() << std::endl;
            // Execute callback if exists
            if (onCollision) { // if callback exists
                onCollision(gameObject, collider->gameObject);
            }

            for(auto component : gameObject->m_componnents) {
                if (component) { // if component exists
                    component->onCollisionEvent(collider->gameObject);
                }
            }
        }
    }
}
