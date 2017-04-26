cmake_minimum_required(VERSION 3.7)
project(c)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_TEST_FIFO  fifo_q.h test_fifo_q.c)
set(SOURCE_TEST_FIFO_100  fifo_q.h test_fifo_q_100.c)

set(SOURCE_TEST_FIFO_INLINE  fifo_q_inline.h test_fifo_q_inline.c)
#set(SOURCE_TEST_FIFO_INLINE_100  fifo_q_inline.h test_fifo_q_inline_100.c)


add_executable(test_fifo ${SOURCE_TEST_FIFO})
add_executable(test_fifo_100 ${SOURCE_TEST_FIFO_100})

add_executable(test_fifo_inline ${SOURCE_TEST_FIFO_INLINE})
#add_executable(test_fifo_100_inline ${SOURCE_TEST_FIFO_INLINE_100})