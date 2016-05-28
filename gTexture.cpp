#include "gTexture.h"

gTexture::gTexture()
{
	mTexture = NULL;
	width = 0;
	height = 0; 
}

void gTexture::setTexture(SDL_Texture* loaded)
{
	mTexture = loaded;
}

SDL_Texture* gTexture::getTexture()
{
	return mTexture;
}

float gTexture::getWidth()
{
	return width;
}

float gTexture::getHeight()
{
	return height;
}

void gTexture::setDimensions(float w, float h)
{
	width = w;
	height = h;
}

void gTexture::close()
{
	SDL_DestroyTexture(mTexture);
}