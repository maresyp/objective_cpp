
#include <iostream>

template <typename T>
class Sequence {
   public:
    Sequence<T>();
    T get_nth(T n);
    bool in_sequence(T elem);
};
template <typename T>
Sequence<T>::Sequence() {}

template <typename T>
T Sequence<T>::get_nth(T n) {
    if (n <= 1) return n;
    return get_nth(n - 1) + get_nth(n - 2);
}

template <typename T>
bool Sequence<T>::in_sequence(T elem) {
    // TODO: impl this
    return false;
}

int main() {
    auto seq = Sequence<int>();
    return 0;
}
