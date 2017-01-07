cmake_minimum_required(VERSION 3.3)
project(Ball_On_Plate_3D_Visual_1.0.0)

find_package(OpenGL REQUIRED)
#TODO set your own irrlicht path
include_directories(include  ${OPENGL_INCLUDE_DIRS}  /home/sveyda/irrlicht-1.8.4/include)

#TODO set your own irrlicht path
link_directories(/home/sveyda/irrlicht-1.8.4/lib)


#TODO set your own header file
file(GLOB 3D_SRC
        "include/*.h"
        "src/*.cpp"
         main.cpp)

#TODO organize own binary file outpath
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "/home/sveyda/ClionProjects/Ball_On_Plate_3D_Visual_1.0.0/bin/")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(GL_LIBRARY GL GLU X11 Xxf86vm)
add_executable(BallOnPlate ${3D_SRC} src/Plotting.cpp include/Plotting.h)

#TODO set your own irrlicht path
target_link_libraries(BallOnPlate /home/sveyda/irrlicht-1.8.4/lib/Linux/libIrrlicht.a ${OPENGL_LIBRARIES}  ${GL_LIBRARY})
