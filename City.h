#ifndef CITY_H
#define CITY_H

#define SHEET_COL 7.0f
#define SHEET_ROW 1.0f

#include "IObject.h"

class City : public IObject
{
private:
	gTexture* sheet;

	float sheet_row,
		sheet_column,
		animationSpeed,
		time;
public:
	bool destroy;
protected:

	static float scale;

public:

	void Init(Game* game, Resource_Manager* rm, float x = 0, float y = 0);
	void Update(float deltaTime);
	void HandleEvents(SDL_Event* event);
	void Render();

	void colorMod(int, int, int);
	void Destroy();
	void animateDestruction();
};

#endif	