#ifndef ADMIN_H
#define ADMIN_H
#include "../libraries/headers.h"
#include "employee.h"

#define UPDATE_EMPLOYEE_ID 1
#define UPDATE_MANAGER_NAME 2
#define ADD_PROJECT_ID 3
#define REMOVE_PROJECT_ID 4
#define ADD_TEAM_MEMBER_TO_MANAGER 5
#define REMOVE_TEAM_MEMBER_TO_MANAGER 6

#define UPDATE_PROJECT_ID 1
#define UPDATE_PROJECT_NAME 2
#define UPDATE_CUSTOMER_NAME 3
#define ADD_TEAM_MEMBER_TO_PROJ 4
#define REMOVE_TEAM_MEMBER_TO_PROJ 5

class Admin : Employee{

    public:
    void addManagerData(Employee& emp);
    void updateManagerData(Employee& emp);
    void viewManagerDetails(Employee& emp);
    void removeManagerData(Employee& emp);

    void addProjectData(Employee& emp);
    void updateProjectData(Employee& emp);
    void viewProjectDetails(Employee& emp);
    void removeProjectData(Employee& emp);

    void readCSVAndStore(const string& filename, Employee& emp);
};
#endif