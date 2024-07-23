cmake_minimum_required(VERSION 3.10)
project(cameraTest)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(cameraTest main.cpp)

target_link_libraries(cameraTest ${OpenCV_LIBS})