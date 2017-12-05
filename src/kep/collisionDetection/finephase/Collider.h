#ifndef COLLIDER_H_
#define COLLIDER_H_
#include "../../Core.h"
#include "CollisionData.h"
namespace kep
{
    class SphereCollider;
    class RigidBody;
    class Collider
    {
    public:
        RigidBody * rigidBody;
        Matrix4 offset;
        Collider(Matrix4 _offset = Matrix4());
        virtual ~Collider()=0;
        virtual int collides(Collider * _c, CollisionData * _collisionData)=0;
        
        virtual int collides(SphereCollider * _c, CollisionData * _collisionData)=0;
        
    };
};

#endif //COLLIDER_H_
