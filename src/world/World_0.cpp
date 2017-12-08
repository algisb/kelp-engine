///
///  @file World_0.cpp
///  @brief holds all the entities that get created also loads assets and other shared objects

#include "World_0.h"
#include "Core.h"
#include "kep/collisionDetection/finephase/Collider.h"
#include "kep/collisionDetection/finephase/SphereCollider.h"
#include "kep/collisionDetection/finephase/HalfPlaneCollider.h"
#include "kep/collisionDetection/finephase/OBBCollider.h"
#include "kep/collisionDetection/finephase/MeshCollider.h"

using namespace kelp;

World_0::World_0(Core * _core) : World(_core)
{
    Entity * refEntity = NULL;
    Transform * refTransform = NULL;
    refEntity = new Entity(this, "empty");//empty structure for having global components and testing stuff
    refEntity->addComponent(new Empty());
    //////////////////////CAM/////////////////////////
    camera = new Entity(this, "camera");//TODO: allow it so this can insted be another entity acting as a root node(scenegraph)
    camera->addComponent(new Transform(
                                    kep::Vector3(0.0f, 5.0f, 40.0f),
                                    kep::Quaternion(), 
                                    kep::Vector3(1.0f, 1.0f, 1.0f)
                                    ));
    
    
    camera->addComponent(
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
    
    wall = new Entity(this, "wall");
    wall->addComponent(new Transform(
                                        kep::Vector3(0.0f, 10.0f, -10.0f),
                                        kep::Quaternion(kep::Vector3(0,1,0), 0.0f), 
                                        kep::Vector3(100.0f, 10.0f, 1.0f)
                                        ));
    wall->addComponent(new Render(m_core->m_cubeMesh, m_core->m_shaderDefault, NULL, RenderMode::SOLID));
    

    
    
    
    
    
    cube = new Entity(this, "physics sphere");
    refTransform = (Transform*)cube->addComponent(new Transform(
                                        kep::Vector3(0.0f, 20.0f, 0.0f),
                                        kep::Quaternion(kep::Vector3(0,1,0), 0.0f), 
                                        kep::Vector3(1.0f, 1.0f, 1.0f)
                                        ));
    cube->addComponent(new Render(m_core->m_sphereMesh, m_core->m_shaderDefault, m_core->m_testTexture, RenderMode::SOLID));
    
    
    cube->addComponent(new KePhys(
        m_physWorld->addRigidBody(new kep::RigidBody(&refTransform->m_position, &refTransform->m_orientation, true, 1.0f, new kep::SphereCollider()))
    ));
    
    
    sphere = new Entity(this, "physics plane");
    refTransform = (Transform*)sphere->addComponent(new Transform(
                                        kep::Vector3(10.0f, 10.0f, 10.0f),//14
                                        kep::Quaternion(kep::Vector3(0,0,1), 0.0f), 
                                        kep::Vector3(10.0f, 10.0f, 10.0f)
                                        ));
    sphere->addComponent(new Render(m_core->m_plane, m_core->m_shaderDefault, NULL, RenderMode::SOLID));
    kep::Matrix4 tmpMat(1,0,0,0,
                        0,1,0,0,
                        0,0,1,0,
                        0,0,0,1);
    
    kep::MeshCollider * mc = new kep::MeshCollider(kep::Matrix4(), m_core->m_plane->m_dataV, m_core->m_plane->m_dataN, m_core->m_plane->m_numVertices, refTransform->m_scale);
    sphere->addComponent(new KePhys(
        m_physWorld->addRigidBody(new kep::RigidBody(&refTransform->m_position, &refTransform->m_orientation, true, 0.0f, mc))//new kep::HalfPlaneCollider()
    ));
    
    //camera->m_parent = cube;
    refEntity = new Entity(this, "m4a1s rifle", camera);
    refEntity->addComponent(new Transform(
                                        kep::Vector3(0.0f, -1.0f, 0.0f),//14
                                        kep::Quaternion(kep::Vector3(0,1,0), 180.0f), 
                                        kep::Vector3(1.0f, 1.0f, 1.0f)
                                        ));
    refEntity->addComponent(new Render(m_core->m_m4a1s, m_core->m_shaderDefault, m_core->m_m4a1sTexture, RenderMode::SOLID));
    
}
World_0::~World_0()
{
    
}

void World_0::initW()
{
    Time::s_deltaT = 0.01666f;//delta time on init is bad
    KePhys * kePhys = cube->getComponent<KePhys>();
    
    //kePhys->m_rigidBody->addTorque(kep::Vector3(0,0,100));
    //kePhys->m_rigidBody->addForceAtBodyPoint(kep::Vector3(0,0,-100), kep::Vector3(1,0,0));
    //kePhys->m_rigidBody->addForce(kep::Vector3(0, -100, 0));
}

void World_0::updateW()
{
    //KePhys * kePhys = cube->getComponent<KePhys>();
    //kePhys->m_rigidBody->velocity.dump();
    //kePhys->m_rigidBody->acceleration.dump();
    //empty[0]->getComponent<Transform>()->dump();
}
