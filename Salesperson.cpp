#ifndef SALESPERSON
#define SALESPERSON
#include "Salesperson.hpp"

Salesperson::Salesperson(std::string name, double salary, double totalSales) : Employee(name, salary), m_totalSales{totalSales} {
    m_role = Role::Salesperson;
}

Salesperson::Salesperson(const Salesperson& other) : Employee(other), m_totalSales{other.m_totalSales} {}

Salesperson::Salesperson(Salesperson&& other) : Employee{std::move(other)}, m_totalSales{std::exchange(other.m_totalSales, 0.0)} {}

Salesperson& Salesperson::operator=(const Salesperson& other) {
    if (this != &other) {
    Salesperson::operator=(other);
    m_totalSales = other.m_totalSales;
    }
    return *this;
}
Salesperson& Salesperson::operator=(Salesperson&& other) {
    if (this != &other) {
        Employee::operator=(std::move(other));
        m_totalSales = std::exchange(other.m_totalSales, 0.0);
    }    
    return *this;
}

 void Salesperson::displayInfo() const {
    Employee::displayInfo();
    std::cout << "totalSales :" << m_totalSales << std::endl; 
    return;
 }

double Salesperson::calculateSalary() const {
    return m_salary + (commissionRate * m_totalSales);
}

Salesperson* Salesperson::clone() const{
    return new Salesperson(*this);
}
#endif //SALESPERSON