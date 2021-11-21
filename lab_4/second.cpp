#include <iostream>
#include <string>

class Person {
private:
    std::string name;
    std::string last_name;
    std::string date_of_birth;

public:
    virtual void WypiszInfo() const {
        std::cout << "{ " << name << last_name << date_of_birth << std::endl;
    }
};

class Student : public Person {
private:
    std::string year;
    unsigned int group;
    std::string index;

public:

};

class FootballPlayer : public Person {

};

int main() {
    std::cout << "Hello World";
    return 0;
}