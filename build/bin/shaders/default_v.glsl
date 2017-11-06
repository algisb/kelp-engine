#version 430 core

layout(location = 0) in vec4 vPosition;
layout(location = 1) in vec3 vNormal;
layout(location = 2) in vec2 vTextCoord;

out vec3 vNormal_m;
out vec3 vDirLigt_m;


uniform mat4 modelMat;
uniform mat4 viewMat;
uniform mat4 projMat;

void main()
{
    vDirLigt_m = normalize(mat3(viewMat) * normalize(vec3(1,1,1)));
    vNormal_m = mat3(viewMat * modelMat) * vNormal;
    gl_Position = projMat * viewMat * modelMat * vPosition;
}

