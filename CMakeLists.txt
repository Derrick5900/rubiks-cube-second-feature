cmake_minimum_required(VERSION 3.16)
project(test_feature)

set(CMAKE_CXX_STANDARD 17)

# Our headers live in the include folder at the project root
include_directories(${CMAKE_SOURCE_DIR}/include)

# This CMakeList.txt is in tests/ folder.
# So we go up one level (..) to src/.
add_executable(test_feature
    ../src/Cube.cpp
    ../src/CubeManager.cpp
    main.cpp       # <- this file is in the same folder as this CMakeLists
)
