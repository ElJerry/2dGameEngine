#include <camera/Camera.h>
#include <components/TransformComponent.hpp>

GameObject* Camera::centeredObject;
Vector2D Camera::game_camera_offset;

int centerX = 400;
int centerY = 300;

void Camera::setCenteredObject(GameObject* gO) {
    centeredObject = gO;
}

Vector2D Camera::getOffset() {
    return game_camera_offset;
}

void Camera::calculateOffsets() {
    // game_camera_offset

    int offsetX = centeredObject->getComponent<TransformComponent>()->position.getX() - centerX;
    int offsetY = centeredObject->getComponent<TransformComponent>()->position.getY() - centerY;

    game_camera_offset = {offsetX, offsetY};

    std::cout << "current offset " << game_camera_offset.getX() << "," << game_camera_offset.getY() << std::endl;
}
