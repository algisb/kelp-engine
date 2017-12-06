#ifndef COLLISIONRESOLVER_H_
#define COLLISIONRESOLVER_H_
#include "collisionDetection/finephase/CollisionData.h"
namespace kep
{
    class CollisionResolver 
    {
    public:
        CollisionResolver();
        ~CollisionResolver();
        void resolve(CollisionData * _cd);
    };
};

#endif //COLLISIONRESOLVER_H_
