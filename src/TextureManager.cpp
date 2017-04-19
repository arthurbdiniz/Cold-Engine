#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include "TextureManager.hpp"
#include "game.hpp"

TextureManager::TextureManager(SDL_Renderer* renderer){
	this->renderer = renderer;
}

TextureManager::~TextureManager(){}

bool TextureManager::load(std::string fileName, std::string id) {

	SDL_Surface* tempSurface = IMG_Load(fileName.c_str());
	if(tempSurface == 0){

	return false;
	}
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
	SDL_FreeSurface(tempSurface);
	// everything went ok, add the texture to our list
	if(texture != 0){

		textureMap[id] = texture;
		return true;
	}
	// reaching here means something went wrong
	return false;
}

void TextureManager::draw(std::string id, int x, int y, int width, 
							int height, SDL_Renderer* renderer, 
								SDL_RendererFlip flip) {

	SDL_Rect srcRect;
	SDL_Rect destinationRect;
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = destinationRect.w = width;
	srcRect.h = destinationRect.h = height;
	destinationRect.x = x;
	destinationRect.y = y;
	
	SDL_RenderCopyEx(renderer, textureMap[id], &srcRect,&destinationRect, 0, 0, flip);
}


void TextureManager::drawFrame(std::string id, int x, int y, int
					width, int height, int currentRow, 
						int currentFrame, SDL_Renderer
							*renderer, SDL_RendererFlip flip){

	SDL_Rect srcRect;
	SDL_Rect destinationRect;
	srcRect.x = width * currentFrame;
	srcRect.y = height * (currentRow - 1);
	srcRect.w = destinationRect.w = width;
	srcRect.h = destinationRect.h = height;
	destinationRect.x = x;
	destinationRect.y = y;

	SDL_RenderCopyEx(renderer, textureMap[id], &srcRect,&destinationRect, 0, 0, flip);
}
