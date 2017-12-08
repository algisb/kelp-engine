#include "Empty.h"
#include "world/World_0.h"
#include "Input.h"
#include "Time.h"
#include <Core.h>

using namespace kelp;
Empty::Empty()
{
    kekX = -8.0f;
}
Empty::~Empty()
{
}

void Empty::init()
{
}

void Empty::update()
{
    if(Input::Keyboard::is(Input::Keyboard::KeyboardKey::KEY_T, Input::Keyboard::KeyboardAction::HELD))
    {
//         Entity * refEntity = ((World_0*)(m_owner->m_world))->plight;
//         refEntity = new Entity(refEntity->m_world, "Point Light");
//         refEntity->addComponent(new Transform(
//                                         kep::Vector3(kekX, 8.0f, 2.0f),
//                                         kep::Quaternion(), 
//                                         kep::Vector3(0.2f, 0.2f, 0.2f)
//                                         ));
//         refEntity->addComponent(new LightPoint(refEntity->m_world->m_core->m_shaderDefault, 50.0f, kep::Vector3(0.0f, 0.0f, 0.0f)));
//         refEntity->addComponent(new Render(refEntity->m_world->m_core->m_sphereMesh, refEntity->m_world->m_core->m_shaderMinimal, NULL, RenderMode::SOLID));
//         kekX  += -10.0f;
        
        
        Entity * refEntity = ((World_0*)(m_owner->m_world))->cube;
        kep::Quaternion q;
        q.setEuler(kep::Vector3(0,1,0), 2.0f);
        refEntity->m_transform->m_orientation *= q;
        
//         Entity * refEntity = NULL;
//         refEntity = new Entity(m_owner->m_world, "camera");//TODO: allow it so this can insted be another entity acting as a root node(scenegraph)
//         refEntity->addComponent(new Transform(
//                                           kep::Vector3(0.0f, 5.0f, 20.0f),
//                                           kep::Quaternion(kep::Vector3(0,1,0), 45.0f), 
//                                           kep::Vector3(1.0f, 1.0f, .0f)
//                                          ));
//         Camera *c = (Camera*)refEntity->addComponent(
//                             new Camera(kep::Vector3(0.0f, 1.0f, 0.0f),
//                             kep::perspectiveProjection(
//                                 45.0f, 
//                                 Config::s_windowWidth, 
//                                 Config::s_windowHeight, 
//                                 1.0f, 
//                                 1000.0f).transpose(),
//                                 true
//                             ));
//         c->setAsRenderCamera();
        
        //refEntity
        //Entity * en = ((World_0*)(m_owner->m_world))->plight;
        //en->deleteComponent<LightPoint>();
        //m_owner->m_world->deleteEntity( ((World_0*)(m_owner->m_world))->wall );
    }
    if(Input::Keyboard::is(Input::Keyboard::KeyboardKey::KEY_Y, Input::Keyboard::KeyboardAction::PRESSED))
    {
//         Entity * en = ((World_0*)(m_owner->m_world))->wall;
//         en = new Entity(m_owner->m_world, "wall");
//         en->addComponent(new Transform(
//                                         kep::Vector3(0.0f, 10.0f, kekX),//-10.0f
//                                         kep::Quaternion(kep::Vector3(0,1,0), 0.0f), 
//                                         kep::Vector3(100.0f, 10.0f, 1.0f)
//                                         ));
        //en->addComponent(new Render(m_owner->m_world->m_core->m_cubeMesh, m_owner->m_world->m_core->m_shaderDefault, RenderMode::SOLID));
        //kekX += -10.0f;
        //Entity * en = ((World_0*)(m_owner->m_world))->plight;
        //en->addComponent(new LightPoint(m_owner->m_world->m_core->m_shaderDefault, 50.0f, kep::Vector3(0.0f, 0.0f, 0.0f)));
        //en->addComponent(new Render(m_owner->m_world->m_core->m_cubeMesh, m_owner->m_world->m_core->m_shaderDefault, RenderMode::SOLID));
        
    }
}
void Empty::render()
{
}
