///
///  @file World_0.cpp
///  @brief holds all the entities that get created also loads assets and other shared objects

#include "World_0.h"

using namespace kelp;

World_0::World_0() : World()
{
    Shader * shader0 = new Shader("./shaders/minimal_v.glsl", "./shaders/minimal_f.glsl");
    
    empty[0] = new Entity("empty");
    empty[0]->addComponent(
        new Transform(kep::Vector3(),
                      kep::Quaternion(), 
                      kep::Vector3(1.0f, 1.0f, 1.0f)
                     )
                        );
    empty[0]->addComponent(new InputController());
    addEntity(empty[0]);
}
World_0::~World_0()
{
    
}

void World_0::updateV()
{
    //empty[0]->getComponent<Transform>()->dump();
}
