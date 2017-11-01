#ifndef WORLD_H_
#define WORLD_H_

#include <vector>
//#include "glm.hpp"
//#include "component/Camera.h"
#include "Entity.h"

//Made up of entities
namespace kelp
{
    class Camera;
    class Component;
    class Entity;
    class World
    {
    public:
        bool m_init;
        Camera * m_renderCamera;
        std::vector<Entity*> m_entities;
        World();
        virtual ~World()=0;
        virtual void updateV()=0;
        void update();
    };
};
#endif // WORLD_H_
