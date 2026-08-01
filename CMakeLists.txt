cmake_minimum_required(VERSION 3.13)
project(Ciya C)

file(GLOB_RECURSE SRC CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c)
add_executable(ciya ${SRC})
target_include_directories(ciya PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/)
