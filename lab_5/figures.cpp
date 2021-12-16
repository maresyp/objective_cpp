//
// Created by Mateusz Pysera on 07/12/2021.
//
#include <iostream>
#include <cmath>

class Bryla {
public:
    virtual double pole() {
        return 0;
    }

    virtual double objetosc() {
        return 0;
    }

    virtual double przekotna() {
        return 0;
    }

    virtual ~Bryla() = default;
};

class Kula : public Bryla {
private:
    double r;
public:
    explicit Kula(double r) : r(r) {}

    double pole() override {
        return 4 * 3.14 * pow(r, 2);
    }

    double objetosc() override {
        return (4.0 / 3.0) * 3.14 * pow(r, 3);
    }

};

class Prostopadloscian : public Bryla {
private:
    double a, b, c;
public:
    Prostopadloscian(double a, double b, double c) : a(a), b(b), c(c) {}

    double pole() override {
        return 2 * ((a * b) + (a * c) + (b * c));
    }

    double objetosc() override {
        return a * b * c;
    }

    double przekotna() override {
        return sqrt(pow(a, 2) + pow(b, 2) + pow(c, 2));
    }

};

class Ostroslup : public Bryla {
public:
    double a, h;

    Ostroslup(double a, double h) : a(a), h(h) {}

    double pole() override {
        return pow(a, 2) + (2 * a * h);
    }

    double objetosc() override {
        return (1.0 / 3.0) * pow(a, 2) * h;
    }

};

int main(int argc, char *argv[], char *envp[]) {

    auto kula = Kula(10);
    std::cout << "Kula objetosc: " << kula.objetosc() << "\n";
    std::cout << "Kula pole: " << kula.pole() << "\n";

    auto prostopadloscian = Prostopadloscian(5, 10, 15);
    std::cout << "Prostopadloscian pole: " << prostopadloscian.pole() << "\n";
    std::cout << "Prostopadloscian objetosc: " << prostopadloscian.objetosc() << "\n";
    std::cout << "Prostopadloscian przekotna: " << prostopadloscian.przekotna() << '\n';

    auto ostroslup = Ostroslup(5, 10);
    std::cout << "Ostroslup pole: " << ostroslup.pole() << '\n';
    std::cout << "Ostroslup objetosc: " << ostroslup.objetosc() << '\n';
    return 0;
}