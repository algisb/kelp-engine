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
    kep::MeshCollider * mc = NULL;


    

    //LIGHTS//////////////////////////////////////////////////////////////////////////////////////
    refEntity = new Entity(this, "Directional Light");
    refEntity->addComponent(new LightDirectional(m_core->m_shaderDefault, 0.5f, kep::Vector3(0.0f,0.0f,0.0f), kep::Vector3(0.0f, 1.0f, 1.0f)));
    
    plight = new Entity(this, "Point Light");
    plight->addComponent(new Transform(
                                        kep::Vector3(-4.0f, 10.0f, 10.0f),
                                        kep::Quaternion(), 
                                        kep::Vector3(0.2f, 0.2f, 0.2f)
                                        ));
    plight->addComponent(new LightPoint(m_core->m_shaderDefault, 50.0f, kep::Vector3(0.0f, 0.0f, 0.0f)));
    plight->addComponent(new Render(m_core->m_sphereMesh, m_core->m_shaderMinimal, NULL, RenderMode::SOLID));
        
    
    refEntity = new Entity(this, "Point Light");
    refEntity->addComponent(new Transform(
                                        kep::Vector3(170.0f, 10.0f, 170.0f),
                                        kep::Quaternion(), 
                                        kep::Vector3(0.2f, 0.2f, 0.2f)
                                        ));
    refEntity->addComponent(new LightPoint(m_core->m_shaderDefault, 50.0f, kep::Vector3(0.0f, 0.0f, 0.0f)));
    refEntity->addComponent(new Render(m_core->m_sphereMesh, m_core->m_shaderMinimal, NULL, RenderMode::SOLID));
    
    refEntity = new Entity(this, "Point Light");
    refEntity->addComponent(new Transform(
                                        kep::Vector3(-170.0f, 10.0f, -170.0f),
                                        kep::Quaternion(), 
                                        kep::Vector3(0.2f, 0.2f, 0.2f)
                                        ));
    refEntity->addComponent(new LightPoint(m_core->m_shaderDefault, 50.0f, kep::Vector3(0.0f, 0.0f, 0.0f)));
    refEntity->addComponent(new Render(m_core->m_sphereMesh, m_core->m_shaderMinimal, NULL, RenderMode::SOLID));
    
    
    refEntity->addComponent(new LightPoint(m_core->m_shaderDefault, 50.0f, kep::Vector3(0.0f, 0.0f, 0.0f)));
    refEntity->addComponent(new Render(m_core->m_sphereMesh, m_core->m_shaderMinimal, NULL, RenderMode::SOLID));
    
    refEntity = new Entity(this, "Point Light");
    refEntity->addComponent(new Transform(
                                        kep::Vector3(170.0f, 10.0f, -170.0f),
                                        kep::Quaternion(), 
                                        kep::Vector3(0.2f, 0.2f, 0.2f)
                                        ));
    refEntity->addComponent(new LightPoint(m_core->m_shaderDefault, 50.0f, kep::Vector3(0.0f, 0.0f, 0.0f)));
    refEntity->addComponent(new Render(m_core->m_sphereMesh, m_core->m_shaderMinimal, NULL, RenderMode::SOLID));
    
    refEntity->addComponent(new LightPoint(m_core->m_shaderDefault, 50.0f, kep::Vector3(0.0f, 0.0f, 0.0f)));
    refEntity->addComponent(new Render(m_core->m_sphereMesh, m_core->m_shaderMinimal, NULL, RenderMode::SOLID));
    
    refEntity = new Entity(this, "Point Light");
    refEntity->addComponent(new Transform(
                                        kep::Vector3(-170.0f, 10.0f, 170.0f),
                                        kep::Quaternion(), 
                                        kep::Vector3(0.2f, 0.2f, 0.2f)
                                        ));
    refEntity->addComponent(new LightPoint(m_core->m_shaderDefault, 50.0f, kep::Vector3(0.0f, 0.0f, 0.0f)));
    refEntity->addComponent(new Render(m_core->m_sphereMesh, m_core->m_shaderMinimal, NULL, RenderMode::SOLID));
    
   /////////////////////////////////////////////////////////////////////////
    refEntity = new Entity(this, "plane");
    refTransform = (Transform*)refEntity->addComponent(new Transform(
                                        kep::Vector3(0.0f, 0.0f, 0.0f),
                                        kep::Quaternion(kep::Vector3(0,1,0), 0.0f), 
                                        kep::Vector3(10.0f, 10.0f, 10.0f)
                                        ));
    refEntity->addComponent(new Render(m_core->m_sandBox, m_core->m_shaderDefault, NULL, RenderMode::SOLID));
    
    mc = new kep::MeshCollider(kep::Matrix4(), m_core->m_sandBox->m_dataV, m_core->m_sandBox->m_dataN, m_core->m_sandBox->m_numVertices, refTransform->m_scale);
    refEntity->addComponent(new KePhys(
        m_physWorld->addRigidBody(new kep::RigidBody(&refTransform->m_position, &refTransform->m_orientation, true, 0.0f, mc))//new kep::HalfPlaneCollider()
    ));
    
