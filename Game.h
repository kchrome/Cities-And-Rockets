#ifndef GAME_H
#define GAME_H

#define CITY "Data/city.png"
#define DOT "Data/dot.png"
#define TITLE "CitiesAndRockets"
#define SCREENWIDTH 640
#define SCREENHEIGHT 480

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <vector>

class IGameState;


class Game
{
private: 
	SDL_Window* window;
	SDL_Renderer* renderer;

	SDL_Event event;
	int screenHeight, screenWidth;

	bool quit;

	Uint32 oldtime,
		   newtime;

	std::vector<IGameState*> states;
public:

	Game();
	bool Init(IGameState* state);
	void Thread();

private:
	void Update();
	void Render();
	void Quit();

public:
	//state management functions
	void PushState(IGameState* state);
	void PopState();

	//Forces game to quit regardless of states on stack
	void setQuit();

	SDL_Renderer* getRenderer();



};
#endif
