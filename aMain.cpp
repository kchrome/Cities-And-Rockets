#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdexcept>

#include "Game.h"
#include "State_Gameplay.h"

int main(int argc, char* args[])
{
	Game g;

	while (g.Init(new State_Gameplay()))
	{
		g.Thread();
	}
	
	return 0;
}
