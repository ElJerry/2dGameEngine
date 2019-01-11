#pragma once
#include <Component.hpp>
#include <SDL.h>
#include <Game.hpp>
#include <iostream>

using namespace std;

class TextureComponent : public Component{
private:
    SDL_Texture *m_texture;
    char* texturePath;
    
public:

    TextureComponent(char *path){
        SDL_Surface *surface = SDL_LoadBMP(path);

        if(!surface){
            cout << "Error al crear surface\n";
            exit;
        }

        m_texture = SDL_CreateTextureFromSurface(Game::ren,surface);
        if(!m_texture){
            cout << "Error al crear la textura\n";
            exit;
        }

        SDL_FreeSurface(surface);
        texturePath = path;
        std::cout << "Created texture\n";
    }

    void info();

    SDL_Texture* getTexture();

};