#ifndef TEXTURE_MANAGER_HPP
#define TEXTURE_MANAGER_HPP
 
#include <string>
#include <SDL2/SDL_image.h>
#include "game.hpp"
#include <map>

using namespace std;


class TextureManager{

	public:

	SDL_Renderer* renderer;
	TextureManager(SDL_Renderer* renderer); 
	~TextureManager(); 

	bool load(std::string fileName, std::string id);
	void draw(std::string id, int x, int y, int width, 
							int height, SDL_Renderer* renderer, 
								SDL_RendererFlip flip);
	void drawFrame(std::string id, int x, int y, int
					width, int height, int currentRow, 
						int currentFrame, SDL_Renderer
							*renderer, SDL_RendererFlip flip);

	std::map<std::string, SDL_Texture*> textureMap;

};


#endif