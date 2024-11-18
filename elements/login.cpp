#include "login.h"
#include "admin.h"
#include "../libraries/messages.h"

#define ATTENDANCE_DIR "/Users/sathiska/Documents/c++/EMS-PORTAL-Using-CPlusPlus/attendance_record/"

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
    int resp;
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
        cout << "           Employee not found " << endl;
        cout << BORDER_LINES <<  endl;
        return;
    }

    cout << "\nWelcome, " << emp.getName(details) << "\n" << endl;

    string options[] = {
        "Enter 01 to view holiday planners",
        "Enter 02 to view leave balances",
        "Enter 03 to apply/cancel/view leave",
        "Enter 04 to view salary",
        "Enter 05 to view the people in the company",
        "Enter 06 to exit",
        "Enter 07 to view project and manager info",
        "Enter 08 to approve leave requests",
        "Enter 09 to submit/cancel/view self-review",
        "Enter 10 to approve the self-review of the employee",
        "Enter 11 to view attendance info",
        "Enter 12 to see notifications"
    };

    int numOptions = sizeof(options) / sizeof(options[0]);

    do{
        cout << "\n" << BORDER_LINES <<  endl;
        cout << "           Employee Operations   " << endl;
        cout << BORDER_LINES << "\n" << endl;

        for (int index = 0 ; index < numOptions; index++){
            cout << options[index] << endl;
        }

        cout << "\n\nEnter your choice - ";
        cin >> resp;

        while ( (resp < 1 || resp > numOptions)){
            cout << "\nWrong input given !!! Enter value from 1 to "<< numOptions << " - ";
            cin >> resp;
        }

        cout << "\n" << BORDER_LINES <<  endl;
        if(resp == 1){
            showHolidays();
            cout << BORDER_LINES <<  endl;
        }else if(resp == 2){
            leaveData *leaveBalance = emp.viewLeaveBalance(emp_id);
            cout << "           Leave Balances" << endl;
            cout << BORDER_LINES <<  endl;
            if (leaveBalance != nullptr) {
                cout << "   Work From Home    :  " << leaveBalance->workFromHome << endl;
                cout << "   Annual Leave      :  " << leaveBalance->annualLeave << endl;
                cout << "   Vacation Leave    :  " << leaveBalance->vacationLeave << endl;
                cout << "   Team Time Off     :  " << leaveBalance->teamOff << endl;
                cout << "   Maternity Leave   :  " << leaveBalance->maternityLeave << endl;
                cout << "   Paternity Leave   :  " << leaveBalance->paternityLeave << endl;
                cout << "   Marriage Leave    :  " << leaveBalance->marriageLeave << endl;
            }else{
                cout << "           Record not found !!!  " << endl;
            }
            cout << BORDER_LINES <<  endl;
        }else if(resp == 3){
            cout << BORDER_LINES <<  endl;
            int leave_operation;
            cout << "\nDo you want to apply for a leave/cancel a leave ? \n" << endl; 
            cout << "Enter 01 to apply for a leave" << endl;
            cout << "Enter 02 to cancel a leave " << endl;
            cout << "Enter 03 to view applied leave " << endl;
            cout << "\nEnter your choice : ";
            cin  >> leave_operation;
            cout << "\n" << BORDER_LINES <<  endl;
            if(leave_operation == 1){
                leave_details details;
                int leave_type, numDays;
                string reason, startDate, endDate;
                bool leave_status;
                cout << "           Select the leave type" << endl;
                cout << BORDER_LINES << "\n" <<endl;
                cout << "Enter 01 to choose work from home " << endl;
                cout << "Enter 02 to choose vacation leave " << endl;
                cout << "Enter 03 to choose annual leave " << endl;
                cout << "Enter 04 to choose team time off " << endl;
                cout << "Enter 05 to choose paternity leave " << endl;
                cout << "Enter 06 to choose maternity leave " << endl;
                cout << "Enter 07 to choose marriage leave " << endl;
                cout << "\nEnter your choice : ";
                cin  >> leave_type;

                cout << "\nEnter the number of days you want to apply : ";
                cin  >> numDays;

                cout << "\nEnter the start date : ";
                cin  >> startDate;

                cout << "\nEnter the end date   : ";
                cin  >> endDate;

                cout << "\nEnter the leave reason : ";
                cin  >> reason;

                details.leave_type = getLeaveType(leave_type);
                details.end_date = endDate;
                details.start_date = startDate;
                details.number_of_days = numDays;
                details.reason = reason;
                details.leave_status = false;
                
                emp.applyLeave(emp_id, details);

                cout << "\n" << BORDER_LINES << endl;
                cout << "   Leave Applied Successfully   " << endl;
                cout << BORDER_LINES << "\n" << endl;

            }else if(leave_operation == 2){
                cout << "\n" << BORDER_LINES << endl;
                cout << " Your current pending leave requests" << endl;
                cout << BORDER_LINES << "\n" << endl;

                map<int, vector<leave_details>>& pending_leave = emp.getLeaveRequest();
               
                if (pending_leave.count(emp_id)) {
                    for (auto it = pending_leave[emp_id].begin(); it != pending_leave[emp_id].end(); ++it ) {
                        if (!it->leave_status){
                            cout << "Leave Type     : " << it->leave_type << endl;
                            cout << "Start Date     : " << it->start_date << endl;
                            cout << "End Date       : " << it->end_date << endl;
                            cout << "Number of Days : " << it->number_of_days << endl;
                            cout << "Reason         : " << it->reason << endl;

                            char choice;
                            cout << "\nDo you want to delete this leave request? (y/n): ";
                            cin >> choice;

                            if (choice == 'y' || choice == 'Y') {
                                it = pending_leave[emp_id].erase(it);
                                cout << "\n<----- Leave Request Cancelled Successfully ----->\n" << endl;
                            }
                        }
                    }
                }else{
                    cout << "There is no pending leave request found !!!";
                }
            }else if(leave_operation == 3){
                map<int, vector<leave_details>>& pending_leave = emp.getLeaveRequest();
                if (pending_leave.count(emp_id)) {
                    for (auto it = pending_leave[emp_id].begin(); it != pending_leave[emp_id].end(); ++it ) {
                        cout << "Leave Type     : " << it->leave_type << endl;
                        cout << "Start Date     : " << it->start_date << endl;
                        cout << "End Date       : " << it->end_date << endl;
                        cout << "Number of Days : " << it->number_of_days << endl;
                        cout << "Reason         : " << it->reason << endl;
                        string status = it->leave_status ? "Approved" : "Pending";
                        cout << "Status         : " << status << endl;
                    }
                }else{
                    cout << "There is no leave request found !!!" << endl;
                }
            }
        }else if(resp == 4){
            cout << "\n      <----- Salary Slip ----->\n" << endl;
            cout << "        Total Salary : Rs." << emp.getSalary(details) << endl;
        }else if(resp == 5){
            cout << "           People in the Company " << endl;
            cout << BORDER_LINES <<  endl;
            emp.showPeopleData();
        }else if(resp == 6){
            cout << "           Exiting Employee Login    " << endl;
            cout << BORDER_LINES <<  endl;
        }else if(resp == 7){
            cout << " View Employee's manager and project data " << endl;
            cout << BORDER_LINES <<  endl;
            int emp_id;
            cout << "Enter the employee id  :  ";
            cin  >> emp_id;
            emp.viewManagerAndProjectDetails(emp_id);
        }else if(resp == 8){
            manager_details* mngr_details = emp.getSpecificManagerData(emp_id);
            message_details message_info;
            string subject;

            if (mngr_details == nullptr) {
                cout << BORDER_LINES <<  endl;
                cout << "     Operation not permitted  " << endl;
                cout << BORDER_LINES <<  endl;
                return;
            }

            map<int, vector<leave_details>>& pending_leave = emp.getLeaveRequest();

            for (int id : mngr_details->team_members_id){
                if (pending_leave.count(id)) {
                    emp_details* emp_info =  emp.getEmployee(id);
                    for (auto it = pending_leave[id].begin(); it != pending_leave[id].end(); ++it) {
                        cout << "Employee Name  : " << emp_info->name << endl;
                        cout << "Leave Type     : " << it->leave_type << endl;
                        cout << "Start Date     : " << it->start_date << endl;
                        cout << "End Date       : " << it->end_date << endl;
                        cout << "Number of Days : " << it->number_of_days << endl;
                        cout << "Reason         : " << it->reason << endl;

                        char choice;
                        cout << "Do you want to approve this leave request? (y/n): ";
                        cin >> choice;

                        if (choice == 'y' || choice == 'Y') {
                            it->leave_status = true;
                            cout << "\n<----- Leave Request Approved Successfully ----->\n" << endl;
                            subject = "Your Leave Application has been Accepted.\n"
                                      "Leave type: " + it->leave_type + "\n" +
                                      "Start Date: " + it->start_date + "\n" +
                                      "End Date: " + it->end_date + "\n" +
                                      "Reason: " + it->reason + "\n";
                            message_info.info = subject;
                            emp.addMessage(id, message_info);
                        }
                    }
                }
            }
        }else if(resp == 9){
            cout << BORDER_LINES <<  endl;
            int review_operation;
            cout << "\nDo you want to submit comment for a review/cancel comments for a review ? \n" << endl; 
            cout << "Enter 01 to submit comments for a review" << endl;
            cout << "Enter 02 to cancel comments for a review " << endl;
            cout << "Enter 03 to view added review comments " << endl;
            cout << "\nEnter your choice : ";
            cin  >> review_operation;
            cout << "\n" << BORDER_LINES <<  endl;
            if(review_operation == 1){
                review_details details;

                cout << "\nEnter your self sufficiency comments         : ";
                cin  >> details.emp_self_sufficiency_comments;

                cout << "\nAdd Rating for the category self sufficiency : ";
                cin  >> details.emp_self_sufficieny_rating;

                cout << "\nEnter your proficiency comments         : ";
                cin  >> details.emp_proficiency_comments;

                cout << "\nAdd Rating for the category proficiency : ";
                cin  >> details.emp_proficiency_rating;

                emp.addReview(emp_id, details);

                cout << "\n" << BORDER_LINES << endl;
                cout << "   Review Added Successfully   " << endl;
                cout << BORDER_LINES << "\n" << endl;

            }else if(review_operation == 2){
                cout << "\n" << BORDER_LINES << endl;
                cout << " Your current pending review" << endl;
                cout << BORDER_LINES << "\n" << endl;

                map<int, vector<review_details>>& pending_review = emp.getReviewData();
               
                if (pending_review.count(emp_id)) {
                    for (auto it = pending_review[emp_id].begin(); it != pending_review[emp_id].end(); ) {
                        cout << "Self Sufficieny Comments     : " << it->emp_self_sufficiency_comments << endl;
                        cout << "Self Sufficieny Rating       : " << it->emp_self_sufficieny_rating << endl;
                        cout << "Proficiency Comments         : " << it->emp_proficiency_comments << endl;
                        cout << "Proficiency Rating           : " << it->emp_proficiency_rating << endl;

                        char choice;
                        cout << "Do you want to delete this review ? (y/n): ";
                        cin >> choice;

                        if (choice == 'y' || choice == 'Y') {
                            it = pending_review[emp_id].erase(it);
                            cout << "\n<----- Review Comments Deleted Successfully ----->\n" << endl;
                        } else {
                            ++it;
                        }
                    }
                }else{
                    cout << "There is no pending review found !!!";
                }
            }
        }else if(resp == 10){
            manager_details* mngr_details = emp.getSpecificManagerData(emp_id);
            message_details message_info;
            string subject;

            if (mngr_details == nullptr) {
                cout << BORDER_LINES <<  endl;
                cout << "     Operation not permitted  " << endl;
                cout << BORDER_LINES <<  endl;
                return;
            }

            map<int, vector<review_details>>& review_info = emp.getReviewData();

            for (int id : mngr_details->team_members_id){
                if (review_info.count(id)) {
                    emp_details* emp_info =  emp.getEmployee(id);
                    for (auto it = review_info[id].begin(); it != review_info[id].end(); ++it) {
                        cout << "\nEmployee Name  : " << emp_info->name << endl;
                        cout << "\nSelf Sufficieny Comments     : " << it->emp_self_sufficiency_comments << endl;
                        cout << "Self Sufficieny Rating       : " << it->emp_self_sufficieny_rating << endl;
                        cout << "Proficiency Comments         : " << it->emp_proficiency_comments << endl;
                        cout << "Proficiency Rating           : " << it->emp_proficiency_rating << endl;

                        char choice;
                        cout << "Do you want to add your comments to this review ? (y/n): ";
                        cin >> choice;

                        if (choice == 'y' || choice == 'Y') {
                            cout << "Add your comments and rating !!!" << endl;

                            cout << "\nEnter your self sufficiency comments         : ";
                            cin  >> it->mngr_self_sufficiency_comments;

                            cout << "\nAdd Rating for the category self sufficiency : ";
                            cin  >> it->mngr_self_sufficieny_rating;

                            cout << "\nEnter your proficiency comments         : ";
                            cin  >> it->mngr_proficiency_comments;

                            cout << "\nAdd Rating for the category proficiency : ";
                            cin  >> it->mngr_proficiency_rating;

                            it->status = true;
                            it->final_rating = (it->mngr_self_sufficieny_rating + it->mngr_proficiency_rating) / 2;

                            subject = "Your Review has been Accepted.\n"
                                      "Final Rating : " + it->final_rating + "\n";
                            message_info.info = subject;
                            emp.addMessage(id, message_info);
                        }
                    }
                }
            }
        }else if (resp == 11){
            cout << "       Attendance Info   " << endl;
            cout << BORDER_LINES <<  endl;
            vector<EmployeeLog> attendance_details = emp.getAttendanceInfo(emp_id);
            cout << "\n" << BORDER_LINES << endl;
            for (const auto& attendance : attendance_details) {
                attendance.display();
            }
            cout << BORDER_LINES << "\n" << endl;
        }else if (resp == 12){
            
        }
    }while(resp != 6);
}

