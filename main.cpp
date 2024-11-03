#include "./elements/employee.h"
#include "./elements/login.h"

//g++ -std=c++11 ./elements/*.cpp main.cpp && ./a.out
//g++ employee.cpp main.cpp && ./a.out

int main(){
    Employee emp;
    Login log;
    bool isContinue, isAdminLogin, isEmpLogin;
    log.frontPage();
    do {
        isContinue = isAdminLogin = isEmpLogin  = false ;
        log.loginPage(&isContinue, &isAdminLogin, &isEmpLogin);
        if (isAdminLogin){
            log.adminLogin(emp);
        } else if (isEmpLogin){
            log.employeeLogin(emp);
        }
    }while(isContinue != false);
    return 0;
}