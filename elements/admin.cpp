#include "admin.h"
#include "../libraries/messages.h"


void Admin::addManagerData(Employee& emp){
    manager_details details;

    int emp_id, number_of_projects, proj_id, team_members, member_id;
    string name;

    cout << "Enter the employee ID   : ";
    cin  >> emp_id;

    cout << "Enter the manager name  : ";
    cin  >> name;

    cout << "\nEnter the number of project managed : ";
    cin  >> number_of_projects;

    cout << "\n<----- Add the " << number_of_projects << " project IDs ----->\n" << endl;
    for (int index = 0 ; index < number_of_projects ; index++){
        cout << "Enter the project " << index + 1 << " id  : ";
        cin  >> proj_id;
        details.project_id.push_back(proj_id);
    }

    cout << "\nEnter the number of employee managed : ";
    cin  >> team_members;

    cout << "\n<----- Add the " << team_members << " employee IDs ----->\n" << endl;
    for (int index = 0 ; index < team_members ; index++){
        cout << "Enter the employee " << index + 1 << " id : ";
        cin  >> member_id;
        details.team_members_id.push_back(member_id);
    }

    details.emp_id = emp_id;
    details.number_of_projects = number_of_projects;
    details.team_member_count = team_members;
    details.name = name;

    emp.saveManagerData(details);
}

void Admin::updateManagerData(Employee& emp){
    int emp_id, resp;

    cout << "Enter the employee id of the manager : ";
    cin  >> emp_id;

    manager_details* details = emp.getSpecificManagerData(emp_id);

    if (details == nullptr) {
        cout << BORDER_LINES <<  endl;
        cout << "     Manager not found " << endl;
        cout << BORDER_LINES <<  endl;
        return;
    }

    cout << "\nWhich field you want to update or edit ? \n" << endl;

    string options[] = {
        "Enter 01 to update employee ID",
        "Enter 02 to update manager name",
        "Enter 03 to add project ID",
        "Enter 04 to remove project ID",
        "Enter 05 to add team member - employee ID",
        "Enter 06 to remove team member - employee ID"
    };

    int numOptions = sizeof(options)/sizeof(options[0]);

    for (int index = 0 ; index < numOptions; index++){
        cout << options[index] << endl;
    }

    cout <<"\n\nEnter your choice - ";
    cin >> resp;
    
    while ( (resp < 1 || resp > numOptions)){
        cout << "\nWrong input given !!! Enter value from 1 to "<< numOptions << " - ";
        cin >> resp;
    }

    if (resp == UPDATE_EMPLOYEE_ID){
        int new_emp_id;
        cout << "\nEnter the new employee ID : ";
        cin  >> new_emp_id;
        details->emp_id = new_emp_id;
    }else if (resp == UPDATE_MANAGER_NAME){
        string new_name;
        cout << "\nEnter the updated name of the manager : ";
        cin  >> new_name;
        details->name = new_name;
    }else if (resp == ADD_PROJECT_ID){
        int count;
        cout << "\nEnter the number of projects you want to add : ";
        cin  >> count;
        int project_id;
        for(int index = 0 ; index < count ; index++){
            cout << "Enter the project ID to add : ";
            cin  >> project_id;
            details->project_id.push_back(project_id);
        }
        details->number_of_projects += count;
    }else if (resp == REMOVE_PROJECT_ID){
        int count;
        cout << "\nEnter the number of projects you want to remove : ";
        cin  >> count;
        int project_id;
        for(int index = 0 ; index < count ; index++){
            cout << "Enter the project ID to remove : ";
            cin  >> project_id;
            details->project_id.erase(remove(details->project_id.begin(), details->project_id.end(), project_id), details->project_id.end());
        }
        details->number_of_projects -= count;
    }else if (resp == ADD_TEAM_MEMBER_TO_MANAGER){
        int count;
        cout << "\nEnter the number of team members you want to add : ";
        cin  >> count;
        int emp_id;
        for(int index = 0 ; index < count ; index++){
            cout << "Enter the Employee ID to add : ";
            cin  >> emp_id;
            details->team_members_id.push_back(emp_id);
        }
        details->team_member_count+=count;
    }else if (resp == REMOVE_TEAM_MEMBER_TO_MANAGER){
        int count;
        cout << "\nEnter the number of team members you want to remove : ";
        cin  >> count;
        int emp_id;
        for(int index = 0 ; index < count ; index++){
            cout << "Enter the Employee ID to remove : ";
            cin  >> emp_id;
            details->team_members_id.erase(remove(details->team_members_id.begin(), details->team_members_id.end(), emp_id), details->team_members_id.end());
        }
        details->team_member_count-=count;
    }
}

