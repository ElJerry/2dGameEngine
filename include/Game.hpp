#pragma once

#include <SDL2/SDL.h>
#include <stdio.h>

class Game {
public:
    Game();
    ~Game();

    void update();
    void render();
    void handleEvents();
    void clean();
    void init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen);

    bool running();
    
    static SDL_Renderer* ren;

    static SDL_Renderer* getRenderer(){
        
        return ren;
    }

private:
    bool isRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;

    SDL_Texture *m_pTexture;
    SDL_Rect m_sourceRect;
    SDL_Rect m_targetRect;
};