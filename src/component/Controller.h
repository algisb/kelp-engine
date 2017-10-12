#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include "Input.h"
#include "Component.h"
#include "Transform.h"
#include "Time.h"
#include <functional>

namespace kelp
{
    class Controller : public Component
    {
    public:
        Controller();
        ~Controller();
        void init();
        void update();
        
    };
};


#endif // CONTROLLER_H_
