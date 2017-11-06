///
///  @file Core.cpp
///  @brief core engine components usually unrelated to the game world and generic

#include "Core.h"


using namespace kelp;

Core::Core()
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
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
    glBindFramebuffer(GL_FRAMEBUFFER, 0); //render to the original buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    
    //update worlds (includes rendering)
    m_world->update();
}
