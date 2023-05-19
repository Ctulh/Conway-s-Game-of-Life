set(LIB_NAME life_lib)

set(INCLUDE_PATH ${PROJECT_SOURCE_DIR}/include/lifeSim)

set(HEADERS ${INCLUDE_PATH}/LifeLogic.hpp)

set(SOURCES LifeLogic.cpp)

add_library(${LIB_NAME} ${HEADERS} ${SOURCES})

target_include_directories(${LIB_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)