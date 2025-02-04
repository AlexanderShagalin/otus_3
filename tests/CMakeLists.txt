cmake_minimum_required(VERSION 3.15)

project(tests LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_definitions(-DGTEST_LANGUAGE_CXX11)

set(PRJ_DIR ..)

set(PRJ_SRC_DIR ${PRJ_DIR}/source)
set(PRJ_INC_DIR ${PRJ_DIR}/include)

find_package(Threads REQUIRED)

find_package(GTest REQUIRED)
include_directories(${INCLUDE_DIRECTORIES}, /usr/include)
include_directories(${INCLUDE_DIRECTORIES}, ${PRJ_INC_DIR})

add_executable(test_vector2d main.cpp test_vector2d.cpp ${PRJ_SRC_DIR}/vector2d.cpp)
target_link_libraries(test_vector2d PRIVATE ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} Threads::Threads )

add_executable(test_rotate main.cpp test_rotate.cpp ${PRJ_SRC_DIR}/vector2d.cpp ${PRJ_SRC_DIR}/rotate.cpp )
target_link_libraries(test_rotate PRIVATE ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} GTest::gmock Threads::Threads )

add_executable(test_move main.cpp test_move.cpp ${PRJ_SRC_DIR}/vector2d.cpp ${PRJ_SRC_DIR}/moveforward.cpp )
target_link_libraries(test_move PRIVATE ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} GTest::gmock Threads::Threads )
