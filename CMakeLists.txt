cmake_minimum_required(VERSION 3.17)
project(servoClasseAvril)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(servoClasseAvril
        servoClasseAvril.ino
        ServoM.cpp
        ServoM.h)
