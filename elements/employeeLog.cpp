#include "employeeLog.h"
#include "../libraries/messages.h"

void EmployeeLog::readCSVAndStore(const string& filename, Employee& emp){
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        return;
    }

    string line;
    getline(file, line);

    while (getline(file, line)) {
        stringstream ss(line);
        string emp_id_str, date, login_time, logout_time;

        getline(ss, emp_id_str, ',');
        getline(ss, date, ',');
        getline(ss, login_time, ',');
        getline(ss, logout_time, ',');

        int emp_id = stoi(emp_id_str);

        // Create an EmployeeLog object and add it to the appropriate map entry
        EmployeeLog log(emp_id, date, login_time, logout_time);
        emp.employee_login[emp_id].push_back(log);
    }

    file.close();
}