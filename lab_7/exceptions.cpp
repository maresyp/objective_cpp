//
// Created by Mateusz Pysera on 02/01/2022.
//
#include <iostream>

int main() {
    std::cout << "Jaki typ pierwiastkow chcesz obliczyc ?\n";
    std::cout << "Wpisz 1 ( Rzeczywiste ) lub 2 ( Zespolone )\n";
    int typ;
    std::cin >> typ;

    if (typ < 1 || typ > 2) throw "Nieprawidlowy typ";
    int a, b, c;
    std::cout << "Podaj:\na: ";
    std::cin >> a;
    std::cout << "\nb: ";
    std::cin >> b;
    std::cout << "\nc: ";
    std::cin >> c;
    std::cout << "\n";
    if (typ == 1) {
        // rzeczywiste
    } else {
        // zespolone
    }
    return 0;
}