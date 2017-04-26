cmake_minimum_required(VERSION 3.7)
project(cpp)

set(CMAKE_CXX_STANDARD 11)

set(DEMOBAR_SOURCE main.cpp WaitingBar.cpp WaitingBar.hpp ProgressBar.hpp ProgressBar.cpp)
set(TEST_FILE_OPERATION_SOURCE TestFileOperation.cpp FileOperation.hpp FileOperation.cpp)

add_executable(DemoBar ${DEMOBAR_SOURCE})
add_executable(TestFileOperation ${TEST_FILE_OPERATION_SOURCE})