//////   
    wall = new Entity(this, "wall");
    refTransform = (Transform*)wall->addComponent(new Transform(
                                        kep::Vector3(0.0f, 10.0f, -10.0f),
                                        kep::Quaternion(kep::Vector3(0,1,0), 0.0f), 
                                        kep::Vector3(100.0f, 10.0f, 1.0f)
                                        ));
    wall->addComponent(new Render(m_core->m_cubeMesh, m_core->m_shaderDefault, NULL, RenderMode::SOLID));
    mc = new kep::MeshCollider(kep::Matrix4(), m_core->m_cubeMesh->m_dataV, m_core->m_cubeMesh->m_dataN, m_core->m_cubeMesh->m_numVertices, refTransform->m_scale);
    wall->addComponent(new KePhys(
        m_physWorld->addRigidBody(new kep::RigidBody(&refTransform->m_position, &refTransform->m_orientation, true, 0.0f, mc))//new kep::HalfPlaneCollider()
    ));
    
//////    
    sphere = new Entity(this, "physics plane");
    refTransform = (Transform*)sphere->addComponent(new Transform(
                                        kep::Vector3(15.0f, 10.0f, 10.0f),//14
                                        kep::Quaternion(kep::Vector3(0,0,1), -20.0f), 
                                        kep::Vector3(10.0f, 10.0f, 10.0f)
                                        ));
    sphere->addComponent(new Render(m_core->m_plane, m_core->m_shaderDefault, NULL, RenderMode::SOLID));
    kep::Matrix4 tmpMat(1,0,0,0,
                        0,1,0,0,
                        0,0,1,0,
                        0,0,0,1);
    
    mc = new kep::MeshCollider(kep::Matrix4(), m_core->m_plane->m_dataV, m_core->m_plane->m_dataN, m_core->m_plane->m_numVertices, refTransform->m_scale);
    sphere->addComponent(new KePhys(
        m_physWorld->addRigidBody(new kep::RigidBody(&refTransform->m_position, &refTransform->m_orientation, true, 0.0f, mc))//new kep::HalfPlaneCollider()
    ));
    
    
    
