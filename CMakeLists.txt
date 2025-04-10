cmake_minimum_required(VERSION 3.30)
project(ccppstart2025)

set(CMAKE_CXX_STANDARD 20)

add_executable(ccppstart2025
        main.cpp
        CircleModule/Circle.cpp
        CircleModule/Color.cpp
        CircleModule/Point.cpp
)

include_directories(CircleModule)
