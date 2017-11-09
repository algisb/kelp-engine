#include "Light.h"
#include <sstream>
#include "Camera.h"
using namespace kelp;

Light::Light(Shader * _shader, float _stength, kep::Vector3 _colour)
{
    
    m_shader = _shader;
    m_strength = _stength;
    m_colour = _colour;
    m_enabled = 1;
}

Light::~Light()
{
    
}
void Light::init()
{
    m_owner->m_world->m_lights.push_back(this);
    ////////////////////////////////////////////////////
    std::string nameInShader;
    std::stringstream ss;
    
    ss << m_owner->m_world->m_lights.size()-1;//TODO: no coping mechanism for deleteing entities of lights sources
    std::string loc;
    ss >> loc;

    
    glUseProgram(m_shader->m_shaderLocation);
    nameInShader.clear();
    nameInShader = "light[" + loc + "].enabled";
    m_shaderEnabledLocation = glGetUniformLocation(m_shader->m_shaderLocation, nameInShader.c_str());

    nameInShader.clear();
    nameInShader = "light[" + loc + "].strength";
    m_shaderStrengthLocation = glGetUniformLocation(m_shader->m_shaderLocation, nameInShader.c_str());
    
    nameInShader.clear();
    nameInShader = "light[" + loc + "].colour";
    m_shaderColourLocation = glGetUniformLocation(m_shader->m_shaderLocation, nameInShader.c_str());
    
    nameInShader.clear();
    nameInShader = "light[" + loc + "].type";
    m_shaderTypeLocation = glGetUniformLocation(m_shader->m_shaderLocation, nameInShader.c_str());



    m_shaderNumLightsLocation = glGetUniformLocation(m_shader->m_shaderLocation, "numLights");
}

void Light::update()
{
    glUseProgram(m_shader->m_shaderLocation);
    glUniform1i(m_shaderEnabledLocation, m_enabled);
    glUniform1f(m_shaderStrengthLocation, m_strength);
    glUniform3fv(m_shaderColourLocation, 1, &m_colour.data[0]);
    glUniform1i(m_shaderNumLightsLocation, m_owner->m_world->m_lights.size());
}

void Light::render()
{
    
}


LightDirectional::LightDirectional(Shader * _shader, float _stength, kep::Vector3 _colour, kep::Vector3 _direction) : Light(_shader, _stength, _colour)
{
    m_direction = _direction;
}

LightDirectional::~LightDirectional()
{
    

}

void LightDirectional::init()
{
    Light::init();
    std::string nameInShader;
    std::stringstream ss;
    
    ss << m_owner->m_world->m_lights.size()-1;
    std::string loc;
    ss >> loc;

    
    glUseProgram(m_shader->m_shaderLocation);
    nameInShader.clear();
    nameInShader = "light[" + loc + "].direction";
    m_shaderDirectionLocation = glGetUniformLocation(m_shader->m_shaderLocation, nameInShader.c_str());
}

void LightDirectional::update()
{
    Light::update();
    glUseProgram(m_shader->m_shaderLocation);
    kep::Matrix4 viewMat = m_owner->m_world->m_renderCamera->m_viewMat;
    kep::Vector3 direction = m_direction;
    direction.normalize();
    direction = kep::Matrix3(viewMat).transpose() * direction;
    glUseProgram(m_shader->m_shaderLocation);
    glUniform3fv(m_shaderDirectionLocation, 1, &direction.data[0]);
    glUniform1i(m_shaderTypeLocation, 0);
}

void LightDirectional::render()
{
    
}





LightPoint::LightPoint(Shader * _shader, float _stength, kep::Vector3 _colour) : Light(_shader, _stength, _colour)
{
    
}

LightPoint::~LightPoint()
{
    
}
void LightPoint::update()
{
}
