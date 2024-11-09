#include "employee.h"
#include "../libraries/messages.h"

void Employee::setEmpId(struct emp_details *detail, int emp_id){
    detail->emp_id = emp_id;
}

void Employee::setAge(struct emp_details *detail, int age){
    detail->age = age;
}

void Employee::setName(struct emp_details *detail, string name){
    detail->name = name;
}

void Employee::setRole(struct emp_details *detail, string role){
    detail->role = role;
}

void Employee::setDob(struct emp_details *detail, string dob){
    detail->dob = dob;
}

void Employee::setFatherName(struct emp_details *detail, string fatherName){
    detail->fatherName = fatherName;
}

void Employee::setDepartment(struct emp_details *detail, string department){
    detail->department = department;
}

void Employee::setDateOfJoin(struct emp_details *detail, string dateOfJoin){
    detail->dateOfJoin = dateOfJoin;
}

void Employee::setInternWorkFromHome(int workFromHome){
    defaultInternWFH = workFromHome;
}

void Employee::setSeniorWorkFromHome(int workFromHome){
    defaultSeniorWFH = workFromHome;
}

void Employee::setManagerWorkFromHome(int workFromHome){
    defaultManagerWFH = workFromHome;
}

void Employee::setVacationLeave(int vacationLeave){
    defaultVacationLeave = vacationLeave;
}

void Employee::setAnnualLeave(int annualLeave){
    defaultAnnualLeave = annualLeave;
}

void Employee::setTeamOff(int teamOff){
    defaultTeamOff = teamOff;
}

void Employee::setPaternityLeave(int paternityLeave){
    defaultPaternityLeave = paternityLeave;
}

void Employee::setMaternityLeave(int maternityLeave){
    defaultMaternityLeave = maternityLeave;
}

void Employee::setMarriageLeave(int marriageLeave){
    defaultMarriageLeave = marriageLeave;
}

void Employee::setSex(struct emp_details *detail, string sex){
    detail->sex = sex;
}

int Employee::getEmpId(struct emp_details *detail){
    return detail->emp_id;
}

int Employee::getAge(struct emp_details *detail){
    return detail->age;
}

string Employee::getName(struct emp_details *detail){
    return detail->name;
}

string Employee::getRole(struct emp_details *detail){
    return detail->role;
}

string Employee::getDob(struct emp_details *detail){
    return detail->dob;
}

string Employee::getFatherName(struct emp_details *detail){
    return detail->fatherName;
}

string Employee::getDepartment(struct emp_details *detail){
    return detail->department;
}

string Employee::getDateOfJoin(struct emp_details *detail){
    return detail->dateOfJoin;
}

int Employee::getInternWorkFromHome(){
    return defaultInternWFH;
}

int Employee::getSeniorWorkFromHome(){
    return defaultSeniorWFH;
}

int Employee::getManagerWorkFromHome(){
    return defaultManagerWFH;
}

int Employee::getVacationLeave(){
    return defaultVacationLeave;
}

int Employee::getAnnualLeave(){
    return defaultAnnualLeave;
}

int Employee::getTeamOff(){
    return defaultTeamOff;
}

int Employee::getPaternityLeave(){
    return defaultPaternityLeave;
}

int Employee::getMaternityLeave(){
    return defaultMaternityLeave;
}

int Employee::getMarriageLeave(){
    return defaultMarriageLeave;
}

string Employee::getSex(struct emp_details *detail){
    return detail->sex;
}

void Employee::addEmployee(struct emp_details details){
    employee.push_back(details);
}

void Employee::displayEmployee(){
    cout << "\n       Company --- Employee Details\n";
    for (auto& emp : employee) {
        cout << BORDER_LINES <<  endl;
        cout << "   Employee Id   : " << getEmpId(&emp) << endl;
        cout << "   Name          : " << getName(&emp) << endl;
        cout << "   Sex           : " << getSex(&emp) << endl;
        cout << "   Father's Name : " << getFatherName(&emp) << endl;
        cout << "   Date of Birth : " << getDob(&emp) << endl;
        cout << "   Age           : " << getAge(&emp) << endl;
        cout << "   Role          : " << getRole(&emp) << endl;
        cout << "   Department    : " << getDepartment(&emp) << endl;
        cout << "   Date of Join  : " << getDateOfJoin(&emp) << endl;
        cout << BORDER_LINES <<  endl;
    }
}

