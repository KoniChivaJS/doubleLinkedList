cmake_minimum_required(VERSION 3.27)
project(doubleLinkedList)

set(CMAKE_CXX_STANDARD 17)

add_executable(doubleLinkedList main.cpp
        DoubleNode.h
        DoubleLinkedList.cpp
        DoubleLinkedList.h)
