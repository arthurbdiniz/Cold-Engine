#include "scene.hpp"
#include <iostream>
#include <string>
#include <stdio.h>

bool Scene::Init( SDL_Renderer* ){
     cout << "Iniciando cena" << endl;
     return true;
}

bool Scene::Shutdown(){
    
    cout << "Fechando cena" << endl;
    return true;
}

bool Scene::Draw( SDL_Renderer* ){
  
  	return true;
}
