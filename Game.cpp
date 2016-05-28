#include "Game.h"
#include "IGameState.h"

#include <iostream>
#include <time.h>

Game::Game()
{
	window = NULL;
	renderer = NULL;

	screenWidth = SCREENWIDTH;
	screenHeight = SCREENHEIGHT;
	
	oldtime = 0;

	quit = false;
}

bool Game::Init(IGameState* state)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cerr << SDL_GetError() << std::endl;
		return false;
	}

	window = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		std::cerr << SDL_GetError() << std::endl;
		return false;
	}

	renderer = SDL_CreateRenderer(window, NULL, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == NULL)
	{
		std::cerr << SDL_GetError();
		return false;
	}

	srand(time(NULL)); 

	PushState(state);

	return true;
}

void Game::Thread()
{
	while (quit == false)
	{
		Update();
		Render();
	}
	Quit();
}

void Game::Update()
{
	while (SDL_PollEvent(&event))
	{
		if (states.size() > 0)
			states.back()->HandleEvents(&event);
	}
	if (states.size() > 0)
	{
		oldtime = newtime;
		newtime = SDL_GetTicks();

		if (newtime > oldtime)
		{
			float deltaTime = (float)(newtime - oldtime) / 1000.0f;

			states.back()->Update(deltaTime);
		}
	}
}


void Game::Render()
{
	//Clear the back buffer
	SDL_SetRenderDrawColor(renderer,0x00, 0x00, 0x00, 0xFF);
	//SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(renderer);

	//Render onto the back buffer
	if (states.size() > 0)
		states.back()->Render();

	//Switch front and the back buffer
	SDL_RenderPresent(renderer);

}

SDL_Renderer* Game::getRenderer()
{
	return renderer;
}

void Game::Quit()
{
	while (states.size() > 0)
	{
		states.back()->Quit();
		delete states.back();
		states.pop_back();
	}

	IMG_Quit();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Game::setQuit()
{
	quit = true;
}
