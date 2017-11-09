///
///  @file World_0.cpp
///  @brief holds all the entities that get created also loads assets and other shared objects

#include "World_0.h"

using namespace kelp;

World_0::World_0() : World()
{
    MeshGen * meshGen = new MeshGen();//TODO : this needs to be derived from entity and later automatically deleted
    meshGen->addTri(kep::Vector3(-2.0,0,0), kep::Vector3(2.0f,0,0), kep::Vector3(0,3.0f,0));
    meshGen->gen();
    
    
    
    MeshLoad * mesh0 = new MeshLoad("./models/city.obj", "./models/");
    MeshLoad * mesh1 = new MeshLoad("./models/sphereUV.obj", "./models/");
    ShaderMin * shaderMin = new ShaderMin();//TODO : this needs to be derived from entity and later automatically deleted
    ShaderDefault * shaderDefault = new ShaderDefault();
    
    Entity * refEntity = NULL;
    //////////////////////CAM/////////////////////////
    refEntity = new Entity(this, "camera");//TODO: allow it so this can insted be another entity acting as a root node(scenegraph)
    refEntity->addComponent(new Transform(
                                          kep::Vector3(0.0f, 0.0f, 10.0f),
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
                                1000.0f).transpose()
                            ));
    refEntity->addComponent(new InputController());
    
    
    refEntity = new Entity(this, "Directional Light");
    refEntity->addComponent(new LightDirectional(shaderDefault, 0.5f, kep::Vector3(0.0f,0.0f,0.0f), kep::Vector3(1.0f, 1.0f, 1.0f)));
    //m_renderCamera = empty[0]->getComponent<Camera>();
    //////////////////////////////////////////////////
    refEntity = new Entity(this, "empty");
    refEntity->addComponent(new Transform(
                                          kep::Vector3(0.0f, 0.0f, 0.0f),
                                          kep::Quaternion(), 
                                          kep::Vector3(1.0f, 1.0f, 1.0f)
                                         ));
    
    refEntity->addComponent(new Render(mesh1, shaderDefault, RenderMode::SOLID));
    
    
    refEntity = new Entity(this, "empty");
    refEntity->addComponent(new Transform(
                                          kep::Vector3(5.0f, 0.0f, 0.0f),
                                          kep::Quaternion(), 
                                          kep::Vector3(1.0f, 1.0f, 1.0f)
                                         ));
    
    refEntity->addComponent(new Render(mesh0, shaderDefault, RenderMode::SOLID));
    
}
World_0::~World_0()
{
    
}

void World_0::updateV()
{
    //empty[0]->getComponent<Transform>()->dump();
}
