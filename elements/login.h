#ifndef LOGIN_H
#define LOGIN_H
#include "../libraries/headers.h"
#include "employee.h"

class Login{
    private:
    map<string,string> holidayCalendar;

    public:
    Login(){
        addHoliday("New Year", "Jan 01 2024");
        addHoliday("Pongal", "Jan 14 2024");
        addHoliday("Republic Day", "Jan 26 2024");
        addHoliday("Tamil New Year", "April 14 2024");
        addHoliday("Independence Day", "August 15 2024");
        addHoliday("Gandhi Jayanthi", "Oct 02 2024");
        addHoliday("Diwali", "Oct 31 2024");
        addHoliday("Christmas", "December 25 2024");
    }
    void frontPage();
    void loginPage(bool *isContinue, bool *isAdminLogin, bool *isEmpLogin);
    void displayEmployeeData(int emp_id, int age, string name, string dob, string role, string fatherName, string department, string dateOfJoin, string sex, int salary);
    void adminLogin(Employee& emp);
    void employeeLogin(Employee& emp);
    void addEmployeeData(Employee& emp);
    void showHolidays();
    void addHoliday(string name, string date);
    string getLeaveType(int type);
};

#endif