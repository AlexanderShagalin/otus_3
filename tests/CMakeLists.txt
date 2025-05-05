cmake_minimum_required(VERSION 3.15)

project(tests LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_definitions(-DGTEST_LANGUAGE_CXX11)

set(PRJ_DIR ..)

set(PRJ_SRC_DIR ${PRJ_DIR}/source)
set(PRJ_INC_DIR ${PRJ_DIR}/include)

enable_testing()

find_package(Threads REQUIRED)

find_package(GTest REQUIRED)
include_directories(${INCLUDE_DIRECTORIES}, /usr/include)
include_directories(${INCLUDE_DIRECTORIES}, ${PRJ_INC_DIR})
include_directories(${INCLUDE_DIRECTORIES}, ${PRJ_DIR}/generated)
include(GoogleTest)

add_executable(test_angle main.cpp test_angle.cpp ${PRJ_SRC_DIR}/angle.cpp)
target_link_libraries(test_angle PRIVATE ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} Threads::Threads )
gtest_discover_tests(test_angle)

add_executable(test_vector2d main.cpp test_vector2d.cpp ${PRJ_SRC_DIR}/vector2d.cpp)
target_link_libraries(test_vector2d PRIVATE ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} Threads::Threads )
gtest_discover_tests(test_vector2d)

add_executable(test_rotate main.cpp test_rotate.cpp ${PRJ_SRC_DIR}/angle.cpp ${PRJ_SRC_DIR}/rotate.cpp )
target_link_libraries(test_rotate PRIVATE ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} GTest::gmock Threads::Threads )
gtest_discover_tests(test_rotate)

add_executable(test_move main.cpp test_move.cpp ${PRJ_SRC_DIR}/vector2d.cpp ${PRJ_SRC_DIR}/moveforward.cpp )
target_link_libraries(test_move PRIVATE ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} GTest::gmock Threads::Threads )
gtest_discover_tests(test_move)

add_executable(test_logcommand main.cpp test_logcommand.cpp ${PRJ_SRC_DIR}/logcommand.cpp )
target_link_libraries(test_logcommand PRIVATE ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} GTest::gmock Threads::Threads )
gtest_discover_tests(test_logcommand)

add_executable(test_repeatcommand main.cpp test_repeatcommand.cpp ${PRJ_SRC_DIR}/repeatcommand.cpp )
target_link_libraries(test_repeatcommand PRIVATE ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} GTest::gmock Threads::Threads )
gtest_discover_tests(test_repeatcommand)

add_executable(test_loghandler main.cpp test_loghandler.cpp ${PRJ_SRC_DIR}/logcommand.cpp ${PRJ_SRC_DIR}/loghandler.cpp )
target_link_libraries(test_loghandler PRIVATE ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} GTest::gmock Threads::Threads )
gtest_discover_tests(test_loghandler)

add_executable(test_retryhandler main.cpp test_retryhandler.cpp ${PRJ_SRC_DIR}/retrycommand.cpp ${PRJ_SRC_DIR}/retryhandler.cpp )
target_link_libraries(test_retryhandler PRIVATE ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} GTest::gmock Threads::Threads )
gtest_discover_tests(test_retryhandler)

add_executable(test_strategy_1  main.cpp 
                                test_strategy_1.cpp 
                                ${PRJ_SRC_DIR}/vector2d.cpp
                                ${PRJ_SRC_DIR}/exceptionmanager.cpp
                                ${PRJ_SRC_DIR}/commandqueue.cpp 
                                ${PRJ_SRC_DIR}/retrycommand.cpp 
                                ${PRJ_SRC_DIR}/retryhandler.cpp 
                                ${PRJ_SRC_DIR}/logcommand.cpp
                                ${PRJ_SRC_DIR}/loghandler.cpp 
                                ${PRJ_SRC_DIR}/moveforward.cpp 
                                )
target_link_libraries(test_strategy_1 PRIVATE ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} GTest::gmock Threads::Threads )
gtest_discover_tests(test_strategy_1)

