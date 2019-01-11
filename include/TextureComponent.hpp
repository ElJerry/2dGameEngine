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

    void info(){
        std::cout << "texture path: " << texturePath << std::endl;
    }

    SDL_Texture* getTexture(){
        return m_texture;
    }

    //void update() override{ std::cout << "update from texturecomp\n";}
    //void render() override{ std::cout << "render from texturecomp\n"; }
};