#ifndef COLLIDER_H_
#define COLLIDER_H_
#include "../../Core.h"
#include "CollisionData.h"
namespace kep
{
    class OBBCollider;
    class HalfPlaneCollider;
    class SphereCollider;
    class RigidBody;
    class Collider
    {
    public:
        RigidBody * rigidBody;//set inside rigidBody constructor
        Matrix4 offset;
        Matrix4 transform;
        
        Collider(Matrix4 _offset = Matrix4());
        virtual ~Collider()=0;
        virtual int collides(Collider * _c, CollisionData * _collisionData)=0;
        
        virtual int collides(SphereCollider * _c, CollisionData * _collisionData)=0;
        virtual int collides(HalfPlaneCollider * _c, CollisionData * _collisionData)=0;
        virtual int collides(OBBCollider * _c, CollisionData * _collisionData)=0;
    };
};

#endif //COLLIDER_H_