void Employee::diplaySpecificEmployee(int emp_id){
    bool dataFound = false;
    cout << "\n     Employee Details - ID : " << emp_id << endl;
    cout << BORDER_LINES <<  endl;
    for (auto& emp : employee) {
        if (emp_id == getEmpId(&emp) ){
            cout << "   Name          : " << getName(&emp) << endl;
            cout << "   Sex           : " << getSex(&emp) << endl;
            cout << "   Father's Name : " << getFatherName(&emp) << endl;
            cout << "   Date of Birth : " << getDob(&emp) << endl;
            cout << "   Age           : " << getAge(&emp) << endl;
            cout << "   Role          : " << getRole(&emp) << endl;
            cout << "   Department    : " << getDepartment(&emp) << endl;
            cout << "   Date of Join  : " << getDateOfJoin(&emp) << endl;
            dataFound = true;
            break;
        }
    }
    if(!dataFound){
        cout << "     Employee Data not found !!!  " << endl;
    }
    cout << BORDER_LINES <<  endl;
}

void Employee::updateEmployeeData(Employee& emp){
    int emp_id;
    string resp;
    cout << "Enter the employee id : ";
    cin  >> emp_id;

    emp_details* details = emp.getEmployee(emp_id);
    
    if (details == nullptr) {
        cout << BORDER_LINES <<  endl;
        cout << "      Employee not found " << endl;
        cout << BORDER_LINES <<  endl;
        return;
    }

    do {
        int editKey;
        int new_emp_id, new_age;
        string new_dob, new_name, new_role, new_fatherName, new_department, new_dateOfJoin;
        cout << "\n" << BORDER_LINES <<  endl;
        cout << "   Which field you want to update ?\n\n";
        cout << "     Enter 1 to update employee ID" << endl;
        cout << "     Enter 2 to update name" << endl;
        cout << "     Enter 3 to update father's name" << endl;
        cout << "     Enter 4 to update date of birth" << endl;
        cout << "     Enter 5 to update Age" << endl;
        cout << "     Enter 6 to update Role" << endl;
        cout << "     Enter 7 to update Department" << endl;
        cout << "     Enter 8 to update Date of Join" << endl;
        cout << BORDER_LINES <<  endl;
        cout << "Enter your choice - ";
        cin >> editKey;
        cout << "\nEnter the new value : ";
        switch (editKey){
            case EDIT_EMP_ID:
                cin  >> new_emp_id;
                setEmpId(details,new_emp_id);
                break;
            case EDIT_NAME:
                cin  >> new_name;
                setName(details,new_name);
                break;
            case EDIT_FATHER_NAME:
                cin  >> new_fatherName;
                setFatherName(details,new_fatherName);
                break;
            case EDIT_DOB:
                cin  >> new_dob;
                setDob(details,new_dob);
                break;
            case EDIT_AGE:
                cin  >> new_age;
                setAge(details,new_age);
                break;
            case EDIT_ROLE:
                cin  >> new_role;
                setRole(details,new_role);
                break;
            case EDIT_DEPARTMENT:
                cin  >> new_department;
                setDepartment(details,new_department);
                break;
            case EDIT_DATE_OF_JOIN:
                cin  >> new_dateOfJoin;
                setDateOfJoin(details,new_dateOfJoin);
                break;
            default:
                cout << "Wrong Value Entered" << endl;
                break;
        }
        cout << "\nEnter 1 to save the data\nEnter 2 to edit any other value\n\nEnter your choice - ";
        cin >> resp;
        while ((resp != "1" && resp != "2")){
            cout << "\nWrong input given !!! Enter 1 or 2 - ";
            cin >> resp;
        }
    }while(resp == "2");
}

emp_details* Employee::getEmployee(int emp_id){
    for (auto& emp : employee) {
        if (emp_id == getEmpId(&emp)){
            return &emp;
        }
    }
    return nullptr;
}

