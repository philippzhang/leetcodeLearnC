cmake_minimum_required(VERSION 3.14)
project(leetcodeLearnC)

set(CMAKE_C_STANDARD 90)

set(CMAKE_BUILD_TYPE Debug)

add_executable(main1 test1.c)
add_executable(main2 test2.c)

add_subdirectory(c1)
add_subdirectory(lc0001)
add_subdirectory(base)
