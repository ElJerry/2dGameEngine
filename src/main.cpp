#include <iostream>
#include <SDL.h>
#include <Game.hpp>
#include <Component.hpp>
#include <GameObject.hpp>
#include <TransformComponent.hpp>

using namespace std;

Game *g = NULL;

int main(){
	
	g = new Game();

	g->init("Game test", 50,50,800,600,false);

	GameObject *go = new GameObject();
	cout << "Created go" << endl;
	TransformComponent *tc = go->getComponent<TransformComponent>();
	tc->info();
	tc->setPos(9,3);
	tc->info();

	tc = go->getComponent<TransformComponent>();
	tc->info();
	
	while (false && g->running())
	{
		g->handleEvents();
		g->update();
		g->render();
		cout << Component::getComponentID<int>() << endl;
		cout << Component::getComponentID<float>() << endl;
		cout << Component::getComponentID<bool>() << endl;
		
	}
    
	g->clean();
	return 0;
}