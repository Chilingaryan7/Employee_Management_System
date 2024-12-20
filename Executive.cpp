#ifndef EXECUTIVE
#define EXECUTIVE
#include "Executive.hpp"

Executive::Executive(std::string name, double salary, unsigned int numEmployees, unsigned int managersSupervised, double companyPerformance)
 : SeniorManager{name, salary, numEmployees, managersSupervised}, m_companyPerformance{companyPerformance} {
 m_role = Role::Executive;
 }

Executive::Executive(const Executive& other) : SeniorManager{other},m_companyPerformance{other.m_companyPerformance} {}

Executive::Executive(Executive&& other) : SeniorManager(std::move(other)), m_companyPerformance{std::exchange(other.m_companyPerformance, 0.0)} {} 

Executive& Executive::operator=(const Executive& other){
    if (this != &other) {
        SeniorManager::operator=(other);
        m_companyPerformance = other.m_companyPerformance;
    }
    return *this;
}
Executive& Executive::operator=(Executive&& other) {
    if (this != &other) {
        SeniorManager::operator=(std::move(other));
        m_companyPerformance = std::exchange(other.m_companyPerformance, 0.0);
    }
    return *this;
}

 void Executive::displayInfo() const {
    SeniorManager::displayInfo();
    std::cout << "companyPerformance : " << m_companyPerformance << std::endl;
    return;
 }

 double Executive::calculateSalary() const {
    return SeniorManager::calculateSalary() + (get_bonus_type(performanceBonus) * m_companyPerformance);
 }

Executive* Executive::clone() const{
    return new Executive(*this);
}

#endif //EXECUTIVE