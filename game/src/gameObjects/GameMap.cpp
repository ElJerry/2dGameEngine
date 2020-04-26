#include <gameObject/GameMap.h>
#include <Game.hpp>
#include <iostream>
#include <SDL_image.h>
#include <components/TileMapComponent.h>

GameMap::GameMap(char *name) : GameObject(name) {

    addComponent<TileMapComponent>(30, 30);
    std::cout << "Added tile map component\n";
}