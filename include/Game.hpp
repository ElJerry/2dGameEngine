#pragma once

#ifdef _WIN32
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif
#include <stdio.h>

class Game {
private:
    bool isRunning;
    SDL_Window *window = NULL;
    SDL_Texture *m_pTexture = NULL;

    SDL_Rect m_sourceRect;
    SDL_Rect m_targetRect;

public:

    static SDL_Renderer *renderer;
    Game();
    ~Game();

    void update();
    void render();
    void handleEvents();
    void clean();
    void init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen);

    bool running();
    
    static SDL_Renderer* ren;

    static SDL_Renderer* getRenderer();
};