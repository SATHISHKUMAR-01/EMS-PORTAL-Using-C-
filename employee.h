#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "headers.h"

struct emp_details {
    int emp_id;
    int age;
    string dob;
    string name;
    string role;
    string fatherName;
    string department;
    string dateOfJoin;
};

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

    vector<emp_details> employee;
    public:
    // Set Methods
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

    void addEmployee(struct emp_details details);
    void displayEmployee();
    void diplaySpecificEmployee(int emp_id);
    emp_details* getEmployee(int emp_id);
};

#endif