add_executable(test_strategy_2  main.cpp 
                                test_strategy_2.cpp 
                                ${PRJ_SRC_DIR}/vector2d.cpp
                                ${PRJ_SRC_DIR}/exceptionmanager.cpp
                                ${PRJ_SRC_DIR}/commandqueue.cpp 
                                ${PRJ_SRC_DIR}/retrycommand.cpp 
                                ${PRJ_SRC_DIR}/retryhandler.cpp 
                                ${PRJ_SRC_DIR}/secondretrycommand.cpp 
                                ${PRJ_SRC_DIR}/secondretryhandler.cpp 
                                ${PRJ_SRC_DIR}/logcommand.cpp
                                ${PRJ_SRC_DIR}/loghandler.cpp 
                                ${PRJ_SRC_DIR}/moveforward.cpp 
                                )
target_link_libraries(test_strategy_2 PRIVATE ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} GTest::gmock Threads::Threads )
gtest_discover_tests(test_strategy_2)

add_executable(test_checkfuelcommand main.cpp test_checkfuelcommand.cpp ${PRJ_SRC_DIR}/checkfuelcommand.cpp )
target_link_libraries(test_checkfuelcommand PRIVATE ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} GTest::gmock Threads::Threads )
gtest_discover_tests(test_checkfuelcommand)

add_executable(test_burnfuelcommand main.cpp test_burnfuelcommand.cpp ${PRJ_SRC_DIR}/burnfuelcommand.cpp )
target_link_libraries(test_burnfuelcommand PRIVATE ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} GTest::gmock Threads::Threads )
gtest_discover_tests(test_burnfuelcommand)

add_executable(test_macrocommand main.cpp test_macrocommand.cpp ${PRJ_SRC_DIR}/macrocommand.cpp )
target_link_libraries(test_macrocommand PRIVATE ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} GTest::gmock Threads::Threads )
gtest_discover_tests(test_macrocommand)

add_executable(test_changevelocitycommand main.cpp test_changevelocitycommand.cpp ${PRJ_SRC_DIR}/vector2d.cpp ${PRJ_SRC_DIR}/changevelocitycommand.cpp )
target_link_libraries(test_changevelocitycommand PRIVATE ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} GTest::gmock Threads::Threads )
gtest_discover_tests(test_changevelocitycommand)

add_executable(test_maneuveringcommand main.cpp test_maneuveringcommand.cpp ${PRJ_SRC_DIR}/vector2d.cpp ${PRJ_SRC_DIR}/angle.cpp ${PRJ_SRC_DIR}/maneuveringcommand.cpp )
target_link_libraries(test_maneuveringcommand PRIVATE ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} GTest::gmock Threads::Threads )
gtest_discover_tests(test_maneuveringcommand)

add_executable(test_iocregistercommand main.cpp
                        test_iocregistercommand.cpp
                        ${PRJ_SRC_DIR}/scope.cpp
                        ${PRJ_SRC_DIR}/resolvercollection.cpp
                        ${PRJ_SRC_DIR}/scopecontainer.cpp
                        ${PRJ_SRC_DIR}/scopechangeradapter.cpp
                        ${PRJ_SRC_DIR}/macrocommand.cpp
                        ${PRJ_SRC_DIR}/iocsetscoperelativecommand.cpp
                        ${PRJ_SRC_DIR}/iocsetscopeabsolutecommand.cpp
                        ${PRJ_SRC_DIR}/iocregistercommand.cpp
                        ${PRJ_SRC_DIR}/iocnewscopecommand.cpp
                        ${PRJ_SRC_DIR}/fallbackcommand.cpp
                        ${PRJ_SRC_DIR}/ioc.cpp
                    )
target_link_libraries(test_iocregistercommand PRIVATE ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} GTest::gmock Threads::Threads )
gtest_discover_tests(test_iocregistercommand)