bool Employee::isAdmin(int emp_id){
    for (auto& id : adminId) {
        if (id == emp_id){
            return true;
        }
    }
    return false;
}

void Employee::addAdminId(int id){
    adminId.push_back(id);
}

void Employee::grantLeaveToEmployee(){
    string resp;
    int internWorkFromHome, seniorWorkFromHome, managerWorkFromHome, vacationLeave, annualLeave, teamOff, paternityLeave, maternityLeave, marriageLeave;
    leaveData leave;
    do{
        cout << "\n" << BORDER_LINES <<  endl;
        cout << "             Leave Operations   " << endl;
        cout << BORDER_LINES <<  endl;

        cout << "\nEnter 1 to set default leave count for all leave types\nEnter 2 to grant default leaves for all employees\nEnter 3 to grant default leaves for specific employee\nEnter 4 to grant specific leave type to an employee\nEnter 5 to grant specific leave type to all employees\nEnter 6 to exit\n\nEnter your choice - ";
        cin >> resp;

        while ((resp != "1" && resp != "2" && resp != "3" && resp != "4" && resp != "5" && resp != "6")){
            cout << "\nWrong input given !!! Enter 1 or 2 or 3 or 4 or 5 or 6 - ";
            cin >> resp;
        }

        if(resp == "1"){
            cout << "\n" << BORDER_LINES <<  endl;
            cout << "Adding default leave count for all leave types" << endl;
            cout << BORDER_LINES <<  endl;

            cout << "\nEnter the work from home(WFH) count for Intern   -  ";
            cin  >> internWorkFromHome;
            cout << "\nEnter the work from home(WFH) count for Senior   -  ";
            cin  >> seniorWorkFromHome;
            cout << "\nEnter the work from home(WFH) count for Manager  -  ";
            cin  >> managerWorkFromHome;
            cout << "\nEnter the vacation leave count      -  ";
            cin  >> vacationLeave;
            cout << "\nEnter the annual leave count        -  ";
            cin  >> annualLeave;
            cout << "\nEnter the team time off count       -  ";
            cin  >> teamOff;
            cout << "\nEnter the paternity leave count     -  ";
            cin  >> paternityLeave;
            cout << "\nEnter the maternity leave count     -  ";
            cin  >> maternityLeave;
            cout << "\nEnter the marriage leave count      -  ";
            cin  >> marriageLeave;

            setInternWorkFromHome(internWorkFromHome);
            setSeniorWorkFromHome(seniorWorkFromHome);
            setManagerWorkFromHome(managerWorkFromHome);
            setAnnualLeave(annualLeave);
            setVacationLeave(vacationLeave);
            setTeamOff(teamOff);
            setPaternityLeave(paternityLeave);
            setMaternityLeave(maternityLeave);
            setMarriageLeave(marriageLeave);

        }else if (resp == "2"){
            cout << "\n" << BORDER_LINES <<  endl;
            cout << "   Granting default leave to all employees " << endl;
            cout << BORDER_LINES <<  endl;
            leaveData leaveDetails;
            for (auto& emp : employee) {
                int emp_id = getEmpId(&emp);
                string role = getRole(&emp);
                string sex = getSex(&emp);
                if (LeaveMap.find(emp_id) != LeaveMap.end()){
                    cout << "   Default Leave Already Granted for ID -  " << emp_id << endl;
                    continue;
                }

                if(role == "Intern"){
                    leaveDetails.workFromHome = defaultInternWFH;
                }else if(role == "Senior"){
                    leaveDetails.workFromHome = defaultSeniorWFH;
                }else if(role == "Mananger"){
                    leaveDetails.workFromHome = defaultManagerWFH;
                }
                leaveDetails.annualLeave = defaultAnnualLeave;
                leaveDetails.vacationLeave = defaultVacationLeave;
                leaveDetails.teamOff = defaultTeamOff;

                if(sex == "Male"){
                    leaveDetails.paternityLeave = defaultPaternityLeave;
                    leaveDetails.maternityLeave = 0;
                }else if(sex == "Female"){
                    leaveDetails.maternityLeave = defaultMaternityLeave;
                    leaveDetails.paternityLeave = 0;
                }
                leaveDetails.marriageLeave = defaultMarriageLeave;

                LeaveMap[emp_id] = leaveDetails;
                cout << "   Default Leave Granted for ID -  " << emp_id << endl;
            }
            cout << BORDER_LINES <<  endl;
            cout << "       Completed Sucessfully !!! " << endl;
        }else if (resp == "3"){
            cout << "\n" << BORDER_LINES <<  endl;
            cout << "   Granting default leave to specific employee " << endl;
            cout << BORDER_LINES <<  endl;
            int emp_id;
            cout << "Enter the employee ID : ";
            cin  >> emp_id;
            leaveData leaveDetails;
            emp_details* details = getEmployee(emp_id);
            bool employeeFound = true;
            if (details == nullptr) {
                cout << BORDER_LINES <<  endl;
                cout << "      Employee not found " << endl;
                cout << BORDER_LINES <<  endl;
                employeeFound = false;
            }

            if(employeeFound){
                if(getRole(details) == "Intern"){
                    leaveDetails.workFromHome = defaultInternWFH;
                }else if(getRole(details) == "Senior"){
                    leaveDetails.workFromHome = defaultSeniorWFH;
                }else if(getRole(details) == "Mananger"){
                    leaveDetails.workFromHome = defaultManagerWFH;
                }
                leaveDetails.annualLeave = defaultAnnualLeave;
                leaveDetails.vacationLeave = defaultVacationLeave;
                leaveDetails.teamOff = defaultTeamOff;

                if(getRole(details) == "Male"){
                    leaveDetails.paternityLeave = defaultPaternityLeave;
                }else if(getRole(details) == "Female"){
                    leaveDetails.maternityLeave = defaultMaternityLeave;
                }
                leaveDetails.marriageLeave = defaultMarriageLeave;

                LeaveMap[emp_id] = leaveDetails;
                cout << BORDER_LINES <<  endl;
                cout << "   Default Leave Granted for ID -  " << emp_id << endl;
                cout << "      Completed Sucessfully !!! " << endl;
                cout << BORDER_LINES <<  endl;
            }else {
                cout << BORDER_LINES <<  endl;
                cout << "       Operation failed !!! " << endl;
                cout << BORDER_LINES <<  endl;
            }
        }else if (resp == "4"){
            cout << "\n" << BORDER_LINES <<  endl;
            cout << "   Granting specific leave to specific employee " << endl;
            cout << BORDER_LINES <<  endl;

            int choice,count,emp_id;
            cout << "\nChoose the leave type from the list " << endl;
            cout << "\nEnter 1 to choose work from home " << endl;
            cout << "Enter 2 to choose annual leave " << endl;
            cout << "Enter 3 to choose vacation leave " << endl;
            cout << "Enter 4 to choose team time off" << endl;
            cout << "Enter 5 to choose maternity leave " << endl;
            cout << "Enter 6 to choose paternity leave" << endl;
            cout << "Enter 7 to choose marriage leave" << endl;
            cout << "Enter your choice - ";
            cin >> choice;

            cout << "\nEnter the employee ID : ";
            cin  >> emp_id;
            leaveData *leaveHistory = &LeaveMap.at(emp_id);
            cout << "\n" << BORDER_LINES <<  endl;
            switch(choice){
                case ADD_WFH:
                    cout << "     Selected Leave Type - Work from home " << endl;
                    cout <<  BORDER_LINES <<  endl;
                    cout << "\nEnter the count of additional leave you want to add : ";
                    cin  >> count;
                    leaveHistory->workFromHome+=count;
                    break;
                case ADD_ANNUAL_LEAVE:
                    cout << "     Selected Leave Type - Annual Leave " << endl;
                    cout <<  BORDER_LINES <<  endl;
                    cout << "\nEnter the count of additional leave you want to add : ";
                    cin  >> count;
                    leaveHistory->annualLeave+=count;
                    break;
                case ADD_VACATION_LEAVE:
                    cout << "     Selected Leave Type - Vacation Leave " << endl;
                    cout <<  BORDER_LINES <<  endl;
                    cout << "\nEnter the count of additional leave you want to add : ";
                    cin  >> count;
                    leaveHistory->vacationLeave+=count;
                    break;
                case ADD_TEAM_OFF:
                    cout << "     Selected Leave Type - Team Time Off " << endl;
                    cout <<  BORDER_LINES <<  endl;
                    cout << "\nEnter the count of additional leave you want to add : ";
                    cin  >> count;
                    leaveHistory->teamOff+=count;
                    break;
                case ADD_MATERNITY_LEAVE:
                    cout << "     Selected Leave Type - Maternity Leave " << endl;
                    cout <<  BORDER_LINES <<  endl;
                    cout << "\nEnter the count of additional leave you want to add : ";
                    cin  >> count;
                    leaveHistory->maternityLeave+=count;
                    break;
                case ADD_PATERNITY_LEAVE:
                    cout << "     Selected Leave Type - Paternity Leave " << endl;
                    cout <<  BORDER_LINES <<  endl;
                    cout << "\nEnter the count of additional leave you want to add : ";
                    cin  >> count;
                    leaveHistory->paternityLeave+=count;
                    break;
                case ADD_MARRIAGE_LEAVE:
                    cout << "     Selected Leave Type - Marriage Leave " << endl;
                    cout <<  BORDER_LINES <<  endl;
                    cout << "\nEnter the count of additional leave you want to add : ";
                    cin  >> count;
                    leaveHistory->marriageLeave+=count;
                    break;
                default:
                    cout << " Wrong Type !!! " << endl;
                    cout <<  BORDER_LINES <<  endl;
                    break;
            }

        }else if (resp == "5"){
            cout << "\n" << BORDER_LINES <<  endl;
            cout << "   Granting specific leave to all employee " << endl;
            cout << BORDER_LINES <<  endl;
            int choice,count;
            cout << "\nChoose the leave type from the list " << endl;
            cout << "\nEnter 1 to choose work from home " << endl;
            cout << "Enter 2 to choose annual leave " << endl;
            cout << "Enter 3 to choose vacation leave " << endl;
            cout << "Enter 4 to choose team time off" << endl;
            cout << "Enter 5 to choose maternity leave " << endl;
            cout << "Enter 6 to choose paternity leave" << endl;
            cout << "Enter 7 to choose marriage leave" << endl;
            cout << "Enter your choice - ";
            cin >> choice;
            
            cout << "\n" << BORDER_LINES <<  endl;
            switch(choice){
                case ADD_WFH:
                    cout << "     Selected Leave Type - Work from home " << endl;
                    cout <<  BORDER_LINES <<  endl;
                    cout << "\nEnter the count of additional leave you want to add : ";
                    cin  >> count;
                    addExtraLeaveToAll(ADD_WFH,count);
                    break;
                case ADD_ANNUAL_LEAVE:
                    cout << "     Selected Leave Type - Annual Leave " << endl;
                    cout <<  BORDER_LINES <<  endl;
                    cout << "\nEnter the count of additional leave you want to add : ";
                    cin  >> count;
                    addExtraLeaveToAll(ADD_ANNUAL_LEAVE,count);
                    break;
                case ADD_VACATION_LEAVE:
                    cout << "     Selected Leave Type - Vacation Leave " << endl;
                    cout <<  BORDER_LINES <<  endl;
                    cout << "\nEnter the count of additional leave you want to add : ";
                    cin  >> count;
                    addExtraLeaveToAll(ADD_VACATION_LEAVE,count);
                    break;
                case ADD_TEAM_OFF:
                    cout << "     Selected Leave Type - Team Time Off " << endl;
                    cout <<  BORDER_LINES <<  endl;
                    cout << "\nEnter the count of additional leave you want to add : ";
                    cin  >> count;
                    addExtraLeaveToAll(ADD_TEAM_OFF,count);
                    break;
                case ADD_MATERNITY_LEAVE:
                    cout << "     Selected Leave Type - Maternity Leave " << endl;
                    cout <<  BORDER_LINES <<  endl;
                    cout << "\nEnter the count of additional leave you want to add : ";
                    cin  >> count;
                    addExtraLeaveToAll(ADD_MATERNITY_LEAVE,count);
                    break;
                case ADD_PATERNITY_LEAVE:
                    cout << "     Selected Leave Type - Paternity Leave " << endl;
                    cout <<  BORDER_LINES <<  endl;
                    cout << "\nEnter the count of additional leave you want to add : ";
                    cin  >> count;
                    addExtraLeaveToAll(ADD_PATERNITY_LEAVE,count);
                    break;
                case ADD_MARRIAGE_LEAVE:
                    cout << "     Selected Leave Type - Marriage Leave " << endl;
                    cout <<  BORDER_LINES <<  endl;
                    cout << "\nEnter the count of additional leave you want to add : ";
                    cin  >> count;
                    addExtraLeaveToAll(ADD_MARRIAGE_LEAVE,count);
                    break;
                default:
                    cout << " Wrong Type !!! " << endl;
                    cout <<  BORDER_LINES <<  endl;
                    break;
            }
        }else if (resp == "6"){
            cout << "           Exiting Leave Operations    " << endl;
            cout << BORDER_LINES <<  endl;
        }

    }while(resp != "6");
}

