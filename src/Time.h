#ifndef TIME_H
#define TIME_H

namespace kelp
{
    class Time
    {
    public:
        static float deltaT;
        static float realT;
        static int frameRate;
        
        static void calc(const float _t);
        
    };
};


#endif
