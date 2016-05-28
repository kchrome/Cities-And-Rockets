#include "Dot.h"

void Dot::Init(Game* game, Resource_Manager* rm, float x, float y)
{
	this->game = game;
	this->rm = rm;;
	this->x = x;
	this->y = y;

	sheet = rm->getTexture(DOT);
	sizeX = sheet->getWidth();
	sizeY = sheet->getHeight();

	velocity = 5;
	destroy = false;

}

void Dot::Update(float deltaTime)
{
	source_rect.x = 0;
	source_rect.y = 0;
	source_rect.w = (int)sheet->getWidth();
	source_rect.h = (int)sheet->getHeight();

	x += dx * velocity;
	y += dy * velocity;

	dest_rect.x = (int)x;
	dest_rect.y = (int)y;
	dest_rect.w = (int)sheet->getWidth();
	dest_rect.h = (int)sheet->getHeight();

	dx = 0;
	dy = 0;
	
}

void Dot::HandleEvents(SDL_Event* event)
{
	/*//If a key was pressed
	if (event->type == SDL_KEYDOWN && event->key.repeat == 0)
	{
		//Adjust the velocity
		switch (event->key.keysym.sym)
		{
		case SDLK_UP: Move(0, -1); break;
		case SDLK_DOWN: Move(0, 1); break;
		case SDLK_LEFT: Move(-1, 0); break;
		case SDLK_RIGHT: Move(1, 0); break;
		}
	}
	//If a key was released
	else if (event->type == SDL_KEYUP && event->key.repeat == 0)
	{
		//Adjust the velocity
		switch (event->key.keysym.sym)
		{
	    case SDLK_UP: Move(0, 1); break;
		case SDLK_DOWN: Move(0, -1); break;
		case SDLK_LEFT: Move(1, 0); break;
		case SDLK_RIGHT: Move(-1, 0); break;
		}
	}*/
}
void Dot::Render()
{
	if (!destroy)
	SDL_RenderCopy(game->getRenderer(), sheet->getTexture(), &source_rect, &dest_rect);
}

void Dot::Move(int x, int y)
{
	dx = x;
	dy = y;
}