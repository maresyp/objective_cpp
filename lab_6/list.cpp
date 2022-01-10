//
// Created by Mateusz Pysera on 07/12/2021.
//
#include <iostream>

template<typename T>
class List {
private:
    size_t capacity = 1;
    size_t size = 0;
    T *data = new T[capacity];
public:
    List() = default;

    void sort();

    [[nodiscard]] T min() const;

    [[nodiscard]] T max() const;

    [[nodiscard]] size_t index() const;

    void push(T value);

    void display() const;

    virtual ~List();

};

template<typename T>
List<T>::~List() {
    delete[] data;
}

template<typename T>
void List<T>::push(T value) {
    if (size == capacity) {
        T *tmp_data = new T[capacity * 2];
        memcpy(tmp_data, data, size * sizeof(*data));
        capacity = capacity * 2;
        delete[] data;
        data = tmp_data;
    }
    data[size++] = value;
}

template<typename T>
void List<T>::sort() {
    // todo: impl sort
}

template<typename T>
T List<T>::min() const {
    T tmp_min = data[0];
    for (int i = 0; i < size; ++i) {
        if (data[i] < tmp_min) tmp_min = data[i];
    }
    return tmp_min;
}

template<typename T>
T List<T>::max() const {
    T tmp_max = data[0];
    for (int i = 0; i < size; ++i) {
        if (data[i] > tmp_max) tmp_max = data[i];
    }
    return tmp_max;
}

template<typename T>
size_t List<T>::index() const {
    // todo: impl index
}

template<typename T>
void List<T>::display() const {
    for (int i = 0; i < size; ++i) {
        std::cout << data[i] << " ";
    }
}

int main() {
    auto test = List<int>();
    test.push(6);
    test.push(2);
    test.push(3);
    test.push(4);
    test.push(5);
    std::cout << "min: " << test.min() << "\n";
    test.display();
    return 0;
}

