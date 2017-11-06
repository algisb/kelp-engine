#ifndef LIGHT_H_
#define LIGHT_H_
#include "Component.h"

namespace kelp
{
    class Light : public Component
    {
    public:
        Light();
        ~Light() = 0;
    };
};


#endif // LIGHT_H_
