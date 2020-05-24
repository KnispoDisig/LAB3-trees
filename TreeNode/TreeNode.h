//
// Created by fell2 on 21.05.2020.
//

#ifndef LAB3_TREES_TREENODE_H
#define LAB3_TREES_TREENODE_H

template<class T>
class TreeNode {
public:
    T data;
    TreeNode *left;
    TreeNode *right;

    void print();

    TreeNode(T val);

    int bfactor();

    T get_data();
};

#endif //LAB3_TREES_TREENODE_H
