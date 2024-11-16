#ifndef EMPLOYEELOG_H
#define EMPLOYEELOG_H
#include "../libraries/headers.h"
#include "employee.h"

class EmployeeLog : Employee {
    public:
    int emp_id;
    string date;
    string login_time;
    string logout_time;

    EmployeeLog(int id, const string& date, const string& login, const string& logout)
        : emp_id(id), date(date), login_time(login), logout_time(logout) {}

    void display() const {
        cout << "Date: " << date << ", Login Time: " << login_time
             << ", Logout Time: " << logout_time << endl;
    }

    void readCSVAndStore(const string& filename, Employee& emp);
};

#endif