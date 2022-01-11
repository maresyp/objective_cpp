//
// Created by Mateusz Pysera on 02/01/2022.
//

#include <string>
#include <iostream>

int convert(std::string str) {
    int sign = 1;
    int base = 0;
    int carrot = 0;

    while (isspace(str[carrot])) carrot++;
    if (str[carrot] == '-' || str[carrot] == '+') {
        sign = (str[carrot] == '-') ? -1 : 1;
        carrot++;
    }
    if (str[carrot] == '0') throw "bad argument";
    while (carrot < str.length()) {
        if (str[carrot] < '0' || str[carrot] > '9')
            throw "bad argument";
        if (base > INT_MAX / 10 || (base == INT_MAX / 10 && str[carrot] - '0' > 7))
            throw "int overflow";
        base = base * 10 + (str[carrot] - '0');
        carrot++;
    }
    return base * sign;
}

int main() {
    std::string txt;
    std::cout << "Wprowadz liczbe ";
    std::cin >> txt;
    std::cout << convert(txt);
    return 0;
}