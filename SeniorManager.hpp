#ifndef SENIOR_MANAGER_HEADER
#define SENIOR_MANAGER_HEADER
#include "Manager.hpp"

class SeniorManager : public Manager {
public:
    //ctors and dtor
    SeniorManager(const SeniorManager& other);
    SeniorManager(SeniorManager&& other);
    SeniorManager(std::string name = "", double salary = 0.0, unsigned int numEmployees = 0, unsigned int managersSupervised = 0);
    SeniorManager& operator=(const SeniorManager& other);
    SeniorManager& operator=(SeniorManager&& other);
    ~SeniorManager() = default;  

    //virtual methods
    virtual double calculateSalary() const override;
    virtual void displayInfo() const override;
    virtual SeniorManager* clone() const override;

protected:
    unsigned int m_managersSupervised{0};
};

#endif // SENIOR_MANAGER_HEADER