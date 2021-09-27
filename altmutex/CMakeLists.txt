cmake_minimum_required(VERSION 3.0.0)
project(altmutex_tests VERSION 0.1.0)

add_executable(${PROJECT_NAME} tests/tests.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC .)
