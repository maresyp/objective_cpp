
#include <iostream>

class Resistor {
   private:
    double resistance;

   public:
    Resistor() {
        this->resistance = 0;
    }
    Resistor(double resistance) {
        this->resistance = resistance;
    }
    double r() {
        return this->resistance;
    }
    void r(double resistance) {
        this->resistance = resistance;
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
std::ostream &
operator<<(std::ostream &output, const Resistor &Res) {
    output << "R: " << Res.resistance;
    return output;
}