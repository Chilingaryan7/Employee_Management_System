#ifndef SALESPERSON_HEADER
#define SALESPERSON_HEADER
#include "Employee.hpp"

class Salesperson : public Employee {
public:
    //ctors and dtor   
    Salesperson(const Salesperson& other);
    Salesperson(Salesperson&& other);
    Salesperson(std::string name = "", double salary = 0.0, double totalSales = 0);
    Salesperson& operator=(const Salesperson& other);
    Salesperson& operator=(Salesperson&& other);
    ~Salesperson() = default;

    //virtual methods
    virtual double calculateSalary() const override;
    virtual void displayInfo() const override;
    virtual Salesperson* clone() const override;

protected:
    double m_totalSales{0.0};
};

#endif //SALESPERSON_PERSON