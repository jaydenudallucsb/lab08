#include "SimpleList.h"
#include <exception>

template <class T>
SimpleList<T>::SimpleList() {
    numElements = 0;
    elements = new T[CAPACITY];
}

template <class T>
SimpleList<T>::~SimpleList() {
    delete[] elements;
}

template <class T>
T SimpleList<T>::at(int index) const {
    if (index < 0 || index >= numElements) {
        throw InvalidIndexException();
    }
    if (!elements[index]) {
        throw InvalidIndexException();
    }
    if (!elements) {
        throw InvalidIndexException();
    }
    return elements[index];
}

template <class T>
bool SimpleList<T>::empty() const {
    return (numElements == 0);
}

template <class T>
T SimpleList<T>::first() const {
    if (this->empty()) {
        throw EmptyListException();
    }
    return elements[0];
}

template <class T>
T SimpleList<T>::last() const {
    if (this->empty()) {
        throw EmptyListException();
    }
    return elements[numElements - 1];
}

template <class T>
int SimpleList<T>::getNumElements() const {
    return numElements;
}

template <class T>
void SimpleList<T>::insert(T item) {
    if (numElements == CAPACITY) {
        throw FullListException();
    }
    elements[numElements] = item;
    numElements++;
}

template <class T>
void SimpleList<T>::remove(int index) {
    if (this->empty()) {
        throw EmptyListException();
    }
    if (index < 0 || index >= CAPACITY) {
        throw InvalidIndexException();
    }
    for (int i = index; i < numElements-1; i++) {
        delete elements[index];
        elements[i] = elements[i+1];
    }
    numElements--;
}


//SimpleList.cpp to be completed by the student
//
