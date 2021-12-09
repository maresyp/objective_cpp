//
// Created by Mateusz Pysera on 07/12/2021.
//
#include <iostream>

template<typename T>
class List {
private:
    T *data;
    size_t capacity;
    size_t size;
public:
    void sort();

    T min() const;

    T max() const;

    size_t index() const;

    void push(T value);


};

template<typename T>
void List<T>::sort() {
    // todo: impl sort
}

template<typename T>
T List<T>::min() const {
    // todo: impl min
}

template<typename T>
T List<T>::max() const {
    // todo: impl max
}

template<typename T>
size_t List<T>::index() const {
    // todo: impl index
}

