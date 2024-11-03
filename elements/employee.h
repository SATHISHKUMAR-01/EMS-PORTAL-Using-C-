#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "../libraries/headers.h"

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

struct leaveData {
    int workFromHome;
    int vacationLeave;
    int annualLeave;
    int teamOff;
    int paternityLeave;
    int maternityLeave;
    int marriageLeave;
};

class Employee {
    private:
    vector<emp_details> employee;
    vector<int> adminId;
    map<int, leaveData> LeaveMap;
    
    public:

    Employee(){
        emp_details info[2];
        info[0].emp_id = 1;
        info[0].age = 22;
        info[0].dob = "01/03/1998";
        info[0].name = "Rahul";
        info[0].role = "Admin";
        info[0].department = "Engineering";
        info[0].fatherName = "Harish";
        info[0].dateOfJoin = "03/12/2021";
        employee.push_back(info[0]);

        info[1].emp_id = 2;
        info[1].age = 21;
        info[1].dob = "01/12/2000";
        info[1].name = "Francis";
        info[1].role = "HR";
        info[1].department = "Engineering";
        info[1].fatherName = "Venkatesh";
        info[1].dateOfJoin = "03/02/2023";
        employee.push_back(info[1]);
    }

    // Set Methods
    void setEmpId(struct emp_details *detail, int emp_id);
    void setAge(struct emp_details *detail, int age);
    void setName(struct emp_details *detail, string name);
    void setRole(struct emp_details *detail, string role);
    void setDob(struct emp_details *detail, string dob);
    void setFatherName(struct emp_details *detail, string fatherName);
    void setDepartment(struct emp_details *detail, string department);
    void setDateOfJoin(struct emp_details *detail, string dateOfJoin);

    //Get Methods
    int getEmpId(struct emp_details *detail);
    int getAge(struct emp_details *detail);
    string getName(struct emp_details *detail);
    string getRole(struct emp_details *detail);
    string getDob(struct emp_details *detail);
    string getFatherName(struct emp_details *detail);
    string getDepartment(struct emp_details *detail);
    string getDateOfJoin(struct emp_details *detail);

    void addEmployee(struct emp_details details);
    void displayEmployee();
    void diplaySpecificEmployee(int emp_id);
    void updateEmployeeData(Employee& emp);
    emp_details* getEmployee(int emp_id);
    bool isAdmin(int emp_id);
    void addAdminId(int id);
    void grantLeaveToEmployee();
};

#endif