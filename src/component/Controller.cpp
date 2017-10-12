#include "Controller.h"

using namespace kelp;

Controller::Controller() : Component()
{
    
    
}

Controller::~Controller()
{
    
}

void Controller::init()
{
    
}
void Controller::update()
{
    if(Input::Keyboard::is(Input::Keyboard::KeyboardKey::KEY_UP, Input::Keyboard::KeyboardAction::HELD))
    {
        m_owner->getComponent<Transform>()->m_position.m_x += 1.0f*Time::s_deltaT;
    }
}
