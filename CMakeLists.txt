cmake_minimum_required(VERSION 3.25)
project(life)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(src)

add_executable(life main.cpp)

target_link_libraries(life sdl_lib life_lib)
target_include_directories(life PUBLIC include/sdl include/lifeSim)
