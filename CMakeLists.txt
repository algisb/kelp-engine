cmake_minimum_required (VERSION 3.1.0)

project (kelp-engine)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "./bin")

#glew------------------------------------------------
#include_directories ("./external/glew/include")
add_subdirectory("./external/glew/build/cmake")
include_directories (${GLEW_DIR}/include)
add_definitions(-DGLEW_STATIC)



#opengl----------------------------------------------
find_package(OpenGL)
include_directories( ${OPENGL_INCLUDE_DIRS} )


#freeglut--------------------------------------------
set(FREEGLUT_BUILD_DEMOS OFF CACHE BOOL "")
set(FREEGLUT_BUILD_SHARED_LIBS OFF CACHE BOOL "")
#set(FREEGLUT_BUILD_STATIC_LIBS OFF CACHE BOOL "")
#set(FREEGLUT_BUILD_PRINT_WARNINGS OFF CACHE BOOL "")

include_directories ("./external/freeglut/include")
#link_directories("./freeglut3/lib")
add_subdirectory("./external/freeglut")
add_definitions(-DFREEGLUT_STATIC)

#-----------------------------------------------------------
add_executable(kelp-engine "./src/main.cpp")
#target_link_libraries (kelp-engine ${OPENGL_LIBRARIES} freeglut)
target_link_libraries (kelp-engine ${OPENGL_LIBRARIES} freeglut_static glew_s )
