#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using namespace std;

class Employee {
    private:
    int emp_id;
    int age;
    string name;
    string role;

    public:
    // Set Methods
    void setEmpId(int emp_id);
    void setAge(int age);
    void setName(string name);
    void setRole(string role);

    //Get Methods
    int getEmpId();
    int getAge();
    int getName();
    int getRole();
};

#endif