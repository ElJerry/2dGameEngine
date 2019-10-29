#include "Game.hpp"
#include <iostream>
#include <SDL.h>
#include <GameObject.hpp>
#include <components/RendererComponent.hpp>
#include <components/TextureComponent.hpp>
#include <components/SpriteAnimatorComponent.hpp>

using namespace std;

SDL_Renderer* Game::ren;

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

        GameObject* gameObject = GameObject::addGameObject("mono1");
        gameObject->addComponent<TextureComponent>("assets/male_sprite_model.png");
        gameObject->addComponent<RendererComponent>();
        gameObject->addComponent<SpriteAnimatorComponent>(4,8,32,64);
        gameObject->getComponent<SpriteAnimatorComponent>()->setRow(2);

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
            case SDL_KEYDOWN:
                GameObject::find("mono1")->getComponent<TransformComponent>()->speed.setX(1);
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