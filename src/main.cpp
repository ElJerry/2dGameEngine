#include <iostream>
#include <SDL.h>
#include <Game.hpp>
#include <Component.hpp>
#include <GameObject.hpp>
#include <TransformComponent.hpp>
#include <ComponentIdentifier.hpp>
#include <TextureComponent.hpp>
#include <Vector2D.hpp>

using namespace std;

Game *g = NULL;

int main(){
	
	// g = new Game();

	// g->init("Game test", 50,50,800,600,false);
	
	// while (g->running())
	// {
	// 	g->handleEvents();
	// 	g->update();
	// 	g->render();		
	// }
    
	// g->clean();

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