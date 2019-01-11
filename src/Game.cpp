#include "Game.hpp"
#include <iostream>
#include <SDL.h>
#include <unistd.h>
#include <GameTexture.hpp>
#include <GameObject.hpp>
#include <RendererComponent.hpp>
#include <TextureComponent.hpp>
#include <TransformComponent.hpp>

using namespace std;

GameObject *gameObject, *go2;
SDL_Renderer* Game::ren;

Game::Game() {}
Game::~Game() {}

void Game::update()
{
    gameObject->update();
    go2->update();
}

void Game::render()
{
    SDL_RenderClear(renderer);
    //add stuff to renderer
    gameObject->render();
    go2->render();
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
        ren = renderer;

        gameObject = new GameObject();
        gameObject->addComponent<TextureComponent,char*>("assets/char.bmp");
        gameObject->addComponent<TransformComponent>();
        gameObject->addComponent<RendererComponent>();

        go2 = new GameObject();
        go2->addComponent<TextureComponent,char*>("assets/char.bmp");
        go2->addComponent<TransformComponent>();
        go2->addComponent<RendererComponent>();

        go2->getComponent<TransformComponent>()->setPos(50,50);
        cout << "finished creating stuff" << endl;
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
