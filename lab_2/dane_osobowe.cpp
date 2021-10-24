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
    Person(std::string pesel, std::string imie, std::string nazwisko, std::string adres) {
        this->pesel = pesel;
        this->imie = imie;
        this->nazwisko = nazwisko;
        this->adres = adres;
    }
    static void load_from_file(std::string filename, std::vector<Person*>* destination) {
        // file format : pesel;imie;nazwisko;adres
        std::fstream file;
        file.open(filename, std::ios::in);
        if (!file) {
            throw "Couldn't open file";
        } else {
            std::string line;
            while (std::getline(file, line)) {
                std::vector<std::string> tokens;
                size_t pos = 0;
                while ((pos = line.find(';')) != std::string::npos) {
                    tokens.push_back(line.substr(0, pos));
                    line.erase(0, pos + 1);
                }
                if (tokens.size() != 4) throw "File read error";
                if (validate_pesel(tokens[0])) {
                    destination->push_back(
                        new Person(tokens[0], tokens[1], tokens[2], tokens[3]));
                } else {
                    throw "Incorrect PESEL";
                }
            }
            file.close();
        }
    }
    static bool validate_pesel(const std::string pesel) {
        if (pesel.length() != 11) return false;
        // TODO: check if all are numbers
        return true;
    }
    void display() {
        std::cout << this->pesel << " | " << this->imie << " | " << this->nazwisko << " | " << this->adres << std::endl;
    }
};
int main() {
    std::vector<Person*> Rekordy;
    Person::load_from_file("rekordy.txt", &Rekordy);
    Rekordy[0]->display();
    return 0;
}