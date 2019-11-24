cmake_minimum_required(VERSION 3.14)
project(2dGameTest)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

if(MSVC)
    # SDL 2
    set(SDL2_INCLUDE_DIRS "libs/SDL2-2.0.10/include")
    set(SDL2_LIBRARIES "${PROJECT_SOURCE_DIR}/libs/SDL2-2.0.10/lib/x64/SDL2.lib;${PROJECT_SOURCE_DIR}/libs/SDL2-2.0.10/lib/x64/SDL2main.lib")

    # SDL 2 Image
    set(SDL2_IMAGE_INCLUDE_DIRS "libs/SDL2_image-2.0.5/include")
    set(SDL2_IMAGE_LIBRARIES "${PROJECT_SOURCE_DIR}/libs/SDL2_image-2.0.5/lib/x64/SDL2_image.lib")

else()
    find_package(SDL2 REQUIRED sdl2)
    find_package(SDL2_image REQUIRED)
endif()

include_directories(
    include
    /usr/local/include/SDL2
    /usr/include/SDL2
    /usr/local/lib
    ${SDL2_INCLUDE_DIRS}
    ${SDL2_IMAGE_INCLUDE_DIRS}
)

add_executable(2dGameTest
    src/main.cpp
    src/components/Component.cpp
    src/components/ComponentIdentifier.cpp
    src/Game.cpp
    src/GameObject.cpp
    src/main.cpp
    src/components/RendererComponent.cpp
    src/components/SpriteAnimatorComponent.cpp
    src/components/TextureComponent.cpp
    src/components/TransformComponent.cpp
    src/Vector2D.cpp
    src/components/ControllerComponent.cpp
    src/gameObjects/Player.cpp
    src/gameObjects/GameMap.cpp
    src/components/TileMapComponent.cpp)

target_link_libraries(2dGameTest ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})


