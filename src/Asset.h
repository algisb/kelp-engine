#ifndef ASSET_H_
#define ASSET_H_
#include "Shader.h"
#include "Mesh.h"
namespace kelp
{
    class Asset
    {
    public:
        Asset(Shader * _shader);
        ~Asset();
        Shader * m_shader;
        
    };
    
};


#endif // ASSET_H_
