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
        "Enter 1 to update employee ID",
        "Enter 2 to update manager name",
        "Enter 3 to add project ID",
        "Enter 4 to remove project ID",
        "Enter 5 to add team member - employee ID",
        "Enter 6 to remove team member - employee ID"
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

    if (resp == 1){
        int new_emp_id;
        cout << "\nEnter the new employee ID : ";
        cin  >> new_emp_id;
        details->emp_id = new_emp_id;
    }else if (resp == 2){
        string new_name;
        cout << "\nEnter the updated name of the manager : ";
        cin  >> new_name;
        details->name = new_name;
    }else if (resp == 3){
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
    }else if (resp == 4){
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
    }else if (resp == 5){
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
    }else if (resp == 6){
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
    for (auto it = manager_info.begin(); it != manager_info.end(); ) {
        if (it->emp_id == emp_id) {
            it = manager_info.erase(it);
        } else {
            ++it;
        }
    }
}