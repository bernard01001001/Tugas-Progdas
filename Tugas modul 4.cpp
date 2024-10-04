#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

vector<string> username;
vector<string> password;

const char upper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char lower[] = "abcdefghijklmnopqrstuvwxyz";
const char spcChar[] = "!@#$%^&*()_+[]{}|;:',.<>?/"; 
const char num[] = "1234567890";

string tempUser;
string tempPass;
int choice=1;

class Myclass{
  public:
  string passCheck(string tempPass){
    bool checkUpper=false;
    bool checkLower=false;
    bool checkSpcChar=false;
    bool checkNum=false;
    
    for(char c:tempPass){
      if (strchr (upper, c)) checkUpper = true;
      if (strchr (lower, c)) checkLower = true;
      if (strchr (spcChar, c)) checkSpcChar = true;
      if (strchr (num, c)) checkNum = true;
    }
    
    if(checkUpper && checkLower && checkSpcChar==true && checkNum) {
      username.push_back(tempUser);
      password.push_back(tempPass);
      return "registered successfully!";
    }
    else{
      return "password not strong enough";
    }

  }
};
void login(string tempUser, string tempPass){
  bool loginSuccess = false;
  
    for(int i=0; i<username.size();i++){
      if(tempPass==password[i] && tempUser==username[i]){
        cout<<"logged in successfully"<<endl;
        loginSuccess = true;
        break;
      }
    }
     if (!loginSuccess) {
        cout << "login invalid"<<endl;
     }
}
int main(){
  Myclass obj;

  while (true) {
    cout << "1. register" << endl;
    cout << "2. login" << endl;
    cout << "3. exit" << endl;
    cin >> choice;

    if (choice == 3) {
      break;
    }  

    if (choice == 1 || choice == 2) {
      cout << "username: " << endl;
      cin >> tempUser;

      if (tempUser.empty()) {
        cout << "username cannot be empty" << endl;
        continue;
      }

      cout << "password: " << endl;
      cin >> tempPass;

      if (tempUser.empty()) {
        cout << "password cannot be empty" << endl;
        continue;
      }  

      if(choice == 1){
        while(obj.passCheck(tempPass)=="password not strong enough"){
          cout<< obj.passCheck(tempPass)<<endl;
          cin>>tempPass;
        }
        cout<<obj.passCheck(tempPass)<<endl;
      }
      else if(choice == 2){
        login(tempUser, tempPass);
      }
    }
  }
  return 0;
}
