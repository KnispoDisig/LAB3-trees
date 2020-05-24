//
// Created by fell2 on 22.05.2020.
//

#include <string>
#include "../TreeNode/TreeNode.cpp"
#include "../Sequence/ListSequence/LinkedListSequence.h"
#include <cmath>

#ifndef LAB3_TREES_BINTREE_H
#define LAB3_TREES_BINTREE_H

template<class T>
class BinTree {
private:
    TreeNode<T> *root;

//    void round(TreeNode<T> *node, T (*visit)(T *), std::string order) {
//        for (int i = 0; i < order.length(); i++) {
//            switch (order[i]) {
//                case 'N':
//
//        }
//    }

    static Sequence<TreeNode<T> *> *thread(TreeNode<T> *node, std::string order) {
        Sequence<TreeNode<T> *> *list = nullptr;
        TreeNode<T> **array;
        for (int i = 0; i < order.length(); i++) {
            switch (order[i]) {
                case 'N':
                    array = new TreeNode<T> *[1];
                    array[0] = node;
                    if (list == nullptr) {
                        list = new LinkedListSequence<TreeNode<T> *>(array, 1);
                    } else {
                        list = list->concat(new LinkedListSequence<TreeNode<T> *>(array, 1));
                    }

                    break;
                case 'R':
                    if (node->right != nullptr) {
                        if (list == nullptr) {
                            list = thread(node->right, order);
                        } else {
                            list = list->concat(thread(node->right, order));
                        }
                    }
                    break;
                case 'L':
                    if (node->left != nullptr) {
                        if (list == nullptr) {
                            list = thread(node->left, order);
                        } else {
                            list = list->concat(thread(node->left, order));
                        }
                    }
                    break;
            }
        }
        return list;
    }

    int bfactor(TreeNode<T> *node) {
        return height(node->right) - height(node->left);
    }

    void rotate_right(TreeNode<T> *node) {
        TreeNode<T> *q = node->left;
        node->left = q->right;
        q->right = node;
    }

    void rotate_left(TreeNode<T> *node) {
        TreeNode<T> *p = node->right;
        node->right = p->left;
        p->left = node;
    }

    TreeNode<T> *find_node(TreeNode<T> *node, T val) {
        if (node->data == val) {
            return node;
        } else if (val < node->data) {
            return find_node(node->left, val);
        } else {
            return find_node(node->right, val);
        }
    }

    void map(T (*func)(T), TreeNode<T> *node) {
        node->data = func(node->data);
        if (node->left == nullptr && node->right == nullptr) {
            return;
        }
        if (node->left != nullptr) {
            map(func, node->left);
        }
        if (node->right != nullptr) {
            map(func, node->right);
        }
    }

public:
    BinTree() {
        this->root = nullptr;
    }

    BinTree(TreeNode<T> *root) {
        this->root = root;
    }

    int height() {
        return height(this->root);
    }

    TreeNode<T> *find_node(T val) {
        return find_node(this->root, val);
    }

    static int height(TreeNode<T> *node) {
        int L;
        int R;
        if (node->left == nullptr && node->right == nullptr) {
            return 0;
        } else {
            if (node->left != nullptr) {
                L = height(node->left) + 1;
            } else {
                L = 0;
            }
            if (node->right != nullptr) {
                R = height(node->right) + 1;
            } else {
                R = 0;
            }
        }
        if (L > R) {
            return L;
        } else {
            return R;
        }
    }

    bool insert_node(T val) {
        TreeNode<T> *new_node = new TreeNode<T>(val);
        TreeNode<T> *ptr = this->root;
        TreeNode<T> *ptr1 = nullptr;

        while (ptr != nullptr) {
            ptr1 = ptr;
            if (val < ptr->get_data()) {
                ptr = ptr->left;
            } else {
                ptr = ptr->right;
            }
        }

        if (ptr1 == nullptr) {
            this->root = new_node;
        } else {
            if (val < ptr1->get_data()) {
                ptr1->left = new_node;
            } else {
                ptr1->right = new_node;
            }
        }
        return true;
    }

