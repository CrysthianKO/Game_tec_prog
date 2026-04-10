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
  src/entities/Player.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME}  SFML::Graphics SFML::Window SFML::System)

target_include_directories(${PROJECT_NAME} PRIVATE include/)
