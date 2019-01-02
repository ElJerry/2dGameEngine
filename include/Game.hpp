#pragma once

#include <SDL2/SDL.h>
#include <stdio.h>

class Game {
public:
    Game();
    ~Game();

    void saludar();
    void update();
    void render();
    void handleEvents();
    void clean();
    void init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen);

    bool running();

private:
    bool isRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;
    int cnt;
};