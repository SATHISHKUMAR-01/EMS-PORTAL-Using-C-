#include "admin.h"
#include "../libraries/messages.h"


void Admin::addManagerData(Employee& emp){
    manager_details details;

    int emp_id, number_of_projects, proj_id, team_members, member_id;

    cout << "Enter the employee ID - ";
    cin  >> emp_id;

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

    emp.saveManagerData(&details);
}

void Admin::updateManagerData(){

}

void Admin::viewManagerDetails(){

}

void Admin::removeManagerData(){

}