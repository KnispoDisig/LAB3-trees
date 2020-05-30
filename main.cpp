#include <iostream>
#include "BinTree/BinTree.h"
#include "Sequence/ListSequence/LinkedListSequence.cpp"
#include "Complex/Complex.h"
#include "Person/Person.h"

int plus1(int n) {
    return n + 1;
}

bool more0(int n) {
    return n > 0;
}

int mult(int n, int m) {
    return n * m;
}

int inc1(int n) {
    return n + 1;
}

int inc2(int n) {
    return n + 2;
}

int inc3(int n) {
    return n + 3;
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

    tree1->wide_walk()->print();


    return 0;
}


