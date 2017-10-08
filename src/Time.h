#ifndef TIME_H
#define TIME_H

#include <GLFW/glfw3.h>
#include "Config.h"

namespace kelp
{
    class Time
    {
    public:
        static float deltaT;
        static float realT;
        static int frameRate;
        
        static void calc();
        static void calcEnd();
        static void delay(const float _t);
        
    };
};


#endif
