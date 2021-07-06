cmake_minimum_required(VERSION 3.5)

project(LifeGFX LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (CMAKE_SYSTEM_NAME MATCHES "^MINGW")
    set(SYSTEM_LIBS -lstdc++)
else()
    set(SYSTEM_LIBS)
endif()

add_executable(LifeGFX main.cpp ConsoleLifeTest.cpp ConsoleLifeTest.h)

target_include_directories(LifeGFX PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}" "C:\\LIB\\Life-LIB\\include\\")
target_include_directories(LifeGFX PUBLIC "C:\\LIB\\SFML-2.5.1-windows-vc15-64-bit\\SFML-2.5.1\\include\\")
target_link_directories(LifeGFX PUBLIC "C:\\LIB\\Life-LIB\\lib\\$<IF:$<CONFIG:Debug>,Debug,Release>")
target_link_directories(LifeGFX PUBLIC "C:\\LIB\\SFML-2.5.1-windows-vc15-64-bit\\SFML-2.5.1\\lib\\")
target_link_libraries(LifeGFX LifeLib sfml-graphics-d.dll sfml-window-d.dll sfml-system-d.dll ${SYSTEM_LIBS})
