#ifndef MENU_SCENE
#define MENU_SCENE

#include "scene.hpp"

class MenuScene : public Scene {

public:
    MenuScene() : Scene("Menu") {}

    ~MenuScene() {}

    bool Init(SDL_Renderer * renderer);
    bool Shutdown();

    bool Draw(SDL_Renderer * renderer);
};

#endif
