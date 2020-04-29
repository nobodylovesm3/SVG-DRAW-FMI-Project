cmake_minimum_required(VERSION 3.13)
project(ProjectOOP)

set(CMAKE_CXX_STANDARD 17)

add_executable(ProjectOOP main.cpp cpps/rectangle.cpp headers/rectangle.h cpps/shape.cpp headers/shape.h cpps/line.cpp headers/line.h cpps/circle.cpp headers/circle.h cpps/group.cpp headers/group.h headers/pugixml.h cpps/pugixml.cpp)