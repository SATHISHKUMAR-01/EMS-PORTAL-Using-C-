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

int main(){
    Employee emp;
    bool isContinue, isAdminLogin, isEmpLogin ;
    string resp;
    frontPage();

    cout << "Do you want to continue (Y/N) - ";
    cin >> resp;
    while ((resp != "Y" && resp != "y") && (resp != "N" && resp != "n")){
        cout << "\nWrong input given !!! Enter either y or n - ";
        cin >> resp;
    }
    if (resp == "Y" || resp == "y"){
        isContinue = true;
        cout << "\nEnter 1 for Employee Login\nEnter 2 for Admin Login\nEnter 3 for Exit\n\nEnter your choice - ";
        cin >> resp;
        while ((resp != "1" && resp != "2" && resp != "3")){
            cout << "\nWrong input given !!! Enter 1 or 2 or 3 - ";
            cin >> resp;
        }
    }
    cout << "\n" << BORDER_LINES <<  endl;
    if (resp == "1") {
        cout << "       You have selected Employee Login     " << endl;
        isEmpLogin = true;
    }else if (resp == "2"){
        cout << "       You have selected Admin Login      " << endl;
        isAdminLogin = true;
    }
    cout << BORDER_LINES <<  endl;

    if (isAdminLogin){
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
            isEmpLogin = true;
        }else if (resp == "2"){
            cout << "           Updating Employee Data    " << endl;
            isAdminLogin = true;
        }
        cout << BORDER_LINES <<  endl;
    }
    
    return 0;
}