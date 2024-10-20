#include "employee.h"

void Employee::setEmpId(int emp_id){
    this->emp_id = emp_id;
}

void Employee::setAge(int age){
    this->age = age;
}

void Employee::setName(string name){
    this->name = name;
}

void Employee::setRole(string role){
    this->role = role;
}

int Employee::getEmpId(){
    return emp_id;
}

int Employee::getAge(){
    return age;
}

string Employee::getName(){
    return name;
}

string Employee::getRole(){
    return role;
}
