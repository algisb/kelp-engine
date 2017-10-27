#ifndef MESH_H_
#define MESH_H_
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include "GL/glew.h"
#include "glm.hpp"
namespace kelp
{
    class Mesh
    {
    public:
        std::vector<glm::vec3> m_verticies;

        std::vector<glm::vec2> m_uvs;

        std::vector<glm::vec3> m_normals;


        std::vector<glm::vec3> m_tangents;

        std::vector<glm::vec3> m_bitangents;


        GLuint m_vao;
        unsigned int m_numVertices;
        
        Mesh();
        virtual ~Mesh()=0;
        
    };
    
    class MeshGen : public Mesh
    {
    public:
        MeshGen();
        ~MeshGen();
        void addTri(glm::vec3 _p0, glm::vec3 _p1, glm::vec3 _p2);
        void gen();
    };
    
    class MeshLoad : public Mesh
    {
    };
};



#endif // MESH_H_
