#ifndef STATE_GAMEPLAY_H
#define STATE_GAMEPLAY_H

#include <list>

#include "IGameState.h"
#include "IObject.h"
#include "Resource_Manager.h"
#include "City.h"
#include "Dot.h"

#include <string>

class State_Gameplay : public IGameState
{
private:
	Resource_Manager* rm;
	City lCity, mCity, rCity;
	Dot dot;
	std::list<City> cities;

	std::string name;



public:
	bool Init(Game* game);
	void HandleEvents(SDL_Event* event);
	void Update(float deltaTime);
	void Render();
	void Quit();
};

#endif