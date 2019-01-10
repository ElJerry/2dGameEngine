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
		cout << "ciclo\n";
		g->handleEvents();
		g->update();
		g->render();
		// cout << ComponentIdentifier::getComponentID<int>() << endl;
		// cout << ComponentIdentifier::getComponentID<float>() << endl;
		// cout << ComponentIdentifier::getComponentID<bool>() << endl;
		
	}
    
	g->clean();
	return 0;
}