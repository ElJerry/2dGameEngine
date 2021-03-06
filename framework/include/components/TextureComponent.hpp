#pragma once
#include <components/Component.hpp>
#include <SDL.h>
#include <Game.hpp>
#include <iostream>
#include <SDL_image.h>

using namespace std;

class TextureComponent : public Component{
private:
    SDL_Texture *m_texture = nullptr;
    string texturePath;

    int width, height;

public:

    TextureComponent(string path){
       
        m_texture = IMG_LoadTexture(Game::ren, path.c_str());
        if(!m_texture){
            cout << "Error Creating texture\n";
            exit;
        }

        SDL_QueryTexture(m_texture, nullptr, nullptr, &width, &height);

        texturePath = path;
    }

    void info();

    SDL_Texture* getTexture();
    int getWidth();
    int getHeight();

};