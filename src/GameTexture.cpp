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
    m_targetRectangle.x = (m_targetRectangle.x + 1) % 800;
    m_targetRectangle.y = (m_targetRectangle.y + 1) % 600;
}