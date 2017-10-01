cmake_minimum_required (VERSION 3.1.0)

project (kelp-engine)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "./bin")

find_package(OpenGL)
include_directories( ${OPENGL_INCLUDE_DIRS} )


include_directories ("./freeglut3/include")
link_directories("./freeglut3/lib")


add_executable(kelp-engine "./src/main.cpp")
target_link_libraries (kelp-engine ${OPENGL_LIBRARIES} glut)
