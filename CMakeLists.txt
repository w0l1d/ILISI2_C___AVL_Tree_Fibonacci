cmake_minimum_required(VERSION 3.24)
project(ILISI2_C___BinaryTree2)

set(CMAKE_CXX_STANDARD 17)

set(PROJECT_HEADERS
        )
set(PROJECT_SOURCES_Tree
        BinaryTree2/main.cpp BinaryTree2/Pair.h BinaryTree2/BTree.h BinaryTree2/BigInt.h
        )
set(PROJECT_SOURCES_hashtable
        hashtable/HashTable.h hashtable/main.cpp
        )

#add_executable(ILISI2_C___BinaryTree2 ${PROJECT_SOURCES} ${PROJECT_HEADERS})



add_executable(ILISI2_C___BinaryTree2  ${PROJECT_SOURCES_hashtable})
