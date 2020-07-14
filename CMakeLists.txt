cmake_minimum_required(VERSION 3.16)
project(Lab_Programmazione)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_AUTOMOC ON)

find_package(Qt5Widgets REQUIRED)

set(SOURCE_FILES main.cpp File.cpp File.h Observer.h Subject.h)

add_executable(Lab_Programmazione main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(core Qt5::Widgets)
target_link_libraries(${PROJECT_NAME} core)