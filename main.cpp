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

void show_info() {
    std::cout << "create (type)  -  creating binary tree with given type\n";
}

std::string first_word(std::string str) {
    std::string word;
    int i = 0;
    while (str[i] != ' ' && i != str.length()) {
        word += str[i];
        i++;
    }
    return word;
}

void remove_first_word(std::string *str) {
    int i = 0;
    while ((*str)[i] != ' ' && i != (*str).length()) {
        i++;
    }
    if (i == (*str).length()) {
        (*str) = "";
    } else {
        (*str).erase(0, i + 1);
    }
}

bool valid_type(std::string type) {
    return type == "int" || type == "double" || type == "complex" || type == "person" || type == "function";
}

BinTree<int> *create_int_tree() {
    int item;
    std::string str;
    BinTree<int> *tree = new BinTree<int>();
    std::cout << "Start to fill the tree writing the int-values\nFor ending enter 'end'\n";

    std::cin >> str;
    while (str != "end") {
        item = std::stoi(str);
        tree->insert_node(item);
        std::cin >> str;
    }

    return tree;
}

BinTree<double> *create_double_tree() {
    double item;
    std::string str;
    BinTree<double> *tree = new BinTree<double>();
    std::cout << "Start to fill the tree writing the double-values\nFor ending enter 'end'\n";

    std::cin >> str;
    while (str != "end") {
        item = std::stod(str);
        tree->insert_node(item);
        std::cin >> str;
    }

    return tree;
}

BinTree<Complex> *create_complex_tree() {
    Complex item;
    std::string str;
    double tempRe;
    double tempIm;
    BinTree<Complex> *tree = new BinTree<Complex>();
    std::cout << "Start to fill the tree writing the complex-values\n(a,b) matches a + i * b\nFor ending enter 'end'\n";

    std::cin >> str;
    while (str != "end") {
        tempRe = std::stod(str.substr(1, str.find_first_of(",") - 1));
        tempIm = std::stod(str.substr(str.find_first_of(",") + 1, str.length() - str.find_first_of(",") - 1));
        tree->insert_node({tempRe, tempIm});
        std::cin >> str;
    }

    return tree;
}

int main() {
    std::string request;
    BinTree<int> *intTree;
    BinTree<double> *doubleTree;
    BinTree<Complex> *complexTree;
    BinTree<Person> *personTree;

    while (request != "exit") {
        std::getline(std::cin, request);

        if (first_word(request) == "create") {
            remove_first_word(&request);
            std::string type = first_word(request);
            if (valid_type(type)) {
                if (type == "int") {
                    intTree = create_int_tree();
                    std::cout << intTree->toString("NLR") << "\n\n";
                } else if (type == "double") {
                    doubleTree = create_double_tree();
                    std::cout << intTree->toString("NLR") << "\n\n";
                } else if (type == "complex") {
                    complexTree = create_complex_tree();
                    std::cout << complexTree->toString("NLR") << "\n\n";
                } else if (type == "person") {
                    personTree = new BinTree<Person>();
                } else {

                }
            } else {
                std::cout << "Incorrect 'type' value\n";
                continue;
            }
        }
    }

    return 0;
}


