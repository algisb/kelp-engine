///
///  @file World.cpp
///  @brief draws entity to the frame buffer

#include "Render.h"
#include "Camera.h"


using namespace kelp;

Render::Render(Mesh * _mesh, Shader * _shader) : Component()
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
    m_modelMat = kep::Matrix4(1,0,0,0,
                              0,1,0,0,
                              0,0,1,-10,
                              0,0,0,1).transpose();
    m_viewMat  = kep::Matrix4();
    
    //glm::mat4 pjmat = glm::perspectiveFov<float>(45.0f, Config::s_windowWidth, Config::s_windowHeight, 0.1f, 2000.0f);
    
    
    m_projectionMat = m_owner->m_world->m_renderCamera->m_projectionMat;
//     m_projectionMat = kep::perspectiveProjection(45.0f, 
//                                                  Config::s_windowWidth, 
//                                                  Config::s_windowHeight, 
//                                                  0.1f, 
//                                                  2000.0f).transpose();
                                   
//     m_projectionMat = kep::Matrix4(pjmat[0][0],pjmat[0][1],pjmat[0][2],pjmat[0][3],
//                                    pjmat[1][0],pjmat[1][1],pjmat[1][2],pjmat[1][3],
//                                    pjmat[2][0],pjmat[2][1],pjmat[2][2],pjmat[2][3],
//                                    pjmat[3][0],pjmat[3][1],pjmat[3][2],pjmat[3][3]);
                                   
                                   
//     printf("%f %f %f %f \n%f %f %f %f \n", m_modelMat.d[0][0], m_modelMat.d[0][1], m_modelMat.d[0][2], m_modelMat.d[0][3], m_modelMat.d[1][0], m_modelMat.d[1][1], m_modelMat.d[1][2], m_modelMat.d[1][3]
//     );
//     printf("\n");

}
void Render::render()
{
    glUseProgram(m_shader->m_shaderLocation);

    glUniformMatrix4fv(m_shader->m_shaderModelMatLocation, 1, 
                       GL_FALSE, &m_modelMat.d[0][0]);
    glUniformMatrix4fv(m_shader->m_shaderViewMatLocation, 1, 
                       GL_FALSE, &m_viewMat.d[0][0]);
    glUniformMatrix4fv(m_shader->m_shaderProjMatLocation, 1, 
                       GL_FALSE, &m_projectionMat.d[0][0]);

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
