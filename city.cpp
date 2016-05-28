#include "City.h"

float City::scale = 1.0f;
 
void City::Init(Game* game, Resource_Manager* rm, float x, float y)
{
	this->game = game;
	this->rm = rm;

	sizeX = 123;
	sizeY = 124;
	
	if (x > SCREENHEIGHT / 2)
		this->x = x - sizeX;
	else if (x < SCREENHEIGHT / 2)
		this->x = x;
	else
		this->x = x - sizeX / 2;

	this->y = y - sizeY * scale;

	sheet_column = 0;
	sheet_row = 0;
	sheet = rm->getTexture(CITY);
	animationSpeed = 10.0f;
	

	destroy = false;
}

void City::Update(float deltaTime)
{
	time = deltaTime;

	if (destroy)
	{
		if (sheet_column < 1)
			sheet_column += (animationSpeed / 16) * deltaTime;
		else if (sheet_column > 6)
			sheet_column += (animationSpeed / 16) * deltaTime;
		else
			sheet_column += animationSpeed * time;

		if (sheet_column > SHEET_COL)
			sheet_column = 0.0f;
		Destroy();
	}

	source_rect.x = (int)sheet_column * (int)sizeX;
	source_rect.y = (int)sheet_row;
	source_rect.w = (int)sizeX;
	source_rect.h = (int)sizeY;

	dest_rect.x = (int)x;
	dest_rect.y = (int)y;
	dest_rect.w = sizeX * scale;
	dest_rect.h = sizeY * scale;

}

void City::HandleEvents(SDL_Event* event)
{

}


void City::Render()
{
	SDL_RenderCopy(game->getRenderer(), sheet->getTexture(), &source_rect, &dest_rect);

}

void City::colorMod(int r, int b, int g)
{
	SDL_SetTextureColorMod(sheet->getTexture(), r, g, b);
}

void City::Destroy()
{
	animateDestruction();
}
void City::animateDestruction()
{
	if (sheet_column < 1)
		sheet_column += (animationSpeed / 16) * time;
	else if (sheet_column > 6)
		sheet_column += (animationSpeed / 16) * time;
	else
		sheet_column += animationSpeed * time;

	if (sheet_column > SHEET_COL)
		sheet_column = 0.0f;
}
