cmake_minimum_required(VERSION 3.24)
project(ILISI2_C___BinaryTree2)

set(CMAKE_CXX_STANDARD 17)

set(PROJECT_HEADERS
        )
set(PROJECT_SOURCES
        main.cpp
        )

#add_executable(ILISI2_C___BinaryTree2 ${PROJECT_SOURCES} ${PROJECT_HEADERS})



add_executable(ILISI2_C___BinaryTree2 main.cpp Pair.h BTree.h BigInt.h)
