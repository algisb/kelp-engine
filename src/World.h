#ifndef WORLD_H_
#define WORLD_H_

#include <vector>
#include "Entity.h"

//Made up of entities
namespace kelp
{
    
    class Component;
    
    class Entity;
    class Shader;
    class Camera;
    class Light;
    class World
    {
    public:
        bool m_init;
        Camera * m_renderCamera;
        std::vector<Light*> m_lights;
        std::vector<Shader*> m_shaders;
        std::vector<Entity*> m_entities;
        World();
        virtual ~World()=0;
        virtual void updateV()=0;
        void update();
    };
};
#endif // WORLD_H_
