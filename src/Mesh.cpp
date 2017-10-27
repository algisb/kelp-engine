#include "Mesh.h"
using namespace kelp;

Mesh::Mesh()
{
    
}

Mesh::~Mesh()
{
    
}

void MeshGen::addTri(glm::vec3 _p0, glm::vec3 _p1, glm::vec3 _p2)
{
    m_verticies.push_back(_p0);
    m_verticies.push_back(_p1);
    m_verticies.push_back(_p2);
}

void MeshGen::gen()
{
    m_vao = 0;
    glGenVertexArrays(1, &m_vao);
    glBindVertexArray(m_vao);

    m_numVertices = m_verticies.size();
    GLuint buffer = 0;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * m_verticies.size(), &m_verticies[0], GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

