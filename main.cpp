#include "employee.h"
#include "messages.h"

//g++ -std=c++11 main.cpp && ./a.out
//g++ employee.cpp main.cpp && ./a.out

#define EDIT_EMP_ID 1
#define EDIT_NAME 2
#define EDIT_FATHER_NAME 3
#define EDIT_DOB 4
#define EDIT_AGE 5
#define EDIT_ROLE 6
#define EDIT_DEPARTMENT 7
#define EDIT_DATE_OF_JOIN 8

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

void displayEmployeeData(int emp_id, int age, string name, string dob, string role, string fatherName, string department, string dateOfJoin){
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

    displayEmployeeData(emp_id,age,name,dob,role,fatherName,department,dateOfJoin);

    cout << "\nEnter 1 to save the data\nEnter 2 to edit any value\n\nEnter your choice - ";
    cin >> resp;

    while ((resp != "1" && resp != "2")){
        cout << "\nWrong input given !!! Enter 1 or 2 - ";
        cin >> resp;
    }

    if (resp == "1"){
        cout << "\n" << BORDER_LINES <<  endl;
        cout << "     Data Saved Successfully !!! " << endl;
        cout << BORDER_LINES <<  endl;
    }else if (resp == "2"){
        do {
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
                    break;
                case EDIT_NAME:
                    cout << "\nOld Name : " << name << endl;
                    cout << "Enter the new value : ";
                    cin  >> name;
                    break;
                case EDIT_FATHER_NAME:
                    cout << "\nOld Father's name : " << fatherName << endl;
                    cout << "Enter the new value : ";
                    cin  >> fatherName;
                    break;
                case EDIT_DOB:
                    cout << "\nOld Date of Birth : " << dob << endl;
                    cout << "Enter the new value : ";
                    cin  >> dob;
                    break;
                case EDIT_AGE:
                    cout << "\nOld Age : " << age << endl;
                    cout << "Enter the new value : ";
                    cin  >> age;
                    break;
                case EDIT_ROLE:
                    cout << "\nOld Role : " << role << endl;
                    cout << "Enter the new value : ";
                    cin  >> role;
                    break;
                case EDIT_DEPARTMENT:
                    cout << "\nOld Department : " << department << endl;
                    cout << "Enter the new value : ";
                    cin  >> department;
                    break;
                case EDIT_DATE_OF_JOIN:
                    cout << "\nOld Date Of Join : " << dateOfJoin << endl;
                    cout << "Enter the new value : ";
                    cin  >> dateOfJoin;
                    break;
                default:
                    cout << "Wrong Value Entered" << endl;
                    break;
            }
            displayEmployeeData(emp_id,age,name,dob,role,fatherName,department,dateOfJoin);
            cout << "\nEnter 1 to save the data\nEnter 2 to edit any value\n\nEnter your choice - ";
            cin >> resp;

            while ((resp != "1" && resp != "2")){
                cout << "\nWrong input given !!! Enter 1 or 2 - ";
                cin >> resp;
            }
        }while(resp == "2");

        emp.setEmpId(emp_id);
        emp.setAge(age);
        emp.setName(name);
        emp.setRole(role);
        emp.setFatherName(fatherName);
        emp.setDepartment(department);
        emp.setDateOfJoin(dateOfJoin);
        emp.setDob(dob);

        cout << "\n" << BORDER_LINES <<  endl;
        cout << "         Data Saved Successfully !!!" << endl;
        cout << BORDER_LINES <<  endl;
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

void employeeLogin(Employee emp){
    cout << "\n" << BORDER_LINES <<  endl;
    cout << "          Welcome to Employee Login" << endl;
    cout << BORDER_LINES <<  endl;
    int emp_id;
    cout << "\nEnter your employee ID : ";
    cin  >> emp_id;
    cout << "\nLoading" << endl;
    sleep(2);
    for (int index = 0 ; index < 3 ; index++){
        sleep(1);
        cout << "." << endl;
    }
    if(emp.getEmpId() == emp_id){
        cout << "Value present";
    }else{
        cout << "Value not present";
    }
}

int main(){
    Employee emp(123, 22, "Raj Kumar", "Intern", "09/09/1999", "Arun", "Engineering", "08/04/2023");
    bool isContinue, isAdminLogin, isEmpLogin;
    isContinue = isAdminLogin = isEmpLogin  = false ;
    frontPage();
    loginPage(&isContinue, &isAdminLogin, &isEmpLogin);
    if (isAdminLogin){
        adminLogin(emp);
    } else if (isEmpLogin){
        employeeLogin(emp);
    }
    return 0;
}