void Admin::viewManagerDetails(Employee& emp){
    vector<manager_details> &manager_info = emp.getManagerData();

    for (auto& manager : manager_info) {
        cout << "\n" << BORDER_LINES <<  endl;
        cout << "Employee ID                 :  " << manager.emp_id << endl;
        cout << "Manager Name                :  " << manager.name << endl;
        cout << "\nNumber of projects managed  :  " << manager.number_of_projects << endl;
        cout << "Project IDs are             :  ";
        for (int project_id : manager.project_id ) {
            cout << project_id << " ";
        }
        
        cout << "\n\nNumber of team members      :  " << manager.number_of_projects << endl;
        cout << "Employee IDs are            :  ";
        for (int member_id : manager.team_members_id ) {
            cout << member_id << " ";
        }

        cout << "\n" << BORDER_LINES <<  endl;
    }
}

void Admin::removeManagerData(Employee& emp){
    int emp_id;
    cout << "Enter the employee id of the manager to remove : ";
    cin  >> emp_id;
    vector<manager_details> &manager_info = emp.getManagerData();
    bool mngr_found = false;
    for (auto it = manager_info.begin(); it != manager_info.end(); ) {
        if (it->emp_id == emp_id) {
            it = manager_info.erase(it);
            mngr_found = true;
            cout << "\n<----- Manager Data Removed Successfully ----->\n" << endl;
        } else {
            ++it;
        }
    }
    if (!mngr_found){
        cout << "\n<----- Manager Details not found ----->\n" << endl;
    }
}

void Admin::addProjectData(Employee& emp){
    project_details details;

    int project_id, team_members, member_id;
    string project_name, customer_name;

    cout << "Enter the Project ID     : ";
    cin  >> project_id;

    cout << "Enter the Project name   : ";
    cin  >> project_name;

    cout << "Enter the Customer name  : ";
    cin  >> customer_name;

    cout << "\nEnter the team members count  : ";
    cin  >> team_members;

    cout << "\n<----- Add the " << team_members << " employee IDs ----->\n" << endl;
    for (int index = 0 ; index < team_members ; index++){
        cout << "Enter the employee " << index + 1 << " id : ";
        cin  >> member_id;
        details.team_members_id.push_back(member_id);
    }

    details.project_id = project_id;
    details.project_name = project_name;
    details.customer_name = customer_name;
    details.team_member_count = team_members;
    
    emp.saveProjectData(details);
}

