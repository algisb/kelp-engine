#ifndef RIGIDBODY_H_
#define RIGIDBODY_H_
#include "Core.h"

namespace kep
{
    class BoundingSphere;
    class RigidBody
    {
    public:
        bool externPO;//externaly defined position and orientation
        
        real inverseMass;
        
        Vector3 * position;
        Quaternion * orientation;
        
        Vector3 velocity;
        Vector3 angularVelocity;
        
        Vector3 acceleration;

        
        Vector3 forceAccum;
        Vector3 torqueAccum;
        
        
        Matrix4 transformMatrix;
        
        Matrix3 inverseInertiaTensor;
        Matrix3 inverseInertiaTensorWorld;
        
        //Collision related
        BoundingSphere * boundingVolume;
        

        
        RigidBody(Vector3 * _position = NULL, Quaternion * _orientation = NULL, real _mass = 1.0f, bool _externPO = false);
        ~RigidBody();
        void calculateDerivedData();
        void setInertiaTensor(const Matrix3 &_inertiaTensor);
        
        void transformInertiaTensor(Matrix3 &_iitWorld,
                                    const Quaternion &_q,
                                    const Matrix3 &_iitBody,
                                    const Matrix4 &_rotmat);
        
        void addForce(const Vector3 &_force);
        void addTorque(const Vector3 &_torque);
        
        void addForceAtPoint(const Vector3 &_force,
                             const Vector3 &_point);
        void addForceAtBodyPoint(const Vector3 &_force,
                                 const Vector3 &_point);
        
        void integrate(real _duration);
        void clearAccumulators();
        real getMass();
        bool hasFiniteMass();
    };
}
#endif //RIGIDBODY_H_
