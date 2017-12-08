#include "ContactResolver.h"
#include "RigidBody.h"
using namespace kep;
ContactResolver::ContactResolver()
{
}
ContactResolver::~ContactResolver()
{
}
void ContactResolver::resolve(CollisionData * _cd)//TODO: for now its does fuckall
{
    for(uint64_t i = 0; i<_cd->contacts.size();i++)
    {
        Contact * c = &_cd->contacts[i];
        c->body[0]->addForce(c->normal * 200.0f);
        c->body[1]->addForce(c->normal * -1.0f * 200.0f);
    }
}

