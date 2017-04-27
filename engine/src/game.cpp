#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include "game.hpp"


using namespace std;




	//TextureManager* textureManager = new TextureManager(renderer);
		
	
	void RunLoop();



Game::~Game(){}


bool Game::InitEverything(){
	
	if ( !InitSDL() )
		return false;

	if ( !CreateWindow() )
		return false;

	
	if ( !CreateRenderer() )
		return false;


	return true;
}

bool Game::DestroyEverything(){

	if( !QuitSDL() )
		return false;

	if( !DestroyWindow() )
		return false;

	if ( !DestroyRenderer() )
		return false;

	return true;
}

bool Game::InitSDL(){

	if ( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
	{
		std::cout << " Failed to initialize SDL : " << SDL_GetError() << std::endl;
		return false;
	}

	int img_flags = IMG_INIT_PNG;
    if(!(IMG_Init(img_flags) & img_flags))
    {
       	std::cout << " Failed to initialize IMG_SDL : " << SDL_GetError() << std::endl;
        return false;
	}

	return true;
}

bool Game::QuitSDL(){

	IMG_Quit();
	SDL_Quit(); 
		

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

bool Game::DestroyWindow(){

	SDL_DestroyWindow(m_window);
	m_window = NULL;
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

bool Game::DestroyRenderer(){
	
	SDL_DestroyRenderer(m_renderer);
	m_renderer = NULL;
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

void Game::Render(){
	// Clear the window and make it all green
	SDL_RenderClear( m_renderer );


    m_scene->Draw( m_renderer );


	// Render our "player"
	//SDL_RenderFillRect( renderer, &playerPos );

	//textureManager->draw("bg", 0, 0, 1000, 500, renderer, flip);

	//textureManager->draw("animate", 0, 0, 128, 82, renderer, flip);

	//textureManager->drawFrame("animate", playerPos.x , playerPos.y, 
	//							128, 82, 1, currentFrame, renderer, flip);

	// Render the changes above
	SDL_RenderPresent( m_renderer);
}

void Game::RunLoop(){

	bool quit = false;
	if ( !InitEverything() ){
		quit = true;	
	}

	SetupRenderer();

	if (m_scene == NULL){

            cout << "No scenes to run!" << endl;
            quit = true;
    }
    cout << "Iniciando Loop!" << endl;
	while ( !quit ){
		if(SceneChangeManager() == false) break;

		SDL_Event event;
		while ( SDL_PollEvent( &event ) ){

			if ( event.type == SDL_QUIT ){

				quit = true;
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

		SDL_RenderClear(m_renderer);

        m_scene->Draw(m_renderer);

		SDL_RenderPresent(m_renderer);

		//Render();

		SDL_Delay( 16 );
	}//Quit loop

	cout << "Fim de jogo!" << endl;

	DestroyEverything();
}

void Game::SetBackgroundColor( int R, int G, int B, int A ){
	m_background_color.r = R;
	m_background_color.g = G;
	m_background_color.b = B;
	m_background_color.a = A;

	if (m_renderer != NULL)
    {
        SDL_SetRenderDrawColor( m_renderer,
                                m_background_color.r, 
                                m_background_color.b,
                                m_background_color.g, 
                                m_background_color.a );
    }
}

bool Game::SceneChangeManager(){

	if ( m_scene_changing ){
        if ( m_scene == NULL ){
            cout << "sem cenas para rodar" << endl;
            return false;
        }else{
            cout << "Mudando da cena" << (m_last_scene ? m_last_scene->getName() : "NULL") << 
            		" para " << m_scene->getName() << "...";

            if(m_last_scene) m_last_scene->Shutdown();
            m_scene->Init(m_renderer);

            m_scene_changing = false;
        }
    }

return true;


}

bool Game::AddScene(Scene & scene){
	auto id = scene.getName();
  	 cout << "Adicionando a cena " << id <<" no Jogo!" << endl;
    if( m_scenes.find(id) != m_scenes.end() ){
       
        cout << "A cena" << id <<" ja existe";
        return false;
    }
    m_scenes[id] = &scene;

    if( m_scene == NULL ) 
    	ChangeScene(id);

return true;

}

bool Game::ChangeScene( const std::string & id ){

	cout << "Mudando de cena para... " << id << endl;

    if (m_scenes.find(id) == m_scenes.end())
    {
    	cout << "Cena" << id << "nao foi encontrada..." << endl;
        return false;
    }

    m_last_scene = m_scene;
    m_scene = m_scenes[id];
    m_scene_changing = true;
	return true;

}





 