#pragma once
#include <Component.hpp>
#include <SDL.h>
#include <Game.hpp>
#include <iostream>
#include <TransformComponent.hpp>
#include <TextureComponent.hpp>

using namespace std;

class RendererComponent : public Component {
private:
    TransformComponent *transform = NULL;
    TextureComponent *texture = NULL;
    
    SDL_Texture *m_texture = NULL;
    SDL_Rect sourceRect, destRect;
    SDL_Renderer *renderer = NULL;

public:
    RendererComponent(){
        // cout << "entre a renderer\n" ;
        renderer = Game::getRenderer();
        // cout << "Renderer grabed is " << renderer << endl;
        // std::cout << "RendererComponent created" << std::endl;
    }
    ~RendererComponent(){};

    void render() override;

    void update() override;

    SDL_Rect* getSourceRect();
    
};