leaveData* Employee::viewLeaveBalance(int emp_id){
    try {
        leaveData *leaveBalances = &LeaveMap.at(emp_id);
        return leaveBalances;
    } catch (const out_of_range& e) {
        return nullptr;
    }
}

void Employee::addExtraLeaveToAll(int leaveType, int count){
    switch(leaveType){
        case ADD_WFH:
            for (auto it = LeaveMap.begin(); it != LeaveMap.end(); ++it) {
                int emp_id = it->first;
                leaveData *leaveInfo = &it->second;
                leaveInfo->workFromHome += count;
            }
            break;
        case ADD_ANNUAL_LEAVE:
            for (auto it = LeaveMap.begin(); it != LeaveMap.end(); ++it) {
                int emp_id = it->first;
                leaveData *leaveInfo = &it->second;
                leaveInfo->annualLeave += count;
            }     
            break;
        case ADD_VACATION_LEAVE:
            for (auto it = LeaveMap.begin(); it != LeaveMap.end(); ++it) {
                int emp_id = it->first;
                leaveData *leaveInfo = &it->second;
                leaveInfo->vacationLeave += count;
            }
            break;
        case ADD_TEAM_OFF:
            for (auto it = LeaveMap.begin(); it != LeaveMap.end(); ++it) {
                int emp_id = it->first;
                leaveData *leaveInfo = &it->second;
                leaveInfo->teamOff += count;
            }
            break;
        case ADD_MATERNITY_LEAVE:
            for (auto it = LeaveMap.begin(); it != LeaveMap.end(); ++it) {
                int emp_id = it->first;
                leaveData *leaveInfo = &it->second;
                leaveInfo->maternityLeave += count;
            }
            break;
        case ADD_PATERNITY_LEAVE:
            for (auto it = LeaveMap.begin(); it != LeaveMap.end(); ++it) {
                int emp_id = it->first;
                leaveData *leaveInfo = &it->second;
                leaveInfo->paternityLeave += count;
            }
            break;
        case ADD_MARRIAGE_LEAVE:
            for (auto it = LeaveMap.begin(); it != LeaveMap.end(); ++it) {
                int emp_id = it->first;
                leaveData *leaveInfo = &it->second;
                leaveInfo->marriageLeave += count;
            }
            break;
        default:
            cout << " Wrong Type !!! " << endl;
            break;
    }
}

void Employee::showPeopleData(){
    for (auto& emp : employee) {
        cout << BORDER_LINES <<  endl;
        cout << "   Employee Id   : " << getEmpId(&emp) << endl;
        cout << "   Name          : " << getName(&emp) << endl;
        cout << "   Role          : " << getRole(&emp) << endl;
        cout << "   Department    : " << getDepartment(&emp) << endl;
        cout << BORDER_LINES <<  endl;
    }
}

void Employee::saveManagerData(struct manager_details details){
    manager_data.push_back(details);
}

vector<manager_details>& Employee::getManagerData(){
    return manager_data;
}

manager_details* Employee::getSpecificManagerData(int emp_id){
    for (auto& manager : manager_data) {
        if (emp_id == manager.emp_id){
            return &manager;
        }
    }
    return nullptr;
}
