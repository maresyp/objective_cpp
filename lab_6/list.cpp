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

    [[nodiscard]] size_t index(T elem) const;

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
    for (int i = 0; i < size - 1; ++i)
        for (int j = 0; j < size - i - 1; ++j)
            if (data[i] > data[i + 1]) std::swap(data[i], data[i + 1]);
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
size_t List<T>::index(T elem) const {
    for (int i = 0; i < size; ++i)
        if (data[i] == elem) return i;

    std::cout << "brak ";
    return 0;
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
    std::cout << "max: " << test.max() << "\n";
    std::cout << "index: " << test.index(3) << "\n";
    std::cout << "index: " << test.index(69) << "\n";
    test.sort();
    test.display();
    return 0;
}

