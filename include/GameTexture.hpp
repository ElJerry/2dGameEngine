#pragma once
#include <SDL.h>


class GameTexture {
private:
    SDL_Rect m_sourceRectangle;
    SDL_Rect m_targetRectangle;

    SDL_Texture *m_texture;
    char *texturePath;

    SDL_Renderer *renderer;

public:
    GameTexture(char* path, SDL_Renderer *renderer);
    void render();
    void update();

    //Source rectangle methods
    void sourceRecX(int x);
    void sourceRecY(int y);
    void sourceRecW(int w);
    void sourceRecH(int h);

};