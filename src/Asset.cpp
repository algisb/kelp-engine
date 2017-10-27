///
///  @file Asset.cpp
///  @brief hold externally loaded models, textures, shaders, skeletal rigs and animations
#include "Asset.h"

using namespace kelp;


Asset::Asset(Shader * _shader)
{
    m_shader = _shader;
}
Asset::~Asset()
{
    delete m_shader;
}
