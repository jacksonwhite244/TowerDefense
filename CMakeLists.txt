cmake_minimum_required(VERSION 3.14)
project(TowerDefense)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(TowerDefenseLib)

add_executable(TowerDefenseExecutable main.cpp)

target_link_libraries(TowerDefenseExecutable PRIVATE TowerDefenseLib)