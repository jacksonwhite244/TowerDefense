project(TowerDefenseLib)

set(SFML_INCLUDE_DIR "C:/SFML/include")
set(SFML_LIB_DIR "C:/SFML/lib")

set(SOURCE_FILES
        Game.cpp
        Game.h
        Character.cpp
        Character.h
        NormalPirate.cpp
        NormalPirate.h
        CharacterMenu.cpp
        CharacterMenu.h
        Map.cpp
        Map.h
        Item.cpp
        Item.h)


add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME}
        PUBLIC ${SFML_INCLUDE_DIR} ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${PROJECT_NAME}
        "${SFML_LIB_DIR}/libsfml-system.a"
        "${SFML_LIB_DIR}/libsfml-window.a"
        "${SFML_LIB_DIR}/libsfml-graphics.a"
        "${SFML_LIB_DIR}/libsfml-audio.a"
        "${SFML_LIB_DIR}/libsfml-network.a")