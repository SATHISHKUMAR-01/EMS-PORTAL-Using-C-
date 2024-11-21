#ifndef LOGIN_H
#define LOGIN_H
#include "../libraries/headers.h"
#include "employee.h"

#define EXIT 0

#define VIEW_HOLIDAY 1
#define VIEW_LEAVE_BALANCE 2
#define LEAVE_OPERATIONS 3
#define VIEW_SALARY 4
#define VIEW_PEOPLE 5
#define VIEW_PROJECT_AND_MANAGER_INFO 6
#define APPROVE_LEAVE_REQ 7
#define REVIEW_OPERATIONS 8
#define APPROVE_REVIEW 9
#define VIEW_ATTENDANCE 10
#define VIEW_NOTIFICATIONS 11

#define ADD_NEW_EMPLOYEE 1
#define UPDATE_EMPLOYEE_DATA 2
#define VIEW_ALL_EMPLOYEE_DATA 3
#define VIEW_SPECIFIC_EMPLOYEE_DATA 4
#define GRANT_LEAVE 5
#define VIEW_LEAVE_COUNTS 6
#define ADD_MANAGER_DATA 7
#define REMOVE_MANAGER_DATA 8
#define VIEW_MANAGER_DATA 9
#define UPDATE_MANAGER_DATA 10
#define ADD_PROJECT_DATA 11
#define REMOVE_PROJECT_DATA 12
#define VIEW_PROJECT_DATA 13
#define UPDATE_PROJECT_DATA 14
#define MAP_EMPLOYEE_TO_MANAGER 15
#define MAP_EMPLOYEE_TO_PROJECT 16
#define VIEW_EMP_PROJECT_AND_MANAGER_INFO 17
#define ADD_ATTENDANCE_ENTRY 18

#define EMPLOYEE_LOGIN 1
#define ADMIN_LOGIN 2

#define SAVE_DATA 1
#define EDIT_DATA 2

#define WORK_FROM_HOME 1
#define VACATION_LEAVE 2
#define ANNUAL_LEAVE 3
#define TEAM_TIME_OFF 4
#define PATERNITY_LEAVE 5
#define MATERNITY_LEAVE 6
#define MARRIAGE_LEAVE 7

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