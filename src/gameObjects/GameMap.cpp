#include <gameObject/GameMap.h>
#include <Game.hpp>
#include <iostream>
#include <SDL_image.h>

int definedMap[HEIGHT][WIDTH]{
        {0,1,1,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
};



GameMap::GameMap(char *name) : GameObject(name) {
    int random[HEIGHT][WIDTH];
    srand(time(nullptr));
    for(int i=0; i<WIDTH; i++){
        for(int j = 0; j < HEIGHT; j++){
            random[i][j] = rand() % 2;
        }
        std::cout << std::endl;
    }

    grass = IMG_LoadTexture(Game::renderer,"assets/grass.png");
    dirt = IMG_LoadTexture(Game::renderer,"assets/dirt.png");

    loadMap(random);
}

void GameMap::loadMap(int theMap[HEIGHT][WIDTH]) {
    std::cout << "=========== Loading Map ===========\n";
    for(int i=0; i<WIDTH; i++){
        for(int j = 0; j < HEIGHT; j++){
            this->map[i][j] = theMap[i][j];
            std::cout << map[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "===================================\n";


    renderer = Game::renderer;
}

void GameMap::drawMap() {
//    std::cout << "rendering map" << std::endl;
    for(int i=0; i<WIDTH; i++){
        for(int j = 0; j < HEIGHT; j++){
            SDL_Rect src, dest;
            SDL_Texture *texture = nullptr;
            src.h = src.w = dest.h = dest.w = 32;
            src.x = src.y = 0;

            dest.x = 32 * j;
            dest.y = 32 * i;
            std::string texturePath = "";
            switch(this->map[i][j]){
                case 0:
                    texture = grass;
                    break;
                case 1:
                    texture = dirt;
                    break;
            }


            SDL_RenderCopy(renderer, texture, &src, &dest);
        }
    }
}