#include "SphereCollider.h"
using namespace kep;

SphereCollider::SphereCollider(Matrix4 _offset, real _radius) : Collider(_offset)
{
    radius = _radius;
    maxReach = radius;
}
SphereCollider::~SphereCollider()
{
}
int SphereCollider::collides(Collider * _c, CollisionData * _collisionData)
{
    return _c->collides(this, _collisionData);
}

int SphereCollider::collides(SphereCollider * _c, CollisionData * _collisionData)
{
    Vector3 positionOne = _c->rigidBody->collider->transform.getAxisVector(3);
    Vector3 positionTwo = rigidBody->collider->transform.getAxisVector(3);
    Vector3 midline = positionOne - positionTwo;
    real size = midline.magnitude();
    real totalR = _c->radius+radius;
    if (size <= 0.0f || size >= totalR)
    {
        return 0;
    }
    
    Contact contact;
    contact.body[0] = _c->rigidBody;
    contact.body[1] = rigidBody;
    contact.normal = midline * (((real)1.0)/size);
    contact.position = positionOne + midline * (real)0.5;
    contact.penetration = (totalR - size);
    _collisionData->contacts.push_back(contact);
    return 1;
}
int SphereCollider::collides(HalfPlaneCollider * _c, CollisionData * _collisionData)
{
    printf("in Sphere class\n");
    return 0;
}
int SphereCollider::collides(OBBCollider * _c, CollisionData * _collisionData)
{
    return 0;
}


