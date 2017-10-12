#ifndef WORLD_H_
#define WORLD_H_

#include <vector>
#include "glm.hpp"
#include "Entity.h"

//Made up of entities
namespace kelp
{
    class World
    {
    public:
        std::vector<Entity*> m_entities;
        World();
        virtual ~World()=0;
        void update();
        inline void addEntity(Entity * _e)
        {
            m_entities.push_back(_e);
        }
        
    };
};
#endif // WORLD_H_
