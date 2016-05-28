#include "Game.h"
#include "IGameState.h"


void Game::PushState(IGameState* state)
{
	states.push_back(state);
	if (state->Init(this) == NULL)
	{
		quit = true;
	}
}

void Game::PopState()
{
	states.back()->Quit();
	delete states.back();
	states.pop_back();
	if (states.size() == 0)
	{
		quit = true;
	}
}