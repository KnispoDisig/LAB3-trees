cmake_minimum_required(VERSION 3.16)
project(LAB3_trees)

set(CMAKE_CXX_STANDARD 14)

add_executable(LAB3_trees main.cpp TreeNode/TreeNode.cpp TreeNode/TreeNode.h BinTree/BinTree.cpp BinTree/BinTree.h Sequence/Sequence.h Sequence/ArraySequence/DynamicArray/DynamicArray.cpp Sequence/ArraySequence/DynamicArray/DynamicArray.h Sequence/ArraySequence/ArraySequence.cpp Sequence/ArraySequence/ArraySequence.h Sequence/ListSequence/LinkedList/LinkedList.cpp Sequence/ListSequence/LinkedList/LinkedList.h Sequence/ListSequence/LinkedListSequence.cpp Sequence/ListSequence/LinkedListSequence.h)