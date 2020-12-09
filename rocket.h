#ifndef ROCKET
#define ROCKET

#include "IObject.h"

class rocket : public IObject
{

private:
        gTexture* sheet;
        
        
        

public:
        void Init(Game* game, Resource_Manager* rm, float x = 0;, float y = 0);
        void Update(float deltaTime);
        void HandleEvents(SDL_Event* event);
        void Render();
        
        // void Trajectory();
}
