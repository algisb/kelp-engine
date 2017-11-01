///
///  @file World.cpp
///  @brief all worlds are derived from this class

#include "World.h"
using namespace kelp;

World::World()
{
    m_init = false;
    m_renderCamera = NULL;
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
    if(!m_init)
    {
        for(int i = 0; i< m_entities.size(); i++)
            m_entities[i]->init();
        m_init = true;
    }
    for(int i = 0; i< m_entities.size(); i++)
        m_entities[i]->update();
    
    for(int i = 0; i< m_entities.size(); i++)
        m_entities[i]->render();
    
}

