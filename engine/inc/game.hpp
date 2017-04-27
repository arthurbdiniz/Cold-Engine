#ifndef GAME_HPP
#define GAME_HPP
 
#include <string>
#include <SDL2/SDL_image.h>
#include <unordered_map>
#include <utility>

#include "scene.hpp"




using namespace std;


class Game{

	public:
	Game(string gameName, pair<int, int> screen_pos,  pair<int, int> window_size)
		: m_gameName(gameName), m_window_size(window_size),
          m_window(NULL), m_renderer(NULL), 
          m_screen_pos(screen_pos),
          m_background_color({0xff, 0xff, 0xff, 0xff}){}

	~Game(); //Destructor

	string m_gameName; //Screen name
	pair<int, int> m_window_size; //Screen size
	SDL_Window*   m_window;
	SDL_Renderer* m_renderer;
	pair<int, int> m_screen_pos; //Screen position
	SDL_Color     m_background_color;

	//Screen Params
	unordered_map<std::string, Scene *> m_scenes; //Map of scenes


	//Scenes Params
	Scene* m_scene; //Current Scene
    Scene* m_last_scene; //Last Scene
	bool m_scene_changing; 


	//Methods
 	bool InitEverything();
 	bool DestroyEverything();
	
	bool InitSDL();
	bool QuitSDL();
	
	bool CreateWindow();
	bool DestroyWindow();
	
	bool CreateRenderer();
	bool DestroyRenderer();
	void SetupRenderer();
	
	void SetBackgroundColor(int R, int G, int B, int A);

	void Render();
	void RunLoop();

	bool AddScene(Scene & scene);
	bool ChangeScene(const std::string & id);
	bool SceneChangeManager();

};


#endif