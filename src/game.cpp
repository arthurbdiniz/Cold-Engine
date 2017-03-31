#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include "game.hpp"

using namespace std;

Game::Game(string gameName, int screenPosX, int screenPosY, int screenSizeX, int screenSizeY){

	this->gameName = gameName;
	this->screenPosX = screenPosX;
	this->screenPosY = screenPosY;
	this->screenSizeX = screenSizeX;
	this->screenSizeY = screenSizeY;
	cout << "\ntesten\n";
	if ( !InitEverything() ){
		//quit
	}

}

Game::~Game(){}

void Game::Render(){
	// Clear the window and make it all green
	SDL_RenderClear( renderer );

	// Render our "player"
	//SDL_RenderFillRect( renderer, &playerPos );

//	draw("bg", 0, 0, 1000, 500, renderer, flip);

	//draw("animate", 0, 0, 128, 82, renderer, flip);

//	drawFrame("animate", playerPos.x , playerPos.y, 128, 82, 1, currentFrame, renderer, flip);

	// Render the changes above
	SDL_RenderPresent( renderer);
}

bool Game::InitEverything(){
	
	if ( !InitSDL() )
		return false;

	if ( !CreateWindow() )
		return false;

	if ( !CreateRenderer() )
		return false;

	SetupRenderer();
	RunLoop();

	return true;
}

bool Game::InitSDL(){

	if ( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
	{
		std::cout << " Failed to initialize SDL : " << SDL_GetError() << std::endl;
		return false;
	}

	return true;
}

bool Game::CreateWindow(){

	window = SDL_CreateWindow( gameName.c_str(), screenPosX, screenPosY, screenSizeX, screenSizeY, 0);

	if ( window == nullptr )
	{
		std::cout << "Failed to create window : " << SDL_GetError();
		return false;
	}

	return true;
}

bool Game::CreateRenderer(){

	renderer = SDL_CreateRenderer( window, -1, 0 );

	if ( renderer == nullptr )
	{
		std::cout << "Failed to create renderer : " << SDL_GetError();
		return false;
	}

	return true;
}

void Game::SetupRenderer(){

	// Set size of renderer to the same as window
	SDL_RenderSetLogicalSize( renderer, screenSizeX, screenSizeY );

	// Set color of renderer to green
	SDL_SetRenderDrawColor( renderer, 0, 255, 0, 255 );
}

void Game::RunLoop(){

	bool quit = true;

	while ( quit ){

		SDL_Event event;
		while ( SDL_PollEvent( &event ) ){

			if ( event.type == SDL_QUIT ){

				quit = false;
			}else if ( event.type == SDL_KEYDOWN ){
				
				switch ( event.key.keysym.sym ){
					
					case SDLK_RIGHT:
						dir = true;
						break;
					
					case SDLK_LEFT:
						esq = true;
						break;

					case SDLK_DOWN:
						break;
					
					case SDLK_UP:
						break;

					default :
						break;
				}
			}else if(event.type == SDL_KEYUP){


			}
		}//Fim do Loop Event

		
		//Movimenta as sprites
		currentFrame = 128 * int(((SDL_GetTicks() / 100) % 6));
				
		esq = false;
		dir = false;
		
		Render();

		// Add a 16msec delay to make our game run at ~60 fps
		SDL_Delay( 16 );
	}
}




