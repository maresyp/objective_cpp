//
// Created by Mateusz Pysera on 16/10/2021.
//
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class Person {
   private:
    std::string imie;
    std::string nazwisko;
    std::string adres;
    std::string pesel;

   public:
    static void load_from_file(std::string filename, std::vector<Person*>* destination) {
        // file format : pesel;imie;nazwisko;adres
        std::fstream file;
        file.open(filename, std::ios::in);
        if (!file) {
            throw "Couldn't open file";
        } else {
            std::string line;
            while (std::getline(file, line)) {
                std::string token;
                size_t pos = 0;
                while ((pos = line.find(';')) != std::string::npos) {
                    token = line.substr(0, pos);
                    std::cout << token << std::endl;
                    line.erase(0, pos + 1);
                }
            }
            file.close();
        }
    }
    void validate_pesel() {
        // 11 cyfr
    }
};
int main() {
    std::vector<Person*> Rekordy;
    Rekordy.push_back(new Person());

    Person::load_from_file("rekordy.txt", &Rekordy);
    return 0;
}