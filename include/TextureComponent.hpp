#pragma once
#include <Component.hpp>
#include <SDL.h>
#include <Game.hpp>
#include <iostream>
#include <SDL_image.h>

using namespace std;

class TextureComponent : public Component{
private:
    SDL_Texture *m_texture = NULL;
    string texturePath = "";

    int width, height;
    
public:

    TextureComponent(string path){
       
        m_texture = IMG_LoadTexture(Game::ren,path.c_str());
        if(!m_texture){
            cout << "Error al crear la textura\n";
            exit;
        }

        SDL_QueryTexture(m_texture,NULL,NULL,&width,&height);
        
        texturePath = path;
        std::cout << "Created texture\n";
    }

    void info();

    SDL_Texture* getTexture();
    int getWidth();
    int getHeight();

};