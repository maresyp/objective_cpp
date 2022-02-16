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

    void setName(const std::string &new_name) {
        Worker::name = new_name;
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

    void setNip(const std::string &new_nip) {
        Worker::nip = new_nip;
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

    void setSalary(double new_salary) {
        Worker::salary = new_salary;
    }

    const std::string &getDepartment() const {
        return department;
    }

    void setDepartment(const std::string &new_department) {
        Worker::department = new_department;
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

    Worker *create_new_worker() {
        std::string name;
        std::string last_name;
        std::string nip;
        std::string date_of_employment;
        double salary;
        std::string department;
        std::cout << "Wprowadz dane nowego pracownika: \n";
        std::cout << "Podaj imie: ";
        std::cin >> name;
        std::cout << "Podaj nazwisko: ";
        std::cin >> last_name;
        std::cout << "Podaj nip: ";
        std::cin >> nip;
        std::cout << "Podaj date zatrudnienia: ";
        std::cin >> date_of_employment;
        std::cout << "Podaj wynagrodzenie: ";
        std::cin >> salary;
        std::cout << "Podaj dzial: ";
        std::cin >> department;
        return new Worker(name, last_name, nip, date_of_employment, salary, department);
    }
};

int main() {
    auto manager = Manager("Adam", "Jezioro", "123456789", "11.02.2008", 14.500, "IT", 3, 5, 14);
    manager.display();
    auto worker = manager.create_new_worker();
    worker->display();
    return 0;
    
}