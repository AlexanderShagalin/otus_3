cmake_minimum_required(VERSION 3.15)

project(battlefield LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SRC ./source)
include_directories(./include)
include_directories(./generated)

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
                            ${SRC}/burnfuelcommand.cpp
                            ${SRC}/secondretrycommand.cpp
                            ${SRC}/changevelocitycommand.cpp
                            ${SRC}/iocregistercommand.cpp
                            ${SRC}/iocnewscopecommand.cpp
                            ${SRC}/iocsetscoperelativecommand.cpp
                            ${SRC}/iocsetscopeabsolutecommand.cpp
                            ${SRC}/fallbackcommand.cpp
                            ${SRC}/macrocommand.cpp
                            ${SRC}/maneuveringcommand.cpp
                            ${SRC}/secondretryhandler.cpp
                            ${SRC}/strategy_1.cpp
                            ${SRC}/strategy_2.cpp
                            ${SRC}/resolvercollection.cpp
                            ${SRC}/scope.cpp
                            ${SRC}/scopechangeradapter.cpp
                            ${SRC}/ioc.cpp
                            ${SRC}/scopecontainer.cpp
                            ${SRC}/battlecruiser.cpp
                            ${SRC}/main.cpp
                            )

install(TARGETS battlefield
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

add_subdirectory(tests)
