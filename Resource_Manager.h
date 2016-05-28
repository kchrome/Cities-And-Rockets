#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include <map>
#include <iterator>
#include <string>

#include "gTexture.h"

class Game;
class gTexture;
class Resource_Manager
{
private:
	std::map<std::string, gTexture*> textures;
	Game* game;


public:
	Resource_Manager(Game* game);

	//Deleting the instance will wipe all the textures allocated by that instance
	~Resource_Manager();

	void loadTexture(std::string filname);

	//Returns NULL if can't find texture with the desingated filename
	gTexture* getTexture(std::string filename);

};



#endif
