#ifndef GAME_HPP
#define GAME_HPP
 
#include <string>
#include <SDL2/SDL_image.h>
using namespace std;


class Game{

	public:
	Game(string gameName, int screenPosX, int screenPosY, int screenSizeX, int screenSizeY); //Construtor
	~Game(); //Destrutor
	
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Rect playerPos; 

	SDL_Texture* texture; //New

	SDL_Rect srcRect; //New
	SDL_Rect destinationRect; //New
	SDL_RendererFlip flip;
	
	int screenWidth;
	int screenHeight;

	//Screen position
	int screenPosX;
	int screenPosY;

	//Screen size
	int screenSizeX;
	int screenSizeY;


	int currentFrame;
	int aceleracaoJump;
	int aceleracaoHorizontal_x;
	std::string id;
	string gameName;

	
	bool dir;
	bool esq;
	bool jump;

	//Metodos
 	bool InitEverything();
	bool InitSDL();
	bool CreateWindow();
	bool CreateRenderer();
	void SetupRenderer();
	void Render();
	void RunLoop();

};


#endif