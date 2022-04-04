cmake_minimum_required(VERSION 3.20)
project(one_way_list)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab0 lab0/main.cpp)
add_executable(lab1 lab1/main.cpp lab1/DoubleLinkedList.cpp lab1/DoubleLinkedList.h)
add_executable(lab2 lab2/main.cpp lab2/SinglyOrderedList.cpp lab2/SinglyOrderedList.h)
add_executable(lab3 lab3/main.cpp lab3/Stack.cpp lab3/Stack.h)
add_executable(lab4 lab4/main.cpp lab4/BinarySearchTree.cpp lab4/BinarySearchTree.h)