#ifndef INC_2DGAMETEST_RIGIDBODYCOMPONENT_H
#define INC_2DGAMETEST_RIGIDBODYCOMPONENT_H

#include <Vector2D.hpp>
#include "Component.hpp"
#include "TransformComponent.hpp"

class RigidBodyComponent : public Component {
private:
    TransformComponent *transform;
public:
    Vector2D gravity;

    RigidBodyComponent(GameObject* go);

    void update() override;
};

#endif //INC_2DGAMETEST_RIGIDBODYCOMPONENT_H
