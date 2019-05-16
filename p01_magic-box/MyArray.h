//
// Created by zvezdomirov98 on 16.05.19.
//

#ifndef ARRAYLIST_H
#define ARRAYLIST_H

template<typename T>
class MyArray {

public:

    explicit MyArray(unsigned int capacity = DEFAULT_CAPACITY);

    explicit MyArray(const T &defaultValue, unsigned int capacity);

    MyArray(const MyArray<T> &); // copy constructor

    ~MyArray();

    unsigned int get_size() const;

    unsigned int get_capacity() const;

    T &operator[](unsigned int ind) const;

    MyArray<T> &operator=(const MyArray<T> &);

    void push_back(const T &value);

    void pop_back();

    void pop_at_ind(unsigned int index);

    bool empty() const;

    bool full() const;

    void clear();

private:

    static const int DEFAULT_CAPACITY = 2;

    T *m_arr;

    unsigned int m_capacity;

    unsigned int m_size;

    void copy(const MyArray<T> &);

    void resize(unsigned int new_capacity);
};

template<typename T>
MyArray<T>::MyArray(unsigned int capacity) {
    m_capacity = capacity;
    m_size = 0;
    m_arr = new T[m_capacity];
}

template<typename T>
MyArray<T>::MyArray(const T &defaultValue, unsigned int capacity) {
    m_capacity = capacity;
    m_size = 0;
    m_arr = new T[m_capacity];

    for (int i = 0; i < m_capacity; i++) {
        m_arr[i] = defaultValue;
    }
}

template<typename T>
MyArray<T>::MyArray(const MyArray<T> &arr) {
    m_size = arr.m_size;
    m_capacity = arr.m_capacity;
    m_arr = new T[m_capacity];
    copy(arr);
}

template<typename T>
MyArray<T>::~MyArray() {
    delete[] m_arr;
}

template<typename T>
void MyArray<T>::copy(const MyArray<T> &arr) {
    for (size_t i = 0; i < m_size; i++) {
        m_arr[i] = arr.m_arr[i];
    }
}

template<typename T>
unsigned int MyArray<T>::get_size() const {
    return m_size;
}

template<typename T>
unsigned int MyArray<T>::get_capacity() const {
    return m_capacity;
}

template<typename T>
T &MyArray<T>::operator[](unsigned int ind) const {
    if (ind >= m_size) {
        throw std::out_of_range("MyArray<T>::operator[]: index is out of range!");
    } else {
        return m_arr[ind];
    }
}

template<typename T>
MyArray<T> &MyArray<T>::operator=(const MyArray<T> &rhs) {
    if (&rhs != this) {
        delete[] m_arr;
        m_size = rhs.m_size;
        m_capacity = rhs.m_capacity;
        m_arr = new T[m_capacity];
        copy(rhs.m_arr);
    }
    return *this;
}

template<typename T>
void MyArray<T>::push_back(const T &value) {
    if (full()) {
        m_capacity += m_capacity / 2 + 1;
        resize(m_capacity);
    }
    m_arr[m_size++] = value;
}

template<typename T>
void MyArray<T>::resize(unsigned int new_capacity) {
    if (new_capacity == 0) {
        clear();
    } else {
        if (new_capacity > m_size) {
            T *new_arr = new T[new_capacity];
            for (size_t i = 0; i < m_capacity; i++) {
                new_arr[i] = m_arr[i];
            }
            delete[] m_arr;
            m_arr = new_arr;
            m_capacity = new_capacity;
        } else {
            throw std::invalid_argument("MyArray has more elements than new_capacity!");
        }
    }
}

template<typename T>
void MyArray<T>::pop_back() {
    if (empty()) {
        throw std::invalid_argument("Trying to pop_back from empty MyArray.");
    } else {
        m_size--;
        if (m_size < m_capacity / 2) {
            resize(m_capacity / 2);
        }
    }
}

template<typename T>
bool MyArray<T>::empty() const {
    return m_size < 0;
}

template<typename T>
bool MyArray<T>::full() const {
    return m_size == m_capacity;
}

template<typename T>
void MyArray<T>::clear() {
    delete[] m_arr;
    m_capacity = DEFAULT_CAPACITY;
    m_arr = new T[m_capacity];
    m_size = 0;
}

template<typename T>
void MyArray<T>::pop_at_ind(unsigned int index) {
    if (index >= m_size) {
        throw std::out_of_range("Index is out of range!");
    }
    for (size_t i = index; i < m_size - 1; i++) {
        m_arr[i] = m_arr[i + 1];
    }
    m_size--;
}

#endif //ARRAYLIST_H
