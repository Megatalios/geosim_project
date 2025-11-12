cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)
project(geosim_project)

add_library(geosim_core 
src/FlatSurface.cpp
)

target_include_directories(geosim_core 
    PUBLIC 
        src
	externals/eigen
)

