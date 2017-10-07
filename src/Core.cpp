#include "Core.h"
using namespace kelp;

Core::Core()
{
    world = new World();
}
Core::~Core()
{
    delete world;
}

void Core::update()
{
    world->update();
}
