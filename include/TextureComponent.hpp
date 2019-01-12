#pragma once
#include <Component.hpp>
#include <SDL.h>
#include <Game.hpp>
#include <iostream>
#include <SDL_image.h>

using namespace std;

class TextureComponent : public Component{
private:
    SDL_Texture *m_texture;
    char* texturePath;
    
public:

    TextureComponent(char *path){
       
        m_texture = IMG_LoadTexture(Game::ren,path);
        if(!m_texture){
            cout << "Error al crear la textura\n";
            exit;
        }
        
        texturePath = path;
        std::cout << "Created texture\n";
    }

    void info();

    SDL_Texture* getTexture();

};