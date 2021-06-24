cmake_minimum_required(VERSION 3.11)

project(life_test CXX)
set(CMAKE_CXX_STANDARD 17)

if (CMAKE_SYSTEM_NAME MATCHES "^MINGW")
    set(SYSTEM_LIBS -lstdc++)
else()
    set(SYSTEM_LIBS)
endif()

add_executable(life_test life.cpp Colony.h Colony.cpp Evolution.h Evolution.cpp Cell.h Cell.cpp Exception.h Structures.h)
target_include_directories(life_test PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(life_test ${SYSTEM_LIBS})
