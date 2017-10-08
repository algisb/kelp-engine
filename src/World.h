#ifndef WORLD_H
#define WORLD_H
#include "glm.hpp"
//Made up of entities
namespace kelp
{
    class World
    {
    public:
        glm::vec3 v1;
        World();
        ~World();
        void update();
        
    };
};
#endif
