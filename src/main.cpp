	
//#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <game.hpp>
#include <iostream>
#include <map>

using namespace std;


int main( int argc, char* args[] ){
	

	Game* game = new Game("Game", 200, 200, 800, 500);

	//Loadinf textura player
	//load("sprite.png","animate", renderer);

	//load("assets/full.png", "bg", renderer);

	// Initlaize our player
	//playerPos.x = 20;
	//playerPos.y = 20;
	//playerPos.w = 20;
	//playerPos.h = 20;

	game->RunLoop();
}

