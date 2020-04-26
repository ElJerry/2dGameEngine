#include <iostream>
#include <components/TileMapComponent.h>
#include <components/TextureComponent.hpp>
#include <components/RendererComponent.hpp>
#include <components/ColliderComponent.h>
#include <GameScripts/GameScript.h>
#include <gameObject/GameMap.h>
#include <gameObject/Player.h>
#include <camera/Camera.h>
#include <game_main.h>

void initGameElemets(){
    // create map
        auto map = new GameMap("Mapa");
        auto mapComp = map->getComponent<TileMapComponent>();
        mapComp->loadTexture("assets/grass.png");
        mapComp->loadTexture("assets/dirt.png");
        mapComp->createRandomMap();

        // create player and add required components
        auto player = new Player("Player");

        // temporary block for testing
        auto block = new GameObject("Block");
        block->addComponent<TextureComponent>("assets/redBlock.png");
        block->addComponent<RendererComponent>();
        block->addComponent<ColliderComponent>(100, 100, nullptr);
        block->getComponent<TransformComponent>()->position = Vector2D{100, 100};

        // temporary block for testing
        auto block2 = new GameObject("Block2");
        block2->addComponent<TextureComponent>("assets/redBlock.png");
        block2->addComponent<RendererComponent>();
        block2->addComponent<ColliderComponent>(100, 100, nullptr);
        block2->getComponent<TransformComponent>()->position = Vector2D{0, 300};
        cout << "finished creating stuff" << endl;

        // Center camera to player
        Camera::setCenteredObject(player);
}

void gameUpdate(){

}

void gameEvents(){

}