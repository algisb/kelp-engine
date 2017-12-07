#ifndef MESHCOLLIDER_H_
#define MESHCOLLIDER_H_
#include "Collider.h"

namespace kep
{
    class Triangle
    {
    public:
        kep::Vector3 p[3];
        kep::Vector3 n;
        Triangle(kep::Vector3 _p0 = kep::Vector3(0.0f, 0.0f, 0.0f), 
                 kep::Vector3 _p1 = kep::Vector3(0.0f, 0.0f, 0.0f), 
                 kep::Vector3 _p2 = kep::Vector3(0.0f, 0.0f, 0.0f), 
                 kep::Vector3 _n = kep::Vector3(0.0f ,0.0f, 0.0f));
        ~Triangle();
    };
    
    
    class MeshCollider : public Collider
    {
    public:
        
        int numTriangles;
        Triangle * triangles;
        Triangle * tTriangles;
        
        MeshCollider(Matrix4 _offset, float * _dataV, float * _dataN, int _numVertex, kep::Vector3 _scale);
        ~MeshCollider();
        void update();
        int spherePlane(kep::Vector3 _spherePosition,
                        float _sphereRadius,
                        kep::Vector3 _planeNormal,
                        kep::Vector3 _planePosition,
                        
                        kep::Vector3 * _contactPosition,
                        float * _penetration);
        
        virtual int collides(Collider * _c, CollisionData * _collisionData);
        
        virtual int collides(SphereCollider * _c, CollisionData * _collisionData);
        virtual int collides(HalfPlaneCollider * _c, CollisionData * _collisionData);
        virtual int collides(OBBCollider * _c, CollisionData * _collisionData);
        virtual int collides(MeshCollider * _c, CollisionData * _collisionData);
    };
};

#endif //MESHCOLLIDER_H_
