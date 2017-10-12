#include "World_0.h"

using namespace kelp;

World_0::World_0() : World()
{
    Entity * entity = new Entity("empty");
    entity->addComponent(
        new Transform(kep::Vector3(),
                      kep::Quaternion(), 
                      kep::Vector3(1.0f, 1.0f, 1.0f)
                     )
                        );
}
World_0::~World_0()
{
    
}

