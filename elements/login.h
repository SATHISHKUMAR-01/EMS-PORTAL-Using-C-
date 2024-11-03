#ifndef LOGIN_H
#define LOGIN_H
#include "../libraries/headers.h"
#include "employee.h"

class Login{
    public:
    void frontPage();
    void loginPage(bool *isContinue, bool *isAdminLogin, bool *isEmpLogin);
    void displayEmployeeData(int emp_id, int age, string name, string dob, string role, string fatherName, string department, string dateOfJoin);
    void adminLogin(Employee& emp);
    void employeeLogin(Employee& emp);
    void addEmployeeData(Employee& emp);
};

#endif