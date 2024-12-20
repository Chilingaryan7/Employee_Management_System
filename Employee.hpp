#ifndef EMPLOYEE_HEAD
#define EMPLOYEE_HEAD
#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include "get_bonus_type.hpp"
#include "Role.hpp"

class Employee {
public:
    //ctors and dtor
    Employee(const Employee& other);
    Employee(Employee&& other);
    Employee(const std::string name = "", const double salary = 0.0);
    Employee& operator=(const Employee& other);
    Employee& operator=(Employee&& other);
    virtual ~Employee() = default;

    //pure virtual methods
    virtual double calculateSalary() const = 0;
    virtual void displayInfo() const = 0;
    virtual Employee* clone() const = 0;
    //not virtual methods
    std::string get_name() const;
    Role get_role() const;

protected:
    Role m_role{Role::Employee};
    double m_salary{0.0};
    std::string m_name{""};
};

#endif //EMPLOYEE_HEAD