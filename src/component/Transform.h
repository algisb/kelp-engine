#ifndef TRANSFORM_H_
#define TRANSFORM_H_

#include "Entity.h"
#include "Component.h"
#include "kep/Core.h"
namespace kelp
{
    class Transform : public Component
    {
    public:
        kep::Vector3 m_position;
        kep::Quaternion m_orientation;
        kep::Vector3 m_scale;
        
        Transform(kep::Vector3 _position, kep::Quaternion _orientation, kep::Vector3 _scale);
        ~Transform();
        void update();
        
        void dump();
    };
};



#endif
