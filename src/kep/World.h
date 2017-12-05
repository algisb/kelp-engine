#ifndef KEPWORLD_H_
#define KEPWORLD_H_

#include "RigidBody.h"
#include "ForceGenerator.h"
#include "collisionDetection/CollisionDetector.h"
namespace kep
{
    class World
    {
    public:
        std::vector<RigidBody*> rigidBodies;
        ForceRegistry * fReg;
        Gravity * gGen;
        LinearDrag * ldGen;
        AngularDrag * adGen;
        CollisionDetector * cDetec;
        World();
        ~World();
        void update(real _duration);
        void addRigidBody(RigidBody * _rigidBody);
    };
}

#endif //KEPWORLD_H_
