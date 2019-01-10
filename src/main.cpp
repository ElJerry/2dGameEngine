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

	GameObject *go = new GameObject();
	cout << "Created go" << endl;
	TransformComponent *tc = go->getComponent<TransformComponent>();
	tc->info();
	tc->setPos(9,3);
	tc->info();

	tc = go->getComponent<TransformComponent>();
	tc->info();

	cout << "objeto 2" << endl;
	GameObject* go2 = tc->getGameObject();
	go2->getComponent<TransformComponent>()->info();
	go2->getComponent<TransformComponent>()->setPos(1,2);
	go2->getComponent<TransformComponent>()->info();
	tc->info();
	go->getComponent<TransformComponent>()->info();

	GameObject *g3 = new GameObject();
	g3->getComponent<TransformComponent>()->info();
	g3->addComponent<TextureComponent,char*>("assets/char.bmp");
	g3->getComponent<TextureComponent>()->info();
	while (g->running())
	{
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