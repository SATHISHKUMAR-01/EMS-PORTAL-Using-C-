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
};
#endif