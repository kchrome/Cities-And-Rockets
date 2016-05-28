#include "Game.h"



class gTexture
{
	friend class Resource_Manager;
private:
	SDL_Texture* mTexture;
	float height, width;


public: 

	gTexture();
	float getHeight();
	float getWidth();
	SDL_Texture* getTexture();

protected:
	void setTexture(SDL_Texture*);
	void setDimensions(float w, float h);
	void close();
};