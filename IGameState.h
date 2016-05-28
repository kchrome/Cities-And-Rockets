#ifndef IGAME_STATE_H
#define IGAME_STATE_H

#include <SDL2/SDL.h>
#include "Game.h"

class IGameState
{
protected:
	Game* game;

public:
	virtual bool Init(Game* game) = 0;
	virtual void HandleEvents(SDL_Event* event) = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Render() = 0;
	virtual void Quit() = 0;

};

#endif
