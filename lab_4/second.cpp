
#include <iostream>

class Person {
protected:
    std::string name;
    std::string last_name;
    std::string date_of_birth;

public:
    Person(const std::string &name, const std::string &lastName, const std::string &dateOfBirth) : name(name),
                                                                                                   last_name(lastName),
                                                                                                   date_of_birth(
                                                                                                           dateOfBirth) {}

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

    Student(const std::string &name, const std::string &lastName, const std::string &dateOfBirth,
            const std::string &year, uint16_t group, const std::string &index) : Person(name, lastName, dateOfBirth),
                                                                                 year(year), group(group),
                                                                                 index(index) {}
};

class FootballPlayer : public Person {
protected:
    std::string position;
    std::string club;
    uint32_t score_count = 0;

public:
    FootballPlayer(const std::string &name, const std::string &lastName, const std::string &dateOfBirth,
                   const std::string &position, const std::string &club, uint32_t scoreCount) : Person(name, lastName,
                                                                                                       dateOfBirth),
                                                                                                position(position),
                                                                                                club(club), score_count(
                    scoreCount) {}

    virtual void print_info() {
        Person::print_info();
        std::cout << position << " " << club << " " << score_count << " ";
    }

    void add_score() {
        score_count++;
    }
};

int main() {
    auto person = Person("Adam", "Nowak", "11.02.2000");
    person.print_info();

    auto fplayer = FootballPlayer("Ola", "Nowak", "20.11.2001", "bramkarz", "PZH", 0);
    fplayer.add_score();
    fplayer.print_info();
    return 0;
}