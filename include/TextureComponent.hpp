#pragma once
#include <Component.hpp>
#include <SDL.h>
#include <Game.hpp>
#include <iostream>

class TextureComponent : public Component{
private:
    SDL_Texture *m_texture;
    char* texturePath;
public:

    TextureComponent(char *path){
        SDL_Surface *surface = SDL_LoadBMP(path);
        m_texture = SDL_CreateTextureFromSurface(Game::ren,surface);
        SDL_FreeSurface(surface);
        texturePath = path;
    }

    void info(){
        std::cout << "texture path: " << texturePath << std::endl;
    }
};