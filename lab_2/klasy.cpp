//
// Created by Mateusz Pysera on 16/10/2021.
//
#include <iostream>
#include <string>

#include "klasy.h"

class Person {
private:
    std::string imie;
    std::string nazwisko;
    std::string adres;
    int pesel;

};
int main() {
    Person persons[10];
    persons[0] = Person::Person("Adam", "Drzewiecki", "Lipowa 12", 123456789);
    return 0;
}