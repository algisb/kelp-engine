#ifndef CONTACTRESOLVER_H_
#define CONTACTRESOLVER_H_
#include "collisionDetection/finephase/CollisionData.h"
namespace kep
{
    class ContactResolver 
    {
    public:
        ContactResolver();
        ~ContactResolver();
        void resolve(CollisionData * _cd);
    };
};

#endif //CONTACTRESOLVER_H_
