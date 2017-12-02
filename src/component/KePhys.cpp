#include "KePhys.h"
#include "Transform.h"
using namespace kelp;
KePhys::KePhys(float _mass)
{
    m_rigidBody = new kep::RigidBody(kep::Vector3(),kep::Quaternion(), _mass);
}
KePhys::~KePhys()
{
}
void KePhys::init()
{
    m_rigidBody->position = m_owner->m_transform->m_position;
    m_rigidBody->orientation = m_owner->m_transform->m_orientation;
    
    m_owner->m_world->m_physWorld->addRigidBody(m_rigidBody);
}
void KePhys::update()
{
    m_owner->m_transform->m_position = m_rigidBody->position;
    m_owner->m_transform->m_orientation = m_rigidBody->orientation;
    //m_rigidBody->position.dump();
}
void KePhys::render()
{
}



