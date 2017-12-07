#include "MeshCollider.h"
using namespace kep;

int MeshCollider::collides(Collider* _c, CollisionData* _collisionData)
{
    return collides(this, _collisionData);
}
int MeshCollider::collides(SphereCollider* _c, CollisionData* _collisionData)
{
    return 0;
}
int MeshCollider::collides(HalfPlaneCollider* _c, CollisionData* _collisionData)
{
    return 0;
}
int MeshCollider::collides(OBBCollider* _c, CollisionData* _collisionData)
{
    return 0;
}
int MeshCollider::collides(MeshCollider * _c, CollisionData * _collisionData)
{
    return 0;
}


