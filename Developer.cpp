#ifndef DEVELOPER
#define DEVELOPER
#include "Developer.hpp"

Developer::Developer(std::string name, double salary, unsigned int projects) : Employee(name, salary), m_projects{projects} {
    m_role = Role::Developer;
}

Developer::Developer(const Developer& other) : Employee(other), m_projects{other.m_projects} {}

Developer::Developer(Developer&& other) : Employee{std::move(other)}, m_projects{std::exchange(other.m_projects, 0)} {}

Developer& Developer::operator=(const Developer& other) {
    if (this != &other) {
        Employee::operator=(other);
        m_projects = other.m_projects;
    }
    return *this;
}
Developer& Developer::operator=(Developer&& other) {
    if (this != &other) {
        Employee::operator=(std::move(other));
        m_projects = std::exchange(other.m_projects, 0);
    }
    return *this;
}

double Developer::calculateSalary() const {
    return m_salary + (get_bonus_type(bonus) * m_projects);
}

void Developer::displayInfo() const {
    Employee::displayInfo();
    std::cout << "projects : " << m_projects << std::endl; 
    return;
} 
Developer* Developer::clone() const{
    return new Developer(*this);
}

#endif //DEVELOPER