#ifndef DEVELOPER_HEAD
#define DEVELOPER_HEAD
#include "Employee.hpp"

class Developer : public Employee {
public: 
    //ctors and dtor
    Developer(const Developer& other);
    Developer(Developer&& other);
    Developer(std::string name = "", double salary = 0.0, unsigned int projects = 0);
    Developer& operator=(const Developer& other);
    Developer& operator=(Developer&& other);
    ~Developer() = default;

//virtual methods
    virtual double calculateSalary() const override;
    virtual void displayInfo() const override;
    virtual Developer* clone() const override;
protected:
    unsigned int m_projects{0};
};

#endif //DEVELOPER_HEAD