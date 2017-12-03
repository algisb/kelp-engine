#include "BoundingSphere.h"
using namespace kep;
BoundingSphere::BoundingSphere()
{
    
}
BoundingSphere::BoundingSphere(Vector3 _position, real _radius)
{
    exterP = false;
    position = new Vector3();
    *position = _position;
    radius = _radius;
}
BoundingSphere::BoundingSphere(Vector3 * _position, real _radius)
{
    exterP = true;
    position = _position;
    radius = _radius;
}
BoundingSphere::~BoundingSphere()
{
    if(!exterP)
        delete position;
}

bool BoundingSphere::overlaps(BoundingSphere *_other)
{
    real distanceSquared = (*position - *_other->position).squareMagnitude();
    return distanceSquared < (radius+_other->radius)*(radius+_other->radius);
}
