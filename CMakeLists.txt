cmake_minimum_required(VERSION 3.10)

project(ProjetoGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(SFML_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(SFML_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(SFML_INSTALL_PDB OFF CACHE BOOL "" FORCE)

add_subdirectory(thirdparty/SFML-2.6.2)

file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/media" 
     DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")

set(SOURCES
  src/Main.cpp
  src/Game.cpp
  src/Physics.cpp
  # src/Menu.cpp
  src/entities/Ente.cpp
  src/entities/Entity.cpp
  src/entities/ListEntities.cpp
  src/entities/characters/Player.cpp
  src/entities/characters/Character.cpp
  # src/entities/characters/Enemy.cpp
  # src/entities/personagens/Tanystropheus.cpp
  # src/entities/personagens/Velociraptor.cpp
  # src/entities/personagens/Mamenchissauro.cpp
  # src/entities/collectables/Collectable.cpp
  # src/entities/collectables/Bone.cpp
  # src/entities/obstacles/Obstacle.cpp
  src/entities/obstacles/Platform.cpp
  # src/entities/obstacles/Cogumelo.cpp
  # src/entities/obstacles/Fogo.cpp
  # src/entities/projectables/Projectable.cpp
  # src/entities/projectables/LaserBall.cpp
  src/levels/Level.cpp
  src/levels/ForestLevel.cpp
  # src/levels/ExtinctionLevel.cpp
  src/managers/GraphicsManager.cpp
  # src/managers/CollisionManager.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME}  
PRIVATE
    sfml-graphics 
    sfml-window 
    sfml-system
)
target_include_directories(${PROJECT_NAME} PRIVATE include/)
