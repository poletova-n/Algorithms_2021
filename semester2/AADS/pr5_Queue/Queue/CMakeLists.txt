cmake_minimum_required(VERSION 3.17)
project(algorithms_2021)

set(CMAKE_CXX_STANDARD 20)

set(EXECUTABLE_OUTPUT_PATH Dir_where_executable_program_is_located)

add_executable(algorithms_2021 main.cpp Queue.cpp Queue.h CircleQueue.cpp CircleQueue.h QueueOverflow.h QueueUnderflow.h QueueWrongSize.h BinarySearchTree.h BinarySearchTree.cpp)