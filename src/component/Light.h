#ifndef LIGHT_H_
#define LIGHT_H_
#include "Component.h"
#include "kep/Core.h"
#include "Shader.h"

namespace kelp
{
    class Light : public Component
    {
    public:
        Shader * m_shader;
        float m_strength;
        kep::Vector3 m_colour;
        int m_enabled;
        
        int m_shaderStrengthLocation;
        int m_shaderColourLocation;
        int m_shaderEnabledLocation;
        int m_shaderTypeLocation;
        int m_shaderNumLightsLocation;

        
        Light(Shader * _shader, float _stength, kep::Vector3 _colour);
        virtual ~Light() = 0;
        virtual void init();
        virtual void update();
        virtual void render();
    };
    
    class LightDirectional : public Light
    {
    public:
        kep::Vector3 m_direction;
        int m_shaderDirectionLocation;
        
        LightDirectional(Shader * _shader, float _stength, kep::Vector3 _colour, kep::Vector3 _direction);
        ~LightDirectional();
        void init();
        void update();
        void render();
    };
    
    
    
    class LightPoint : public Light
    {
    public:
        LightPoint(Shader * _shader, float _stength, kep::Vector3 _colour);
        ~LightPoint();
        void update();
    };
};


#endif // LIGHT_H_