void Login::displayEmployeeData(int emp_id, int age, string name, string dob, string role, string fatherName, string department, string dateOfJoin, string sex, int salary){
    cout << "\n" << BORDER_LINES <<  endl;
    cout << "      Summary of New Employee Details" << endl;
    cout << BORDER_LINES <<  endl;
    cout << "   Employee Id   : " << emp_id << endl;
    cout << "   Name          : " << name << endl;
    cout << "   Sex           : " << sex << endl;
    cout << "   Father's Name : " << fatherName << endl;
    cout << "   Date of Birth : " << dob << endl;
    cout << "   Age           : " << age << endl;
    cout << "   Role          : " << role << endl;
    cout << "   Department    : " << department << endl;
    cout << "   Date of Join  : " << dateOfJoin << endl;
    cout << "   Salary        : " << salary << endl;
    cout << BORDER_LINES <<  endl;
}

void Login::addEmployeeData(Employee& emp){
    int emp_id, age, count, salary;
    string dob, name, role, fatherName, department, dateOfJoin, sex;

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
        cout << "\nEnter the sex (Male/Female/Others) : ";
        cin >> sex;
        cout << "\nEnter the Date of Birth (DD/MM/YYYY) : ";
        cin >> dob;
        cout << "\nEnter the employee role (Intern/Senior/Manager) : ";
        cin >> role;
        cout << "\nEnter the department belongs to (Admin/HR/IT/Engineering) : ";
        cin >> department;
        cout << "\nEnter the Date of Join (DD/MM/YYYY) : ";
        cin >> dateOfJoin;
        cout << "\nEnter the salary : ";
        cin  >> salary;

        displayEmployeeData(emp_id,age,name,dob,role,fatherName,department,dateOfJoin,sex,salary);

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
                cout << "     Enter 01 to edit employee ID" << endl;
                cout << "     Enter 02 to edit name" << endl;
                cout << "     Enter 03 to edit father's name" << endl;
                cout << "     Enter 04 to edit date of birth" << endl;
                cout << "     Enter 05 to edit Age" << endl;
                cout << "     Enter 06 to edit Role" << endl;
                cout << "     Enter 07 to edit Department" << endl;
                cout << "     Enter 08 to edit Date of Join" << endl;
                cout << "     Enter 09 to edit sex" << endl;
                cout << "     Enter 10 to edit salary" << endl;
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
                        cout << "Enter the new value (Intern/Senior/Manager) : ";
                        cin  >> role;
                        break;
                    case EDIT_DEPARTMENT:
                        cout << "\nOld Department : " << department << endl;
                        cout << "Enter the new value (Admin/HR/IT/Engineering) : ";
                        cin  >> department;
                        break;
                    case EDIT_DATE_OF_JOIN:
                        cout << "\nOld Date Of Join : " << dateOfJoin << endl;
                        cout << "Enter the new value : ";
                        cin  >> dateOfJoin;
                        break;
                    case EDIT_SEX:
                        cout << "\nOld Sex : " << sex << endl;
                        cout << "Enter the new value (Male/Female/Others) : ";
                        cin  >> sex;
                        break;
                    case EDIT_SALARY:
                        cout << "\nOld Salary : " << salary << endl;
                        cout << "Enter the new value : ";
                        cin  >> salary;
                        break;
                    default:
                        cout << "Wrong Value Entered" << endl;
                        break;
                }
                displayEmployeeData(emp_id,age,name,dob,role,fatherName,department,dateOfJoin,sex,salary);
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
        details[index].sex = sex;
        details[index].salary = salary;

        emp.addEmployee(details[index]);

        cout << "\n" << BORDER_LINES <<  endl;
        cout << "       Data Saved Successfully !!! " << endl;
        cout << BORDER_LINES <<  endl;
    }
}

