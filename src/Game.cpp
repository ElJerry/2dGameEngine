#include "Game.hpp"
#include <iostream>
#include <SDL.h>
#include <unistd.h>
#include <GameTexture.hpp>
#include <GameObject.hpp>
#include <RendererComponent.hpp>
#include <TextureComponent.hpp>
#include <TransformComponent.hpp>
#include <SpriteAnimatorComponent.hpp>

using namespace std;

SDL_Renderer* Game::ren;

Game::Game() {}
Game::~Game() {}

void Game::update()
{
    
    for(GameObject* go : GameObject::getGameObjects()){
        go->update();
    }

    GameObject* found = GameObject::find("mono2");
    if(found != NULL){
        found->getComponent<TransformComponent>()->setPos(500,500);    
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
        gameObject->addComponent<TextureComponent,char*>("assets/male_sprite_model.png");
        gameObject->addComponent<RendererComponent>();
        gameObject->addComponent<SpriteAnimatorComponent,int>(4,8,32,64);
        
        gameObject->getComponent<SpriteAnimatorComponent>()->setRow(2);

        gameObject = GameObject::addGameObject("mono2");
        gameObject->addComponent<TextureComponent,char*>("assets/male_sprite_model.png");
        gameObject->addComponent<RendererComponent>();
        gameObject->addComponent<SpriteAnimatorComponent,int>(4,8,32,64);
        
        gameObject->getComponent<SpriteAnimatorComponent>()->setRow(0);
        gameObject->getComponent<SpriteAnimatorComponent>()->setColumnsInRow(0,5);
        gameObject->getComponent<SpriteAnimatorComponent>()->setBounce(true);
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

SDL_Renderer* Game::getRenderer(){
    return ren;
}