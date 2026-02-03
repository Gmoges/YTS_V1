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



void invstTracker(){
    string date;
    int Icode;
    date.c_str();
    ofstream fout("investor.txt",ios::app);
    if(fout.is_open()){
     cout << "Enter Investment Code: ";
     cin>>Icode;
    }else{
        cout <<RED << "404!!"<<RESET<<endl;
    }
}