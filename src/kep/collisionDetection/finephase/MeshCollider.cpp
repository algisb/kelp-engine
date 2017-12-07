#include "MeshCollider.h"
#include "SphereCollider.h"
using namespace kep;

Triangle::Triangle(kep::Vector3 _p0, kep::Vector3 _p1, kep::Vector3 _p2, kep::Vector3 _n)
{
    p[0] = _p0;
    p[1] = _p1;
    p[2] = _p2;
    n = _n;
}

Triangle::~Triangle()
{
}



MeshCollider::MeshCollider(Matrix4 _offset, float* _dataV, float* _dataN, int _numVertex, kep::Vector3 _scale)
{
    numTriangles = _numVertex/3;
    triangles = new Triangle[numTriangles];
    tTriangles = new Triangle[numTriangles];
    maxReach = 1.0f;
    
    kep::Matrix3 scaleMat(_scale.x, 0.0f, 0.0f,
                          0.0f, _scale.y, 0.0f,
                          0.0f, 0.0f, _scale.z);
    for(int i = 0; i <_numVertex*3; i = i + 3)//maxReach calculated at the initilization if the mesh changes size at runtime the bounding volume will not follow
    {
        kep::Vector3 v(_dataV[i+0],_dataV[i+1],_dataV[i+2]);
        float mag = (scaleMat*v).magnitude();
        if(mag > maxReach)
            maxReach = mag;
    }
    
    
    printf("%f \n", maxReach);
    
    for(int i = 0; i <_numVertex*3; i = i + 9)
    {
        triangles[i/9] = Triangle(kep::Vector3( _dataV[i+0], _dataV[i+1], _dataV[i+2]),
                            kep::Vector3( _dataV[i+3], _dataV[i+4], _dataV[i+5]),
                            kep::Vector3( _dataV[i+6], _dataV[i+7], _dataV[i+8]),
                            kep::Vector3( _dataN[i+0], _dataN[i+1], _dataN[i+2]));
    }
}
MeshCollider::~MeshCollider()
{
    delete [] triangles;
    delete [] tTriangles;
}

void MeshCollider::update()
{
    for(int i = 0 ; i < numTriangles; i++)
    {
        tTriangles[i] = Triangle(transform * triangles[i].p[0],
                                 transform * triangles[i].p[1],
                                 transform * triangles[i].p[2],
                                 kep::Matrix3(transform) * triangles[i].n);
    }
}

int MeshCollider::spherePlane(kep::Vector3 _spherePosition,
                              float _sphereRadius,
                              kep::Vector3 _planeNormal,
                              kep::Vector3 _planePosition,
                              
                              kep::Vector3 * _contactPosition,
                              float * _penetration
                             )
{
    Vector3 position = _spherePosition - _planePosition;
    real ballDistance = _planeNormal * position - _sphereRadius;
    if (ballDistance >= 0 ||
        abs(ballDistance) > _sphereRadius)//no contacts generated if on the other side of the plane 
        return 0;
    
    *_contactPosition = position - _planeNormal * (ballDistance + _sphereRadius);
    *_penetration = -ballDistance;
    return 1;
}

int MeshCollider::collides(Collider* _c, CollisionData* _collisionData)
{
    return collides(this, _collisionData);
}
int MeshCollider::collides(SphereCollider* _c, CollisionData* _collisionData)
{
    int totalContacts = 0;
    for(int i = 0 ; i < numTriangles; i++)
    {
        kep::Vector3 contactPosition;
        float penetration = 0.0f;
        
        int test = spherePlane(_c->transform.getAxisVector(3),
                    _c->radius,
                    tTriangles[i].n, 
                    tTriangles[i].p[0], 
                    &contactPosition, 
                    &penetration);
        
        if(test == 0)
            continue;
        Contact contact;
        contact.body[1] = rigidBody;
        contact.body[0] = _c->rigidBody;
        contact.normal = tTriangles[i].n;
        contact.position = contactPosition;
        contact.penetration = penetration;
        _collisionData->contacts.push_back(contact);
        totalContacts++;
        //break //uncommet to limit the mesh collider to generating only 1 contact
    }
    //printf("%d\n", totalContacts);
    return totalContacts;
}
int MeshCollider::collides(HalfPlaneCollider* _c, CollisionData* _collisionData)
{
    return 0;
}
int MeshCollider::collides(OBBCollider* _c, CollisionData* _collisionData)
{
    return 0;
}
int MeshCollider::collides(MeshCollider * _c, CollisionData * _collisionData)
{
    return 0;
}


