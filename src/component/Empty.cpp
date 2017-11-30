#include "Empty.h"
#include "world/World_0.h"
#include "Input.h"
#include "Time.h"
#include <Core.h>

using namespace kelp;
Empty::Empty()
{
    kekX = -10.0f;
}
Empty::~Empty()
{
}

void Empty::init()
{
}

void Empty::update()
{
    if(Input::Keyboard::is(Input::Keyboard::KeyboardKey::KEY_T, Input::Keyboard::KeyboardAction::PRESSED))
    {
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
