
#include <iostream>

class Person {
protected:
    std::string name;
    std::string last_name;
    std::string date_of_birth;

public:
    virtual void print_info() {
        std::cout << name << " " << last_name << " " << date_of_birth << " ";
    }
};

class Student : public Person {
protected:
    std::string year;
    uint16_t group;
    std::string index;

public:
    virtual void print_info() {
        Person::print_info();
        std::cout << year << " " << group << " " << index << " ";
    }
};

class FootballPlayer : public Person {
protected:
    std::string position;
    std::string club;
    uint32_t score_count;

public:
    virtual void print_info() {
        Person::print_info();
        std::cout << position << " " << club << " " << score_count << " ";
    }

    void add_score() {
        score_count++;
    }
};

int main() {
    return 0;
}