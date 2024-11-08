#ifndef ADMIN_H
#define ADMIN_H
#include "../libraries/headers.h"
#include "employee.h"

class Admin : Employee{

    public:
    void addManagerData(Employee& emp);
    void updateManagerData();
    void viewManagerDetails();
    void removeManagerData();

};
#endif