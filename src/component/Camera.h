#ifndef CAMERA_H_
#define CAMERA_H_

#include "Component.h"
#include "kep/Core.h"
#include "Config.h"
#include "Transform.h"
namespace kelp
{
    class Camera : public Component
    {
    public:
        kep::Matrix4 m_projectionMat;
        Transform * m_transform;
        
        
        Camera(kep::Matrix4 _projectionMat);
        ~Camera();
        
        void init();
        void update();
        void render();
    };
};


#endif // CAMERA_H_
