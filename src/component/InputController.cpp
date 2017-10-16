///
///  @file InputController.cpp
///  @brief attaches player related input to any entity
#include "InputController.h"

using namespace kelp;

InputController::InputController() : Component()
{
    
    
}

InputController::~InputController()
{
    
}

void InputController::init()
{
    
}
void InputController::update()
{
    if(Input::Keyboard::is(Input::Keyboard::KeyboardKey::KEY_UP, Input::Keyboard::KeyboardAction::HELD))
    {
        m_owner->getComponent<Transform>()->m_position.m_x += 1.0f*Time::s_deltaT;
    }
}