//////   
    refEntity = new Entity(this, "physics cube mesh");
    refTransform = (Transform*)refEntity->addComponent(new Transform(
                                        kep::Vector3(0.0f, 12.0f, 0.0f),
                                        kep::Quaternion(kep::Vector3(0,0,1), 0.0f), 
                                        kep::Vector3(1.0f, 1.0f, 1.0f)
                                        ));
     refEntity->addComponent(new Render(m_core->m_cubeMesh, m_core->m_shaderDefault, m_core->m_testTexture, RenderMode::SOLID));
    
    mc = new kep::MeshCollider(kep::Matrix4(), m_core->m_cubeMesh->m_dataV, m_core->m_cubeMesh->m_dataN, m_core->m_cubeMesh->m_numVertices, refTransform->m_scale);
    refEntity->addComponent(new KePhys(
        m_physWorld->addRigidBody(new kep::RigidBody(&refTransform->m_position, &refTransform->m_orientation, true, 0.0f, mc))//TODO: rigidbodies with mass 0 should not be check for collision againsts other bodies with mass 0 
    ));
    
    for(int i = 0; i < 20; i++)
    {
        refEntity = new Entity(this, "physics sphere");
        refTransform = (Transform*)refEntity->addComponent(new Transform(
                                            kep::Vector3((float)i+2, 20.0f, 10.0f),
                                            kep::Quaternion(kep::Vector3(0,1,0), 0.0f), 
                                            kep::Vector3(1.0f, 1.0f, 1.0f)
                                            ));
        refEntity->addComponent(new Render(m_core->m_sphereMesh, m_core->m_shaderDefault, m_core->m_testTexture, RenderMode::SOLID));
        
        
        refEntity->addComponent(new KePhys(
            m_physWorld->addRigidBody(new kep::RigidBody(&refTransform->m_position, &refTransform->m_orientation, true, 1.0f, new kep::SphereCollider(kep::Matrix4())))
        ));
    }
    empty[2] = new Entity(this, "physics sphere");
    refTransform = (Transform*)empty[2]->addComponent(new Transform(
                                        kep::Vector3(-5.0f, 24.0f, 10.0f),
                                        kep::Quaternion(kep::Vector3(0,1,0), 0.0f), 
                                        kep::Vector3(1.0f, 1.0f, 1.0f)
                                        ));
    empty[2]->addComponent(new Render(m_core->m_sphereMesh, m_core->m_shaderDefault, m_core->m_testTexture, RenderMode::SOLID));
    
    
    empty[2]->addComponent(new KePhys(
        m_physWorld->addRigidBody(new kep::RigidBody(&refTransform->m_position, &refTransform->m_orientation, true, 1.0f, new kep::SphereCollider(kep::Matrix4())))
    ));
    
    
    
    ///////////////////////////////////////////////////////////////////////////////////////////////
    
    
    
    ////////////////////////Player body//////////////////////////////////////////
    empty[0] = new Entity(this, "player body");
    refTransform = (Transform*)empty[0]->addComponent(new Transform(
                                        kep::Vector3(0.0f, 10.0f, 20.0f),
                                        kep::Quaternion(kep::Vector3(0,1,0), 0.0f), 
                                        kep::Vector3(0.5f, 0.5f, 0.5f)
                                        ));
    //empty[0]->addComponent(new Render(m_core->m_sphereMesh, m_core->m_shaderDefault, m_core->m_testTexture, RenderMode::SOLID));
    
    
    empty[0]->addComponent(new KePhys(
        m_physWorld->addRigidBody(new kep::RigidBody(&refTransform->m_position, &refTransform->m_orientation, true, 1.0f, new kep::SphereCollider(kep::Matrix4()),true))
    ));
    
    //////////////////////CAM/////////////////////////
    empty[1] = new Entity(this, "player camera", empty[0]);
    empty[1]->addComponent(new Transform(
                                    kep::Vector3(0.0f, 2.0f, 0.0f),
                                    kep::Quaternion(), 
                                    kep::Vector3(1.0f, 1.0f, 1.0f)
                                    ));
    
    
    empty[1]->addComponent(
                            new Camera(kep::Vector3(0.0f, 1.0f, 0.0f),
                            kep::perspectiveProjection(
                                45.0f, 
                                Config::s_windowWidth, 
                                Config::s_windowHeight, 
                                1.0f, 
                                1000.0f).transpose(),
                                true
                            ));
    refEntity = new Entity(this, "empty");//empty structure for having global components and testing stuff
    refEntity->addComponent(new Empty(empty[1], empty[0], empty[2]));
    
    ///////////////////rifle/////////////////////////////////
    refEntity = new Entity(this, "m4a1s rifle", empty[1]);
    refTransform = (Transform*)refEntity->addComponent(new Transform(
                                        kep::Vector3(0.0f, 0.0f, 0.0f),
                                        kep::Quaternion(kep::Vector3(0,1,0), 180.0f), 
                                        kep::Vector3(1.0f, 1.0f, 1.0f)
                                        ));
     refEntity->addComponent(new Render(m_core->m_m4a1s, m_core->m_shaderDefault, m_core->m_m4a1sTexture, RenderMode::SOLID, kep::Vector3(), true));
     //crosshair////////////////////
     refEntity = new Entity(this, "crosshair");
     
     refEntity->addComponent(new RenderLine2(kep::Vector3(0,0.1f,-10.0f), kep::Vector3(0,0.2f,-10.0f)));
     refEntity->addComponent(new RenderLine2(kep::Vector3(0,-0.1f,-10.0f), kep::Vector3(0,-0.2f,-10.0f)));
     
     refEntity->addComponent(new RenderLine2(kep::Vector3(0.1f,0.0f,-10.0f), kep::Vector3(0.2f,0.0f,-10.0f)));
     refEntity->addComponent(new RenderLine2(kep::Vector3(-0.1f,0.0f,-10.0f), kep::Vector3(-0.2f,0.0f,-10.0f)));
    
    
}
World_0::~World_0()
{
    
}

void World_0::initW()
{
    //Time::s_deltaT = 0.01666f;//delta time on init is bad
    //KePhys * kePhys = cube->getComponent<KePhys>();
    
    //kePhys->m_rigidBody->addTorque(kep::Vector3(0,0,1000));
    //kePhys->m_rigidBody->addForceAtBodyPoint(kep::Vector3(0,0,-100), kep::Vector3(1,0,0));
    //kePhys->m_rigidBody->addForce(kep::Vector3(0, -1000, 0));
    //kePhys->m_rigidBody->addForce(kep::Vector3(500, 0, 0));
    //kePhys->m_rigidBody->addForce(kep::Vector3(500, 0, 0))
}

void World_0::updateW()
{
    //KePhys * kePhys = cube->getComponent<KePhys>();
    
    //kePhys->m_rigidBody->velocity.dump();
    //kePhys->m_rigidBody->acceleration.dump();
    //empty[0]->getComponent<Transform>()->dump();
    //kePhys->m_rigidBody->angularVelocity.dump();
}
