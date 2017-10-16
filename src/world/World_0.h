#ifndef WORLD_0_H
#define WORLD_0_H

#include "Shader.h"
#include "World.h"
#include "component/Transform.h"
#include "component/InputController.h"

namespace kelp
{
    class World_0 : public World
    {
    public:
        Entity * empty[10];
        
        World_0();
        ~World_0();
        void updateV();
    };
    
};


#endif // WORLD_0_H