void Admin::updateProjectData(Employee& emp){
    int proj_id, resp;

    cout << "Enter the project id of the project : ";
    cin  >> proj_id;

    project_details* details = emp.getSpecificProjectData(proj_id);

    if (details == nullptr) {
        cout << BORDER_LINES <<  endl;
        cout << "     Project not found " << endl;
        cout << BORDER_LINES <<  endl;
        return;
    }

    cout << "\nWhich field you want to update or edit ? \n" << endl;

    string options[] = {
        "Enter 1 to update project ID",
        "Enter 2 to update project name",
        "Enter 3 to update customer name",
        "Enter 4 to add team member - employee ID",
        "Enter 5 to remove team member - employee ID"
    };

    int numOptions = sizeof(options)/sizeof(options[0]);

    for (int index = 0 ; index < numOptions; index++){
        cout << options[index] << endl;
    }

    cout <<"\n\nEnter your choice - ";
    cin >> resp;
    
    while ( (resp < 1 || resp > numOptions)){
        cout << "\nWrong input given !!! Enter value from 1 to "<< numOptions << " - ";
        cin >> resp;
    }

    if (resp == UPDATE_PROJECT_ID){
        int new_proj_id;
        cout << "\nEnter the updated project ID : ";
        cin  >> new_proj_id;
        details->project_id = new_proj_id;
    }else if (resp == UPDATE_PROJECT_NAME){
        string new_name;
        cout << "\nEnter the updated name of the project : ";
        cin  >> new_name;
        details->project_name = new_name;
    }else if (resp == UPDATE_CUSTOMER_NAME){
        string new_customer_name;
        cout << "\nEnter the updated name of the customer : ";
        cin  >> new_customer_name;
        details->customer_name = new_customer_name;
    }else if (resp == ADD_TEAM_MEMBER_TO_PROJ){
        int count;
        cout << "\nEnter the number of team members you want to add : ";
        cin  >> count;
        int emp_id;
        for(int index = 0 ; index < count ; index++){
            cout << "Enter the Employee ID to add : ";
            cin  >> emp_id;
            details->team_members_id.push_back(emp_id);
        }
        details->team_member_count+=count;
    }else if (resp == REMOVE_TEAM_MEMBER_TO_PROJ){
        int count;
        cout << "\nEnter the number of team members you want to remove : ";
        cin  >> count;
        int emp_id;
        for(int index = 0 ; index < count ; index++){
            cout << "Enter the Employee ID to remove : ";
            cin  >> emp_id;
            details->team_members_id.erase(remove(details->team_members_id.begin(), details->team_members_id.end(), emp_id), details->team_members_id.end());
        }
        details->team_member_count-=count;
    }
}

void Admin::viewProjectDetails(Employee& emp){
    vector<project_details> &project_info = emp.getProjectData();

    for (auto& project : project_info) {
        cout << "\n" << BORDER_LINES <<  endl;
        cout << "Project ID                  :  " << project.project_id << endl;
        cout << "Project Name                :  " << project.project_name << endl;
        cout << "Customer Name               :  " << project.customer_name << endl;
        
        cout << "\nNumber of team members      :  " << project.team_member_count << endl;
        cout << "Employee IDs are            :  ";
        for (int member_id : project.team_members_id ) {
            cout << member_id << " ";
        }

        cout << "\n" << BORDER_LINES <<  endl;
    }
}

void Admin::removeProjectData(Employee& emp){
    int project_id;
    cout << "Enter the project id of the project to remove : ";
    cin  >> project_id;
    vector<project_details> &project_info = emp.getProjectData();
    bool proj_found = false;
    for (auto it = project_info.begin(); it != project_info.end(); ) {
        if (it->project_id == project_id) {
            it = project_info.erase(it);
            proj_found = true;
            cout << "\n<----- Project Data Removed Successfully ----->\n" << endl;
        } else {
            ++it;
        }
    }
    if (!proj_found){
        cout << "\n<----- Project Details not found ----->\n" << endl;
    }
}

void Admin::readCSVAndStore(const string& filename, Employee& emp){
    
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        return;
    }
    string line;
    getline(file, line);

    cout << string(58, '-') << endl;
    cout << left << setw(10) << "EMP_ID"
    << setw(12) << "NAME"
    << setw(12) << "DATE"
    << setw(12) << "LOGIN_TIME"
    << setw(12) << "LOGOUT_TIME" << endl;
    cout << string(58, '-') << endl;
    
    while (getline(file, line)) {
        stringstream ss(line);
        string emp_id_str, name, date, login_time, logout_time;
        getline(ss, emp_id_str, ',');
        getline(ss, name, ',');
        getline(ss, date, ',');
        getline(ss, login_time, ',');
        getline(ss, logout_time, ',');
        int emp_id = stoi(emp_id_str);
        cout << left << setw(10) << emp_id_str
        << setw(12) << name
        << setw(12) << date
        << setw(12) << login_time
        << setw(12) << logout_time << endl;
        // Create an EmployeeLog object and add it to the appropriate map entry
        EmployeeLog log(emp_id, name, date, login_time, logout_time);
        emp.employee_login[emp_id].push_back(log);
    }
    cout <<  "\n <--- The above details have been updated successfully --->" << endl;
    file.close();
}