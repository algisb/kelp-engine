#ifndef SPHERECOLLIDER_H_
#define SPHERECOLLIDER_H_
#include "Collider.h"
namespace kep
{
    class SphereCollider : public Collider
    {
    public:
        SphereCollider(RigidBody * _rigidBody = NULL, Matrix4 _offset = Matrix4());
        ~SphereCollider();
    };
};

#endif //SPHERECOLLIDER_H_
