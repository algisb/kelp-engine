#ifndef KEPWORLD_H_
#define KEPWORLD_H_

#include "RigidBody.h"
#include "ForceGenerator.h"
#include "collisionDetection/CollisionDetector.h"
#include "CollisionResolver.h"
namespace kep
{
    class World
    {
    public:
        real targetTimeStep;
        real timeStepAccumulator;
        std::vector<RigidBody*> rigidBodies;
        ForceRegistry * fReg;
        Gravity * gGen;
        LinearDrag * ldGen;
        AngularDrag * adGen;
        CollisionDetector * cDetec;
        CollisionResolver * cRes;
        World();
        ~World();
        void update(real _deltaT);
        void addRigidBody(RigidBody * _rigidBody);
    };
}

#endif //KEPWORLD_H_
