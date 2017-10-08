#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Config.h"
#include "Input.h"
#include "Core.h"
#include "Time.h"


static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) 
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
    
    kelp::Input::update(key, action);
        
}
static void error_callback(int error, const char *description)
{
    fputs(description, stderr);
}




int main(void)
{
    GLFWwindow *window;
    
    glewExperimental = GL_TRUE;
    glewInit();
    
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    window = glfwCreateWindow(
        kelp::Config::windowWidth, 
        kelp::Config::windowHeight,
        "kelp-engine", 
        NULL, 
        NULL);
    if (!window) 
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);
    //////////////////////////////////////////////////////////////
    kelp::Core * core = new kelp::Core();
    while (!glfwWindowShouldClose(window))
    {
        kelp::Time::calc();
        //printf("fps: %d \n", kelp::Time::frameRate);
        //printf("deltaT: %f \n", kelp::Time::deltaT);
        
        glClearColor(0.0f, 0.1f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT/*|GL_DEPTH_BUFFER_BIT|GL_ACCUM_BUFFER_BIT*/);
        glfwPollEvents();
        kelp::Input::printKeyList();
        core->update();
        
        glfwSwapBuffers(window);
        kelp::Input::clear();
        
        
        //NOT SO FAST
        //              .--._
        //               `.  `-.
        //               .-'    `.
        //             .'      _..:._
        //            `.  .--.'      `.
        //            _.'  \.      .--.\
        //          .'      |     |    |
        //         `--.     |  .--|    D
        //             `;  /'\/   ,`---'@
        //           .'  .'   '._ `-.__.'
        //         .'  .'      _.`---'
        //       .'--''   .   `-..__.--.
        //    ~-=  =-~_-   `-..___(  ===;
        //    ~-=  - -    .'       `---'
        kelp::Time::calcEnd();
    }

    
    delete core;
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}
