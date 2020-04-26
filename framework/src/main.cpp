#include <iostream>
#include <SDL.h>
#include <Game.hpp>
#include <components/Component.hpp>
#include <GameObject.hpp>
#include <components/TransformComponent.hpp>
#include <components/ComponentIdentifier.hpp>
#include <components/TextureComponent.hpp>
#include <Vector2D.hpp>

using namespace std;

Game *g = NULL;

int main(){
	
	g = new Game();

	g->init("Game test", 50,50,800,600,false);
	
	int start, end;
	while (g->running())
	{
		//make it 30fps
		start = SDL_GetTicks();
		g->handleEvents();
		g->update();
		g->render();		
		end = SDL_GetTicks();

		int fps = 1000 / 30;
		int fps_dif = end - start;
		if(fps_dif < fps){
			SDL_Delay(fps - fps_dif);
		}
	}
    
	g->clean();
	return 0;
}