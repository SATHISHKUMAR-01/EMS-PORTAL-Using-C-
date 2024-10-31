#ifndef LOGIN_H
#define LOGIN_H
#include "headers.h"
#include "employee.h"

#define EDIT_EMP_ID 1
#define EDIT_NAME 2
#define EDIT_FATHER_NAME 3
#define EDIT_DOB 4
#define EDIT_AGE 5
#define EDIT_ROLE 6
#define EDIT_DEPARTMENT 7
#define EDIT_DATE_OF_JOIN 8

class Login{
    public:
    void frontPage();
    void loginPage(bool *isContinue, bool *isAdminLogin, bool *isEmpLogin);
    void displayEmployeeData(int emp_id, int age, string name, string dob, string role, string fatherName, string department, string dateOfJoin);
    void adminLogin(Employee& emp);
    void employeeLogin(Employee& emp);
    void addEmployeeData(Employee& emp);
    void updateEmployeeData(Employee& emp);
};

#endif