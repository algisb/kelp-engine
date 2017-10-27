#ifndef SHADER_H_
#define SHADER_H_

#include "GL/glew.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>


namespace kelp
{
    class Shader
    {
    public:
        int m_shaderLocation;

        //matrix locations
        //int m_shaderModelMatLocation;
        //int m_shaderViewMatLocation;
        //int m_shaderProjMatLocation;


        Shader(const char * _vertexShaderPath,const char * _fragmentShaderPath);
        ~Shader();
        
        std::string LoadShader(const char *_shaderPath);
        bool CheckShaderCompiled(int _shaderLocation);
        void BuildShader(int &_shaderLocation, const char * _vertexShaderPath, const char * _fragmentShaderPath);

    };
    
};

#endif // SHADER_H_
