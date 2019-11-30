#pragma once
#include <components/Component.hpp>
#include <SDL.h>
#include <Game.hpp>
#include <iostream>
#include <components/TransformComponent.hpp>
#include <components/TextureComponent.hpp>

using namespace std;

class RendererComponent : public Component {
private:
    TransformComponent *transform = nullptr;
    TextureComponent *texture = nullptr;
    
    SDL_Texture *m_texture = nullptr;
    SDL_Rect sourceRect = {0, 0};
    SDL_Renderer *renderer = nullptr;
    SDL_RendererFlip m_flip = SDL_FLIP_NONE;

public:
    SDL_Rect destRect = {0, 0};

    RendererComponent(){
        renderer = Game::getRenderer();
    }

    ~RendererComponent(){};

    void render() override;
    void updateRects();

    SDL_Rect* getSourceRect();
    
};