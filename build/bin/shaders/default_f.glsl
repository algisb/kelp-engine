#version 430 core

out vec4 fragColour;
////////////////////

in vec3 vNormal_m;
in vec3 vDirLigt_m;

void main()
{
    float diff = clamp(dot(vNormal_m, vDirLigt_m), 0, 1);
    fragColour = vec4(vec3(1.0, 0.0, 0.0)*diff, 1.0);
}

