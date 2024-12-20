#ifndef MANAGER
#define MANAGER
#include "Manager.hpp"
Manager::Manager(std::string name, double salary, unsigned int numEmployees) : Employee(name, salary), m_numEmployees{numEmployees} {
    m_role = Role::Manager;
}

Manager::Manager(const Manager& other) : Employee(other), m_numEmployees{other.m_numEmployees} {}

Manager::Manager(Manager&& other) : Employee{std::move(other)}, m_numEmployees{std::exchange(other.m_numEmployees, 0)} {}

Manager& Manager::operator=(const Manager& other) {
    if (this != &other) {
    Employee::operator=(other);
    m_numEmployees = other.m_numEmployees;
    }
    return *this;
}
Manager& Manager::operator=(Manager&& other) {
    if (this != &other) {
        Employee::operator=(std::move(other));
        m_numEmployees = std::exchange(other.m_numEmployees, 0);
    }    
    return *this;
}

 void Manager::displayInfo() const {
    Employee::displayInfo();
    std::cout << "numEmployees : " << m_numEmployees << std::endl; 
    return;
 }

double Manager::calculateSalary() const {
    return m_salary + (get_bonus_type(bonus) * m_numEmployees);
}

Manager* Manager::clone() const{
    return new Manager(*this);
}
#endif //MANAGER