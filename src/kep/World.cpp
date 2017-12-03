#include "World.h"
using namespace kep;

World::World()
{
    m_fReg = new ForceRegistry();
    
    m_gGen = new Gravity(Vector3(0.0f, -9.81f, 0.0f));
    m_ldGen = new LinearDrag(0.1f, 0.001f);
    m_adGen = new AngularDrag(0.5, 0.1f);
}
World::~World()
{
    delete m_fReg;
    delete m_gGen;
    delete m_ldGen;
    delete m_adGen;
}
void World::update(real _duration)
{
    std::vector<PotencialContact> potencialContacts;
    //broadphase collision check
    for(int i = 0; i < m_rigidBody.size(); i++)
        for(int j = 0; j < m_rigidBody.size(); j++)
        {
            if(i==j)//dont check collision against self
                continue;
            if(m_rigidBody[i]->boundingVolume.overlaps(&m_rigidBody[j]->boundingVolume))
            {
                potencialContacts.push_back(PotencialContact(m_rigidBody[i], m_rigidBody[j]));
                printf("we have contact nigga !!\n");
            }
            
        }
    //fine collision check
    
    m_fReg->updateForces(_duration);
    for(int i = 0; i < m_rigidBody.size(); i++)
        m_rigidBody[i]->integrate(_duration);
    
}
void World::addRigidBody(RigidBody * _rigidBody)
{
    //m_fReg->add(_rigidBody, m_gGen);
    m_fReg->add(_rigidBody, m_ldGen);
    m_fReg->add(_rigidBody, m_adGen);
    m_rigidBody.push_back(_rigidBody);
}
