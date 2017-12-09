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
        
        KePhys * m_playerPhysicsComp;
        Camera * m_playerCameraComp;
        
        Empty(Entity * _playerCamera, Entity * _playerBody);
        ~Empty();
        void init();
        void update();
        void render();
    };
};

#endif //EMPTY_H_
