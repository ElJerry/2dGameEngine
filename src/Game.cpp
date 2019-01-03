#include "Game.hpp"
#include <iostream>
#include <SDL.h>
#include <unistd.h>
#include <GameTexture.hpp>

using namespace std;

GameTexture *gt1;

Game::Game() {}
Game::~Game() {}

void Game::update()
{
    cout << "cnt: " << cnt++ << endl;
    gt1->update();
}

void Game::render()
{
    SDL_RenderClear(renderer);
    //add stuff to renderer
    cout << "rendereo" << endl;
    gt1->render();
    SDL_RenderPresent(renderer);
}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;
    if (fullscreen)
        flags = SDL_WINDOW_FULLSCREEN;

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        cout << "Subsystems initialised..." << endl;

        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (window)
        {
            cout << "Window created..." << endl;
        }
        else
        {
            cout << "window creation fail" << endl;
            return;
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer)
        {
            SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
            cout << "Renderer created!" << endl;
        }
        else
        {
            cout << "Renderer creation failed" << endl;
            return;
        }

        /*SDL_Surface *surface = SDL_LoadBMP("assets/char.bmp");
        if (!surface){
            cout << "surface creation failed: " << SDL_GetError() ;
            return;
            
        }
        m_pTexture = SDL_CreateTextureFromSurface(renderer,surface);
        SDL_FreeSurface(surface);

        if (!m_pTexture)
        {
            cout << "texture creation failed: " << SDL_GetError() ;
            return;
        }

        SDL_QueryTexture(m_pTexture,NULL,NULL,&m_sourceRect.w,&m_sourceRect.h);
        m_targetRect.h = m_sourceRect.h;
        m_targetRect.w = m_sourceRect.w;
        m_targetRect.x = m_targetRect.y = m_sourceRect.x = m_sourceRect.y = 0;
        cout << "cargue la perra imagen" << endl;*/

        gt1 = new GameTexture("assets/char.bmp",renderer);

        isRunning = true;
    }
    else
    {
        isRunning = false;
    }
}

void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type)
    {
    case SDL_QUIT:
        isRunning = false;
        break;
    default:
        break;
    }
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    cout << "Game cleaned" << endl;
}

bool Game::running()
{
    return isRunning;
}