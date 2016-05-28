#include "Game.h"
#include "IObject.h"

class Dot : public IObject
{
private:
	gTexture* sheet;
	int velocity; 
	int dx, dy;

public:
	bool destroy;

public:
	void Init(Game* game, Resource_Manager* rm, float x = 0, float y = 0);
	void Update(float deltaTime);
	void HandleEvents(SDL_Event* event);
	void Render();

	void Move(int, int);
};