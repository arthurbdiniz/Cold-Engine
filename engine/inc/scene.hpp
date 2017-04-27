#ifndef SCENE_HPP
#define SCENE_HPP


#include <string>

#include <SDL2/SDL_image.h>

using namespace std;

class Scene {

protected:

    string m_name;
    SDL_Texture* m_texture;
    int m_w;
    int m_h;
    


public:
  
    
    Scene(std::string name)
        : m_name(name), m_texture(NULL), m_w(0), m_h(0) {}

    virtual ~Scene() {}



    virtual bool Init(SDL_Renderer* renderer);
    virtual bool Shutdown();

    virtual bool Draw(SDL_Renderer* renderer);

    string getName(){return m_name;}

};


#endif