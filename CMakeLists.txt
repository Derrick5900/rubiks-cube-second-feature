cmake_minimum_required(VERSION 3.16)
project(Rubik_sCubeFirstFeature)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/include)

# ------------ main program ----------------
add_executable(Rubik_sCubeFirstFeature
    src/Cube.cpp
    src/CubeManager.cpp
    src/CubeSaver.cpp
    src/Side.cpp
    main.cpp
        include/Cubeloader.h
        src/CubeLoader.cpp
)

# ----------------- tests -------------------
enable_testing()

add_executable(test_feature
    tests/test_feature.cpp
    src/Cube.cpp
    src/CubeManager.cpp
    src/Side.cpp

)

