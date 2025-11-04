cmake_minimum_required(VERSION 3.20)

project(geosim_project)

add_library(geosim_core 
src/FlatSurface.cpp
)

target_include_directories(geosim_core 
    PUBLIC 
        src
	externals/eigen
)

