#ifndef GAME_HPP
#define GAME_HPP
 
#include <string>
#include <SDL2/SDL_image.h>
#include <TextureManager.hpp>
using namespace std;


class Game{

	public:
	Game(string gameName, pair<int, int> screen_pos,  pair<int, int> window_size)
		: m_gameName(gameName), m_window_size(window_size),
          m_window(NULL), m_renderer(NULL), 
          m_screen_pos(screen_pos),
          m_background_color({0xff, 0xff, 0xff, 0xff}){}

	~Game(); //Destrutor

	
	
	SDL_Window*   m_window;
	SDL_Renderer* m_renderer;
	SDL_Color     m_background_color;

	//Screen Params
	string m_gameName;//Screen name
	pair<int, int> m_window_size;//Screen size
	pair<int, int> m_screen_pos;//Screen position
	
	string id;

	//Metodos
 	bool InitEverything();
 	bool DestroyEverything();
	bool InitSDL();
	bool QuitSDL();
	bool CreateWindow();
	bool CreateRenderer();
	bool DestroyWindow();
	bool DestroyRender();
	void SetupRenderer();
	void SetBackgroundColor(int R, int G, int B, int A);

	void Render();
	void RunLoop();

};


#endif