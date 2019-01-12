#pragma once
#include <SDL.h>


class GameTexture {
private:
    SDL_Rect m_sourceRectangle;
    SDL_Rect m_targetRectangle;

    SDL_Texture *m_texture = NULL;
    char *texturePath = NULL;

    SDL_Renderer *renderer = NULL;

    enum RectProp {
        X_POS,
        Y_POS,
        WITDH,
        HEIGHT
    };

public:
    GameTexture(char* path, SDL_Renderer *renderer);
    void render();
    void update();

    //Source rectangle methods
    void setSourceRecProp(GameTexture::RectProp prop, int val);
    void setTargetRecProp(GameTexture::RectProp prop, int val);

};