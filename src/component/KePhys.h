#ifndef KEPHYS_H_
#define KEPHYS_H_
#include "Component.h"
#include "kep/RigidBody.h"
#include "kep/World.h"
namespace kelp
{
    class KePhys : public Component
    {
    public:
        kep::RigidBody * m_rigidBody;
        KePhys(float _mass = 1.0f);
        ~KePhys();
        
        void init();
        void update();
        void render();
    };
};
#endif // KEPHYS_H_
