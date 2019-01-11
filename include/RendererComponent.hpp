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
    SDL_Renderer *renderer;
    TransformComponent *transform;
    TextureComponent *texture;
    SDL_Texture *m_texture;

    SDL_Rect sourceRect, destRect;

public:
    RendererComponent(){
        // cout << "entre a renderer\n" ;
        renderer = Game::getRenderer();
        // cout << "Renderer grabed is " << renderer << endl;
        // std::cout << "RendererComponent created" << std::endl;
    }
    ~RendererComponent(){};

    void render() override{
        // std::cout << "Rendering" << std::endl;
        SDL_RenderCopy(renderer,m_texture,&sourceRect,&destRect);
    }

    void update() override{
        //make sure all required components are loaded and referenced
        // texture component
        if(texture==NULL){
            texture = gameObject->getComponent<TextureComponent>();
            m_texture = texture->getTexture();
            //load size of texture into sourceRect
            SDL_QueryTexture(m_texture,NULL,NULL,
                             &sourceRect.w,&sourceRect.h);
            
            sourceRect.x = sourceRect.y = 0;
        }

        // transform component
        if(transform==NULL){
            transform = gameObject->getComponent<TransformComponent>();
        }

        //update destRec x and y with transform component
        destRect.x = transform->getX();
        destRect.y = transform->getY();
        destRect.w = sourceRect.w;
        destRect.h = sourceRect.h;

    }
    
};