void Login::adminLogin(Employee& emp){
    int resp;
    bool addEntry, updateEntry;
    Admin admin;

    int emp_id;
    cout << "\n" << BORDER_LINES <<  endl;
    cout << "          Welcome to Admin Login" << endl;
    cout << BORDER_LINES <<  endl;
    
    cout << "\nEnter your employee ID : ";
    cin  >> emp_id;
    bool isAdmin = emp.isAdmin(emp_id);

    if(!isAdmin){
        cout << "\n" << BORDER_LINES <<  endl;
        cout << "              Admin not found " << endl;
        cout << BORDER_LINES <<  endl;
        return;
    }

    string options[] = {
        "Enter 01 to add new employee data",
        "Enter 02 to update existing employee data",
        "Enter 03 to view all employee details",
        "Enter 04 to view specific employee details",
        "Enter 05 to exit",
        "Enter 06 to grant leave to employee",
        "Enter 07 to view the leave counts for all leave types",
        "Enter 08 to add new manager",
        "Enter 09 to remove manager details",
        "Enter 10 to view list of managers in the company",
        "Enter 11 to view update manager details",
        "Enter 12 to add new project",
        "Enter 13 to remove project details",
        "Enter 14 to view list of  projects in the company",
        "Enter 15 to update project details",
        "Enter 16 to map employee to the manager",
        "Enter 17 to map employee to the project",
        "Enter 18 to view project and manager details of an employee",
        "Enter 19 to add attendance entry"
    };

    int numOptions = sizeof(options) / sizeof(options[0]);

    do {
        cout << "\n" << BORDER_LINES <<  endl;
        cout << "            Admin Operations   " << endl;
        cout << BORDER_LINES << "\n" << endl;

        for (int index = 0 ; index < numOptions; index++){
            cout << options[index] << endl;
        }

        cout <<"\n\nEnter your choice - ";
        cin >> resp;
        while ( (resp < 1 || resp > numOptions)){
            cout << "\nWrong input given !!! Enter value from 1 to "<< numOptions << " - ";
            cin >> resp;
        }
        cout << "\n" << BORDER_LINES <<  endl;
        if (resp == 1) {
            cout << "           Adding new Employee Data     " << endl;
            cout << BORDER_LINES <<  endl;
            addEmployeeData(emp);
        }else if (resp == 2){
            cout << "           Updating Employee Data    " << endl;
            cout << BORDER_LINES <<  endl;
            emp.updateEmployeeData(emp);
        }else if (resp == 3){
            cout << "         Displaying all Employee Data    " << endl;
            cout << BORDER_LINES <<  endl;
            emp.displayEmployee();
        }else if (resp == 4){
            int emp_id;
            cout << "       Displaying specific Employee Data    " << endl;
            cout << BORDER_LINES <<  endl;
            cout << "\nEnter the employee id : ";
            cin  >> emp_id;
            emp.diplaySpecificEmployee(emp_id);
        }else if (resp == 5){
            cout << "           Exiting Admin Login    " << endl;
            cout << BORDER_LINES <<  endl;
        }else if (resp == 6){
            cout << "           Granting Leave to employees    " << endl;
            cout << BORDER_LINES <<  endl;
            emp.grantLeaveToEmployee();
        }else if (resp == 7){
            cout << "           Default Leave counts   " << endl;
            cout << BORDER_LINES <<  endl;
            cout << "   Intern Work from Home    -  " << emp.getInternWorkFromHome() << endl;
            cout << "   Senior Work from Home    -  " << emp.getSeniorWorkFromHome() << endl;
            cout << "   Manager Work from Home   -  " << emp.getManagerWorkFromHome() << endl;
            cout << "   Annual Leave             -  " << emp.getAnnualLeave() << endl;
            cout << "   Vacation Leave           -  " << emp.getAnnualLeave() << endl;
            cout << "   Team Time Off            -  " << emp.getTeamOff() << endl;
            cout << "   Maternity Leave          -  " << emp.getMaternityLeave() << endl;
            cout << "   Paternity Leave          -  " << emp.getPaternityLeave() << endl;
            cout << "   Marriage Leave           -  " << emp.getMarriageLeave() << endl;
        }else if (resp == 8){
            cout << "         Adding new manager data   " << endl;
            cout << BORDER_LINES <<  endl;
            admin.addManagerData(emp);
        }else if (resp == 9){
            cout << "         Remove Manager data   " << endl;
            cout << BORDER_LINES <<  endl;
            admin.removeManagerData(emp);
        }else if (resp == 10){
            cout << "         Viewing Manager details   " << endl;
            cout << BORDER_LINES <<  endl;
            admin.viewManagerDetails(emp);
        }else if (resp == 11){
            cout << "         Updating Manager details   " << endl;
            cout << BORDER_LINES <<  endl;
            admin.updateManagerData(emp);
        }else if (resp == 12){
            cout << "         Adding new project data   " << endl;
            cout << BORDER_LINES <<  endl;
            admin.addProjectData(emp);
        }else if (resp == 13){
            cout << "         Viewing Project details   " << endl;
            cout << BORDER_LINES <<  endl;
            admin.removeProjectData(emp);
        }else if (resp == 14){
            cout << "         Updating Project details   " << endl;
            cout << BORDER_LINES <<  endl;
            admin.viewProjectDetails(emp);
        }else if (resp == 15){
            cout << "         Remove Project data   " << endl;
            cout << BORDER_LINES <<  endl;
            admin.updateProjectData(emp);
        }else if (resp == 16){
            cout << "         Mapping employee to manager  " << endl;
            cout << BORDER_LINES <<  endl;
            int emp_id,manager_id;
            cout << "Enter the engineer - employee id  :  ";
            cin  >> emp_id;
            cout << "\nEnter the manager - employee id   :  ";
            cin  >> manager_id;
            emp.mapEmployeeToManager(emp_id, manager_id);
        }else if (resp == 17){
            cout << "         Mapping employee to project  " << endl;
            cout << BORDER_LINES <<  endl;
            int emp_id,project_id;
            cout << "Enter the employee id  :  ";
            cin  >> emp_id;
            cout << "Enter the project id   :  ";
            cin  >> project_id;
            emp.mapEmployeeToProject(emp_id, project_id);
        }else if (resp == 18){
            cout << " View Employee's manager and project data " << endl;
            cout << BORDER_LINES <<  endl;
            int emp_id;
            cout << "Enter the employee id  :  ";
            cin  >> emp_id;
            emp.viewManagerAndProjectDetails(emp_id);
        }else if (resp == 19){
            cout << "     Adding the attendance entry of the day " << endl;
            cout << BORDER_LINES <<  endl;
            string filename;
            cout << "\nEnter the csv file name : ";
            cin >> filename;
            filename = ATTENDANCE_DIR+filename;
            admin.readCSVAndStore(filename, emp);
        }

    }while(resp != 5);
}

void Login::addHoliday(string name, string date){
    holidayCalendar[name] = date;
}

void Login::showHolidays(){
    cout << "          HOLIDAY CALENDAR  -  2024   " <<  endl;
    cout << BORDER_LINES <<  endl;
    for (auto it = holidayCalendar.begin(); it != holidayCalendar.end(); ++it) {
        cout << "      " << it->first << " : " << it->second << '\n';
    }
}

string Login::getLeaveType(int type){
    string leave_type;

    if(type == 1){
        leave_type = "WORK_FROM_HOME";
    }else if(type == 2){
        leave_type = "VACATION_LEAVE";
    }else if(type == 3){
        leave_type = "ANNUAL_LEAVE";
    }else if(type == 4){
        leave_type = "TEAM_TIME_OFF";
    }else if(type == 5){
        leave_type = "PATERNITY_LEAVE";
    }else if(type == 6){
        leave_type = "MATERNITY_LEAVE";
    }else if(type == 7){
        leave_type = "MARRIAGE_LEAVE";
    }
    return leave_type;
}