#include "SphereCollider.h"
using namespace kep;

SphereCollider::SphereCollider(RigidBody * _rigidBody, Matrix4 _offset) : Collider(_rigidBody, _offset)
{
}
SphereCollider::~SphereCollider()
{
}

