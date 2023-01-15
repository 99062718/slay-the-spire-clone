cmake_minimum_required(VERSION 3.0)

project(slay_the_spire_clone)

include_directories(${PROJECT_SOURCE_DIR})
add_executable(app main.cpp general/battle.cpp entities/entity.cpp entities/ally.cpp entities/enemy.cpp cards/cardsLogic.cpp)