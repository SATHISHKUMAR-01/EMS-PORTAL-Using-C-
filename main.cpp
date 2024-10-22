#include "employee.h"
#include "messages.h"

//g++ -std=c++11 main.cpp && ./a.out
//g++ main.cpp && ./a.out

void frontPage(){
    cout << "\n" << WELCOME_MESSAGE << " " << APP_NAME << endl;
    
    int boxCount = 5;
    int middleArea = (boxCount/2);
    cout << BORDER_LINES <<  endl;
    for(int index = 0; index < boxCount; index++){
        if (index==middleArea){
            cout << "|---          For More Information,        ---|" << endl;
            cout << "|---           Login to Portal             ---|" << endl;
        }else {
            cout << BODY_LINES << endl;
        }
    }
    cout << BORDER_LINES << "\n" << endl;
}

void loginPage(bool *isContinue, bool *isAdminLogin, bool *isEmpLogin){
    string resp;
    cout << "Do you want to continue (Y/N) - ";
    cin >> resp;
    while ((resp != "Y" && resp != "y") && (resp != "N" && resp != "n")){
        cout << "\nWrong input given !!! Enter either y or n - ";
        cin >> resp;
    }
    if (resp == "Y" || resp == "y"){
        *isContinue = true;
        cout << "\nEnter 1 for Employee Login\nEnter 2 for Admin Login\nEnter 3 for Exit\n\nEnter your choice - ";
        cin >> resp;
        while ((resp != "1" && resp != "2" && resp != "3")){
            cout << "\nWrong input given !!! Enter 1 or 2 or 3 - ";
            cin >> resp;
        }
    }else{
        cout << "Exiting..." << endl;
        return;
    }
    cout << "\n" << BORDER_LINES <<  endl;
    if (resp == "1") {
        cout << "       You have selected Employee Login     " << endl;
        *isEmpLogin = true;
    }else if (resp == "2"){
        cout << "       You have selected Admin Login      " << endl;
        *isAdminLogin = true;
    }
    cout << BORDER_LINES <<  endl;
}

void addEmployeeData(Employee emp){
    int emp_id;
    int age;
    string dob;
    string name;
    string role;
    string fatherName;
    string department;
    string dateOfJoin;

    cout << "\nEnter the employee ID : ";
    cin >> emp_id;

    cout << "\nEnter the name of the employee : ";
    cin >> name;

    cout << "\nEnter the father's name : ";
    cin >> fatherName;

    cout << "\nEnter the age : ";
    cin >> age;

    cout << "\nEnter the Date of Birth (DD/MM/YYYY) : ";
    cin >> dob;

    cout << "\nEnter the employee role : ";
    cin >> role;

    cout << "\nEnter the department belongs to : ";
    cin >> department;

    cout << "\nEnter the Date of Join (DD/MM/YYYY) : ";
    cin >> dateOfJoin;
}

void updateEmployeeData(Employee emp){

}

void adminLogin(Employee emp){
    string resp;
    bool addEntry, updateEntry;
    cout <<"\nEnter 1 for adding new employee data\nEnter 2 for update existing employee data\nEnter 3 for Exit\n\nEnter your choice - ";
    cin >> resp;
    while ((resp != "1" && resp != "2" && resp != "3")){
        cout << "\nWrong input given !!! Enter 1 or 2 or 3 - ";
        cin >> resp;
    }
    cout << "\n" << BORDER_LINES <<  endl;
    if (resp == "1") {
        cout << "           Adding new Employee Data     " << endl;
        cout << BORDER_LINES <<  endl;
        addEmployeeData(emp);
    }else if (resp == "2"){
        cout << "           Updating Employee Data    " << endl;
        cout << BORDER_LINES <<  endl;
        updateEmployeeData(emp);
    }
}



int main(){
    Employee emp;
    bool isContinue, isAdminLogin, isEmpLogin;
    isContinue = isAdminLogin = isEmpLogin  = false ;
    frontPage();
    loginPage(&isContinue, &isAdminLogin, &isEmpLogin);
    if (isAdminLogin){
        adminLogin(emp);
    }
    return 0;
}