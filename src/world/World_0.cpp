///
///  @file World_0.cpp
///  @brief holds all the entities that get created also loads assets and other shared objects

#include "World_0.h"
#include <Core.h>

using namespace kelp;

World_0::World_0(Core * _core) : World(_core)
{
    Entity * refEntity = NULL;
    refEntity = new Entity(this, "empty");//empty structure for having global components and testing stuff
    refEntity->addComponent(new Empty());
    //////////////////////CAM/////////////////////////
    refEntity = new Entity(this, "camera");//TODO: allow it so this can insted be another entity acting as a root node(scenegraph)
    refEntity->addComponent(new Transform(
                                          kep::Vector3(0.0f, 5.0f, 40.0f),
                                          kep::Quaternion(), 
                                          kep::Vector3(1.0f, 1.0f, .0f)
                                         ));
    refEntity->addComponent(
                            new Camera(kep::Vector3(0.0f, 1.0f, 0.0f),
                            kep::perspectiveProjection(
                                45.0f, 
                                Config::s_windowWidth, 
                                Config::s_windowHeight, 
                                1.0f, 
                                1000.0f).transpose(),
                                true
                            ));
    

    
    refEntity = new Entity(this, "Directional Light");
    refEntity->addComponent(new LightDirectional(m_core->m_shaderDefault, 0.5f, kep::Vector3(0.0f,0.0f,0.0f), kep::Vector3(0.0f, 1.0f, 1.0f)));
    
    plight = new Entity(this, "Point Light");
    plight->addComponent(new Transform(
                                        kep::Vector3(-4.0f, 8.0f, 2.0f),
                                        kep::Quaternion(), 
                                        kep::Vector3(0.2f, 0.2f, 0.2f)
                                        ));
    plight->addComponent(new LightPoint(m_core->m_shaderDefault, 50.0f, kep::Vector3(0.0f, 0.0f, 0.0f)));
    plight->addComponent(new Render(m_core->m_sphereMesh, m_core->m_shaderMinimal, NULL, RenderMode::SOLID));
        
    
   //////////////////////////////////////////////////////////////////////////////////////////// 
    refEntity = new Entity(this, "plane");
    refEntity->addComponent(new Transform(
                                        kep::Vector3(0.0f, 0.0f, 0.0f),
                                        kep::Quaternion(kep::Vector3(0,1,0), 0.0f), 
                                        kep::Vector3(100.0f, 1.0f, 100.0f)
                                        ));
    refEntity->addComponent(new Render(m_core->m_plane, m_core->m_shaderDefault, m_core->m_testTexture, RenderMode::SOLID));
    
    cube = new Entity(this, "cube");
    cube->addComponent(new Transform(
                                        kep::Vector3(0.0f, 20.0f, 0.0f),
                                        kep::Quaternion(kep::Vector3(0,1,0), 0.0f), 
                                        kep::Vector3(1.0f, 1.0f, 1.0f)
                                        ));
    cube->addComponent(new Render(m_core->m_cubeMesh, m_core->m_shaderDefault, m_core->m_testTexture, RenderMode::SOLID));
    cube->addComponent(new KePhys(1.0f));

    
    
    sphere = new Entity(this, "sphere");
    sphere->addComponent(new Transform(
                                        kep::Vector3(0.0f, 1.0f, 0.0f),
                                        kep::Quaternion(kep::Vector3(0,1,0), 0.0f), 
                                        kep::Vector3(1.0f, 1.0f, 1.0f)
                                        ));
    sphere->addComponent(new Render(m_core->m_sphereSmoothMesh, m_core->m_shaderDefault, NULL, RenderMode::SOLID));
    sphere->addComponent(new KePhys(1.0f));
    
    
    wall = new Entity(this, "wall");
    wall->addComponent(new Transform(
                                        kep::Vector3(0.0f, 10.0f, -10.0f),
                                        kep::Quaternion(kep::Vector3(0,1,0), 0.0f), 
                                        kep::Vector3(100.0f, 10.0f, 1.0f)
                                        ));
    wall->addComponent(new Render(m_core->m_cubeMesh, m_core->m_shaderDefault, NULL, RenderMode::SOLID));
    


    
}
World_0::~World_0()
{
    
}

void World_0::initW()
{
    KePhys * kePhys = cube->getComponent<KePhys>();
    
    //kePhys->m_rigidBody->addTorque(kep::Vector3(0,0,100));
    //kePhys->m_rigidBody->addForceAtBodyPoint(kep::Vector3(0,0,-100), kep::Vector3(1,0,0));
    kePhys->m_rigidBody->addForce(kep::Vector3(0, -100, 0));
}

void World_0::updateW()
{
    //empty[0]->getComponent<Transform>()->dump();
}
