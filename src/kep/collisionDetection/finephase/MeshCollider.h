#ifndef MESHCOLLIDER_H_
#define MESHCOLLIDER_H_
#include "Collider.h"

namespace kep
{
    class MeshCollider : public Collider
    {
    public:
        MeshCollider(Matrix4 _offset = Matrix4());
        ~MeshCollider();
        
        virtual int collides(Collider * _c, CollisionData * _collisionData);
        
        virtual int collides(SphereCollider * _c, CollisionData * _collisionData);
        virtual int collides(HalfPlaneCollider * _c, CollisionData * _collisionData);
        virtual int collides(OBBCollider * _c, CollisionData * _collisionData);
        virtual int collides(MeshCollider * _c, CollisionData * _collisionData);
    };
};

#endif //MESHCOLLIDER_H_
