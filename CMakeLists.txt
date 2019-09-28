cmake_minimum_required(VERSION 3.14)
project(2dGameTest)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED sdl2)
find_package(SDL2_image REQUIRED)


include_directories(
        include
        /usr/local/include/SDL2
        /usr/include/SDL2
        /usr/local/lib
        ${SDL2_INCLUDE_DIRS}
)

add_executable(2dGameTest
    src/main.cpp
    src/Component.cpp
    src/ComponentIdentifier.cpp
    src/Game.cpp
    src/GameObject.cpp
    src/GameTexture.cpp
    src/main.cpp
    src/RendererComponent.cpp
    src/SpriteAnimatorComponent.cpp
    src/TextureComponent.cpp
    src/TransformComponent.cpp
    src/Vector2D.cpp
)

target_link_libraries(2dGameTest ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})


