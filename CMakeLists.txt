cmake_minimum_required(VERSION 3.4)
project(Des_algori)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp data_tables.h bit_tables.h bit_tables.cpp permutations.h permutations.cpp data_messages_examples.h)
add_executable(Des_algori ${SOURCE_FILES})