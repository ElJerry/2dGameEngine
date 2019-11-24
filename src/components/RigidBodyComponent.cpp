#include <components/RigidBodyComponent.h>

using namespace std;

RigidBodyComponent::RigidBodyComponent(GameObject* go) {
     cout << "Creando rigid\n";
    transform = go->getComponent<TransformComponent>();
    if (!transform) {
        std::cout << go->getName() << " rigidbody: Error, no transform present in gameobject\n";
        // close application
        exit(1);
    }

    // Set gravity
    gravity.setX(0);
    gravity.setY(.1);
}

void RigidBodyComponent::update() {
    transform->acceleration.addVector(gravity);
}

void RigidBodyComponent::render(){}

void RigidBodyComponent::handleEvents(){}