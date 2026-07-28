# cmake_minimum_required(VERSION 3.7)
# project(Ciya C)

# file(GLOB_RECURSE SRC CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c)
# add_executable(ciya ${SRC})
# target_include_directories(ciya PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/)

cmake_minimum_required(VERSION 3.7)
project(Ciya C)

set(CMAKE_C_STANDARD 99)

# Automatically find all .c files right where they currently are
file(GLOB SRC CONFIGURE_DEPENDS "*.c" "utils/*.c")

add_executable(ciya ${SRC})

# Keep headers accessible from your current directories
target_include_directories(ciya PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/utils)
