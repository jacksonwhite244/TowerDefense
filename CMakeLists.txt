cmake_minimum_required(VERSION 3.10)
project(TowerDefenseProj)

set(CMAKE_CXX_STANDARD 20)

include_directories("C:/SFML/include")

add_executable(TowerDefenseProj main.cpp)

target_link_libraries(TowerDefenseProj
        "C:/SFML/lib/libsfml-system.a"
        "C:/SFML/lib/libsfml-window.a"
        "C:/SFML/lib/libsfml-graphics.a"
        "C:/SFML/lib/libsfml-audio.a"
        "C:/SFML/lib/libsfml-network.a"
)

