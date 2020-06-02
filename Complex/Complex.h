//
// Created by fell2 on 29.05.2020.
//

#ifndef LAB3_TREES_COMPLEX_H
#define LAB3_TREES_COMPLEX_H


#include <iosfwd>

class Complex {
private:
    double re;
    double im;
public:
    Complex(double re, double im);

    Complex();

    friend bool operator==(const Complex &z1, const Complex &z2);

    friend bool operator!=(const Complex &z1, const Complex &z2);

    friend bool operator>(const Complex &z1, const Complex &z2);

    friend bool operator>=(const Complex &z1, const Complex &z2);

    friend bool operator<(const Complex &z1, const Complex &z2);

    friend bool operator<=(const Complex &z1, const Complex &z2);

    Complex operator+(Complex z) const;

    Complex operator-(Complex z) const;

    Complex operator*(Complex z) const;

    Complex operator/(Complex z) const;

    double abs() const;

    friend std::ostream& operator<<(std::ostream &out, Complex z);

    static std::string to_string(Complex z);

    void print() const;
};


#endif //LAB3_TREES_COMPLEX_H
