#ifndef COLLISIONDETECTOR_H_
#define COLLISIONDETECTOR_H_
#include "../RigidBody.h"
#include "finephase/CollisionData.h"
#include <vector>
namespace kep
{
    class CollisionDetector
    {
    public:
        std::vector<RigidBody*> * rigidBodies;
        CollisionDetector();
        ~CollisionDetector();
        void detect(CollisionData * _collisionData);
    private:
        void broadPhase();
        void finePhase();
    };
};

#endif // COLLISIONDETECTOR_H_
