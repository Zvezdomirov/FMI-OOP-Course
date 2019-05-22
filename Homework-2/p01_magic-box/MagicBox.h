//
// Created by zvezdomirov98 on 12.05.19.
//

#ifndef P01_MAGIC_BOX_MAGICBOX_H
#define P01_MAGIC_BOX_MAGICBOX_H

#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include "MyArray.h"

template<typename T>
class MagicBox {

public:
    MagicBox();

    MagicBox(const MagicBox& copy);

    ~MagicBox();

    void insert(const T& item);

    void pop();

    void list() const;

private:
    MyArray<T> *box;
};

template<typename T>
MagicBox<T>::MagicBox() {
    box = new MyArray<T>();
}

template<typename T>
MagicBox<T>::~MagicBox() {
    delete box;
}

template<typename T>
MagicBox<T>::MagicBox(const MagicBox &copy) {
    box = new MyArray<T>(copy.box);
}

template<typename T>
void MagicBox<T>::insert(const T &item) {
    box->push_back(item);
}

template<typename T>
void MagicBox<T>::pop() {
    //generate random integer in range [0, box->get_size() - 1]
    unsigned int random_int = rand() % box->get_size();
    box->pop_at_ind(rand() % (box->get_size()));
}

template<typename T>
void MagicBox<T>::list() const {
    for (int i = 0; i < box->get_size(); i++) {
        std::cout << (*box)[i] << std::endl;
    }
}

#endif //P01_MAGIC_BOX_MAGICBOX_H