    bool delete_node(T val, TreeNode<T> *node) {
        if (node == nullptr) {
            return false;
        }
        bool where;
        TreeNode<T> *ptr1 = nullptr;
        TreeNode<T> *ptr = node;
        if (ptr->left == nullptr && ptr->right == nullptr) {
            if (ptr->data == val) {
                delete ptr;
                return true;
            } else {
                return false;
            }
        }

        while (ptr != nullptr && ptr->data != val) {
            if (val < ptr->data) {
                where = false;
                ptr1 = ptr;
                ptr = ptr->left;
            } else if (val > ptr->data) {
                where = true;
                ptr1 = ptr;
                ptr = ptr->right;
            }
        }
        if (ptr == nullptr) {
            return false;
        } else {
            if (ptr->right == nullptr && ptr->left == nullptr) {
                if (!where) {
                    ptr1->left = nullptr;
                } else {
                    ptr1->right = nullptr;
                }
                delete ptr;
                return true;
            } else if (ptr->right != nullptr && ptr->left == nullptr) {
                if (ptr1->left == ptr) {
                    ptr1->left = ptr->right;
                } else {
                    ptr1->right = ptr->right;
                }
                delete ptr;
                return true;
            } else if (ptr->left != nullptr && ptr->right == nullptr) {
                if (ptr1->left == ptr) {
                    ptr1->left = ptr->left;
                } else {
                    ptr1->right = ptr->left;
                }
                delete ptr;
                return true;
            } else if (ptr->left != nullptr && ptr->right != nullptr) {
                TreeNode<T> *ptr2 = nullptr;
                ptr1 = ptr;
                ptr2 = ptr;
                where = true;
                ptr = ptr->right;
                while (ptr->left != nullptr) {
                    ptr2 = ptr;
                    where = false;
                    ptr = ptr->left;
                }
                ptr1->data = ptr->data;

                if (ptr->right != nullptr) {
                    if (where) {
                        ptr2->right = ptr->right;
                    } else {
                        ptr2->left = ptr->right;
                    }
                    delete ptr;
                    return true;
                } else {
                    if (where) {
                        ptr2->right = nullptr;
                    } else {
                        ptr2->left = nullptr;
                    }
                    delete ptr;
                    return true;
                }
            }
        }
    }

    bool contains(T x) {
        TreeNode<T> *ptr = this->root;
        while (ptr != nullptr) {
            if (x < ptr->get_data()) {
                ptr = ptr->left;
            } else if (x > ptr->get_data()) {
                ptr = ptr->right;
            } else {
                return true;
            }
        }
        if (ptr == nullptr) {
            return false;
        }
    }

    TreeNode<T> *find_max(TreeNode<T> *node);

    TreeNode<T> *find_min(TreeNode<T> *node) {
        TreeNode<T> *ptr = node;
        while (ptr->left != nullptr) {
            ptr = ptr->left;
        }
        return ptr;
    }

    TreeNode<T> *get_root() {
        return this->root;
    }

    void map(T (*func)(T)) {
        this->map(func, this->root);
    }

    std::basic_string<char> where(bool (*func)(T), std::string order) {
        Sequence<TreeNode<T>*> *thread_tree = this->thread(order);
        std::string res;

        for (int i = 0; i < thread_tree->getLength(); i++) {
            if (func(thread_tree->get(i)->data)) {
                res += "1 ";
            } else {
                res += "0 ";
            }
        }

        return res;
    }

    T reduce(T (*func)(T, T), T start, std::string order) {
        Sequence<TreeNode<T>*> *thread_tree = this->thread(order);
        T res;
        for (int i = 0; i < thread_tree->getLength(); i++) {
            if (i == 0) {
                res = func(thread_tree->get(i)->data, start);
            } else {
                res = func(thread_tree->get(i)->data, res);
            }
        }

        return res;
    }

//    bool isBalanced(TreeNode<T> *node) {
//        TreeNode<T> *left_ptr = node->left;
//        TreeNode<T> *right_ptr = node->right;
//        if (right_ptr == nullptr && left_ptr == nullptr) {
//            return true;
//        }
//        if (abs(height(left_ptr) - height(right_ptr)) <= 1 && this->isBalanced(left_ptr) && this->isBalanced(right_ptr)) {
//            return true;
//        } else {
//            return false;
//        }
//    }

    std::string toString(std::string order) {
        std::string res;

        Sequence<TreeNode<T>*> *thread_tree = this->thread(order);
        for (int i = 0; i < thread_tree->getLength(); i++) {
            if (i == 0) {
                res += std::to_string(thread_tree->get(i)->data) + " ";
            } else {
                res += "-> " + std::to_string(thread_tree->get(i)->data) + " ";
            }
        }

        return res;
    }

    int nodes_count() {
        return this->thread("NLR")->getLength();
    }

    Sequence<TreeNode<T> *> *thread(std::string order) {
        return thread(this->root, order);
    }

    BinTree<T> *extract_subtree(T val) {
        TreeNode<T> *ptr = this->find_node(val);
        BinTree<T> *newTree = new BinTree<T>(ptr);

        return newTree;
    }

    bool contains_subtree(BinTree<T> *subtree);

    void balance(TreeNode<T> *node);
};

#endif //LAB3_TREES_BINTREE_H
