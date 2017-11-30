#ifndef WORLD_H_
#define WORLD_H_

#include <vector>
#include "Entity.h"


//Made up of entities
namespace kelp
{
    class Core;
    class Component;
    
    class Entity;
    class Camera;
    class Light;
    class World
    {
    public:
        Core * m_core;
        Camera * m_renderCamera;
        std::vector<Light*> m_lights;
        std::vector<Entity*> m_entities;
        std::vector<Entity*> m_newEntities;//entities to be added ie. initializer not called yet-- BCUZ ENTITY CANT BE ADDED MID LOOP
        std::vector<Entity*> m_exiledEntities;//entities to be deleted on the next frame
        World(Core * _core);
        virtual ~World()=0;
        virtual void updateV()=0;
        void update();
        int deleteEntity(Entity * _entity);
        int deleteEntityNextFrame(Entity * _entity);
    };
};
#endif // WORLD_H_
