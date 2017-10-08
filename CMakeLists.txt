cmake_minimum_required (VERSION 3.1.0)

project (kelp-engine)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "./bin")

#glew------------------------------------------------------
#include_directories ("./external/glew/include")
add_subdirectory("./external/glew/build/cmake")
include_directories ("./external/glew/include")
add_definitions(-DGLEW_STATIC)



#opengl----------------------------------------------------
find_package(OpenGL)
include_directories( ${OPENGL_INCLUDE_DIRS} )


#glfw------------------------------------------------------
set(BUILD_SHARED_LIBS OFF CACHE BOOL "")
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "")
set(GLFW_BUILD_TESTS OFF CACHE BOOL "")
set(GLFW_BUILD_DOCS OFF CACHE BOOL "")
set(GLFW_INSTALL OFF CACHE BOOL "")

include_directories ("./external/glfw/include")
add_subdirectory("./external/glfw")
add_definitions(-DGLFW_STATIC)

#glm-------------------------------------------------------
include_directories ("./external/glm/glm")

#kelp engine-----------------------------------------------
include_directories ("./src" "./src/Component")
file(GLOB KELP_SRC "./src/*.cpp" "./src/Component/*.cpp")
add_executable(kelp-engine ${KELP_SRC})
target_link_libraries (kelp-engine ${OPENGL_LIBRARIES} glfw glew_s )
