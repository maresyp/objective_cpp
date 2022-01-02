//
// Created by Mateusz Pysera on 07/12/2021.
//
#include <iostream>
#include <fstream>
#include <chrono>

class TestTime {
public:
    virtual void read_file_vr(const std::string &filename);

    void read_file_non_vr(const std::string &filename);

};

void TestTime::read_file_vr(const std::string &filename) {
    std::string data;
    std::ifstream file;
    file.open(filename);
    file >> data;
    file.close();
}

void TestTime::read_file_non_vr(const std::string &filename) {
    std::string data;
    std::ifstream file;
    file.open(filename);
    file >> data;
    file.close();
}

class ChildTestTime : public TestTime {

};

int main() {
    auto cht = ChildTestTime();

    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 100; ++i) {
        cht.read_file_vr("data.txt");
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Virtual - 1000 x call " << duration.count() << "\n";


    auto start2 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 100; ++i) {
        cht.read_file_non_vr("data.txt");
    }
    auto end2 = std::chrono::high_resolution_clock::now();
    auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(end2 - start2);
    std::cout << "Non Virtual - 1000 x call " << duration2.count() << "\n";
    return 0;
}

