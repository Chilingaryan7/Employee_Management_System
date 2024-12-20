#ifndef EMPLOYEE_MANAGEMENT_SYSTEM
#define  EMPLOYEE_MANAGEMENT_SYSTEM
#include "EmployeeManagementSystem.hpp"
EmployeeManagementSystem::EmployeeManagementSystem() : m_employers{} {}

EmployeeManagementSystem::~EmployeeManagementSystem() {
    for ( auto i : m_employers) {
        delete i;
    }
}

EmployeeManagementSystem::EmployeeManagementSystem(const EmployeeManagementSystem& other) {
    for (auto i : other.m_employers) {
        m_employers.push_back(i -> clone());
    }
}

EmployeeManagementSystem::EmployeeManagementSystem(EmployeeManagementSystem&& other) :  m_employers{std::move(other.m_employers)} {}

EmployeeManagementSystem& EmployeeManagementSystem::operator=(const EmployeeManagementSystem& other) {
    if (this != &other) {
        for(auto i : m_employers) {
            delete i;
        }
        m_employers.clear();
        for (auto i : other.m_employers) {
            m_employers.push_back(i -> clone());
        }
    }
    return *this;
}

EmployeeManagementSystem& EmployeeManagementSystem::operator=(EmployeeManagementSystem&& other){
    if (this != &other) {
        m_employers = std::move(other.m_employers);
    }
    return *this;
}

void EmployeeManagementSystem::addEmployee(Employee* employee){
    m_employers.push_back(employee);
}

void EmployeeManagementSystem::displayAllEmployees() const{
    for (auto i : m_employers) {
        i -> displayInfo();
    }
}

double EmployeeManagementSystem::calculateTotalSalary() const {
    double result{0.0};
    for (auto i : m_employers) {
        result += i ->calculateSalary();
    }
    return result;
}

void EmployeeManagementSystem::searchEmployeeByName(const std::string& name) const {
    for (auto i : m_employers) {
        if (name == i -> get_name()) {
            i -> displayInfo();
        }
    }
    return;
}

void EmployeeManagementSystem::searchEmployeeByRole(const Role& role) const {
    for (auto i : m_employers) {
        if (role == i -> get_role()) {
            i -> displayInfo();
        }
    }
    return;
}

void EmployeeManagementSystem::removeEmployeeByName(const std::string& name) {
    for (size_t i = 0; i < m_employers.size(); ++i) {
        if (m_employers[i] -> get_name() == name) {
            m_employers.erase(m_employers.begin() + i);
        }
    }
    return;
 }

#endif //EMPLOYEE_MANAGEMENT_SYSTEM