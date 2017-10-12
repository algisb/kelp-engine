///
///  @file World.cpp
///  @brief holds all the entities that get created also loads models and other shared objects

#include "World.h"
using namespace kelp;

World::World()
{
    
}
World::~World()
{
    for(int i = 0; i< m_entities.size(); i++)
        delete m_entities[i];
    m_entities.clear();
}

void World::update()
{
    updateV();
    for(int i = 0; i< m_entities.size(); i++)
        m_entities[i]->update();
    
    for(int i = 0; i< m_entities.size(); i++)
        m_entities[i]->render();
    
}

