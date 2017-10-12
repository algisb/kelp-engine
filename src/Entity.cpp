///
///  @file Entity.cpp
///  @brief Anything and everything

#include "Entity.h"
using namespace kelp;

Entity::Entity(std::string _tag)
{
    m_tag = _tag;
}
Entity::~Entity()
{
    for(int i = 0; i< m_components.size(); i++)
        delete m_components[i];
    m_components.clear();
}

void Entity::update()
{
    for(int i = 0; i< m_components.size(); i++)
        m_components[i]->update();
}

void Entity::addComponent(Component * io_c)
{
    io_c->m_owner = this;
    m_components.push_back(io_c);
}

