#include "GameTexture.hpp"
#include "Game.hpp"
#include <iostream>

GameTexture::GameTexture(char* path, SDL_Renderer *renderer){
    SDL_Surface *surface = SDL_LoadBMP(path);
    if(!surface){
        std::cout << "Surface creation failed: " << SDL_GetError() << std::endl;
        return;
    }
    
    this->renderer = renderer;
    m_texture = SDL_CreateTextureFromSurface(renderer,surface);
    SDL_FreeSurface(surface);

    SDL_QueryTexture(m_texture,NULL,NULL,&m_sourceRectangle.w,&m_sourceRectangle.h);
    m_targetRectangle.h = m_sourceRectangle.h;
    m_targetRectangle.w = m_sourceRectangle.w;
    m_targetRectangle.x = m_targetRectangle.y = m_sourceRectangle.x = m_sourceRectangle.y = 0;
}

void GameTexture::render(){
    SDL_RenderCopy(renderer,m_texture,&m_sourceRectangle,&m_targetRectangle);
}

void GameTexture::update(){
    
}

void GameTexture::setSourceRecProp(GameTexture::RectProp prop, int val){
    
    switch(prop){
        case RectProp::X_POS:
            m_sourceRectangle.x = val;
            break;
        case RectProp::Y_POS:
            m_sourceRectangle.y = val;
            break;
        case RectProp::HEIGHT:
            m_sourceRectangle.h = val;
            break;  
        case RectProp::WITDH:
            m_sourceRectangle.w = val;
            break;
        default:
            //Not implemented
            break;
    }
}

void GameTexture::setTargetRecProp(GameTexture::RectProp prop, int val){
    
    switch(prop){
        case RectProp::X_POS:
            m_targetRectangle.x = val;
            break;
        case RectProp::Y_POS:
            m_targetRectangle.y = val;
            break;
        case RectProp::HEIGHT:
            m_targetRectangle.h = val;
            break;  
        case RectProp::WITDH:
            m_targetRectangle.w = val;
            break;
        default:
            //Not implemented
            break;
    }
}