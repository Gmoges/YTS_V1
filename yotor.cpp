#include<iostream>
#include<fstream>
#include<string>
#include "app/income/connector.h"
#include "app/Report/connect.h"
#include "app/capital/con.h"

using namespace std;


// -----------COLORS WE USE----------------------------------------------
                                                                      //
    const string BLUE   = "\033[34m";                                 //
    const string YELLOW = "\033[33m";                                 //
    const string RED    = "\033[31m";                                 //   
    const string GREEN  = "\033[32m";                                 //
    const string RESET  = "\033[0m";  // DEFOULT COLOR                //

                                                                      //
//
class userInfo
{
    public:
  string name;
  string userName;
  int password;
};

bool UserRegister();
void CheckUser(string ,int pass);
void menuVIP(string newRole,string user);

class globals{
    public:
    string username;
    int pass;

};

void logo(){
    cout << RED ;



  
cout << "     .--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--.        "<<endl;
cout << "      / .. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\  "<<endl;
cout << "      \\ \\/\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ \\/ / "<<endl;
cout << "      \\/ /`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'\\/ /   "<<endl;
cout << "      / /\\                                                                        / /\\      "<<endl;
cout << "      / /\\ \\       _____ _____    _    __  __  __   _____ _____ ___  ____         / /\\ \\    "<<endl;
cout << "      \\ \\/ /      |_   _| ____|  / \\  |  \\/  | \\ \\ / / _ \\_   _/ _ \\|  _ \\        \\ \\/ /  "<<endl;
cout << "      \\/ /          | | |  _|   / _ \\ | |\\/| |  \\ V / | | || || | | | |_) |        \\/ /     "<<endl;
cout << "      / /\\          | | | |___ / ___ \\| |  | |   | || |_| || || |_| |  _ <         / /\\        "<<endl;
cout << "      / /\\ \\        |_| |_____/_/   \\_\\_|  |_|   |_| \\___/ |_| \\___/|_| \\_\\       / /\\ \\  "<<endl;
cout << "      \\ \\/ /                                                                      \\ \\/ /   "<<endl;
cout << "      \\/ /                                                                        \\/ /      "<<endl;
cout << "      / /\\.--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--./ /\\     "<<endl;
cout << "      / /\\ \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\/\\ \\  "<<endl;
cout << "      \\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `' /   "<<endl;
cout << "      `--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'    "<<endl;

    cout <<  RESET <<endl;
}

int main(){
    globals global;
    int Uchoise;
    logo();
    do{
        cout << "  1. Sign In \n  2. Sign Up\nEnter your choise: ";
        cin>>Uchoise;
    switch (Uchoise)
    {
    case 1:{
        cout << "Enter username: ";
        cin>>global.username;
        cout << "Enter password: ";
        cin>>global.pass;
         CheckUser(global.username , global.pass);
        break;
    }
    case 2:{
        if(UserRegister()){
            cout << GREEN << "Registerd!!" << RESET <<endl;
        }
        break;
    }
    case 0:
     cout <<  BLUE <<"Good bye" << RESET <<endl;
     break;
    default:
    cout << RED << "Invalid Input!" << RESET <<endl;
        break;
    }
    }while(Uchoise !=0);
    return 0;
}

bool UserRegister(){
    userInfo u;
    bool val = true;
    bool found = false;
   string userNameCheek;
   int p;
   string r;
    ofstream fout("DB.txt",ios::app);
    cout << " please Enter the following steps to register!"<<endl;
    cout << " "<<endl;
    cout << " 1. Enter username: ";
    cin>>u.userName;
    cout << " 2. Enter password: ";
    cin>>u.password;    
     ifstream fin("DB.txt");
     while(fin>>userNameCheek>>r>>p){
          if(userNameCheek == u.userName){
            found = true;
            break;
          } 
      }
        if(found){
          cout << RED << "User already exists "<<RESET<<endl;
          val = false;
        }else{      
        fout << u.userName << " VIP "/* DEFOULT ROLE */ << u.password <<  " " <<endl;
       }
  fout.close();
  fin.close();
  return val;
}

void CheckUser(string user, int pass) {
    ifstream fin("DB.txt");
    string u, r;
    int p;
    bool found = false; // Track if we found a match

    while (fin >> u >> r >> p) {
        if (u == user && p == pass) {
            found = true; 
            if (r == "VIP") {
                cout << BLUE << "Welcome VIP!" << RESET << endl;
                menuVIP("Admin", u);
            } else {
                cout << GREEN << "Welcome User!" << RESET << endl;
            }
            break; // Stop searching once found
        }
    }
    if (!found) {
        cout << RED << "Invalid username or password!!" << RESET << endl;
    }
}

void logo2(string role){
    cout << RED;
cout<<"                                                           Role: "<<role<<endl;
cout << " "<<endl;
    cout << GREEN;
cout<<"            _____                               _____     " <<endl;
cout<<"           ( ___ )                             ( ___ )   " <<endl;
cout<<"            |   |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|   |     " <<endl;
cout<<"            |   |                               |   |     " <<endl;
cout<<"            |   |      __   _______ ____        |   |     " <<endl;
cout<<"            |   |      \\ \\ / /_   _/ ___|       |   |     " <<endl;
cout<<"            |   |       \\ V /  | | \\___ \\       |   |     " <<endl;
cout<<"            |   |        | |   | |  ___)|       |   |     " <<endl;
cout<<"            |   |        |_|   |_| |____/       |   |     " <<endl;
cout<<"            |   |                               |   |     " <<endl;
cout<<"            |___|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|___|     " <<endl;
cout<<"           (_____)                             (_____)   " <<endl;
cout <<RED;
cout <<"                          yotor tracking      "<<endl;
cout << "                              system                     "<<BLUE<<" Version: 1.10" <<endl;
     cout << RESET;       
}

void menuVIP(string newRole, string user){
    globals info;
if(newRole == "Admin"){
        system("clear");
        logo2(newRole);
        int Vchoise;
    do
    {
        cout << " "<<endl;
       cout << " 1. Track Investments \n 2. Track Income \n 3. Capital \n 4. Read Reports \n 0.Logout \nEnter your choise: ";
       cin>>Vchoise;
    switch (Vchoise)
    {
    case 1:{
       cout << "working on investment traking:..."<<endl;
       cout << user <<endl;
       cout << "test"<<endl;
        break;
    }
    case 2:
    system("clear");
        infoU();
        break;
    
    case 3:
    system("clear");
        capTracker();
        break;
    
     case 4:
     system("clear");
        Reporter();
        break;
    case 0:
       cout <<YELLOW<< "Good bye" <<RESET<<endl;
        break;
    default:
     cout <<RED << "Invalid Input!!"<<RESET<<endl;
        break;
    }
    } while (Vchoise != 0);
}       
}



