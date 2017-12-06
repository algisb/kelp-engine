#ifndef OBBCOLLIDER_H_
#define OBBCOLLIDER_H_
#include "Collider.h"
namespace kep
{
    class HalfPlaneCollider;
    class SphereCollider;
    class OBBCollider : public Collider
    {
    public:
        kep::Vector3 halfSize;
        OBBCollider(kep::Vector3 _halfSize);
        ~OBBCollider();
        virtual int collides(Collider * _c, CollisionData * _collisionData);
        
        virtual int collides(SphereCollider * _c, CollisionData * _collisionData);
        virtual int collides(HalfPlaneCollider * _c, CollisionData * _collisionData);
        virtual int collides(OBBCollider * _c, CollisionData * _collisionData);
        
    };
};
#endif //OBBCOLLIDER_H_
