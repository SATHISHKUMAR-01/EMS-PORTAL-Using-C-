#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "headers.h"

class Employee {
    private:
    int emp_id;
    int age;
    string dob;
    string name;
    string role;
    string fatherName;
    string department;
    string dateOfJoin;

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