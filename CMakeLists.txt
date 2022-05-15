cmake_minimum_required(VERSION 3.20)
project(one_way_list)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab0 lab0/main.cpp)
add_executable(lab1 lab1/main.cpp lab1/DoubleLinkedList.cpp)
add_executable(lab2 lab2/main.cpp lab2/SinglyOrderedList.cpp)
add_executable(lab3 lab3/main.cpp lab3/Stack.cpp)
add_executable(lab4 lab4/main.cpp lab4/BinarySearchTree.cpp)
add_executable(lab5 lab5/main.cpp lab5/BinarySearchTree.cpp lab5/BinarySearchTree.h lab5/CircleQueue.cpp lab5/CircleQueue.h lab5/Queue.h lab5/WrongSizeQueue.h)
add_executable(ind6 ind6/main.cpp)