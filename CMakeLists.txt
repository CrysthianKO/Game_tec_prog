cmake_minimum_required(VERSION 3.10)

project(ProjetoGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(SFML_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(SFML_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(SFML_INSTALL_PDB OFF CACHE BOOL "" FORCE)

add_subdirectory(thirdparty/SFML-3.0.2)

file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/media" 
     DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")

set(SOURCES
  src/Main.cpp
  src/Game.cpp
  src/Physics.cpp
<<<<<<< HEAD
  src/Menu.cpp
  src/Ente.cpp
  src/entities/Entity.cpp
  src/entities/characters/Player.cpp
  src/entities/characters/Character.cpp
  src/entities/characters/Enemy.cpp
  src/entities/characters/Tanystropheus.cpp
  src/entities/characters/Velociraptor.cpp
  src/entities/characters/Mamenchissauro.cpp
  src/entities/collectables/Collectable.cpp
  src/entities/collectables/Bone.cpp
  src/entities/obstacles/Obstacle.cpp
  src/entities/obstacles/Mushroom.cpp
  src/entities/obstacles/Platform.cpp
  src/entities/obstacles/Fire.cpp
  src/entities/projectables/Projectable.cpp
  src/entities/projectables/LaserBall.cpp
  src/phases/Level.cpp
  src/phases/ForestLevel.cpp
  src/phases/ExtinctionLevel.cpp
  src/managers/GraphicsManager.cpp
  src/managers/CollisionManager.cpp
  src/lists/Element.cpp
  src/lists/List.cpp
  src/lists/EntityList.cpp
=======
  # src/Menu.cpp
  src/entities/Ente.cpp
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
  # src/fases/Level.cpp
  # src/fases/ForestLevel.cpp
  # src/fases/ExtinctionLevel.cpp
  src/managers/GraphicsManager.cpp
  # src/managers/CollisionManager.cpp
>>>>>>> 4795ee6bbd3d3fcd1a4b5ea5a06f8eca20a8fb09
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME}  SFML::Graphics SFML::Window SFML::System)
target_include_directories(${PROJECT_NAME} PRIVATE include/)
