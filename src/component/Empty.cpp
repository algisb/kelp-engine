#include "Empty.h"
#include "world/World_0.h"
#include "Input.h"
#include "Time.h"
#include <Core.h>

using namespace kelp;
Empty::Empty(Entity * _playerCamera, Entity * _playerBody)
{
    kekX = -8.0f;
    m_playerBodyEntity = _playerBody;
    m_playerCameraEntity = _playerCamera;
}
Empty::~Empty()
{
}

void Empty::init()
{
    m_playerCameraComp = m_playerCameraEntity->getComponent<Camera>();
    m_playerPhysicsComp = m_playerBodyEntity->getComponent<KePhys>();
    m_playerCameraComp->m_possessed = false;//no longer use internal controls
    Input::Mouse::setMouseJoystickMode();
    
}

void Empty::update()
{
        const float rotSpd = 70.0f * Time::s_deltaT;
        const float mouseRotSpd = rotSpd *0.1f;
        //pitch///////////////////////////////////////
        float tmpAng = m_playerCameraComp->m_pitchAngle;
        tmpAng += -mouseRotSpd * Input::Mouse::dy;
        
        if(tmpAng < 90.0f && tmpAng > -90.0f)//pitch clamp
        {
            m_playerCameraComp->m_pitchAngle = tmpAng;
            kep::Quaternion q;
            q.setEuler(m_playerCameraComp->m_left, -mouseRotSpd * Input::Mouse::dy);
            m_playerCameraComp->m_transform->m_orientation *= q;
        }
        
        
        //yaw/////////////////////////////////////
        m_playerCameraComp->m_yawAngle += mouseRotSpd * Input::Mouse::dx;
        kep::Quaternion q;
        q.setEuler(m_playerCameraComp->m_up, mouseRotSpd * Input::Mouse::dx);
        m_playerCameraComp->m_transform->m_orientation *= q;
    
        kep::Quaternion moveQuat;
        moveQuat.setEuler(m_playerCameraComp->m_up, m_playerCameraComp->m_yawAngle);
        kep::Matrix3 moveMat;
        moveMat.setOrientation(moveQuat);
        kep::Vector3 moveDir(0,0,-1);
        moveDir = moveMat * moveDir;
        
    
        float moveF = 10.0f;  
        if(Input::Keyboard::is(Input::Keyboard::KeyboardKey::KEY_W, Input::Keyboard::KeyboardAction::HELD))
        {
            m_playerPhysicsComp->m_rigidBody->addForce(moveDir * moveF);
        }
        if(Input::Keyboard::is(Input::Keyboard::KeyboardKey::KEY_S, Input::Keyboard::KeyboardAction::HELD))
        {
            m_playerPhysicsComp->m_rigidBody->addForce(moveDir * moveF * -1.0f);
            //m_playerPhysicsComp->m_rigidBody->velocity += moveDir * moveF * -1.0f;
        }
        if(Input::Keyboard::is(Input::Keyboard::KeyboardKey::KEY_A, Input::Keyboard::KeyboardAction::HELD))
        {
            m_playerPhysicsComp->m_rigidBody->addForce(m_playerCameraComp->m_left* moveF);
        }
        if(Input::Keyboard::is(Input::Keyboard::KeyboardKey::KEY_D, Input::Keyboard::KeyboardAction::HELD))
        {
            m_playerPhysicsComp->m_rigidBody->addForce(m_playerCameraComp->m_left* moveF *-1.0f);
        }
        if(Input::Keyboard::is(Input::Keyboard::KeyboardKey::KEY_SPACE, Input::Keyboard::KeyboardAction::PRESSED))
        {
            //m_playerPhysicsComp->m_rigidBody->addForce(kep::Vector3(0,1,0) * 1000.0f);
            m_playerPhysicsComp->m_rigidBody->velocity += kep::Vector3(0,20,0);
            //printf("jump\n");
        }
        //printf("vel: %f \n", m_playerPhysicsComp->m_rigidBody->velocity.magnitude());
        
}
void Empty::render()
{
}
