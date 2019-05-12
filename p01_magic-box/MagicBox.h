//
// Created by zvezdomirov98 on 12.05.19.
//

#ifndef P01_MAGIC_BOX_MAGICBOX_H
#define P01_MAGIC_BOX_MAGICBOX_H

template <class T>
class MagicBox {
public:
    MagicBox(int); // constructor with initial capacity

    MagicBox() : MagicBox(DEFAULT_CAPACITY) {}; // default constructor

    ~MagicBox(); // destructor

    void insert(const T&);

    void pop();

    void list(std::ostream&) const;

    int getSize() const;

    bool empty() const;

    bool full() const;

    int getCapacity() const;

private:

    static const int DEFAULT_CAPACITY = 2;
    T* arr;
    int size;
    int capacity;
    void doubleCapacity();

};


template <class T>
MagicBox<T>::MagicBox(int initialCapacity) {
    capacity = initialCapacity;
    arr = new T[capacity];
    size = 0;
}

template <class T>
MagicBox<T>::~MagicBox() {
    delete[] arr;
}

template <class T>
void MagicBox<T>::insert(const T& item) {
    if (full()) {
        doubleCapacity();
    }
    arr[size++] = item;
}

template <class T>
void MagicBox<T>::pop() {
    if (empty()) {
        std::cerr << "The box is empty!" << std::endl;
    } else {
        size--;
    }
}

template<class T>
void MagicBox<T>::list(std::ostream& os) const {
    for (int i = 0; i < size; i++) {
        os << arr[i] << std::endl;
    }
}

template<class T>
bool MagicBox<T>::empty() const {
    return size == 0;
}

template<class T>
bool MagicBox<T>::full() const {
    return size == capacity;
}

template<class T>
void MagicBox<T>::doubleCapacity() {
    int newCapacity = capacity * 2;
    T* doubledArr = new T[newCapacity];

    for (int i = 0; i < capacity; i++) {
        doubledArr[i] = arr[i];
    }
    delete[] arr;
    arr = doubledArr;
    capacity = newCapacity;
    std::cout << "Capacity is doubled" << std::endl;
}

template<class T>
int MagicBox<T>::getSize() const {
    return size;
}

template<class T>
int MagicBox<T>::getCapacity() const {
    return capacity;
}

#endif //P01_MAGIC_BOX_MAGICBOX_H
