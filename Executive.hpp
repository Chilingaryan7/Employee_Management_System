#ifndef EXECUTIVE_HEADER
#define EXECUTIVE_HEADER
#include "SeniorManager.hpp"

class Executive : public SeniorManager {
public:
    //ctors and dtor
    Executive(const Executive& other);
    Executive(Executive&& other);
    Executive(std::string name = "", double salary = 0.0, unsigned int numEmployees = 0, unsigned int managersSupervised = 0, double companyPerformance = 0);
    Executive& operator=(const Executive& other);
    Executive& operator=(Executive&& other);
    ~Executive() = default;

    //virtual methods
    virtual double calculateSalary() const override;
    virtual void displayInfo() const override;
    virtual Executive* clone() const override;

protected:
double m_companyPerformance{0.0};
};

#endif //EXECUTIVE_HEADER