#include <iostream>
#include "BinTree/BinTree.h"
#include "Sequence/ListSequence/LinkedListSequence.cpp"
#include "Complex/Complex.h"
#include "Person/Person.h"
#include "locale"
#include <ctime>

int plus1(int n) {
    return n + 1;
}

double plus1(double d) {
    return d + 1;
}

Complex plus_1_1(Complex c) {
    return {c.getRe() + 1, c.getIm() + 1};
}

Person name_to_up(Person person) {
    std::locale loc;
    string name;
    string surname;
    for (int i = 0; i < person.get_name().length(); i++) {
        name += std::toupper(person.get_name()[i], loc);
    }
    for (int i = 0; i < person.get_surname().length(); i++) {
        surname += std::toupper(person.get_surname()[i], loc);
    }

    return {name, surname};
}

bool more0(int n) {
    return n > 0;
}

int mult(int n, int m) {
    return n * m;
}

void show_info() {
    std::cout << "create (type)  -  creating binary tree with given type\n";
    std::cout << "add  -  adding one element to the tree\n";
    std::cout << "print (format)  -  printing the tree with given format ('N' - node, 'L' - left, 'R' - right)\n";
    std::cout << "delete  -  deleting the value\n";
    std::cout << "reduce (format)  -  reduce function for tree with given format\n";
    std::cout << "map  -  mapping entering tree\n";
    std::cout << "extract (value)  -  extracting tree with given node\n";
    std::cout << "check  -  checking if the tree contains given one\n";
    std::cout << "test  -  testing time\n";
    std::cout << "exit  -  ending the program\n\n";
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

Complex enter_complex() {
    string str;
    getline(cin, str);
    double tempRe = std::stod(str.substr(1, str.find_first_of(",") - 1));
    double tempIm = std::stod(str.substr(str.find_first_of(",") + 1, str.length() - str.find_first_of(",") - 1));

    return {tempRe, tempIm};
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

bool valid_format(string format) {
    return format.find('N') != string::npos && format.find('R') != string::npos &&
           format.find('L') != string::npos && format.length() == 3;
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

BinTree<Person> *create_person_tree() {
    Person person;
    string str;
    string f_name;
    string l_name;
    BinTree<Person> *tree = new BinTree<Person>();
    std::cout << "Start to fill the tree writing the person-values\n"
                 "Please, enter first name and last name through the space\nFor ending enter 'end'\n";

    std::getline(cin, str);
    while (str != "end") {
        f_name = first_word(str);
        remove_first_word(&str);
        l_name = first_word(str);
        tree->insert_node({f_name, l_name});
        std::getline(cin, str);
    }

    return tree;
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    std::cout << R"(
  _               ____      _  _  ____    ____  _    _______
 | |        /\   |  _ \   _| || ||___ \  |  _ \(_)  |__   __|
 | |       /  \  | |_) | |_  __  _|__) | | |_) |_ _ __ | |_ __ ___  ___
 | |      / /\ \ |  _ <   _| || |_|__ <  |  _ <| | '_ \| | '__/ _ \/ _ \
 | |____ / ____ \| |_) | |_  __  _|__) | | |_) | | | | | | | |  __/  __/
 |______/_/    \_\____/    |_||_||____/  |____/|_|_| |_|_|_|  \___|\___|

                                                                        )";
    std::cout << "\n";
    std::string request;
    BinTree<int> *intTree = nullptr;
    BinTree<double> *doubleTree = nullptr;
    BinTree<Complex> *complexTree = nullptr;
    BinTree<Person> *personTree = nullptr;

    while (request != "exit") {
        std::getline(std::cin, request);

        if (first_word(request) == "create") {
            remove_first_word(&request);
            std::string type = first_word(request);
            if (valid_type(type)) {
                if (type == "int") {
                    intTree = create_int_tree();
                    personTree = nullptr;
                    doubleTree = nullptr;
                    complexTree = nullptr;
                    std::cout << intTree->toString("NLR") << "\n\n";
                } else if (type == "double") {
                    doubleTree = create_double_tree();
                    personTree = nullptr;
                    intTree = nullptr;
                    complexTree = nullptr;
                    std::cout << doubleTree->toString("NLR") << "\n\n";
                } else if (type == "complex") {
                    complexTree = create_complex_tree();
                    personTree = nullptr;
                    doubleTree = nullptr;
                    intTree = nullptr;
                    std::cout << complexTree->toString("NLR") << "\n\n";
                } else if (type == "person") {
                    personTree = create_person_tree();
                    intTree = nullptr;
                    doubleTree = nullptr;
                    complexTree = nullptr;
                    std::cout << personTree->toString("NLR") << "\n\n";
                } else {

                }
            } else {
                std::cout << "Incorrect 'type' value\n";
                continue;
            }
        } else if (first_word(request) == "help") {
            show_info();
        } else if (first_word(request) == "add") {
            if (intTree != nullptr) {
                std::cout << "Enter an integer\n";
                int n;
                std::cin >> n;
                intTree->insert_node(n);
            } else if (doubleTree != nullptr) {
                std::cout << "Enter a real number\n";
                double d;
                std::cin >> d;
                doubleTree->insert_node(d);
            } else if (complexTree != nullptr) {
                std::cout << "Enter a complex number\n";
                string str;
                std::cin >> str;
                double tempRe = std::stod(str.substr(1, str.find_first_of(",") - 1));
                double tempIm = std::stod(
                        str.substr(str.find_first_of(",") + 1, str.length() - str.find_first_of(",") - 1));
                complexTree->insert_node({tempRe, tempIm});
            } else if (personTree != nullptr) {
                std::cout << "Enter a person\n";
                string str;
                string f_name;
                string l_name;
                getline(cin, str);
                f_name = first_word(str);
                remove_first_word(&str);
                l_name = first_word(str);
                personTree->insert_node({f_name, l_name});
            } else {
                std::cout << "Tree doesn't exist\n\n";
                continue;
            }
        } else if (first_word(request) == "print") {
            string format;
            remove_first_word(&request);
            format = first_word(request);

            if (!valid_format(format)) {
                std::cout << "Format is incorrect\n\n";
                continue;
            }

            if (intTree != nullptr) {
                std::cout << intTree->toString(format) << "\n\n";
            } else if (doubleTree != nullptr) {
                std::cout << doubleTree->toString(format) << "\n\n";
            } else if (complexTree != nullptr) {
                std::cout << complexTree->toString(format) << "\n\n";
            } else if (personTree != nullptr) {
                std::cout << personTree->toString(format) << "\n\n";
            } else {
                std::cout << "Tree doesn't exist\n\n";
                continue;
            }
        } else if (first_word(request) == "delete") {
            if (intTree != nullptr) {
                int n;
                std::cout << "Enter an integer\n";
                std::cin >> n;
                if (intTree->contains(n)) {
                    intTree->delete_node(n);
                }
            } else if (doubleTree != nullptr) {
                double d;
                std::cout << "Enter a real number\n";
                std::cin >> d;
                if (doubleTree->contains(d)) {
                    doubleTree->delete_node(d);
                }
            } else if (complexTree != nullptr) {
                std::cout << "Enter a complex number\n";
                string str;
                std::cin >> str;
                double tempRe = std::stod(str.substr(1, str.find_first_of(",") - 1));
                double tempIm = std::stod(
                        str.substr(str.find_first_of(",") + 1, str.length() - str.find_first_of(",") - 1));

                if (complexTree->contains({tempRe, tempIm})) {
                    complexTree->delete_node({tempRe, tempIm});
                }
            } else if (personTree != nullptr) {
                std::cout << "Enter a person\n";
                string str;
                string f_name;
                string l_name;
                getline(cin, str);
                f_name = first_word(str);
                remove_first_word(&str);
                l_name = first_word(str);
                if (personTree->contains({f_name, l_name})) {
                    personTree->delete_node({f_name, l_name});
                }
            } else {
                std::cout << "Tree doesn't exist\n\n";
                continue;
            }
        } else if (first_word(request) == "reduce") {
            remove_first_word(&request);
            string order = first_word(request);
            if (valid_format(order)) {
                if (intTree != nullptr) {
                    std::cout << intTree->reduce(mult, 1, order);
                } else if (doubleTree != nullptr) {

                } else if (complexTree != nullptr) {

                } else if (personTree != nullptr) {

                } else {
                    std::cout << "Tree doesn't exist\n\n";
                    continue;
                }
            } else {
                std::cout << "Incorrect 'type' value\n";
                continue;
            }
        } else if (first_word(request) == "map") {
            if (intTree != nullptr) {
                intTree->map(plus1);
            } else if (doubleTree != nullptr) {
                doubleTree->map(plus1);
            } else if (complexTree != nullptr) {
                complexTree->map(plus_1_1);
            } else if (personTree != nullptr) {
                personTree->map(name_to_up);
            } else {
                std::cout << "Tree doesn't exist\n\n";
                continue;
            }
        } else if (first_word(request) == "extract") {
            remove_first_word(&request);

            if (intTree != nullptr) {
                int val = stoi(first_word(request));
                BinTree<int> *extracted_tree = intTree->extract_subtree(val);
                if (extracted_tree != nullptr) {
                    std::cout << extracted_tree->toString("NLR");
                } else {
                    std::cout << "Such tree wasn't founded\n\n";
                }
            } else if (doubleTree != nullptr) {
                double val = stod(first_word(request));
                BinTree<double> *extracted_tree = doubleTree->extract_subtree(val);
                if (extracted_tree != nullptr) {
                    std::cout << extracted_tree->toString("NLR");
                } else {
                    std::cout << "Such tree wasn't founded\n\n";
                }
            } else if (complexTree != nullptr) {
                string str = first_word(request);
                double tempRe = std::stod(str.substr(1, str.find_first_of(",") - 1));
                double tempIm = std::stod(
                        str.substr(str.find_first_of(",") + 1, str.length() - str.find_first_of(",") - 1));
                BinTree<Complex> *extracted_tree = complexTree->extract_subtree({tempRe, tempIm});
                if (extracted_tree != nullptr) {
                    std::cout << extracted_tree->toString("NLR");
                } else {
                    std::cout << "Such tree wasn't founded\n\n";
                }
            } else if (personTree != nullptr) {
                string f_name = first_word(request);
                remove_first_word(&request);
                string l_name = first_word(request);
                BinTree<Person> *extracted_tree = personTree->extract_subtree({f_name, l_name});
                if (extracted_tree != nullptr) {
                    std::cout << extracted_tree->toString("NLR");
                } else {
                    std::cout << "Such tree wasn't found\n\n";
                }
            } else {
                std::cout << "Tree doesn't exist\n\n";
                continue;
            }

            std::cout << "\n\n";
        } else if (first_word(request) == "check") {
            std::cout << "Enter the tree\n";
            if (intTree != nullptr) {
                BinTree<int> *tree = create_int_tree();
                if (intTree->contains_subtree(tree)) {
                    std::cout << "Main tree contains given tree\n";
                } else {
                    std::cout << "Main tree doesn't contain given tree\n";
                }
            } else if (doubleTree != nullptr) {
                BinTree<double> *tree = create_double_tree();
                if (doubleTree->contains_subtree(tree)) {
                    std::cout << "Main tree contains given tree\n";
                } else {
                    std::cout << "Main tree doesn't contain given tree\n";
                }
            } else if (complexTree != nullptr) {
                BinTree<Complex> *tree = create_complex_tree();
                if (complexTree->contains_subtree(tree)) {
                    std::cout << "Main tree contains given tree\n";
                } else {
                    std::cout << "Main tree doesn't contain given tree\n";
                }
            } else if (personTree != nullptr) {
                BinTree<Person> *tree = create_person_tree();
                if (personTree->contains_subtree(tree)) {
                    std::cout << "Main tree contains given tree\n";
                } else {
                    std::cout << "Main tree doesn't contain given tree\n";
                }
            }
        } else if (first_word(request) == "test") {
            int count = 10;

                for (int i = 0; i < 9; i++) {
                    BinTree<int> *tree = new BinTree<int>();
                    double time = 0;
                    tree->insert_node(500);
                    std::cout << "Count = " << count << "\n";
                    for (int j = 1; j < count; j++) {
                        tree->insert_node(rand() % 1000 + 1);
                    }
                    std::cout << "TESTING DEEP SEARCH:\n";
                    for (int j = 0; j < 100; j++) {
                        unsigned int start_time =  clock();
                        Sequence<TreeNode<int> *> *sequence = tree->thread("NLR");
                        unsigned int end_time = clock();
                        unsigned int search_time = end_time - start_time;
                        time += search_time;
                    }
                    std::cout << "average time = " << time / 100 << "\n";
                    time = 0;
                    std::cout << "TESTING WIDE WALK\n";
                    for (int j = 0; j < 100; j++) {
                        unsigned int start_time =  clock();
                        Sequence<TreeNode<int> *> *sequence = tree->wide_walk();
                        unsigned int end_time = clock();
                        unsigned int search_time = end_time - start_time;
                        time += search_time;
                    }
                    std::cout << "average time = " << time / 100 << "\n\n";;
                    count *= 10;
                }

        } else {
            std::cout << "Tree doesn't exist\n\n";
            continue;
        }
        std::cout << '\n';
    }
    return 0;
}



