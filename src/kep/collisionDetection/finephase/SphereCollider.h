#ifndef SPHERECOLLIDER_H_
#define SPHERECOLLIDER_H_
#include "Collider.h"
namespace kep
{
    class SphereCollider : public Collider
    {
    public:
        real radius;
        SphereCollider(Matrix4 _offset = Matrix4(), real _radius = 1.0f);
        ~SphereCollider();
        virtual int collides(Collider * _c, CollisionData * _collisionData);

        virtual int collides(SphereCollider * _c, CollisionData * _collisionData);
    };
};

#endif //SPHERECOLLIDER_H_
