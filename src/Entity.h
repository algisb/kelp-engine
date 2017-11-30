#ifndef ENTITY_H_
#define ENTITY_H_

#include <vector>
#include <string>
#include "Component.h"
#include "World.h"

namespace kelp
{
    class World;
    class Component;
    class Entity
    {
    public:
        World * m_world;
        std::string m_tag;
        std::vector<Component*> m_components;
        std::vector<Component*> m_newComponents;
        std::vector<Component*> m_exiledComponents;
        Entity * m_parent;
        Entity(World * _world, std::string _tag);
        ~Entity();
        void init();
        void update();
        void render();
        void addComponent(Component * _c);
        int deleteComponent(Component * _c);
        int deleteComponentNextFrame(Component * _c);
        template<typename ComponentType> inline ComponentType * getComponent()
        {
            for (int i = 0; i < this->m_components.size(); i++)
            {
                ComponentType * tempComp = dynamic_cast<ComponentType*>(this->m_components[i]);
                if (tempComp != NULL)
                    return tempComp;
            }
            return NULL;
        }
        
        template<typename ComponentType> inline int deleteComponent(bool _nextFrame = false)
        {
            ComponentType * comp = getComponent<ComponentType>();
            if(comp != NULL)
                if(_nextFrame)
                    return deleteComponentNextFrame(comp);
                else
                    return deleteComponent(comp);
            return 1;//the component does not exist
        }
        
        
    };
    
};
#endif // ENTITY_H_
