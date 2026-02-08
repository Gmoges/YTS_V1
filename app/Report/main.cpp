#include<iostream>
#include<fstream>
#include<string>
#include "connect.h"
using namespace std;



// -----------COLORS WE USE----------------------------------------------
                                                                      //
    const string BLUE   = "\033[34m";                                 //
    const string YELLOW = "\033[33m";                                 //
    const string RED    = "\033[31m";                                 //   
    const string GREEN  = "\033[32m";                                 //
    const string RESET  = "\033[0m"; 

void DayRepoGenerate(){
    ifstream fin("Daytracker.txt");

    if(fin.is_open()){
        int sum = 0;
        string week;
        int amt;
        while(fin>>week>>amt){
            cout << GREEN;
            cout << " "<<endl;
            cout << "on the date: " << week << " you earn: "<<amt<<endl;
            sum = amt + sum;
        } 
            cout << " "<<endl;
            cout << YELLOW;
            cout << "total earned money is: " << sum <<endl;
            cout << RESET;
            cout << " "<<endl;
            cout <<RED;
            cout << " money leaft for next step: "<<10000-sum<<endl;
            cout << " "<<endl;
            cout << "The total money leaft for free cap is: " << 16000 - sum<<endl;
            cout << " "<<endl;
            cout <<RESET;
    }else{
        cout << RED <<"404"<<endl;
        cout <<RESET;
    }
  fin.close();
}

void WeekRepo(){
     ifstream fin("WeekTracker.txt");
    if(fin.is_open()){
        int sum = 0;
        string Wnum;
        int amt;
         cout << " "<<endl;
         cout << BLUE;
        cout << " Week                   amount of income "<<endl;
        cout << RESET;
        while(fin>>Wnum>>amt){
            cout << GREEN;
            cout << " "<<endl;
            cout << RED<< "  "<< Wnum << "                        " << GREEN<< amt << "  " <<endl;
            sum = amt + sum;
            cout << RESET;
        } 
        
        cout << " "<<endl;
         cout << " "<<endl;
         cout << YELLOW;
        cout << "total earned money is: " << sum <<endl;
        cout << " "<<endl;
        cout << RESET;
    }else{
        cout << RED <<"404"<<endl;
        cout <<RESET;
    }
  fin.close();
}


void monthlyRepo(){
     ifstream fin("monthlyTracker.txt");

    if(fin.is_open()){
        int sum = 0;
        string Mnum;
        int amt;
        cout << " month                   amount of income "<<endl;
        while(fin>>Mnum>>amt){
            cout << GREEN;
            cout << " "<<endl;
            cout << RED<< "  "<< Mnum << "                        " << GREEN<< amt << "  " <<endl;
            sum = amt + sum;
            cout << RESET;
        } 
        cout << " "<<endl;
         cout << " "<<endl;
         cout << YELLOW;
        cout << "total earned money is: " << sum <<endl;
        cout << " "<<endl;
        cout << RESET;
    }else{
        cout << RED <<"404"<<endl;
        cout <<RESET;
    }
  fin.close();
}


void Reporter(){
        int Uchoise;
    do
    {
        cout << "choose track type "<<endl;
        cout << "     1. Daily Report \n     2. weekly Report \n     3. monthly Report \n     0. exit \nEnter your choise: ";
        cin>>Uchoise;
    
    switch (Uchoise)
    {
    case 1:
        DayRepoGenerate();
        break;
    case 2:
        WeekRepo();
        break;
    case 3:
        monthlyRepo();
        break;
    default:
    cout << RED << "Invalid Input"<<RESET<<endl;
        break;
    }
    } while (Uchoise != 0);
}

