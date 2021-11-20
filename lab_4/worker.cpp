#include <iostream>
#include <string>

class Worker {
private:
    std::string name;
    std::string last_name;
    std::string nip;
    std::string date_of_employment;
    double salary;
    std::string department;

public:
    Worker(const std::string &name, const std::string &lastName, const std::string &nip,
           const std::string &dateOfEmployment, double salary, const std::string &department) : name(name),
                                                                                                last_name(lastName),
                                                                                                nip(nip),
                                                                                                date_of_employment(
                                                                                                        dateOfEmployment),
                                                                                                salary(salary),
                                                                                                department(
                                                                                                        department) {}

    virtual void display() {
        std::cout << "Worker { name: " << name << " last_name: " << last_name << " nip: " << nip
                  << " date_of_employment: " << date_of_employment << " salary: " << salary << " department: "
                  << department << " }";
    }

    const std::string &getName() const {
        return name;
    }

    void setName(const std::string &name) {
        Worker::name = name;
    }

    const std::string &getLastName() const {
        return last_name;
    }

    void setLastName(const std::string &lastName) {
        last_name = lastName;
    }

    const std::string &getNip() const {
        return nip;
    }

    void setNip(const std::string &nip) {
        Worker::nip = nip;
    }

    const std::string &getDateOfEmployment() const {
        return date_of_employment;
    }

    void setDateOfEmployment(const std::string &dateOfEmployment) {
        date_of_employment = dateOfEmployment;
    }

    double getSalary() const {
        return salary;
    }

    void setSalary(double salary) {
        Worker::salary = salary;
    }

    const std::string &getDepartment() const {
        return department;
    }

    void setDepartment(const std::string &department) {
        Worker::department = department;
    }

    virtual ~Worker() = default;
};

class Manager : public Worker {
private:
    unsigned int amount_of_slaves;
    int type_of_management;
    double functional_supplement;
public:
    Manager(const std::string &name, const std::string &lastName, const std::string &nip,
            const std::string &dateOfEmployment, double salary, const std::string &department,
            unsigned int amountOfSlaves, int typeOfManagement, double functionalSupplement) : Worker(name, lastName,
                                                                                                     nip,
                                                                                                     dateOfEmployment,
                                                                                                     salary,
                                                                                                     department),
                                                                                              amount_of_slaves(
                                                                                                      amountOfSlaves),
                                                                                              type_of_management(
                                                                                                      typeOfManagement),
                                                                                              functional_supplement(
                                                                                                      functionalSupplement) {}

    void display() override {
        std::cout << "Worker { name: " << getName() << " last_name: " << getLastName() << " nip: " << getNip()
                  << " date_of_employment: " << getDateOfEmployment() << " salary: " << getSalary() << " department: "
                  << getDepartment() << "amout_of_slaves: " << amount_of_slaves << "type_of_menagement: "
                  << type_of_management << "funcional_suplement: " << functional_supplement << " }";
    }
};

int main() {
    std::string imie = "Adam";
    std::string nazwisko = "Jezioro";
    std::string nip = "123456789";
    std::string data = "12:03:2020";
    std::string dzial = "bankowosc";
    auto worker = Worker(imie, nazwisko, nip, data, 20., dzial);
    return 0;
}