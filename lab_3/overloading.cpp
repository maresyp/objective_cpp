#include <iostream>

class Something {
   private:
    int a;
    double b;
    float c;

   public:
    Something() {
        std::cout << "Wywolano konstuktor domyslny" << std::endl;
        set_a(0);
        set_b(0);
        set_c(0);
    }
    Something(int a) {
        set_a(a);
        std::cout << "Wywolano konstuktor przeciazony z parametrami: int" << std::endl;
        std::cout << "Pierwszy parametr typu int ma wartosc: " << get_a() << std::endl;
    }
    Something(int a, double b) {
        set_a(a);
        set_b(b);
        std::cout << "Wywolano konstuktor przeciazony z parametrami: int, double" << std::endl;
        std::cout << "Pierwszy parametr typu int ma wartosc: " << get_a() << std::endl;
        std::cout << "Drugi parametr typu double ma wartosc: " << get_b() << std::endl;
    }
    Something(int a, double b, float c) {
        set_a(a);
        set_b(b);
        set_c(c);
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
    void set_a(int a) {
        this->a = a;
    }
    void set_b(double b) {
        this->b = b;
    }
    void set_c(double c) {
        this->c = c;
    }
};

int main() {
    Something a = Something(5);
    Something b = Something(5, 1.);
    Something c = Something(5, 1., 2.);
    return 0;
}