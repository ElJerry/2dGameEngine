#include "Game.hpp"
#include <iostream>
#include <SDL.h>
#include <GameObject.hpp>
#include <gameObject/Player.h>
#include <gameObject/GameMap.h>
#include <gameObject/Floor.h>
#include <components/TileMapComponent.h>
#include <components/TransformComponent.hpp>

using namespace std;

SDL_Renderer* Game::ren;
SDL_Renderer* Game::renderer;
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

        // create map
        auto map = new GameMap("Mapa");
        auto mapComp = map->getComponent<TileMapComponent>();
        mapComp->loadTexture("assets/grass.png");
        mapComp->loadTexture("assets/dirt.png");
        mapComp->createRandomMap();

        // create player and add required components
        new Player("Player");

        // create floor
        new Floor("floor1", 0, 250);
        new Floor("floor2", 100, 450);


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
            default:
                for (auto go : GameObject::getGameObjects()){
                    go->handleEvents(event);
                }
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