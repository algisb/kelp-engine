#ifndef EMPTY_H_
#define EMPTY_H_
#include "Component.h"
namespace kelp
{
    class Empty : public Component
    {
    public:
        Empty();
        ~Empty();
        void init();
        void update();
        void render();
    };
};

#endif //EMPTY_H_
