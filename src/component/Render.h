#ifndef RENDER_H_
#define RENDER_H_
#include "Component.h"
#include "Mesh.h"
#include "Shader.h"
#include "Transform.h"
#include "glm.hpp"
#include "gtc/type_ptr.hpp"
#include "gtc/matrix_transform.hpp"
#include "Config.h"
namespace kelp
{
    class Render : public Component
    {
    public:

        Mesh * m_mesh;
        Shader * m_shader;
        Transform * m_transform;
        
        glm::mat4 m_modelMat;
        glm::mat4 m_viewMat;
        glm::mat4 m_projectionMat;
        
        Render(Mesh * _mesh, Shader * _shader);
        ~Render();
        void init();
        void update();
        void render();
    };
};

#endif // RENDER_H_
