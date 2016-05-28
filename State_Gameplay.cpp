#include "State_Gameplay.h"
#include <stdexcept>

bool State_Gameplay::Init(Game* game)
{
	this->game = game;
	rm = new Resource_Manager(game);

	
	try
	{
		rm->loadTexture(CITY);
		rm->loadTexture(DOT);
	}
	catch (std::runtime_error &e)
	{
		std::cerr << e.what() << std::endl;
		return false;
	}
	
	lCity.Init(game, rm, 0, 480);
	mCity.Init(game, rm, 640 / 2, 480);
	rCity.Init(game, rm, 640, 480);


	dot.Init(game, rm, 0, 0);
	return true;
}

void State_Gameplay::HandleEvents(SDL_Event* event)
{
	if (event->type == SDL_QUIT)
		game->PopState();

	dot.HandleEvents(event);
}

void State_Gameplay::Update(float deltaTime)
{
	const Uint8 *keyboard = SDL_GetKeyboardState(NULL);
	if (keyboard[SDL_SCANCODE_W])
		dot.Move(0, -1);
	if (keyboard[SDL_SCANCODE_S])
		dot.Move(0, 1);
	if (keyboard[SDL_SCANCODE_A])
		dot.Move(-1, 0);
	if (keyboard[SDL_SCANCODE_D])
		dot.Move(1, 0);
	if (keyboard[SDL_SCANCODE_W] && keyboard[SDL_SCANCODE_D])
		dot.Move(1, -1);
	if (keyboard[SDL_SCANCODE_W] && keyboard[SDL_SCANCODE_A])
		dot.Move(-1, -1);
	if (keyboard[SDL_SCANCODE_S] && keyboard[SDL_SCANCODE_D])
		dot.Move(1, 1);
	if (keyboard[(SDL_SCANCODE_S)] && keyboard[SDL_SCANCODE_A])
		dot.Move(-1, 1);

	if (dot.collidesWith(&lCity))
	{
		lCity.destroy = true;
		dot.destroy = true;
	}
	else
	{
		lCity.destroy = false;
		dot.destroy = false;
	}

	lCity.Update(deltaTime);
	mCity.Update(deltaTime);
	rCity.Update(deltaTime);

	dot.Update(deltaTime);

}

void State_Gameplay::Render()
{
	lCity.colorMod(0, 0, 255);
	lCity.Render();
	mCity.colorMod(255, 100, 0);
	mCity.Render();
	rCity.colorMod(255, 255, 255);
	rCity.Render();

	dot.Render();
}

void State_Gameplay::Quit()
{
	rm->~Resource_Manager();
}
