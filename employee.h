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
    Employee(int emp_id, int age, string name, string role, string dob, string fatherName, string department, string dateOfJoin);
    void setEmpId(int emp_id);
    void setAge(int age);
    void setName(string name);
    void setRole(string role);
    void setDob(string dob);
    void setFatherName(string fatherName);
    void setDepartment(string department);
    void setDateOfJoin(string dateOfJoin);

    //Get Methods
    int getEmpId();
    int getAge();
    string getName();
    string getRole();
    string getDob();
    string getFatherName();
    string getDepartment();
    string getDateOfJoin();
};

#endif