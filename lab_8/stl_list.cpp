//
// Created by Mateusz Pysera on 23/01/2022.
//

#include <iostream>
#include <list>

int main() {
    unsigned int amount_of_numbers;
    std::cout << "Podaj ile liczb chcesz wprowadzic: ";
    std::cin >> amount_of_numbers;
    if (amount_of_numbers < 1) {
        std::cout << "Bledna ilosc liczb";
        return 1;
    }

    std::list<int> numbers;
    int tmp_number;
    while (amount_of_numbers--) {
        std::cin >> tmp_number;
        std::cout << " ";
        (tmp_number >= 0) ? numbers.push_back(tmp_number) : numbers.push_front(tmp_number);
    }

    std::cout << "numbers = { ";
    for (int n: numbers) {
        std::cout << n << ", ";
    }
    std::cout << "};\n";

    return 0;
}