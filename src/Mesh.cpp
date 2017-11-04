#include "Mesh.h"
using namespace kelp;
#define TINYOBJLOADER_IMPLEMENTATION
#include "tiny_obj_loader.h"
Mesh::Mesh()
{
    m_vao = 0;
    m_vbo = 0;
}

Mesh::~Mesh()
{
    
}


MeshGen::MeshGen()
{
    
}
MeshGen::~MeshGen()
{
    if(m_vbo != 0)
        glDeleteBuffers(1, &m_vbo);
    if(m_vao != 0)
        glDeleteVertexArrays(1, &m_vao);
}

void MeshGen::addTri(kep::Vector3 _p0, kep::Vector3 _p1, kep::Vector3 _p2)
{
    m_verticies.push_back(_p0);
    m_verticies.push_back(_p1);
    m_verticies.push_back(_p2);
}

void MeshGen::gen()
{
    ///////////////////////////////////
    if(m_vbo != 0)
        glDeleteBuffers(1, &m_vbo);
    if(m_vao != 0)
        glDeleteVertexArrays(1, &m_vao);
    ///////////////////////////////////
    
    
    glGenVertexArrays(1, &m_vao);
    glBindVertexArray(m_vao);

    m_numVertices = m_verticies.size();
    glGenBuffers(1, &m_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(kep::Vector3) * m_verticies.size(), &m_verticies[0], GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}


MeshLoad::MeshLoad(const char * _objPath, const char * _mtlDir)
{
    tinyobj::attrib_t attrib;
    std::vector<tinyobj::shape_t> shapes;
    std::vector<tinyobj::material_t> materials;
    
    std::string err;
    bool ret = tinyobj::LoadObj(&attrib, &shapes, &materials, &err, _objPath, _mtlDir);
    
    if (!err.empty())
        printf("%s \n", err.c_str());
        

    if (!ret) 
        exit(1);

    
    size_t dataSize = 0;
    
    for (size_t s = 0; s < shapes.size(); s++) 
    {
        size_t index_offset = 0;
        for (size_t f = 0; f < shapes[s].mesh.num_face_vertices.size(); f++)
        {
            int fv = shapes[s].mesh.num_face_vertices[f];
            for (size_t v = 0; v < fv; v++)
            {
                for(size_t i = 0; i<3; i++)
                    dataSize++;
            }
        }
    }
    float * data = new float[dataSize];
    size_t dataPointer = 0;
    
    // Loop over shapes
    for (size_t s = 0; s < shapes.size(); s++) 
    {
        // Loop over faces(polygon)
        size_t index_offset = 0;
        for (size_t f = 0; f < shapes[s].mesh.num_face_vertices.size(); f++)
        {
            int fv = shapes[s].mesh.num_face_vertices[f];
            //printf("face %d %d \n", f, fv);
            // Loop over vertices in the face.
            for (size_t v = 0; v < fv; v++)
            {
                // access to vertex
                tinyobj::index_t idx = shapes[s].mesh.indices[index_offset + v];
                for(size_t i = 0; i<3; i++)
                {
                    data[dataPointer] = attrib.vertices[3*idx.vertex_index+i];
                    dataPointer++;
                }
                
                
                
//                 tinyobj::real_t vx = attrib.vertices[3*idx.vertex_index+0];
//                 tinyobj::real_t vy = attrib.vertices[3*idx.vertex_index+1];
//                 tinyobj::real_t vz = attrib.vertices[3*idx.vertex_index+2];
                
                //printf("%f %f %f \n", vx, vy, vz);
//                 tinyobj::real_t nx = attrib.normals[3*idx.normal_index+0];
//                 tinyobj::real_t ny = attrib.normals[3*idx.normal_index+1];
//                 tinyobj::real_t nz = attrib.normals[3*idx.normal_index+2];
//                 
//                 tinyobj::real_t tx = attrib.texcoords[2*idx.texcoord_index+0];
//                 tinyobj::real_t ty = attrib.texcoords[2*idx.texcoord_index+1];
                // Optional: vertex colors
                // tinyobj::real_t red = attrib.colors[3*idx.vertex_index+0];
                // tinyobj::real_t green = attrib.colors[3*idx.vertex_index+1];
                // tinyobj::real_t blue = attrib.colors[3*idx.vertex_index+2];
            }
            index_offset += fv;

            // per-face material
            shapes[s].mesh.material_ids[f];
        }
    }
    
    m_numVertices = dataSize/3;
    glGenVertexArrays(1, &m_vao);
    glBindVertexArray(m_vao);

    glGenBuffers(1, &m_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * dataSize, &data[0], GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    
    delete[] data;
}

MeshLoad::~MeshLoad()
{
    if(m_vbo != 0)
        glDeleteBuffers(1, &m_vbo);
    if(m_vao != 0)
        glDeleteVertexArrays(1, &m_vao);
}

