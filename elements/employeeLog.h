#ifndef EMPLOYEELOG_H
#define EMPLOYEELOG_H
#include "../libraries/headers.h"

class EmployeeLog {
    public:
    int emp_id;
    string name;
    string date;
    string login_time;
    string logout_time;

    EmployeeLog(int id, const string& name, const string& date, const string& login, const string& logout)
        : emp_id(id), name(name), date(date), login_time(login), logout_time(logout) {}

    void display() const {
        cout << "ID : " << emp_id << " Name : " << name << " Date: " << date << ", Login Time: " << login_time
             << ", Logout Time: " << logout_time << endl;
    }
};

#endif