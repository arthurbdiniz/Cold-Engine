#include "menuscene.hpp"

#include "log.h"
#include "sdl_log.h"
#include <iostream>
#include <string>
#include <stdio.h>

bool MenuScene::Init(SDL_Renderer * renderer)
{
    Scene::Init(renderer);

    // ===== Load Texture =====
    cout << "Load Texture"<< endl;
    INFO("Load Texture");

    SDL_Surface * image = NULL;
    image = IMG_Load("assets/sprites/playnow.png");

    if (image == NULL)
    {
        SDL_IMG_ERROR("Can't load sprite");
        return false;
    }

    m_texture = SDL_CreateTextureFromSurface(renderer, image);

    if (m_texture == NULL)
    {
        SDL_ERROR("Can't create texture from image");
        return false;
    }

    m_w = image->w;
    m_h = image->h;

    SDL_FreeSurface(image);
    image = NULL;

    return true;
}

bool MenuScene::Shutdown()
{
    Scene::Shutdown();

    INFO("Destroy texture");
    SDL_DestroyTexture(m_texture);
    m_texture = NULL;

    return true;
}

bool MenuScene::Draw(SDL_Renderer * renderer)
{
    SDL_Rect renderQuad = {10, 10, m_w, m_h};
    SDL_RenderCopy(renderer, m_texture, NULL, &renderQuad);

    return true;
}
