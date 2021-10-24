#include <iostream>

class Something {
   private:
    int a;
    double b;
    float c;

   public:
    Something(int a) {
        this->a = a;
        std::cout << "Wywolano konstuktor przeciazony z parametrami: int" << std::endl;
        std::cout << "Pierwszy parametr typu int ma wartosc: " << get_a() << std::endl;
    }
    Something(int a, double b) {
        this->a = a;
        this->b = b;
        std::cout << "Wywolano konstuktor przeciazony z parametrami: int, double" << std::endl;
        std::cout << "Pierwszy parametr typu int ma wartosc: " << get_a() << std::endl;
        std::cout << "Drugi parametr typu double ma wartosc: " << get_b() << std::endl;
    }
    Something(int a, double b, float c) {
        this->a = a;
        this->b = b;
        this->c = c;
        std::cout << "Wywolano konstuktor przeciazony z parametrami: int, double, float" << std::endl;
        std::cout << "Pierwszy parametr typu int ma wartosc: " << get_a() << std::endl;
        std::cout << "Drugi parametr typu double ma wartosc: " << get_b() << std::endl;
        std::cout << "Trzeci parametr typu float ma wartosc: " << get_b() << std::endl;
    }
    int get_a() {
        return this->a;
    }
    int get_b() {
        return this->b;
    }
    int get_c() {
        return this->c;
    }
};

int main() {
    Something a = Something(5);
    Something b = Something(5, 1.);
    Something c = Something(5, 1., 2.);
    return 0;
}