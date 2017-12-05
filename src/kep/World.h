#ifndef KEPWORLD_H_
#define KEPWORLD_H_

#include "RigidBody.h"
#include "ForceGenerator.h"
#include "broadphase/PotencialContact.h"
#include "broadphase/BoundingSphere.h"
#include "finephase/CollisionData.h"
namespace kep
{
    class World
    {
    public:
        std::vector<RigidBody*> m_rigidBody;
        ForceRegistry * m_fReg;
        Gravity * m_gGen;
        LinearDrag * m_ldGen;
        AngularDrag * m_adGen;
        
        World();
        ~World();
        void update(real _duration);
        void addRigidBody(RigidBody * _rigidBody);
    };
}

#endif //KEPWORLD_H_
