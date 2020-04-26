#ifndef SCRIPT_ANIMATIONSCRIPTSELECTOR_H
#define SCRIPT_ANIMATIONSCRIPTSELECTOR_H

#include <GameScripts/GameScript.h>
#include <components/TransformComponent.hpp>
#include <components/SpriteAnimatorComponent.hpp>

class AnimationSpriteSelector : public GameScript {
private:
    
public:
    void update() override {
        auto transform = gameObject->getComponent<TransformComponent>();
        auto animator = gameObject->getComponent<SpriteAnimatorComponent>();

        if (transform->speed.getX() > 0) {
            animator->setRow(2);
        }

        if (transform->speed.getX() < 0) {
            animator->setRow(3);
        }

        if (transform->speed.getY() > 0) {
            animator->setRow(1);
        }

        if (transform->speed.getY() < 0) {
            animator->setRow(0);
        }

        Vector2D zero;
        if (transform->speed.length() == 0) {
            animator->animate(false);
        }
        else {
            animator->animate(true);
        }
    }
};

#endif // SCRIPT_ANIMATIONSCRIPTSELECTOR_H