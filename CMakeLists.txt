cmake_minimum_required(VERSION 3.14)
project(TowerDefense)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(TowerDefenseLib)

add_executable(TowerDefenseExecutable main.cpp)

# copy the imges folder and level folder to cmake build directory
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/images/
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/images/)

target_link_libraries(TowerDefenseExecutable PRIVATE TowerDefenseLib)