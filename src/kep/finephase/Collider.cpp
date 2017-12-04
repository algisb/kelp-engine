#include "Collider.h"
#include "../RigidBody.h"
using namespace kep;
Collider::Collider(RigidBody* _rigidBody, Matrix4 _offset)
{
    rigidBody = _rigidBody;
    offset = _offset;
}
Collider::~Collider()
{
}

