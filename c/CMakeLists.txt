cmake_minimum_required(VERSION 3.7)
project(c)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_TEST_FIFO  fifo_q.h test_fifo_q.c)
set(SOURCE_TEST_FIFO_100  fifo_q.h test_fifo_q_100.c)

add_executable(test_fifo ${SOURCE_TEST_FIFO})
add_executable(test_fifo_100 ${SOURCE_TEST_FIFO_100})