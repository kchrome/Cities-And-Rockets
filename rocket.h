#ifndef ROCKET
#define ROCKET

#include "IObject.h"

class rocket : public IObject
{

private:
        gTexture* sheet;
        
        
        

public:
        void Init();
        void Update();
        void HandleEvents()
        void Render();
        
        
}
