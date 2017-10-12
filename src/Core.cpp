///
///  @file Core.cpp
///  @brief core engine components usually unrelated to the game world and generic

#include "Core.h"


using namespace kelp;

Core::Core()
{
    m_world = new World_0();
    ///////////////////////////////////////
    
}
Core::~Core()
{
    delete m_world;
}

void Core::update()
{
    //printf("fps: %d \n", Time::s_frameRate);
    //printf("deltaT: %f \n", kelp::Time::s_deltaT);
    //Input::printKeyList();
    glClearColor(0.0f, 0.1f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT/*|GL_DEPTH_BUFFER_BIT|GL_ACCUM_BUFFER_BIT*/);
    
    
    //update worlds (includes rendering)
    m_world->update();
}
