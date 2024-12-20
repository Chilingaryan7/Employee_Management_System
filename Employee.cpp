#ifndef EMPLOYEE
#define EMPLOYEE
#include "Employee.hpp"
Employee::Employee(const Employee& other) : m_name{other.m_name}, m_salary{other.m_salary} {
    m_role = Role::Employee;
}

Employee::Employee(Employee&& other) : m_name{std::move(other.m_name)}, m_salary{std::exchange(other.m_salary, 0)} {}

Employee::Employee(const std::string name, const double salary) :m_name{name}, m_salary{salary}  {}

Employee& Employee::operator=(const Employee& other) {
    if (this != &other) {
        m_name = other.m_name;
        m_salary = other.m_salary;
        m_role = other.m_role;
    }
    return *this;    
}

Employee& Employee::operator=(Employee&& other) {
    if (this != &other) {
        m_name = std::exchange(other.m_name, "");
        m_salary = std::exchange(other.m_salary, 0);
    }
    return *this;    
}

std::string Employee::get_name() const {
    return m_name;
}
Role Employee::get_role() const {
    return m_role;
}

void Employee::displayInfo() const {
    std::cout << "name: " << m_name << std::endl;
    std::cout << "salary: " << m_salary << std::endl;  
    return;
}

#endif //EMPLOYEE