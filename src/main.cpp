#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Input.h"

#define GLSL(src) #src

static void error_callback(int error, const char *description)
{
    fputs(description, stderr);
}

static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) 
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
    
    if(key == GLFW_KEY_UP && action == GLFW_PRESS)
        printf("up pressed \n");
    
        
}


static void render(GLFWwindow *window)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT|GL_ACCUM_BUFFER_BIT);
}


int main(void)
{
    GLFWwindow *window;

    glfwSetErrorCallback(error_callback);

    if (!glfwInit())
        exit(EXIT_FAILURE);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    window = glfwCreateWindow(640, 480, "kelp-engine", NULL, NULL);
    if (!window) 
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glewExperimental = GL_TRUE;
    glewInit();

    glfwMakeContextCurrent(window);

    glfwSetKeyCallback(window, key_callback);
    glClearColor(1,0,0,1);
    kelp::Input input; 
    while (!glfwWindowShouldClose(window))
    {
        
        render(window);

        glfwSwapBuffers(window);
        glfwPollEvents();
        //glfwWaitEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}
