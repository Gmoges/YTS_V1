#include<iostream>
#include<fstream>
#include<string>
#include "connector.h"
using namespace std;



// -----------COLORS WE USE----------------------------------------------
                                                                      //
    const string BLUE   = "\033[34m";                                 //
    const string YELLOW = "\033[33m";                                 //
    const string RED    = "\033[31m";                                 //   
    const string GREEN  = "\033[32m";                                 //
    const string RESET  = "\033[0m"; 


void DayTracker();
void WeekTracker();
void monthlyTracker();


void infoU(){
    int Uchoise;
    do
    {
        cout << "choose track type "<<endl;
        cout << "     1. Daily Income traker \n     2. weekly Income tracker \n     3. monthly Income tracker \n     0. exit \nEnter your choise: ";
        cin>>Uchoise;
    
    switch (Uchoise)
    {
    case 1:
        DayTracker();
        break;
    case 2:
        WeekTracker();
        break;
    case 3:
        monthlyTracker();
        break;
    default:
        break;
    }
    } while (Uchoise != 0);
    
}


void DayTracker(){
    string date;
    int Eamt;
    date.c_str();
    ofstream fout("DayTracker.txt",ios::app);
    if(fout.is_open()){
        cout << "Enter the date of the income: ";
        cin>>date;
        cout << "Enter amount of Income: ";
        cin>>Eamt;
        fout << date << "  " <<Eamt <<endl;
        cout << GREEN << "DONE!!!"<<RESET<<endl;
    }else{
        cout <<RED << "404!!"<<RESET<<endl;
    }
    fout.close();
}

void WeekTracker(){
        string weekCode;
        int Eamt;
    ofstream fout("WeekTracker.txt",ios::app);
    if(fout.is_open()){
        cout << "Enter the week code: ";
        cin>>weekCode;
        cout << "Enter amount of Income: ";
        cin>>Eamt;
        fout << weekCode << "  " <<Eamt <<endl;
        cout << GREEN << "DONE!!!"<<RESET<<endl;
    }else{
        cout <<RED << "404!!"<<RESET<<endl;
    }
    fout.close();
}

void monthlyTracker(){
        string month;
    int Eamt;
    ofstream fout("monthlyTracker.txt",ios::app);
    if(fout.is_open()){
        cout << "Enter a month(sept,feb): ";
        cin>>month;
        cout << "Enter amount of Income: ";
        cin>>Eamt;
        fout << month << "  " <<Eamt <<endl;
        cout << GREEN << "DONE!!!"<<RESET<<endl;
    }else{
        cout <<RED << "404!!"<<RESET<<endl;
    }
    fout.close();
}

/*

int main(){
    infoU();
    return 0;
}

*/

