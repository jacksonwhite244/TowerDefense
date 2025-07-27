project(TowerDefenseLib)

set(SFML_ROOT "/opt/homebrew/opt/sfml")
set(SFML_INCLUDE_DIR "${SFML_ROOT}/include")
set(SFML_LIB_DIR "${SFML_ROOT}/lib")

set(SOURCE_FILES
        Game.cpp Game.h
        Character.cpp Character.h
        CharacterMenu.cpp CharacterMenu.h
        Map.cpp Map.h
        Cat.cpp Cat.h
        Monster.cpp Monster.h
        MainMenu.cpp MainMenu.h
)

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

# Include SFML headers and your source folder
target_include_directories(${PROJECT_NAME} PUBLIC
        ${SFML_INCLUDE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}
)

# Link the SFML dynamic libraries explicitly
target_link_libraries(${PROJECT_NAME}
        "${SFML_LIB_DIR}/libsfml-graphics.dylib"
        "${SFML_LIB_DIR}/libsfml-window.dylib"
        "${SFML_LIB_DIR}/libsfml-system.dylib"
        "${SFML_LIB_DIR}/libsfml-audio.dylib"
        "${SFML_LIB_DIR}/libsfml-network.dylib"
)
