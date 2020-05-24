//
// Created by fell2 on 21.05.2020.
//

#include <iostream>
#include "TreeNode.h"

template<class T>
TreeNode<T>::TreeNode(T val) {
    data = val;
    left = nullptr;
    right = nullptr;
}

template<class T>
T TreeNode<T>::get_data() {
    return data;
}

template<class T>
void TreeNode<T>::print() {
    std::cout << this->data << " ";
}

