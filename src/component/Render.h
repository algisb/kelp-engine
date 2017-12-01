#ifndef RENDER_H_
#define RENDER_H_
#include "Component.h"
#include "Mesh.h"
#include "Shader.h"
#include "Transform.h"
#include "Config.h"
#include "kep/Core.h"
#include "Texture.h"
namespace kelp
{
    enum RenderMode
    {
        SOLID = 0,
        WIRE
    };
    class Render : public Component
    {
    public:

        Mesh * m_mesh;
        Shader * m_shader;
        Transform * m_transform;
        
        RenderMode m_renderMode;
        
        kep::Matrix4 m_modelMat;
        kep::Vector3 m_colour;
        
        Texture * m_texture;

        
        Render(Mesh* _mesh, Shader* _shader, Texture * _texture, RenderMode _renderMode, kep::Vector3 _colour = kep::Vector3(1.0f, 0.0f, 0.0f));
        ~Render();
        void init();
        void update();
        void render();
    };
};

#endif // RENDER_H_
