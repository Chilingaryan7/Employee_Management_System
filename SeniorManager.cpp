#ifndef SENIOR_MANAGER
#define SENIOR_MANAGER
#include "SeniorManager.hpp"

SeniorManager::SeniorManager(std::string name, double salary, unsigned int numEmployees, unsigned int managersSupervised) : Manager{name, salary, numEmployees}, m_managersSupervised{managersSupervised} {}

SeniorManager::SeniorManager(const SeniorManager& other) : Manager{other}, m_managersSupervised{other.m_managersSupervised} {}

SeniorManager::SeniorManager(SeniorManager&& other) : Manager{std::move(other)}, m_managersSupervised{std::exchange(other.m_managersSupervised, 0.0)} {}

SeniorManager& SeniorManager::operator=(const SeniorManager& other) {
    if (this != &other) {
        Manager::operator=(other);
        m_managersSupervised = other.m_managersSupervised;
    }
    return *this;
}

SeniorManager& SeniorManager::operator=(SeniorManager&& other) {
    if (this != &other) {
        Manager::operator=(std::move(other));
        m_managersSupervised = std::exchange(other.m_managersSupervised, 0.0);
    }
    return *this;
}

void SeniorManager::displayInfo() const {
    Manager::displayInfo();
    std::cout << "ManagersSupervised : " << m_managersSupervised <<std::endl;
    return;
}

double SeniorManager::calculateSalary() const {
    return Manager::calculateSalary() + (m_managersSupervised * get_bonus_type(additionalBonus));
}

SeniorManager* SeniorManager::clone() const{
    return new SeniorManager(*this);
}

#endif //SENIOR_MANAGER