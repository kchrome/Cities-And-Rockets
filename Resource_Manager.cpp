#include "Resource_Manager.h"
#include "Game.h"
#include <stdexcept>

Resource_Manager::Resource_Manager(Game* game)
{
	this->game = game;

}

Resource_Manager::~Resource_Manager()
{
	gTexture* texture;
	std::map<std::string, gTexture*>::iterator i;
	for (i = textures.begin(); i != textures.end(); i++)
	{
		texture = i->second;
		texture->close();
	}
	textures.clear();
}


void Resource_Manager::loadTexture(std::string filename)
{
	gTexture* texture = new gTexture();
	SDL_Surface* key = NULL;

	key = IMG_Load(filename.c_str());
	if (key == NULL)
		throw std::runtime_error("Unable to load asset:" + filename);

	texture->width = key->w;
	texture->height = key->h;

	SDL_SetColorKey(key, SDL_TRUE, SDL_MapRGB(key->format, 216, 186, 100));

	//Create texture from keyed suface pixels
	texture->mTexture =  SDL_CreateTextureFromSurface(game->getRenderer(), key);
	SDL_FreeSurface(key);
	
	//Load Texture without color key
	//texture = IMG_LoadTexture(game->getRenderer(), filename.c_str());

	if (texture->mTexture == NULL)
		throw std::runtime_error("Error while creating texture:" + filename);

	textures.insert(std::pair<std::string, gTexture*>(filename, texture));

	/*The final texture
	SDL_Texture *texture = NULL;

	//Load image at specified path
	SDL_Surface *loadedSurface = IMG_Load(filename.c_str());
	if (loadedSurface == NULL)
	{
		throw std::runtime_error("Error while loading texture:" + filename);
	}
	else
	{
		//Create texture from surface pixels
		texture = SDL_CreateTextureFromSurface(game->getRenderer(), loadedSurface);
		if (texture == NULL)
		{
			throw std::runtime_error("Error while loading texture:" + filename);

		}
		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}*/
}

gTexture* Resource_Manager::getTexture(std::string filename)
{
    gTexture* texture = NULL;
	std::map<std::string, gTexture*>::iterator i;

	i = textures.find(filename);

	texture = i->second;

	return texture;
}

