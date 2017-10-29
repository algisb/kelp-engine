///
///  @file World.cpp
///  @brief draws entity to the frame buffer

#include "Render.h"


using namespace kelp;

Render::Render(Mesh * _mesh, Shader * _shader)
{
    m_mesh = _mesh;
    m_shader = _shader;
}
Render::~Render()
{
    
}

void Render::init()
{
    m_transform = m_owner->getComponent<Transform>();
}
void Render::update()
{
    m_modelMat = glm::translate(glm::mat4(1.0f), glm::vec3(0,0,-10));
    m_viewMat  = glm::mat4(1.0f);
    m_projectionMat = glm::perspectiveFov<float>(45.0f,Config::s_windowWidth, Config::s_windowHeight, 0.1f, 2000.0f);
}
void Render::render()
{
    glUseProgram(m_shader->m_shaderLocation);

    glUniformMatrix4fv(m_shader->m_shaderModelMatLocation, 1, 
                       GL_FALSE, glm::value_ptr(m_modelMat));
    glUniformMatrix4fv(m_shader->m_shaderViewMatLocation, 1, 
                       GL_FALSE, glm::value_ptr(m_viewMat));
    glUniformMatrix4fv(m_shader->m_shaderProjMatLocation, 1, 
                       GL_FALSE, glm::value_ptr(m_projectionMat));

    switch(1)
    {
        case 1:
            glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
            break;
        
        case 2:
            glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
            break;
    }
    glBindVertexArray( m_mesh->m_vao );
    glDrawArrays(GL_TRIANGLES, 0, m_mesh->m_numVertices);
    glBindVertexArray( 0 );

}
