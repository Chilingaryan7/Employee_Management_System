#ifndef EMPLOYEE_MANAGEMENT_SYSTEM_HEADER
#define  EMPLOYEE_MANAGEMENT_SYSTEM_HEADER
#include "Employee.hpp"

class EmployeeManagementSystem {
public:    
    //ctors and dtor
    EmployeeManagementSystem();
    EmployeeManagementSystem(const EmployeeManagementSystem& other);
    EmployeeManagementSystem(EmployeeManagementSystem&& other);
    EmployeeManagementSystem& operator=(const EmployeeManagementSystem& other);
    EmployeeManagementSystem& operator=(EmployeeManagementSystem&& other);

    //not virtual methods
    void addEmployee(Employee* employee);
    void displayAllEmployees() const;
    double calculateTotalSalary() const;
    void searchEmployeeByName(const std::string& name) const;
    void searchEmployeeByRole(const Role& role) const;
    void removeEmployeeByName(const std::string& name);
    virtual ~EmployeeManagementSystem();
private:
    std::vector<Employee*> m_employers{nullptr};
};

#endif //EMPLOYEE_MANAGEMENT_SYSTEM_HEADER