#include "login.h"
#include "messages.h"

void Login::frontPage(){
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

void Login::loginPage(bool *isContinue, bool *isAdminLogin, bool *isEmpLogin){
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

void Login::employeeLogin(Employee& emp){
    int emp_id;
    string resp;
    cout << "\n" << BORDER_LINES <<  endl;
    cout << "          Welcome to Employee Login" << endl;
    cout << BORDER_LINES <<  endl;
    
    cout << "\nEnter your employee ID : ";
    cin  >> emp_id;
    cout << "\nLoading" << endl;
    sleep(2);
    for (int index = 0 ; index < 3 ; index++){
        sleep(1);
        cout << "." << endl;
    }
    emp_details* details = emp.getEmployee(emp_id);
    
    if (details == nullptr) {
        cout << BORDER_LINES <<  endl;
        cout << "      Employee not found " << endl;
        cout << BORDER_LINES <<  endl;
        return;
    }

    cout << "\nWelcome, " << emp.getName(details) << endl;

    do{
        cout << "\nEnter 1 to view holiday planners\nEnter 2 to view leave balances\nEnter 3 to apply for a leave\nEnter 4 to view payslip\nEnter 5 to view the people in the company\nEnter 6 to exit\n\nEnter your choice - " << endl;
        cin >> resp;

        while ((resp != "1" && resp != "2" && resp != "3" && resp != "4" && resp != "5" && resp != "6")){
            cout << "\nWrong input given !!! Enter 1 or 2 or 3 or 4 or 5 or 6 - ";
            cin >> resp;
        }

    }while(resp != "6");
}

void Login::displayEmployeeData(int emp_id, int age, string name, string dob, string role, string fatherName, string department, string dateOfJoin){
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

void Login::addEmployeeData(Employee& emp){
    int emp_id, age, count;
    string dob, name, role, fatherName, department, dateOfJoin;

    cout << "\nEnter the count of employee data you want to add : ";
    cin >> count;

    emp_details details[count];
    for(int index=0 ; index<count ; index++) {
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
            
        if (resp == "2"){
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
        }

        details[index].emp_id = emp_id;
        details[index].name = name;
        details[index].age = age;
        details[index].fatherName = fatherName;
        details[index].dob = dob;
        details[index].role = role;
        details[index].department = department;
        details[index].dateOfJoin = dateOfJoin;

        emp.addEmployee(details[index]);

        cout << "\n" << BORDER_LINES <<  endl;
        cout << "       Data Saved Successfully !!! " << endl;
        cout << BORDER_LINES <<  endl;
    }
}

void Login::adminLogin(Employee& emp){
    string resp;
    bool addEntry, updateEntry;
    do {
        cout <<"\nEnter 1 to add new employee data\nEnter 2 to update existing employee data\nEnter 3 to view all employee details\nEnter 4 to view specific employee details\nEnter 5 to exit\n\nEnter your choice - ";
        cin >> resp;
        while ((resp != "1" && resp != "2" && resp != "3" && resp != "4" && resp != "5")){
            cout << "\nWrong input given !!! Enter 1 or 2 or 3 or 4 or 5 - ";
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
            emp.updateEmployeeData(emp);
        }else if (resp == "3"){
            cout << "         Displaying all Employee Data    " << endl;
            cout << BORDER_LINES <<  endl;
            emp.displayEmployee();
        }else if (resp == "4"){
            int emp_id;
            cout << "       Displaying specific Employee Data    " << endl;
            cout << BORDER_LINES <<  endl;
            cout << "Enter the employee id : ";
            cin  >> emp_id;
            emp.diplaySpecificEmployee(emp_id);
        }else if (resp == "5"){
            cout << "           Exiting Admin Login    " << endl;
            cout << BORDER_LINES <<  endl;
        }
    }while(resp != "5");
}