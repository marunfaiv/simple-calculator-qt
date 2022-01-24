cmake_minimum_required(VERSION 3.10.0)

project(calculator)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5 CONFIG REQUIRED COMPONENTS Widgets)

add_executable(calculator
   mainwindow.ui
   mainwindow.cpp
   main.cpp
#    object.cpp
   resources.qrc)

target_link_libraries(calculator
   Qt5::Widgets)