#include "World.h"
#include "collisionDetection/broadphase/PotencialContact.h"
#include "collisionDetection/broadphase/BoundingSphere.h"
#include "collisionDetection/finephase/CollisionData.h"
#include "collisionDetection/finephase/SphereCollider.h"
using namespace kep;

World::World()
{
    fReg = new ForceRegistry();
    
    gGen = new Gravity(Vector3(0.0f, -9.81f, 0.0f));
    ldGen = new LinearDrag(0.1f, 0.001f);
    adGen = new AngularDrag(0.5, 0.1f);
    cDetec = new CollisionDetector(&rigidBodies);
}
World::~World()
{
    delete fReg;
    delete gGen;
    delete ldGen;
    delete adGen;
    delete cDetec;
}
void World::update(real _duration)
{
    CollisionData cd;
    cDetec->detect(&cd);
    //printf("%d\n", cd.contacts.size());
    
        
    fReg->updateForces(_duration);
    for(int i = 0; i < rigidBodies.size(); i++)
        rigidBodies[i]->integrate(_duration);
    
}
void World::addRigidBody(RigidBody * _rigidBody)
{
    //fReg->add(_rigidBody, gGen);
    fReg->add(_rigidBody, ldGen);
    fReg->add(_rigidBody, adGen);
    rigidBodies.push_back(_rigidBody);
}
