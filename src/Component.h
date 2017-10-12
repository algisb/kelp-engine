
#ifndef COMPONENT_H_
#define COMPONENT_H_
#include "Entity.h"


namespace kelp
{
    class Entity;
    class Component
    {
    public:
        Entity * m_owner;//owner is aded by add component
        bool m_enabled;
        
        Component();
        virtual ~Component()=0;
        virtual void update()=0;
        
    };
};

#endif // COMPONENT_H_
