//
// Created by fell2 on 30.05.2020.
//

#include "string"
#include "ostream"


#ifndef LAB3_TREES_STUDENT_H
#define LAB3_TREES_STUDENT_H

#endif //LAB3_TREES_STUDENT_H
using namespace std;

class Person {
private:
    std::string first_name;
    std::string last_name;
public:
    Person(std::string first_name, std::string last_name) {
        this->first_name = first_name;
        this->last_name = last_name;
    }

    Person() {
        first_name = "Mark";
        last_name = "Karavashkin";
    }

    std::string get_surname() {
        return last_name;
    }

    string get_name() {
        return first_name;
    }

    friend bool operator==(const Person &s1, const Person &s2) {
        return s1.last_name == s2.last_name && s1.first_name == s2.first_name;
    }

    friend bool operator!=(const Person &s1, const Person &s2) {
        return !(s1 == s2);
    }

    friend bool operator>(const Person &s1, const Person &s2) {
        return s1.last_name > s2.last_name;
    }

    friend bool operator>=(const Person &s1, const Person &s2) {
        return s1.last_name >= s2.last_name;
    }

    friend bool operator<(const Person &s1, const Person &s2) {
        return s1.last_name < s2.last_name;
    }

    friend bool operator<=(const Person &s1, const Person &s2) {
        return s1.last_name <= s2.last_name;
    }

    friend std::ostream& operator<<(std::ostream &out, Person student) {
        out << student.last_name + " " + student.first_name;
        return out;
    }

    friend std::string to_string(Person const& person) {
        return person.first_name + " " + person.last_name;
    }
};