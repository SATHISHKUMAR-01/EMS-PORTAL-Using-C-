#include "employee.h"
#include "messages.h"

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

void Employee::addEmployee(struct emp_details details){
    employee.push_back(details);
}

void Employee::displayEmployee(){
    cout << "\n       Company --- Employee Details\n";
    for (const auto& emp : employee) {
        cout << BORDER_LINES <<  endl;
        cout << "   Employee Id   : " << emp.emp_id << endl;
        cout << "   Name          : " << emp.name << endl;
        cout << "   Father's Name : " << emp.fatherName << endl;
        cout << "   Date of Birth : " << emp.dob << endl;
        cout << "   Age           : " << emp.age << endl;
        cout << "   Role          : " << emp.role << endl;
        cout << "   Department    : " << emp.department << endl;
        cout << "   Date of Join  : " << emp.dateOfJoin << endl;
        cout << BORDER_LINES <<  endl;
    }
}

void Employee::diplaySpecificEmployee(int emp_id){
    bool dataFound = false;
    cout << "\n     Employee Details - ID : " << emp_id << endl;
    cout << BORDER_LINES <<  endl;
    for (const auto& emp : employee) {
        if (emp_id == emp.emp_id){
            cout << "   Name          : " << emp.name << endl;
            cout << "   Father's Name : " << emp.fatherName << endl;
            cout << "   Date of Birth : " << emp.dob << endl;
            cout << "   Age           : " << emp.age << endl;
            cout << "   Role          : " << emp.role << endl;
            cout << "   Department    : " << emp.department << endl;
            cout << "   Date of Join  : " << emp.dateOfJoin << endl;
            dataFound = true;
            break;
        }
    }
    if(!dataFound){
        cout << "     Employee Data not found !!!  " << endl;
    }
    cout << BORDER_LINES <<  endl;
}

emp_details* Employee::getEmployee(int emp_id){
    for (auto& emp : employee) {
        if (emp_id == emp.emp_id){
            return &emp;
        }
    }
    return nullptr;
}