#include "Game.hpp"
#include <iostream>
#include <SDL.h>
#include <GameObject.hpp>
#include <components/RendererComponent.hpp>
#include <components/TextureComponent.hpp>
#include <components/SpriteAnimatorComponent.hpp>
#include <components/ControllerComponent.h>

using namespace std;

SDL_Renderer* Game::ren;

GameObject* player = nullptr;

Game::Game() {}
Game::~Game() {}

void Game::update()
{
    for(GameObject* go : GameObject::getGameObjects()){
        go->update();
    }
}

void Game::render()
{
    SDL_RenderClear(renderer);
    //add stuff to renderer
    for(GameObject* go : GameObject::getGameObjects()){
        go->render();
    }
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

        player = GameObject::addGameObject("player");
        player->addComponent<TextureComponent>("assets/male_sprite_model.png");
        player->addComponent<RendererComponent>();
        player->addComponent<SpriteAnimatorComponent>(4,8,32,64);
        player->getComponent<SpriteAnimatorComponent>()->setRow(2);
        player->addComponent<ControllerComponent>();

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
    while(SDL_PollEvent(&event)){
        switch (event.type)
        {
            case SDL_QUIT:
                isRunning = false;
                break;
            // Moving character
            case SDL_KEYUP:
            case SDL_KEYDOWN:
                player->getComponent<ControllerComponent>()->handleEvents(event);
                break;
            default:
                break;
        }
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

SDL_Renderer* Game::getRenderer(){
    return ren;
}