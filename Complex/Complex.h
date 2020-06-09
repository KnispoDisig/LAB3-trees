//
// Created by fell2 on 29.05.2020.
//

#ifndef LAB3_TREES_COMPLEX_H
#define LAB3_TREES_COMPLEX_H


#include <iosfwd>
#include "string"
using namespace std;

namespace notstd {
    namespace adl_helper {
        using std::to_string;

        template<class T>
        std::string as_string( T&& t ) {
            return to_string( std::forward<T>(t) );
        }
    }
    template<class T>
    std::string to_string( T&& t ) {
        return adl_helper::as_string(std::forward<T>(t));
    }
}

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

    double getRe() const {
        return this->re;
    }

    double getIm() const {
        return this->im;
    }

    friend std::ostream& operator<<(std::ostream &out, Complex z);

    friend std::string to_string(Complex const& z);

    void print() const;
};


#endif //LAB3_TREES_COMPLEX_H
