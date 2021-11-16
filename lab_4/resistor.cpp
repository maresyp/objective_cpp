
#include <iostream>

class Resistor {
private:
    double resistance;

public:
    Resistor() : resistance(0) {
    }

    explicit Resistor(double resistance) : resistance(resistance) {
    }

    double r() const {
        return this->resistance;
    }

    void r(double res) {
        this->resistance = res;
    }

    friend Resistor operator+(const Resistor &res1, const Resistor &res2);

    friend Resistor operator*(const Resistor &res1, const Resistor &res2);

    friend std::ostream &operator<<(std::ostream &output, const Resistor &Res);
};

Resistor operator+(const Resistor &res1, const Resistor &res2) {
    return Resistor(res1.resistance + res2.resistance);
}

Resistor operator*(const Resistor &res1, const Resistor &res2) {
    return Resistor((res1.resistance * res2.resistance) / (res1.resistance + res2.resistance));
}

std::ostream &operator<<(std::ostream &output, const Resistor &Res) {
    output << "R: " << Res.resistance;
    return output;
}