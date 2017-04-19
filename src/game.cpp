#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include "game.hpp"
#include "TextureManager.hpp"

using namespace std;




	//TextureManager* textureManager = new TextureManager(renderer);
		
	
	void RunLoop();



Game::~Game(){}

void Game::Render(){
	// Clear the window and make it all green
	SDL_RenderClear( m_renderer );

	// Render our "player"
	//SDL_RenderFillRect( renderer, &playerPos );

	//textureManager->draw("bg", 0, 0, 1000, 500, renderer, flip);

	//textureManager->draw("animate", 0, 0, 128, 82, renderer, flip);

	//textureManager->drawFrame("animate", playerPos.x , playerPos.y, 
	//							128, 82, 1, currentFrame, renderer, flip);

	// Render the changes above
	SDL_RenderPresent( m_renderer);
}

bool Game::InitEverything(){
	
	if ( !InitSDL() )
		return false;

	if ( !CreateWindow() )
		return false;

	
	if ( !CreateRenderer() )
		return false;


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

	m_window = SDL_CreateWindow( 
							m_gameName.c_str(), 
							m_screen_pos.first, 
							m_screen_pos.second, 
							m_window_size.first, 
							m_window_size.second, 
							0);

	if ( m_window == nullptr )
	{
		std::cout << "Failed to create window : " << SDL_GetError();
		return false;
	}

	return true;
}

bool Game::CreateRenderer(){

	m_renderer = SDL_CreateRenderer( m_window, -1, 
			SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if ( m_renderer == nullptr )
	{
		std::cout << "Failed to create renderer : " << SDL_GetError();
		return false;
	}

	return true;
}

void Game::SetupRenderer(){

	// Set size of renderer to the same as window
	SDL_RenderSetLogicalSize( m_renderer, m_window_size.first, m_window_size.second );

	// Set color of renderer to green
	SDL_SetRenderDrawColor(m_renderer,
                           m_background_color.r, 
                           m_background_color.b,
                           m_background_color.g, 
                           m_background_color.a);
}

void Game::RunLoop(){

	if ( !InitEverything() ){
		//quit
	}
	SetupRenderer();

	bool quit = true;

	while ( quit ){

		SDL_Event event;
		while ( SDL_PollEvent( &event ) ){

			if ( event.type == SDL_QUIT ){

				quit = false;
			}else if ( event.type == SDL_KEYDOWN ){
				
				switch ( event.key.keysym.sym ){
					
					case SDLK_RIGHT:
						
						break;
					
					case SDLK_LEFT:
						
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
		//currentFrame = 128 * int(((SDL_GetTicks() / 100) % 6));
				
	
		
		Render();

		// Add a 16msec delay to make our game run at ~60 fps
		SDL_Delay( 16 );
	}
}


void Game::SetBackgroundColor(int R, int G, int B, int A){
	m_background_color.r = R;
	m_background_color.g = G;
	m_background_color.b = B;
	m_background_color.a = A;

	if (m_renderer != NULL)
    {
        SDL_SetRenderDrawColor(m_renderer,
                               m_background_color.r, 
                               m_background_color.b,
                               m_background_color.g, 
                               m_background_color.a);
    }
}





 