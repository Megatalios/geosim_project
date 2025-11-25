cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)
project(geosim_project)

add_library(geosim_core 
    src/FlatSurface.cpp
    src/Solver.cpp
    
    # Заголовки
    src/ISurface.h
    src/Solver.h
    src/FlatSurface.h
)

add_executable(test_app
    src/FlatSurface.cpp
    src/Solver.cpp
    src/TestExecutable/main.cpp
    
    # Заголовки
    src/ISurface.h
    src/Solver.h
    src/FlatSurface.h
)

target_include_directories(geosim_core 
    PUBLIC 
        src
	externals/eigen
)

target_include_directories(test_app 
    PUBLIC 
        src
	externals/eigen
)
