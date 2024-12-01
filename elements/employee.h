#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "../libraries/headers.h"
#include "employeeLog.h"

#define ADD_WFH 1
#define ADD_ANNUAL_LEAVE 2
#define ADD_VACATION_LEAVE 3
#define ADD_TEAM_OFF 4
#define ADD_MATERNITY_LEAVE 5
#define ADD_PATERNITY_LEAVE 6
#define ADD_MARRIAGE_LEAVE 7

enum operations{
    PENDING,
    APPROVED,
    REJECTED
};

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
    int salary;
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
    operations leave_status;

    void print() const {
        std::cout << "Leave Type: " << leave_type << ", Reason: " << reason
                  << ", Start Date: " << start_date << ", End Date: " << end_date
                  << ", Number of Days: " << number_of_days
                  << ", Status: " << (leave_status ? "Approved" : "Pending") << std::endl;
    }
};

struct review_details{
    string emp_self_sufficiency_comments;
    int emp_self_sufficieny_rating;
    string emp_proficiency_comments;
    int emp_proficiency_rating;
    string mngr_self_sufficiency_comments;
    int mngr_self_sufficieny_rating;
    string mngr_proficiency_comments;
    int mngr_proficiency_rating;
    bool status;
    int final_rating;
};

struct message_details{
    string info;
    
    void print() const {
        cout << "\nInformation : " << info << endl;
    }
};

struct leave_req{
    int number_of_days;
    string leave_type;
    operations status;
    string comments;
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
    map<int, vector<leave_details>> leave_data;
    map<int, vector<review_details>> review_data;
    map<int, vector<message_details>> message_data;
    map<int, vector<leave_req>> leave_req_data;
    map<int, string> emp_credentials;
    int defaultInternWFH, defaultSeniorWFH, defaultManagerWFH, defaultVacationLeave, defaultAnnualLeave, defaultTeamOff, defaultPaternityLeave, defaultMaternityLeave, defaultMarriageLeave;

    public:
    map<int, vector<EmployeeLog>> employee_login;
    Employee(){
        emp_details emp_info[5];
        manager_details mngr_info[2];
        project_details proj_info[2];

        emp_info[0].emp_id = 1;
        emp_info[0].age = 23;
        emp_info[0].dob = "01/12/2001";
        emp_info[0].name = "Sathish";
        emp_info[0].role = "Senior";
        emp_info[0].department = "Engineering";
        emp_info[0].fatherName = "RTK";
        emp_info[0].dateOfJoin = "26/12/2023";
        emp_info[0].sex = "Male";
        emp_info[0].salary = 800000;
        employee.push_back(emp_info[0]);
        emp_credentials[emp_info[0].emp_id] = "SaSenior";

        emp_info[1].emp_id = 2;
        emp_info[1].age = 23;
        emp_info[1].dob = "01/10/2000";
        emp_info[1].name = "Nithya";
        emp_info[1].role = "Senior";
        emp_info[1].department = "Engineering";
        emp_info[1].fatherName = "Bala";
        emp_info[1].dateOfJoin = "03/06/2023";
        emp_info[1].sex = "Female";
        emp_info[1].salary = 800000;
        employee.push_back(emp_info[1]);

        emp_info[2].emp_id = 3;
        emp_info[2].age = 21;
        emp_info[2].dob = "01/10/2002";
        emp_info[2].name = "Roshan";
        emp_info[2].role = "Intern";
        emp_info[2].department = "HR";
        emp_info[2].fatherName = "Vinoth";
        emp_info[2].dateOfJoin = "03/06/2025";
        emp_info[2].sex = "Male";
        emp_info[2].salary = 600000;
        employee.push_back(emp_info[2]);

        emp_info[3].emp_id = 4;
        emp_info[3].age = 35;
        emp_info[3].dob = "02/03/1990";
        emp_info[3].name = "Nishanth";
        emp_info[3].role = "Manager";
        emp_info[3].department = "Engineering";
        emp_info[3].fatherName = "John";
        emp_info[3].dateOfJoin = "28/07/2011";
        emp_info[3].sex = "Male";
        emp_info[3].salary = 3000000;
        employee.push_back(emp_info[3]);

        emp_info[4].emp_id = 5;
        emp_info[4].age = 34;
        emp_info[4].dob = "24/12/1991";
        emp_info[4].name = "Dinesh";
        emp_info[4].role = "Manager";
        emp_info[4].department = "Engineering";
        emp_info[4].fatherName = "Vijay";
        emp_info[4].dateOfJoin = "22/04/2013";
        emp_info[4].sex = "Male";
        emp_info[4].salary = 2500000;
        employee.push_back(emp_info[4]);

        mngr_info[0].emp_id = 4;
        mngr_info[0].name = "Nishanth";
        mngr_info[0].number_of_projects = 1;
        mngr_info[0].project_id.push_back(1001);
        mngr_info[0].team_member_count = 1;
        mngr_info[0].team_members_id.push_back(1);
        manager_data.push_back(mngr_info[0]);

        mngr_info[1].emp_id = 5;
        mngr_info[1].name = "Dinesh";
        mngr_info[1].number_of_projects = 1;
        mngr_info[1].project_id.push_back(1002);
        mngr_info[1].team_member_count = 1;
        mngr_info[1].team_members_id.push_back(2);
        manager_data.push_back(mngr_info[1]);

        proj_info[0].project_id = 1001;
        proj_info[0].project_name = "Cisco CTO";
        proj_info[0].customer_name = "Sri";
        proj_info[0].team_member_count = 1;
        proj_info[0].team_members_id.push_back(1);
        project_data.push_back(proj_info[0]);

        proj_info[1].project_id = 1002;
        proj_info[1].project_name = "Cisco Security";
        proj_info[1].customer_name = "BK";
        proj_info[1].team_member_count = 1;
        proj_info[1].team_members_id.push_back(2);
        project_data.push_back(proj_info[1]);

        emp_to_manager_map[1] = 4;
        emp_to_project_map[1] = 1001; 

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
    void setSalary(struct emp_details *detail, int salary);

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
    int getSalary(struct emp_details *detail);

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
    void viewManagerAndProjectDetails(int emp_id);
    void applyLeave(int emp_id, struct leave_details details);
    map<int, vector<leave_details>>& getLeaveRequest();
    void addReview(int emp_id, struct review_details details);
    map<int, vector<review_details>>& getReviewData();
    vector<EmployeeLog> getAttendanceInfo(int emp_id);
    void addMessage(int emp_id, struct message_details details);
    vector<message_details> getMessage(int emp_id);
    void applyLeaveReq(int emp_id, struct leave_req details);
    map<int, vector<leave_req>>& getPendingLeaveRequest();
    bool validateCredentials(int emp_id, string password);
    void addCredentials(int emp_id, string password);
};

#endif