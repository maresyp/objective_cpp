
#include <iostream>

class Wektor {
   public:
    static unsigned int obj_count;
    double start;
    double end;

   public:
    Wektor(double start, double end) {
        this->start = start;
        this->end = end;
        obj_count++;
    }
    static unsigned int get_obj_count() {
        return obj_count;
    }
    Wektor* add(const Wektor& vec) {
        return new Wektor((this->start + vec.start), (this->end + vec.end));
    }

    Wektor* sub(const Wektor& vec) {
        return new Wektor((this->start - vec.start), (this->end - vec.end));
    }
    double mul(const Wektor& vec) {
        return (this->start * vec.start) + (this->end * vec.end);
    }
    void display() {
        std::cout << "[" << this->start << "," << this->end << "] ";
    }
    ~Wektor() {
        std::cout << "Zadanie wykonane" << std::endl;
    }
};

unsigned int Wektor::obj_count = 0;
int main() {
    Wektor one = Wektor(3, -1);
    Wektor two = Wektor(2, 2);

    Wektor* result = one.add(two);
    result->display();

    result = one.sub(two);
    result->display();

    std::cout << one.mul(two) << " ";

    std::cout << Wektor::get_obj_count() << std::endl;

    delete result;
    return 0;
}
