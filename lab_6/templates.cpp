
#include <iostream>
#include <cmath>

template<typename T>
class Sequence {
public:
    Sequence<T>();

    T get_nth(T n);

    bool in_sequence(T elem) const;

    bool is_perfect_square(T number) const;

};

template<typename T>
Sequence<T>::Sequence() {}

template<typename T>
T Sequence<T>::get_nth(T n) {
    if (n <= 1) return n;
    return get_nth(n - 1) + get_nth(n - 2);
}

template<typename T>
bool Sequence<T>::in_sequence(T elem) const {
    return is_perfect_square(5 * elem * elem + 4) || is_perfect_square(5 * elem * elem - 4);
}

template<typename T>
bool Sequence<T>::is_perfect_square(T number) const {
    T sqr = sqrt(number);
    return (sqr * sqr == number);
}

int main() {

    auto seq = Sequence<int>();
    std::cout << seq.get_nth(3) << "\n";
    std::cout << seq.in_sequence(seq.get_nth(5)) << "\n";
    std::cout << seq.in_sequence(seq.get_nth(10)) << "\n";

    auto seq_float = Sequence<float>();
    std::cout << seq_float.get_nth(3) << "\n";
    std::cout << seq_float.in_sequence(seq_float.get_nth(5)) << "\n";
    std::cout << seq_float.in_sequence(seq_float.get_nth(10)) << "\n";

    return 0;
}
