//
// Created by fell2 on 22.05.2020.
//

#ifndef LAB3_TREES_SEQUENCE_H
#define LAB3_TREES_SEQUENCE_H

template<class T>
class Sequence {
public:
    virtual int getLength() const = 0;

    virtual T getFirst() const = 0;

    virtual T getLast() const = 0;

    virtual T get(const int i) const = 0;

    virtual Sequence<T> *getSubsequence(const int startIndex, const int endIndex) const = 0;

    virtual void append(T value) = 0;

    virtual void prepend(T value) = 0;

    virtual void set(int index, T value) = 0;

//    virtual void setNull(int index) = 0;

    virtual void insertAt(const int index, T value) = 0;

    virtual Sequence<T> *concat(Sequence<T> *list) = 0;

    virtual void print() = 0;
};

#endif //LAB3_TREES_SEQUENCE_H
