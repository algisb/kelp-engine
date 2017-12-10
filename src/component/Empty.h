#ifndef EMPTY_H_
#define EMPTY_H_
#include "Component.h"
#include "Entity.h"
#include "KePhys.h"
namespace kelp
{
    class Empty : public Component
    {
    public:
        float kekX;
        Entity * m_playerCameraEntity;
        Entity * m_playerBodyEntity;
        Entity * m_projectileEntity;
        
        KePhys * m_playerPhysicsComp;
        Camera * m_playerCameraComp;
        KePhys * m_projectileEntityPhysicsComp;
        kep::Vector3 lastFrameVel;
        
        Empty(Entity * _playerCamera, Entity * _playerBody, Entity * _projectileEntity);
        ~Empty();
        void init();
        void update();
        void render();
    };
};

#endif //EMPTY_H_
