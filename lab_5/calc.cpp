//
// Created by Mateusz Pysera on 21/11/2021.
//

#include <iostream>

class Number {
public:
    long number;

    virtual long str_to_num(std::string &str) = 0;

    std::string to_dec() const {
        return "";
    }

    virtual std::string to_bin() {
        return "";
    };

    virtual std::string to_hex() {
        return "";
    }

    virtual ~Number() = 0;
};

class DecNumber : public Number {
public:

    explicit DecNumber(long num) {
        this->number = num;
    }

    friend DecNumber operator+(const DecNumber &num1, const DecNumber &num2) {
        return DecNumber(num1.number + num2.number);
    }

    friend DecNumber operator-(const DecNumber &num1, const DecNumber &num2) {
        return DecNumber(num1.number - num2.number);
    }

    friend DecNumber operator*(const DecNumber &num1, const DecNumber &num2) {
        return DecNumber(num1.number * num2.number);
    }

    friend DecNumber operator/(const DecNumber &num1, const DecNumber &num2) {
        return DecNumber(num1.number / num2.number);
    }

    friend std::ostream &operator<<(std::ostream &output, const DecNumber &num) {
        output << "";
        return output;
    }
};

class HexNumber : public Number {

};

class BinNumber : public Number {

};

int main() {

    auto dec = DecNumber(10);
    return 0;
}