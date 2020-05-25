#include <iostream>
#include "BinTree/BinTree.h"
#include "Sequence/ListSequence/LinkedListSequence.cpp"

int plus1(int n) {
    return n + 1;
}

bool more0(int n) {
    return n > 0;
}

int mult(int n, int m) {
    return n * m;
}

int main() {
    BinTree<int> *tree = new BinTree<int>();
    tree->insert_node(2);
    tree->insert_node(1);
    tree->insert_node(0);
    tree->insert_node(3);
    tree->insert_node(5);
    tree->insert_node(8);
    tree->insert_node(7);
    BinTree<int> *tree1 = new BinTree<int>();
    tree1->insert_node(5);
    tree1->insert_node(7);
    tree1->insert_node(8);

    if (tree->contains_subtree(tree1)) {
        std::cout << tree->toString("NLR");
    }
    return 0;
}


