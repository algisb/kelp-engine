#include "World.h"
#include "broadphase/PotencialContact.h"
#include "broadphase/BoundingSphere.h"
#include "finephase/CollisionData.h"
#include "finephase/SphereCollider.h"
using namespace kep;

World::World()
{
    fReg = new ForceRegistry();
    
    gGen = new Gravity(Vector3(0.0f, -9.81f, 0.0f));
    ldGen = new LinearDrag(0.1f, 0.001f);
    adGen = new AngularDrag(0.5, 0.1f);
}
World::~World()
{
    delete fReg;
    delete gGen;
    delete ldGen;
    delete adGen;
}
void World::update(real _duration)
{
    std::vector<PotencialContact> pc;
    //broadphase collision check
    for(int i = 0; i < rigidBodies.size(); i++)
        for(int j = 0; j < rigidBodies.size(); j++)
        {
            if(i==j)//dont check collision against self
                continue;
            if(rigidBodies[i]->boundingVolume->overlaps(rigidBodies[j]->boundingVolume))
            {
                pc.push_back(PotencialContact(rigidBodies[i], rigidBodies[j]));//generates 2 PotencialContacts for a single overlap
            }
            
        }
    //fine collision check
    CollisionData cd;
    for(int i = 0; i < pc.size(); i++)
        pc[i].rigidBody[0]->collider->collides(pc[i].rigidBody[1]->collider, &cd);//Double dynamic dispatch aka C++ magic
    //printf("%d\n", pc.size());
    
        
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
