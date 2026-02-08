#include<iostream>
#include<fstream>
#include<string>
#include "con.h"
using namespace std;


// -----------COLORS WE USE----------------------------------------------
                                                                      //
    const string BLUE   = "\033[34m";                                 //
    const string YELLOW = "\033[33m";                                 //
    const string RED    = "\033[31m";                                 //   
    const string GREEN  = "\033[32m";                                 //
    const string RESET  = "\033[0m";                                  //
                                                                      //



void Ctrack(){
    int balance;
    string date;
    date.c_str();
    cout << "Please Enter the date: ";
    cin>>date;
    cout << "Enter the new current balance for capital: ";
    cin>>balance;

    ofstream fout("cap.txt",ios::app);
    if(fout.is_open()){
        fout << date << "  "<<balance<<endl;
        cout <<GREEN << "capital is Updated!"<<endl;
    }else{
        cout << RED << "404!!"<<endl;
    }
}

void Creport(){
    int balance;
    string date;
    ifstream fin("cap.txt");
    if(fin.is_open()){
           cout << GREEN << "here is the full report of the capital"<<endl;
           cout << " "<<endl;
           cout <<RESET;
        while (fin>>date>>balance)
        {
            cout << YELLOW <<"on the date " << date << " the total capital in cash was: " <<balance<<endl;
            cout << " "<<endl;
            cout <<RESET;
        }
        cout << " "<<endl;
        
    }else{
        cout << RED << "404!!"<<endl;
        cout <<RESET;
    }
}

void current(){
    int Choise;
    do
    {
       cout << "1. Track \n2. Report \n0.exit"<<endl;
       cout << "Enter your choise: ";
       cin>>Choise;
    switch (Choise)
    {
    case 1:{
        system("clear");
        Ctrack();
        break;
    }   
    case 2:{
        system("clear");
        Creport();
        break;
    } 
    case 0:
        cout << GREEN << "Good bay!"<<endl;
        cout <<RESET;
        break;
    default:
       cout << RED << "Invalid Input!!"<<endl;
       cout <<RESET;
        break;
    }
    } while(Choise != 0);
}


void tot(){
      cout << "comming soon"<<endl;
}


void capTracker(){
    int Uchoise;
    do
    { 
    cout << " "<<endl;
    cout << " 1. current balance Track or Report: \n 2. total capital Track or Report"<<endl;
    cout << " "<<endl;
    cout << " enter your choise: ";  
    cin>>Uchoise;
    switch (Uchoise)
    {
    case 1:
        current();
        break;
    case 2:
        tot();
        break;
    case 0:
    cout << "Thanks for visting"<<endl;
        break;
    default:
    cout << "Invalid input!!"<<endl;
        break;
    }
    } while (Uchoise !=0);
    
}