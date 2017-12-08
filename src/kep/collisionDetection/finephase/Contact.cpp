#include "Contact.h"
using namespace kep;

Contact::Contact()
{
}

Contact::~Contact()
{
}

void Contact::calculateContactBasis()
{
      Vector3 contactTangent[2];

    // Check whether the Z-axis is nearer to the X or Y axis
    if (real_abs(normal.x) > real_abs(normal.y))
    {
        // Scaling factor to ensure the results are normalised
        const real s = (real)1.0f/real_sqrt(normal.z*normal.z +
            normal.x*normal.x);

        // The new X-axis is at right angles to the world Y-axis
        contactTangent[0].x = normal.z*s;
        contactTangent[0].y = 0;
        contactTangent[0].z = -normal.x*s;

        // The new Y-axis is at right angles to the new X- and Z- axes
        contactTangent[1].x = normal.y*contactTangent[0].x;
        contactTangent[1].y = normal.z*contactTangent[0].x - normal.x*contactTangent[0].z;
        contactTangent[1].z = -normal.y*contactTangent[0].x;
    }
    else
    {
        // Scaling factor to ensure the results are normalised
        const real s = (real)1.0/real_sqrt(normal.z*normal.z +
            normal.y*normal.y);

        // The new X-axis is at right angles to the world X-axis
        contactTangent[0].x = 0;
        contactTangent[0].y = -normal.z*s;
        contactTangent[0].z = normal.y*s;

        // The new Y-axis is at right angles to the new X- and Z- axes
        contactTangent[1].x = normal.y*contactTangent[0].z -
            normal.z*contactTangent[0].y;
        contactTangent[1].y = -normal.x*contactTangent[0].z;
        contactTangent[1].z = normal.x*contactTangent[0].y;
    }

    // Make a matrix from the three vectors.
    contactToWorld.setComponents(normal, contactTangent[0],contactTangent[1]);
}
void Contact::resolve()
{
    calculateContactBasis();
    Vector3 relativeContactPosition[2] = {position - *body[0]->position, position - *body[1]->position};
    // Build a vector that shows the change in velocity in
    // world space for a unit impulse in the direction of the contact
    // normal.
    Vector3 velocity;

    real deltaVelocity = 0;
    if(body[0]->hasFiniteMass())
    {
        Vector3 deltaVelWorld = relativeContactPosition[0] % normal;
        deltaVelWorld = body[0]->inverseInertiaTensorWorld * deltaVelWorld;
        deltaVelWorld = deltaVelWorld % relativeContactPosition[0];
        // Work out the change in velocity in contact coordinates.
        deltaVelocity += deltaVelWorld * normal;
        // Add the linear component of velocity change.
        deltaVelocity += body[0]->inverseMass;
        
        ///////////////////////////
        velocity += body[0]->angularVelocity % relativeContactPosition[0];
        velocity += body[0]->velocity;
        
    }
    // Check whether we need to consider the second body’s data.
    if (body[1]->hasFiniteMass())
    {
        // Find the inertia tensor for this body.
        //body[1]->getInverseInertiaTensorWorld(&inverseInertiaTensor[1]);
        // Go through the same transformation sequence again.
        Vector3 deltaVelWorld = relativeContactPosition[1] % normal;
        deltaVelWorld = body[1]->inverseInertiaTensorWorld * deltaVelWorld;
        deltaVelWorld = deltaVelWorld % relativeContactPosition[1];
        // Add the change in velocity due to rotation.
        deltaVelocity += deltaVelWorld * normal;
        
        // Add the change in velocity due to linear motion.
        deltaVelocity += body[1]->inverseMass;
        
        //////////////////////////
        velocity += body[1]->angularVelocity % relativeContactPosition[1];
        velocity += body[1]->velocity;
    }
    //printf("%f\n", deltaVelocity);
    Vector3 contactVelocity = contactToWorld.transpose() * velocity;
    //contactVelocity.dump();
    const float restitution = 1.0f;//TODO: each contact should have its own
    float desiredDeltaVelocity = -contactVelocity.x * (1 + restitution);
    
    Vector3 impulseContact;
    impulseContact.x = desiredDeltaVelocity / deltaVelocity;
    impulseContact.y = 0;
    impulseContact.z = 0;
    
    
    Vector3 impulse = contactToWorld * impulseContact;
    
    if(body[0]->hasFiniteMass())
    {
        Vector3 velocityChange = impulse * body[0]->inverseMass;
        Vector3 impulsiveTorque = impulse % relativeContactPosition[0];
        Vector3 rotationChange = body[0]->inverseInertiaTensor * impulsiveTorque;
        body[0]->velocity += velocityChange;
        body[0]->angularVelocity += rotationChange;
    }
    impulse *= -1;
    if(body[1]->hasFiniteMass())
    {
        Vector3 velocityChange = impulse * body[1]->inverseMass;
        Vector3 impulsiveTorque = impulse % relativeContactPosition[1];
        Vector3 rotationChange = body[1]->inverseInertiaTensor * impulsiveTorque;
        body[1]->velocity += velocityChange;
        body[1]->angularVelocity += rotationChange;
    }




}

