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

	//vector testing
	Vector2D v1, v2(3,4);
	cout << v2.toString() << endl;
	v2.printVector();

	v1.setPos(65,12);
	v1.printVector();

	v1.addVector(v2);
	cout << v1.toString() << endl;
	return 0;
}