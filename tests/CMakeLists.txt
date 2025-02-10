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
