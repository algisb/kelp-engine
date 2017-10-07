#include "Time.h"

using namespace kelp;

float Time::deltaT = 0.0f;
float Time::realT = 0.0f;
int Time::frameRate = 0;

void Time::calc(const float _t)
{
    deltaT = _t-realT;
    realT = _t;//updated last frame time
    if(deltaT != 0.0f)//just incase float spills spahaghetti 
        frameRate = int(1.0f/deltaT);
}


