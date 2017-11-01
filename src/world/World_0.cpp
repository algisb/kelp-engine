///
///  @file World_0.cpp
///  @brief holds all the entities that get created also loads assets and other shared objects

#include "World_0.h"

using namespace kelp;

World_0::World_0() : World()
{
    MeshGen * meshGen = new MeshGen();
    meshGen->addTri(kep::Vector3(-2.0,0,0), kep::Vector3(2.0f,0,0), kep::Vector3(0,3.0f,0));
    meshGen->gen();
    ShaderUnlit * shaderUnlit = new ShaderUnlit();
    
    //////////////////////CAM/////////////////////////
    empty[0] = new Entity(this, "camera");
    empty[0]->addComponent(
        new Transform(kep::Vector3(),
                  kep::Quaternion(), 
                  kep::Vector3(1.0f, 1.0f, -10.0f)
                 ));
    empty[0]->addComponent(new Camera(
        kep::perspectiveProjection(
            45.0f, 
            Config::s_windowWidth, 
            Config::s_windowHeight, 
            0.1f, 
            2000.0f).transpose()
                                     ));
    //m_renderCamera = empty[0]->getComponent<Camera>();
    //////////////////////////////////////////////////
    
    
    empty[1] = new Entity(this, "empty");
    empty[1]->addComponent(
        new Transform(kep::Vector3(),
                      kep::Quaternion(), 
                      kep::Vector3(1.0f, 1.0f, 1.0f)
                     ));
    empty[1]->addComponent(new InputController());
    empty[1]->addComponent(new Render(meshGen, shaderUnlit));
    
}
World_0::~World_0()
{
    
}

void World_0::updateV()
{
    //empty[0]->getComponent<Transform>()->dump();
}
