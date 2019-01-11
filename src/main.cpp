#include <iostream>
#include <SDL.h>
#include <Game.hpp>
#include <Component.hpp>
#include <GameObject.hpp>
#include <TransformComponent.hpp>
#include <ComponentIdentifier.hpp>
#include <TextureComponent.hpp>

using namespace std;

Game *g = NULL;

int main(){
	
	g = new Game();

	g->init("Game test", 50,50,800,600,false);
	while (g->running())
	{
		g->handleEvents();
		g->update();
		g->render();
		
	}
    
	g->clean();
	return 0;
}