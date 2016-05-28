#ifndef IOBJECT
#define IOBJECT

#include "Game.h"
#include "Resource_Manager.h"

class IObject
{
protected:
	/*pos in the world*/
	float x, y;

	/*size in pixels*/
	float sizeX, sizeY;

	Game* game;
	Resource_Manager* rm;

	SDL_Rect source_rect;
	SDL_Rect dest_rect;

public:
	virtual void Init(Game* game, Resource_Manager* rm, float = 0, float = 0) = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void HandleEvents(SDL_Event* event) = 0;
	virtual void Render() = 0;

	bool collidesWith(IObject* other);


};

#endif