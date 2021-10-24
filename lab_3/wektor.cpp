
#include <iostream>

class Point {
   private:
    double x;
    double y;

   public:
    double get_x() {
        return this->x;
    }
    double get_y() {
        return this->y;
    }
};
class Wektor {
   private:
    static unsigned int obj_count;

   public:
    Wektor(const Point& start, const Point& end) {
        obj_count++;
    }
    static unsigned int get_obj_count() {
        return obj_count;
    }
    Wektor* add(const Wektor& vec) {
        //
    }
    Wektor* sub(const Wektor& vec) {
        //
    }
    Wektor* mul(const Wektor& vec) {
        //
    }
    ~Wektor() {
        std::cout << "Zadanie wykonane" << std::endl;
    }
};

unsigned int Wektor::obj_count = 0;
int main() {
    std::cout << Wektor::get_obj_count() << std::endl;
    return 0;
}
