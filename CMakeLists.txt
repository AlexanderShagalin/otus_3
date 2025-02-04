cmake_minimum_required(VERSION 3.15)

project(battlefield LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SRC ./source)
include_directories(./include)

add_executable(battleship   ${SRC}/main.cpp 
                            ${SRC}/angle.cpp 
                            ${SRC}/vector2d.cpp 
                            ${SRC}/moveforward.cpp
                            ${SRC}/rotate.cpp
                            ${SRC}/battlecruiser.cpp
                             )

install(TARGETS battleship
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

add_subdirectory(tests)
