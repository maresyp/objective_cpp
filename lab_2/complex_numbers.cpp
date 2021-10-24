#include <cmath>
#include <iostream>
class Complex {
   private:
    double real;
    double imaginary;

   public:
    Complex(double real = 1., double img = 1.) {
        this->real = real;
        this->imaginary = img;
    }
    void display() {
        std::cout << this->real;
        if (this->imaginary < 0) {
            std::cout << this->imaginary << "i";
        } else {
            std::cout << "+" << this->imaginary << "i";
        }
        std::cout << std::endl;
    }
    Complex* add(const Complex& complex) {
        return new Complex(this->real + complex.real, this->imaginary + complex.imaginary);
    }
    Complex* sub(const Complex& complex) {
        return new Complex(this->real - complex.real, this->imaginary - complex.imaginary);
    }
    Complex* mul(const Complex& complex) {
        return new Complex(
            ((this->real * complex.real) - (this->imaginary * complex.imaginary)),
            ((this->real * complex.imaginary) + (this->imaginary * complex.real)));
    }
    Complex* div(const Complex& complex) {
        double denominator = std::pow(complex.real, 2) + std::pow(complex.imaginary, 2);
        if (denominator == 0) {
            throw "Zero Division";
        } else {
            return new Complex(
                ((this->real * complex.real) + (this->imaginary * complex.imaginary)) / denominator,
                ((this->imaginary * complex.real) - (this->real * complex.imaginary)) / denominator);
        }
    }
};

int main() {
    Complex complex = Complex(12, -3);
    Complex* res = complex.div(Complex(6, 8));
    res->display();
    Complex test = Complex(0.5, 0.3);
    test.display();
    return 0;
}