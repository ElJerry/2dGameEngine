#ifndef GAME_CAMERA_H
#define GAME_CAMERA_H

#include <Vector2D.hpp>
#include <GameObject.hpp>

class Camera {
private:
    static GameObject* centeredObject;
    static Vector2D game_camera_offset;

public:
    static void setCenteredObject(GameObject* gO);
    static void calculateOffsets();
    static Vector2D getOffset();
};

#endif // GAME_CAMERA_H