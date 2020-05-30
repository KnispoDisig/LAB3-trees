//
// Created by fell2 on 29.05.2020.
//

#include "Complex.h"
#include "cmath"
#include <string>
#include "ostream"

Complex::Complex(double Re, double Im) {
    this->re = Re;
    this->im = Im;
}


bool operator==(const Complex &z1, const Complex &z2) {
    return (z1.im == z2.im && z1.re == z2.re);
}

bool operator!=(const Complex &z1, const Complex &z2) {
    return !(z1 == z2);
}

double Complex::abs() const {
    return sqrt(re * re + im * im);
}

bool operator>(const Complex &z1, const Complex &z2) {
    return (z1.abs() > z2.abs());
}

bool operator>=(const Complex &z1, const Complex &z2) {
    return (z1.abs() >= z2.abs());
}

bool operator<(const Complex &z1, const Complex &z2) {
    return (z1.abs() < z2.abs());
}

bool operator<=(const Complex &z1, const Complex &z2) {
    return (z1.abs() <= z2.abs());
}

Complex Complex::operator+(Complex z) const {
    return {re + z.re, im + z.im};
}

Complex Complex::operator-(Complex z) const {
    return {re - z.re, im - z.im};
}

Complex Complex::operator*(Complex z) const {
    return {this->re * z.re - im * z.im, im * z.re + re * z.im};
}

Complex Complex::operator/(Complex z) const {
    return {(re * z.re + im * z.im) / (z.re * z.re + z.im * z.im),
                   (im * z.re - re * z.im) / (z.re * z.re + z.im * z.im)};
}

std::ostream &operator<<(std::ostream &out, Complex z) {
    out << z.re << " + i * " << z.im;
    return out;
}
