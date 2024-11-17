#ifndef ADMIN_H
#define ADMIN_H
#include "../libraries/headers.h"
#include "employee.h"

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