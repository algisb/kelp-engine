#include "OBBCollider.h"
using namespace kep;
OBBCollider::OBBCollider(kep::Vector3 _halfSize)
{
    halfSize = _halfSize;
}

OBBCollider::~OBBCollider()
{
}
int OBBCollider::collides(Collider* _c, CollisionData* _collisionData)
{
    return _c->collides(this, _collisionData);
}
int OBBCollider::collides(SphereCollider* _c, CollisionData* _collisionData)
{
    return 0;
}
int OBBCollider::collides(HalfPlaneCollider* _c, CollisionData* _collisionData)
{
    return 0;
}
int OBBCollider::collides(OBBCollider* _c, CollisionData* _collisionData)
{
    return 0;
}


