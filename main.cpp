#include "employee.h"
#include "messages.h"

//g++ -std=c++11 main.cpp && ./a.out
//g++ main.cpp && ./a.out

#define EDIT_EMP_ID 1

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
    int emp_id, age;
    string dob, name, role, fatherName, department, dateOfJoin;
    string resp;

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

    cout << "\n" << BORDER_LINES <<  endl;
    cout << "      Summary of New Employee Details" << endl;
    cout << BORDER_LINES <<  endl;
    cout << "   Employee Id   : " << emp_id << endl;
    cout << "   Name          : " << name << endl;
    cout << "   Father's Name : " << fatherName << endl;
    cout << "   Date of Birth : " << dob << endl;
    cout << "   Age           : " << age << endl;
    cout << "   Role          : " << role << endl;
    cout << "   Department    : " << department << endl;
    cout << "   Date of Join  : " << dateOfJoin << endl;
    cout << BORDER_LINES <<  endl;

    cout << "\nEnter 1 to save the data\nEnter 2 to edit any value\n\nEnter your choice - ";
    cin >> resp;

    while ((resp != "1" && resp != "2")){
        cout << "\nWrong input given !!! Enter 1 or 2 - ";
        cin >> resp;
    }

    if (resp == "1"){
        cout << "Data Saved" << endl;
    }else if (resp == "2"){
        int editKey;
        cout << "\n" << BORDER_LINES <<  endl;
        cout << "   Which field you want to change ?\n\n";
        cout << "     Enter 1 to edit employee ID" << endl;
        cout << "     Enter 2 to edit name" << endl;
        cout << "     Enter 3 to edit father's name" << endl;
        cout << "     Enter 4 to edit date of birth" << endl;
        cout << "     Enter 5 to edit Age" << endl;
        cout << "     Enter 6 to edit Role" << endl;
        cout << "     Enter 7 to edit Department" << endl;
        cout << "     Enter 8 to edit Date of Join" << endl;
        cout << BORDER_LINES <<  endl;
        cout << "Enter your choice - ";
        cin >> editKey;

        switch (editKey){
            case EDIT_EMP_ID:
                cout << "\nOld employee ID : " << emp_id << endl;
                cout << "Enter the new value : ";
                cin  >> emp_id;
                cout << "Updated Data " << endl;
                break;
            default:
                cout << "Select def ID : " << endl;
                break;
        }
    }
}

void updateEmployeeData(Employee emp){

}

void adminLogin(Employee emp){
    string resp;
    bool addEntry, updateEntry;
    cout <<"\nEnter 1 to add new employee data\nEnter 2 to update existing employee data\nEnter 3 to exit\n\nEnter your choice - ";
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