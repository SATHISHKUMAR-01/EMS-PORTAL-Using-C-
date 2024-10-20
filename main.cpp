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
            cout << "|---           Login/Register              ---|" << endl;
        }else {
            cout << BODY_LINES << endl;
        }
    }
    cout << BORDER_LINES << "\n" << endl;
}

int main(){
    Employee emp;
    frontPage();
    return 0;
}