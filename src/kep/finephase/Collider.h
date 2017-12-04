#ifndef COLLIDER_H_
#define COLLIDER_H_
#include "../Core.h"
namespace kep
{
    class RigidBody;
    class Collider
    {
    public:
        RigidBody * rigidBody;
        Matrix4 offset;
        Collider(RigidBody * _rigidBody = NULL, Matrix4 _offset = Matrix4());
        ~Collider();
    };
};

#endif //COLLIDER_H_
