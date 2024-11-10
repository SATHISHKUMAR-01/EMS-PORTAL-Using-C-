#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "../libraries/headers.h"

#define ADD_WFH 1
#define ADD_ANNUAL_LEAVE 2
#define ADD_VACATION_LEAVE 3
#define ADD_TEAM_OFF 4
#define ADD_MATERNITY_LEAVE 5
#define ADD_PATERNITY_LEAVE 6
#define ADD_MARRIAGE_LEAVE 7

struct emp_details {
    int emp_id;
    int age;
    string dob;
    string name;
    string role;
    string fatherName;
    string department;
    string dateOfJoin;
    string sex;
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

struct manager_details {
    int emp_id;
    string name;
    int number_of_projects;
    vector<int> project_id;
    int team_member_count;
    vector<int> team_members_id;

    bool operator==(const manager_details& other) const {
        return emp_id == other.emp_id;
    }
};

struct project_details {
    int project_id;
    string project_name;
    string customer_name;
    int team_member_count;
    vector<int> team_members_id;

    bool operator==(const project_details& other) const {
        return project_id == other.project_id;
    }
};

struct leave_details {
    string leave_type;
    string reason;
    string start_date;
    string end_date;
    int number_of_days;
    string leave_status;
};

class Employee {
    private:
    vector<emp_details> employee;
    vector<int> adminId;
    map<int, leaveData> LeaveMap;
    vector<manager_details> manager_data;
    vector<project_details> project_data;
    map<int, int> emp_to_manager_map;
    map<int, int> emp_to_project_map;
    map<int, leave_details> leave_data;
    int defaultInternWFH, defaultSeniorWFH, defaultManagerWFH, defaultVacationLeave, defaultAnnualLeave, defaultTeamOff, defaultPaternityLeave, defaultMaternityLeave, defaultMarriageLeave;

    public:
    Employee(){
        emp_details info[2];
        info[0].emp_id = 1;
        info[0].age = 22;
        info[0].dob = "01/03/1998";
        info[0].name = "Rahul";
        info[0].role = "Intern";
        info[0].department = "Admin";
        info[0].fatherName = "Harish";
        info[0].dateOfJoin = "03/12/2021";
        info[0].sex = "Male";
        employee.push_back(info[0]);

        info[1].emp_id = 2;
        info[1].age = 21;
        info[1].dob = "01/12/2000";
        info[1].name = "Francis";
        info[1].role = "Senior";
        info[1].department = "HR";
        info[1].fatherName = "Venkatesh";
        info[1].dateOfJoin = "03/02/2023";
        info[1].sex = "Female";
        employee.push_back(info[1]);

        defaultInternWFH = defaultSeniorWFH = defaultManagerWFH = defaultVacationLeave = defaultAnnualLeave = defaultTeamOff =  defaultPaternityLeave = defaultMaternityLeave = defaultMarriageLeave = 0;
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
    void setSex(struct emp_details *detail, string sex);

    void setSeniorWorkFromHome(int workFromHome);
    void setInternWorkFromHome(int workFromHome);
    void setManagerWorkFromHome(int workFromHome);
    void setVacationLeave(int vacationLeave);
    void setAnnualLeave(int annualLeave);
    void setTeamOff(int teamOff);
    void setPaternityLeave(int paternityLeave);
    void setMaternityLeave(int maternityLeave);
    void setMarriageLeave(int marriageLeave);

    //Get Methods
    int getEmpId(struct emp_details *detail);
    int getAge(struct emp_details *detail);
    string getName(struct emp_details *detail);
    string getRole(struct emp_details *detail);
    string getDob(struct emp_details *detail);
    string getFatherName(struct emp_details *detail);
    string getDepartment(struct emp_details *detail);
    string getDateOfJoin(struct emp_details *detail);
    string getSex(struct emp_details *detail);

    int getSeniorWorkFromHome();
    int getInternWorkFromHome();
    int getManagerWorkFromHome();
    int getVacationLeave();
    int getAnnualLeave();
    int getTeamOff();
    int getPaternityLeave();
    int getMaternityLeave();
    int getMarriageLeave();

    void addEmployee(struct emp_details details);
    void displayEmployee();
    void diplaySpecificEmployee(int emp_id);
    void updateEmployeeData(Employee& emp);
    emp_details* getEmployee(int emp_id);
    bool isAdmin(int emp_id);
    void addAdminId(int id);
    void grantLeaveToEmployee();
    leaveData* viewLeaveBalance(int emp_id);
    void addExtraLeaveToAll(int leaveType, int count);
    void showPeopleData();
    void saveManagerData(struct manager_details details);
    vector<manager_details>& getManagerData();
    manager_details* getSpecificManagerData(int emp_id);
    void saveProjectData(struct project_details details);
    vector<project_details>& getProjectData();
    project_details* getSpecificProjectData(int proj_id);
    void mapEmployeeToManager(int emp_id, int manager_id);
    void mapEmployeeToProject(int emp_id, int project_id);
};

#endif