set(LIB_NAME sdl_lib)

set(INCLUDE_PATH ${PROJECT_SOURCE_DIR}/include/sdl)

set(HEADERS ${INCLUDE_PATH}/Field.hpp
            ${INCLUDE_PATH}/SdlElement.hpp
            ${INCLUDE_PATH}/LifeAdapter.hpp)

set(SOURCES Field.cpp
            LifeAdapter.cpp
            Application.cpp)

find_package(SDL2 REQUIRED)

add_library(${LIB_NAME} ${HEADERS} ${SOURCES})

target_link_libraries(${LIB_NAME} ${SDL2_LIBRARIES})
target_include_directories(${LIB_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)