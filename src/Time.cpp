#include "Time.h"

using namespace kelp;

float Time::deltaT = 0.0f;
float Time::realT = 0.0f;
int Time::frameRate = 0;

void Time::calc()
{
    float t = glfwGetTime();
    deltaT = t-realT;
    realT = t;//updated last frame time
    if(deltaT != 0.0f)//just incase float spills spahaghetti 
        frameRate = int(1.0f/deltaT);
}

void Time::calcEnd()
{
    if(Config::capFrameRate)
    {
        float t1 = glfwGetTime();
        float tt = t1 - realT;
        if(tt < Config::targetDeltaT)
            delay(Config::targetDeltaT-tt);
    }
}
void Time::delay(const float _t)
{
    float delay = _t;
    float elapsedT = 0.0f;
    float prevT = glfwGetTime();
    while(elapsedT < delay)
    {
        float t = glfwGetTime();
        float diff = t-prevT;
        elapsedT += diff;
        prevT = t;
    }
}


