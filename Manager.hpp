#ifndef MANAGER_HEADER
#define MANAGER_HEADER
#include "Employee.hpp"
class Manager : public Employee {
public:
//ctors and dtor
    Manager(const Manager& other);
    Manager(Manager&& other);
    Manager(std::string name = "", double salary = 0.0, unsigned int numEmployees = 0);
    Manager& operator=(const Manager& other);
    Manager& operator=(Manager&& other);
    ~Manager() = default;

//virtual methods
    virtual double calculateSalary() const override;
    virtual void displayInfo() const override;
    virtual Manager* clone() const override;

protected:
    unsigned int m_numEmployees{0};
};
#endif //MANAGER_HEADER