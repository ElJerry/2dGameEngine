cmake_minimum_required(VERSION 3.14)
project(2dGameTest)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED sdl2)
find_package(SDL2_image REQUIRED)


include_directories(
    framework/include
    game/include
    game/scripts
    /usr/local/include/SDL2
    /usr/include/SDL2
    /usr/local/lib
    ${SDL2_INCLUDE_DIRS}
)

add_executable(2dGameTest
    # Framework binaries
    framework/src/main.cpp
    framework/src/Game.cpp
    framework/src/GameObject.cpp
    framework/src/main.cpp
    framework/src/Vector2D.cpp
    framework/src/components/Component.cpp
    framework/src/components/ComponentIdentifier.cpp
    framework/src/components/RendererComponent.cpp
    framework/src/components/SpriteAnimatorComponent.cpp
    framework/src/components/TextureComponent.cpp
    framework/src/components/TransformComponent.cpp
    framework/src/components/ControllerComponent.cpp
    framework/src/components/TileMapComponent.cpp
    framework/src/components/RigidBodyComponent.cpp
    framework/src/components/ColliderComponent.cpp
    framework/src/collision/CollisionManager.cpp
    framework/src/camera/Camera.cpp

    # Game binaries
    game/src/game_main.cpp
    game/src/gameObjects/Player.cpp
    game/src/gameObjects/GameMap.cpp
    )

target_link_libraries(2dGameTest ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})


