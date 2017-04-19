	
//#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <game.hpp>
#include <TextureManager.hpp>
#include <iostream>
#include <map>

using namespace std;


int main( int argc, char* args[] ){

	const pair<int, int> screen_pos(200, 200);
	const pair<int, int> window_size(800, 500);

	Game* game = new Game("Game",  screen_pos, window_size);
	game->SetBackgroundColor(255, 255, 255, 0);
	//

	//game->textureManager.load("sprite.png","animate");
	//game->textureManager.load("assets/full.png", "bg");
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

