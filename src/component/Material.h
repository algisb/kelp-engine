#ifndef MATERIAL_H_
#define MATERIAL_H_
#include "Component.h"
#include "Shader.h"
#include "Texture.h"

namespace kelp
{
    class Material : public Component
    {
    public:
        Material();
        ~Material();
        
        Shader * m_shader;
        Texture * m_texture;
    };
};


#endif // MATERIAL_H_
