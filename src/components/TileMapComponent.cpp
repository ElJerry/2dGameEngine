
#include <Game.hpp>
#include <SDL_image.h>
#include <iostream>
#include "components/TileMapComponent.h"

#ifdef _WIN32
#include <time.h>
#endif

TileMapComponent::TileMapComponent(int height, int width) {
    m_height = height;
    m_width = width;

    tileMap.assign(height, std::vector<int>(width));
}

void TileMapComponent::loadTexture(std::string path){
    auto texture = IMG_LoadTexture(Game::renderer, path.c_str());
    textures.push_back(texture);
}

void TileMapComponent::deleteTexture(int handle) {

    if (handle >= textures.size())
        return;

    SDL_DestroyTexture(textures[handle]);
    textures[handle] = nullptr;
}

bool TileMapComponent::loadMap(std::vector<std::vector<int>> map){
    int y = map.size();
    if (y != m_height)
        return false;

    int x = map[0].size();
    if(x != m_width)
        return false;

    tileMap = map;
    return true;
}

void TileMapComponent::createRandomMap(){
    std::cout << "creating random tileMap\n";
    std::cout << "textures: " << textures.size() << "\n";

    srand(time(nullptr));
    for(int i=0 ; i < m_height ; i++){
        for(int j=0; j < m_width; j++){
            tileMap[i][j] = (rand() % textures.size());
            std::cout << tileMap[i][j];
        }
        std::cout << "\n";
    }

}

void TileMapComponent::setWidth(int width){
    this->m_width = width;
}

void TileMapComponent::setHeight(int height){
    this->m_height = height;
}

void TileMapComponent::render() {
    for(int i=0; i < m_width; i++){
        for(int j = 0; j < m_height; j++){
            SDL_Rect src, dest;

            // Null texture
            if(tileMap[i][j] >= textures.size() || textures[tileMap[i][j]] == nullptr){
                continue;
            }

            SDL_Texture *texture = textures[tileMap[i][j]];
            src.h = src.w = dest.h = dest.w = 32;
            src.x = src.y = 0;

            dest.x = 32 * j;
            dest.y = 32 * i;

            SDL_RenderCopy(Game::renderer, texture, &src, &dest);
        }
    }
}

void TileMapComponent::update() {}

void TileMapComponent::handleEvents(SDL_Event) {}