add_executable(test_iocnewscopecommand main.cpp
                        test_iocnewscopecommand.cpp
                        ${PRJ_SRC_DIR}/scope.cpp
                        ${PRJ_SRC_DIR}/resolvercollection.cpp
                        ${PRJ_SRC_DIR}/scopecontainer.cpp
                        ${PRJ_SRC_DIR}/scopechangeradapter.cpp
                        ${PRJ_SRC_DIR}/macrocommand.cpp
                        ${PRJ_SRC_DIR}/iocsetscoperelativecommand.cpp
                        ${PRJ_SRC_DIR}/iocsetscopeabsolutecommand.cpp
                        ${PRJ_SRC_DIR}/iocregistercommand.cpp
                        ${PRJ_SRC_DIR}/iocnewscopecommand.cpp
                        ${PRJ_SRC_DIR}/fallbackcommand.cpp
                        ${PRJ_SRC_DIR}/ioc.cpp
                    )
target_link_libraries(test_iocnewscopecommand PRIVATE ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} GTest::gmock Threads::Threads )
gtest_discover_tests(test_iocnewscopecommand)

add_executable(test_iocsetscoperelativecommand main.cpp
                        test_iocsetscoperelativecommand.cpp
                        ${PRJ_SRC_DIR}/scope.cpp
                        ${PRJ_SRC_DIR}/resolvercollection.cpp
                        ${PRJ_SRC_DIR}/scopecontainer.cpp
                        ${PRJ_SRC_DIR}/scopechangeradapter.cpp
                        ${PRJ_SRC_DIR}/macrocommand.cpp
                        ${PRJ_SRC_DIR}/iocsetscoperelativecommand.cpp
                        ${PRJ_SRC_DIR}/iocsetscopeabsolutecommand.cpp
                        ${PRJ_SRC_DIR}/iocregistercommand.cpp
                        ${PRJ_SRC_DIR}/iocnewscopecommand.cpp
                        ${PRJ_SRC_DIR}/fallbackcommand.cpp
                        ${PRJ_SRC_DIR}/ioc.cpp
                    )
target_link_libraries(test_iocsetscoperelativecommand PRIVATE ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} GTest::gmock Threads::Threads )
gtest_discover_tests(test_iocsetscoperelativecommand)

add_executable(test_iocsetscopeabsolutecommand main.cpp
                        test_iocsetscopeabsolutecommand.cpp
                        ${PRJ_SRC_DIR}/scope.cpp
                        ${PRJ_SRC_DIR}/resolvercollection.cpp
                        ${PRJ_SRC_DIR}/scopecontainer.cpp
                        ${PRJ_SRC_DIR}/scopechangeradapter.cpp
                        ${PRJ_SRC_DIR}/macrocommand.cpp
                        ${PRJ_SRC_DIR}/iocsetscoperelativecommand.cpp
                        ${PRJ_SRC_DIR}/iocsetscopeabsolutecommand.cpp
                        ${PRJ_SRC_DIR}/iocregistercommand.cpp
                        ${PRJ_SRC_DIR}/iocnewscopecommand.cpp
                        ${PRJ_SRC_DIR}/fallbackcommand.cpp
                        ${PRJ_SRC_DIR}/ioc.cpp
                    )
target_link_libraries(test_iocsetscopeabsolutecommand PRIVATE ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} GTest::gmock Threads::Threads )
gtest_discover_tests(test_iocsetscopeabsolutecommand)

add_executable(test_ioc main.cpp 
                        test_ioc.cpp 
                        ${PRJ_SRC_DIR}/scope.cpp 
                        ${PRJ_SRC_DIR}/resolvercollection.cpp 
                        ${PRJ_SRC_DIR}/scopecontainer.cpp 
                        ${PRJ_SRC_DIR}/scopechangeradapter.cpp
                        ${PRJ_SRC_DIR}/iocsetscoperelativecommand.cpp
                        ${PRJ_SRC_DIR}/iocsetscopeabsolutecommand.cpp
                        ${PRJ_SRC_DIR}/iocregistercommand.cpp
                        ${PRJ_SRC_DIR}/iocnewscopecommand.cpp
                        ${PRJ_SRC_DIR}/fallbackcommand.cpp
                        ${PRJ_SRC_DIR}/ioc.cpp
                    )
target_link_libraries(test_ioc PRIVATE ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} GTest::gmock Threads::Threads )
gtest_discover_tests(test_ioc)
