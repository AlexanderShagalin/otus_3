cmake_minimum_required(VERSION 3.15)

project(battlefield LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SRC ./source)
include_directories(./include)

enable_testing()

add_executable(battlefield  ${SRC}/commandqueue.cpp
                            ${SRC}/angle.cpp 
                            ${SRC}/vector2d.cpp 
                            ${SRC}/exceptionmanager.cpp
                            ${SRC}/logger.cpp
                            ${SRC}/logexception.cpp
                            ${SRC}/loghandler.cpp
                            ${SRC}/moveforward.cpp
                            ${SRC}/rotate.cpp
                            ${SRC}/logcommand.cpp
                            ${SRC}/repeatcommand.cpp
                            ${SRC}/retrycommand.cpp
                            ${SRC}/retryhandler.cpp
                            ${SRC}/checkfuelcommand.cpp
                            ${SRC}/secondretrycommand.cpp
                            ${SRC}/secondretryhandler.cpp
                            ${SRC}/strategy_1.cpp
                            ${SRC}/strategy_2.cpp
                            ${SRC}/battlecruiser.cpp
                            ${SRC}/main.cpp
                            )

install(TARGETS battlefield
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

add_subdirectory(tests)
