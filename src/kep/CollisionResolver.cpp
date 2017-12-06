#include "CollisionResolver.h"
#include "RigidBody.h"
using namespace kep;
CollisionResolver::CollisionResolver()
{
}
CollisionResolver::~CollisionResolver()
{
}
void CollisionResolver::resolve(CollisionData * _cd)//TODO: for now its does fuckall
{
    for(uint64_t i = 0; i<_cd->contacts.size();i++)
    {
        Contact * c = &_cd->contacts[i];
        RigidBody * rb = c->body[0];
        rb->addForce(c->normal * 100.0f);
    }
}

