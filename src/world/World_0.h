#ifndef WORLD_0_H
#define WORLD_0_H

#include "World.h"
#include "Shader.h"
#include "Mesh.h"
#include "component/Transform.h"
#include "component/InputController.h"
#include "component/Render.h"

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
