#ifndef KEPWORLD_H_
#define KEPWORLD_H_

#include "RigidBody.h"
#include "ForceGenerator.h"
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
        
        World();
        ~World();
        void update(real _duration);
        void addRigidBody(RigidBody * _rigidBody);
    };
}

#endif //KEPWORLD_H_
