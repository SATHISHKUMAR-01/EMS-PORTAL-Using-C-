#include "employee.h"

Employee::Employee(int emp_id, int age, string name, string role, string dob, string fatherName, string department, string dateOfJoin){
    this->emp_id = emp_id;
    this->age = age;
    this->name = name;
    this->role = role;
    this->dob = dob;
    this->fatherName = fatherName;
    this->department = department;
    this->dateOfJoin = dateOfJoin;
}

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

void Employee::setDob(string dob){
    this->dob = dob;
}

void Employee::setFatherName(string fatherName){
    this->fatherName = fatherName;
}

void Employee::setDepartment(string department){
    this->department = department;
}

void Employee::setDateOfJoin(string dateOfJoin){
    this->dateOfJoin = dateOfJoin;
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

string Employee::getDob(){
    return dob;
}

string Employee::getFatherName(){
    return fatherName;
}

string Employee::getDepartment(){
    return department;
}

string Employee::getDateOfJoin(){
    return dateOfJoin;
}