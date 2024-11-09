#include "admin.h"
#include "../libraries/messages.h"


void Admin::addManagerData(Employee& emp){
    manager_details details;

    int emp_id, number_of_projects, proj_id, team_members, member_id;
    string name;

    cout << "Enter the employee ID - ";
    cin  >> emp_id;

    cout << "Enter the manager name - ";
    cin  >> name;

    cout << "Enter the number of project managed - ";
    cin  >> number_of_projects;

    cout << "Add the " << number_of_projects << " project IDs " << endl;
    for (int index = 0 ; index < number_of_projects ; index++){
        cout << "Enter the project " << index + 1 << " id - ";
        cin  >> proj_id;
        details.project_id.push_back(proj_id);
    }

    cout << "Enter the number of employee managed - ";
    cin  >> team_members;

    cout << "Add the " << team_members << " employee IDs " << endl;
    for (int index = 0 ; index < team_members ; index++){
        cout << "Enter the employee " << index + 1 << " id - ";
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
    int emp_id;

    cout << "Enter the employee id of the manager : ";
    cin  >> emp_id;

    manager_details* details = getEmployee(emp_id);

    if (details == nullptr) {
        cout << BORDER_LINES <<  endl;
        cout << "     Manager not found " << endl;
        cout << BORDER_LINES <<  endl;
        return;
    }

    cout << "Which field you want to update or edit ? " << endl;

    string options = {
        "Enter 1 to edit/update employee ID",
        "Enter 2 to "
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
        cout << "Employee IDs are              :  ";
        for (int member_id : manager.team_members_id ) {
            cout << member_id << " ";
        }

        cout << "\n" << BORDER_LINES <<  endl;
    }
}

void Admin::removeManagerData(Employee& emp){

}